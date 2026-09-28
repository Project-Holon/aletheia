#!/usr/bin/env python3
"""Find unreached code in every region, the way tools/twl_probe.py found it in twl.

disasm.py emits any byte it could not reach from a seed as data.  A linked
binary has no dead code, so the only code that goes missing is code whose sole
reference is indirect -- a function-pointer table.  So: collect every
pointer-sized word in the whole image, look up the ones that land inside each
region, and report the targets that land on neither a listing label nor an SDK
symbol.  Those are candidate hidden entries.

    python tools/deadcode_probe.py                 table for every region
    python tools/deadcode_probe.py --seeds ov021   function_starts.txt lines
"""
import argparse
import glob
import json
import os
import re
import sys
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
INSN = re.compile(r"/\*\s*([0-9A-Fa-f]{8})\s+((?:[0-9A-Fa-f]{2} )+)\*/")
RANGE = re.compile(r"address range\s+0x([0-9A-Fa-f]+)\.\.0x([0-9A-Fa-f]+)")
NAME = re.compile(r"^ \* (\S+)\s*$", re.M)


def union_key(region):
    """The layout/symbols_sdk.json region a listing region belongs to."""
    if region == "arm9_main":
        return "arm9"
    if region == "arm9_itcm":
        return "arm9_autoload0_ITCM"
    m = re.match(r"overlay_(\d+)$", region)
    if m:
        return "ov%03d" % int(m.group(1))
    return region


def listing_region(path):
    head = "".join(open(path, encoding="utf-8", errors="replace").readlines()[:8])
    m = RANGE.search(head)
    n = NAME.search(head)
    if not (m and n):
        return None
    return n.group(1), int(m.group(1), 16), int(m.group(2), 16)


def code_addrs(path):
    out = set()
    with open(path, encoding="utf-8", errors="replace") as fh:
        for line in fh:
            m = INSN.search(line)
            if m:
                out.add(int(m.group(1), 16))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seeds", metavar="REGION")
    ap.add_argument("--min", type=int, default=1)
    ap.add_argument("--tables", action="store_true",
                    help="only report runs of >=4 consecutive pointers into one region")
    args = ap.parse_args()

    listings = sorted(glob.glob(os.path.join(ROOT, "asm", "arm9", "*.s"))
                      + glob.glob(os.path.join(ROOT, "asm", "twl", "*.s"))
                      + glob.glob(os.path.join(ROOT, "asm", "overlays", "ov*.s")))
    regions = {}
    for p in listings:
        r = listing_region(p)
        if r:
            name, lo, hi = r
            regions[name] = {"lo": lo, "hi": hi, "code": code_addrs(p)}

    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import sdkclass
    U = sdkclass.union()

    # aligned address -> [region names covering it]
    members = defaultdict(list)
    for name, r in regions.items():
        for a in range(r["lo"] & ~3, r["hi"], 4):
            members[a].append(name)
    print("# %d regions, %d covered addresses" % (len(regions), len(members)))

    layout = json.load(open(os.path.join(ROOT, "layout", "layout.json"), encoding="utf-8"))
    srcs = []
    a9 = layout["arm9"]
    img = open(os.path.join(ROOT, "extract", a9["decompressed_file"]), "rb").read()
    st = a9["static"]
    srcs.append(("arm9", st["ram_start"], img[st["src_offset"]:st["src_offset"] + st["size"]]))
    for al in a9["autoloads"]:
        srcs.append(("autoload%d_%s" % (al["index"], al["kind"]),
                     al["ram_start"], img[al["src_offset"]:al["src_offset"] + al["code_size"]]))
    if "twl" in layout:
        t = layout["twl"]
        ti = open(os.path.join(ROOT, "extract", t["decompressed_file"]), "rb").read()
        srcs.append(("twl", t["ram_start"],
                     ti[t["src_offset"]:t["src_offset"] + t["code_size"]]))
    for ov in layout["overlays"]:
        p = os.path.join(ROOT, "extract", ov["decompressed_file"])
        if os.path.exists(p):
            srcs.append(("ov%03d" % ov["id"], ov["ram_start"], open(p, "rb").read()))

    # candidate pointer words, with the site that holds them
    cand = defaultdict(list)
    site = {}
    if args.tables:
        # only runs of >=4 consecutive words that all land in one region
        for sname, base, data in srcs:
            n = len(data) // 4
            i = 0
            while i < n:
                w = int.from_bytes(data[i * 4:i * 4 + 4], "little")
                regs = [nm for nm in members.get(w & ~1, []) if members.get(w & ~1)]
                if not regs:
                    i += 1
                    continue
                j = i
                while j < n:
                    wj = int.from_bytes(data[j * 4:j * 4 + 4], "little")
                    if not (wj & ~1) in members:
                        break
                    j += 1
                if j - i >= 4:
                    tgts = [int.from_bytes(data[k * 4:k * 4 + 4], "little")
                            for k in range(i, j)]
                    names = sorted({nm for nm in members.get(tgts[0] & ~1, [])})

                    def known(t):
                        for nm in members.get(t & ~1, []):
                            if t & ~1 in regions[nm]["code"]:
                                return True
                        return False
                    miss = [t for t in tgts if not known(t)]
                    if miss:
                        print("TABLE %-12s 0x%08X x%-3d -> %-28s unclassified %d/%d  first 0x%08X"
                              % (sname, base + i * 4, j - i, ",".join(names)[:28],
                                 len(miss), len(tgts), miss[0]))
                i = max(j, i + 1)
        return
    for sname, base, data in srcs:
        for off in range(0, len(data) - 3, 4):
            w = int.from_bytes(data[off:off + 4], "little")
            if (w & ~1) in members or w in members:
                cand[w].append((sname, base + off))
                site[(sname, base + off)] = w

    def listing_of(sname):
        if sname in ("arm9", "twl"):
            return {"arm9": "arm9_main", "twl": "twl"}[sname]
        m = re.match(r"ov(\d+)$", sname)
        if m:
            return "overlay_%s" % m.group(1)
        return None

    def site_is_code(sname, saddr):
        lname = listing_of(sname)
        return bool(lname and lname in regions and saddr in regions[lname]["code"])

    def in_table(sname, saddr, lo, hi):
        """>=2 of the four neighbouring words also point into this region."""
        n = 0
        for k in (-2, -1, 1, 2):
            w2 = site.get((sname, saddr + 4 * k))
            if w2 is not None and lo <= (w2 & ~1) < hi:
                n += 1
        return n >= 2

    rows = []
    for name, r in regions.items():
        code, lo, hi = r["code"], r["lo"], r["hi"]
        sdk = set(U.get(union_key(name), {}))
        ptr = oncode = onsdk = 0
        unk = []
        for w, sites in cand.items():
            t = w & ~1
            if not (lo <= t < hi):
                continue
            ptr += 1
            if t in code:
                oncode += 1
            elif t in sdk:
                onsdk += 1
            elif any(site_is_code(sn, sa) for sn, sa in sites) or \
                    any(in_table(sn, sa, lo, hi) for sn, sa in sites):
                unk.append((w, sites))
        rows.append((len(unk), name, len(code), ptr, oncode, onsdk, unk))

    print("%-24s %7s %7s %7s %7s %9s" % ("region", "code", "ptr", "onCode", "onSDK", "unknown"))
    for n, name, ncode, ptr, oncode, onsdk, unk in sorted(rows, reverse=True):
        if n < args.min:
            continue
        print("%-24s %7d %7d %7d %7d %9d" % (name, ncode, ptr, oncode, onsdk, n))

    if args.seeds:
        for n, name, ncode, ptr, oncode, onsdk, unk in rows:
            if name != args.seeds:
                continue
            seen = set()
            for w, sites in sorted(unk):
                t = w & ~1
                if t in seen:
                    continue
                seen.add(t)
                isa = "thumb" if w & 1 else "arm"
                reg, site = sites[0]
                print("%s  0x%08X  %s   # pointer word 0x%08X (%s), target 0x%08X"
                      % (name, t, isa, site, reg, w))


if __name__ == "__main__":
    main()
