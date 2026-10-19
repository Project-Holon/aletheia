#!/usr/bin/env python3
"""Link every overlay for White from src/game and list PASS/FAIL per overlay.

Runs `gamelink.py N --version white` for each overlay that has a source directory
(or the ids given) and writes build/whitelink.tsv (overlay, PASS/FAIL, differing
words). Nothing is written to src/ or to tracked files.

    python tools/whitelink.py [--jobs N] [--black] [ids...]

--black runs the same overlays without the version flag, as the control.
"""
import argparse
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def code_overlays():
    out = []
    for d in sorted(os.listdir(os.path.join(ROOT, "src", "game"))):
        m = re.fullmatch(r"ov(\d{3})", d)
        if m:
            out.append(int(m.group(1)))
    return out


def one(n, black):
    cmd = [sys.executable, "tools/gamelink.py", str(n)]
    if not black:
        cmd += ["--version", "white"]
    g = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    text = g.stdout + g.stderr
    line = next((l for l in text.splitlines() if re.match(r"\s*ov%03d\s" % n, l)), "")
    if " PASS" in line:
        return n, "PASS", ""
    d = re.search(r"'diffs': (\[.*?\]), 'split'", line)
    if d:
        words = re.findall(r"'(0x[0-9a-f]+)'", d.group(1))
        return n, "FAIL", "diffs " + " ".join(words)
    return n, "FAIL", (line or (text.strip().splitlines() or ["no output"])[-1])[:300]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=6)
    ap.add_argument("--black", action="store_true")
    ap.add_argument("ids", nargs="*", type=int)
    a = ap.parse_args()
    ids = a.ids or code_overlays()
    with ThreadPoolExecutor(a.jobs) as ex:
        res = sorted(ex.map(lambda n: one(n, a.black), ids))
    os.makedirs(os.path.join(ROOT, "build"), exist_ok=True)
    name = "blacklink.tsv" if a.black else "whitelink.tsv"
    with open(os.path.join(ROOT, "build", name), "w", newline="\n") as fh:
        for n, st, why in res:
            fh.write("ov%03d\t%s\t%s\n" % (n, st, why))
    ok = [n for n, st, _ in res if st == "PASS"]
    print("%s: %d of %d overlays PASS" % ("black" if a.black else "white", len(ok), len(res)))
    for n, st, why in res:
        if st != "PASS":
            print("  ov%03d FAIL %s" % (n, why[:200]))


if __name__ == "__main__":
    main()
