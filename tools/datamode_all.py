#!/usr/bin/env python3
"""Link every overlay that holds code in data mode and list the result per overlay.

For each overlay: `datagen.py companions N` (the data tail as C, in build/datac/ovNNN/,
from the user's own extract), then `gamelink.py N --data --extra=build/datac/ovNNN`.
Writes build/datamode_all.tsv (overlay, PASS/FAIL, reason) and prints a summary.
Nothing is written to src/ or to tracked files.

    python tools/datamode_all.py [--jobs N] [ids...]
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


def one(n):
    py = sys.executable
    c = subprocess.run([py, "tools/datagen.py", "companions", str(n)], cwd=ROOT,
                       capture_output=True, text=True)
    if c.returncode != 0:
        return n, "FAIL", "companions: " + (c.stdout + c.stderr).strip().splitlines()[-1][:300]
    g = subprocess.run([py, "tools/gamelink.py", str(n), "--data",
                        "--extra=build/datac/ov%03d" % n], cwd=ROOT, capture_output=True, text=True)
    text = g.stdout + g.stderr
    line = next((l for l in text.splitlines() if re.match(r"\s*ov%03d\s" % n, l)), "")
    if " PASS" in line:
        return n, "PASS", ""
    why = re.search(r"'why': '([^']*)'", line)
    return n, "FAIL", (why.group(1) if why else (line or text.strip().splitlines()[-1] if text.strip() else "no output"))[:300]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=6)
    ap.add_argument("ids", nargs="*", type=int)
    a = ap.parse_args()
    ids = a.ids or code_overlays()
    with ThreadPoolExecutor(a.jobs) as ex:
        res = sorted(ex.map(one, ids))
    os.makedirs(os.path.join(ROOT, "build"), exist_ok=True)
    with open(os.path.join(ROOT, "build", "datamode_all.tsv"), "w") as fh:
        for n, st, why in res:
            fh.write("ov%03d\t%s\t%s\n" % (n, st, why))
    ok = [n for n, st, _ in res if st == "PASS"]
    print("data mode: %d of %d overlays PASS" % (len(ok), len(res)))
    for n, st, why in res:
        if st != "PASS":
            print("  ov%03d FAIL %s" % (n, why))


if __name__ == "__main__":
    main()
