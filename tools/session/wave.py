#!/usr/bin/env python3
"""wave.py -- the fold-in and commit steps of the wave loop, portable.

    python tools/session/wave.py foldin
    python tools/session/wave.py commit "<label>" <prev_exact> <prev_repro>

foldin: worklist refresh, pending re-verify (promote_fast --dry), pending
figure, split build and pack, ROM build (exits non-zero unless the sha1 is
the original's), coverage maps,
then INCLUDE / HOLD lists of untracked src/matched files (sharded or not).
commit: runs foldin first and refuses unless it passes, then README figure, stage README, shards, docs, pending and the sharded
untracked sources only, commit with both figures and deltas, push.
Runs from any cwd on Windows, macOS and Linux (it changes to the repo root
itself); importable without side effects.  Stdlib only.
"""
import glob, json, os, re, subprocess, sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))), "tools"))
import env  # noqa: E402

ROOT = env.ROOT
PY = env.PYTHON
SES = os.path.join("tools", "session")
TOOL = lambda name: os.path.join("tools", name)
ROM_SHA1 = "26ad0b9967aa279c4a266ee69f52b9b2332399a5"


def run(cmd, tail=1, check=True):
    r = subprocess.run(cmd, capture_output=True, text=True, encoding="utf-8", errors="replace")
    out = (r.stdout + r.stderr).strip().splitlines()
    for line in out[-tail:] if tail else []:
        print("   ", line)
    if check and r.returncode != 0:
        sys.exit("failed: %s" % " ".join(cmd))
    return "\n".join(out)


def sharded_sources():
    s = {}
    for f in glob.glob(os.path.join("layout", "matched", "*", "pkt_*.json")):
        for e in json.load(open(f, encoding="utf-8"))["functions"]:
            s[e["source"].replace("\\", "/")] = f
    return s


def untracked_matched():
    st = subprocess.run(["git", "status", "--short"], capture_output=True, text=True).stdout.splitlines()
    return [l[3:].replace("\\", "/") for l in st if l.startswith("?? src/matched/")]


def figures():
    out = run([PY, os.path.join(SES, "pending_pct.py")], tail=0, check=False)
    ex = re.search(r"exact coverage\s+([\d.]+)%.*?, (\d+) functions", out)
    rp = re.search(r"reproduced coverage\s+([\d.]+)%", out)
    if not (ex and rp):
        sys.exit("figures missing:\n" + out)
    return float(ex.group(1)), float(rp.group(1)), int(ex.group(2)), out


def foldin():
    os.chdir(ROOT)
    print("[refresh]"); run([PY, TOOL("worklist.py"), "--refresh"])
    print("[pending re-verify]"); run([PY, os.path.join(SES, "promote_fast.py"), "--dry"], tail=1, check=False)
    print("[figures]"); ex, rp, nf, out = figures(); print("   ", out.strip().replace("\n", "\n    "))
    print("[split build]"); run([PY, TOOL("build.py"), "--split", "--pack"])
    print("[rom]"); o = run([PY, TOOL("ndsrom.py"), "build", "extract", "-o", os.path.join("build", "pokeblack.nds"),
                             "--override", os.path.join("build", "pack")], tail=0)
    shl = [l for l in o.splitlines() if "sha1" in l][-1:]
    print("   ", shl)
    if not shl or ROM_SHA1 not in shl[0].lower():
        sys.exit("foldin FAILED: rebuilt ROM sha1 is not %s (got %s)"
                 % (ROM_SHA1, shl[0] if shl else "no sha1 line"))
    print("[maps]"); run([PY, TOOL("coveragemap.py")])
    sh = sharded_sources(); unt = untracked_matched()
    print("INCLUDE", " ".join(u for u in unt if u in sh))
    print("HOLD   ", " ".join(u for u in unt if u not in sh))
    st = subprocess.run(["git", "status", "--short"], capture_output=True, text=True).stdout
    print("\n".join(l for l in st.splitlines() if l.startswith("?? layout")))
    print("FIGURES %.2f %.2f %d" % (ex, rp, nf))
    return ex, rp, nf


def commit(label, pex, prp):
    """Runs foldin() first, in this same invocation: a commit never rests on
    a fold-in from an earlier run or a tree whose ROM no longer rebuilds.
    foldin() exits non-zero on a sha1 mismatch, so reaching the next line
    means it passed."""
    os.chdir(ROOT)
    print("[commit: foldin first]")
    fres = foldin()
    if not fres:
        sys.exit("commit refused: foldin did not pass in this invocation")
    ex, rp, nf, _ = figures()
    if not (ex and nf):
        sys.exit("commit refused: coverage figures missing")
    p = "README.md"; s = open(p, encoding="utf-8").read()
    s2 = re.sub(r"\d*\.?\d*% of ARM9 game code ships as verified C \(\d* functions",
                "%.2f%% of ARM9 game code ships as verified C (%d functions" % (ex, nf), s)
    if s2 == s and ("%.2f%% of ARM9" % ex) not in s:
        sys.exit("README pattern not found")
    open(p, "w", encoding="utf-8").write(s2)
    sh = sharded_sources(); inc = [u for u in untracked_matched() if u in sh]
    dex = ex - pex; drp = (rp - prp) - dex
    subprocess.run(["git", "add", "-u", "README.md", "layout/matched", "layout/worklist.json", "docs/families", "docs/notes",
                    "docs/idioms", "docs/sessions", "src/pending", "src/matched",
                    "docs/coverage_map.svg", "docs/coverage_map_files.svg"], check=False)
    subprocess.run(["git", "add", "README.md", "docs/MATCHING.md", "layout/matched", "docs/families", "docs/notes", "docs/idioms",
                    "docs/sessions", "src/pending", "docs/coverage_map.svg", "docs/coverage_map_files.svg"], check=False)
    if inc:
        subprocess.run(["git", "add"] + inc, check=True)
    msg = "%s: %d functions exact, exact coverage %.2f percent (%+.2f); reproduced coverage %.2f percent (pending part %+.2f)" % (
        label, len(inc), ex, dex, rp, drp)
    subprocess.run(["git", "commit", "-q", "-m", msg], check=True)
    for _ in range(4):
        if subprocess.run(["git", "push", "-q", "origin", "main"]).returncode == 0:
            break
    print(run(["git", "log", "--oneline", "-1"], tail=0))
    print("FIGURES %.2f %.2f %d" % (ex, rp, nf))


if __name__ == "__main__":
    if len(sys.argv) >= 2 and sys.argv[1] == "foldin":
        foldin()
    elif len(sys.argv) == 5 and sys.argv[1] == "commit":
        commit(sys.argv[2], float(sys.argv[3]), float(sys.argv[4]))
    else:
        sys.exit(__doc__)
