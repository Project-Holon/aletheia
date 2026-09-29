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

usage: python tools/datareg.py [--region arm9 --region ov203 ...]
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

def build_region(layout, region, lo_hi, arm9_labels, datamap, old_names):
    base, img, listing = region_image(layout, region)
    code_end, data, labels, words = scan_listing(listing)
    if lo_hi:
        lo, hi = lo_hi
    else:
        lo = min(a for a, s in data if a >= code_end)
        hi = max(a + s for a, s in data)
        hi = min(hi, base + len(img))
    b = img[lo - base:hi - base]

    starts = {lo}
    for a in labels:
        if lo < a < hi:
            starts.add(a)
    if region == "arm9":
        starts.update(a for a in datamap if lo < a < hi)
    for site, v in words:
        if lo < v < hi:
            starts.add(v)
    # externs: labelled addresses outside the tail
    known = dict((a, n) for a, n in labels.items())
    if region != "arm9":
        for a, n in arm9_labels.items():
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
            for a2, sb2 in split_strings(s, sb):
                objs.append((a2, sb2, {"kind": "string"} if not is_zero(sb2) else {"kind": "zero"}))
        else:
            objs.append((s, sb, c))
    externs = {}
    out = []
    for a, sb, c in objs:
        o = {"addr": hx(a), "size": len(sb), "kind": c["kind"],
             "name": old_names.get(a, "g_%08X" % a)}
        for k in ("elem", "count", "fields", "targets"):
            if k in c:
                o[k] = c[k]
        out.append(o)
        for t in c.get("targets", []):
            if t:
                v = int(t, 16)
                r = resolve(v, syms)
                if r and not (lo <= r[0] < hi):
                    nm = known.get(r[0], "g_%08X" % r[0])
                    kind = "func" if nm.startswith("func_") else "data"
                    externs[r[0]] = {"addr": hx(r[0]), "name": ("func_%08X" % r[0]) if kind == "func" else "g_%08X" % r[0],
                                     "kind": kind}
    return {"base": hx(base), "range": [hx(lo), hx(hi)], "objects": out,
            "externs": [externs[k] for k in sorted(externs)]}


def dump(reg, path):
    lines = ["{"]
    lines.append('"tool": "datareg.py", "version": 1,')
    lines.append('"note": "addresses, sizes, types, counts and names only; contains no game data",')
    lines.append('"regions": {')
    rk = list(reg["regions"])
    for ri, r in enumerate(rk):
        R = reg["regions"][r]
        lines.append('%s: {"base": %s, "range": %s,' % (json.dumps(r), json.dumps(R["base"]), json.dumps(R["range"])))
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


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--region", action="append")
    ap.add_argument("--out", default=REG_PATH)
    a = ap.parse_args()
    regions = a.region or ["arm9", "ov203"]
    layout = load_layout()
    old = {}
    if os.path.isfile(a.out):
        with open(a.out, encoding="utf-8") as fh:
            old = json.load(fh).get("regions", {})
    reg = dict(old)
    _c, _d, arm9_labels, _w = scan_listing(os.path.join(ASM, "arm9", "main.s"))
    arm9_labels = {k: v for k, v in arm9_labels.items() if v.startswith("func_")}
    datamap = load_datamap_starts()
    for r in regions:
        names = {int(o["addr"], 16): o["name"] for o in old.get(r, {}).get("objects", [])
                 if o["name"] != "g_%s" % o["addr"][2:]}
        reg[r] = build_region(layout, r, ARM9_TAIL if r == "arm9" else None,
                              arm9_labels, datamap, names)
    out = {"regions": {k: reg[k] for k in sorted(reg, key=lambda x: (x != "arm9", x))}}
    dump(out, a.out)
    for r in regions:
        c = Counter(o["kind"] for o in reg[r]["objects"])
        by = Counter()
        for o in reg[r]["objects"]:
            by[o["kind"]] += o["size"]
        print(r, reg[r]["range"], len(reg[r]["objects"]), "objects;",
              ", ".join("%s %d (%d B)" % (k, c[k], by[k]) for k in sorted(c)),
              "; externs", len(reg[r]["externs"]))


if __name__ == "__main__":
    main()
