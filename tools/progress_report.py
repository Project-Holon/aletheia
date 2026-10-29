#!/usr/bin/env python3
"""progress_report.py -- the ByteMatch progress report (progress/report.json).

ByteMatch reads an objdiff report: the Report message of objdiff-core's
protos/report.proto (encounter/objdiff), written as protobuf JSON the way objdiff
itself writes it (pbjson with proto field names kept):

  * field names are the proto names in snake_case (total_code, not totalCode);
  * 64-bit integers (uint64: total_code, matched_code, complete_code, size,
    virtual_address, ...) are JSON strings; 32-bit integers and floats are numbers;
  * fields at their default value (0, 0.0, "", empty list) are left out;
  * `version` is 2 (objdiff REPORT_VERSION); readers migrate older versions, and
    a version 1 report would get total_units and complete_units added twice.

The figures come from tools/linkstats.py (rules D, U, C, L in its docstring):

  denominator   every non-veneer function of the region listings (rule D), its
                instruction bytes as its size;
  matched       a function is matched (fuzzy_match_percent 100, else 0) when it
                has an EXACT/EXACT* match record (tools/ovstats.py
                matched_addresses) or sits in a unit whose bytes came out
                identical (linkstats rule C2);
  complete      a unit is complete when linkstats says it is linked (rule L):
                complete_code is the unit's code, complete_units counts it.

One ReportUnit per top-level src/game source file that linkstats counts as a
unit (named `<region>/<stem>`, metadata.source_path its path).  Code that no
unit covers goes into two auto_generated units per region,
`<region>/_no_unit_game` and `<region>/_no_unit_sdk`; they count in the code
and function figures but not in total_units.  A unit is in category `sdk` when
most of its code bytes are SDK functions (rule D3), else in category `game`;
each category's measures are the sum of its units, as objdiff computes them.
Function names are `func_XXXXXXXX`, or the SDK symbol from
layout/symbols_sdk.txt; metadata.virtual_address is the function address.

Categories: `game` and `sdk` (all units), and per region group `arm9`, `itcm` (and each
other autoload block), `overlays`, `twl`, with `<group>_game` and `<group>_sdk` for arm9,
overlays and twl.  Each unit lists every category it belongs to in
metadata.progress_categories.

The report holds names, sizes, addresses and percentages only, no ROM bytes.  It
needs the asm/ listings (built from the ROM), so CI cannot make it: it is made
locally and committed; .github/workflows/progress.yml uploads the committed file.
Output is deterministic (fixed order, fixed float rounding, no timestamps), one
unit per line, so the file changes only when a figure changes.

usage
    python tools/progress_report.py [--out progress/report.json] [--jobs N]
                                    [--no-relink] [--check] [--version white | --target T]

--version white writes progress/report_white.json: the same units, with White addresses and
the White verdicts of layout/matched_white (tools/whitetrack.py; see white_report).
--target black and --target white are the same as --version black and --version white.  A language
target (black_fr ...) has no report yet: its tracking (layout/matched_<t>) comes with the language
sites in src/game, and the tool says so instead of writing a report.

By default linkstats is run first (it relinks only regions whose sources
changed; build/linkstats/cache.json).  --no-relink uses the cache as it is.
--check compares with the existing file and exits 1 when it is out of date.
"""

from __future__ import annotations

import argparse
import bisect
import contextlib
import io
import json
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOLS = os.path.join(ROOT, "tools")
if TOOLS not in sys.path:
    sys.path.insert(0, TOOLS)

import linkstats  # noqa: E402
import ovstats  # noqa: E402
import fnaddr  # noqa: E402  (function addresses whatever the name)

REPORT_VERSION = 2
DEFAULT_OUT = os.path.join(ROOT, "progress", "report.json")
CATEGORIES = (("game", "Game"), ("sdk", "SDK"))
U64 = {"total_code", "matched_code", "complete_code", "size", "address", "virtual_address"}


# ------------------------------------------------------------------ inputs

_FUNCS = {}


def functions(region, listing):
    """linkstats.listing_functions, memoised (compute() and this tool both need it)."""
    if region not in _FUNCS:
        _FUNCS[region] = _orig_listing_functions(region, listing)
    return _FUNCS[region]


_orig_listing_functions = linkstats.listing_functions
linkstats.listing_functions = functions


def sdk_symbols():
    """{(region, address): SDK symbol} from layout/symbols_sdk.txt."""
    out = {}
    try:
        f = open(os.path.join(ROOT, "layout", "symbols_sdk.txt"), encoding="utf-8")
    except OSError:
        return out
    with f:
        for line in f:
            w = line.split()
            if len(w) >= 4 and not line.startswith("#"):
                try:
                    out.setdefault((w[3], int(w[0], 16)), w[1])
                except ValueError:
                    pass
    return out


def matched_set(region, listing):
    try:
        labels = ovstats.listing_labels(listing)
        by_label = {}
        for a, n in labels:
            by_label.setdefault(n, a)
        m, _u = ovstats.matched_addresses(region, [a for a, _ in labels], by_label)
    except Exception:       # noqa: BLE001  (a region with no match records)
        return set()
    # an entry that reproduces several entry points of one body (the arm9 runtime
    # library, kind "runtime") lists them in "covers" and "functions"
    labelset = {a for a, _ in labels}
    for d in ovstats.shard_docs_of(region):
        for f in d.get("functions", []):
            if not isinstance(f, dict) or not str(f.get("status", "")).startswith(ovstats.MATCHED):
                continue
            for c in f.get("covers") or []:
                try:
                    a = int(str(c), 16)
                except ValueError:
                    continue
                if a in labelset:
                    m.add(a)
            # every name the entry lists, by address (tools/fnaddr.py: a unit's
            # `addresses`, a func_XXXXXXXX name, or its compiled layout), or by
            # the listing label of that name
            for n, a in fnaddr.listed_functions(f):
                if a is None and isinstance(n, str):
                    a = by_label.get(n)
                if a in labelset:
                    m.add(a)
    return m


def refresh(jobs, relink):
    """Bring build/linkstats/cache.json up to date, then load it."""
    if relink:
        with contextlib.redirect_stdout(io.StringIO()):
            linkstats.main(["--jobs", str(jobs)])
    try:
        return json.load(open(linkstats.CACHE, encoding="utf-8"))
    except (OSError, ValueError):
        sys.exit("progress_report: no %s; run without --no-relink" % linkstats.CACHE)


# ------------------------------------------------------------------ measures

def f32(x):
    """A percentage as objdiff stores it (float32), rounded for a stable text form."""
    return round(struct.unpack("<f", struct.pack("<f", x))[0], 4)


def pct(a, b):
    return 100.0 * a / b if b else 0.0


def measures(total, matched, complete, nf, mf, nu, cu):
    return dict(fuzzy_match_percent=pct(matched, total), total_code=total, matched_code=matched,
                matched_code_percent=pct(matched, total), total_functions=nf, matched_functions=mf,
                matched_functions_percent=pct(mf, nf), complete_code=complete,
                complete_code_percent=pct(complete, total), total_units=nu, complete_units=cu)


def add(ms):
    keys = ("total_code", "matched_code", "complete_code", "total_functions", "matched_functions",
            "total_units", "complete_units")
    s = {k: sum(m[k] for m in ms) for k in keys}
    return measures(s["total_code"], s["matched_code"], s["complete_code"], s["total_functions"],
                    s["matched_functions"], s["total_units"], s["complete_units"])


def group_of(region):
    """(group id, group name) of a region."""
    if region.startswith("ov"):
        return "overlays", "Overlays"
    if region == "arm9":
        return "arm9", "ARM9"
    if region == "twl":
        return "twl", "TWL"
    if region == "arm9_autoload0_ITCM":
        return "itcm", "ITCM"
    gid = region.replace("arm9_", "").lower()
    return gid, gid.replace("_", " ").upper()


KIND_SPLIT = ("arm9", "overlays", "twl")


def pbjson(v, key=None):
    """protobuf JSON as objdiff writes it: u64 as strings, defaults left out."""
    if isinstance(v, dict):
        out = {}
        for k, x in v.items():
            if k == "complete":          # optional bool: present even when false
                out[k] = bool(x)
                continue
            if x is None or x == "" or x == [] or (x == 0 and not isinstance(x, bool)) or x is False:
                continue
            out[k] = pbjson(x, k)
        return out
    if isinstance(v, list):
        return [pbjson(x, key) for x in v]
    if isinstance(v, bool):
        return v
    if isinstance(v, int):
        return str(v) if key in U64 else v
    if isinstance(v, float):
        return f32(v)
    return v


# ------------------------------------------------------------------ report

def build(cache, jobs=4):
    rows_in = linkstats.regions()
    _rows, unitrows = linkstats.compute(rows_in, cache)
    names = sdk_symbols()
    byreg = {}
    for u in unitrows:
        byreg.setdefault(u["region"], []).append(u)
    units = []
    for region, listing, _s, _l in rows_in:
        funcs = functions(region, listing)
        msel = matched_set(region, listing)
        us = sorted(byreg.get(region, []), key=lambda u: u["stem"])
        iv = sorted((int(x, 16), int(y, 16), k) for k, u in enumerate(us) if u["addr"]
                    for x, y in (u.get("pieces") or [[u["addr"], u["end"]]]))
        keys = [x for x, _y, _k in iv]
        buckets = [[] for _ in us]
        rest = {False: [], True: []}
        for a, n, is_sdk in funcs:
            i = bisect.bisect_right(keys, a) - 1
            if i >= 0 and a < iv[i][1]:
                buckets[iv[i][2]].append((a, n, is_sdk))
            else:
                rest[bool(is_sdk)].append((a, n, is_sdk))

        gid, gname = group_of(region)

        def unit(name, fl, exact, comp, real, path):
            items, tot, mat, mf, sdkb = [], 0, 0, 0, 0
            for a, n, is_sdk in sorted(fl):
                ok = exact or a in msel
                tot += n
                mat += n if ok else 0
                mf += ok
                sdkb += n if is_sdk else 0
                items.append(dict(name=names.get((region, a)) or "func_%08X" % a, size=n,
                                  fuzzy_match_percent=100.0 if ok else 0.0,
                                  metadata=dict(virtual_address=a)))
            cat = "sdk" if 2 * sdkb > tot else "game"
            cats = [cat, gid] + (["%s_%s" % (gid, cat)] if gid in KIND_SPLIT else [])
            meta = dict(complete=bool(comp), module_name=region, source_path=path,
                        progress_categories=cats, auto_generated=not real)
            return dict(name=name, measures=measures(tot, mat, tot if comp else 0, len(items), mf,
                                                     int(real), int(real and comp)),
                        functions=items, metadata=meta)

        for k, u in enumerate(us):
            units.append(unit("%s/%s" % (region, u["stem"]), buckets[k], bool(u["bytes_ok"]),
                              bool(u["linked"]), True, u["path"]))
        for is_sdk, tag in ((False, "game"), (True, "sdk")):
            if rest[is_sdk]:
                units.append(unit("%s/_no_unit_%s" % (region, tag), rest[is_sdk], False, False,
                                  False, None))
    cats = categories(units)
    return dict(measures=add([u["measures"] for u in units]), units=units, version=REPORT_VERSION,
                categories=cats)


def categories(units):
    """game and sdk first, then the region groups (and their game/sdk kinds) that have units."""
    names = list(CATEGORIES)
    seen = {}
    for u in units:
        for c in u["metadata"]["progress_categories"]:
            seen.setdefault(c, None)
    gnames = {}
    for u in units:
        gnames[group_of(u["metadata"]["module_name"])[0]] = group_of(u["metadata"]["module_name"])[1]
    for gid in sorted(gnames, key=lambda g: ("arm9", "itcm", "overlays", "twl").index(g)
                      if g in ("arm9", "itcm", "overlays", "twl") else 9):
        for cid, nm in ((gid, gnames[gid]), (gid + "_game", gnames[gid] + " game"),
                        (gid + "_sdk", gnames[gid] + " SDK")):
            if cid in seen:
                names.append((cid, nm))
    return [dict(id=cid, name=cname,
                 measures=add([u["measures"] for u in units if cid in u["metadata"]["progress_categories"]]))
            for cid, cname in names]


def white_report(report):
    """The same report for the White build.  The units, function names and sizes are Black's
    (same source files); each function is matched when layout/matched_white (tools/whitetrack.py)
    says EXACT, its address is the White address, and a function the tracking has no row for
    follows its Black verdict when the region's White link passes.  A unit is complete when its
    Black verdict is complete and every function is matched in White.  Only EXACT counts as
    matched (every record is EXACT today)."""
    import whitetrack
    import white_map
    track = {}
    for region in {u["metadata"]["module_name"] for u in report["units"]}:
        p = os.path.join(whitetrack.OUT, "%s.json" % region)
        if os.path.exists(p):
            for r in json.load(open(p, encoding="utf-8"))["functions"]:
                track[(region, int(r["black_address"], 16))] = r
    rows = whitetrack.read_rows()
    linked = {}
    for u in report["units"]:
        region = u["metadata"]["module_name"]
        if region not in linked:
            st = whitetrack.link_state(region)
            linked[region] = not isinstance(st, str)
        done = []
        for f in u["functions"]:
            a = f["metadata"]["virtual_address"]
            t = track.get((region, a))
            if t is not None:
                ok = t["status"] == "EXACT"
                wa = int(t["white_address"], 16) if t.get("white_address") else a
            else:
                ok = linked[region] and f["fuzzy_match_percent"] == 100.0 and not u["metadata"]["auto_generated"]
                r = rows.get(region, {}).get(a)
                try:
                    wa = r[0] if r and r[0] is not None else white_map.to_white(a, region if region.startswith("ov") else None)
                except KeyError:
                    wa = a
            f["fuzzy_match_percent"] = 100.0 if ok else 0.0
            f["metadata"]["virtual_address"] = wa
            done.append(ok)
        tot = sum(f["size"] for f in u["functions"])
        mat = sum(f["size"] for f, ok in zip(u["functions"], done) if ok)
        real = not u["metadata"]["auto_generated"]
        comp = bool(u["metadata"]["complete"]) and all(done) and linked[region]
        u["metadata"]["complete"] = comp
        u["measures"] = measures(tot, mat, tot if comp else 0, len(done), sum(done), int(real), int(real and comp))
    report["categories"] = categories(report["units"])
    report["measures"] = add([u["measures"] for u in report["units"]])
    return report


def dumps(report):
    """Deterministic text: the header indented, one unit per line."""
    r = pbjson(report)
    c = dict(separators=(",", ":"), ensure_ascii=False)
    lines = ["{",
             ' "version":%d,' % r["version"],
             ' "measures":%s,' % json.dumps(r["measures"], **c),
             ' "categories":[',
             ",\n".join("  " + json.dumps(x, **c) for x in r["categories"]),
             " ],",
             ' "units":[',
             ",\n".join("  " + json.dumps(x, **c) for x in r["units"]),
             " ]",
             "}"]
    return "\n".join(lines) + "\n"


def headline(report):
    def line(tag, m):
        return ("%-16s code %9d  matched %9d (%7.3f%%)  complete %9d (%7.3f%%)  functions %6d/%6d  "
                "units %4d/%4d" % (tag, m["total_code"], m["matched_code"], m["matched_code_percent"],
                                   m["complete_code"], m["complete_code_percent"], m["matched_functions"],
                                   m["total_functions"], m["complete_units"], m["total_units"]))
    out = [line("all", report["measures"])]
    out += [line(c["id"], c["measures"]) for c in report["categories"]]
    return "\n".join(out)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--out", default=DEFAULT_OUT)
    ap.add_argument("--jobs", type=int, default=max(1, min(8, (os.cpu_count() or 2) - 1)))
    ap.add_argument("--no-relink", action="store_true", help="use build/linkstats/cache.json as it is")
    ap.add_argument("--check", action="store_true", help="exit 1 if --out is out of date")
    ap.add_argument("--version", choices=("black", "white"), default="black",
                    help="white: figures for the White build (progress/report_white.json)")
    ap.add_argument("--target", default=None, help="black or white (same as --version); language targets: not yet")
    a = ap.parse_args(argv)
    if a.target:
        if a.target not in ("black", "white"):
            print("no report for target %r yet: the Black and White reports are the only ones" % a.target, file=sys.stderr)
            return 2
        a.version = a.target
    if a.version == "white" and a.out == DEFAULT_OUT:
        a.out = os.path.join(ROOT, "progress", "report_white.json")
    report = build(refresh(a.jobs, not a.no_relink), a.jobs)
    if a.version == "white":
        report = white_report(report)
    text = dumps(report)
    print(headline(report))
    if a.check:
        try:
            old = open(a.out, encoding="utf-8").read()
        except OSError:
            old = None
        if old != text:
            print("%s is out of date" % os.path.relpath(a.out, ROOT), file=sys.stderr)
            return 1
        return 0
    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    with open(a.out, "w", encoding="utf-8", newline="\n") as f:
        f.write(text)
    print("wrote %s (%d units, %d bytes)" % (os.path.relpath(a.out, ROOT), len(report["units"]), len(text)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
