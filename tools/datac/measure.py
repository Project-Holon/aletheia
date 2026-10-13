#!/usr/bin/env python3
"""DG1 step 1: per region data bytes, data objects, owner files.

Owner of a data object = the src/game files that reference an address inside
it, from (a) the file header symbols: block (data lines) and (b) literal pool
words (asm listing .word lines) that lie in the file's code range and point
inside the object.  Reads layout/data_objects.json (overlay and arm9 tail
objects), layout/data_objects.txt (arm9 object starts) and asm/ listings.
"""
import bisect
import json
import os
import re
import sys
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, ROOT + "/tools")
import datareg  # noqa
import gamebuild  # noqa
import gamelink  # noqa

lay = datareg.load_layout()
reg = json.load(open(ROOT + "/layout/data_objects.json"))["regions"]

# ---- file ranges per region
files = []          # (start, region, relpath, symaddrs)
for d in sorted(os.listdir(ROOT + "/src/game")):
    p = os.path.join(ROOT, "src/game", d)
    if not os.path.isdir(p):
        continue
    rg = {"arm9": "arm9", "arm9_autoload0_ITCM": "itcm"}.get(d, d)
    for f in sorted(os.listdir(p)):
        fp = os.path.join(p, f)
        if not f.endswith(".c") or f.startswith("_") or not os.path.isfile(fp):
            continue
        raw = open(fp, encoding="latin1").read()
        h, _st = gamebuild._settings(raw)
        try:
            a = int(h.get("address", "0"), 16)
        except ValueError:
            continue
        hs = gamelink.header_symbols(raw)
        data_addrs = [v for (v, k) in hs.values() if k == "data"]
        files.append((a, rg, d + "/" + f, data_addrs))
files.sort()
fstarts = [f[0] for f in files]

# region of each file start is ambiguous for overlays sharing addresses: key by region
by_region = defaultdict(list)
for a, rg, rel, da in files:
    by_region[rg].append((a, rel))
for rg in by_region:
    by_region[rg].sort()


def tail_start(region):
    if region in reg:
        return int(reg[region]["range"][0], 16)
    return None


def file_of(region, site):
    lst = by_region.get(region)
    if not lst:
        return None
    i = bisect.bisect_right([x[0] for x in lst], site) - 1
    if i < 0:
        return None
    ts = tail_start(region)
    if ts is not None and site >= ts:
        return None
    return lst[i][1]


# ---- pool words from every listing
listings = {"arm9": ROOT + "/asm/arm9/main.s", "itcm": ROOT + "/asm/arm9/itcm.s"}
for o in lay["overlays"]:
    listings["ov%03d" % o["id"]] = ROOT + "/asm/overlays/ov%03d.s" % o["id"]
words = []     # (value, region, site)
codeend = {}
for rg, path in listings.items():
    if not os.path.exists(path):
        continue
    ce, _d, _l, w = datareg.scan_listing(path)
    codeend[rg] = ce
    for site, v in w:
        words.append((v, rg, site))
words.sort()
wvals = [w[0] for w in words]

# objects to classify: registry objects (with sizes)
objs = []   # (region, addr, size, kind, name)
for rg, R in reg.items():
    for o in R["objects"]:
        objs.append((rg, int(o["addr"], 16), o["size"], o["kind"], o["name"]))

# overlay address spaces overlap: a data address in an overlay is referenced by
# files of that overlay, arm9, itcm, or overlays loaded together.  Accept a
# reference only from: same region, arm9, itcm; or (for arm9 objects) anywhere.
hdr_refs = defaultdict(set)    # (region_of_file, addr) -> files
for a, rg, rel, da in files:
    for x in da:
        hdr_refs[x].add((rg, rel))
hdr_sorted = sorted(hdr_refs)


def owners(rg, a, size):
    own = set()
    lo = bisect.bisect_left(wvals, a)
    hi = bisect.bisect_left(wvals, a + max(size, 1))
    for v, wr, site in words[lo:hi]:
        if rg != "arm9" and wr not in (rg, "arm9", "itcm"):
            continue
        f = file_of(wr, site)
        if f:
            own.add(f)
    lo = bisect.bisect_left(hdr_sorted, a)
    hi = bisect.bisect_left(hdr_sorted, a + max(size, 1))
    for x in hdr_sorted[lo:hi]:
        for fr, rel in hdr_refs[x]:
            if rg != "arm9" and fr not in (rg, "arm9", "itcm"):
                continue
            own.add(rel)
    return own


rows = {}
own_of = {}
for rg, a, size, k, n in objs:
    o = owners(rg, a, size)
    own_of[(rg, a)] = o
    r = rows.setdefault(rg, Counter())
    r["objs"] += 1
    r["bytes"] += size
    if len(o) == 1:
        r["one"] += 1
        r["one_b"] += size
    elif len(o) == 0:
        r["none"] += 1
        r["none_b"] += size
    else:
        r["many"] += 1
        r["many_b"] += size

# arm9 data_objects.txt rows
txt = Counter()
for line in open(ROOT + "/layout/data_objects.txt", encoding="utf-8"):
    if line.startswith("#") or not line.strip():
        continue
    p = line.split()
    if len(p) >= 3 and p[1].startswith("0x"):
        txt[p[0]] += 1

ovinfo = {"ov%03d" % o["id"]: o for o in lay["overlays"]}
out = []
tot = Counter()
for rg in sorted(set(list(rows) + list(ovinfo)), key=lambda x: (x != "arm9", x)):
    r = rows.get(rg, Counter())
    if rg == "arm9":
        st = lay["arm9"]["static"]
        size = st["size"]
        bss = 0x021542C0 - 0x020A9E80
    else:
        o = ovinfo[rg]
        size = o["code_size"]
        bss = o["bss_size"]
    ts = tail_start(rg)
    tailb = (int(reg[rg]["range"][1], 16) - ts) if ts else 0
    nfiles = len(by_region.get(rg, []))
    out.append((rg, size, tailb, bss, txt.get(rg, 0), r["objs"], r["one"], r["many"], r["none"],
                r["one_b"], r["many_b"], r["none_b"], nfiles))
    for k, v in zip(("size", "tail", "bss", "txt", "objs", "one", "many", "none", "one_b", "many_b", "none_b", "files"),
                    out[-1][1:]):
        tot[k] += v
json.dump({"rows": out, "total": tot}, open(os.path.dirname(os.path.abspath(__file__)) + "/measure.json", "w"))
print("%-6s %8s %7s %7s %5s %5s %5s %5s %5s %7s %7s %7s %4s" % (
    "region", "image", "tail", "bss", "txt", "objs", "one", "many", "none", "one_B", "many_B", "none_B", "tus"))
for r in out:
    print("%-6s %8d %7d %7d %5d %5d %5d %5d %5d %7d %7d %7d %4d" % r)
print("total", dict(tot))
# dump owner lists for later use
json.dump({"%s:%08X" % k: sorted(v) for k, v in own_of.items()},
          open(os.path.dirname(os.path.abspath(__file__)) + "/owners.json", "w"), indent=0)
