#!/usr/bin/env python3
"""Packetise the open arm9 SDK pool for lane assignment.

Open = sdkclass union for region arm9, restricted to addresses that are real
labels in asm/arm9/main.s, minus anything with a matched shard entry, minus
the runtime_arm9.txt rows.  Packets are contiguous address bands balanced by
bytes so no two lanes overlap and each works one stretch of the image.

    python tools/session/arm9sdk_packets.py [--lanes N]
"""
import argparse
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import sdkclass  # noqa: E402

LABEL = re.compile(r"^(?:func|sub)_[0-9A-Fa-f]{6,8}:", re.M)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--lanes", type=int, default=12)
    args = ap.parse_args()

    union = sdkclass.union().get("arm9", {})

    labels = set()
    listing = os.path.join(ROOT, "asm", "arm9", "main.s")
    if os.path.exists(listing):
        txt = open(listing, encoding="utf-8", errors="replace").read()
        for m in LABEL.finditer(txt):
            labels.add(int(m.group(0)[:-1].split("_")[1], 16))

    matched = set()
    for jp in glob.glob(os.path.join(ROOT, "layout", "matched", "arm9", "**", "*.json"),
                        recursive=True):
        try:
            d = json.load(open(jp, encoding="utf-8"))
        except Exception:
            continue
        for f in (d.get("functions") or d.get("entries") or []):
            a = f.get("address")
            if a is not None:
                matched.add(int(a, 16) if isinstance(a, str) else a)

    runtime = set()
    rt = os.path.join(ROOT, "layout", "runtime_arm9.txt")
    if os.path.exists(rt):
        for ln in open(rt, encoding="utf-8"):
            p = ln.split("#", 1)[0].split()
            if p:
                try:
                    runtime.add(int(p[0], 16))
                except ValueError:
                    pass

    # library/object per catalogued address, for the extraction hint
    objof = {}
    cat = os.path.join(ROOT, "layout", "symbols_sdk.json")
    if os.path.exists(cat):
        for s in json.load(open(cat, encoding="utf-8")).get("symbols", []):
            if s.get("region") == "arm9":
                objof[int(s["address"])] = (os.path.basename(s.get("lib") or ""),
                                            s.get("object") or "")

    openf = []
    for a, e in union.items():
        if a in labels and a not in matched and a not in runtime:
            lib, obj = objof.get(a, ("", ""))
            openf.append({"addr": a, "size": int(e.get("size") or 0),
                          "name": e.get("name") or "func_%08X" % a,
                          "lib": lib, "object": obj})
    openf.sort(key=lambda f: f["addr"])

    total = sum(f["size"] for f in openf)
    target = total / args.lanes
    packets, cur, curb = [], [], 0
    for f in openf:
        cur.append(f)
        curb += f["size"]
        if curb >= target and len(packets) < args.lanes - 1:
            packets.append(cur)
            cur, curb = [], 0
    if cur:
        packets.append(cur)

    out = []
    for i, p in enumerate(packets, 1):
        out.append({
            "id": "A9%02d" % i,
            "lo": "0x%08X" % p[0]["addr"],
            "hi": "0x%08X" % (p[-1]["addr"] + p[-1]["size"]),
            "funcs": len(p),
            "bytes": sum(f["size"] for f in p),
            "objects": sorted({f["object"] for f in p if f["object"]}),
            "list": [{"addr": "0x%08X" % f["addr"], "size": f["size"], "name": f["name"],
                      "lib": f["lib"], "object": f["object"]} for f in p],
        })
    dst = os.path.join(ROOT, "tools", "session", "arm9sdk_packets.json")
    json.dump({"open_functions": len(openf), "open_bytes": total, "packets": out},
              open(dst, "w", encoding="utf-8"), indent=1)

    print("open arm9 SDK: %d functions, %d bytes, %d objects"
          % (len(openf), total, len({f["object"] for f in openf if f["object"]})))
    print("%d packets -> %s" % (len(out), os.path.relpath(dst, ROOT)))
    print()
    print("%-6s %-20s %6s %8s  %s" % ("packet", "range", "funcs", "bytes", "objects"))
    for p in out:
        print("%-6s %-20s %6d %8d  %d" % (p["id"], p["lo"] + "-" + p["hi"], p["funcs"],
                                          p["bytes"], len(p["objects"])))


if __name__ == "__main__":
    main()
