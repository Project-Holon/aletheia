#!/usr/bin/env python3
"""
langcheck.py -- compile source files for a target and compare each function with the target's image.

    python tools/langcheck.py --target black_ja src/game/ov186/br_res.c [more files] [-v]

For each function of a file (layout/function_addrs.tsv), the file is compiled with the target's
VERSION and LANGUAGE (tools/targets.py) and the function's bytes are compared with the target's
function, relocations masked.  The target function is found from the Black address
(white_map.to_white) and confirmed by the shape of its listing, so a function that moved inside
its overlay is still found.  This checks a function before the whole region links.

Needs the target's listings in build/<t>/asm/ (tools/disasm.py -e extract_<t> -l
build/<t>/layout -o build/<t>/asm arm9, and ... overlay --all) and the Black listings in asm/.
Output per function: ok, DIFF (bytes differing), SIZE (lengths differ).  Stdlib only.
"""
import argparse
import difflib
import json
import os
import re
import shutil
import struct
import sys
import tempfile
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)

FUNC_RE = re.compile(r"func_([0-9A-F]{8}):")


def read_lines(path):
    with open(path, encoding="latin1") as fh:
        return fh.read().replace("\r", "").split("\n")


def listing(base, region):
    """All lines of the listings of a region (arm9: every file of asm/arm9)."""
    if region == "arm9":
        d = os.path.join(base, "arm9")
        out = []
        for f in sorted(os.listdir(d)):
            if f.endswith(".s"):
                out += read_lines(os.path.join(d, f))
        return out
    return read_lines(os.path.join(base, "overlays", "%s.s" % region))


def index(lines):
    return {int(m.group(1), 16): k for k, l in enumerate(lines) for m in [FUNC_RE.match(l)] if m}


def body(lines, i):
    j = i + 1
    while j < len(lines) and not FUNC_RE.match(lines[j]):
        j += 1
    return lines[i:j]


def norm(l):
    l = re.sub(r"/\*.*?\*/", "", l).strip()
    if not l or l.startswith((".org", ".thumb_func", ".type", ".global", ".align")):
        return None
    l = re.sub(r"\.inst\.w\s+0x[0-9A-F]{8}", "bl X", l)
    l = re.sub(r"(func|loc|data|lit|off|pool)_[0-9A-F]{8}", "X", l)
    return re.sub(r"\.word\s+0x02[0-9A-F]{6}\b", ".word PTR", l)


def listing_bytes(lines):
    b = bytearray()
    for l in lines:
        m = re.search(r"/\*\s*[0-9A-F]{8}\s+((?:[0-9A-F]{2} ?)+)", l)
        if m:
            b += bytes.fromhex(m.group(1).replace(" ", ""))
            continue
        m = re.match(r"\s*\.byte\s+(.*)", l)
        if m:
            b += bytes(int(x, 16) for x in m.group(1).split(","))
            continue
        m = re.match(r"\s*\.word\s+(0x[0-9A-Fa-f]+)", l)
        if m:
            b += struct.pack("<I", int(m.group(1), 16))
            continue
        m = re.match(r"\s*\.(?:hword|short)\s+(0x[0-9A-Fa-f]+)", l)
        if m:
            b += struct.pack("<H", int(m.group(1), 16))
    return bytes(b)


def pair_file(fs, region, lb, ib, lt, it, cache):
    """Pair the functions of one file (in this region) with target functions.  Each function
    gets the candidates within 0x800 of its mapped address, scored by listing similarity minus a
    distance penalty; the file's functions keep their order in the target, so the best increasing
    chain is taken (small functions that look alike no longer pair with a neighbour's twin)."""
    import white_map
    rows = sorted((b, n) for n, b, r in fs if r == region)
    cands = []
    for baddr, name in rows:
        k0 = ib.get(baddr & ~1)
        if k0 is None or "%s:%X" % (region, baddr) in cache:
            cands.append(None)
            continue
        nb = [x for x in map(norm, body(lb, k0)) if x]
        try:
            guess = white_map.to_white(baddr, region if region != "arm9" else None) & ~1
        except KeyError:
            guess = baddr & ~1
        cl = []
        for ta, k in it.items():
            if abs(ta - guess) < 0x800:
                nt = [x for x in map(norm, body(lt, k)) if x]
                r = difflib.SequenceMatcher(None, nb, nt, autojunk=False).ratio()
                cl.append((ta, r, r - abs(ta - guess) / 4096.0))
        cl.sort()
        cands.append(cl)
    # best increasing chain: chain[i][j] = (score, previous (i, j)) ending with candidate j of function i
    chain = []
    for i, cl in enumerate(cands):
        row = []
        for ta, r, sc in (cl or []):
            best = (0.0, None)
            for i2 in range(i):
                for j2, (ta2, _r2, _s2) in enumerate(cands[i2] or []):
                    if ta2 < ta and chain[i2][j2][0] > best[0]:
                        best = (chain[i2][j2][0], (i2, j2))
            row.append((best[0] + max(sc, 0.0) + 0.001, best[1]))
        chain.append(row)
    end = None
    for i, row in enumerate(chain):
        for j, (v, _p) in enumerate(row):
            if end is None or v > chain[end[0]][end[1]][0]:
                end = (i, j)
    while end is not None:
        i, j = end
        ta, r, _s = cands[i][j]
        cache["%s:%X" % (region, rows[i][0])] = [ta, round(r, 3)]
        end = chain[i][j][1]


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[1])
    ap.add_argument("--target", required=True)
    ap.add_argument("files", nargs="+")
    ap.add_argument("-v", "--verbose", action="store_true", help="also list the functions that match")
    a = ap.parse_args()
    os.environ["ALETHEIA_TARGET"] = a.target
    os.chdir(ROOT)
    import targets
    import match
    import gamebuild
    import white_map
    white_map.set_target(a.target)
    tasm = os.path.join(targets.build_dir(a.target), "asm")
    if not os.path.isdir(tasm):
        raise SystemExit("no listings in %s (see the header of this tool)" % tasm)

    funcs = {}
    with open(os.path.join(ROOT, "layout", "function_addrs.tsv"), encoding="utf-8") as fh:
        next(fh)
        for row in fh:
            p = row.rstrip("\n").split("\t")
            if len(p) >= 6:
                funcs.setdefault(p[5], []).append((p[2], int(p[1], 16), p[0]))

    cache_p = os.path.join(targets.build_dir(a.target), "langcheck_map.json")
    try:
        cache = json.load(open(cache_p, encoding="utf-8"))
    except (OSError, ValueError):
        cache = {}
    lists = {}
    total_bad = 0
    for path in a.files:
        rel = os.path.relpath(path, ROOT).replace("\\", "/")
        fs = funcs.get(rel)
        if not fs:
            print("%s: no functions in layout/function_addrs.tsv" % rel)
            continue
        raw = open(path, encoding="latin1").read()
        _h, st = gamebuild._settings(raw)
        work = tempfile.mkdtemp(prefix="langcheck_")
        try:
            obj, _cmd, log, _rc = match.compile_tu(path, st["compiler"], st["flags"].split(),
                                                   st["isa"] == "thumb", st["lang"] or None, work)
            if obj is None:
                print("%s: compile failed: %s" % (rel, log[-1500:]))
                total_bad += 1
                continue
            tl = match.layout_tu(obj)
        finally:
            shutil.rmtree(work, ignore_errors=True)
        offs = sorted(set(tl.locals.values()))
        bad = 0
        for name, baddr, region in fs:
            if region not in lists:
                lb, lt = listing(os.path.join(ROOT, "asm"), region), listing(tasm, region)
                lists[region] = (lb, index(lb), lt, index(lt))
            lb, ib, lt, it = lists[region]
            if name not in tl.locals:
                print("  %s: not in the object" % name)
                continue
            key = "%s:%X" % (region, baddr)
            if key not in cache:
                pair_file(fs, region, lb, ib, lt, it, cache)
            if key not in cache:
                print("  %s: no target function near 0x%08X" % (name, baddr))
                continue
            ta, ratio = cache[key]
            tb = listing_bytes(body(lt, it[ta]))
            o = tl.locals[name]
            nx = [x for x in offs if x > o]
            e = nx[0] if nx else len(tl.data)
            mine, mask = bytes(tl.data[o:e]), tl.mask[o:e]
            if len(tb) > len(mine) and all((not mask[i]) or mine[i] == tb[i] for i in range(len(mine))):
                tb = tb[:len(mine)]          # the target listing runs on into a pool it did not label
            if len(tb) != len(mine):
                print("  SIZE %s 0x%08X -> 0x%08X: ours %d, target %d (match %.2f)"
                      % (name, baddr, ta, len(mine), len(tb), ratio))
                bad += 1
                continue
            d = [i for i in range(len(mine)) if mask[i] and mine[i] != tb[i]]
            if d:
                print("  DIFF %s 0x%08X -> 0x%08X: %d bytes, first +0x%X (match %.2f)"
                      % (name, baddr, ta, len(d), d[0], ratio))
                bad += 1
            elif a.verbose:
                print("  ok %s" % name)
        print("%s: %d of %d functions differ" % (rel, bad, len(fs)))
        total_bad += bad
    save_cache(cache_p, cache)
    return 1 if total_bad else 0


def save_cache(path, cache):
    """Merge into the file on disk and replace it whole: several runs share it."""
    try:
        old = json.load(open(path, encoding="utf-8"))
    except (OSError, ValueError):
        old = {}
    old.update(cache)
    tmp = "%s.%d" % (path, os.getpid())
    with open(tmp, "w", encoding="utf-8") as fh:
        json.dump(old, fh)
    for _ in range(20):
        try:
            os.replace(tmp, path)
            return
        except PermissionError:          # Windows: another run has the file open; try again
            time.sleep(0.2)
    os.remove(tmp)


if __name__ == "__main__":
    sys.exit(main())
