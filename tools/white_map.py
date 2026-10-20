#!/usr/bin/env python3
"""white_map.py -- Black address -> White address, for building White from the same source.

Pokemon White's ARM9 static module is 0x20 bytes longer and several blocks of it moved, and
every overlay loads 0x20 higher.  to_white(a) maps an address of the Black image to the
address of the same thing in White:

  below the ARM9 static module (ITCM, DTCM, IO, BIOS)   unchanged
  inside the ARM9 static module, in code or data that
    lines up with a White block                          moved by that block's offset
  inside it, in code that has no White twin             KeyError (the caller reports it)
  from the end of the static module upwards (static bss,
    overlay RAM)                                         + the growth of the module (0x20)

The blocks come from the same word alignment tools/white_diff.py uses (relocation-wildcarded
words, difflib), over extract/ and extract_white/ (both gitignored).  The result is cached in
build/white/arm9_map.json.  Stdlib only.  Never stores or prints game bytes.
"""
import bisect
import re
import difflib
import json
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CACHE = os.path.join(ROOT, "build", "white", "arm9_map.json")
MAIN_MEMORY_END = 0x02400000
SECURE = 0x800          # the secure area is encrypted with the game code: not compared

_MAP = None


def _build():
    import sys
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    from white_align import mask_words
    lb = json.load(open(os.path.join(ROOT, "layout", "layout.json"), encoding="utf-8"))
    lw = json.load(open(os.path.join(ROOT, "build", "white", "layout", "layout.json"), encoding="utf-8"))
    sb, sw = lb["arm9"]["static"], lw["arm9"]["static"]
    ab = open(os.path.join(ROOT, "extract", "arm9_dec.bin"), "rb").read()[:sb["size"]]
    aw = open(os.path.join(ROOT, "extract_white", "arm9_dec.bin"), "rb").read()[:sw["size"]]
    mb, mw = mask_words(ab[SECURE:]), mask_words(aw[SECURE:])
    sm = difflib.SequenceMatcher(None, mb, mw, autojunk=False)
    blocks = []     # [black start, black end, white start] as addresses
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        # a block of changed words of the same length (a constant that differs) keeps its place
        if tag == "equal" or (tag == "replace" and i2 - i1 == j2 - j1):
            blocks.append((sb["ram_start"] + SECURE + i1 * 4, sb["ram_start"] + SECURE + i2 * 4,
                           sw["ram_start"] + SECURE + j1 * 4))
    # The secure area: the SVC thunks (`swi N; bx lr`) sit at other offsets in White, between
    # filler bytes that are different too.  A thunk is found by its swi number (one each).
    def thunks(d):
        return {d[k]: k for k in range(SECURE - 3) if d[k + 1:k + 4] == bytes([0xdf, 0x70, 0x47])}
    tb, tw = thunks(ab), thunks(aw)
    secure_map = {str(sb["ram_start"] + tb[n]): sw["ram_start"] + tw[n] for n in tb if n in tw}
    return dict(static_start=sb["ram_start"], black_end=sb["ram_end"], white_end=sw["ram_end"],
                secure=SECURE, blocks=blocks, secure_map=secure_map)


def _load():
    global _MAP
    if _MAP is None:
        try:
            _MAP = json.load(open(CACHE, encoding="utf-8"))
            if "secure_map" not in _MAP:
                raise ValueError("old cache")
        except (OSError, ValueError):
            _MAP = _build()
            os.makedirs(os.path.dirname(CACHE), exist_ok=True)
            with open(CACHE, "w", newline="\n") as fh:
                json.dump(_MAP, fh)
        _MAP["_starts"] = [b[0] for b in _MAP["blocks"]]
    return _MAP


_ROWS = None
TSV = os.path.join(ROOT, "docs", "restructure", "white_diff.tsv")


def _rows():
    """region -> (sorted [(black address, White address)], starts) of the function rows of white_diff.tsv."""
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


def _ov_blocks(region):
    """Word alignment of overlay `region` in Black and White (relocation-wildcarded words,
    difflib, like the ARM9 map): [black start, black end, white start] address blocks, cached
    in build/white/ovmap_ovNNN.json.  Code and data both move by it."""
    if region in _OVB:
        return _OVB[region]
    cache = os.path.join(ROOT, "build", "white", "ovmap_%s.json" % region)
    try:
        blocks = json.load(open(cache, encoding="utf-8"))
    except (OSError, ValueError):
        import sys
        sys.path.insert(0, os.path.join(ROOT, "tools"))
        import white_diff as D
        from white_align import mask_words
        n = int(region[2:])
        lb = json.load(open(os.path.join(ROOT, "layout", "layout.json"), encoding="utf-8"))
        lw = json.load(open(os.path.join(ROOT, "build", "white", "layout", "layout.json"), encoding="utf-8"))
        ob, ow = lb["overlays"][n], lw["overlays"][n]
        rb = D.rd(os.path.join(ROOT, "extract", ob.get("decompressed_file") or ob["file"]))
        rw = D.rd(os.path.join(ROOT, "extract_white", ow.get("decompressed_file") or ow["file"]))
        blocks = []
        for tag, i1, i2, j1, j2 in D.aligned_ops(mask_words(rb), mask_words(rw)):
            if tag == "equal" or (tag == "replace" and i2 - i1 == j2 - j1):
                blocks.append([ob["ram_start"] + i1 * 4, ob["ram_start"] + i2 * 4, ow["ram_start"] + j1 * 4])
        os.makedirs(os.path.dirname(cache), exist_ok=True)
        with open(cache, "w", newline="\n") as fh:
            json.dump(blocks, fh)
    _OVB[region] = (blocks, [b[0] for b in blocks])
    return _OVB[region]


def to_white_ov(region, a):
    """White address of the Black address `a` inside overlay `region` ("ov021"): through the
    aligned block that holds it; between blocks, the shift of the block before."""
    if region not in _rows():
        raise KeyError("no White rows for %s" % region)
    blocks, starts = _ov_blocks(region)
    k = max(bisect.bisect_right(starts, a) - 1, 0)
    s, e, w = blocks[k]
    if a < e:
        return w + (a - s)
    return a + (w - s)


def to_black_ov(region, w):
    """Black address of the White address `w` inside overlay `region`: the inverse of to_white_ov
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
    """Black address of the White address `w` in the ARM9 static module: the inverse of to_white
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


IRREGULAR = ("ov021", "ov172", "ov088", "ov181", "ov203", "ov204")


def guess_callee_region(a):
    """The overlay of a callee that no header annotates: the irregular overlay (code moved
    inside it) that has a function starting exactly at the Black address `a`, ov021 first."""
    if a < 0x02100000:
        return None
    for r in IRREGULAR:
        rows = _rows().get(r)
        if rows:
            i = bisect.bisect_left(rows[1], a & ~1)
            if i < len(rows[1]) and rows[1][i] == (a & ~1):
                return r
    return None


def to_white(a, region=None):
    """White address of the Black address `a` (a Thumb function keeps its low bit).
    `region`: the overlay `a` belongs to, when it is one whose code moved inside it."""
    bit = a & 1
    if (a & ~1) >= MAIN_MEMORY_END:
        return a            # the DSi block (0x02700000..), DTCM, WRAM, IO, VRAM: the same in both games
    if region and region.startswith("ov") and a >= 0x02100000:
        try:
            return to_white_ov(region, a & ~1) | bit
        except KeyError:
            pass
    m = _load()
    a &= ~1
    lo = m["static_start"]
    if a < lo:
        return a | bit
    if a >= MAIN_MEMORY_END:
        return a | bit      # DTCM, shared WRAM, IO, VRAM, outside every region
    if a >= m["black_end"]:
        return a + (m["white_end"] - m["black_end"]) | bit
    if a < lo + m["secure"]:
        return m.get("secure_map", {}).get(str(a), a) | bit
    k = bisect.bisect_right(m["_starts"], a) - 1
    if k >= 0:
        s, e, w = m["blocks"][k]
        if a < e:
            return w + (a - s) | bit
    raise KeyError("0x%08X has no White twin in the ARM9 static module" % a)


def to_black(a):
    """Inverse for the overlay RAM window only (every overlay loads 0x20 higher in White)."""
    m = _load()
    d = m["white_end"] - m["black_end"]
    if MAIN_MEMORY_END <= a:
        return a            # the DSi block and everything above main memory: not moved
    if a >= m["white_end"]:
        return a - d
    raise KeyError("0x%08X is not in the overlay window" % a)


if __name__ == "__main__":
    import sys
    for x in sys.argv[1:]:
        print("0x%08X -> 0x%08X" % (int(x, 16), to_white(int(x, 16))))


_LIT = None


def remap_source(text, path):
    """White build: the source text with every 0x02xxxxxx address literal mapped from its Black
    address to the White one.  The sources of src/game hold the addresses of overlay data and
    ARM9 data as literals; an overlay loads 0x20 higher in White (more inside the overlays whose
    code moved), so the same literal is a different number.  `path` names the file: the overlay
    it belongs to (src/game/ovNNN/) decides how addresses inside that overlay move.  Anything
    that has no White twin stays as it is."""
    import re
    global _LIT
    if _LIT is None:
        _LIT = re.compile(r"(?<![0-9A-Za-z_])0[xX](0?2[0-9A-Fa-f]{6})(?![0-9A-Za-z_])")
        lb = json.load(open(os.path.join(ROOT, "layout", "layout.json"), encoding="utf-8"))
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
        return mo.group(0)[:2] + ("%08X" if len(mo.group(1)) == 8 else "%07X") % w
    return rx.sub(sub, text)
