#!/usr/bin/env python3
"""Family table: family = original source file, inferred from __FILE__ anchors (layout/file_anchors.txt).
The image was linked file after file, so every function from one file's anchored function up to the next
file's anchored function is attributed to the first file (edges are fuzzy by a few functions).
Consecutive anchors naming the same file merge. Prints families ranked by matched-function count desc.

    python tools/session/families.py [OUT.txt]      (any cwd)
"""
import sys, os, bisect, collections
sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))), "tools"))
import env  # noqa: E402
import worklist as w  # noqa: E402


def main(argv=None):
    argv = sys.argv[1:] if argv is None else argv
    inv = w.build_inventory(); funcs = sorted(inv["funcs"], key=lambda f: f["addr"])
    anch = []
    for ln in open(os.path.join(env.ROOT, "layout", "file_anchors.txt")):
        p = ln.split()
        if ln.startswith("#") or len(p) < 5 or p[2] != "arm9_main": continue
        anch.append((int(p[1], 16), p[4]))
    anch.sort()
    merged = []
    for a, name in anch:
        if merged and merged[-1][1] == name: continue
        merged.append((a, name))
    starts = [a for a, _ in merged]
    fam = collections.OrderedDict()
    for f in funcs:
        i = bisect.bisect_right(starts, f["addr"]) - 1
        key = merged[i][1] if i >= 0 else "(before first anchor)"
        key = "%s@%08X" % (key, merged[i][0]) if i >= 0 else key
        fam.setdefault(key, []).append(f)
    rows = []
    for key, fs in fam.items():
        m = [f for f in fs if f["cls"] == "matched"]; o = [f for f in fs if f["cls"] == "open"]
        ob = sum(f["code_bytes"] for f in o)
        if not o: continue
        rows.append((len(m), -ob, key, len(fs), len(m), len(o), ob, fs[0]["addr"], fs[-1]["addr"],
                     sum(1 for f in fs if f["cls"] == "sdk"), " ".join("%X/%d" % (f["addr"], f["code_bytes"]) for f in o[:12])))
    rows.sort(reverse=True)
    out = open(argv[0] if argv else os.devnull, "w")
    print("families with open functions: %d (of %d)" % (len(rows), len(fam)))
    print("%-4s %-34s %5s %5s %5s %7s  %-8s %-8s  open functions (addr/bytes)" % ("#", "family", "fns", "match", "open", "openB", "from", "to"))
    for i, (_, _, key, n, nm, no, ob, a0, a1, nsdk, ol) in enumerate(rows, 1):
        line = "%-4d %-34s %5d %5d %5d %7d  %08X %08X  %s" % (i, key, n, nm, no, ob, a0, a1, ol)
        print(line); out.write(line + "\n")
    out.close()


if __name__ == "__main__":
    main()
