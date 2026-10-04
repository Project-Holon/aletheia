#!/usr/bin/env python3
"""Enumerate open overlay functions in a size band, for a lane.

This is the one enumerator packet agents should use instead of re-deriving it.
It fixes three traps that cost lanes time:

  * coverage is checked against EVERY shard entry, including the nested
    ``functions`` list of a ``game_unit`` entry (ovstats.shard_entries keys on
    the entry's own name only, so a unit's members read as open) and against
    ``src/pending`` headers too;
  * shard files are read through match.shard_files(), so the twl region's
    non-``pkt_*.json`` shards are seen;
  * a candidate whose body has no branch and no ``[pc`` load over a long
    extent is flagged ``phantom?`` - it is a stale ``func_`` label on a pool
    run, not a function (docs/idioms/a-data-word-that-looks-like-a-saved-lr-prologue-becomes-a-function.md).

Usage:
    python tools/lane.py --band 128 256 --overlays 0 47
    python tools/lane.py --band 0 16 --regions ov021 ov022
    python tools/lane.py --band 256 512 --overlays 120 236 --limit 200
"""
import argparse
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import ovstats  # noqa: E402
import match  # noqa: E402

RE_HEX8 = re.compile(r"(?:func|sub)_([0-9A-Fa-f]{8})$")
RE_BR = re.compile(r"\b(bl|blx)\b|\bpc\b|\[pc")


def covered_addresses():
    """(region, address) pairs every shard entry covers, nested names included."""
    out = set()
    for path in match.shard_files():
        try:
            doc = json.load(open(path, encoding="utf-8"))
        except Exception:
            continue
        for e in doc.get("functions", []):
            if not isinstance(e, dict):
                continue
            reg = e.get("region", "")
            if e.get("address"):
                out.add((reg, int(e["address"], 16)))
            for name in e.get("functions", []) or []:
                m = RE_HEX8.search(str(name))
                if m:
                    out.add((reg, int(m.group(1), 16)))
    return out


def pending_addresses():
    """Pending claims keyed by region as well as address: overlays overlap."""
    out = {}
    for path in glob.glob(os.path.join(ROOT, "src", "pending", "**", "*.c"), recursive=True):
        head = open(path, encoding="utf-8", errors="replace").read(6000).split("*/", 1)[0]
        m = re.search(r"^ \* address:\s+0x([0-9A-Fa-f]{8})", head, re.M)
        if m:
            region = re.search(r"^ \* region:\s+(\S+)", head, re.M)
            if region:
                out[(region.group(1), int(m.group(1), 16))] = os.path.basename(path)
    return out


def body_has_branch(path, addr, end):
    """True if any instruction in [addr,end) is a call or a pc/pool load."""
    try:
        fh = open(path, encoding="utf-8", errors="replace")
    except OSError:
        return True
    try:
        ins = False
        for line in fh:
            s = line.strip()
            if s.startswith("func_") or s.startswith("sub_") or s.startswith("loc_"):
                ins = False
            m = ovstats.INSN.search(line)
            if m:
                a = int(m.group(1), 16)
                if a < addr:
                    continue
                if a >= end:
                    break
                if "bl" in line or "blx" in line or "pc" in line or "[pc" in line:
                    return True
    finally:
        fh.close()
    return False


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--band", nargs=2, type=int, required=True, metavar=("LO", "HI"))
    ap.add_argument("--overlays", nargs=2, type=int, metavar=("A", "B"))
    ap.add_argument("--regions", nargs="+")
    ap.add_argument("--limit", type=int, default=300)
    a = ap.parse_args(argv)

    lo, hi = a.band
    covered = covered_addresses()
    pending = pending_addresses()

    paths = sorted(glob.glob(os.path.join(ROOT, "asm", "overlays", "ov*.s")))
    rows = []
    for path in paths:
        region = os.path.basename(path)[:-2]
        if not (region.startswith("ov") and region[2:].isdigit()):
            continue
        n = int(region[2:])
        if a.regions:
            if region not in a.regions:
                continue
        elif a.overlays:
            if not (a.overlays[0] <= n <= a.overlays[1]):
                continue
        head = "".join(open(path, encoding="utf-8", errors="replace").readlines()[:18])
        m = ovstats.HDR_RANGE.search(head)
        span_end = int(m.group(2), 16) if m else 0
        labels = ovstats.listing_labels(path)
        addrs = [x for x, _ in labels]
        for i, (addr, name) in enumerate(labels):
            end = addrs[i + 1] if i + 1 < len(addrs) else span_end
            size = end - addr
            if not (lo <= size < hi):
                continue
            if (region, addr) in covered or (region, addr) in pending:
                continue
            flag = ""
            if size >= 256 and not body_has_branch(path, addr, end):
                flag = "phantom?"
            rows.append((region, addr, size, name, flag))

    rows.sort(key=lambda r: (r[1], r[0]))
    print("open overlay functions in [%d,%d): %d candidate(s)" % (lo, hi, len(rows)))
    for region, addr, size, name, flag in rows[:a.limit]:
        print("  %-7s 0x%08X %6d  %-22s %s" % (region, addr, size, name, flag))
    if len(rows) > a.limit:
        print("  ... %d more" % (len(rows) - a.limit))
    return 0


if __name__ == "__main__":
    sys.exit(main())
