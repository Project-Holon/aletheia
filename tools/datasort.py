#!/usr/bin/env python3
"""datasort.py: sort the bytes an overlay listing emits as data directives.

disasm.py writes every byte it did not trace as code as a .word/.short/.byte
line, and the listing header counts all of them as "data".  Most of those bytes
are not free-standing data.  This tool puts each one in exactly one class:

  matched_fn     inside the extent of a function with an EXACT/EXACT* shard
                 entry.  match.py compares a function from its label to the next
                 function label (target_extent), so these bytes (literal pools,
                 jump tables, code disasm.py did not trace) are already verified.
  matched_pad    alignment fill inside a matched extent: the Thumb nop pair
                 (C0 46) disasm.py writes before a pool, and zero words at the
                 end of an extent that ends on a 4-byte boundary.
  veneer         inside a linker veneer or decryptor entry (ovstats rules, or a
                 veneer_ label disasm.py wrote as data words).
  open_fn        inside the extent of a function with no matched entry.
  encrypted      before the first label of an overlay that has a decrypted
                 view (asm/ov230d): ciphertext of code listed there.
  pre_label      before the first function label of the listing, with no
                 matched entry (untraced leaf functions at an overlay start).
                 An overlay with no function label at all is all tail.
  tail_obj       after the last function's code, inside a data_objects.json
                 object (a described data object, values made by datagen.py).
  tail_free      after the last function's code, in no registry object.

A matched entry at an address with no listing label (a function head
disasm.py wrote as data, often right after a Thumb veneer) starts an extent
of its own, as match.py's next_listing_label() compares it.

The last function's extent stops at the data tail start datareg.py uses (the
end of the last traced instruction); its pool words are counted in the tail.

The tool reads listings, shards and the registry only and writes nothing
outside its optional --csv file.

usage
  python tools/datasort.py [--region ovNNN ...] [--csv FILE] [--top N]
"""
from __future__ import annotations

import argparse
import bisect
import collections
import csv
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import datareg  # noqa: E402
import match  # noqa: E402
import ovstats  # noqa: E402

ROOT = os.path.dirname(HERE)
CLASSES = ("matched_fn", "matched_pad", "veneer", "open_fn", "encrypted", "pre_label", "tail_obj", "tail_free")


ORG_RE = re.compile(r"^\s*\.org\s+(0x[0-9A-Fa-f]+|\d+)")
BARE_BYTES_RE = re.compile(r"^\s*\.byte\s+((?:0x[0-9A-Fa-f]+|\d+)(?:\s*,\s*(?:0x[0-9A-Fa-f]+|\d+))*)\s*$")
VENEER_LABEL_RE = re.compile(r"^veneer_([0-9A-F]{8}):", re.M)
NOP_FILL = (0xC0, 0x46)  # Thumb mov r8, r8: alignment fill before a pool


def data_lines(path):
    """[(addr, size, value or None, is_fill)] of every data directive, plus the
    end of the last traced instruction.  An uncommented `.byte` list (the Thumb
    alignment fill disasm.py writes after .org) takes its address from the .org."""
    out = []
    code_end = 0
    base = None
    cur = None
    with open(path, encoding="utf-8", errors="replace") as fh:
        for line in fh:
            if base is None:
                m = ovstats.HDR_RANGE.search(line)
                if m:
                    base = int(m.group(1), 16)
            m = datareg.DATA_RE.match(line)
            if m:
                try:
                    v = int(m.group(2), 0)
                except ValueError:
                    v = None
                a, n = int(m.group(3), 16), datareg.SIZES[m.group(1)]
                out.append((a, n, v, False))
                cur = a + n
                continue
            m = datareg.CODE_RE.search(line)
            if m:
                a = int(m.group(1), 16) + len(m.group(2).split())
                code_end = max(code_end, a)
                cur = a
                continue
            m = ORG_RE.match(line)
            if m and base is not None:
                cur = base + int(m.group(1), 0)
                continue
            m = BARE_BYTES_RE.match(line)
            if m and cur is not None:
                vals = tuple(int(x, 0) for x in m.group(1).split(","))
                out.append((cur, len(vals), None, vals == NOP_FILL or not any(vals)))
                cur += len(vals)
    return out, code_end


def sort_region(region, reg):
    path = os.path.join(ROOT, "asm", "overlays", "ov%s.s" % region[2:])
    lines, code_end = data_lines(path)
    starts = sorted(match.scan_listing(region))
    with open(path, encoding="utf-8", errors="replace") as fh:
        m = ovstats.HDR_RANGE.search(fh.read(4000))
    region_lo, region_hi = int(m.group(1), 16), int(m.group(2), 16)
    _head, labels, _insns = ovstats.scan_listing(path)
    by_label = {}
    for a, name in labels:
        by_label.setdefault(name, a)
    matched, unc = ovstats.matched_addresses(region, [a for a, _ in labels], by_label)
    # A matched entry at an address with no listing label (disasm.py wrote the
    # function's head as data words): match.py compares it up to the next label.
    for key, _st in unc:
        if isinstance(key, int) and region_lo <= key < region_hi:
            matched.add(key)
            starts = sorted(set(starts) | {key})
    with open(path, encoding="utf-8", errors="replace") as fh:
        named = {int(h, 16) for h in VENEER_LABEL_RE.findall(fh.read())}
    veneers = ovstats.veneer_labels(path) | named
    objs = sorted((int(o["addr"], 16), o["size"]) for o in reg.get(region, {}).get("objects", []))
    obj_starts = [a for a, _ in objs]

    def owner(a):
        """Start of the function extent holding a, or None."""
        i = bisect.bisect_right(starts, a) - 1
        return starts[i] if i >= 0 else None

    def in_obj(a):
        i = bisect.bisect_right(obj_starts, a) - 1
        return i >= 0 and a < objs[i][0] + objs[i][1]

    encrypted = os.path.isdir(os.path.join(ROOT, "asm", region + "d"))
    last = starts[-1] if starts else None
    tail_start = max(code_end, last or 0)
    cls_of = []
    for a, n, v, fill in lines:
        f = owner(a)
        if f is None and not starts:
            c = "tail_obj" if in_obj(a) else "tail_free"
        elif f is None and encrypted:
            c = "encrypted"
        elif f is None:
            c = "pre_label"
        elif a >= tail_start and f == last and fill and f in matched:
            c = "matched_pad"
        elif a >= tail_start and f == last:
            c = "tail_obj" if in_obj(a) else "tail_free"
        elif f in veneers:
            c = "veneer"
        elif f in matched:
            c = "matched_pad" if fill else "matched_fn"
        else:
            c = "open_fn"
        cls_of.append(c)
    # padding: trailing zero data lines of a matched extent, ending 4-aligned
    i = len(lines) - 1
    while i >= 0:
        if cls_of[i] != "matched_fn":
            i -= 1
            continue
        f = owner(lines[i][0])
        j = i
        while j >= 0 and cls_of[j] == "matched_fn" and owner(lines[j][0]) == f:
            j -= 1
        k = i
        nxt = starts[bisect.bisect_right(starts, f)] if bisect.bisect_right(starts, f) < len(starts) else None
        if lines[i][0] + lines[i][1] == nxt and nxt % 4 == 0:
            while k > j and lines[k][2] == 0 and not lines[k][3]:
                cls_of[k] = "matched_pad"
                k -= 1
        i = j
    tot = collections.Counter()
    rows = []
    for (a, n, v, _fill), c in zip(lines, cls_of):
        tot[c] += n
        rows.append((region, "0x%08X" % a, n, c, "0x%08X" % owner(a) if owner(a) is not None else ""))
    return tot, rows


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--region", action="append")
    ap.add_argument("--csv")
    ap.add_argument("--top", type=int, default=15)
    a = ap.parse_args()
    with open(datareg.REG_PATH, encoding="utf-8") as fh:
        reg = json.load(fh)["regions"]
    regions = a.region or sorted(os.path.basename(p)[:-2] for p in
                                 os.listdir(os.path.join(ROOT, "asm", "overlays"))
                                 if re.fullmatch(r"ov\d{3}\.s", p))
    grand = collections.Counter()
    per = {}
    allrows = []
    open_fns = collections.Counter()
    for r in regions:
        tot, rows = sort_region(r, reg)
        per[r] = tot
        grand.update(tot)
        allrows += rows
        for row in rows:
            if row[3] == "open_fn":
                open_fns[(r, row[4])] += row[2]
    if a.csv:
        with open(a.csv, "w", newline="") as fh:
            w = csv.writer(fh)
            w.writerow(["region", "addr", "size", "class", "extent"])
            w.writerows(allrows)
    total = sum(grand.values())
    print("%d overlays, %d B in data directives" % (len(regions), total))
    for c in CLASSES:
        print("  %-12s %9d B  %5.1f%%" % (c, grand[c], 100.0 * grand[c] / total if total else 0))
    for c in ("open_fn", "pre_label", "tail_free"):
        worst = sorted(((t[c], r) for r, t in per.items() if t[c]), reverse=True)[:a.top]
        if worst:
            print("%s by overlay: %s" % (c, ", ".join("%s %d" % (r, n) for n, r in worst)))
    if open_fns:
        print("open extents with data lines: %d; largest: %s" % (
            len(open_fns), ", ".join("%s %s %d" % (r, f, n) for (r, f), n in open_fns.most_common(a.top))))


if __name__ == "__main__":
    main()
