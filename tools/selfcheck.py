#!/usr/bin/env python3
"""Smoke test of the host setup: what tools/env.py resolved, one compile through
match.py of an already-EXACT function, and one split build with that function's
C unit spliced in.  Writes nothing under the repo (the build goes to the scratch
directory); runs from any cwd on Windows, macOS and Linux.

    python tools/selfcheck.py [--shard pkt_XXXXXXXX]

Without --shard it takes the git-tracked single-function EXACT shard under
layout/matched/arm9 with the smallest source file.  Exit status 0 when every
check passes.
"""

from __future__ import annotations

import argparse
import glob
import json
import os
import re
import shutil
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import env  # noqa: E402

ROOT = env.ROOT


def tracked_shards():
    """Repo-relative shard paths git knows about, or None without git."""
    git = shutil.which("git")
    if not git:
        return None
    r = subprocess.run([git, "ls-files", "--", os.path.join("layout", "matched", "arm9")],
                       cwd=ROOT, capture_output=True, text=True)
    if r.returncode != 0:
        return None
    return {os.path.normpath(p) for p in r.stdout.split()}


def pick_entry(shard_id=None):
    tracked = tracked_shards()
    best = None
    for path in sorted(glob.glob(os.path.join(ROOT, "layout", "matched", "arm9", "pkt_*.json"))):
        rel = os.path.normpath(os.path.relpath(path, ROOT))
        if shard_id and os.path.splitext(os.path.basename(path))[0] != shard_id:
            continue
        if not shard_id and tracked is not None and rel not in tracked:
            continue
        d = json.load(open(path, encoding="utf-8"))
        fs = d.get("functions", [])
        if len(fs) != 1 and not shard_id:
            continue
        e = fs[0]
        src = os.path.join(ROOT, *e["source"].split("/"))
        if e.get("status") != "EXACT" or e.get("kind") != "game" or not os.path.exists(src):
            continue
        key = os.path.getsize(src)
        if best is None or key < best[0]:
            best = (key, path, d, e, src)
    if best is None:
        sys.exit("selfcheck: no suitable EXACT shard found%s" % (" for " + shard_id if shard_id else ""))
    return best[1:]


def run(cmd, timeout):
    t0 = time.time()
    try:
        r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True,
                           encoding="utf-8", errors="replace", timeout=timeout)
        out, rc = r.stdout + r.stderr, r.returncode
    except Exception as exc:   # missing interpreter, timeout
        out, rc = str(exc), 127
    return rc, out, time.time() - t0


def check_compile(entry, shard, src):
    flags = entry["flags"]
    base = shard.get("base_flags", "")
    if base and flags.startswith(base):
        flags = flags[len(base):]
    flags = re.sub(r"-lang\s+\S+", "", flags).split()
    cc = entry["compiler"].split("/", 1)[-1] if entry["compiler"].startswith("dsi/") else entry["compiler"]
    cmd = [env.PYTHON, os.path.join(ROOT, "tools", "match.py"), "one", "--src", src,
           "--func", entry["name"], "--addr", entry["address"], "--cc", cc,
           "--" + entry.get("isa", "thumb"), "--lang", entry.get("lang", "c99")]
    if flags:
        cmd.append("--flags=" + " ".join(flags))
    rc, out, dt = run(cmd, 600)
    m = re.search(r"^(EXACT\*?|MATCH\*?|DIFF|SIZE|CCERR|ISA)\b", out, re.M)
    verdict = m.group(1) if m else "?"
    ok = verdict == "EXACT"
    return ok, "%s %s -> %s (%.1fs)" % (entry["name"], entry["compiler"], verdict, dt), out


def check_build(shard_path):
    bdir = env.scratch_dir("selfcheck_build")
    cmd = [env.PYTHON, os.path.join(ROOT, "tools", "build.py"), "--split", "--only", "arm9_main",
           "--c-manifest", shard_path, "-b", bdir]
    rc, out, dt = run(cmd, 600)
    line = next((l.strip() for l in out.splitlines() if l.strip().startswith("arm9_main ")), "")
    ok = rc == 0 and "PASS" in line
    return ok, "%s (%.1fs)" % (re.sub(r"\s+", " ", line) or "no result line", dt), out


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--shard", help="shard id to use, e.g. pkt_02031288")
    ap.add_argument("-v", "--verbose", action="store_true", help="print tool output on failure and success")
    args = ap.parse_args(argv)

    print("[env]")
    for line in env.report():
        print("  " + line)
    shard_path, shard, entry, src = pick_entry(args.shard)
    print("[subject] %s  %s" % (os.path.relpath(shard_path, ROOT), os.path.relpath(src, ROOT)))

    results = []
    for name, fn, a in (("match.py one", check_compile, (entry, shard, src)),
                        ("build.py --split", check_build, (shard_path,))):
        ok, summary, out = fn(*a)
        results.append(ok)
        print("[%s] %s  %s" % (name, "PASS" if ok else "FAIL", summary))
        if args.verbose or not ok:
            print("\n".join("    " + l for l in out.strip().splitlines()[-15:]))
    passed = sum(results)
    print("selfcheck: %d/%d passed" % (passed, len(results)))
    return 0 if passed == len(results) else 1


if __name__ == "__main__":
    sys.exit(main())
