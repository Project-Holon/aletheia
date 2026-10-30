#!/usr/bin/env python3
"""jatail.py -- content-based placement of an overlay's data tail in a Japanese target.

The word-block map of white_map is a rough shift for the data tail of a _ja target: tables that
only exist in Japanese, or that change length, move everything after them.  This module places each
Black data object by its bytes instead.  Every object is searched in the target's tail with the
pointer words as wildcards, in order, so that the placement is monotonic:

  1. the next object of a matched one is tried where the Black distance puts it (the shift stays);
  2. an object that does not sit there is searched forward (only objects with some content);
  3. unmatched objects between two matched ones are tried backward from the next one;
  4. the rest are tried by their first words only (a table that grew or shrank in Japanese);
  5. what is still unmatched takes the next free place in the gap, or is dropped when it has no room.

Library use (datagen.companions, white_map.to_white_ov):
    align(items, timg, tbase, windows) -> [target start or None] per item
    blocks_for(items, starts)          -> [[black start, black end, target start]] for matched items
Nothing is written here; datagen writes the blocks to build/<t>/jatail_ovNNN.json and
white_map reads them for the tail of a _ja target.  Stdlib only.
"""
import bisect
import os
import re
import struct


def _addr_like(w):
    return (0x01FF0000 <= w < 0x02800000 or 0x02FE0000 <= w < 0x03000000
            or 0x03800000 <= w < 0x03810000 or 0x04000000 <= w < 0x04100000
            or 0x06000000 <= w < 0x06A00000)


WWORD = None       # Black word -> target word for code pointers the function map knows, or None


def _pattern(addr, data, n=None):
    """Regex for the first n bytes of `data` (at Black address addr): aligned address-like words
    are four wildcard bytes, or the target's word when WWORD maps it (a pointer to a function)."""
    n = len(data) if n is None else min(n, len(data))
    out, i = [], 0
    while i < n:
        if (addr + i) % 4 == 0 and i + 4 <= n and _addr_like(struct.unpack_from("<I", data, i)[0]):
            v = WWORD(struct.unpack_from("<I", data, i)[0]) if WWORD else None
            out.append(re.escape(struct.pack("<I", v)) if v is not None else b"....")
            i += 4
            continue
        j = i
        while j < n and not ((addr + j) % 4 == 0 and j + 4 <= n and _addr_like(struct.unpack_from("<I", data, j)[0])):
            j += 1
        out.append(re.escape(data[i:j]))
        i = j
    return re.compile(b"".join(out), re.S)


def _info(it):
    """(strong, pattern) of an item: strong = enough varying content to be searched on its own."""
    d = it["data"]
    pat = _pattern(it["addr"], d)
    # the aligned address-like words are wildcards: they do not count as content (a table of
    # pointers only would match anywhere)
    lit = bytes(b for k, b in enumerate(d) if not ((it["addr"] + k - k % 4) % 4 == 0 and k - k % 4 + 4 <= len(d) and
                _addr_like(struct.unpack_from("<I", d, k - k % 4)[0]) and (it["addr"] + k) % 4 == k % 4))
    strong = len(d) >= 8 and len(set(lit)) >= 3
    # with a matched object before it, an object is searched near its predicted place, where
    # pointer words are enough to tell it from its neighbours
    near = len(d) >= 8 and len(set(d)) >= 3
    has_ptr = any((it["addr"] + k) % 4 == 0 and k + 4 <= len(d) and _addr_like(struct.unpack_from("<I", d, k)[0])
                  for k in range(len(d)))
    return strong, pat, len(d) >= 8 and not lit, near, has_ptr


def _trace(stage, idx, res, items, pins, cand):
    import os
    tr = os.environ.get("JATAIL_TRACE")
    if not tr:
        return
    lo, hi = (int(x, 16) for x in tr.split(":"))
    for i in idx:
        if lo <= items[i]["addr"] < hi:
            print("  trace %s %08X -> %s pin %s cand %s" % (stage, items[i]["addr"], res[i] and "%08X" % res[i],
                                                         i in pins, cand.get(i) and "%08X" % cand[i]))


def _near_short(it, timg, tbase, lo, hi):
    """Target address of a short object without pointers in [lo, hi): its bytes up to the first
    zero after the content (a string padded to its alignment), at a 4-byte aligned place."""
    d = bytes(it["data"]).rstrip(b"\0") + b"\0"
    k = timg.find(d, max(0, lo - tbase), max(0, hi - tbase))
    while k >= 0 and (tbase + k) % 4 != it["addr"] % 4:
        k = timg.find(d, k + 1, max(0, hi - tbase))
    return tbase + k if k >= 0 else None


def align(items, timg, tbase, windows, hint=None, reach=0x800, pin=None, wword=None, pin_weak=None):
    """Target start per item (None when unmatched).  `items`: dicts addr, size, data, sec in link
    order.  `windows`: {sec: (lo, hi)} target address ranges to search; timg is the target image
    loaded at tbase.  `hint(addr)`: rough target address (the word-block map) for an object when no
    object before it is matched; a search stays within `reach` bytes of the predicted place and
    takes the occurrence nearest to it.  `pin(addr)`: exact target address of an object that the
    code references (the literal pools of matching functions), or None; it wins when the object's
    content fits there."""
    global WWORD
    WWORD = wword
    n = len(items)
    res = [None] * n
    info = [_info(it) for it in items]

    def mapped_ptrs(i):
        d = items[i]["data"]
        return wword is not None and any((items[i]["addr"] + k) % 4 == 0 and _addr_like(struct.unpack_from("<I", d, k)[0])
                                         and wword(struct.unpack_from("<I", d, k)[0]) is not None
                                         for k in range(0, len(d) - 3))

    def at(i, t, size=None):
        lo, hi = windows[items[i]["sec"]]
        sz = items[i]["size"] if size is None else size
        if t < lo or t + sz > hi:
            return False
        pat = info[i][1] if size is None else _pattern(items[i]["addr"], items[i]["data"], size)
        m = pat.match(timg, t - tbase, t - tbase + sz)
        return bool(m) and m.end() == t - tbase + sz

    for sec in windows:
        idx = [i for i in range(n) if items[i]["sec"] == sec]
        # pinned objects first, in link order: each pin must start after the pin before it (an
        # object that is shorter in the target is cut at the next object later)
        cand = {}
        for i in idx:
            pn = None
            if pin:
                # the object's start, or the addresses inside it that the code references, when
                # they all give the same start (a table split or reordered in the target gives none)
                st_ = {pin(a_) - (a_ - items[i]["addr"]) for a_ in range(items[i]["addr"], items[i]["addr"] + items[i]["size"])
                       if pin(a_) is not None}
                if len(st_) == 1:
                    pn = st_.pop()
                elif pin(items[i]["addr"]) is not None:
                    pn = pin(items[i]["addr"])     # the start's own pin (the inside moved apart in the target)
            if pn is None and pin_weak and pin_weak(items[i]["addr"]) is not None and at(i, pin_weak(items[i]["addr"])):
                pn = pin_weak(items[i]["addr"])     # weaker evidence, with the content there
            if pn is not None and windows[sec][0] <= pn < windows[sec][1] and not (mapped_ptrs(i) and not at(i, pn)):
                # (a table of function pointers must hold the target's functions there)
                cand[i] = pn
        # an object the target moved elsewhere breaks the order: keep the longest run of pins
        # that rises with the link order
        ci = [i for i in idx if i in cand]
        best, prev_ = [1] * len(ci), [-1] * len(ci)
        for b_ in range(len(ci)):
            for a_ in range(b_):
                if cand[ci[a_]] < cand[ci[b_]] and best[a_] + 1 > best[b_]:
                    best[b_], prev_[b_] = best[a_] + 1, a_
        pins = {}
        k_ = max(range(len(ci)), key=lambda q: best[q]) if ci else -1
        while k_ >= 0:
            pins[ci[k_]] = cand[ci[k_]]
            k_ = prev_[k_]
        nextpin, np_ = {}, windows[sec][1]
        nextpin_i, ni_ = {}, None
        for i in reversed(idx):
            nextpin[i], nextpin_i[i] = np_, ni_
            if i in pins:
                np_, ni_ = pins[i], i
        cur, last = windows[sec][0], None
        pinned_at = sorted(pins.values())

        def free(i, t):
            # no pinned object of another item, and no object placed already, starts inside
            # [t, t + size)
            k = bisect.bisect_left(pinned_at, t)
            if k < len(pinned_at) and pinned_at[k] < t + items[i]["size"] and pins.get(i) != pinned_at[k]:
                return False
            return not any(res[j] is not None and j != i and res[j] < t + items[i]["size"] and t < res[j] + items[j]["size"]
                           for j in idx)
        for i in idx:
            it = items[i]
            pred = None if last is None else res[last] + it["addr"] - items[last]["addr"]
            if pred is not None and i not in pins and not free(i, pred):
                pred = None
            if i in pins:
                # a pinned object may hold other values in the target (a longer table before it,
                # Japanese text): the code says where it is, its bytes come from the target
                res[i] = pins[i]
            elif pred is not None and pred >= cur and pred + it["size"] <= nextpin[i] and at(i, pred):
                res[i] = pred
            elif pred is not None and pred >= cur and nextpin_i[i] is not None and                     nextpin[i] - pred == items[nextpin_i[i]]["addr"] - it["addr"]:
                # between two pins whose distance did not change: the same layout, other values
                res[i] = pred
            elif pred is not None and not info[i][3] and any(it["data"]) and not info[i][4] and (
                    _near_short(it, timg, tbase, max(cur, pred), min(nextpin[i], pred + 0x40)) is not None):
                # a short object a few bytes after its predicted place (the target inserted
                # something before it): its first match close behind
                res[i] = _near_short(it, timg, tbase, max(cur, pred), min(nextpin[i], pred + 0x40))
            elif info[i][0] or (pred is not None and info[i][3]):
                pr = pred if pred is not None else (hint(it["addr"]) if hint else None)
                lo, hi = max(cur, windows[sec][0]), nextpin[i]
                if pr is not None:
                    lo, hi = max(lo, pr - reach), min(hi, pr + reach + it["size"])
                cands = [tbase + m.start() for m in info[i][1].finditer(timg, lo - tbase, hi - tbase)
                         if m.end() - m.start() == it["size"]]
                best = None
                if pred is None and len(cands) > 1:
                    # no matched object before it: similar objects (path strings) can match in
                    # several places; keep the place where the most following objects fit
                    after = [j for j in idx if j > i][:8]

                    def fits(c):
                        return sum(1 for j in after if at(j, c + items[j]["addr"] - it["addr"]))
                    best = max(cands, key=lambda c: (fits(c), -abs(c - pr) if pr is not None else -c))
                elif cands:
                    best = cands[0] if pr is None else min(cands, key=lambda c: abs(c - pr))
                res[i] = best
            if res[i] is not None:
                cur, last = res[i] + it["size"], i
        _trace("main", idx, res, items, pins, cand)
        # an object the code places out of order (moved in the target): put it at its pin when
        # nothing else is placed there
        for i in cand:
            if i in pins:
                continue
            # the object placed before it (by target address) must end there, and none may start
            # there; the object is cut at the next start later (it can be shorter in the target)
            lo_ = cand[i]
            if res[i] == lo_:
                continue
            same = [j for j in idx if j != i and res[j] == lo_]
            if os.environ.get("JATAIL_TRACE") and same:
                print("  swapcheck %08X same %08X sizes %d %d cand %s at %s %s" % (items[i]["addr"], items[same[0]]["addr"],
                      items[i]["size"], items[same[0]]["size"], same[0] in cand, at(i, lo_), res[i] is not None and at(same[0], res[i])))
            if same and res[i] is not None and items[same[0]]["size"] == items[i]["size"] and                     (cand.get(same[0]) == res[i] or (same[0] not in cand and same[0] not in pins
                                                     and at(i, lo_))):
                # two objects of the same size that the target swapped (similar tables)
                res[i], res[same[0]] = res[same[0]], res[i]
                continue
            before = [j for j in idx if j != i and res[j] is not None and res[j] <= lo_]
            if before and max(res[j] for j in before) == lo_:
                continue
            pj = max(before, key=lambda j: res[j]) if before else None
            if pj is None or res[pj] + items[pj]["size"] <= lo_:
                res[i] = cand[i]
        _trace("moved", idx, res, items, pins, cand)
        # unmatched objects before a matched one: backward from it
        nxt = None
        for i in reversed(idx):
            if res[i] is not None:
                nxt = i
            elif nxt is not None:
                t = res[nxt] - (items[nxt]["addr"] - items[i]["addr"])
                prev = [j for j in idx if j < i and res[j] is not None]
                lo = res[prev[-1]] + items[prev[-1]]["size"] if prev else windows[sec][0]
                if (t >= lo or not any(res[j] is not None and res[j] < t + items[i]["size"] and t < res[j] + items[j]["size"]
                                       for j in idx)) and t >= windows[sec][0] and at(i, t) and free(i, t):
                    res[i] = t
                    nxt = i
        # an object of pointers only could not be searched: try the rough place of the hint, when it
        # fits between its matched neighbours
        if hint:
            for k, i in enumerate(idx):
                if res[i] is None and info[i][2]:
                    pv = [j for j in idx[:k] if res[j] is not None]
                    nx = [j for j in idx[k + 1:] if res[j] is not None]
                    lo = res[pv[-1]] + items[pv[-1]]["size"] if pv else windows[sec][0]
                    hi = res[nx[0]] if nx else windows[sec][1]
                    t = hint(items[i]["addr"])
                    if t is not None and t >= lo and t + items[i]["size"] <= hi and at(i, t):
                        res[i] = t
        # an unplaced object of 8 bytes or more whose size is exactly a hole between placed objects,
        # with content that fits there (a table the target moved before its neighbour)
        for i in idx:
            if res[i] is not None or items[i]["size"] < 8:
                continue
            pl = sorted((res[j], res[j] + items[j]["size"]) for j in idx if res[j] is not None)
            for (a1, b1), (a2, _b2) in zip(pl, pl[1:]):
                if a2 - b1 == items[i]["size"] and at(i, b1):
                    res[i] = b1
                    break
        # prefix match, then free places, inside each run between matched objects
        k = 0
        while k < len(idx):
            if res[idx[k]] is not None:
                k += 1
                continue
            e = k
            while e < len(idx) and res[idx[e]] is None:
                e += 1
            run = idx[k:e]
            lo = res[idx[k - 1]] + items[idx[k - 1]]["size"] if k else windows[sec][0]
            hi = res[idx[e]] if e < len(idx) else windows[sec][1]
            # objects placed out of link order inside [lo, hi) hold their bytes: skip them
            occ = sorted((res[j], res[j] + items[j]["size"]) for j in idx if res[j] is not None and lo <= res[j] < hi)

            def skip(t, n):
                for a_, b_ in occ:
                    if t < b_ and a_ < t + n:
                        t = b_
                return t
            cur = lo
            for i in run:
                it = items[i]
                done = False
                if info[i][0] and it["size"] > 24:
                    m = _pattern(it["addr"], it["data"], 24).search(timg, cur - tbase, hi - tbase)
                    if m:
                        res[i] = tbase + m.start()
                        done = True
                if not done:
                    al = 4 if it["addr"] % 4 == 0 else 1
                    t = skip((cur + al - 1) & ~(al - 1), it["size"])
                    if t < hi:
                        res[i] = t
                if res[i] is not None:
                    cur = res[i] + min(it["size"], max(hi - res[i], 0))
            k = e
        _trace("final", idx, res, items, pins, cand)
    return res


def blocks_for(items, starts):
    """[black start, black end, target start] for each placed item, in Black address order."""
    return [[it["addr"], it["addr"] + it["size"], t] for it, t in zip(items, starts) if t is not None]
