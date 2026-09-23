#!/usr/bin/env python3
"""
datascan.py -- audits tools/disasm.py's code/data split for arm9_main,
looking for function-shaped code that the classifier filed as data.

Written from scratch, reusing only tools/disasm.py's own building blocks
(Region, Analyser, load_layout, build_arm9_regions, index_hidden_pool_words):
no new decoder, no new classification policy. The question this tool
answers is narrower than disasm.py's own analysis: given the classification
disasm.py already settled on, are there byte runs it emitted as
``.word``/``.byte`` that still look like a function if you test them
against the same prologue-plus-return shape the prologue sweep uses, once
you stop asking whether disasm.py's own trace happened to reach them?

Why this can find something disasm.py's own prologue sweep did not
--------------------------------------------------------------------
``Analyser.sweep_prologues()`` only tests bytes that are still ``UNK`` at
the time it runs (``if r.kind[off] != UNK: continue``); it exists inside
the same fixed-point loop as literal-pool reservation. A byte that a
PC-relative load elsewhere reserved as a pool word (``_reserve_pool``)
turns ``DATA`` before the sweep ever looks at it, and a whole aligned
width -- not just the four bytes the load actually needs -- can be
claimed that way. If a real function prologue happens to sit inside (or
right after) a run that got claimed for an unrelated reason, the sweep
never gets a chance to test it. This tool re-tests every byte of every
data run disasm.py produced, independent of *why* it is not CODE, against
the same two prologue shapes ``_has_prologue`` recognises, and decodes
forward on its own (ignoring ``region.kind`` except to recognise a clean
merge into code already traced) to see whether the shape holds up: every
instruction must decode, and the run must reach an unconditional return
within a byte budget, with no undefined instruction in between.

Scope and exclusions
---------------------
Only ``arm9_main`` is scanned (the region worklist.py's denominator
covers). Excluded before any prologue test runs:

  - bytes disasm.py already attributes to some function's own literal
    pool (``region.pools``): those are not unreached bytes, they are a
    function's constants, already accounted for in its own extent;
  - a run that is a pure pointer table: every aligned word in it decodes
    as an address inside the NDS main-RAM range (0x02000000..0x02400000,
    which covers arm9_main, every autoload and every overlay); a table of
    pointers is data by construction, not a candidate for containing a
    prologue;
  - a run that is a pure string: mostly printable bytes with the shape a
    NUL-terminated (or unterminated, table-packed) text blob has.

For each byte left over, at every ARM word-aligned and Thumb halfword-
aligned offset, this checks:

  - ARM ``stmfd sp!, {..., lr}`` / ``str lr, [sp, #-4]!`` (the same two
    words ``Analyser._has_prologue`` recognises for ARM);
  - Thumb ``push {..., lr}`` at a halfword-aligned offset (the same
    ``_has_prologue`` check for Thumb);
  - a decode that reaches an unconditional return (``bx lr``, ``pop {...,
    pc}``, ``ldm ... pc``, ``mov pc, lr``, etc., via the same
    ``Analyser._is_return`` rule disasm.py's own tracer uses) within
    4096 bytes, with every intermediate instruction decoding cleanly and
    every intermediate unconditional branch staying inside the region.

It also looks for the other shape a real seed round has to add by hand
(see layout/function_starts.txt and its many "no lr-saving prologue"
entries): a Thumb leaf with no push at all, ending in an unconditional
return within 64 bytes, whose start address is the target of some bl/blx
found anywhere in the region's own trace, or the value of some pool word
anywhere in the region. A leaf with neither kind of witness is not
reported: nothing yet says its start address is a function's start rather
than an arbitrary point inside a run of constants that happens to decode.

Evidence
--------
Each hit is scored, not just listed:

  - ``bl_to_labelled``: true when some instruction inside the candidate's
    decoded run is a bl/blx whose target is already a labelled func_/loc_
    in this region -- the candidate calls something disasm.py already
    trusts, which is the same kind of evidence a real seed carries.
  - ``called_from``: true when the candidate's own start address is the
    target of a bl/blx traced anywhere in the region -- direct call-site
    evidence, the strongest kind (this is exactly what
    ``layout/function_starts.txt`` requires of every entry it adds).
  - ``pointed_from_pool``: true when some pool word's *value* anywhere in
    the region equals the candidate's start address (thumb bit stripped)
    -- a function-pointer table entry, the second evidence class
    ``layout/function_starts.txt`` accepts.
  - ``is_pool_site``: true when the candidate's own start address is
    itself a site disasm.py recorded a literal-pool reservation at
    (``region.pools``), i.e. some other traced instruction's PC-relative
    load reads *these very bytes* back as a plain data word. This is
    self-contradictory for a function start (nothing loads its own
    opcodes as a constant) and marks the hit as data wearing a
    prologue's clothes rather than code: reported, but never counted as
    strong evidence.

A hit counts as STRONG evidence when ``called_from`` or
``pointed_from_pool`` is true and ``is_pool_site`` is false. Everything
else that still passed the decode test is WEAK: a byte pattern that
happens to look like a function with nothing outside it saying so, which
is exactly the class the prologue sweep is deliberately narrow to avoid
manufacturing (see disasm.py's module docstring, step 4).

Usage
-----
    python tools/datascan.py                    write layout/datascan_report.txt
    python tools/datascan.py --out PATH          write somewhere else
    python tools/datascan.py --quiet             suppress the progress summary

Nothing here writes to layout/function_starts.txt, src/ or asm/: this is a
read-only audit. Promoting a hit into function_starts.txt is a decision
for a human (or a lane) to make per docs/HANDOFF.md's process, citing the
call site or pool word this tool already found, exactly as every existing
entry in that file does.
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import disasm  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LAYOUT_DIR = os.path.join(ROOT, "layout")
EXTRACT_DIR = os.path.join(ROOT, "extract")
OUT_PATH = os.path.join(LAYOUT_DIR, "datascan_report.txt")

# NDS main RAM: arm9_main, every autoload and every overlay all live here.
# A run whose every aligned word falls in this range, with nothing further
# to say about it, is a pointer table by construction.
RAM_LO, RAM_HI = 0x02000000, 0x02400000

MAX_PROLOGUE_BYTES = 4096       # "within 4 KB" for a pushed/stmfd candidate
MAX_LEAF_BYTES = 64             # "within 64 bytes" for a no-push leaf


# ---------------------------------------------------------------------------
# building the classified region
# ---------------------------------------------------------------------------

def build_main_region():
    """The arm9_main Region, classified exactly as a real disasm.py run would."""
    layout = disasm.load_layout(LAYOUT_DIR)
    regions = disasm.build_arm9_regions(layout, EXTRACT_DIR, LAYOUT_DIR)
    for r in regions:
        disasm.Analyser(r).run()
    for r in regions:
        disasm.index_hidden_pool_words(r, regions)
    main = next(r for r in regions if r.name == "arm9_main")
    return main


# ---------------------------------------------------------------------------
# data runs and their exclusions
# ---------------------------------------------------------------------------

def data_runs(region):
    """[(start_off, end_off)] over every contiguous span disasm.py did not
    classify CODE -- exactly the bytes a real run would emit as .word/.byte."""
    k = region.kind
    n = len(k)
    runs = []
    i = 0
    while i < n:
        if k[i] == disasm.CODE:
            i += 1
            continue
        j = i
        while j < n and k[j] != disasm.CODE:
            j += 1
        runs.append((i, j))
        i = j
    return runs


def is_pool_owned(region, start_off, end_off):
    """True when every byte of the run is a pool word disasm.py already
    attributed to some function's own literal pool."""
    addr = region.base + start_off
    end = region.base + end_off
    a = addr
    while a < end:
        w = region.pools.get(a)
        if w is None:
            return False
        a += w
    return a == end


def looks_like_pointer_table(region, start_off, end_off):
    span = end_off - start_off
    if span < 4 or span % 4 != 0 or (region.base + start_off) % 4 != 0:
        return False
    for off in range(start_off, end_off, 4):
        val = struct.unpack_from("<I", region.data, off)[0]
        if not (RAM_LO <= val < RAM_HI):
            return False
    return True


def looks_like_string(region, start_off, end_off):
    buf = region.data[start_off:end_off]
    if len(buf) < 4:
        return False
    printable = sum(1 for b in buf if 0x20 <= b < 0x7F or b in (0, 9, 10, 13))
    nonzero = sum(1 for b in buf if b != 0)
    if nonzero == 0:
        return False
    return printable == len(buf) and (buf.count(0) / len(buf)) < 0.5


def excluded_reason(region, start_off, end_off):
    if is_pool_owned(region, start_off, end_off):
        return "pool"
    if looks_like_pointer_table(region, start_off, end_off):
        return "pointer_table"
    if looks_like_string(region, start_off, end_off):
        return "string"
    return None


# ---------------------------------------------------------------------------
# cross-region witness sets: bl/blx targets and pool-word values
# ---------------------------------------------------------------------------

def call_targets(region):
    """{addr} for every bl/blx target this region's own trace recorded."""
    out = set()
    for rec in region.insns.values():
        mnem = rec.text.split("\t", 1)[0].split(".")[0]
        if mnem not in disasm.CALL_MNEMONICS:
            continue
        parts = rec.text.split("\t", 1)
        if len(parts) != 2 or not parts[1].startswith("#"):
            continue
        try:
            out.add(int(parts[1][1:], 0))
        except ValueError:
            continue
    return out


def pool_pointer_targets(region):
    """{addr} (thumb bit stripped) for every value a traced pool word holds."""
    out = set()
    for paddr in region.pools:
        val = region.word(paddr)
        if val is not None:
            out.add(val & ~1)
    return out


# ---------------------------------------------------------------------------
# independent decode: ignores region.kind except to recognise a clean merge
# ---------------------------------------------------------------------------

def trace_shape(an, region, addr, thumb, max_bytes):
    """Decode forward from addr on its own terms.

    Returns (length_bytes, bl_to_labelled) on a clean run to an
    unconditional return (or a merge into already-traced code of the same
    mode), or None if any instruction fails to decode, an unconditional
    branch leaves the region, or the byte budget is exceeded.
    """
    r = region
    a = addr
    total = 0
    bl_to_labelled = False
    first = True
    while total < max_bytes:
        if not r.contains(a):
            return None
        o = r.off(a)
        if not first and r.kind[o] == disasm.CODE and r.mode_at.get(o) == thumb:
            return total, bl_to_labelled
        insn = an._decode(a, thumb)
        if insn is None or insn.size == 0:
            return None
        first = False
        mnem = insn.mnemonic.split(".")[0]
        uncond = (insn.cc == disasm.CC_AL or insn.cc == 0)
        if mnem in disasm.CALL_MNEMONICS:
            tgt = an._branch_target(insn)
            if tgt is not None and (tgt in r.funcs or tgt in r.locs):
                bl_to_labelled = True
        if an._is_return(insn) and uncond:
            total += insn.size
            return total, bl_to_labelled
        if mnem in disasm.BRANCH_MNEMONICS and uncond:
            tgt = an._branch_target(insn)
            if tgt is None or not r.contains(tgt):
                return None
            total += insn.size
            a = tgt
            continue
        total += insn.size
        a += insn.size
    return None


# ---------------------------------------------------------------------------
# candidate scan
# ---------------------------------------------------------------------------

class Hit:
    __slots__ = ("addr", "thumb", "leaf", "length", "bl_to_labelled",
                 "called_from", "pointed_from_pool", "is_pool_site")

    def evidence(self):
        if self.is_pool_site:
            return "contradicted"
        if self.called_from or self.pointed_from_pool:
            return "strong"
        return "weak"


def scan_run(an, region, start_off, end_off, calls, pool_vals):
    hits = []
    base = region.base

    for off in range(start_off, max(start_off, end_off - 7)):
        addr = base + off
        if addr % 4 == 0 and an._has_prologue(off, False):
            result = trace_shape(an, region, addr, False, MAX_PROLOGUE_BYTES)
            if result is not None:
                hits.append(make_hit(region, addr, False, result, False,
                                     calls, pool_vals))
        if addr % 2 == 0 and an._has_prologue(off, True):
            result = trace_shape(an, region, addr, True, MAX_PROLOGUE_BYTES)
            if result is not None:
                hits.append(make_hit(region, addr, True, result, False,
                                     calls, pool_vals))

    # no-push Thumb leaves: only reported when something outside already
    # points at the address, exactly as layout/function_starts.txt requires.
    for off in range(start_off, end_off):
        addr = base + off
        if addr % 2 != 0:
            continue
        if addr not in calls and addr not in pool_vals:
            continue
        if an._has_prologue(off, True):
            continue  # already covered by the push scan above
        result = trace_shape(an, region, addr, True, MAX_LEAF_BYTES)
        if result is not None:
            hits.append(make_hit(region, addr, True, result, True,
                                 calls, pool_vals))
    return hits


def make_hit(region, addr, thumb, result, leaf, calls, pool_vals):
    length, bl_to_labelled = result
    h = Hit()
    h.addr = addr
    h.thumb = thumb
    h.leaf = leaf
    h.length = length
    h.bl_to_labelled = bl_to_labelled
    h.called_from = addr in calls
    h.pointed_from_pool = addr in pool_vals
    h.is_pool_site = addr in region.pools
    return h


def run_scan(region):
    calls = call_targets(region)
    pool_vals = pool_pointer_targets(region)
    an = disasm.Analyser(region)

    hits = []
    excluded = {"pool": 0, "pointer_table": 0, "string": 0}
    excluded_bytes = {"pool": 0, "pointer_table": 0, "string": 0}
    scanned_bytes = 0
    total_data_bytes = 0

    for start_off, end_off in data_runs(region):
        span = end_off - start_off
        total_data_bytes += span
        reason = excluded_reason(region, start_off, end_off)
        if reason is not None:
            excluded[reason] += 1
            excluded_bytes[reason] += span
            continue
        scanned_bytes += span
        hits.extend(scan_run(an, region, start_off, end_off, calls, pool_vals))

    # de-duplicate: the same start address can validate under both scans
    # only if _has_prologue matched in one mode; keep the longest decode.
    by_addr = {}
    for h in hits:
        key = (h.addr, h.thumb)
        if key not in by_addr or h.length > by_addr[key].length:
            by_addr[key] = h
    hits = sorted(by_addr.values(), key=lambda h: h.addr)

    return {
        "hits": hits,
        "total_data_bytes": total_data_bytes,
        "scanned_bytes": scanned_bytes,
        "excluded": excluded,
        "excluded_bytes": excluded_bytes,
    }


# ---------------------------------------------------------------------------
# the two known bugs
# ---------------------------------------------------------------------------

def check_known_bugs(region):
    lines = []

    # (1) pools printed as Thumb: 0x02010B84..97 and 0x02010D84..97.
    for lo, hi in ((0x02010B84, 0x02010B98), (0x02010D84, 0x02010D98)):
        off_lo, off_hi = region.off(lo), region.off(hi)
        kinds = set(region.kind[off_lo:off_hi])
        pool_sites = [a for a in range(lo, hi, 4) if a in region.pools]
        lines.append(
            "0x%08X..0x%08X: kind bytes = %s; pool-reserved words at %s"
            % (lo, hi,
               ",".join(sorted({"CODE" if k == disasm.CODE else
                                 "DATA" if k == disasm.DATA else "UNK"
                                 for k in kinds})),
               ", ".join("0x%08X" % a for a in pool_sites) or "none"))

    # (2) the mcss.c three-row function 0x02014D2C..0x020155A0.
    lo, hi = 0x02014D2C, 0x020155A0
    rows = sorted(a for a in region.funcs if lo <= a < hi)
    lines.append(
        "0x%08X..0x%08X: %d func_ label(s) inside the range that should be "
        "one entry: %s"
        % (lo, hi, len(rows), ", ".join("0x%08X" % a for a in rows)))
    return lines


# ---------------------------------------------------------------------------
# report
# ---------------------------------------------------------------------------

DENOMINATOR = 393066  # tools/worklist.py --summary, code_bytes_game, 2026-09-23


def write_report(region, scan, bug_lines, out_path):
    hits = scan["hits"]
    strong = [h for h in hits if h.evidence() == "strong"]
    weak = [h for h in hits if h.evidence() == "weak"]
    contradicted = [h for h in hits if h.evidence() == "contradicted"]

    strong_bytes = sum(h.length for h in strong)
    weak_bytes = sum(h.length for h in weak)

    ranked = sorted(
        hits,
        key=lambda h: (h.evidence() != "strong", h.evidence() == "contradicted",
                       -h.length),
    )

    lines = []
    add = lines.append
    add("# layout/datascan_report.txt -- tools/datascan.py output")
    add("# addresses and sizes only, no game bytes; regenerate with:")
    add("#   python tools/datascan.py")
    add("")
    add("region arm9_main  base 0x%08X  size 0x%X (%d) bytes"
        % (region.base, len(region.data), len(region.data)))
    add("data bytes (kind != CODE): %d" % scan["total_data_bytes"])
    add("  excluded as pool-owned:     %6d bytes over %d run(s)"
        % (scan["excluded_bytes"]["pool"], scan["excluded"]["pool"]))
    add("  excluded as pointer table:  %6d bytes over %d run(s)"
        % (scan["excluded_bytes"]["pointer_table"], scan["excluded"]["pointer_table"]))
    add("  excluded as string:         %6d bytes over %d run(s)"
        % (scan["excluded_bytes"]["string"], scan["excluded"]["string"]))
    add("  scanned for a function shape: %d bytes" % scan["scanned_bytes"])
    add("")
    add("candidates found: %d  (strong %d, weak %d, contradicted %d)"
        % (len(hits), len(strong), len(weak), len(contradicted)))
    add("candidate bytes:  strong %d, weak %d, contradicted %d"
        % (strong_bytes, weak_bytes, sum(h.length for h in contradicted)))
    add("")
    add("comparison to the game-code denominator (tools/worklist.py --summary, "
        "code_bytes_game = %d):" % DENOMINATOR)
    add("  strong-evidence candidate bytes are %d (%.4f%% of the denominator);"
        % (strong_bytes, 100.0 * strong_bytes / DENOMINATOR))
    add("  weak-evidence candidate bytes (decode-only, no outside witness) "
        "are %d (%.4f%%)." % (weak_bytes, 100.0 * weak_bytes / DENOMINATOR))
    add("")
    add("ranked candidate list (strong first, then weak, then contradicted; "
        "longest decode first within each class)")
    add("%-12s %-5s %6s  %-4s  %-12s %-11s %-16s %-6s"
        % ("address", "isa", "bytes", "leaf", "evidence", "called_from",
           "pointed_from_pool", "is_pool_site"))
    for h in ranked:
        add("0x%08X  %-5s %6d  %-4s  %-12s %-11s %-16s %-6s"
            % (h.addr, "thumb" if h.thumb else "arm", h.length,
               "yes" if h.leaf else "no", h.evidence(),
               "yes" if h.called_from else "no",
               "yes" if h.pointed_from_pool else "no",
               "yes" if h.is_pool_site else "no"))
    add("")
    add("known-bug cross-check")
    for ln in bug_lines:
        add("  " + ln)
    add("")

    with open(out_path, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("\n".join(lines) + "\n")

    return strong_bytes, weak_bytes, ranked


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[1])
    ap.add_argument("--out", default=OUT_PATH, help="report output path")
    ap.add_argument("--quiet", action="store_true", help="suppress the summary")
    args = ap.parse_args(argv)

    region = build_main_region()
    scan = run_scan(region)
    bug_lines = check_known_bugs(region)
    strong_bytes, weak_bytes, ranked = write_report(region, scan, bug_lines, args.out)

    if not args.quiet:
        print("wrote %s" % os.path.relpath(args.out, ROOT))
        print("candidates: %d (strong %d bytes, weak %d bytes)"
              % (len(ranked), strong_bytes, weak_bytes))
        print("denominator (worklist.py --summary code_bytes_game): %d"
              % DENOMINATOR)
    return 0


if __name__ == "__main__":
    sys.exit(main())
