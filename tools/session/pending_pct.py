#!/usr/bin/env python3
"""Print exact coverage (worklist summary) and reproduced coverage = exact + bytes of open game
functions that have a byte-correct file in src/pending (status MATCH or MATCH*). Unit files in
pending count only functions they name in `symbols:`/`function:` that are open; approximate.

    python tools/session/pending_pct.py      (any cwd; reads the verdicts promote_fast.py
                                              wrote to <scratch>/pending_verdicts.json)
"""
import json, re, glob, os, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))), "tools"))
import env  # noqa: E402

VERDICTS = "pending_verdicts.json"


def verdicts_path():
    return os.path.join(env.scratch_dir(), VERDICTS)


def rel(path):
    """Repo-relative, forward slashes: the key promote_fast.py writes."""
    return os.path.relpath(path, env.ROOT).replace(os.sep, "/")


def main():
    wl = json.load(open(os.path.join(env.ROOT, "layout", "worklist.json")))
    s = wl["summary"]
    open_funcs = {}
    for p in wl["packets"].values():
        for f in p["functions"]:
            open_funcs[int(f["addr"], 16)] = f["code"]
    pend_addrs = set(); unverified = []
    try:
        fresh = json.load(open(verdicts_path()))
    except Exception:
        fresh = {}
    for f in sorted(glob.glob(os.path.join(env.ROOT, "src", "pending", "*.c"))):
        head = open(f, encoding="utf-8", errors="replace").read(6000)
        m = re.search(r"^ \* status:\s+(MATCH\*?)\s*$", head, re.M)
        if not m:
            continue
        # trust only a fresh tool verdict (written by promote_fast.py), never the header line alone
        v = fresh.get(rel(f))
        if v is None:
            unverified.append(f); continue
        if v not in ("MATCH", "MATCH*", "EXACT", "EXACT*"):
            continue
        for a in re.findall(r"^ \* address:\s+0x([0-9A-Fa-f]{8})", head, re.M):
            pend_addrs.add(int(a, 16))
        # functions the file itself defines (definitions in the body, not header symbols)
        body = open(f, encoding="utf-8", errors="replace").read().split("*/", 1)[-1]
        for a in re.findall(r"^[A-Za-z_][^\n;=]*\b(?:func|sub)_([0-9A-Fa-f]{8})\s*\([^;]*$", body, re.M):
            pend_addrs.add(int(a, 16))
    pend_bytes = sum(open_funcs[a] for a in pend_addrs if a in open_funcs)
    pend_n = sum(1 for a in pend_addrs if a in open_funcs)
    tot = s["code_bytes_game"]
    exact = s["code_bytes_matched"]
    print("exact coverage      %.4f%% (%d / %d bytes, %d functions)" % (100.0 * exact / tot, exact, tot, s["functions_matched"]))
    if unverified:
        print("WARNING: %d pending MATCH files have no fresh verdict in pending_verdicts.json and were NOT counted; run promote_fast.py" % len(unverified))
    print("reproduced coverage %.4f%% (exact + %d pending bytes in %d byte-correct MATCH functions)" % (100.0 * (exact + pend_bytes) / tot, pend_bytes, pend_n))


if __name__ == "__main__":
    main()
