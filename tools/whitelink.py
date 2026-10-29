#!/usr/bin/env python3
"""Link every region for a target from src/game and list PASS/FAIL per region.

Runs `gamelink.py N --target T` for each overlay that has a source directory (or the ids
given), then arm9_main and itcm, and writes build/<t>/link.tsv (region, PASS/FAIL, number of
differing words, the functions they sit in).  A FAIL lists each function with the count of its
differing words and the Black address of the function; build/<t>/link_words.tsv holds one row per
differing word (region, target address, Black address, function; never the bytes).  The other
autoload blocks (3 small ones) have no source: romlink writes them from the target's layout, so
they are listed as PASS (layout words).  Nothing is written to src/ or to tracked files.

    python tools/whitelink.py [--target T] [--jobs N] [--black] [--no-asm] [ids...]

T is a name of tools/targets.py (default white; --version white is the older spelling).
--black runs the same overlays for Black as the control (build/blacklink.tsv).
For the target white the summary is also written to build/whitelink.tsv, as before.
ids are overlay numbers or the names arm9_main and itcm.
"""
import argparse
import bisect
import os
import re
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402

TARGET = "white"
_FUNCS = {}


def code_overlays():
    out = []
    for d in sorted(os.listdir(os.path.join(ROOT, "src", "game"))):
        m = re.fullmatch(r"ov(\d{3})", d)
        if m:
            out.append(int(m.group(1)))
    return out


def region_name(n):
    return n if isinstance(n, str) else "ov%03d" % n


def funcs_of(region):
    """Sorted [(Black address, size, name)] of a region from layout/function_addrs.tsv."""
    if not _FUNCS:
        with open(os.path.join(ROOT, "layout", "function_addrs.tsv"), encoding="utf-8") as fh:
            next(fh)
            for line in fh:
                f = line.rstrip("\n").split("\t")
                if len(f) >= 5:
                    _FUNCS.setdefault(f[0], []).append((int(f[1], 16) & ~1, int(f[4]), f[2]))
        for v in _FUNCS.values():
            v.sort()
    return _FUNCS.get({"arm9_main": "arm9", "itcm": "itcm"}.get(region, region), [])


def black_addr(wm, region, a):
    """The Black address of the target address `a` of `region`."""
    if region == "arm9_main":
        return wm.to_black_arm9(a)
    if region == "itcm":
        return a
    return wm.to_black_ov(region, a)


def word_diffs(gl, wm, n):
    """The real code differences between the last link of region n and the target image:
    [(target address, Black address, function name, Black function address, kind)], or None.
    Both sides are aligned word by word with the relocation masks of tools/white_align.py (like
    tools/white_diff.py), so a function that has another size in the target does not turn
    every word after it into a difference.  `kind` is "changed" (same length), "grow" or
    "shrink" (the target has more or fewer words there; one row per op, at its first word)."""
    region = region_name(n)
    pub = os.path.join(gl.OUT, region + targets.suffix(TARGET))
    try:
        out = open(os.path.join(pub, "ov.bin"), "rb").read()
    except OSError:
        return None
    base, img = gl.white_overlay_info(n) if TARGET != "black" else gl.overlay_info(n)
    if len(out) != len(img):
        return None
    rows = align_rows(wm, region, out, base, img)
    # The alignment masks the words that look like addresses (pool words), so a pool word that the
    # link got wrong does not show there.  Both images have the same length: list every word that
    # differs outright and no row covers yet (kind "word").
    seen = {r[0] for r in rows}
    fl = funcs_of(region)
    starts = [f[0] for f in fl]
    for i in range(0, len(out) - 3, 4):
        if out[i:i + 4] != img[i:i + 4] and base + i not in seen:
            ta = base + i
            ba = black_addr(wm, region, ta) if TARGET != "black" else ta
            k = bisect.bisect_right(starts, ba) - 1
            nm, fa = (fl[k][2], fl[k][0]) if k >= 0 else ("-", 0)
            rows.append((ta, ba, nm, fa, "word"))
    rows.sort()
    return rows


def static_diffs(gl, wm, n):
    """When the link itself fails (a file of another size does not fit), the same list from the
    two images: Black's bytes are what src/game builds, so the differences between Black's and the
    target's image are the ones the link would show.  The first 0x800 bytes of arm9_main (the
    secure area, thunks at other places) are left out."""
    region = region_name(n)
    bbase, bimg = gl.overlay_info(n)
    tbase, timg = gl.white_overlay_info(n)
    if region == "arm9_main":
        bimg, timg = bimg[0x800:], timg[0x800:]
        bbase, tbase = bbase + 0x800, tbase + 0x800
    rows = align_rows(wm, region, bimg, bbase, timg, first_is_black=True)
    return rows


def align_rows(wm, region, out, base, img, first_is_black=False):
    import white_diff as D
    from white_align import mask_words
    fl = funcs_of(region)
    starts = [f[0] for f in fl]

    def where(i):
        ta = base + i * 4
        ba = ta if (TARGET == "black" or first_is_black) else black_addr(wm, region, ta)
        k = bisect.bisect_right(starts, ba) - 1
        return ta, ba, (fl[k][2], fl[k][0]) if k >= 0 else ("-", 0)
    rows = []
    for tag, i1, i2, j1, j2 in D.aligned_ops(mask_words(out), mask_words(img)):
        if tag == "equal":
            continue
        if i2 - i1 == j2 - j1:
            for i in range(i1, i2):
                ta, ba, (nm, fa) = where(i)
                rows.append((ta, ba, nm, fa, "changed"))
        else:
            ta, ba, (nm, fa) = where(i1)
            rows.append((ta, ba, nm, fa, ("grow %d" if j2 - j1 > i2 - i1 else "shrink %d") % abs((j2 - j1) - (i2 - i1))))
    return rows


def one(n, black):
    t0 = time.time()
    cmd = [sys.executable, "tools/gamelink.py", str(n)]
    if not black:
        cmd += ["--target", TARGET]
    g = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    text = g.stdout + g.stderr
    line = next((l for l in text.splitlines() if re.match(r"\s*%s\s" % region_name(n), l)), "")
    if " PASS" in line:
        return n, "PASS", "", []
    why = (line or (text.strip().splitlines() or ["no output"])[-1])[:300]
    if "'diffs'" in line:
        return n, "FAIL", why, True         # the words are read after the pool (one gamelink import)
    return n, "FAIL", why, False


def main():
    global TARGET
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=6)
    ap.add_argument("--black", action="store_true")
    ap.add_argument("--target", default=None)
    ap.add_argument("--version", default=None, help="older spelling of --target")
    ap.add_argument("--no-asm", action="store_true", help="overlays only (no arm9_main and itcm)")
    ap.add_argument("ids", nargs="*")
    a = ap.parse_args()
    TARGET = (a.target or a.version or "white").lower()
    if TARGET not in targets.TARGETS or TARGET == "black":
        raise SystemExit("unknown target %r (known: %s)" % (TARGET, ", ".join(t for t in targets.TARGETS if t != "black")))
    os.environ["ALETHEIA_TARGET"] = "black" if a.black else TARGET
    os.environ["ALETHEIA_VERSION"] = "black" if a.black else TARGET
    ids = [int(x) if x.isdigit() else x for x in a.ids]
    if not ids:
        ids = code_overlays() + ([] if a.no_asm else ["arm9_main", "itcm"])
    with ThreadPoolExecutor(a.jobs) as ex:
        res = list(ex.map(lambda n: one(n, a.black), ids))
    res.sort(key=lambda r: (isinstance(r[0], str), str(r[0]) if isinstance(r[0], str) else r[0]))
    import gamelink as gl
    import white_map as wm
    if not a.black:
        wm.set_target(TARGET)
    words = {}
    final = []
    for n, st, why, linked in res:
        detail = why
        if st == "FAIL":
            rows = word_diffs(gl, wm, n) if linked else (static_diffs(gl, wm, n) if not a.black else None)
            if rows is not None:
                if not linked:
                    rows = [r[:4] + ("static " + r[4],) for r in rows]
                words[n] = rows
                per = {}
                for ta, ba, nm, fa, kind in rows:
                    per.setdefault((nm, fa), []).append(kind)
                detail = ("link error (%s); static diff: " % why.split("'why': ")[-1].strip("}'\" ")[:80] if not linked else "") \
                    + "words %d; " % len(rows) + "; ".join(
                    "%s@0x%08X %s" % (nm, fa, ",".join(sorted({k.split()[0] for k in v})) + " " + str(len(v)))
                    for (nm, fa), v in sorted(per.items(), key=lambda kv: kv[0][1]))
        final.append((n, st, detail))
    bdir = os.path.join(ROOT, "build") if a.black else targets.build_dir(TARGET)
    os.makedirs(bdir, exist_ok=True)
    name = "blacklink.tsv" if a.black else "link.tsv"
    # the three small autoload blocks come from the layout words (romlink), not from source
    extra = [] if (a.black or a.ids or a.no_asm) else [("autoload%d" % i, "PASS", "layout words") for i in (1, 2, 3)]
    # with ids given, the other regions of an earlier run stay in the files
    keep, keepw = [], []
    mine = {region_name(n) for n, _s, _w in final}
    if a.ids and not a.black:
        for old_name, store, col in (("link.tsv", keep, 0), ("link_words.tsv", keepw, 0)):
            try:
                with open(os.path.join(bdir, old_name), encoding="utf-8") as fh:
                    store += [l for l in fh if l.split("\t")[0] not in mine and not l.startswith("region\t")]
            except OSError:
                pass
    with open(os.path.join(bdir, name), "w", newline="\n") as fh:
        rowsout = [l for l in keep] + ["%s\t%s\t%s\n" % (region_name(n), st, why) for n, st, why in final + extra]
        fh.writelines(sorted(rowsout, key=lambda l: (l.startswith(("arm9", "itcm", "autoload")), l.split("\t")[0])))
    if not a.black:
        with open(os.path.join(bdir, "link_words.tsv"), "w", newline="\n") as fh:
            fh.write("region\ttarget_address\tblack_address\tfunction\tfunction_address\tkind\n")
            fh.writelines(keepw)
            for n in sorted(words, key=str):
                for ta, ba, nm, fa, kind in words[n]:
                    fh.write("%s\t0x%08X\t0x%08X\t%s\t0x%08X\t%s\n" % (region_name(n), ta, ba, nm, fa, kind))
    if a.black or TARGET == "white":
        # the older summary files: the overlays only, 'diffs' words as gamelink prints them
        old = "blacklink.tsv" if a.black else "whitelink.tsv"
        with open(os.path.join(ROOT, "build", old), "w", newline="\n") as fh:
            for n, st, why in final:
                if isinstance(n, int):
                    fh.write("%s\t%s\t%s\n" % (region_name(n), st, why if st == "FAIL" else ""))
    ok = [n for n, st, _ in final if st == "PASS"]
    print("%s: %d of %d regions PASS" % ("black" if a.black else TARGET, len(ok) + len(extra), len(final) + len(extra)))
    for n, st, why in final:
        if st != "PASS":
            print("  %s FAIL %s" % (region_name(n), why[:200]))


if __name__ == "__main__":
    main()
