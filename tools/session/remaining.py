#!/usr/bin/env python3
"""Recompute open functions per pseudo-family (upper half) and per anchored family from current shards.

    python tools/session/remaining.py      (any cwd)
"""
import json, glob, os, re, sys
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(HERE)), "tools"))
import env  # noqa: E402


def R(*parts):
    return os.path.join(env.ROOT, *parts)


def main():
    matched = set()
    for f in glob.glob(R("layout", "matched", "*", "pkt_*.json")):
        for e in json.load(open(f))["functions"]:
            matched.add(int(e["address"], 16))
            for m in e.get("functions", []):
                mm = re.search(r"([0-9A-Fa-f]{8})", m)
                if mm: matched.add(int(mm.group(1), 16))
    w = json.load(open(R("layout", "worklist.json")))
    size = {}; isa = {}
    for p in w["packets"].values():
        for fn in p["functions"]:
            a = int(fn["addr"], 16); size[a] = fn["code"]; isa[a] = fn["isa"][0]
    notes = set()
    for f in glob.glob(R("docs", "notes", "*.txt")):
        for mm in re.finditer(r"0x(02[0-9A-Fa-f]{6})", open(f, errors="ignore").read()[:4000]):
            notes.add(int(mm.group(1), 16))
    pend = set()
    for f in glob.glob(R("src", "pending", "*.c")):
        mm = re.search(r"address:\s+0x([0-9A-Fa-f]{8})", open(f, errors="ignore").read())
        if mm: pend.add(int(mm.group(1), 16))

    def tag(a):
        return "P" if a in pend else ("N" if a in notes else "U")
    fams = json.load(open(os.path.join(HERE, "pseudo_families.json")))
    rows = []
    for fam in fams:
        op = [a for a in fam["members"] if a not in matched and (a-4) not in matched and size.get(a, 0) > 0]
        if not op: continue
        ob = sum(size[a] for a in op)
        mc = sum(1 for a in fam["members"] if a in matched)
        rows.append((ob, fam["name"], mc, op))
    rows.sort(reverse=True)
    tot = sum(r[0] for r in rows)
    print(f"clusters with open functions: {len(rows)}, open functions {sum(len(r[3]) for r in rows)}, bytes {tot}")
    for ob, name, mc, op in rows:
        print(f"{name:14s} matched {mc:3d} openB {ob:5d}  " + " ".join(f"0x{a:08X}/{size[a]}{isa[a]}/{tag(a)}" for a in op))


if __name__ == "__main__":
    main()
