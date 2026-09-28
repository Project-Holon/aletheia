#!/usr/bin/env python3
"""Does the twl 'data' hide unreached code?

disasm.py emits anything not reached from a seed as data words, so a function
whose only reference is an indirect one (a callback/vtable entry) shows up as
data and leaves the twl game denominator.  In a linked binary that is the only
way code goes missing: the compiler does not emit dead code.

So: collect every pointer-sized word in the image, find the ones that target
the twl region, and check whether they land on an address the listing already
treats as code.  A pointer landing on 'data' is a candidate hidden entry.

    python tools/twl_probe.py
"""
import json
import os
import re
import sys
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
INSN = re.compile(r"/\*\s*([0-9A-Fa-f]{8})\s+((?:[0-9A-Fa-f]{2} )+)\*/")


def read(path):
    return open(path, "rb").read()


def main():
    layout = json.load(open(os.path.join(ROOT, "layout", "layout.json"), encoding="utf-8"))
    twl = layout["twl"]
    a9 = layout["arm9"]

    twl_bytes = read(os.path.join(ROOT, "extract", twl["decompressed_file"]))
    twl_data = twl_bytes[twl["src_offset"]:twl["src_offset"] + twl["code_size"]]
    lo, hi = twl["ram_start"], twl["ram_start"] + twl["code_size"]
    print("twl region 0x%08X..0x%08X (%d bytes)" % (lo, hi, len(twl_data)))

    # addresses the listing already calls code
    listing = os.path.join(ROOT, "asm", "twl", "twl.s")
    code = set()
    with open(listing, encoding="utf-8", errors="replace") as fh:
        for line in fh:
            m = INSN.search(line)
            if m:
                code.add(int(m.group(1), 16))
    print("listing code words: %d" % len(code))

    # sdk symbols in the region (tools/sdkclass.py union)
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import sdkclass
    sdk = sdkclass.union().get("twl", {})
    print("twl sdk symbols: %d" % len(sdk))

    # every 4-byte word of every region, looking for targets into [lo, hi)
    regions = [("arm9-static", None)]
    srcs = []
    img = read(os.path.join(ROOT, "extract", a9["decompressed_file"]))
    st = a9["static"]
    srcs.append(("arm9-static", st["ram_start"], img[st["src_offset"]:st["src_offset"] + st["size"]]))
    srcs.append(("twl", lo, twl_data))
    for ov in layout["overlays"]:
        p = os.path.join(ROOT, "extract", ov["decompressed_file"])
        if os.path.exists(p):
            srcs.append(("ov%03d" % ov["id"], ov["ram_start"], read(p)))

    hits = Counter()
    where = defaultdict(Counter)
    sites = defaultdict(list)
    for name, base, data in srcs:
        for off in range(0, len(data) - 3, 4):
            w = int.from_bytes(data[off:off + 4], "little")
            if lo <= w < hi:
                hits[w] += 1
                where[w][name] += 1
                sites[w].append((name, base + off))

    code_t = [w for w in hits if w in code]
    sdk_t = [w for w in hits if w not in code and w in sdk]
    unknown = [w for w in hits if w not in code and w not in sdk]
    print()
    print("distinct pointers into the twl region: %d" % len(hits))
    print("  landing on listing code : %d" % len(code_t))
    print("  landing on an sdk symbol: %d" % len(sdk_t))
    print("  landing on neither       : %d" % len(unknown))
    print()
    print("candidate hidden entries (target not code, not sdk), by target:")
    for w in sorted(unknown):
        print("  0x%08X  x%-3d  referenced from %s"
              % (w, hits[w], ",".join("%s(%d)" % kv for kv in where[w].most_common(3))))

    # how big is the 'data' between known code, and does any of it look like code?
    lo_align = (lo + 3) & ~3
    dat = [a for a in range(lo_align, hi, 4) if a not in code]
    print()
    print("unaligned/‘data’ words in the region: %d" % len(dat))

    # seed lines: mask the thumb bit, name the pointer word as the witness
    print()
    print("--- candidate seeds (function_starts.txt form) ---")
    seen = set()
    for w in sorted(unknown):
        t = w & ~1
        if t in seen or not (lo <= t < hi):
            continue
        seen.add(t)
        isa = "thumb" if (w & 1) else "arm"
        reg, site = sites[w][0]
        print("twl  0x%08X  %s   # pointer word 0x%08X (%s), target 0x%08X"
              % (t, isa, site, reg, w))


if __name__ == "__main__":
    main()
