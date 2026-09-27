#!/usr/bin/env python3
"""Packetise the open overlay SDK pool for lane assignment.

Reads layout/symbols_sdk.json, drops everything that already has a matched
shard entry, groups what is left by (region, archive object) so a lane
extracts each member once, and packs those groups into byte-balanced
packets.  A packet never spans two overlay regions, because overlay windows
overlap: the same address can be code in ov016 and something else in ov107,
so a shard name is only unique within its region.

Writes tools/session/sdk_packets.json and prints the assignment table.

    python tools/session/sdk_packets.py            20 packets
    python tools/session/sdk_packets.py --lanes 12
"""
import argparse
import glob
import json
import os
from collections import defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
OUT = os.path.join(ROOT, "tools", "session", "sdk_packets.json")


def load():
    sdk = json.load(open(os.path.join(ROOT, "layout", "symbols_sdk.json"), encoding="utf-8"))["symbols"]
    matched = set()
    for p in glob.glob(os.path.join(ROOT, "layout", "matched", "**", "*.json"), recursive=True):
        try:
            sh = json.load(open(p, encoding="utf-8"))
        except Exception:
            continue
        reg = str(sh.get("region") or "").lower()
        for f in (sh.get("functions") or sh.get("entries") or []):
            a = f.get("address")
            if a:
                matched.add((reg, int(a, 16) if isinstance(a, str) else a))
    ov = [s for s in sdk if str(s.get("region", "")).startswith("ov")]
    openf = [s for s in ov if (s["region"].lower(), s["address"]) not in matched]
    for s in openf:
        s["isa"] = "thumb" if s.get("thumb") else "arm"
        s["lib"] = os.path.basename(s.get("lib") or "")
    return openf


def ffd(groups, slots):
    """First-fit-decreasing: groups (list) into `slots` bins, balanced by bytes."""
    bins = [[] for _ in range(slots)]
    load = [0] * slots
    for g in sorted(groups, key=lambda g: -g["bytes"]):
        i = min(range(slots), key=lambda i: load[i])
        bins[i].append(g)
        load[i] += g["bytes"]
    return bins


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--lanes", type=int, default=20)
    args = ap.parse_args()

    openf = load()
    by_region = defaultdict(list)
    for s in openf:
        by_region[s["region"]].append(s)

    rbytes = {r: sum(x["size"] for x in v) for r, v in by_region.items()}

    # One group per (region, archive object): a lane extracts each member once and
    # then works its functions back to back.  Packing is global and byte-balanced
    # rather than per-region, because a per-region split gave the 117 KB overlay
    # a single 714-function packet.  Packets may span regions, so overlay SDK
    # shards are named pkt_<region>_<addr>: overlay windows overlap and the same
    # address is different code in different overlays, so the address alone is
    # not a unique shard id.
    groups = defaultdict(list)
    for s in openf:
        groups[(s["region"], s["lib"], s["object"])].append(s)
    glist = [{"region": k[0], "lib": k[1], "object": k[2],
              "funcs": sorted(v, key=lambda x: x["size"]),
              "bytes": sum(x["size"] for x in v)} for k, v in groups.items()]

    packets = []
    pid = 0
    for b in ffd(glist, args.lanes):
        fns = [f for g in b for f in g["funcs"]]
        if not fns:
            continue
        pid += 1
        packets.append({
            "id": "SDK%02d" % pid,
            "regions": sorted({f["region"] for f in fns}),
            "bytes": sum(f["size"] for f in fns),
            "funcs": len(fns),
            "objects": sorted({(g["region"], g["object"]) for g in b}),
            "size_bands": {("%d-%d" % (lo, hi - 1)): sum(1 for f in fns if lo <= f["size"] < hi)
                           for lo, hi in ((0, 32), (32, 64), (64, 128), (128, 256),
                                          (256, 512), (512, 1024), (1024, 1 << 30))
                           if any(lo <= f["size"] < hi for f in fns)},
            "list": [{"region": f["region"], "addr": "0x%08X" % f["address"], "size": f["size"],
                      "name": f["name"], "isa": f["isa"], "lib": f["lib"], "object": f["object"]}
                     for f in fns],
        })

    packets.sort(key=lambda p: (-p["bytes"], p["id"]))
    for n, p in enumerate(packets, 1):
        p["id"] = "SDK%02d" % n
    total_b = sum(p["bytes"] for p in packets)
    json.dump({"generated_from": "layout/symbols_sdk.json", "open_functions": len(openf),
               "open_bytes": total_b, "packets": packets},
              open(OUT, "w", encoding="utf-8"), indent=1)

    print("open pool: %d functions, %d bytes, %d objects, %d regions"
          % (len(openf), total_b, len({(s['lib'], s['object']) for s in openf}), len(by_region)))
    print("%d packets -> %s" % (len(packets), os.path.relpath(OUT, ROOT)))
    print()
    print("%-7s %6s %9s %-22s %s" % ("packet", "funcs", "bytes", "regions", "size bands (funcs)"))
    for p in packets:
        bands = " ".join("%s:%d" % (k, v) for k, v in sorted(p["size_bands"].items(),
                                                             key=lambda kv: int(kv[0].split("-")[0])))
        print("%-7s %6d %9d %-22s %s" % (p["id"], p["funcs"], p["bytes"],
                                          ",".join(p["regions"]), bands))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
