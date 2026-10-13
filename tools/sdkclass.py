#!/usr/bin/env python3
"""Deterministic SDK placement.

tools/libmatch.py finds SDK functions one pattern at a time and records only
the addresses it can verify, so a member whose small or relocation-heavy
functions never verified on their own was never placed.  This does the same
scan and then *propagates*: the linker lays an archive member's code out
contiguously in one section, in symbol order, at the object's own offsets, so
one verified function pins the whole member.  every other symbol in that
section follows at base + value.

Output: layout/sdk_class.json, region -> address -> {name, size, lib, member,
object, method} where method is "verified" for a directly matched function or
"propagated" for a sibling placed by an anchor.

    python tools/sdkclass.py                 full run
    python tools/sdkclass.py --variants TWL.HYB NTR
"""
from __future__ import annotations

import argparse
import glob
import json
import os
import re
import sys
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import libmatch  # noqa: E402

OUT = os.path.join(ROOT, "layout", "sdk_class.json")
CATALOG = os.path.join(ROOT, "layout", "symbols_sdk.json")

def union(catalog=CATALOG, scan=OUT):
    """The authoritative SDK set: {region: {address: {name, size, source}}}.

    Union of libmatch.py's catalog and this tool's placement scan.  The scan
    is the determinate half (it places whole archive members, so it sees the
    DSi-only libraries libmatch never listed); the catalog is kept because a
    handful of its rows are variants the scan's profile does not cover.  A
    function is SDK if either says so, which makes the classifier monotone:
    nothing that used to be SDK stops being SDK.

    The catalog is not filtered here.  worklist.py's weak-row override is
    deliberately arm9-only (a duplicated overlay symbol name is a real
    function linked into several overlays, not a false positive), so applying
    it globally would reclassify matched SDK functions as game.
    """
    out = {}

    def add(region, addr, name, size, source):
        d = out.setdefault(region, {})
        e = d.get(addr)
        if e is None:
            d[addr] = {"name": name, "size": size, "source": source}
        else:
            if size > e["size"]:
                e["size"] = size
            if source == "catalog":
                e["name"] = name
                e["source"] = "catalog"

    if os.path.exists(catalog):
        for s in json.load(open(catalog, encoding="utf-8")).get("symbols", []):
            add(s.get("region"), int(s["address"]), s.get("name"), int(s.get("size") or 0), "catalog")
    if os.path.exists(scan):
        for region, d in json.load(open(scan, encoding="utf-8")).get("regions", {}).items():
            for a, e in d.items():
                add(region, int(a, 16), e.get("name"), int(e.get("size") or 0), "scan")
    extra = os.path.join(ROOT, "layout", "sdk_class_extra.json")   # evidence-based reclassification (not regenerated)
    if os.path.exists(extra):
        for region, d in json.load(open(extra, encoding="utf-8")).get("regions", {}).items():
            for a, e in d.items():
                add(region, int(a, 16), e.get("name"), int(e.get("size") or 0), "extra")
    return out


def addresses(region, **kw):
    return set(union(**kw).get(region, {}))



# ---------------------------------------------------------------- interiors
#
# Propagation places every sibling of an anchored member at base + value.  A
# sibling whose bytes happen to repeat inside another function (the tail of
# G3X_SetClearColor reads as SBServerSetPublicAddr, the last three blocks of
# MTX_Copy44To43_ read as MTX_Copy44To33_) then lands mid-function.  A scan
# placement is rejected when it starts strictly inside the extent of another
# function known in that region, unless the listing has a function label at
# exactly that address (or a catalog row or matched shard entry starts there:
# disasm.py traces straight through MI_CpuCopy8 into MI_CpuComp8 and
# MI_CpuCopy, which the catalog and the shards know as function starts).
# Known functions:
#   listing  a func_XXXXXXXX label in the region's disasm.py listing; its
#            extent is its traced code (label to the end of its last
#            instruction before the next label; pools and untraced .word
#            runs after it are outside)
#   catalog  a layout/symbols_sdk.json row with a size
#   matched  a layout/matched shard entry; its extent is the catalog size at
#            that address, else the listing extent that starts there

RE_FUNC_LABEL = re.compile(r"^func_([0-9A-Fa-f]{8}):")
RE_ADDR_BYTES = re.compile(
    r"/\*\s+([0-9A-F]{8})(?:\s\s((?:[0-9A-F]{2})(?:\s[0-9A-F]{2})*))?")


def listing_files(region):
    """The disasm.py listing file(s) of one region."""
    units = {"arm9": "units_arm9.json", "arm9_autoload0_ITCM": "units_itcm.json"}
    if region in units:
        doc = json.load(open(os.path.join(ROOT, "layout", units[region]), encoding="utf-8"))
        return [os.path.join(ROOT, u["file"].replace("/", os.sep)) for u in doc["units"]]
    if region == "twl":
        return [os.path.join(ROOT, "asm", "twl", "twl.s")]
    if region.startswith("ov"):
        return [os.path.join(ROOT, "asm", "overlays", region + ".s")]
    return []


def listing_labels(region):
    """(sorted label addresses, {label: extent end}) for one region.

    A label's extent is its traced code: from the label to the end of the
    last instruction before the next function label.  disasm.py writes code
    it never reached as .word data, so an unlabelled SDK function that sits
    after a function's literal pool (OSi_IrqDma0 after OSi_IrqHandler's
    pool) is outside the extent, while a lookalike that repeats a function's
    own instructions is inside it."""
    labels = []
    ends = {}
    for path in listing_files(region):
        if not os.path.exists(path):
            continue
        cur = None
        with open(path, encoding="utf-8") as fh:
            for raw in fh:
                line = raw.strip()
                m = RE_FUNC_LABEL.match(line)
                if m:
                    cur = int(m.group(1), 16)
                    labels.append(cur)
                    continue
                if cur is None or not line or line.startswith("/*"):
                    continue
                if line.startswith(".") and not line.startswith(".inst"):
                    continue
                am = RE_ADDR_BYTES.search(line)
                if am and am.group(2):
                    end = int(am.group(1), 16) + len(am.group(2).split())
                    if end > ends.get(cur, cur):
                        ends[cur] = end
    return sorted(set(labels)), ends


def known_extents(region, catalog_rows, shard_addrs):
    """(exempt starts, sorted [(start, end, kind, name)]) of the functions
    known in one region.  Exempt starts are the listing labels, catalog row
    addresses and shard entry addresses."""
    labels, lend = listing_labels(region)
    ext = []
    for a in labels:
        if a in lend:
            ext.append((a, lend[a], "listing", "func_%08X" % a))
    csize = {}
    for a, name, size in catalog_rows:
        if size > 0:
            ext.append((a, a + size, "catalog", name))
            csize[a] = max(size, csize.get(a, 0))
    for a, name in shard_addrs:
        if a in csize:
            end = a + csize[a]
        elif a in lend:
            end = lend[a]
        else:
            # a shard entry with no label and no catalog size: no extent
            continue
        ext.append((a, end, "matched", name))
    ext.sort()
    exempt = set(labels)
    exempt.update(a for a, _n, _s in catalog_rows)
    exempt.update(a for a, _n in shard_addrs)
    return exempt, ext


def load_shards():
    """{region: [(address, name)]} from layout/matched."""
    out = defaultdict(list)
    for path in glob.glob(os.path.join(ROOT, "layout", "matched", "*", "*.json")):
        try:
            doc = json.load(open(path, encoding="utf-8"))
        except ValueError:
            continue
        for f in doc.get("functions", []):
            reg = f.get("region") or doc.get("region")
            try:
                out[reg].append((int(str(f["address"]), 0), f.get("name")))
            except (KeyError, ValueError):
                continue
    return out


def interior_rejections(out, catalog=CATALOG):
    """Drop scan placements that start strictly inside another known
    function; returns [(region, address, name, reason)]."""
    import bisect
    cat = defaultdict(list)
    if os.path.exists(catalog):
        for s in json.load(open(catalog, encoding="utf-8")).get("symbols", []):
            cat[s.get("region")].append((int(s["address"]), s.get("name"),
                                         int(s.get("size") or 0)))
    shards = load_shards()
    rejected = []
    for reg in list(out):
        exempt, ext = known_extents(reg, cat.get(reg, ()), shards.get(reg, ()))
        starts = [e[0] for e in ext]
        # prefix maximum of the extent ends, with the entry that reaches it
        best = []
        cur = None
        for e in ext:
            if cur is None or e[1] > cur[1]:
                cur = e
            best.append(cur)
        for a in sorted(out[reg]):
            if a in exempt:
                continue
            k = bisect.bisect_left(starts, a) - 1
            if k < 0:
                continue
            s, end, kind, name = best[k]
            if end > a:
                e = out[reg].pop(a)
                rejected.append((reg, a, e["name"],
                                 "interior: starts inside %s %s 0x%08X..0x%08X (+0x%X)"
                                 % (kind, name, s, end, a - s)))
    return rejected


def profile_archives(variants, builds=("Rom",), include_demos=False):
    out = []
    for ap in libmatch.find_archives(include_demos=include_demos):
        tree, build, variant, thumb, libname = libmatch.classify(ap)
        if build in builds and variant in variants:
            out.append((ap, variant, thumb))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--variants", nargs="+", default=["TWL.HYB"])
    ap.add_argument("--builds", nargs="+", default=["Rom"])
    ap.add_argument("--demos", action="store_true")
    ap.add_argument("--where", nargs=2, metavar=("ADDR", "REGION"),
                    help="print where one address belongs and exit (no scan)")
    args = ap.parse_args()

    if args.where:
        addr = int(args.where[0], 0)
        region = args.where[1]
        e = union().get(region, {}).get(addr)
        top = ("itcm" if region.startswith("arm9_autoload")
               else "ov" if region.startswith("ov") else region)
        folder = top + ("_sdk" if e else "")
        print("region %s  address 0x%08X" % (region, addr))
        print("  kind   : %s" % ("sdk" if e else "game"))
        print("  folder : src/matched/%s/   (src/pending mirrors it)" % folder)
        if e:
            print("  symbol : %s" % e["name"])
        return 0

    picked = profile_archives(args.variants, args.builds, args.demos)
    archives = [a for a, _, _ in picked]
    print("archives (build %s, variants %s): %d" % (",".join(args.builds),
                                                    ",".join(args.variants), len(archives)))

    patterns, prov, by_archive = libmatch.collect(archives)
    print("distinct patterns: %d" % len(patterns))

    layout = json.load(open(os.path.join(ROOT, "layout", "layout.json"), encoding="utf-8"))
    regions = libmatch.load_regions(layout, os.path.join(ROOT, "extract"), overlays=True)
    rlen = {r.name: len(r.data) for r in regions}
    rbase = {r.name: r.base for r in regions}
    print("regions: %d" % len(regions))

    hits, usable = libmatch.scan(regions, patterns, progress=False)
    print("patterns scanned: %d; patterns with at least one hit: %d" % (usable, len(hits)))

    # The reference checks of libmatch.py: a hit whose named callees or
    # globals disagree with the image (a lookalike in game code) anchors
    # nothing.
    checker = libmatch.Checker(regions, patterns, hits)
    checker.build_consensus([(i, *next(iter(set(v)))) for i, v in hits.items()
                             if len(set(v)) == 1])
    dropped = []
    for i in list(hits):
        keep = []
        for reg, adr in hits[i]:
            why = checker.bad(i, reg, adr)
            if why:
                dropped.append((reg, adr, patterns[i].name, why))
            else:
                keep.append((reg, adr))
        if keep:
            hits[i] = keep
        else:
            del hits[i]
    print("hits dropped by the reference checks: %d" % len(dropped))

    # Patterns whose bytes verify at exactly the places another name's do
    # (one 16-byte getter shape under GX_GetBankForLCDC, OS_IsTickAvailable,
    # ...): their hits say nothing about which member sits there, so they
    # anchor nothing; libmatch.py names those addresses from callers and
    # siblings.
    shape = defaultdict(set)
    for i, v in hits.items():
        shape[frozenset(v)].add(patterns[i].name)
    twins = set(i for i, v in hits.items() if len(shape[frozenset(v)]) > 1)
    print("patterns sharing their hits with another name: %d" % len(twins))

    # group the patterns of one member+section: (archive, member, section)
    groups = defaultdict(list)
    for i, p in enumerate(patterns):
        if not prov.get(i):
            continue
        archive, member = prov[i][0]
        section, value = p.order
        groups[(archive, member, section)].append((value, p.size, p.name, i))

    out = defaultdict(dict)
    placed = 0
    verified = 0
    conflicts = []
    ties = []
    for (archive, member, section), syms in groups.items():
        # anchors per region: adr - value, from every direct hit in that region
        by_region = defaultdict(Counter)
        for value, size, name, i in syms:
            if i in twins:
                continue
            for reg, adr in hits.get(i, ()):
                by_region[reg][adr - value] += 1
        for reg, bases in by_region.items():
            if reg not in rlen:
                continue
            top = bases.most_common(2)
            base, support = top[0]
            if len(bases) > 1:
                conflicts.append((reg, os.path.basename(archive), member,
                                  hex(base), [hex(b) for b, _ in bases.most_common(3)]))
                if top[1][1] == support:
                    # A tie (a one-function member whose bytes verify at
                    # several places) does not determine the member's
                    # place; tools/libmatch.py resolves such rows.
                    ties.append((reg, member, [hex(b) for b, _ in top]))
                    continue
            for value, size, name, i in syms:
                a = base + value
                off = a - rbase[reg]
                if off < 0 or off + size > rlen[reg]:
                    continue
                method = "verified" if hits.get(i) and any(
                    r == reg and ad == a for r, ad in hits[i]) else "propagated"
                if method == "verified":
                    verified += 1
                else:
                    placed += 1
                out[reg][a] = {
                    "name": name,
                    "size": size,
                    "lib": os.path.basename(archive),
                    "member": member,
                    "method": method,
                }

    interior = interior_rejections(out)
    print("placements inside another known function, rejected: %d" % len(interior))
    for r, a, n, w in sorted(interior):
        print("   %-22s 0x%08X %-32s %s" % (r, a, n, w))
    dropped.extend(interior)
    verified = sum(1 for d in out.values() for e in d.values() if e["method"] == "verified")
    placed = sum(1 for d in out.values() for e in d.values() if e["method"] == "propagated")

    total = sum(len(v) for v in out.values())
    print()
    print("placed: %d symbols  (%d verified directly, %d propagated from an anchor)"
          % (total, verified, placed))
    print("groups: %d member+section; with an anchor: %d"
          % (len(groups), sum(1 for g in groups.values()
                              if any(hits.get(i) for _, _, _, i in g))))
    print("base conflicts (a member with two different bases in one region): %d" % len(conflicts))
    print("  of which ties, left unplaced: %d" % len(ties))
    for c in conflicts[:10]:
        print("   ", c)

    for reg in sorted(out, key=lambda r: -len(out[r])):
        b = sum(e["size"] for e in out[reg].values())
        p = sum(1 for e in out[reg].values() if e["method"] == "propagated")
        print("  %-24s %6d symbols %8d bytes   (%d propagated)"
              % (reg, len(out[reg]), b, p))

    json.dump({"variants": args.variants, "builds": args.builds,
               "regions": {r: {"%08X" % a: e for a, e in sorted(d.items())}
                           for r, d in out.items()},
               "rejected": [{"region": r, "address": "%08X" % a, "name": n,
                             "reason": w} for r, a, n, w in sorted(dropped)]},
              open(OUT, "w", encoding="utf-8"), indent=1)
    print("wrote %s" % os.path.relpath(OUT, ROOT))


if __name__ == "__main__":
    main()
