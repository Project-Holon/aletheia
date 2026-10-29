#!/usr/bin/env python3
"""Link every overlay that holds code in data mode and list the result per overlay.

For each overlay: `datagen.py companions N` (the data tail as C, in build/datac/ovNNN/,
from the user's own extract), then `gamelink.py N --data --extra=build/datac/ovNNN`.
Writes build/datamode_all.tsv (overlay, PASS/FAIL, reason) and prints a summary.
Nothing is written to src/ or to tracked files.

    python tools/datamode_all.py [--jobs N] [--target NAME | --version white] [ids...]

--version white: companions with Black's structure and White's values (build/datac_white/ovNNN),
linked with `gamelink.py N --data --version white`; the table is build/datamode_all_white.tsv.
--target NAME does the same for any target of tools/targets.py (build/datac_<t>/ovNNN,
build/datamode_all_<t>.tsv).

The DSi block is a region too (id `twl`, last in the table; with no ids it runs after the overlays):
`twldata.py --check` writes its data as C (build/datac/twl) and links src/game/twl with it, and
PASS needs no gap between the files.
"""
import argparse
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402


def tflag(t):
    """Command-line flags that select the target t (none for Black; `white` keeps its older spelling)."""
    if t == "black":
        return []
    return ["--version", "white"] if t == "white" else ["--target", t]


def code_overlays():
    out = []
    for d in sorted(os.listdir(os.path.join(ROOT, "src", "game"))):
        m = re.fullmatch(r"ov(\d{3})", d)
        if m:
            out.append(int(m.group(1)))
    return out


def one_twl(t="black"):
    """The DSi block: tools/twldata.py --check writes the companions and links src/game/twl."""
    g = subprocess.run([sys.executable, "tools/twldata.py", "--check"] + tflag(t),
                       cwd=ROOT, capture_output=True, text=True)
    text = g.stdout + g.stderr
    if g.returncode == 0 and "twl PASS" in text:
        return "twl", "PASS", ""
    why = re.search(r"'why': (?:'([^']*)'|\"([^\"]*)\")", text)
    lines = text.strip().splitlines()
    return "twl", "FAIL", ((why.group(1) or why.group(2)) if why else (lines[-1] if lines else "no output"))[:300]


def one(n, t="black"):
    if n == "twl":
        return one_twl(t)
    py = sys.executable
    ver = tflag(t)
    c = subprocess.run([py, "tools/datagen.py", "companions", str(n)] + ver, cwd=ROOT,
                       capture_output=True, text=True)
    if c.returncode != 0:
        return n, "FAIL", "companions: " + (c.stdout + c.stderr).strip().splitlines()[-1][:300]
    g = subprocess.run([py, "tools/gamelink.py", str(n), "--data",
                        "--extra=build/datac%s/ov%03d" % (targets.suffix(t), n)] + ver,
                       cwd=ROOT, capture_output=True, text=True)
    text = g.stdout + g.stderr
    line = next((l for l in text.splitlines() if re.match(r"\s*ov%03d\s" % n, l)), "")
    if " PASS" in line:
        return n, "PASS", ""
    why = re.search(r"'why': '([^']*)'", line)
    return n, "FAIL", (why.group(1) if why else (line or text.strip().splitlines()[-1] if text.strip() else "no output"))[:300]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=6)
    ap.add_argument("--version", choices=("black", "white"), default=None, help="older spelling of --target")
    ap.add_argument("--target", choices=sorted(targets.TARGETS), default=None)
    ap.add_argument("ids", nargs="*", help="overlay ids, or twl (the DSi block); none: every overlay and twl")
    a = ap.parse_args()
    t = a.target or a.version or "black"
    ids = [x if x == "twl" else int(x) for x in a.ids] or code_overlays() + ["twl"]
    with ThreadPoolExecutor(a.jobs) as ex:
        res = sorted(ex.map(lambda n: one(n, t), ids), key=lambda r: (r[0] == "twl", r[0]))
    os.makedirs(os.path.join(ROOT, "build"), exist_ok=True)
    with open(os.path.join(ROOT, "build", "datamode_all%s.tsv" % targets.suffix(t)), "w") as fh:
        for n, st, why in res:
            fh.write("%s\t%s\t%s\n" % (n if n == "twl" else "ov%03d" % n, st, why))
    ok = [n for n, st, _ in res if st == "PASS"]
    print("data mode: %d of %d regions PASS" % (len(ok), len(res)))
    for n, st, why in res:
        if st != "PASS":
            print("  %s FAIL %s" % (n if n == "twl" else "ov%03d" % n, why))


if __name__ == "__main__":
    main()
