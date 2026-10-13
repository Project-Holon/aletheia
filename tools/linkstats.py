#!/usr/bin/env python3
"""linkstats.py -- "fully linked" progress: code in complete units that mwldarm links.

The figure is the decomp.dev / objdiff "complete" figure: the share of code bytes
that sit in translation units that are finished AND whose compiled object is what
the real linker puts into the region, as opposed to bytes spliced into an image
that is assembled from the asm/ listings.

Regions (one row each)
  every overlay with a listing asm/overlays/ovNNN.s (src/game/ovNNN/, link id N);
  arm9      asm/arm9/main.s,  src/game/arm9/,                link id arm9_main;
  itcm      asm/arm9/itcm.s,  src/game/arm9_autoload0_ITCM/, link id itcm;
  twl       asm/twl/twl.s,    src/game/twl/,                 link id twl (gamelink.py
            through the region hook of tools/twllink.py);
  the autoload blocks arm9_autoload1/2 (MAIN_TWL) and 3 (VRAM_LCDC): code, no
  src/game folder.
  ov230d (the decrypted view of ov230) is left out, as tools/ovstats.py does.

Denominator (rule D), the measure of tools/ovstats.py, applied to every region:
  D1  a function is a func_/sub_ label of the region's listing; its size is the
      sum of the decoded instruction bytes credited to it (pool words and data
      runs count nowhere);
  D2  linker veneers are excluded: the Thumb and ARM veneer forms and the ov230
      decryptor entries that ovstats.veneer_labels() recognises, and every
      `veneer_XXXXXXXX` label disasm.py marks (arm9, twl); a veneer label is a
      boundary, so its bytes are not credited to the function before it;
  D3  SDK or game: a function whose start is in tools/sdkclass.py's union for the
      region is SDK, every other function is game.  Totals are given for game,
      SDK and both.
  The arm9 denominator therefore differs from layout/worklist.json (which counts
  per unit with a runtime class); the overlay rows equal ovstats' insn_bytes less
  its veneers (ovstats adds register-mismatch functions the listing does not
  label; those are not counted here).

Units (rule U).  A unit is one top-level `.c` file of the region's src/game folder
(files starting with `_`, the `unplaced` folder and member folders are not units).
Its code range is [header address, header address + its linked .text size)
(from the gamelink.py link, or from match.run_tu when the region did not link).
A function belongs to the unit whose range holds its start address.  Code no
unit covers (docs/restructure/gamegaps.tsv) is in no unit.

Complete (rule C).  A unit is complete when all of these hold:
  C1  it is one whole source file: not a `<tu>_pNN.c` part, and no `<tu>/`
      folder holds .c member files of it (the split rule of tools/tucount.py,
      docs/restructure/split_tus.tsv);
  C2  its bytes are the original: the gamelink.py link of the region compared
      its range byte-identical (the file is not in the link's `diffs`), or, when
      the region did not link, match.run_tu gives EXACT with no wildcard byte;
  C3  no asm stand-in: every `asm` function definition in the file (an `asm`
      function, or a body that is one asm block; tools/placeholders.py
      definitions()) is allowed only when
        H1  the comment block right above it says "hand-written in the original"
            (the ASM2C brief's marker), or
        H2  it is SDK code: its address (from a func_XXXXXXXX name, the file's
            `symbols:` header, or the file's compiled layout, tools/fnaddr.py) is
            SDK by rule D3, or its name is a symbol of
            layout/symbols_sdk.txt.  NitroSDK, NitroSystem and DWC write such
            routines as `asm` functions inside .c files (MI_CpuCopy32,
            OS_SaveContext, DC_StoreRange), so asm there is the original form;
      and no asm body is a placeholder (tools/placeholders.py P1-P3).  The
      strict variant (H1 only) is reported as well.

Linked (rule L).  A complete unit is linked when gamelink.py linked its region
with mwldarm and the whole region came out byte-identical to the original
(gamelink result ok) in a link of EVERY top-level file of the region.  When that
link fails to produce a per-file verdict, the region is linked again with the
split parts (rule C1) left to the image; that second link only feeds the
secondary figures `linked_skip` (complete units in a region whose second link is
byte-identical) and `unit_ok`, and the per-file verdicts of rule C2.  When no link
gives per-file verdicts, C2 comes from match.run_tu.  Bytes between units (data, code no unit covers)
are still taken from the image in every gamelink.py link (see
docs/restructure/BUILD_FROM_GAME.md); that is the same for every region and is
what "spliced" does not mean here: a linked unit's code is the linker's output
from its own object.  The arm9 static image is built by splicing
(tools/gamebuild.py) and counts as linked only if the gamelink.py arm9_main link
is byte-identical.  A secondary column, `unit_ok`, counts complete units whose
own range came out identical even when the region as a whole did not.

Cache.  Link results are kept in build/linkstats/cache.json (gitignored), keyed
by region, with a stamp over the region's src/game files, every .h file under
src/ and include/, and tools/gamelink.py, tools/gamebuild.py, tools/twllink.py.  --relink ignores
the cache.  Work files go to build/linkstats/work/ (not build/gamelink/).

Output.  A table (one row per region with any code), totals for game, SDK and
both, and with --json PATH the same figures as JSON (rows, units, totals) for
tools/coveragemap.py and README use.  --objdiff PATH writes a report in the
shape of objdiff-core's report.proto (Report / Measures / ReportUnit) as JSON:
fuzzy_match_percent, matched_code (functions with an EXACT shard entry or in a
unit compiled EXACT), complete_code (linked units), and the rest.

usage
    python tools/linkstats.py [--jobs N] [--relink] [--json OUT] [--objdiff OUT]
                              [--only REGION ...] [--units]
"""

from __future__ import annotations

import argparse
import concurrent.futures as cf
import hashlib
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOLS = os.path.join(ROOT, "tools")
if TOOLS not in sys.path:
    sys.path.insert(0, TOOLS)

GAME = os.path.join(ROOT, "src", "game")
CACHE = os.path.join(ROOT, "build", "linkstats", "cache.json")
WORK = os.path.join(ROOT, "build", "linkstats", "work")
PART = re.compile(r"^(.+)_p\d+\.c$")
FUNCNAME = re.compile(r"^(?:func|sub)_[0-9A-Fa-f]{6,8}$")
VENEER_LABEL = re.compile(r"^veneer_([0-9A-Fa-f]{8})$")
ADDR_NAME = re.compile(r"(?:func|sub)_([0-9A-Fa-f]{8})$")
MARKER = "hand-written in the original"


# ------------------------------------------------------------------ regions

def regions():
    """[(name, listing, src dir or None, link id or None)]."""
    out = []
    ovd = os.path.join(ROOT, "asm", "overlays")
    for f in sorted(os.listdir(ovd)):
        m = re.match(r"^ov(\d+)\.s$", f)
        if m:
            name = "ov%03d" % int(m.group(1))
            out.append((name, os.path.join(ovd, f), name, int(m.group(1))))
    out.append(("arm9", os.path.join(ROOT, "asm", "arm9", "main.s"), "arm9", "arm9_main"))
    out.append(("arm9_autoload0_ITCM", os.path.join(ROOT, "asm", "arm9", "itcm.s"),
                "arm9_autoload0_ITCM", "itcm"))
    out.append(("twl", os.path.join(ROOT, "asm", "twl", "twl.s"), "twl", "twl"))
    for n, f in (("arm9_autoload1_MAIN_TWL", "autoload1_main_twl.s"),
                 ("arm9_autoload2_MAIN_TWL", "autoload2_main_twl.s"),
                 ("arm9_autoload3_VRAM_LCDC", "vram_lcdc.s")):
        out.append((n, os.path.join(ROOT, "asm", "arm9", f), None, None))
    return [r for r in out if os.path.exists(r[1])]


# ------------------------------------------------------------------ denominator (rule D)

def listing_functions(region, path):
    """[(addr, code bytes, is_sdk)] for every non-veneer function of a listing."""
    import ovstats
    old = ovstats.FUNCNAME
    # veneer_ labels are boundaries too (rule D2): scan with them as function labels
    ovstats.FUNCNAME = re.compile(r"^(?:(?:func|sub)_[0-9A-Fa-f]{6,8}|veneer_[0-9A-Fa-f]{8})$")
    try:
        _head, labels, insns = ovstats.scan_listing(path)
    finally:
        ovstats.FUNCNAME = old
    addrs = [a for a, _ in labels]
    code = ovstats.code_bytes_from(insns, addrs)
    ven = set(ovstats.veneer_labels(path))
    ven |= {a for a, n in labels if VENEER_LABEL.match(n)}
    sdk = ovstats.sdk_addrs(region)
    ven -= {a for a in ven if a in sdk and not any(a == x and VENEER_LABEL.match(n) for x, n in labels)}
    out, seen = [], set()
    for a, _n in labels:
        if a in seen or a in ven:
            continue
        seen.add(a)
        if code[a] > 0:
            out.append((a, code[a], a in sdk))
    return out


# ------------------------------------------------------------------ units (rules U, C1, C3)

def unit_files(srcdir):
    """{stem: dict(path, split)} for the top-level .c files of a src/game folder."""
    d = os.path.join(GAME, srcdir)
    if not os.path.isdir(d):
        return {}
    files = {}
    parts, members = set(), set()
    for f in os.listdir(d):
        p = os.path.join(d, f)
        if f.endswith(".c") and not f.startswith("_") and os.path.isfile(p):
            files[f[:-2]] = p
            m = PART.match(f)
            if m:
                parts.add(m.group(1))
        elif os.path.isdir(p) and any(g.endswith(".c") for g in os.listdir(p)):
            members.add(f)
    out = {}
    for stem, p in files.items():
        m = PART.match(stem + ".c")
        split = bool(m) or stem in members
        out[stem] = dict(path=p, split=split, tu=m.group(1) if m else stem)
    return out


_SDKNAMES = None


def sdk_names():
    global _SDKNAMES
    if _SDKNAMES is None:
        _SDKNAMES = set()
        try:
            for line in open(os.path.join(ROOT, "layout", "symbols_sdk.txt"), encoding="utf-8"):
                if line.startswith("#"):
                    continue
                w = line.split()
                if len(w) >= 2:
                    _SDKNAMES.add(w[1])
        except OSError:
            pass
    return _SDKNAMES


def marker_above(text, name):
    """True when the comment block right above the definition of `name` holds MARKER."""
    m = None
    for c in re.finditer(r"^[^\n;{}]*\b" + re.escape(name) + r"\s*\(", text, re.M):
        ends = [k for k in (text.find(";", c.end()), text.find("{", c.end())) if k >= 0]
        if ends and text[min(ends)] == "{":
            m = c          # the definition, not a prototype
            break
    if not m:
        return False
    lines = text[:m.start()].split("\n")[:-1]
    block = []
    in_comment = False
    for line in reversed(lines):
        s = line.strip()
        if not s and not in_comment:
            if block:
                break
            continue
        if s.endswith("*/") or in_comment or s.startswith(("/*", "*", "//")):
            block.append(s)
            if s.startswith("/*") or s.startswith("//"):
                in_comment = False
            elif s.endswith("*/") and not s.startswith("/*"):
                in_comment = True
            continue
        break
    return any(MARKER in s for s in block)


def asm_report(path, region, sdk):
    """(stand-ins, sdk asm, marked asm, placeholders) as name lists for one file (rule C3)."""
    import placeholders
    import gamebuild
    text = open(path, encoding="latin1").read()
    try:
        h, _st = gamebuild._settings(text)
        hsyms = {n: a for n, (a, _k, _r) in h.get("symbols", {}).items()}
    except Exception:
        hsyms = {}
    stand, sdkasm, marked, ph = [], [], [], []
    lay = []
    for name, is_asm, body, inc in placeholders.definitions(text):
        if not is_asm:
            continue
        if not inc and placeholders.classify_asm(body):
            ph.append(name)
            continue
        if marker_above(text, name):
            marked.append(name)
            continue
        am = ADDR_NAME.search(name)
        a = int(am.group(1), 16) if am else hsyms.get(name)
        if a is None and name not in sdk_names():
            # any other name: its address in the file's compiled layout (tools/fnaddr.py)
            if not lay:
                import fnaddr
                lay.append(fnaddr.layouts([path], {path: region}).get(path) or {})
            a = lay[0].get(name)
        if (a is not None and a in sdk) or name in sdk_names():
            sdkasm.append(name)
        else:
            stand.append(name)
    return stand, sdkasm, marked, ph


# ------------------------------------------------------------------ link (rules C2, L)

def _stamp(srcdir):
    h = hashlib.sha1()
    paths = []
    if srcdir:
        for dp, _dn, fn in os.walk(os.path.join(GAME, srcdir)):
            paths += [os.path.join(dp, f) for f in fn]
    for p in sorted(set(paths)):
        try:
            st = os.stat(p)
        except OSError:
            continue
        h.update(("%s|%d|%d\n" % (os.path.relpath(p, ROOT), st.st_size, st.st_mtime_ns)).encode())
    h.update(_header_stamp().encode())
    return h.hexdigest()


_HDR = []


def _header_stamp():
    """One digest over every .h under src/ (src/matched skipped) and include/, and
    tools/gamelink.py, tools/gamebuild.py; computed once per run."""
    if not _HDR:
        h = hashlib.sha1()
        paths = [os.path.join(TOOLS, "gamelink.py"), os.path.join(TOOLS, "gamebuild.py"),
                 os.path.join(TOOLS, "twllink.py")]
        for top in (os.path.join(ROOT, "src"), os.path.join(ROOT, "include")):
            for dp, dn, fn in os.walk(top):
                if dp == os.path.join(ROOT, "src"):
                    dn[:] = [d for d in dn if d != "matched"]
                paths += [os.path.join(dp, f) for f in fn if f.endswith(".h")]
        for p in sorted(paths):
            try:
                st = os.stat(p)
            except OSError:
                continue
            h.update(("%s|%d|%d\n" % (os.path.relpath(p, ROOT), st.st_size, st.st_mtime_ns)).encode())
        _HDR.append(h.hexdigest())
    return _HDR[0]


def _slim(r):
    return dict(ok=bool(r.get("ok")), why=r.get("why"),
                diffs=[d[0] for d in r.get("diffs") or []],
                units=r.get("units"), files=r.get("files"), gap_bytes=r.get("gap_bytes"),
                bss_standin_bytes=r.get("bss_standin_bytes"))


def _run_tu_units(srcdir, region):
    """Fallback when a region does not link: compile each file with match.run_tu."""
    import match
    import gamebuild
    units, notes = [], {}
    for stem, u in sorted(unit_files(srcdir).items()):
        raw = open(u["path"], encoding="latin1").read()
        if raw.startswith("\xef\xbb\xbf"):
            raw = raw[3:]
        h, st = gamebuild._settings(raw)
        try:
            addr = int(h.get("address", "0"), 16)
        except ValueError:
            addr = 0
        if not addr:
            notes[stem] = "no address"
            continue
        flags = st["flags"].split() if st["flags"] else ["-O4,p"]
        try:
            r, _tl = match.run_tu(u["path"], addr, st["compiler"], flags, st["isa"] == "thumb",
                                  st["lang"] or None, region=(h.get("region") or region).strip())
        except (Exception, SystemExit) as e:
            notes[stem] = "ERROR %r" % (e,)
            continue
        fb = r.func
        size = len(fb.data) if fb is not None and fb.data is not None else 0
        exact = r.status.startswith("EXACT") and fb is not None and not any(b == 0 for b in fb.mask)
        units.append(dict(stem=stem, addr=addr, end=addr + size, exact=exact, status=r.status))
    return units, notes


def link_region(job):
    """Worker: (region, srcdir, link id) -> result dict (runs in its own process)."""
    region, srcdir, lid = job
    import gamelink
    import twllink
    twllink.install()          # adds the region "twl" to gamelink.link_overlay
    gamelink.OUT = WORK
    out = dict(region=region, attempts=[])
    if lid is not None:
        try:
            r = gamelink.link_overlay(lid, verbose=False)
        except (Exception, SystemExit) as e:
            r = dict(ok=False, why="exception %r" % (e,))
        out["attempts"].append(dict(skip=[], **_slim(r)))
        if r.get("units") is None:
            skip = sorted({u["tu"] + "_p" if PART.match(s + ".c") else s + "."
                           for s, u in unit_files(srcdir).items() if u["split"]})
            if skip:
                try:
                    r = gamelink.link_overlay(lid, verbose=False, skip=tuple(skip))
                except (Exception, SystemExit) as e:
                    r = dict(ok=False, why="exception %r" % (e,))
                out["attempts"].append(dict(skip=skip, **_slim(r)))
    final = out["attempts"][-1] if out["attempts"] else None
    out["link"] = final
    if final is None or final.get("units") is None:
        out["tu_units"], out["tu_notes"] = _run_tu_units(srcdir, region)
    return out


# ------------------------------------------------------------------ figures

def compute(rows_in, results):
    import ovstats
    rows, unitrows = [], []
    for region, listing, srcdir, lid in rows_in:
        funcs = listing_functions(region, listing)
        sdk = ovstats.sdk_addrs(region)
        res = results.get(region) or {}
        link = res.get("link")
        att = res.get("attempts") or []
        # rule L: the link of every file of the region; rule L-skip: the last attempt
        linked_region = bool(att and att[0].get("ok"))
        linked_skip_region = bool(link and link.get("ok"))
        files = unit_files(srcdir) if srcdir else {}
        ranges = {}
        if link and link.get("units") is not None:
            diffs = set(link.get("diffs") or [])
            for u in link["units"]:
                # a file whose code is not contiguous in the original links as pieces
                pcs = [tuple(x) for x in u.get("pieces") or [(u["addr"], u["end"])]]
                ranges[u["stem"]] = (u["addr"], u["end"], u["stem"] not in diffs, "link", pcs)
        for u in res.get("tu_units") or []:
            ranges[u["stem"]] = (u["addr"], u["end"], u["exact"], u["status"], [(u["addr"], u["end"])])
        starts = sorted((a, e, s) for s, r in ranges.items() for a, e in r[4])
        import bisect
        keys = [a for a, _e, _s in starts]
        per = {s: [0, 0, 0] for s in ranges}       # game, sdk, functions
        tot = dict(game=0, sdk=0)
        for a, n, is_sdk in funcs:
            tot["sdk" if is_sdk else "game"] += n
            i = bisect.bisect_right(keys, a) - 1
            if i >= 0 and a < starts[i][1]:
                s = starts[i][2]
                per[s][1 if is_sdk else 0] += n
                per[s][2] += 1
        row = dict(region=region, linked_region=linked_region, linked_skip_region=linked_skip_region,
                   link_tried=lid is not None, link_why_all=(att[0].get("why") if att else None),
                   link_why=(link or {}).get("why"), skip=(link or {}).get("skip") or [],
                   bss_standin_bytes=(link or {}).get("bss_standin_bytes") or 0,
                   units=0, units_complete=0, units_complete_strict=0, units_linked=0,
                   total_game=tot["game"], total_sdk=tot["sdk"])
        for k in ("covered", "complete", "complete_strict", "linked", "linked_strict", "linked_skip", "unit_ok"):
            row[k + "_game"] = 0
            row[k + "_sdk"] = 0
        for stem, u in sorted(files.items()):
            g, s, nf = per.get(stem, [0, 0, 0])
            a, e, ok, how, pcs = ranges.get(stem, (None, None, False, "not built", []))
            stand, sdkasm, marked, ph = asm_report(u["path"], region, sdk)
            complete = (not u["split"]) and ok and not stand and not ph
            strict = complete and not sdkasm
            linked = complete and linked_region
            row["units"] += 1
            row["covered_game"] += g
            row["covered_sdk"] += s
            for k, flag in (("complete", complete), ("complete_strict", strict), ("linked", linked),
                            ("linked_strict", strict and linked_region),
                            ("linked_skip", complete and linked_skip_region),
                            ("unit_ok", complete and how == "link")):
                if flag:
                    row[k + "_game"] += g
                    row[k + "_sdk"] += s
            row["units_complete"] += complete
            row["units_complete_strict"] += strict
            row["units_linked"] += linked
            unitrows.append(dict(region=region, stem=stem, path=os.path.relpath(u["path"], ROOT).replace(os.sep, "/"),
                                 addr="0x%08X" % a if a is not None else None,
                                 end="0x%08X" % e if e is not None else None,
                                 pieces=[["0x%08X" % x, "0x%08X" % y] for x, y in pcs],
                                 game=g, sdk=s, functions=nf, split=u["split"], bytes_ok=bool(ok),
                                 verdict=how, asm_standins=stand, asm_sdk=sdkasm, asm_marked=marked,
                                 asm_placeholders=ph, complete=complete, complete_strict=strict,
                                 linked=linked))
        rows.append(row)
    return rows, unitrows


def totals(rows):
    t = {}
    for r in rows:
        for k, v in r.items():
            if isinstance(v, bool) or not isinstance(v, int):
                continue
            t[k] = t.get(k, 0) + v
    for k in ("total", "covered", "complete", "complete_strict", "linked", "linked_strict", "linked_skip", "unit_ok"):
        t[k + "_all"] = t.get(k + "_game", 0) + t.get(k + "_sdk", 0)
    t["regions"] = len(rows)
    t["regions_linked"] = sum(1 for r in rows if r["linked_region"])
    t["regions_linked_skip"] = sum(1 for r in rows if r["linked_skip_region"])
    return t


def pct(a, b):
    return 100.0 * a / b if b else 0.0


def print_table(rows, t):
    print("%-26s %4s %5s %5s %9s %9s %9s %9s %9s  %s" % (
        "region", "link", "units", "compl", "code", "covered", "complete", "linked", "unit_ok", "why"))
    for r in rows:
        tot = r["total_game"] + r["total_sdk"]
        if not tot:
            continue
        lk = ("PASS" if r["linked_region"] else "SKIP" if r["linked_skip_region"]
              else "FAIL" if r["link_tried"] else "-")
        why = "" if r["linked_region"] else (r["link_why_all"] or r["link_why"]
                                              or ("diff" if r["link_tried"] else "no link"))
        if r["linked_skip_region"] and not r["linked_region"]:
            why = "PASS with split parts left to the image; all files: " + (why or "diff")
        print("%-26s %4s %5d %5d %9d %9d %9d %9d %9d  %s" % (
            r["region"], lk, r["units"], r["units_complete"], tot,
            r["covered_game"] + r["covered_sdk"], r["complete_game"] + r["complete_sdk"],
            r["linked_game"] + r["linked_sdk"], r["unit_ok_game"] + r["unit_ok_sdk"], (why or "")[:70]))
    print()
    print("regions %d: linked byte-identical with every file %d, with split parts left out %d; "
          "units %d, complete %d (strict %d), linked %d" % (
              t["regions"], t["regions_linked"], t["regions_linked_skip"], t["units"], t["units_complete"],
              t["units_complete_strict"], t["units_linked"]))
    cols = ("covered", "complete", "linked", "linked_strict", "linked_skip")
    print("%-5s %9s" % ("", "code") + "".join(" %9s %7s" % (c[:9], "%") for c in cols))
    for side in ("game", "sdk", "all"):
        tot = t["total_" + side]
        print("%-5s %9d" % (side, tot) + "".join(" %9d %6.2f%%" % (t[c + "_" + side], pct(t[c + "_" + side], tot))
                                                for c in cols))
    print("covered = in a unit; linked = complete unit in a region whose link of every file is "
          "byte-identical (rule L);")
    print("linked_strict = same with only asm marked 'hand-written in the original' allowed; "
          "linked_skip = rule L with split parts left to the image")


# ------------------------------------------------------------------ objdiff report

def objdiff_report(rows, unitrows, results, rows_in):
    """A Report in the shape of objdiff-core report.proto, as a dict for JSON."""
    import ovstats
    matched_by_region = {}
    for region, listing, _s, _l in rows_in:
        try:
            labels = ovstats.listing_labels(listing)
            by_label = {}
            for a, n in labels:
                by_label.setdefault(n, a)
            m, _u = ovstats.matched_addresses(region, [a for a, _ in labels], by_label)
        except Exception:
            m = set()
        matched_by_region[region] = m

    def measures(total, matched, complete, nf, mf, nu, cu):
        return dict(fuzzy_match_percent=pct(matched, total), total_code=total, matched_code=matched,
                    matched_code_percent=pct(matched, total), total_data=0, matched_data=0,
                    matched_data_percent=0.0, total_functions=nf, matched_functions=mf,
                    matched_functions_percent=pct(mf, nf), complete_code=complete,
                    complete_code_percent=pct(complete, total), complete_data=0,
                    complete_data_percent=0.0, total_units=nu, complete_units=cu)

    import bisect
    units = []
    byreg = {}
    for u in unitrows:
        byreg.setdefault(u["region"], []).append(u)
    for region, listing, _s, _l in rows_in:
        funcs = listing_functions(region, listing)
        us = [u for u in byreg.get(region, []) if u["addr"]]
        us.sort(key=lambda u: int(u["addr"], 16))
        iv = sorted((int(x, 16), int(y, 16), k) for k, u in enumerate(us)
                    for x, y in (u.get("pieces") or [[u["addr"], u["end"]]]))
        keys = [x for x, _y, _k in iv]
        buckets = {id(u): [] for u in us}
        rest = []
        for a, n, is_sdk in funcs:
            i = bisect.bisect_right(keys, a) - 1
            if i >= 0 and a < iv[i][1]:
                buckets[id(us[iv[i][2]])].append((a, n, is_sdk))
            else:
                rest.append((a, n, is_sdk))
        msel = matched_by_region.get(region, set())
        for u in us + [None]:
            fl = buckets[id(u)] if u is not None else rest
            if not fl:
                continue
            exact_unit = u is not None and u["bytes_ok"]
            items, tot, mat, mf = [], 0, 0, 0
            for a, n, is_sdk in fl:
                ok = exact_unit or a in msel
                tot += n
                mat += n if ok else 0
                mf += ok
                items.append(dict(name="func_%08X" % a, size=n, fuzzy_match_percent=100.0 if ok else 0.0,
                                  address=a, metadata=dict(virtual_address=a)))
            comp = u is not None and u["linked"]
            name = "%s/%s" % (region, u["stem"]) if u is not None else "%s/_not_in_a_unit" % region
            cat = ["sdk" if all(s for _a, _n, s in fl) else "game", region]
            units.append(dict(name=name, measures=measures(tot, mat, tot if comp else 0, len(fl), mf, 1, int(comp)),
                              functions=items, sections=[],
                              metadata=dict(complete=bool(comp), module_name=region,
                                            source_path=u["path"] if u is not None else None,
                                            progress_categories=cat, auto_generated=u is None)))

    def agg(sel):
        tot = sum(x["measures"]["total_code"] for x in sel)
        mat = sum(x["measures"]["matched_code"] for x in sel)
        com = sum(x["measures"]["complete_code"] for x in sel)
        nf = sum(x["measures"]["total_functions"] for x in sel)
        mf = sum(x["measures"]["matched_functions"] for x in sel)
        real = [x for x in sel if not x["metadata"]["auto_generated"]]
        return measures(tot, mat, com, nf, mf, len(real), sum(1 for x in real if x["metadata"]["complete"]))

    cats = [dict(id="game", name="Game", measures=agg([x for x in units if "game" in x["metadata"]["progress_categories"]])),
            dict(id="sdk", name="SDK", measures=agg([x for x in units if "sdk" in x["metadata"]["progress_categories"]]))]
    return dict(version=1, measures=agg(units), categories=cats, units=units)


# ------------------------------------------------------------------ main

def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--jobs", type=int, default=max(1, min(8, (os.cpu_count() or 2) - 1)))
    ap.add_argument("--relink", action="store_true", help="ignore build/linkstats/cache.json")
    ap.add_argument("--only", nargs="*", help="regions to relink (others come from the cache)")
    ap.add_argument("--json", help="write rows, units and totals as JSON")
    ap.add_argument("--objdiff", help="write an objdiff report.proto-shaped JSON report")
    ap.add_argument("--units", action="store_true", help="list units that are not complete")
    a = ap.parse_args(argv)

    rows_in = regions()
    try:
        cache = json.load(open(CACHE, encoding="utf-8"))
    except (OSError, ValueError):
        cache = {}
    stamps = {r[0]: _stamp(r[2]) for r in rows_in if r[2]}
    todo = []
    for region, _l, srcdir, lid in rows_in:
        if not srcdir or not os.path.isdir(os.path.join(GAME, srcdir)):
            continue
        c = cache.get(region)
        fresh = c and c.get("stamp") == stamps[region] and not a.relink
        if a.only is not None:
            if region not in a.only:
                continue          # kept from the cache when there, else left out of the link
            fresh = False
        if not fresh:
            todo.append((region, srcdir, lid))
    if todo:
        print("linking %d region(s) with %d job(s)" % (len(todo), a.jobs), file=sys.stderr)
        os.makedirs(WORK, exist_ok=True)
        with cf.ProcessPoolExecutor(max_workers=a.jobs) as ex:
            futs = {ex.submit(link_region, j): j for j in todo}
            for n, f in enumerate(cf.as_completed(futs), 1):
                j = futs[f]
                try:
                    r = f.result()
                except Exception as e:      # noqa: BLE001
                    r = dict(region=j[0], attempts=[], link=dict(ok=False, why="worker %r" % (e,)))
                r["stamp"] = stamps[j[0]]
                cache[j[0]] = r
                lk = r.get("link") or {}
                if not lk:
                    note = "run_tu"
                elif lk.get("why"):
                    note = lk["why"]
                elif lk.get("diffs"):
                    note = "diff " + ",".join(lk["diffs"])
                else:
                    note = ""
                print("[%d/%d] %s %s %s" % (n, len(todo), j[0], "PASS" if lk.get("ok") else "FAIL",
                                            note[:100]), file=sys.stderr)
        os.makedirs(os.path.dirname(CACHE), exist_ok=True)
        json.dump(cache, open(CACHE, "w", encoding="utf-8"), indent=0)

    rows, unitrows = compute(rows_in, cache)
    t = totals(rows)
    print_table(rows, t)
    if a.units:
        print()
        for u in unitrows:
            if not u["complete"] and (u["game"] or u["sdk"]):
                why = []
                if u["split"]:
                    why.append("split")
                if not u["bytes_ok"]:
                    why.append("bytes:" + str(u["verdict"]))
                if u["asm_standins"]:
                    why.append("asm:" + ",".join(u["asm_standins"][:4]))
                if u["asm_placeholders"]:
                    why.append("placeholder:" + ",".join(u["asm_placeholders"][:4]))
                print("%-10s %-32s %7d  %s" % (u["region"], u["stem"], u["game"] + u["sdk"], " ".join(why)))
    if a.json:
        json.dump(dict(tool="linkstats", rules="see tools/linkstats.py docstring", totals=t, regions=rows,
                       units=unitrows), open(a.json, "w", encoding="utf-8"), indent=1)
    if a.objdiff:
        json.dump(objdiff_report(rows, unitrows, cache, rows_in), open(a.objdiff, "w", encoding="utf-8"), indent=1)
    return 0


if __name__ == "__main__":
    sys.exit(main())
