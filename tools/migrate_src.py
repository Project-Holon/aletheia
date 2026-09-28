#!/usr/bin/env python3
"""Migrate src/matched and src/pending into category subfolders.

Destination is derived, never authored: a file's region gives the top folder
(arm9 / itcm / ov / twl) and membership in tools/sdkclass.py's union gives the
_sdk suffix.  Shard `source:` strings are rewritten textually so the JSON
formatting is untouched.

    python migrate_src.py --dry     report only
    python migrate_src.py           move files and rewrite shards
"""
import argparse
import glob
import json
import os
import re
import shutil
import sys

sys.path.insert(0, "tools")
import sdkclass

HDR_REGION = re.compile(r"^ \* region:\s+(\S+)", re.M)
HDR_ADDR = re.compile(r"^ \* address:\s+(\S+)", re.M)


def top(region):
    if region.startswith("arm9_autoload"):
        return "itcm"
    if region.startswith("ov"):
        return "ov"
    return region


def dest(region, is_sdk):
    return "%s%s" % (top(region), "_sdk" if is_sdk else "")


def header(path):
    try:
        txt = open(path, encoding="utf-8", errors="replace").read(8000)
    except OSError:
        return None, None
    r = HDR_REGION.search(txt)
    a = HDR_ADDR.search(txt)
    if not (r and a):
        return None, None
    try:
        return r.group(1), int(a.group(1), 0)
    except ValueError:
        return r.group(1), None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry", action="store_true")
    args = ap.parse_args()

    U = sdkclass.union()

    def is_sdk(region, addr):
        return addr is not None and addr in U.get(region, {})

    old2new = {}
    shard_hits = {}          # old -> shard path it was learned from
    shards = glob.glob("layout/matched/**/*.json", recursive=True)
    for jp in shards:
        try:
            d = json.load(open(jp, encoding="utf-8"))
        except Exception:
            continue
        reg = d.get("region") or ""
        for f in (d.get("functions") or d.get("entries") or []):
            src = f.get("source") or ""
            if not src.startswith(("src/matched/", "src/pending/")):
                continue
            a = f.get("address")
            a = int(a, 16) if isinstance(a, str) else a
            if a is None:
                continue
            base = os.path.basename(src)
            new = "src/matched/%s/%s" % (dest(reg, is_sdk(reg, a)), base)
            if new != src:
                old2new.setdefault(src, new)
            shard_hits.setdefault(src, jp)

    # files not referenced by any shard: classify from the header
    unreferenced = []
    for d in ("src/matched", "src/pending"):
        for fn in sorted(os.listdir(d)):
            if not fn.endswith((".c", ".cpp")):
                continue
            p = d + "/" + fn
            if p in old2new or p in shard_hits:
                continue
            reg, a = header(p)
            if reg is None:
                unreferenced.append((p, "no region header"))
                continue
            if a is None:
                unreferenced.append((p, "no address header"))
                continue
            new = "%s/%s/%s" % (d, dest(reg, is_sdk(reg, a)), fn)
            if new != p:
                old2new[p] = new
            else:
                unreferenced.append((p, "already in place"))

    # collisions: two sources want the same destination
    seen = {}
    collisions = []
    for old, new in old2new.items():
        if new in seen:
            collisions.append((new, seen[new], old))
        seen[new] = old

    from collections import Counter
    buckets = Counter(os.path.dirname(v) for v in old2new.values())
    print("shards read: %d" % len(shards))
    print("files to move: %d" % len(old2new))
    for k in sorted(buckets):
        print("   %-30s %6d" % (k, buckets[k]))
    print("collisions: %d" % len(collisions))
    for c in collisions[:10]:
        print("   ", c)
    print("unmapped/unmoved: %d" % len(unreferenced))
    for p, why in unreferenced[:10]:
        print("   %s (%s)" % (p, why))

    if args.dry:
        return

    # 1. move the files
    for old, new in sorted(old2new.items()):
        os.makedirs(os.path.dirname(new), exist_ok=True)
        if os.path.exists(old) and not os.path.exists(new):
            shutil.move(old, new)

    # 2. rewrite the shard source strings, textually, in EVERY shard that
    #    names a moved file (a source can appear in several shards).
    rewritten = 0
    for jp in shards:
        txt = open(jp, encoding="utf-8", newline="").read()
        orig = txt
        for m in set(re.findall(r'"source": "([^"]+)"', txt)):
            new = old2new.get(m)
            if new and new != m:
                txt = txt.replace('"source": "%s"' % m, '"source": "%s"' % new)
        if txt != orig:
            open(jp, "w", encoding="utf-8", newline="").write(txt)
            rewritten += 1
    print("moved %d files; rewrote %d shard files" % (len(old2new), rewritten))


if __name__ == "__main__":
    main()
