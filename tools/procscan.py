#!/usr/bin/env python3
"""procscan.py -- classify ARM function epilogues to infer -proc per unit.

The project's pinned compiler flags are `-proc arm946e`, and under that flag
mwcc returns from a non-leaf function with a single `ldmia sp!, {..., pc}`
(printed by the listings as `pop {..., pc}`).  One known translation unit
(0x0205429C..0x020584E0, see
docs/idioms/an-arm-epilogue-of-pop-lr-then-bx-names-a-proc-arm7tdmi-unit.md)
was actually built with `-proc arm7tdmi`: on that core a pop into pc does
not switch instruction set, so every non-leaf function there instead
restores lr and returns through it:

    pop {r4, lr}
    bx  lr

Every function in a unit built this way stays DIFF under the pinned flags
until an agent notices and overrides `flags:` in the file header, and the
tell (per the idiom doc) is that the two-instruction return is the *only*
shape every non-leaf function in the unit uses -- leaf functions (which
push nothing) look the same either way.

This scans every ARM function in arm9_main and every overlay, classifies
its return into one of five buckets, and aggregates per translation unit
(layout/units_arm9.json), per overlay, and per still-open work packet
(layout/worklist.json), writing the census to layout/proc_hints.txt so
tools/worklist.py can surface the right -proc before an agent starts.

Buckets
-------
  pop_into_pc      `pop{cond} {..., pc}` -- the pinned arm946e idiom
  ldm_into_pc      `ldm{cond} sp!, {..., pc}` (capstone declines the pop
                   alias for some register lists; functionally the same
                   single-instruction return as pop_into_pc)
  pop_lr_then_bx   `pop{cond} {..., lr}` immediately followed by
                   `bx{cond} lr` -- the arm7tdmi tell
  bx_lr_leaf       a bare `bx lr` with no push anywhere before it in the
                   function -- a leaf, uninformative about -proc
  other            anything else: a pop of lr not immediately followed by
                   bx lr, a tail branch, or no return found at all

A function can have more than one return site; its bucket is whichever of
the five the function has the most instances of (address order break ties
in the priority pop_into_pc > pop_lr_then_bx > ldm_into_pc > bx_lr_leaf >
other), so almost every function -- which mwcc funnels through one shared
epilogue -- lands cleanly in one bucket.

The 23A note (docs/notes/func_0205841C.c.txt and neighbours) also names a
second, `-proc`-independent trait of the same unit: an explicit
`sub sp, sp, #4` where mwcc 1.1p1 would ordinarily push a spare
caller-saved register for stack alignment.  This is counted per unit too
(any occurrence, not just in the prologue) since it is a second witness
for "this unit was not built the way the rest of the image was", even
though it survives every `-proc`.

Inferred proc, per unit/overlay/packet
---------------------------------------
  nonleaf = pop_into_pc + ldm_into_pc + pop_lr_then_bx  (bx_lr_leaf and
            other carry no -proc evidence and are excluded)
  arm946e   nonleaf == 0 (no contrary evidence; the pinned default), or
            (pop_into_pc + ldm_into_pc) > pop_lr_then_bx
  arm7tdmi  pop_lr_then_bx > (pop_into_pc + ldm_into_pc)
  mixed     nonleaf > 0 and neither side is strictly greater

Nothing here reads or writes game data: only addresses, counts and the
inferred -proc token are ever written out.

Usage
-----
  python tools/procscan.py                 write layout/proc_hints.txt
  python tools/procscan.py --check         report whether it would change,
                                            write nothing
  python tools/procscan.py --crosscheck    also run the EXACT/-proc
                                            cross-check (see below) and
                                            print its report

Cross-check
-----------
Every arm9 manifest entry that is EXACT under the *default* flags (i.e.
its `flags:` field carries `-proc arm946e`, not an override) is real,
positive evidence that its unit was built with the pinned proc.  Every
such unit this scan does not also classify arm946e is reported: that is
either a false classification here or a second real arm7tdmi-built unit
hiding behind an EXACT match that happens to not need the four-byte-
shorter epilogue to be byte-identical (leaf-heavy files, mostly).
"""

from __future__ import annotations

import argparse
import bisect
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

import disasm  # noqa: E402

UNITS_JSON = os.path.join(ROOT, "layout", "units_arm9.json")
LAYOUT_JSON = os.path.join(ROOT, "layout", "layout.json")
WORKLIST_JSON = os.path.join(ROOT, "layout", "worklist.json")
MATCHED_ARM9_DIR = os.path.join(ROOT, "layout", "matched", "arm9")
OUT_PATH = os.path.join(ROOT, "layout", "proc_hints.txt")

HEADER = [
    "# ARM epilogue census: -proc inference per arm9 unit, overlay and packet",
    "# generated by tools/procscan.py; do not edit, do not commit game bytes",
    "# addresses, instruction-class counts and inferred -proc only",
    "# see docs/idioms/an-arm-epilogue-of-pop-lr-then-bx-names-a-proc-arm7tdmi-unit.md",
    "#",
    "# columns:",
    "#   kind    unit | overlay | packet",
    "#   id      unit source file stem, overlay_NNN, or packet id",
    "#   region  arm9_main or overlay_NNN",
    "#   start end        address range (end exclusive)",
    "#   arm_funcs         ARM-mode functions classified",
    "#   thumb_funcs       Thumb-mode functions in range, not classified",
    "#   pop_pc pop_lr_bx ldm_pc bx_leaf other   epilogue bucket counts",
    "#   subsp4            functions containing a literal 'sub sp, sp, #4'",
    "#   proc              inferred: arm946e | arm7tdmi | mixed",
]

COLUMNS = (
    "kind", "id", "region", "start", "end", "arm_funcs", "thumb_funcs",
    "pop_pc", "pop_lr_bx", "ldm_pc", "bx_leaf", "other", "subsp4", "proc",
)

# ---------------------------------------------------------------- parsing

RE_LABEL = re.compile(r"^([A-Za-z_.$][A-Za-z0-9_.$]*):")
RE_FUNC_LABEL = re.compile(r"^func_([0-9A-Fa-f]{8}):")

_COND_ALT = "|".join(disasm.CONDS)
RE_POP_MNEM = re.compile(r"^(pop|ldm)(%s)?$" % _COND_ALT, re.IGNORECASE)
RE_PUSH_MNEM = re.compile(r"^push(%s)?$" % _COND_ALT, re.IGNORECASE)
RE_BX_MNEM = re.compile(r"^bx(%s)?$" % _COND_ALT, re.IGNORECASE)
RE_SUB_MNEM = re.compile(r"^sub(%s)?$" % _COND_ALT, re.IGNORECASE)
RE_SUBSP4_OPS = re.compile(r"^sp\s*,\s*sp\s*,\s*#0?x?0*4$", re.IGNORECASE)


def hexa(addr):
    return "0x%08X" % addr


def parse_funcs(path):
    """[(addr, isa)] function labels in a listing, in address order.

    Mirrors tools/worklist.py's parse_unit label/mode tracking (the only
    other reader of this shape); kept independent here rather than
    imported since worklist.py's parse_unit also builds edges and data
    runs this tool has no use for.
    """
    funcs = []
    mode = "arm"
    pending_thumb_func = False
    if not os.path.isfile(path):
        return funcs
    with open(path, encoding="utf-8") as fh:
        for raw in fh:
            line = raw.strip()
            if not line or line.startswith("/*") or line.startswith("*"):
                continue
            m = RE_LABEL.match(line)
            if m:
                fm = RE_FUNC_LABEL.match(line)
                if fm:
                    addr = int(fm.group(1), 16)
                    isa = "thumb" if pending_thumb_func else mode
                    funcs.append((addr, isa))
                    pending_thumb_func = False
                continue
            if line.startswith(".") and not line.startswith(".inst"):
                tok = line.split()[0]
                if tok == ".thumb_func":
                    pending_thumb_func = True
                elif tok == ".thumb":
                    mode = "thumb"
                elif tok == ".arm":
                    mode = "arm"
    return funcs


def reglist(ops):
    i = ops.find("{")
    j = ops.find("}")
    if i == -1 or j == -1:
        return []
    return [t.strip().lower() for t in ops[i + 1:j].split(",") if t.strip()]


BUCKETS = ("pop_pc", "pop_lr_bx", "ldm_pc", "bx_leaf", "other")
BUCKET_PRIORITY = {"pop_pc": 0, "pop_lr_bx": 1, "ldm_pc": 2, "bx_leaf": 3, "other": 4}


def classify_function(instrs):
    """(bucket, has_subsp4) for one function's (addr, mnem, ops) instructions."""
    counts = dict((b, 0) for b in BUCKETS)
    has_push = False
    has_subsp4 = False
    prev_pop_lr = False

    for _addr, mnem, ops in instrs:
        m_low = mnem.lower()
        cur_pop_lr = False

        if RE_PUSH_MNEM.match(m_low):
            has_push = True
        elif RE_SUB_MNEM.match(m_low) and RE_SUBSP4_OPS.match(ops.strip()):
            has_subsp4 = True
        elif RE_POP_MNEM.match(m_low):
            regs = reglist(ops)
            if "pc" in regs:
                counts["pop_pc" if m_low.startswith("pop") else "ldm_pc"] += 1
            elif "lr" in regs:
                cur_pop_lr = True
        elif RE_BX_MNEM.match(m_low) and ops.strip().lower() == "lr":
            if prev_pop_lr:
                counts["pop_lr_bx"] += 1
            elif not has_push:
                counts["bx_leaf"] += 1
            else:
                counts["other"] += 1

        prev_pop_lr = cur_pop_lr

    total = sum(counts.values())
    if total == 0:
        return "other", has_subsp4
    bucket = min(
        (b for b in BUCKETS if counts[b] > 0),
        key=lambda b: (-counts[b], BUCKET_PRIORITY[b]),
    )
    return bucket, has_subsp4


def new_row(kind, rid, region, start, end):
    row = dict((c, 0) for c in COLUMNS)
    row.update(kind=kind, id=rid, region=region, start=start, end=end,
               proc="arm946e")
    return row


MIN_RUN_EVIDENCE = 3  # a lone hand-written stmdb/bx-lr routine is not a TU


def infer_proc(row):
    """arm946e / arm7tdmi / mixed from a row's epilogue bucket counts.

    Below MIN_RUN_EVIDENCE total non-leaf samples the default (arm946e,
    the pinned flag) wins regardless: one stray hand-written low-level
    routine (crt0-style, an `stmdb sp!, {lr}` / `ldm sp!, {lr}; bx lr`
    static-initialiser walker turns up once in arm9_main) is not the
    "every non-leaf function" consistency the idiom doc's tell requires,
    and a packet with only 1-2 open functions should not flip proc on a
    single coincidental match either.
    """
    pc_style = row["pop_pc"] + row["ldm_pc"]
    lr_style = row["pop_lr_bx"]
    nonleaf = pc_style + lr_style
    if nonleaf < MIN_RUN_EVIDENCE:
        return "arm946e"
    if lr_style > pc_style:
        return "arm7tdmi"
    if pc_style > lr_style:
        return "arm946e"
    return "mixed"


# ---------------------------------------------------------------- arm9_main
#
# layout/units_arm9.json splits arm9_main into fixed 180-function listing
# files (30 of 31 entries carry exactly 180; the last carries the 50-
# function remainder) -- a disasm.py output-chunking convention, not real
# mwcc translation-unit boundaries: the known arm7tdmi library
# (0x0205429C..0x020584E0) sits inside one such 180-function file together
# with ~130 unrelated, arm946e-compiled functions either side of it, so
# aggregating strictly at that file granularity would average the tell
# away. Real translation units are recovered here instead as maximal
# address-contiguous runs of ARM functions that agree on hard evidence
# (pop-into-pc/ldm-into-pc vs. pop-lr-then-bx-lr); a leaf or "other"
# function carries no evidence and simply joins whichever run is open. The
# file-level split is kept too, as "unit_file" rows, purely for provenance
# (which asm/arm9/src/*.s an address falls in).


def _classify_arm9_functions():
    """[(addr, end, file_stem, bucket, has_subsp4)] for every ARM function.

    Also returns func_class: addr -> bucket, for scan_packets().
    """
    with open(UNITS_JSON, encoding="utf-8") as fh:
        units_doc = json.load(fh)

    instrs = list(disasm.scan_mnemonics("arm9_main"))
    instr_addrs = [t[0] for t in instrs]

    out = []
    func_class = {}
    for u in units_doc["units"]:
        path = os.path.join(ROOT, u["file"].replace("/", os.sep))
        funcs = parse_funcs(path)
        unit_end = u["base"] + u["size"]
        stem = os.path.splitext(os.path.basename(u["file"]))[0]

        for i, (addr, isa) in enumerate(funcs):
            end = funcs[i + 1][0] if i + 1 < len(funcs) else unit_end
            if isa == "thumb":
                out.append((addr, end, stem, "thumb", False))
                continue
            lo = bisect.bisect_left(instr_addrs, addr)
            hi = bisect.bisect_left(instr_addrs, end)
            bucket, has_subsp4 = classify_function(instrs[lo:hi])
            func_class[addr] = bucket
            out.append((addr, end, stem, bucket, has_subsp4))

    out.sort(key=lambda t: t[0])
    return out, func_class


PC_STYLE_BUCKETS = ("pop_pc", "ldm_pc")
LR_STYLE_BUCKETS = ("pop_lr_bx",)


def _signal_of(bucket):
    if bucket in PC_STYLE_BUCKETS:
        return "pc"
    if bucket in LR_STYLE_BUCKETS:
        return "lr"
    return None  # bx_leaf, other, thumb: no -proc evidence


def _run_hard_evidence_count(run):
    return sum(1 for rec in run if _signal_of(rec[3]) is not None)


def _segment_arm9_functions(funcs, min_evidence=MIN_RUN_EVIDENCE):
    """Group classified ARM functions into maximal same-signal address runs.

    A run continues across leaf/"other"/thumb functions (no signal to
    conflict with); it breaks the moment a function's hard evidence
    (pc-style vs. lr-style) disagrees with the run's own signal.

    A single stray function (a hand-written low-level routine, or a rare
    misclassification) should not by itself flip a whole stretch of an
    otherwise-consistent file: after the initial split, any run with fewer
    than ``min_evidence`` hard-evidence functions of its own is folded into
    an adjacent run instead of standing as its own segment (see the idiom
    doc: the tell is *every* non-leaf function in a unit, not one).
    """
    raw = []
    cur = []
    cur_signal = None
    for rec in funcs:
        _addr, _end, _stem, bucket, _sub = rec
        sig = _signal_of(bucket)
        if sig is not None and cur_signal is not None and sig != cur_signal:
            raw.append(cur)
            cur = []
            cur_signal = None
        cur.append(rec)
        if sig is not None:
            cur_signal = sig
    if cur:
        raw.append(cur)

    runs = []
    pending = []
    for run in raw:
        run = pending + run
        pending = []
        if _run_hard_evidence_count(run) < min_evidence:
            if runs:
                runs[-1].extend(run)
            else:
                pending = run  # leading weak run: attach to the first strong one
        else:
            runs.append(run)
    if pending:
        if runs:
            runs[-1].extend(pending)
        else:
            runs.append(pending)
    return runs


def _row_from_records(kind, rid, region, records):
    start = records[0][0]
    end = records[-1][1]
    row = new_row(kind, rid, region, hexa(start), hexa(end))
    for _addr, _end, _stem, bucket, has_subsp4 in records:
        if bucket == "thumb":
            row["thumb_funcs"] += 1
            continue
        row["arm_funcs"] += 1
        row[bucket] += 1
        if has_subsp4:
            row["subsp4"] += 1
    row["proc"] = infer_proc(row)
    return row


def scan_arm9_main():
    """(rows, func_class): unit_file rows, segment ("unit") rows, func_class.

    func_class maps every classified ARM function address to its bucket,
    reused by scan_packets() so packet aggregation does not re-derive it.
    """
    funcs, func_class = _classify_arm9_functions()

    file_rows = []
    segment_rows = []
    for stem, group in _groupby_stem(funcs):
        file_rows.append(_row_from_records("unit_file", stem, "arm9_main", group))
        # Segment within one listing file only: a run must never be allowed
        # to bridge two files, since a stray/sparse-evidence function in a
        # nearly-all-Thumb file would otherwise poison every unrelated file
        # after it until the next hard-evidence function turns up, however
        # far away that is (arm-mode functions are sparse for long stretches
        # of this image, so that gap can be huge).
        for run in _segment_arm9_functions(group):
            rid = "seg_%08X" % run[0][0]
            segment_rows.append(_row_from_records("unit", rid, "arm9_main", run))

    return file_rows + segment_rows, func_class


def _groupby_stem(funcs):
    """[(stem, [records])] preserving units_arm9.json file order."""
    order = []
    by_stem = {}
    for rec in funcs:
        stem = rec[2]
        if stem not in by_stem:
            by_stem[stem] = []
            order.append(stem)
        by_stem[stem].append(rec)
    return [(stem, by_stem[stem]) for stem in order]


# ---------------------------------------------------------------- overlays


def scan_overlays():
    with open(LAYOUT_JSON, encoding="utf-8") as fh:
        layout_doc = json.load(fh)

    rows = []
    for ov in layout_doc["overlays"]:
        ov_id = ov["id"]
        region = "overlay_%03d" % ov_id
        s_path = os.path.join(ROOT, "asm", "overlays", "ov%03d.s" % ov_id)
        if not os.path.isfile(s_path):
            continue

        funcs = parse_funcs(s_path)
        base, end = ov["ram_start"], ov["ram_end"]
        row = new_row("overlay", region, region, hexa(base), hexa(end))
        if not funcs:
            row["proc"] = infer_proc(row)
            rows.append(row)
            continue

        instrs = list(disasm.scan_mnemonics(region))
        instr_addrs = [t[0] for t in instrs]

        for i, (addr, isa) in enumerate(funcs):
            fend = funcs[i + 1][0] if i + 1 < len(funcs) else end
            if isa == "thumb":
                row["thumb_funcs"] += 1
                continue
            row["arm_funcs"] += 1
            lo = bisect.bisect_left(instr_addrs, addr)
            hi = bisect.bisect_left(instr_addrs, fend)
            bucket, has_subsp4 = classify_function(instrs[lo:hi])
            row[bucket] += 1
            if has_subsp4:
                row["subsp4"] += 1

        row["proc"] = infer_proc(row)
        rows.append(row)

    return rows


# ---------------------------------------------------------------- packets


def scan_packets(func_class):
    if not os.path.isfile(WORKLIST_JSON):
        return []
    with open(WORKLIST_JSON, encoding="utf-8") as fh:
        doc = json.load(fh)

    rows = []
    for pkt in doc.get("packets", {}).values():
        row = new_row("packet", pkt["id"], "arm9_main", pkt["start"], pkt["end"])
        for f in pkt.get("functions", []):
            addr = int(f["addr"], 16)
            bucket = func_class.get(addr)
            if bucket is None:
                continue  # thumb, or not classified (shouldn't happen)
            row["arm_funcs"] += 1
            row[bucket] += 1
        row["proc"] = infer_proc(row)
        rows.append(row)
    return rows


# ---------------------------------------------------------------- output


def render(rows):
    lines = list(HEADER)
    lines.append("#")
    lines.append("# " + "  ".join(COLUMNS))
    for row in rows:
        lines.append(
            "%-8s %-24s %-14s %-12s %-12s %5d %5d  %5d %5d %5d %5d %5d  %5d  %s"
            % (
                row["kind"], row["id"], row["region"], row["start"], row["end"],
                row["arm_funcs"], row["thumb_funcs"],
                row["pop_pc"], row["pop_lr_bx"], row["ldm_pc"],
                row["bx_leaf"], row["other"], row["subsp4"], row["proc"],
            )
        )
    return "\n".join(lines) + "\n"


def parse_hints(path=OUT_PATH):
    """{(kind, id): proc} read back from a written proc_hints.txt.

    The one function tools/worklist.py needs; kept here so there is a
    single parser for the format instead of one per caller.
    """
    hints = {}
    if not os.path.isfile(path):
        return hints
    with open(path, encoding="utf-8") as fh:
        for line in fh:
            if not line.strip() or line.startswith("#"):
                continue
            parts = line.split()
            if len(parts) < 14:
                continue
            kind, rid = parts[0], parts[1]
            proc = parts[-1]
            hints[(kind, rid)] = proc
    return hints


# ---------------------------------------------------------------- cross-check


def crosscheck(unit_rows, func_class):
    """EXACT-under-default-flags arm9 entries vs. this scan's segment proc.

    ``unit_rows`` is the combined unit_file + unit (segment) row list
    scan_arm9_main() returns; only the segment ("unit") rows carry a
    meaningful -proc verdict (see the comment above scan_arm9_main), so
    this bisects on those. Returns (checked_segment_ids, mismatches),
    where mismatches is [(segment_id, classified_proc)] for a segment that
    holds an EXACT, default-flags (no -proc override) manifest entry but
    was not itself classified arm946e.

    Only an entry whose own function is classified pop_pc/ldm_pc (real,
    single-instruction-return non-leaf evidence) counts as a witness for
    "this address was built arm946e": a leaf function's EXACT match under
    default flags proves nothing about -proc (the idiom doc's own
    caution -- leaf functions match under either value), so it is not
    evidence against a segment classified arm7tdmi around it.
    """
    segments = [r for r in unit_rows if r["kind"] == "unit"]
    segments.sort(key=lambda r: int(r["start"], 16))
    seg_starts = [int(r["start"], 16) for r in segments]

    def segment_for_addr(addr):
        i = bisect.bisect_right(seg_starts, addr) - 1
        if i < 0:
            return None
        r = segments[i]
        if int(r["start"], 16) <= addr < int(r["end"], 16):
            return r
        return None

    exact_default_units = set()
    if os.path.isdir(MATCHED_ARM9_DIR):
        for path in sorted(glob.glob(os.path.join(MATCHED_ARM9_DIR, "*.json"))):
            with open(path, encoding="utf-8") as fh:
                shard = json.load(fh)
            for ent in shard.get("functions", []):
                if ent.get("status") != "EXACT":
                    continue
                flags = ent.get("flags", "")
                if "-proc arm7tdmi" in flags:
                    continue  # a known, already-flagged override; not evidence
                if "-proc arm946e" not in flags:
                    continue  # unexpected flag string; not counted either way
                addrs = []
                if ent.get("address"):
                    addrs.append(int(ent["address"], 16))
                for member in ent.get("functions", []) or []:
                    m = re.search(r"([0-9A-Fa-f]{8})$", member)
                    if m:
                        addrs.append(int(m.group(1), 16))
                for addr in addrs:
                    if func_class.get(addr) not in PC_STYLE_BUCKETS:
                        continue
                    seg = segment_for_addr(addr)
                    if seg:
                        exact_default_units.add(seg["id"])

    mismatches = []
    proc_of_seg = dict((r["id"], r["proc"]) for r in segments)
    for sid in sorted(exact_default_units):
        proc = proc_of_seg.get(sid)
        if proc != "arm946e":
            mismatches.append((sid, proc))
    return sorted(exact_default_units), mismatches


# ---------------------------------------------------------------- main


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--check", action="store_true",
                    help="report whether output would change, write nothing")
    ap.add_argument("--out", default=OUT_PATH)
    ap.add_argument("--crosscheck", action="store_true",
                    help="also print the EXACT/-proc cross-check report")
    args = ap.parse_args(argv)

    unit_rows, func_class = scan_arm9_main()
    overlay_rows = scan_overlays()
    packet_rows = scan_packets(func_class)

    rows = unit_rows + overlay_rows + packet_rows
    text = render(rows)

    if args.check:
        old = None
        if os.path.isfile(args.out):
            with open(args.out, encoding="utf-8") as fh:
                old = fh.read()
        same = old == text
        print("unchanged" if same else "would change")
        if args.crosscheck:
            _checked, mismatches = crosscheck(unit_rows, func_class)
            _print_crosscheck(unit_rows, func_class, mismatches)
        return 0 if same else 1

    with open(args.out, "w", encoding="utf-8", newline="\n") as fh:
        fh.write(text)
    print("wrote %s" % os.path.relpath(args.out, ROOT))

    nonarm946e = [r for r in unit_rows if r["kind"] == "unit" and r["proc"] != "arm946e"]
    print("%d unit(s) not arm946e:" % len(nonarm946e))
    for r in nonarm946e:
        print("  %-24s %s..%s  %s" % (r["id"], r["start"], r["end"], r["proc"]))
    ov_nonarm946e = [r for r in overlay_rows if r["proc"] != "arm946e"]
    print("%d overlay(s) not arm946e:" % len(ov_nonarm946e))
    for r in ov_nonarm946e:
        print("  %-14s %s..%s  %s" % (r["id"], r["start"], r["end"], r["proc"]))

    if args.crosscheck:
        checked, mismatches = crosscheck(unit_rows, func_class)
        _print_crosscheck(unit_rows, func_class, mismatches, checked)

    return 0


def _print_crosscheck(unit_rows, func_class, mismatches, checked=None):
    if checked is None:
        checked, mismatches = crosscheck(unit_rows, func_class)
    print("cross-check: %d unit(s) carry an EXACT default-flags entry" % len(checked))
    if mismatches:
        print("  %d mismatch(es) (EXACT under arm946e but not classified arm946e):"
              % len(mismatches))
        for uid, proc in mismatches:
            print("    %-24s classified %s" % (uid, proc))
    else:
        print("  all classify arm946e")


if __name__ == "__main__":
    sys.exit(main())
