#!/usr/bin/env python3
"""Fast promotion pass: verify every src/pending MATCH/MATCH* file 6-way in parallel (exactly what
`one`/`tu` do), git mv the EXACT/EXACT* ones to src/matched with the header status fixed and the
re-verify note dropped, then re-verify every touched shard 6-way in parallel. Prints a table."""
import re, glob, os, sys, subprocess
from concurrent.futures import ThreadPoolExecutor
REPO = "<home>/Documents/aletheia"; os.chdir(REPO)
S = "/private/tmp/claude-501/-Users-ilias-Documents-aletheia/0da4c159-a458-434b-9491-68afdc3fd61a/scratchpad"
def hdr(f):
    h = open(f, errors="replace").read(12000).split("*/", 1)[0]
    g = lambda k: (re.search(r"^ \* %s:\s+(\S+)" % k, h, re.M) or [None, None])[1]
    return dict(status=g("status"), fn=g("function"), addr=g("address"), isa=g("isa"),
                cc=g("compiler") or "1.1p1", unit=bool(re.search(r"^ \* unit:\s+yes", h, re.M)),
                pkt=g("packet"), flags=(re.search(r"^ \* flags:\s+(.*)$", h, re.M) or [None, None])[1])
files = [f for f in sorted(glob.glob("src/pending/*.c")) if hdr(f)["status"] in ("MATCH", "MATCH*", "EXACT", "EXACT*")]
def verify(f):
    h = hdr(f)
    if h["unit"]:
        cmd = [sys.executable, "tools/match.py", "tu", "--src", f, "--addr", h["addr"], "--" + (h["isa"] or "thumb")]
    else:
        cmd = [sys.executable, "tools/match.py", "one", "--src", f, "--func", h["fn"], "--addr", h["addr"],
               "--cc", h["cc"]] + (["--" + h["isa"]] if h["isa"] else [])
    if h["flags"]: cmd += ["--flags=" + h["flags"]]
    out = subprocess.run(cmd, capture_output=True, text=True).stdout
    m = re.search(r"\b(EXACT\*?|MATCH\*?|DIFF|SIZE|CCERR|ISA)\b", out)
    sites = re.findall(r"\[sole-ref[^\]]*\]", out)
    return f, (m.group(1) if m else "?"), len(sites)
with ThreadPoolExecutor(6) as ex:
    res = list(ex.map(verify, files))
import json
json.dump({f: v for f, v, _ in res}, open(S + "/pending_verdicts.json", "w"), indent=0)
moved = []; pkts = set()
if "--dry" in sys.argv:
    print("verified %d pending files (dry): %s" % (len(res), {k: sum(1 for _, v, _ in res if v == k) for k in set(v for _, v, _ in res)})); sys.exit(0)
for f, v, ns in res:
    if v not in ("EXACT", "EXACT*"): continue
    dst = "src/matched/" + os.path.basename(f)
    if os.path.exists(dst): print("SKIP (exists):", dst); continue
    subprocess.run(["git", "mv", "-k", f, dst], check=False)
    if not os.path.exists(dst): os.replace(f, dst)
    lines = open(dst, encoding="utf-8").read().split("\n")
    out = []
    for ln in lines:
        if re.match(r"^ \* status:", ln): ln = " * status:   " + v
        if re.match(r"^ \* note:     re-verified 2026-09-2", ln): continue
        out.append(ln)
    open(dst, "w", encoding="utf-8", newline="\n").write("\n".join(out))
    moved.append((dst, v, ns)); pkts.add(hdr(dst)["pkt"] or "legacy")
print("verified %d pending files: %s" % (len(res), {k: sum(1 for _, v, _ in res if v == k) for k in set(v for _, v, _ in res)}))
print("moved %d files to src/matched; %d packets to re-shard" % (len(moved), len(pkts)))
def shard(p):
    r = subprocess.run([sys.executable, "tools/match.py", "manifest", "--verify", "--shard", p], capture_output=True, text=True)
    bad = [l for l in r.stdout.split("\n") if re.match(r"^ +0x[0-9A-F]{8} ", l) and not l.rstrip().endswith(("EXACT", "EXACT*"))]
    return p, len(bad), ("Traceback" in r.stderr)
with ThreadPoolExecutor(6) as ex:
    for p, nbad, err in ex.map(shard, sorted(pkts)):
        if nbad or err: print("SHARD PROBLEM %s non-exact=%d err=%s" % (p, nbad, err))
print("shards re-verified: %d" % len(pkts))
for dst, v, ns in moved: print("  %-45s %-6s sole-ref sites %d" % (dst, v, ns))
