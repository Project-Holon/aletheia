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
import re
import struct


def _addr_like(w):
    return (0x01FF0000 <= w < 0x02800000 or 0x02FE0000 <= w < 0x03000000
            or 0x03800000 <= w < 0x03810000 or 0x04000000 <= w < 0x04100000
            or 0x06000000 <= w < 0x06A00000)


def _pattern(addr, data, n=None):
    """Regex for the first n bytes of `data` (at Black address addr): aligned address-like words
    are four wildcard bytes."""
    n = len(data) if n is None else min(n, len(data))
    out, i = [], 0
    while i < n:
        if (addr + i) % 4 == 0 and i + 4 <= n and _addr_like(struct.unpack_from("<I", data, i)[0]):
            out.append(b"....")
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


def align(items, timg, tbase, windows, hint=None, reach=0x800, pin=None):
    """Target start per item (None when unmatched).  `items`: dicts addr, size, data, sec in link
    order.  `windows`: {sec: (lo, hi)} target address ranges to search; timg is the target image
    loaded at tbase.  `hint(addr)`: rough target address (the word-block map) for an object when no
    object before it is matched; a search stays within `reach` bytes of the predicted place and
    takes the occurrence nearest to it.  `pin(addr)`: exact target address of an object that the
    code references (the literal pools of matching functions), or None; it wins when the object's
    content fits there."""
    n = len(items)
    res = [None] * n
    info = [_info(it) for it in items]

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
        cur, last = windows[sec][0], None
        for i in idx:
            it = items[i]
            pred = None if last is None else res[last] + it["addr"] - items[last]["addr"]
            pn = pin(it["addr"]) if pin else None
            if pn is not None and pn >= cur and (at(i, pn) or (not info[i][4] and pn + it["size"] <= windows[sec][1])):
                # a pinned object without pointers may hold other values in the target (a longer
                # table before it, Japanese text): the code says where it is, its bytes come from the target
                res[i] = pn
            elif pred is not None and pred >= cur and at(i, pred):
                res[i] = pred
            elif info[i][0] or (pred is not None and info[i][3]):
                pr = pred if pred is not None else (hint(it["addr"]) if hint else None)
                lo, hi = max(cur, windows[sec][0]), windows[sec][1]
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
        # unmatched objects before a matched one: backward from it
        nxt = None
        for i in reversed(idx):
            if res[i] is not None:
                nxt = i
            elif nxt is not None:
                t = res[nxt] - (items[nxt]["addr"] - items[i]["addr"])
                prev = [j for j in idx if j < i and res[j] is not None]
                lo = res[prev[-1]] + items[prev[-1]]["size"] if prev else windows[sec][0]
                if t >= lo and at(i, t):
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
                    t = (cur + al - 1) & ~(al - 1)
                    if t < hi:
                        res[i] = t
                if res[i] is not None:
                    cur = res[i] + min(it["size"], max(hi - res[i], 0))
            k = e
    return res


def blocks_for(items, starts):
    """[black start, black end, target start] for each placed item, in Black address order."""
    return [[it["addr"], it["addr"] + it["size"], t] for it, t in zip(items, starts) if t is not None]
