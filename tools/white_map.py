#!/usr/bin/env python3
"""white_map.py -- Black address -> address in another cartridge (White, or a language ROM).

The source of src/game is planned in Black's addresses.  Every other target (tools/targets.py:
white, black_fr, white_fr, black_de, ...) has its ARM9 static module a different length with
blocks of it moved, and its overlays load at other addresses (some with code moved inside).
to_white(a) maps an address of the Black image to the address of the same thing in the target
(the name stays from the time White was the only other game):

  below the ARM9 static module (ITCM, DTCM, IO, BIOS)   unchanged
  inside the ARM9 static module, in code or data that
    lines up with a block of the target                  moved by that block's offset
  inside it, in code that has no twin                    KeyError (the caller reports it)
  from the end of the static module upwards (static bss,
    overlay RAM)                                         + the growth of the module
  inside an overlay named by the caller                  through that overlay's block map

The blocks come from the word alignment tools/white_diff.py uses (relocation-wildcarded
words, difflib), over extract/ and the target's extract (extract_<t>/, gitignored).  Results are
cached in build/<t>/arm9_map.json and build/<t>/ovmap_ovNNN.json.  The target is the one set by
set_target(), else ALETHEIA_TARGET / ALETHEIA_VERSION, else white.  Stdlib only.  Never stores
or prints game bytes.

    python tools/white_map.py [--target T] 0x02012345 ...     map addresses
    python tools/white_map.py [--target T] scan [--jobs N]    align every overlay, write
                                                              build/<t>/irregular.json
    python tools/white_map.py --target T irregular            list the overlays whose code moved
                                                              or whose size differs
"""
import bisect
import re
import difflib
import json
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402

MAIN_MEMORY_END = 0x02400000
SECURE = 0x800          # the secure area is encrypted with the game code: not compared

_T = None


def set_target(t):
    """Map to target `t` (a name of tools/targets.py) from now on."""
    global _T
    if t not in targets.TARGETS or t == "black":
        raise ValueError("white_map: %r is not a target to map to" % (t,))
    _T = t


def target():
    """The target being mapped to: set_target(), else the environment, else white."""
    if _T:
        return _T
    t = targets.current()
    return "white" if t == "black" else t


def _cache(name, t=None):
    return os.path.join(targets.build_dir(t or target()), name)


_LAYOUTS = {}


def _lay(t):
    if t not in _LAYOUTS:
        with open(os.path.join(targets.layout_dir(t), "layout.json"), encoding="utf-8") as fh:
            _LAYOUTS[t] = json.load(fh)
    return _LAYOUTS[t]


def _ov_rec(lay, n):
    return [o for o in lay["overlays"] if o["id"] == n][0]


_MAPS = {}


def _build(t):
    from white_align import mask_words
    lb, lw = _lay("black"), _lay(t)
    sb, sw = lb["arm9"]["static"], lw["arm9"]["static"]
    ab = open(os.path.join(targets.extract_dir("black"), "arm9_dec.bin"), "rb").read()[:sb["size"]]
    aw = open(os.path.join(targets.extract_dir(t), "arm9_dec.bin"), "rb").read()[:sw["size"]]
    mb, mw = mask_words(ab[SECURE:]), mask_words(aw[SECURE:])
    sm = difflib.SequenceMatcher(None, mb, mw, autojunk=False)
    blocks = []     # [black start, black end, target start] as addresses
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        # a block of changed words of the same length (a constant that differs) keeps its place
        if tag == "equal" or (tag == "replace" and i2 - i1 == j2 - j1):
            blocks.append((sb["ram_start"] + SECURE + i1 * 4, sb["ram_start"] + SECURE + i2 * 4,
                           sw["ram_start"] + SECURE + j1 * 4))
    # The secure area: the SVC thunks (`swi N; bx lr`) sit at other offsets in the other games,
    # between filler bytes that are different too.  A thunk is found by its swi number (one each).
    def thunks(d):
        return {d[k]: k for k in range(SECURE - 3) if d[k + 1:k + 4] == bytes([0xdf, 0x70, 0x47])}
    tb, tw = thunks(ab), thunks(aw)
    secure_map = {str(sb["ram_start"] + tb[n]): sw["ram_start"] + tw[n] for n in tb if n in tw}
    return dict(static_start=sb["ram_start"], black_end=sb["ram_end"], white_end=sw["ram_end"],
                secure=SECURE, blocks=blocks, secure_map=secure_map)


def _load(t=None):
    t = t or target()
    if t not in _MAPS:
        cache = _cache("arm9_map.json", t)
        try:
            m = json.load(open(cache, encoding="utf-8"))
            if "secure_map" not in m:
                raise ValueError("old cache")
        except (OSError, ValueError):
            m = _build(t)
            os.makedirs(os.path.dirname(cache), exist_ok=True)
            with open(cache, "w", newline="\n") as fh:
                json.dump(m, fh)
        m["_starts"] = [b[0] for b in m["blocks"]]
        _MAPS[t] = m
    return _MAPS[t]


_ROWS = None
TSV = os.path.join(ROOT, "docs", "restructure", "white_diff.tsv")


def _rows():
    """region -> (sorted [(black address, White address)], starts) of the function rows of white_diff.tsv.
    The Black addresses hold for every target; the White ones are White's."""
    global _ROWS
    if _ROWS is None:
        raw = {}
        with open(TSV, encoding="utf-8") as fh:
            next(fh)
            for line in fh:
                f = line.rstrip("\n").split("\t")
                if len(f) >= 4 and f[1] != "-" and f[2] != "-":
                    raw.setdefault(f[0], []).append((int(f[1], 16), int(f[2], 16)))
        _ROWS = {}
        for k, v in raw.items():
            v.sort()
            _ROWS[k] = (v, [b for b, _w in v])
    return _ROWS


_OVB = {}


def _ov_blocks(region, t=None, anchor=True):
    """Word alignment of overlay `region` in Black and the target (relocation-wildcarded words,
    difflib, like the ARM9 map): [black start, black end, target start] address blocks, cached
    in build/<t>/ovmap_ovNNN.json.  Code and data both move by it."""
    t = t or target()
    if (t, region, anchor) in _OVB:
        return _OVB[(t, region, anchor)]
    cache = _cache("ovmap_%s.json" % region, t)
    try:
        blocks = json.load(open(cache, encoding="utf-8"))
    except (OSError, ValueError):
        import white_diff as D
        from white_align import mask_words
        n = int(region[2:])
        ob, ow = _ov_rec(_lay("black"), n), _ov_rec(_lay(t), n)
        rb = D.rd(os.path.join(targets.extract_dir("black"), ob.get("decompressed_file") or ob["file"]))
        rw = D.rd(os.path.join(targets.extract_dir(t), ow.get("decompressed_file") or ow["file"]))
        blocks = []
        for tag, i1, i2, j1, j2 in D.aligned_ops(mask_words(rb), mask_words(rw)):
            if tag == "equal" or (tag == "replace" and i2 - i1 == j2 - j1):
                blocks.append([ob["ram_start"] + i1 * 4, ob["ram_start"] + i2 * 4, ow["ram_start"] + j1 * 4])
        os.makedirs(os.path.dirname(cache), exist_ok=True)
        with open(cache, "w", newline="\n") as fh:
            json.dump(blocks, fh)
    # Code before the first aligned block (its first words differ) keeps the shift of the image
    # start: an anchor block at the load addresses stops the block shift being extrapolated back.
    n = int(region[2:])
    ob, ow = _ov_rec(_lay("black"), n), _ov_rec(_lay(t), n)
    if anchor and blocks and blocks[0][0] > ob["ram_start"] + 4:
        blocks = [[ob["ram_start"], ob["ram_start"] + 4, ow["ram_start"]]] + blocks
    _OVB[(t, region, anchor)] = (blocks, [b[0] for b in blocks])
    return _OVB[(t, region, anchor)]


def to_white_ov(region, a):
    """Target address of the Black address `a` inside overlay `region` ("ov021"): through the
    aligned block that holds it; between blocks, the shift of the block before."""
    if target() == "white" and region not in _rows():
        raise KeyError("no White rows for %s" % region)
    blocks, starts = _ov_blocks(region)
    if not blocks:
        raise KeyError("no aligned block in %s" % region)
    k = max(bisect.bisect_right(starts, a) - 1, 0)
    s, e, w = blocks[k]
    if a < e:
        return w + (a - s)
    return a + (w - s)


def to_black_ov(region, w):
    """Black address of the target address `w` inside overlay `region`: the inverse of to_white_ov
    (through the aligned block that holds it; between blocks, the shift of the block before)."""
    blocks, _starts = _ov_blocks(region)
    wb = sorted(blocks, key=lambda b: b[2])
    ws = [b[2] for b in wb]
    k = max(bisect.bisect_right(ws, w) - 1, 0)
    s, e, w0 = wb[k]
    if w < w0 + (e - s):
        return s + (w - w0)
    return w - (w0 - s)


def to_black_arm9(w):
    """Black address of the target address `w` in the ARM9 static module: the inverse of to_white
    (through the aligned block that holds it; between blocks, the shift of the block before)."""
    m = _load()
    if w < m["static_start"] or w >= m["white_end"]:
        return w
    if w < m["static_start"] + m["secure"]:
        inv = {v: int(k) for k, v in m.get("secure_map", {}).items()}
        return inv.get(w, w)
    wb = sorted(m["blocks"], key=lambda b: b[2])
    ws = [b[2] for b in wb]
    k = max(bisect.bisect_right(ws, w) - 1, 0)
    s, e, w0 = wb[k]
    if w < w0 + (e - s):
        return s + (w - w0)
    return w - (w0 - s)


IRREGULAR = ("ov021", "ov172", "ov088", "ov181", "ov203", "ov204")     # White: code moved inside


def global_shift(t=None):
    """How far the overlay RAM window moves in the target: its static module grows by this."""
    m = _load(t)
    return m["white_end"] - m["black_end"]


def overlay_report(t=None):
    """{region: dict(shift, size_differs, shifts)} for every overlay of the target: `shift` is
    the difference of the load addresses, `shifts` the sorted distinct block shifts of the word
    alignment (more than one: code moved inside), `size_differs` the decompressed sizes."""
    t = t or target()
    lb, lw = _lay("black"), _lay(t)
    out = {}
    for ob, ow in zip(lb["overlays"], lw["overlays"]):
        r = "ov%03d" % ob["id"]
        blocks, _s = _ov_blocks(r, t, anchor=False)
        out[r] = dict(shift=ow["ram_start"] - ob["ram_start"],
                      size_differs=ob["decompressed_size"] != ow["decompressed_size"],
                      shifts=sorted({w - s for s, _e, w in blocks}))
    return out


def irregular(t=None):
    """The overlays the link treats as moved (gamelink OWN_OVERLAY): code that moved inside, a
    size that differs, or a load address that is not the window's shift.  White keeps the list
    it was proven with (IRREGULAR); every other target gets its list from the alignment
    (cached in build/<t>/irregular.json, made by `white_map.py --target T scan`)."""
    t = t or target()
    if t == "white":
        return IRREGULAR
    cache = _cache("irregular.json", t)
    try:
        return tuple(json.load(open(cache, encoding="utf-8")))
    except (OSError, ValueError):
        pass
    g = global_shift(t)
    res = tuple(sorted(r for r, v in overlay_report(t).items()
                       if v["size_differs"] or len(v["shifts"]) > 1 or v["shift"] != g))
    os.makedirs(os.path.dirname(cache), exist_ok=True)
    with open(cache, "w", newline="\n") as fh:
        json.dump(res, fh)
    return res


def guess_callee_region(a):
    """The overlay of a callee that no header annotates: the irregular overlay (code moved
    inside it) that has a function starting exactly at the Black address `a`, ov021 first."""
    if a < 0x02100000:
        return None
    order = IRREGULAR if target() == "white" else sorted(irregular(), key=lambda r: (r != "ov021", r))
    for r in order:
        rows = _rows().get(r)
        if rows:
            i = bisect.bisect_left(rows[1], a & ~1)
            if i < len(rows[1]) and rows[1][i] == (a & ~1):
                return r
    return None


_WIN = {}


def _window_shift(a, t):
    """Shift of the overlay RAM at Black address `a` when every overlay that holds `a` loads
    at the same offset in the target; None when they differ (or none holds it)."""
    if t not in _WIN:
        lb, lw = _lay("black"), _lay(t)
        _WIN[t] = [(ob["ram_start"], max(ob["ram_end"], ob["bss_end"]), ow["ram_start"] - ob["ram_start"])
                   for ob, ow in zip(lb["overlays"], lw["overlays"])]
    sh = {d for lo, hi, d in _WIN[t] if lo <= a < hi}
    return next(iter(sh)) if len(sh) == 1 else None


_EXACT = {}
_EXSTARTS = {}
USE_EXACT = os.environ.get("ALETHEIA_NO_EXACT") is None     # gamelink turns it off while it links arm9_main itself


def _link_syms(path, data):
    """{name: address} of the global symbols a link left in ov.elf: functions (and, when `data`,
    objects) that sit in a real section.  Empty when the file is missing."""
    try:
        import gamelink
        _d, _secs, syms = gamelink.read_elf(path)
    except (OSError, ImportError, ValueError, KeyError):
        return {}
    out = {}
    for y in syms:
        if y["name"] and (y["info"] >> 4) == 1 and 0 < y["shndx"] < 0xFF00 and (y["info"] & 15) in ((1, 2) if data else (2,)):
            out[y["name"]] = (y["value"] & ~1, y["size"])
    return out


def _link_ok(path):
    try:
        return bool(json.load(open(os.path.join(os.path.dirname(path), "ov.json"), encoding="utf-8")).get("ok"))
    except (OSError, ValueError):
        return False


def exact_map(region, t=None):
    """{Black address: (target address, size)} of the symbols of `region` ("arm9" for arm9_main, "ovNNN")
    that the target's own passing link placed, joined with Black's link by name.  The alignment
    map is wrong for a function whose size changed (the map assumes the words before it line up);
    a passing link knows the real place.  Functions come from build/gamelink/<region>_<t>/,
    functions and data from build/gamelink_data/<region>_<t>/ when that link passes too.  {} when
    no link passes (the caller falls back to the alignment)."""
    t = t or target()
    key = (t, region)
    if key in _EXACT:
        return _EXACT[key]
    res = {}
    if t != "black" and USE_EXACT:
        rn = "arm9_main" if region == "arm9" else region
        for sub, data in (("gamelink", False), ("gamelink_data", True)):
            tp = os.path.join(ROOT, "build", sub, "%s_%s" % (rn, t), "ov.elf")
            bp = os.path.join(ROOT, "build", sub, rn, "ov.elf")
            if not (os.path.exists(tp) and os.path.exists(bp) and _link_ok(tp) and _link_ok(bp)):
                continue
            bs, ts = _link_syms(bp, data), _link_syms(tp, data)
            for n, (ba, bsz) in bs.items():
                if n in ts:
                    res[ba] = (ts[n][0], min(bsz, ts[n][1]))
    _EXACT[key] = res
    return res


_IMGS = {}
_GUESS = {}
_EXPL = {}
_CTX = {"region": None}
_CTXW = {}


def set_context(region):
    """The module being linked ("arm9" or "ovNNN"; None for no context): its literal pools are the
    evidence guess_data_region reads."""
    _CTX["region"] = region
    if region:
        os.environ["ALETHEIA_CTX_REGION"] = region     # compile workers in other processes read it
    else:
        os.environ.pop("ALETHEIA_CTX_REGION", None)


def _ov_image(t, n):
    key = (t, n)
    if key not in _IMGS:
        o = _ov_rec(_lay(t), n)
        try:
            with open(os.path.join(targets.extract_dir(t), o.get("decompressed_file") or o["file"]), "rb") as fh:
                _IMGS[key] = (o["ram_start"], fh.read())
        except OSError:
            _IMGS[key] = (o["ram_start"], b"")
    return _IMGS[key]


def _ctx_words(t, region):
    """Counter of the 4-aligned words of the module `region` in target `t` (Black for "black")."""
    import struct
    from collections import Counter
    key = (t, region)
    if key not in _CTXW:
        if region == "arm9":
            st = _lay(t)["arm9"]["static"]
            with open(os.path.join(targets.extract_dir(t), _lay(t)["arm9"]["decompressed_file"]), "rb") as fh:
                img = fh.read()[st["src_offset"]:st["src_offset"] + st["size"]]
        else:
            img = _ov_image(t, int(region[2:]))[1]
        n = len(img) // 4
        _CTXW[key] = Counter(struct.unpack("<%dI" % n, img[:n * 4]))
    return _CTXW[key]


def guess_data_region(a, t=None):
    """Target address of the data at the Black address `a` of an overlay that no header names, from
    the literal pools of the module being linked (set_context): each overlay that covers `a`
    gives a candidate address (its alignment); the one whose number of words in the target's
    module equals the number of words `a` in Black's module wins.  None when no context is
    set, or when none or several candidates agree."""
    t = t or target()
    reg = _CTX["region"] or os.environ.get("ALETHEIA_CTX_REGION")
    key = (t, reg, a)
    if key in _GUESS:
        return _GUESS[key]
    res = None
    if t != "black" and reg and (reg == "arm9" or reg.startswith("ov")):
        bc = _ctx_words("black", reg).get(a, 0)
        if bc:
            tw = _ctx_words(t, reg)
            cands = set()
            for ob in _lay("black")["overlays"]:
                if ob["ram_start"] <= a < max(ob["ram_end"], ob["bss_end"]):
                    try:
                        m = to_white_ov("ov%03d" % ob["id"], a)
                    except KeyError:
                        continue
                    if tw.get(m, 0) == bc:
                        cands.add(m)
            res = next(iter(cands)) if len(cands) == 1 else None
    _GUESS[key] = res
    return res


def refine(a, m, t=None):
    """Check the target address `m` that the alignment gave for the Black pointer value `a` (low
    Thumb bit included) against the literal pools of the module being linked (set_context): the
    word `a` occurs N times in Black's module, so the right target word occurs N times in the
    target's.  When `m` does not, and exactly one address within 0x80 bytes does, that one is the
    address; otherwise `m` stays.  Only for the overlay window and the ARM9 data (a >= 0x02000000)."""
    t = t or target()
    reg = _CTX["region"] or os.environ.get("ALETHEIA_CTX_REGION")
    if t == "black" or not reg or not (reg == "arm9" or reg.startswith("ov")) or a < 0x02000000 or a >= MAIN_MEMORY_END:
        return m
    bc = _ctx_words("black", reg).get(a, 0)
    if not bc:
        return m
    tw = _ctx_words(t, reg)
    if tw.get(m, 0) == bc:
        return m
    key = (t, reg)
    if key not in _EXPL:
        # Words the alignment explains (the image of a Black word whose count matches) are done.  The
        # rest of Black's words (U) and of the target's words (T) are paired in address order, each
        # to the nearest unpaired target word within 0x80 bytes of its alignment image with the same
        # count, never going back (the pools of a module keep their order).
        bw_ = _ctx_words("black", reg)
        img, done = {}, set()
        U = []
        for v in sorted(bw_):
            if 0x02000000 <= v < MAIN_MEMORY_END:
                try:
                    mv = to_white(v & ~1, reg if reg.startswith("ov") else None, exact=False) | (v & 1)
                except KeyError:
                    continue
                if tw.get(mv, 0) == bw_[v]:
                    done.add(mv)
                else:
                    U.append((v, mv))
        T = sorted(c for c in tw if 0x02000000 <= c < MAIN_MEMORY_END and c not in done)
        res, last = {}, 0
        for v, mv in U:
            best = None
            for c in T:
                if c <= last or abs(c - mv) > 0x80 or tw[c] != bw_[v]:
                    continue
                if best is None or abs(c - mv) < abs(best - mv):
                    best = c
            if best is not None:
                res[v] = best
                last = best
        _EXPL[key] = res
    return _EXPL[key].get(a, m)


def exact_lookup(region, a, t=None):
    """Target address of the Black address `a` through exact_map: a symbol's start, or an address
    inside a symbol (same offset in the target; both sizes must cover it).  None when no
    passing link knows it."""
    m = exact_map(region, t)
    if not m:
        return None
    key = (t or target(), region)
    if key not in _EXSTARTS:
        _EXSTARTS[key] = sorted(m)
    st = _EXSTARTS[key]
    k = bisect.bisect_right(st, a) - 1
    if k < 0:
        return None
    ba = st[k]
    ta, sz = m[ba]
    if a == ba or a - ba < sz:
        return ta + (a - ba)
    return None


def to_white(a, region=None, exact=True):
    """Target address of the Black address `a` (a Thumb function keeps its low bit).
    `region`: the overlay `a` belongs to, when it is one whose code moved inside.
    `exact`: use the symbols of a passing link of the target (exact_map) before the alignment."""
    bit = a & 1
    if (a & ~1) >= MAIN_MEMORY_END:
        return a            # the DSi block (0x02700000..), DTCM, WRAM, IO, VRAM: the same in all games
    if region and region.startswith("ov") and a >= 0x02100000:
        x = exact_lookup(region, a & ~1) if exact else None
        if x is not None:
            return x | bit
        try:
            return to_white_ov(region, a & ~1) | bit
        except KeyError:
            pass
    m = _load()
    a &= ~1
    lo = m["static_start"]
    if a < lo:
        return a | bit
    if exact and lo <= a < m["black_end"]:
        x = exact_lookup("arm9", a)
        if x is not None:
            return x | bit
    if a >= MAIN_MEMORY_END:
        return a | bit      # DTCM, shared WRAM, IO, VRAM, outside every region
    if a >= m["black_end"]:
        if target() != "white":
            if exact and region is None:
                g_ = guess_data_region(a)
                if g_ is not None:
                    return g_ | bit
            d = _window_shift(a, target())      # one shift for every overlay that holds it
            if d is not None:
                return a + d | bit
        return a + (m["white_end"] - m["black_end"]) | bit
    if a < lo + m["secure"]:
        return m.get("secure_map", {}).get(str(a), a) | bit
    k = bisect.bisect_right(m["_starts"], a) - 1
    if k >= 0:
        s, e, w = m["blocks"][k]
        if a < e:
            return w + (a - s) | bit
        if target() != "white":
            # code that differs lies between two aligned blocks: it starts where the block
            # before it ends, so that block's shift places it (its own bytes differ for real)
            return a + (w - s) | bit
    raise KeyError("0x%08X has no %s twin in the ARM9 static module" % (a, target()))


def to_black(a):
    """Inverse for the overlay RAM window only (the window's shift)."""
    m = _load()
    d = m["white_end"] - m["black_end"]
    if MAIN_MEMORY_END <= a:
        return a            # the DSi block and everything above main memory: not moved
    if a >= m["white_end"]:
        return a - d
    raise KeyError("0x%08X is not in the overlay window" % a)


def _ov_blocks_job(a):
    _ov_blocks(*a)


def scan(t, jobs=4):
    """Align every overlay of target `t` (in parallel), write build/<t>/irregular.json, return the list."""
    from concurrent.futures import ProcessPoolExecutor
    regions = ["ov%03d" % o["id"] for o in _lay(t)["overlays"]]
    _load(t)
    with ProcessPoolExecutor(jobs) as ex:
        list(ex.map(_ov_blocks_job, [(r, t) for r in regions], chunksize=4))
    cache = _cache("irregular.json", t)
    if os.path.exists(cache) and t != "white":
        os.remove(cache)
    return irregular(t)


if __name__ == "__main__":
    args = sys.argv[1:]
    if args[:1] == ["--target"]:
        set_target(args[1])
        args = args[2:]
    if args[:1] == ["scan"]:
        jobs = int(args[args.index("--jobs") + 1]) if "--jobs" in args else 4
        r = scan(target(), jobs)
        print("%s: %d overlays irregular: %s" % (target(), len(r), " ".join(r)))
    elif args[:1] == ["irregular"]:
        print(" ".join(irregular()))
    else:
        for x in args:
            print("0x%08X -> 0x%08X" % (int(x, 16), to_white(int(x, 16))))


_LIT = None


def remap_source(text, path):
    """Non-Black build: the source text with every 0x02xxxxxx address literal mapped from its Black
    address to the target's.  The sources of src/game hold the addresses of overlay data and
    ARM9 data as literals; an overlay loads at another address in the target (more inside the overlays whose
    code moved), so the same literal is a different number.  `path` names the file: the overlay
    it belongs to (src/game/ovNNN/) decides how addresses inside that overlay move.  Anything
    that has no twin stays as it is."""
    import re
    global _LIT
    if _LIT is None:
        _LIT = re.compile(r"(?<![0-9A-Za-z_])0[xX](0?2[0-9A-Fa-f]{6})(?![0-9A-Za-z_])")
        lb = _lay("black")
        _LIT = (_LIT, {"ov%03d" % o["id"]: (o["ram_start"], max(o["ram_end"], o["bss_end"])) for o in lb["overlays"]})
        _LIT[1]["*"] = (0, max(v[1] for v in _LIT[1].values() if v[1] < MAIN_MEMORY_END))
    rx, rng = _LIT
    m = re.search(r"[/\\](ov[0-9]{3})[/\\]", path)
    own = m.group(1) if m else None
    lo, hi = rng.get(own, (0, 0))

    def sub(mo):
        a = int(mo.group(1), 16)
        m = _load()
        if a >= m["black_end"] and not lo <= a < hi and a >= rng["*"][1]:
            return mo.group(0)      # beyond every overlay: a memory-map limit, not a symbol
        try:
            w = to_white(a, own if lo <= a < hi else None)
        except KeyError:
            return mo.group(0)
        w = refine(a, w)
        return mo.group(0)[:2] + ("%08X" if len(mo.group(1)) == 8 else "%07X") % w
    return rx.sub(sub, text)
