#!/usr/bin/env python3
"""whitetrack.py: per-function tracking for the White build of src/game.

Black has layout/matched/<region>/*.json (one record per matched function: name, address, source,
status).  White has the same code in the same files, so its records go in a separate tree,
layout/matched_white/<region>.json, one file per region.  A record holds names, addresses,
sizes and a status; no game bytes.

For every function of a Black manifest (layout/matched/, all kinds, EXACT and EXACT*):

  name, black_address   the Black record
  white_address         the same function in White (docs/restructure/white_diff.tsv rows, which
                        come from the word alignment in tools/white_map.py)
  size                  bytes of the White function (the listing extent; the next White row for a
                        function whose code differs)
  diff                  the white_diff kind: same, constant, shifted, differs (real code change);
                        mapped for a function that has no white_diff row (address from white_map)
  source                the src/game file that holds the function, found the way tools/gamecheck.py
                        finds it (func_ address names, renamed functions, unit members, header rows,
                        the file that holds an alternate entry or inner label); this is the file
                        compiled with ALETHEIA_VERSION=white
  version_switch        true when that file has a `VERSION` conditional or uses a named version
                        constant of src/game/version.h
  status                EXACT       the function's bytes in the White link of its region
                                    (build/gamelink/<region>_white, made by tools/gamelink.py
                                    --version white, which compiles the file with match.compile_tu
                                    and the White flag) equal the White image at white_address
                        IMAGE       the bytes at white_address are image data in the link (a gap
                                    between compiled files), not code from src/game
                                    (none today)
                        NO_TWIN     the function has no White row
                        STANDALONE  (kept for --standalone; no record uses it today) a function with no
                                    src/game file, checked from its src/matched file
                        UNAVAILABLE a region with no White link (none today: the DSi block is
                                    linked by tools/twllink.py --version=white against the decrypted
                                    White arm9i)
                        DIFF        the link ran but the bytes differ
                        NOT_LINKED  the region has no passing White link

A linker veneer has no source line (it is linker output).  Its record is EXACT with
kind "linker veneer" when the White image holds a veneer of the same form that jumps to the White
twin of the Black veneer's target.

The link is the proof: it compiles the same src/game files as Black with the White define and
address map, and the bytes are compared against extract_white.  Run `whitelink.py` (and
`gamelink.py arm9_main itcm --version white`) first; this tool only reads build/gamelink/*_white.

usage
    python tools/whitetrack.py              write layout/matched_white/ and print the figures
    python tools/whitetrack.py --check      exit 1 when layout/matched_white/ is out of date
    python tools/whitetrack.py --summary    print the figures only
"""
import argparse
import bisect
import glob
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)

OUT = os.path.join(ROOT, "layout", "matched_white")
TSV = os.path.join(ROOT, "docs", "restructure", "white_diff.tsv")
SRC = os.path.join(ROOT, "src", "game")
LINKS = os.path.join(ROOT, "build", "gamelink")
SECURE_END = 0x02004800
VERSION_WORDS = re.compile(r"\bVERSION\b|\bVERSION_WHITE\b|\bPM_VERSION_\w+|\bMSG_PROFANITY_NOTICE\b")


def link_dir(region):
    """(directory of the White link, gamelink id for the White target image)."""
    if region == "arm9":
        return "arm9_main_white", "arm9_main"
    if region == "arm9_autoload0_ITCM":
        return "itcm_white", "itcm"
    if region == "twl":
        return "twl_white", "twl"
    m = re.match(r"ov(\d+)d?$", region)
    if m:
        n = int(m.group(1))
        return "ov%03d_white" % n, n
    return None, None


def read_rows():
    """{region: {black address: (white address, kind)}, sorted white starts per region}."""
    rows = {}
    with open(TSV, encoding="utf-8") as fh:
        next(fh)
        for line in fh:
            f = line.rstrip("\n").split("\t")
            if len(f) < 4 or f[1] == "-":
                continue
            rows.setdefault(f[0], {})[int(f[1], 16)] = (None if f[2] == "-" else int(f[2], 16), f[3])
    return rows


def read_white_starts():
    ws = {}
    with open(TSV, encoding="utf-8") as fh:
        next(fh)
        for line in fh:
            f = line.rstrip("\n").split("\t")
            if len(f) >= 4 and f[2] != "-":
                try:
                    ws.setdefault(f[0], []).append(int(f[2], 16))
                except ValueError:
                    pass
    return {k: sorted(set(v)) for k, v in ws.items()}


def source_index():
    """{(region, function name): src/game path} and the version-switch flag per path."""
    idx, sw = {}, {}
    for path in glob.glob(os.path.join(SRC, "**", "*.c"), recursive=True):
        rel = os.path.relpath(path, ROOT).replace("\\", "/")
        raw = open(path, encoding="utf-8", errors="replace").read()
        head = raw.split("*/", 1)[0]
        m = re.search(r"^ \* region:\s*(\S+)", head, re.M)
        region = m.group(1) if m else os.path.basename(os.path.dirname(path))
        for fm in re.finditer(r"^ \* function:\s*(.*(?:\n \*   .*)*)", head, re.M):
            for n in re.split(r"[,\s]+", fm.group(1).replace("*", " ")):
                if n:
                    idx.setdefault((region, n), rel)
        body = raw
        sw[rel] = bool(VERSION_WORDS.search(body))
    return idx, sw


_HAVE = {}


def resolve_source(region, name, a):
    """The src/game file of a function the way tools/gamecheck.py finds it: by the address in a
    func_/sub_ name, by the name (renamed functions, SDK names, unit members), or by a header row
    (`name 0xADDR thumb|arm`).  Returns "" when the tree has no such definition."""
    import gamecheck as gc
    import restructure as rs
    if "idx" not in _HAVE:
        _HAVE["idx"] = rs.shard_index()
    if region not in _HAVE:
        have, _blob = gc.defined_in_tree(os.path.join(ROOT, "src", "game"), region,
                                         gc.region_names(_HAVE["idx"], region))
        _HAVE[region] = (have, {k: list(v) for k, v in gc.ROWDEF.items()})
    have, rowdef = _HAVE[region]
    for files in (have.get(a), have.get(name), rowdef.get(a)):
        if files:
            return files[0]
    return ""


def containing_source(region, name, a):
    """The src/game file that holds an alternate entry or an inner label (a name the file gives only
    in a comment or an asm label): the file with the closest header address at or below `a` that
    mentions the name."""
    import gamecheck as gc
    key = ("starts", region)
    if key not in _HAVE:
        _HAVE[key] = gc.file_starts(os.path.join(ROOT, "src", "game"), region)
    starts = _HAVE[key]
    i = bisect.bisect_right([x[0] for x in starts], a) - 1
    if i < 0:
        return ""
    path = starts[i][1]
    if name in open(path, encoding="utf-8", errors="replace").read():
        return os.path.relpath(path, ROOT).replace("\\", "/")
    return ""


VENEER_ARM = 8
VENEER_THUMB = 16


def veneer_target(data, off):
    """(size, absolute target word) of the linker veneer at `off` in `data`, or None."""
    import match
    n = match._veneer_size(data, off)
    if not n:
        return None
    return n, int.from_bytes(data[off + n - 4:off + n], "little")


def veneer_check(region, a, w, tgt, base):
    """True when the White image holds a veneer at `w` that jumps to the White twin of the Black
    veneer's target (a veneer is linker output, so its proof is the target)."""
    import match
    import white_map
    try:
        r = match.find_region(a, region)
    except SystemExit:
        return False
    b = veneer_target(r.data, a - r.base)
    c = veneer_target(tgt, w - base)
    if not b or not c or b[0] != c[0]:
        return False
    t = b[1]
    for reg in (region if region.startswith("ov") else None, None):
        try:
            if white_map.to_white(t & ~1, reg) | (t & 1) == c[1]:
                return True
        except KeyError:
            pass
    return b[1] == c[1]


def manifest_functions():
    """[(region, name, black address, record)] from every layout/matched shard, units expanded."""
    out = []
    for f in sorted(glob.glob(os.path.join(ROOT, "layout", "matched", "*", "*.json"))):
        d = json.load(open(f, encoding="utf-8"))
        for e in d["functions"]:
            if e.get("status") not in ("EXACT", "EXACT*"):
                continue
            if e.get("functions") and e.get("addresses"):
                for n, a in zip(e["functions"], e["addresses"]):
                    out.append((e["region"], n, int(a, 16) & ~1, e))
            else:
                out.append((e["region"], e["name"], int(e["address"], 16) & ~1, e))
    return out


_LINK = {}


def link_state(region):
    """(ok, base, link image, White target image, gap list) or a reason string."""
    ld, gid = link_dir(region)
    if ld is None:
        return "UNAVAILABLE"
    if ld in _LINK:
        return _LINK[ld]
    res = "NOT_LINKED"
    jp = os.path.join(LINKS, ld, "ov.json")
    bp = os.path.join(LINKS, ld, "ov.bin")
    if os.path.exists(jp) and os.path.exists(bp):
        j = json.load(open(jp, encoding="utf-8"))
        if j.get("version") == "white" and j.get("ok") and not j.get("standin"):
            import gamelink
            if gid == "twl":
                import twllink
                twllink.install()
            base, tgt = gamelink.white_overlay_info(gid)
            img = open(bp, "rb").read()
            gaps = sorted(tuple(g) for g in j.get("gaps", []))
            res = (j["base"], img, tgt, gaps, [g[0] for g in gaps])
    _LINK[ld] = res
    return res


def in_gap(state, a, n):
    """Bytes of [a, a+n) that lie in gaps of the link (image data).  `a` is a Black address: ov.json
    lists the gaps in Black coordinates for both versions (gamelink maps them back with _B)."""
    base, _img, _tgt, gaps, starts = state
    k = bisect.bisect_right(starts, a) - 1
    tot = 0
    for i in range(max(k, 0), len(gaps)):
        lo, hi = gaps[i]
        if lo >= a + n:
            break
        tot += max(0, min(hi, a + n) - max(lo, a))
    return tot


STANDALONE = os.path.join(ROOT, "build", "white", "standalone.json")


def load_standalone():
    try:
        return json.load(open(STANDALONE, encoding="utf-8"))
    except OSError:
        return {}


def standalone_check(jobs):
    """Compile the src/matched file of each IMAGE function without a src/game file (the White
    define on) and compare its bytes with White's image.  Relocation fields are wildcarded
    (the file has no link context), so a pass is STANDALONE, not EXACT.  Cached in
    build/white/standalone.json (key: region, name, Black address)."""
    import concurrent.futures
    import shutil
    import tempfile
    import match
    os.environ["ALETHEIA_VERSION"] = "white"
    import gamelink
    import white_map
    res = build()
    ents = {}
    for region, name, a, e in manifest_functions():
        ents[(region, name, "0x%08X" % a)] = e
    todo = [(r, x) for r, recs in res.items() for x in recs if x["status"] == "IMAGE" and not x["source"]]
    imgs = {}

    def target(region):
        if region not in imgs:
            _ld, gid = link_dir(region)
            imgs[region] = gamelink.white_overlay_info(gid)
        return imgs[region]

    def one(item):
        region, x = item
        e = ents[(region, x["name"], x["black_address"])]
        src = os.path.join(ROOT, e["source"])
        work = tempfile.mkdtemp(prefix="wtrack_")
        try:
            ver = e["compiler"].split("/")[-1]
            flags = [t for t in e["flags"].split() if t]
            thumb = e["isa"] == "thumb"
            base_flags = [t for t in e["flags"].replace("-thumb", "").split()]
            # the manifest flags carry the base flags and -lang; compile_tu adds both itself
            fl = [t for t in match.BASE_FLAGS]
            opt = [t for t in e["flags"].split() if t.startswith("-O")]
            obj, _cmd, _log, rc = match.compile_tu(src, ver, opt, thumb, e.get("lang"), work)
            if obj is None:
                return None
            fb = match.extract_function(obj, x["name"], prefer_thumb=thumb)
            base, tgt = target(region)
            off = int(x["white_address"], 16) - base
            n = len(fb.data)
            seg = tgt[off:off + n]
            if len(seg) != n:
                return None
            if all(fb.data[i] == seg[i] for i in range(n) if fb.mask[i]) and n == x["size"]:
                return "STANDALONE"
            return None
        except (SystemExit, Exception):
            return None
        finally:
            shutil.rmtree(work, ignore_errors=True)

    out = load_standalone()
    with concurrent.futures.ThreadPoolExecutor(jobs) as ex:
        for (region, x), st in zip(todo, ex.map(one, todo)):
            out["%s %s %s" % (region, x["name"], x["black_address"])] = st or ""
    os.makedirs(os.path.dirname(STANDALONE), exist_ok=True)
    with open(STANDALONE, "w", encoding="utf-8", newline="\n") as fh:
        json.dump(out, fh, indent=0, sort_keys=True)
    print("standalone: %d checked, %d match" % (len(todo), sum(1 for v in out.values() if v)))


def build():
    import match
    import white_map
    rows = read_rows()
    wstarts = read_white_starts()
    sidx, sw = source_index()
    per = {}
    ents = {}
    for region, name, a, e in manifest_functions():
        per.setdefault(region, []).append((name, a))
        ents[(region, name, a)] = e
    standalone = load_standalone()
    result = {}
    for region, fl in sorted(per.items()):
        rr = rows.get(region, {})
        ws = wstarts.get(region, [])
        try:
            starts = sorted(match.scan_listing(region))
        except SystemExit:
            starts = []
        state = link_state(region)
        recs, seen = [], set()
        for name, a in sorted(fl, key=lambda x: (x[1], x[0])):
            if (name, a) in seen:
                continue
            seen.add((name, a))
            r = rr.get(a)
            if region == "twl":
                # the DSi block loads at the same address in both games (arm9i header); the
                # White link and image decide the status, the diff kind says whether bytes moved
                r = (a, "same")
            if (r is None or r[0] is None) and state != "UNAVAILABLE":
                # a function the white_diff listing has no row (or no White address) for:
                # the word alignment
                try:
                    r = (white_map.to_white(a, region if region.startswith("ov") else None),
                         r[1] if r else "mapped")
                except KeyError:
                    r = None
            src = sidx.get((region, name)) or resolve_source(region, name, a)
            if not src:
                src = containing_source(region, name, a)
            rec = dict(name=name, black_address="0x%08X" % a)
            if r is None or r[0] is None:
                rec.update(status="NO_TWIN" if state != "UNAVAILABLE" else "UNAVAILABLE", diff=r[1] if r else "")
                rec.update(source=src or "")
                recs.append(rec)
                continue
            w, kind = r
            k = bisect.bisect_right(starts, a)
            bsize = (starts[k] - a) if k < len(starts) else 4
            if kind in ("differs", "new"):
                j = bisect.bisect_right(ws, w)
                size = (ws[j] - w) if j < len(ws) else bsize
            else:
                size = bsize
            if region == "arm9" and a < SECURE_END and name.startswith("SVC_"):
                size = 4        # a thunk (`swi N; bx lr`) in the secure area; the filler around it is image
            rec.update(white_address="0x%08X" % w, size=size, diff=kind, source=src or "",
                       version_switch=bool(src and sw.get(src)))
            if isinstance(state, str):
                rec["status"] = state
            else:
                base, img, tgt, gaps, _g = state
                if region == "twl":
                    rb = match.find_region(a, region)
                    same = rb.data[a - rb.base:a - rb.base + size] == tgt[a - base:a - base + size]
                    rec["diff"] = "same" if same else "constant"
                off = w - base
                if off < 0 or off + size > len(img) or off + size > len(tgt):
                    rec["status"] = "NO_TWIN"
                elif not src and veneer_check(region, a, w, tgt, base):
                    # linker output: the link makes (or keeps) it, no source line exists
                    rec["status"] = "EXACT" if img[off:off + size] == tgt[off:off + size] else "DIFF"
                    rec["kind"] = "linker veneer"
                elif not src or (a >= SECURE_END and in_gap(state, a, bsize) >= bsize):
                    rec["status"] = "IMAGE"
                elif img[off:off + size] == tgt[off:off + size]:
                    rec["status"] = "EXACT"
                else:
                    rec["status"] = "DIFF"
            if rec["status"] == "IMAGE":
                st = standalone.get("%s %s %s" % (region, name, rec["black_address"]))
                if st:
                    rec["status"] = st
                    e = ents[(region, name, a)]
                    rec["source"] = rec["source"] or e.get("source", "")
            recs.append(rec)
        result[region] = recs
    return result


def render(recs):
    lines = ['{', ' "tool": "tools/whitetrack.py",', ' "version": 1,',
             ' "note": "White per-function tracking: addresses, names, sizes and status only, no game bytes",',
             ' "functions": [']
    lines.append(",\n".join("  " + json.dumps(r, separators=(", ", ": ")) for r in recs))
    lines += [' ]', '}']
    return "\n".join(lines) + "\n"


def figures(result):
    tot = {}
    for region, recs in result.items():
        for r in recs:
            t = tot.setdefault(r["status"], [0, 0])
            t[0] += 1
            t[1] += r.get("size", 0)
    return tot


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--summary", action="store_true")
    ap.add_argument("--standalone", type=int, metavar="JOBS",
                    help="compile the src/matched file of each function that has no src/game file and compare")
    a = ap.parse_args(argv)
    if a.standalone:
        standalone_check(a.standalone)
    result = build()
    f = figures(result)
    n = sum(v[0] for v in f.values())
    for k, v in sorted(f.items()):
        print("%-12s %6d functions  %8d bytes" % (k, v[0], v[1]))
    print("%-12s %6d" % ("total", n))
    diffs = [(r_, x) for r_, recs in result.items() for x in recs if x["status"] in ("DIFF", "NOT_LINKED", "NO_TWIN")]
    for r_, x in diffs[:40]:
        print("  not exact:", r_, x["name"], x["black_address"], x["status"])
    if a.summary:
        return 0
    texts = {os.path.join(OUT, "%s.json" % r): render(v) for r, v in result.items()}
    if a.check:
        bad = 0
        for p, t in texts.items():
            if not os.path.exists(p) or open(p, encoding="utf-8").read() != t:
                bad += 1
        if bad:
            print("%d files out of date" % bad, file=sys.stderr)
        return 1 if bad else 0
    os.makedirs(OUT, exist_ok=True)
    for p, t in texts.items():
        with open(p, "w", encoding="utf-8", newline="\n") as fh:
            fh.write(t)
    print("wrote %d files to layout/matched_white" % len(texts))
    return 0


if __name__ == "__main__":
    sys.exit(main())
