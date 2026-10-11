#!/usr/bin/env python3
"""gamebuild.py -- take the code of a region from src/game instead of src/matched.

build.py --game calls this module.  For every file of src/game/<dir>/ (top level
only: folders hold member copies and `unplaced` holds stand-ins) that lies in a
region being built, the file is

    compiled once as a translation unit (match.run_tu: mwccarm at the flags of
    its header: compiler, flags, lang, isa)
      -> laid out end to end (match.layout_tu with the original image, see below)
      -> every relocation resolved at the file's address (match.run_tu does this)
      -> required to be EXACT: every byte hard (resolved by the resolver) and
         equal.  A MATCH file keeps wildcarded relocation fields that the
         resolver could not attest.  Those bytes would have to come from the
         image, and the image is not an input of this build, so a MATCH file is
         refused with the number of unresolved sites; it is counted, not spliced.
      -> emitted as a csrc.Splice (region, address, bytes)

build.py then overwrites that range of the region image it assembled from asm/,
exactly as it does for src/matched splices.  The data sections (.data, .rodata,
.bss) and every code range that no src/game file covers still come from asm/.

Linker veneers: layout_tu(image=...) copies the veneers that sit between two code
sections of a file out of the original image (match.linker_gap).  This is
acceptable for this milestone and is the one place where the image is still
read as a code source.  The count is kept per file and totalled in the summary
(see "veneers from image").  A real mwldarm link would make them instead.

Like csrc, this never falls back to asm/ for a file that fails: a failing file
is reported with its verdict and the region FAILs.

usage (normally through build.py)
    python tools/build.py --game --only ov011 ov012
    python tools/gamebuild.py ov011 ov012       # compile and report only
"""

from __future__ import annotations

import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
if os.path.join(ROOT, "tools") not in sys.path:
    sys.path.insert(0, os.path.join(ROOT, "tools"))

import csrc          # noqa: E402
import match         # noqa: E402
import protofix as pf  # noqa: E402

TREE = os.path.join(ROOT, "src", "game")


class GameStats:
    """Counters for one run, printed by build.py."""

    def __init__(self):
        self.files = 0          # src/game files in the chosen regions
        self.spliced = 0
        self.bytes = 0
        self.refused = []       # (file, why): MATCH or not EXACT
        self.veneer_count = 0
        self.veneer_bytes = 0
        self.skipped = []       # (file, why): no address, outside the regions


def region_dir(spec):
    """The src/game folder that holds the files of a build region."""
    if spec.key.startswith("ov"):
        return spec.key
    if spec.key == "arm9_main":
        return "arm9"
    if spec.key == "itcm":
        return "arm9_autoload0_ITCM"
    return spec.name.replace("arm9_", "arm9_", 1)


def _settings(raw):
    h = pf.parse_header(raw)
    cc = (h.get("compiler") or "1.1p1").strip()
    cc = cc[4:] if cc.startswith("dsi/") else cc
    import re
    fl = re.sub(r"-proc\s+arm946e", "", h.get("flags") or "").strip() or "-O4,p"
    return h, {"compiler": cc, "flags": fl, "lang": (h.get("lang") or "").strip(),
               "isa": ((h.get("isa") or "thumb").split() or ["thumb"])[0]}


def game_files(spec, tree=TREE):
    base = os.path.join(tree, region_dir(spec))
    if not os.path.isdir(base):
        return []
    return sorted(os.path.join(base, f) for f in os.listdir(base)
                  if f.endswith(".c") and not f.startswith("_")
                  and os.path.isfile(os.path.join(base, f)))


def compile_game_file(path, spec, stats_lock=None):
    """Compile one src/game file.  Returns (Splice or None, why, nveneers, vbytes)."""
    rel = os.path.relpath(path, ROOT).replace(os.sep, "/")
    try:
        raw = open(path, encoding="latin1").read()
    except OSError as e:
        return None, "unreadable: %s" % e, 0, 0
    if raw.startswith("\xef\xbb\xbf"):
        raw = raw[3:]
    h, st = _settings(raw)
    try:
        addr = int(h.get("address", "0"), 16)
    except ValueError:
        addr = 0
    if not addr:
        return None, "no address in header", 0, 0
    if not spec.contains(addr):
        return None, "address %08X outside region" % addr, 0, 0
    region = (h.get("region") or region_dir(spec)).strip()
    flags = st["flags"].split() if st["flags"] else ["-O4,p"]
    thumb = st["isa"] == "thumb"
    try:
        r, tl = match.run_tu(path, addr, st["compiler"], flags, thumb,
                             st["lang"] or None, region=region)
    except (Exception, SystemExit) as e:
        return None, "ERROR %r" % (e,), 0, 0
    if r.status == "CCERR":
        return None, "compiler rejected the file: %s" % (r.note or "")[:120], 0, 0
    fb = r.func
    if r.status.startswith("MATCH"):
        wild = sum(1 for b in fb.mask if b == 0)
        unres = sum(1 for s in fb.sites if not s.resolved)
        return None, ("MATCH: %d unresolved relocation site(s), %d wildcard byte(s); "
                      "the resolver cannot fill them and the image is not a source"
                      % (unres, wild)), 0, 0
    if not r.status.startswith("EXACT"):
        return None, "%s (%d byte(s) differ)" % (r.status, len(r.diffs or [])), 0, 0
    if any(b == 0 for b in fb.mask):
        return None, "EXACT but wildcards remain", 0, 0
    nres = sum(1 for s in fb.sites if s.resolved)
    sp = csrc.Splice(os.path.basename(path)[:-2], addr, bytes(fb.data), rel,
                     "game_tu", region, len(fb.relocs), nres)
    vn = len(tl.veneers)
    vb = sum(n for _o, n in tl.veneers)
    return sp, "", vn, vb


def attach_game_sources(specs, jobs=1, tree=TREE, progress=None, skip=()):
    """Compile every src/game file of the chosen regions and hang the splices on
    their RegionSpec.  Returns GameStats.  Raises csrc.CSourceError if any file
    that is in a region fails (the caller turns that into a build failure)."""
    stats = GameStats()
    work = []
    for s in specs:
        for p in game_files(s, tree):
            name = os.path.basename(p)
            if any(name == k + ".c" or name.startswith(k + "_p") for k in skip):
                continue
            work.append((s, p))
    stats.files = len(work)
    if work:
        match.load_all_regions()
        match.evidence()
        match.sdk_symbols()
        match.matched_symbols()

    def one(item):
        s, p = item
        return item, compile_game_file(p, s)

    if jobs > 1 and len(work) > 1:
        from concurrent.futures import ThreadPoolExecutor
        with ThreadPoolExecutor(max_workers=jobs) as pool:
            results = list(pool.map(one, work))
    else:
        results = [one(w) for w in work]

    for (s, p), (sp, why, vn, vb) in results:
        rel = os.path.relpath(p, ROOT).replace(os.sep, "/")
        if sp is None:
            stats.refused.append((rel, why))
            continue
        s.splices.append(sp)
        stats.spliced += 1
        stats.bytes += sp.size
        stats.veneer_count += vn
        stats.veneer_bytes += vb
        if progress:
            progress(sp)
    for s in specs:
        s.splices.sort(key=lambda sp: sp.address)
        for a, b in zip(s.splices, s.splices[1:]):
            if b.address < a.end:
                raise csrc.CSourceError(
                    "%s and %s overlap in region %s (0x%08X..0x%08X)"
                    % (a.source, b.source, s.key, b.address, a.end))
    return stats


def main(argv=None):
    """Compile and report only (no assembler needed)."""
    import argparse
    import build
    ap = argparse.ArgumentParser(prog="gamebuild.py")
    ap.add_argument("regions", nargs="+")
    ap.add_argument("-j", "--jobs", type=int, default=4)
    a = ap.parse_args(argv)
    import json
    with open(os.path.join(ROOT, "layout", "layout.json"), encoding="utf-8") as fh:
        layout = json.load(fh)
    specs = [s for s in build.region_specs(layout, os.path.join(ROOT, "extract"),
                                           os.path.join(ROOT, "asm"),
                                           os.path.join(ROOT, "layout"))
             if s.key in a.regions]
    st = attach_game_sources(specs, a.jobs)
    for s in specs:
        print("%-12s %d file(s) spliced, %d bytes" % (s.key, len(s.splices),
                                                       sum(x.size for x in s.splices)))
    for f, why in st.refused:
        print("  refused %s: %s" % (f, why))
    print("veneers from image: %d (%d bytes)" % (st.veneer_count, st.veneer_bytes))
    return 0


if __name__ == "__main__":
    sys.exit(main())
