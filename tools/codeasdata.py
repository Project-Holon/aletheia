#!/usr/bin/env python3
"""codeasdata.py: find code that the data registry files as data.

A function that only a data table names (a callback, a vtable slot) is not
reached by the trace of tools/disasm.py, so the listing shows its bytes as
.word lines and tools/datareg.py files them as data objects.  This check reads
every data object of layout/data_objects.json and every word in it (values from
the local extract, never printed in full) and lists each word that looks like a
code pointer but does not name a known function start of
layout/function_addrs.tsv:

  func-in-data    a function of layout/function_addrs.tsv that starts inside a
                  region's data tail (the registry covers its code)
  thumb-in-data   odd value whose even address lies in the region's data tail
                  (a registry object): the strongest sign of code filed as data
  thumb-in-gap    odd value into the code part of the region, in no function
  thumb-mid       odd value inside a known function, not at its start
  odd-in-data     (--all only) odd value into the data tail whose bytes do not
                  read as Thumb code: byte arrays and strings with odd starts
  arm-gap         4-aligned value into the code part, in no function, where the
                  word there decodes as an ARM push/stmdb (a plausible entry)

Targets are looked up in the word's own region and in the ARM9 static module.
Pointer-typed words (pointer_table and struct ptr fields) are always checked;
words of numeric and raw objects only for the thumb-in-data and thumb-in-gap
classes, where a random number rarely lands.

usage
    python tools/codeasdata.py               # every region
    python tools/codeasdata.py --region ov198
    python tools/codeasdata.py --all         # also the weak classes for numeric words
Exit status 1 when a func-in-data or thumb-in-data row exists.
"""
from __future__ import annotations

import argparse
import bisect
import json
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import datareg  # noqa: E402


def load_functions():
    """{region: sorted [(start, end, isa, name)]} from layout/function_addrs.tsv."""
    out = {}
    with open(os.path.join(ROOT, "layout", "function_addrs.tsv"), encoding="utf-8") as fh:
        next(fh)
        for line in fh:
            t = line.rstrip("\n").split("\t")
            a = int(t[1], 16)
            out.setdefault(t[0], []).append((a, a + int(t[4]), t[3], t[2]))
    for v in out.values():
        v.sort()
    return out


class Region:
    def __init__(self, name, base, img, funcs, R):
        self.name = name
        self.base = base
        self.img = img
        self.end = base + len(img)
        self.funcs = funcs
        self.starts = [f[0] for f in funcs]
        self.by_start = {f[0]: f for f in funcs}
        self.tail = (int(R["range"][0], 16), int(R["range"][1], 16)) if R else (self.end, self.end)
        self.objs = sorted((int(o["addr"], 16), o) for o in R["objects"]) if R else []
        self.oaddr = [a for a, _ in self.objs]

    def func_at(self, a):
        i = bisect.bisect_right(self.starts, a) - 1
        if i >= 0 and self.funcs[i][0] <= a < self.funcs[i][1]:
            return self.funcs[i]
        return None

    def obj_at(self, a):
        i = bisect.bisect_right(self.oaddr, a) - 1
        if i >= 0:
            s, o = self.objs[i]
            if s <= a < s + o["size"]:
                return o
        return None

    def word(self, a):
        o = a - self.base
        if 0 <= o and o + 4 <= len(self.img):
            return struct.unpack_from("<I", self.img, o)[0]
        return None


def thumb_shape(rg, t):
    """True when the halfwords from t read as a short Thumb body: a push or a
    pc-relative load first, and a bx/blx register or a pop {..., pc} within 16
    halfwords."""
    o = t - rg.base
    hw = [struct.unpack_from("<H", rg.img, o + 2 * i)[0]
          for i in range(16) if o + 2 * i + 2 <= len(rg.img)]
    if not hw:
        return False
    first = hw[0]
    if not ((first & 0xFE00) == 0xB400 or (first & 0xF800) == 0x4800
            or (first & 0xFFC0) == 0x1C00):
        return False
    return any((h & 0xFF00) == 0x4700 or (h & 0xFF00) == 0xBD00 for h in hw)


def classify(rg, v, pointer):
    """-> (class, detail) or None for a value v looked up in region rg."""
    if not (rg.base <= v < rg.end):
        return None
    if v & 1:
        t = v - 1
        f = rg.by_start.get(t)
        if f and f[2] == "thumb":
            return None
        if rg.tail[0] <= t < rg.tail[1]:
            o = rg.obj_at(v)
            if o and o["kind"] == "string" and int(o["addr"], 16) == v:
                return None             # a pointer to an odd-aligned string
            if not thumb_shape(rg, t):
                return ("odd-in-data", "no code shape") if pointer == "all" else None
            o = rg.obj_at(t)
            return ("thumb-in-data", o["name"] if o else "tail")
        f = rg.func_at(t)
        if f is None:
            return ("thumb-in-gap", "")
        if pointer:
            return ("thumb-mid", "%s+0x%X" % (f[3], t - f[0]))
        return None
    if v & 3 or not pointer:
        return None
    if v >= rg.tail[0] or v in rg.by_start:
        return None
    if rg.func_at(v) is not None:
        return None
    w = rg.word(v)
    if w is not None and (w & 0x0FFF0000) == 0x092D0000 and (w >> 28) == 0xE:
        return ("arm-gap", "push")
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--region", action="append")
    ap.add_argument("--all", action="store_true")
    a = ap.parse_args()
    layout = datareg.load_layout()
    with open(datareg.REG_PATH, encoding="utf-8") as fh:
        reg = json.load(fh)["regions"]
    funcs = load_functions()
    cache = {}

    def region(name):
        if name not in cache:
            base, img, _l = datareg.region_image(layout, name)
            cache[name] = Region(name, base, img, funcs.get(name, []), reg.get(name))
        return cache[name]

    arm9 = region("arm9")
    names = a.region or [r for r in reg if r == "arm9" or r.startswith("ov")]
    rows = []
    for rn in names:
        if rn not in reg:
            continue
        rg = region(rn)
        for start, o in rg.objs:
            k = o["kind"]
            if k in ("string", "zero"):
                continue
            ptr_sites = set()
            if k == "pointer_table":
                ptr_sites = {start + 4 * i for i in range(o["size"] // 4)}
            elif k == "struct":
                i = 0
                for t, c in o["fields"]:
                    if t == "ptr":
                        ptr_sites |= {start + 4 * (i + j) for j in range(c)}
                    i += c
            first = (start + 3) & ~3
            for site in range(first, start + o["size"] - 3, 4):
                v = rg.word(site)
                if v is None:
                    continue
                pointer = "all" if a.all else site in ptr_sites
                for tr in ((rg, arm9) if rg is not arm9 else (arm9,)):
                    c = classify(tr, v, pointer)
                    if c:
                        rows.append((c[0], rn, site, o["name"], tr.name, v, c[1]))
                        break
    # functions of src/game that the registry files as data: a function that
    # starts inside a region's data tail (its literal pool may sit there, its
    # first instruction may not)
    for rn in names:
        if rn not in reg or rn == "arm9":
            continue
        rg = region(rn)
        for f in rg.funcs:
            if rg.tail[0] <= f[0] < rg.tail[1]:
                o = rg.obj_at(f[0])
                rows.append(("func-in-data", rn, f[0], o["name"] if o else "tail", rn, f[0], f[3]))
    order = {"func-in-data": 0, "thumb-in-data": 1, "thumb-in-gap": 2, "arm-gap": 3, "thumb-mid": 4, "odd-in-data": 5}
    rows.sort(key=lambda r: (order[r[0]], r[1], r[2]))
    for r in rows:
        print("%-13s %-5s site 0x%08X in %-12s -> %-5s 0x%08X %s" % r)
    from collections import Counter
    c = Counter(r[0] for r in rows)
    print("total:", ", ".join("%s %d" % (k, c[k]) for k in sorted(c, key=order.get)) or "0")
    sys.exit(1 if c["thumb-in-data"] or c["func-in-data"] else 0)


if __name__ == "__main__":
    main()
