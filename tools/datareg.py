#!/usr/bin/env python3
"""datareg.py: build the data object registry (layout/data_objects.json).

The registry lists standalone data objects of a region's data tail: address,
size, kind, name and, for pointer-bearing kinds, the target addresses.  It
holds NO data values: numeric tables are described by element type and count
only, strings by size only.  tools/datagen.py turns registry + the user's own
extracted image into typed C in a gitignored folder.

The classifier reads the image bytes (to decide kinds) and the disassembly
listings under asm/ (to find the tail and the object boundaries).  Only its
output, addresses/sizes/types/counts/names, is committed.

kinds: string, numeric (elem u8/u16/u32 + count), pointer_table (targets),
       struct (fields runs of u32/ptr + targets), zero, raw (byte array)

Regions: arm9 (fixed scout range), every overlay ovNNN (tail = everything
after the last traced code line of the overlay listing) and twl (the DSi-mode
block: the byte ranges between the src/game/twl files, TWL_RANGES, kept under the registry key twl_data; names from
TWL_NAMES, function targets named by layout/function_addrs.tsv).  Each object also
carries "ev", the evidence classes that fix its start: tail (region start),
label (listing label), datamap (layout/data_objects.txt, arm9), pool (a code
literal pool word names it), ptr (a pointer stored in the tail names it),
matched (a symbols: block of matched code names it), str (string split).  An
object whose ev is only tail/str has no outside witness for its start: it is a
boundary kept as large as the evidence allows.

usage: python tools/datareg.py [--region arm9 --region ov203 ...]
                               (no --region: arm9 and every overlay)
       python tools/datareg.py --report     per-region coverage table
"""
from __future__ import annotations

import argparse
import json
import os
import re
import struct
import sys
from collections import Counter

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REG_PATH = os.path.join(ROOT, "layout", "data_objects.json")
ASM = os.path.join(ROOT, "asm")

# Default regions: the ARM9 standalone tail (scout range) and the ov203 pilot.
ARM9_TAIL = (0x0209D86C, 0x020A9E80)

# twl: the bytes of the DSi block that no src/game/twl file writes (the gaps of tools/twllink.py with
# --image-gaps): the embedded DSP component, a pointer table of mi_sharedWram.c, the strings and one
# variable of the DSP files, and the zero padding up to the bss.  A range must lie between two files.
TWL_RANGES = ((0x02707CB4, 0x0272E9E8), (0x027301E0, 0x02730210), (0x02732D54, 0x02732D7C),
              (0x02732D81, 0x02732DA0))
# The registry key of region twl.  It is not "twl": tools/gamegaps.py and tools/tuboundary.py read the
# key of a region as "the data tail starts at range[0]", which is wrong for a block with data in the middle.
REG_KEY = {"twl": "twl_data"}
# twl object names, from the code that uses each object (see docs/WHITE.md "twl data")
TWL_NAMES = {
    0x02707CB4: "DSPi_StaticComponentG711",    # FS_CreateFileFromMemory(file, data, ...) in DSPi_OpenStaticComponentG711Core
    0x027301E0: "MIi_GetWramBankMasterFuncs",  # MI_GetWramBankMaster: funcs[type](bank), the _A/_B/_C functions
    0x027301EC: "MIi_GetWramMapStartFuncs",    # MI_GetWramMapStart
    0x027301F8: "MIi_SetWramBankEnableFuncs",  # MIi_SetWramBankEnable
    0x02730204: "MIi_SetWramBankMasterFuncs",  # MIi_SetWramBankMaster
    0x02732D54: "DSPi_ProcessNameFlagged",     # STD_CompareString(name, ...) == 0 sets flags |= 1
    0x02732D64: "DSPi_SegNameDataA",           # STD_SearchString(name, ...), bank A, flags & 8
    0x02732D68: "DSPi_SegNameDataAHigh",       # the same, size + 0x20000
    0x02732D6C: "DSPi_SegNameDataB",           # bank B, flags & 0x10
    0x02732D70: "DSPi_SegNameDataBHigh",
    0x02732D74: "DSPi_DefaultProcessName",     # DSP_InitProcessContext: src == 0
    0x02732D81: "twl_pad_02732D81",            # linker alignment up to the bss
}
# kind overrides where the byte classifier cannot know: the variable DSPi_SoundPriority is a word
TWL_FORCE = {0x02732D78: {"kind": "numeric", "elem": "u32", "count": 1, "name": "DSPi_SoundPriority"}}

CODE_RE = re.compile(r"/\* ([0-9A-F]{8})  ((?:[0-9A-F]{2} ?)+)")
DATA_RE = re.compile(r"^\s*\.(word|byte|short|hword)\s+(\S+)\s+/\* ([0-9A-F]{8})")
LABEL_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):")
SIZES = {"word": 4, "byte": 1, "short": 2, "hword": 2}


def hx(v):
    return "0x%08X" % v


def load_layout():
    with open(os.path.join(ROOT, "layout", "layout.json"), encoding="utf-8") as fh:
        return json.load(fh)


def region_image(layout, region):
    """(base, image bytes, listing path) of one region."""
    ex = os.path.join(ROOT, layout["extract_dir"])
    if region == "arm9":
        st = layout["arm9"]["static"]
        with open(os.path.join(ex, "arm9_dec.bin"), "rb") as fh:
            img = fh.read()
        return (st["ram_start"], img[st["src_offset"]:st["src_offset"] + st["size"]],
                os.path.join(ASM, "arm9", "main.s"))
    if region == "twl":
        t = layout["twl"]
        with open(os.path.join(ex, t["decompressed_file"]), "rb") as fh:
            img = fh.read()
        return (t["ram_start"], img[t["src_offset"]:t["src_offset"] + t["code_size"]],
                os.path.join(ASM, "twl", "twl.s"))
    m = re.fullmatch(r"ov(\d{3})", region)
    if not m:
        raise SystemExit("unknown region %r" % region)
    oid = int(m.group(1))
    for o in layout["overlays"]:
        if o["id"] == oid:
            with open(os.path.join(ex, o["decompressed_file"].replace("/", os.sep)), "rb") as fh:
                img = fh.read()
            return (o["ram_start"], img[:o["code_size"]],
                    os.path.join(ASM, "overlays", "ov%03d.s" % oid))
    raise SystemExit("no overlay %r" % region)


def scan_listing(path):
    """-> (last code end, data line list [(addr,size)], labels {addr:name},
    word values [(site, value)])."""
    code_end = 0
    data = []
    labels = {}
    words = []
    with open(path, "r", encoding="utf-8", errors="replace") as fh:
        for line in fh:
            m = DATA_RE.match(line)
            if m:
                a = int(m.group(3), 16)
                data.append((a, SIZES[m.group(1)]))
                if m.group(1) == "word":
                    try:
                        words.append((a, int(m.group(2), 0)))
                    except ValueError:
                        pass
                continue
            m = CODE_RE.search(line)
            if m:
                a = int(m.group(1), 16)
                n = len(m.group(2).split())
                if a + n > code_end:
                    code_end = a + n
                continue
            m = LABEL_RE.match(line)
            if m:
                name = m.group(1)
                h = re.search(r"([0-9A-F]{8})$", name)
                if h:
                    labels.setdefault(int(h.group(1), 16), name)
    return code_end, data, labels, words


SYM_RE = re.compile(r"^\s*\*\s+\S+\s+(0x[0-9A-Fa-f]{8})")
REGION_RE = re.compile(r"^ \* region:\s+(ov\d{3})")


def load_matched_addrs():
    """{region: set(addresses)} named by the symbols: blocks of matched overlay
    code (src/matched/ov, src/matched/ov_sdk).  Read-only; headers only."""
    out = {}
    for sub in ("ov", "ov_sdk"):
        d = os.path.join(ROOT, "src", "matched", sub)
        if not os.path.isdir(d):
            continue
        for fn in os.listdir(d):
            if not fn.endswith(".c"):
                continue
            region = None
            in_sym = False
            with open(os.path.join(d, fn), encoding="utf-8", errors="replace") as fh:
                for line in fh:
                    if not line.startswith(" *"):
                        if region and line.startswith("#"):
                            break
                        if line.startswith("/*") or line.strip() == "":
                            continue
                        break
                    m = REGION_RE.match(line)
                    if m:
                        region = m.group(1)
                        continue
                    if line.startswith(" * symbols:"):
                        in_sym = True
                        continue
                    if in_sym:
                        m = SYM_RE.match(line)
                        if m and region:
                            out.setdefault(region, set()).add(int(m.group(1), 16))
                        elif line.strip() == "*":
                            in_sym = False
    return out


def load_datamap_starts():
    out = set()
    p = os.path.join(ROOT, "layout", "data_objects.txt")
    if not os.path.isfile(p):
        return out
    with open(p, encoding="utf-8") as fh:
        for line in fh:
            if line.startswith("#"):
                continue
            t = line.split()
            if len(t) >= 3 and t[0] == "arm9" and t[2] in ("pool", "string", "data-decl", "table-guess"):
                out.add(int(t[1], 16))
    return out


# --------------------------------------------------------------------------
# classification
# --------------------------------------------------------------------------

def is_zero(b):
    return not any(b)


def string_like(b):
    if len(b) < 2 or 0 not in b:
        return False
    pr = sum(1 for c in b if 0x20 <= c < 0x7F)
    cov = sum(1 for c in b if 0x20 <= c < 0x7F or c == 0)
    return pr >= 0.35 * len(b) and cov >= 0.9 * len(b) and pr >= 2


def split_strings(addr, b):
    """Split a string-like segment after each terminator that precedes the
    next printable run; trailing NULs stay with the previous string."""
    cuts = [0]
    i = 0
    n = len(b)
    while i < n:
        while i < n and b[i] != 0:
            i += 1
        while i < n and b[i] == 0:
            i += 1
        if i < n:
            cuts.append(i)
    cuts.append(n)
    return [(addr + cuts[k], b[cuts[k]:cuts[k + 1]]) for k in range(len(cuts) - 1)]


def has_stride(b):
    n = len(b)
    if n < 16:
        return True
    for st in range(2, min(64, n // 2) + 1):
        good = 0
        for col in range(st):
            c = Counter(b[col::st])
            tot = sum(c.values())
            if tot and c.most_common(1)[0][1] >= 0.6 * tot:
                good += 1
        if good >= 0.5 * st:
            return True
    return False


def numeric_elem(addr, b):
    n = len(b)
    if addr % 4 == 0 and n % 4 == 0:
        w = struct.unpack("<%dI" % (n // 4), b)
        if sum(1 for x in w if x >= 0x10000) >= 0.3 * len(w):
            return "u32", n // 4
    if addr % 2 == 0 and n % 2 == 0:
        h = struct.unpack("<%dH" % (n // 2), b)
        if sum(1 for x in h if x >= 0x100) >= 0.3 * len(h):
            return "u16", n // 2
    return "u8", n


def resolve(v, syms):
    """(target address, addend) if v names a known symbol (thumb bit aware)."""
    if v in syms:
        return v, 0
    if v & 1 and (v - 1) in syms:
        return v - 1, 1
    return None


def classify(addr, b, syms):
    n = len(b)
    if is_zero(b):
        return {"kind": "zero"}
    if string_like(b):
        return {"kind": "string"}
    if addr % 4 == 0 and n % 4 == 0 and n >= 4:
        words = struct.unpack("<%dI" % (n // 4), b)
        nres = sum(1 for w in words if w and resolve(w, syms))
        if nres:
            others = sum(1 for w in words if w and not resolve(w, syms))
            targets = [hx(w) if w and resolve(w, syms) else 0 for w in words]
            if others == 0 and nres >= 0.5 * sum(1 for w in words if w) and nres >= 1:
                # every non-zero word is a named target (zeros are null slots)
                return {"kind": "pointer_table", "count": len(words),
                        "targets": [hx(w) if w else 0 for w in words]}
            if nres >= 0.2 * len(words):
                fields = []
                tg = []
                for w in words:
                    t = "ptr" if (w and resolve(w, syms)) else "u32"
                    if t == "ptr":
                        tg.append(hx(w))
                    if fields and fields[-1][0] == t:
                        fields[-1][1] += 1
                    else:
                        fields.append([t, 1])
                return {"kind": "struct", "fields": fields, "targets": tg}
    if n > 16 and not has_stride(b):
        return {"kind": "raw"}
    e, c = numeric_elem(addr, b)
    return {"kind": "numeric", "elem": e, "count": c}


# --------------------------------------------------------------------------

def build_region(layout, region, lo_hi, arm9_labels, datamap, old_names, matched=None,
                 arm9_data=None):
    base, img, listing = region_image(layout, region)
    code_end, data, labels, words = scan_listing(listing)
    if lo_hi:
        lo, hi = lo_hi
    else:
        cand = [a for a, s in data if a >= code_end]
        if not cand:
            return None
        lo = min(cand)
        hi = max(a + s for a, s in data)
        hi = min(hi, base + len(img))
    if lo >= hi:
        return None
    b = img[lo - base:hi - base]

    ev = {lo: {"tail"}}
    for a in labels:
        if lo < a < hi:
            ev.setdefault(a, set()).add("label")
    if region == "arm9":
        for a in datamap:
            if lo < a < hi:
                ev.setdefault(a, set()).add("datamap")
    for site, v in words:
        if lo < v < hi:
            ev.setdefault(v, set()).add("ptr" if lo <= site < hi else "pool")
    for a in (matched or {}).get(region, ()):
        if lo < a < hi:
            ev.setdefault(a, set()).add("matched")
    starts = set(ev)
    # externs: labelled addresses outside the tail
    known = dict((a, n) for a, n in labels.items())
    if region != "arm9":
        for a, n in arm9_labels.items():
            known.setdefault(a, n)
        for a, n in (arm9_data or {}).items():
            known.setdefault(a, n)
    else:
        for a in datamap:
            known.setdefault(a, "g_%08X" % a)

    segs = []
    order = sorted(starts)
    for i, s in enumerate(order):
        e = order[i + 1] if i + 1 < len(order) else hi
        segs.append((s, b[s - lo:e - lo]))

    # symbol universe for pointer resolution: in-tail starts (grow as strings
    # split, but strings are never pointer targets of interest) + externs.
    syms = set(starts) | {a for a in known if not (lo <= a < hi)}

    objs = []
    for s, sb in segs:
        c = classify(s, sb, syms)
        if c["kind"] == "string":
            for k, (a2, sb2) in enumerate(split_strings(s, sb)):
                e2 = set(ev[s]) if k == 0 else {"str"}
                objs.append((a2, sb2, {"kind": "string"} if not is_zero(sb2) else {"kind": "zero"}, e2))
        else:
            objs.append((s, sb, c, ev[s]))
    externs = {}
    out = []
    for a, sb, c, e in objs:
        o = {"addr": hx(a), "size": len(sb), "kind": c["kind"],
             "name": old_names.get(a, "g_%08X" % a)}
        for k in ("elem", "count", "fields", "targets"):
            if k in c:
                o[k] = c[k]
        o["ev"] = ",".join(x for x in EV_ORDER if x in e)
        out.append(o)
        for t in c.get("targets", []):
            if t:
                v = int(t, 16)
                r = resolve(v, syms)
                if r and not (lo <= r[0] < hi):
                    nm = known.get(r[0], "g_%08X" % r[0])
                    kind = "func" if nm.startswith("func_") else "data"
                    externs[r[0]] = {"addr": hx(r[0]), "name": ("func_%08X" % r[0]) if kind == "func" else (arm9_data or {}).get(r[0], "g_%08X" % r[0]),
                                     "kind": kind}
    return {"base": hx(base), "range": [hx(lo), hx(hi)], "objects": out,
            "externs": [externs[k] for k in sorted(externs)]}


def twl_functions():
    """[(address, size, name, file stem)] of the functions of src/game/twl (layout/function_addrs.tsv)."""
    out = []
    with open(os.path.join(ROOT, "layout", "function_addrs.tsv"), encoding="utf-8") as fh:
        next(fh)
        for line in fh:
            t = line.rstrip("\n").split("\t")
            if t[0] == "twl":
                out.append((int(t[1], 16), int(t[4]), t[2], os.path.splitext(os.path.basename(t[5]))[0]))
    return sorted(out)


def build_twl(layout, old_names):
    """The registry region `twl`: the objects of TWL_RANGES.  Each object carries "owner", the
    twl source file whose code refers to it first (its companion is named after that file)."""
    base, img, listing = region_image(layout, "twl")
    _ce, _data, _labels, words = scan_listing(listing)
    funcs = twl_functions()
    fstart = {a: (n, f) for a, _s, n, f in funcs}
    inside = lambda v: any(lo <= v < hi for lo, hi in TWL_RANGES)

    def owner_of(addr):
        sites = sorted(site for site, v in words if v == addr and not inside(site))
        for site in sites:
            for a, sz, _n, f in funcs:
                if a <= site < a + sz:
                    return f
        # a literal pool lies after its function: take the function before it
        for site in sites:
            prev = [x for x in funcs if x[0] <= site]
            if prev:
                return prev[-1][3]
        return None

    objs = []
    externs = {}
    for lo, hi in TWL_RANGES:
        b = img[lo - base:hi - base]
        starts = {lo} | {v for site, v in words if lo < v < hi and not inside(site)}
        starts |= {a for a in TWL_FORCE if lo < a < hi} | {a for a in TWL_NAMES if lo < a < hi}
        order = sorted(starts)
        syms = set(order) | set(fstart)
        for i, st in enumerate(order):
            e = order[i + 1] if i + 1 < len(order) else hi
            sb = b[st - lo:e - lo]
            if st in TWL_FORCE:
                c = {k: v for k, v in TWL_FORCE[st].items() if k != "name"}
            elif len(sb) > 0x1000:
                c = {"kind": "raw"}          # an embedded binary image: no classifier
            else:
                c = classify(st, sb, syms)
            parts = [(st, sb, c)]
            if c["kind"] == "string":
                parts = [(a2, sb2, {"kind": "string"} if not is_zero(sb2) else {"kind": "zero"})
                         for a2, sb2 in split_strings(st, sb)]
            for a2, sb2, c2 in parts:
                nm = TWL_FORCE.get(a2, {}).get("name") or TWL_NAMES.get(a2) or old_names.get(a2) or "g_%08X" % a2
                o = {"addr": hx(a2), "size": len(sb2), "kind": c2["kind"], "name": nm}
                for k in ("elem", "count", "fields", "targets"):
                    if k in c2:
                        o[k] = c2[k]
                ow = owner_of(a2)
                if ow:
                    o["owner"] = ow
                objs.append(o)
                for t in c2.get("targets", []):
                    if t:
                        r = resolve(int(t, 16), syms)
                        if r and r[0] in fstart:
                            externs[r[0]] = {"addr": hx(r[0]), "name": fstart[r[0]][0], "kind": "func"}
    return {"base": hx(base), "range": [hx(TWL_RANGES[0][0]), hx(TWL_RANGES[-1][1])],
            "ranges": [[hx(a), hx(b)] for a, b in TWL_RANGES],
            "objects": objs, "externs": [externs[k] for k in sorted(externs)]}


EV_ORDER = ("matched", "pool", "label", "datamap", "ptr", "str", "tail")


def dump(reg, path):
    lines = ["{"]
    lines.append('"tool": "datareg.py", "version": 1,')
    lines.append('"note": "addresses, sizes, types, counts and names only; contains no game data",')
    lines.append('"regions": {')
    rk = list(reg["regions"])
    for ri, r in enumerate(rk):
        R = reg["regions"][r]
        lines.append('%s: {"base": %s, "range": %s,' % (json.dumps(r), json.dumps(R["base"]), json.dumps(R["range"])))
        if "ranges" in R:
            lines.append('"ranges": %s,' % json.dumps(R["ranges"]))
        lines.append('"objects": [')
        for i, o in enumerate(R["objects"]):
            lines.append(json.dumps(o, separators=(", ", ": ")) + ("," if i + 1 < len(R["objects"]) else ""))
        lines.append('],')
        lines.append('"externs": [')
        for i, o in enumerate(R["externs"]):
            lines.append(json.dumps(o, separators=(", ", ": ")) + ("," if i + 1 < len(R["externs"]) else ""))
        lines.append(']}' + ("," if ri + 1 < len(rk) else ""))
    lines.append("}}")
    with open(path, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("\n".join(lines) + "\n")


HDR_DATA = re.compile(r"classified\s+0x[0-9A-F]+ bytes code \([0-9.]+%\), 0x([0-9A-F]+) bytes data")


def listing_data_bytes(layout, region):
    """Data bytes the listing header reports for the region (ovstats' figure)."""
    _b, _i, path = region_image(layout, region)
    with open(path, encoding="utf-8", errors="replace") as fh:
        for _ in range(30):
            m = HDR_DATA.search(fh.readline())
            if m:
                return int(m.group(1), 16)
    return 0


def report(layout, reg):
    rows = []
    for r in reg:
        if r in ("arm9", "twl_data"):
            continue
        R = reg[r]
        cov = sum(o["size"] for o in R["objects"])
        rows.append((r, len(R["objects"]), cov, listing_data_bytes(layout, r)))
    print("%-6s %8s %10s %12s %12s" % ("region", "objects", "covered B", "listing data", "undescribed"))
    to = tc = td = 0
    for r, n, c, d in rows:
        print("%-6s %8d %10d %12d %12d" % (r, n, c, d, max(d - c, 0)))
        to += n
        tc += c
        td += d
    all_ov = [o["id"] for o in layout["overlays"]]
    missing = ["ov%03d" % i for i in all_ov if "ov%03d" % i not in reg]
    print("overlays: %d regions with a tail, %d objects, %d B covered of %d B listing data "
          "(%d B undescribed; %d overlays without a tail: %s)"
          % (len(rows), to, tc, td, td - tc, len(missing), " ".join(missing)))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--region", action="append")
    ap.add_argument("--out", default=REG_PATH)
    ap.add_argument("--report", action="store_true")
    a = ap.parse_args()
    layout = load_layout()
    old = {}
    if os.path.isfile(a.out):
        with open(a.out, encoding="utf-8") as fh:
            old = json.load(fh).get("regions", {})
    if a.report:
        report(layout, old)
        return
    regions = a.region or ["arm9"] + ["ov%03d" % o["id"] for o in layout["overlays"]] + ["twl"]
    reg = dict(old)
    reg.pop("twl", None)       # the key of an earlier run (see REG_KEY)
    _c, _d, arm9_labels, _w = scan_listing(os.path.join(ASM, "arm9", "main.s"))
    arm9_labels = {k: v for k, v in arm9_labels.items() if v.startswith("func_")}
    datamap = load_datamap_starts()
    matched = load_matched_addrs()
    for r in regions:
        key = REG_KEY.get(r, r)
        names = {int(o["addr"], 16): o["name"] for o in old.get(key, {}).get("objects", [])
                 if o["name"] != "g_%s" % o["addr"][2:]}
        arm9_data = {int(o["addr"], 16): o["name"] for o in reg.get("arm9", {}).get("objects", [])}
        if r == "twl":
            res = build_twl(layout, names)
        else:
            res = build_region(layout, r, ARM9_TAIL if r == "arm9" else None,
                               arm9_labels, datamap, names, matched, arm9_data)
        if res is None:
            reg.pop(key, None)
        else:
            reg[key] = res
    out = {"regions": {k: reg[k] for k in sorted(reg, key=lambda x: (x != "arm9", x))}}
    dump(out, a.out)
    for r in regions:
        r = REG_KEY.get(r, r)
        if r not in reg:
            print(r, "no data tail")
            continue
        c = Counter(o["kind"] for o in reg[r]["objects"])
        by = Counter()
        for o in reg[r]["objects"]:
            by[o["kind"]] += o["size"]
        print(r, reg[r]["range"], len(reg[r]["objects"]), "objects;",
              ", ".join("%s %d (%d B)" % (k, c[k], by[k]) for k in sorted(c)),
              "; externs", len(reg[r]["externs"]))


if __name__ == "__main__":
    main()
