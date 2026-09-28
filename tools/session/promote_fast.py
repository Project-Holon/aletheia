#!/usr/bin/env python3
"""Fast promotion pass: verify every src/pending MATCH/MATCH* file 6-way in parallel (exactly what
`one`/`tu` do), git mv the EXACT/EXACT* ones to src/matched with the header status fixed and the
re-verify note dropped, then re-verify every touched shard 6-way in parallel. Prints a table.

    python tools/session/promote_fast.py [--dry]      (any cwd)

Verdicts go to <scratch>/pending_verdicts.json (ALETHEIA_SCRATCH, else <tempdir>/aletheia),
where pending_pct.py reads them.  --dry verifies and writes verdicts but moves nothing.
"""
import re, glob, os, posixpath, sys, json, subprocess
from concurrent.futures import ThreadPoolExecutor
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(HERE)), "tools"))
sys.path.insert(0, HERE)
import env  # noqa: E402
from pending_pct import verdicts_path  # noqa: E402

MATCH_PY = os.path.join(env.ROOT, "tools", "match.py")


def hdr(f):
    h = open(f, encoding="utf-8", errors="replace").read(12000).split("*/", 1)[0]
    g = lambda k: (re.search(r"^ \* %s:\s+(\S+)" % k, h, re.M) or [None, None])[1]
    # status is a bare token; some files carry prose on the same line after a colon
    # ("status:   MATCH: every concrete byte reproduces; ..."), so match the word only.
    return dict(status=(re.search(r"^ \* status:\s+([A-Za-z][A-Za-z0-9]*\*?)", h, re.M) or [None, None])[1],
                fn=g("function"), addr=g("address"), isa=g("isa"),
                cc=g("compiler") or "1.1p1", unit=bool(re.search(r"^ \* unit:\s+yes", h, re.M)),
                pkt=g("packet"), region=g("region"),
                flags=(re.search(r"^ \* flags:\s+(.*)$", h, re.M) or [None, None])[1])


def verify(f):
    h = hdr(f)
    if h["unit"]:
        cmd = [env.PYTHON, MATCH_PY, "tu", "--src", f, "--addr", h["addr"], "--" + (h["isa"] or "thumb")]
    else:
        cmd = [env.PYTHON, MATCH_PY, "one", "--src", f, "--func", h["fn"], "--addr", h["addr"],
               "--cc", h["cc"]] + (["--" + h["isa"]] if h["isa"] else [])
    # overlays share load windows, so the same address disassembles differently in each;
    # without the header's region match.py picks the first region in load order and the
    # comparison silently uses the wrong overlay.  arm9/twl/ov230d names are valid too.
    if h.get("region"): cmd += ["--region", h["region"]]
    if h["flags"]: cmd += ["--flags=" + h["flags"]]
    out = subprocess.run(cmd, capture_output=True, text=True, cwd=env.ROOT).stdout
    m = re.search(r"\b(EXACT\*?|MATCH\*?|DIFF|SIZE|CCERR|ISA)\b", out)
    sites = re.findall(r"\[sole-ref[^\]]*\]", out)
    return f, (m.group(1) if m else "?"), len(sites)


def shard(p):
    r = subprocess.run([env.PYTHON, MATCH_PY, "manifest", "--verify", "--shard", p],
                       capture_output=True, text=True, cwd=env.ROOT)
    bad = [l for l in r.stdout.split("\n") if re.match(r"^ +0x[0-9A-F]{8} ", l) and not l.rstrip().endswith(("EXACT", "EXACT*"))]
    return p, len(bad), ("Traceback" in r.stderr)


def main(argv=None):
    argv = sys.argv[1:] if argv is None else argv
    os.chdir(env.ROOT)   # file keys and git paths are repo-relative

    def dest_dir(f):
        """src/matched/<category>/<file>: the category is derived, not chosen."""
        h = hdr(f)
        region = h["region"] or ""
        try:
            addr = int(h["addr"], 0) if h["addr"] else None
        except ValueError:
            addr = None
        try:
            sys.path.insert(0, os.path.join(env.ROOT, "tools"))
            import sdkclass
            is_sdk = addr is not None and addr in sdkclass.union().get(region, {})
        except Exception:
            is_sdk = False
        base = "itcm" if region.startswith("arm9_autoload") else (
            "ov" if region.startswith("ov") else region)
        return posixpath.join("src", "matched", base + ("_sdk" if is_sdk else ""),
                              posixpath.basename(f))
    target_args = [a for a in argv if not a.startswith("-")]
    if target_args:
        files = []
        for arg in target_args:
            files.extend(glob.glob(os.path.normpath(arg)))
        files = [f.replace(os.sep, "/") for f in sorted(set(files))]
    else:
        files = [f.replace(os.sep, "/") for f in sorted(glob.glob(os.path.join("src", "pending", "**", "*.c"), recursive=True))]
    # consider every pending file; a stale header status (e.g. DIFF that now
    # verifies EXACT) must not hide a promotable file.  verify() decides.
    files = [f for f in files if hdr(f)["status"] not in (None, "?")]
    with ThreadPoolExecutor(6) as ex:
        res = list(ex.map(verify, files))
    json.dump({f: v for f, v, _ in res}, open(verdicts_path(), "w"), indent=0)
    tally = {k: sum(1 for _, v, _ in res if v == k) for k in set(v for _, v, _ in res)}
    if "--dry" in argv:
        print("verified %d pending files (dry): %s" % (len(res), tally)); return 0
    moved = []; pkts = set()
    for f, v, ns in res:
        if v not in ("EXACT", "EXACT*"): continue
        dst = dest_dir(f)   # git pathspec, same on every host
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
    print("verified %d pending files: %s" % (len(res), tally))
    print("moved %d files to src/matched; %d packets to re-shard" % (len(moved), len(pkts)))
    with ThreadPoolExecutor(6) as ex:
        for p, nbad, err in ex.map(shard, sorted(pkts)):
            if nbad or err: print("SHARD PROBLEM %s non-exact=%d err=%s" % (p, nbad, err))
    print("shards re-verified: %d" % len(pkts))
    for dst, v, ns in moved: print("  %-45s %-6s sole-ref sites %d" % (dst, v, ns))
    return 0


if __name__ == "__main__":
    sys.exit(main())
