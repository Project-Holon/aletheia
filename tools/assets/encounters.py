#!/usr/bin/env python3
"""
encounters.py -- decoder for the wild encounter table archive `a/1/2/6`,
112 sub-files, tied to the zone table (`a/0/1/2`, see zones.py) through
the zone record's `packed_1a` lane (record offset +0x1a, low 10 bits).

Written from scratch for the aletheia asset lane. Stdlib only.

--------------------------------------------------------------------------
How the archive was found
--------------------------------------------------------------------------
This pass tested a shape hypothesis against every archive under
`extract/data/a` (235 files, same set zones.py's `--survey` walks): a
small header of per-method encounter rate bytes, followed by slots of
{u16 species-and-form, u8 min level, u8 max level}, species below 650
(masked by 0x7FF) and min <= max <= 100. `a/1/2/6` is the only archive
that fits this shape at a single header length across (effectively) all
its sub-files; several other archives surfaced in a first coarse scan
that allowed any header length 0-19 and treated bare zero slots as a
free pass (`a/0/1/9`, `a/0/2/4`, `a/1/6/9`, `a/2/1/4`, ...), but none of
them has `a/1/2/6`'s distinctive two-tier sub-file size (100 sub-files at
232 bytes, 12 at 928 bytes, both exact multiples of a 232-byte block) or
its semantic content (see below); they are ordinary fixed-stride record
tables for other data and are not revisited here.

--------------------------------------------------------------------------
Block layout (232 bytes)
--------------------------------------------------------------------------
    +0x00  u8 x 7   method rates, in slot order below (grass, double
                    grass, shaking grass, surf, rippling water, fishing,
                    rippling fishing)
    +0x07  u8       pad (unread by every check in this module; always
                    present so the header is 8 bytes, keeping the body
                    4-byte aligned)
    +0x08  56 x {u16 species_and_form, u8 min_level, u8 max_level}
                    one slot per 4 bytes, in method order:

        slot range   count   method
        0..11        12      grass
        12..23       12      double grass
        24..35       12      shaking grass
        36..40        5      surf
        41..45        5      rippling water
        46..50        5      fishing
        51..55        5      rippling fishing

    species_and_form: species id is the low 11 bits (mask 0x7FF, matches
    the mission's "species below 650" bound with room to spare -- the
    archive's real max species value is 633); the remaining 5 high bits
    hold a form id (0-3 observed archive-wide, e.g. Deerling/Shellos-style
    seasonal or regional forms). An all-zero slot (species 0, min 0, max
    0) means "no encounter in this slot" -- 12-slot methods commonly run
    short (trailing zero slots) on routes with fewer than 12 distinct
    grass encounters.

This 12/12/12/5/5/5/5 = 56-slot layout is not assumed, it is what the
sizes force: every sub-file's body (after the 8-byte header, and after
splitting a multi-season sub-file into 232-byte blocks, see below) is
exactly 224 bytes = 56 x 4, with no remainder, and reading it as
grass/double-grass/shaking-grass groups of 12 each followed by four
groups of 5 is the only grouping under which the zero/nonzero boundary
inside a sub-file lines up with a change of method (confirmed below by
the all-grass-zero, water-nonzero winter block and the
Patrat/Lillipup/Purrloin/Audino sanity check, see docs/ASSETS.md).

--------------------------------------------------------------------------
Seasons
--------------------------------------------------------------------------
A sub-file is either exactly 232 bytes (one block, no seasonal
variation -- the same table applies all year, the common case: 100/112
sub-files) or exactly 928 bytes = 4 x 232 (four concatenated blocks, one
per season, in order: 12/112 sub-files, all on outdoor overworld zones).
No sub-file has any other size. The season order is not separately
attested by any code traced in this lane; it is reported here as
block 0..3 in file order, and this module does not assert which block is
which real-world season. Block 3 is not uniform across the 12 seasonal
sub-files: in 3 of the 12 its grass/double-grass/shaking-grass slots are
all empty while blocks 0-2 have real grass data (consistent with a
snow-covered season on those routes), in most of the rest all four
blocks carry the same grass slot count, and on one sub-file block 3 has
more grass slots filled than blocks 0-2. That spread (not a fixed
"block 3 always differs this way") is reported as-is rather than forced
into a single season story.

--------------------------------------------------------------------------
The zone lane
--------------------------------------------------------------------------
docs/ASSETS.md's zone record (`zones.py`, 48-byte records, `a/0/1/2`)
lists several lanes with no attested meaning. Tested against `a/1/2/6`
(112 sub-files) via the same bounded-range + classifier-correlation
method `zones.py --map-lane-check` already used for the map lane:

    packed_1a, low 10 bits (record +0x1a & 0x3ff): bounded (< 112) on
    406/427 zones, 111 distinct values (one short of the 112 sub-files --
    one sub-file, #3, is unreferenced by this lane on this sample), and
    the classifier split is sharp: zones whose resolved map is
    house-prefixed use only 3 distinct indices, zones whose resolved map
    is an outdoor overworld model use 66 distinct indices, and the two
    sets overlap on only 2 of those values. No other numeric lane in the
    record (field_00, field_01, field_02, field_14, field_18, field_20,
    the other packed_1a half, any packed_1c slice, any flags bit range)
    gets close: most either fail the bounded-range test outright or show
    no house/outdoor split at all (see docs/ASSETS.md for the per-lane
    table this reproduces).

    Direct confirmation, not just the statistical split: zone ids 290,
    291, 292 (three consecutive zones, all matrix_id 175, one of the two
    overworld halves) index packed_1a values 77, 78, 79 -- three
    consecutive sub-files. Sub-file 78's grass slots are Patrat (504),
    Lillipup (506) and Purrloin (509) at levels 4-7, and its shaking-grass
    slots are Audino (531) at levels 4-7: an early-route species set at
    the mission's predicted low levels, sitting on a lane whose three
    adjacent values line up with three adjacent zones on the overworld.
    That is the pairing this module resolves `--zone` through.

21 zones land outside 0..111 on this lane (index 112-116); those are not
resolved by `--zone` (treated as "no encounter table"), consistent with
most of them being interiors that have no wild encounters at all rather
than a 113th sub-file that does not exist.

--------------------------------------------------------------------------
CLI
--------------------------------------------------------------------------
    python tools/assets/encounters.py --list
        Per sub-file: index, size, block count (1 or 4), and per block
        the 7 method rates plus every non-empty slot's species/form and
        level range.

    python tools/assets/encounters.py --zone N
        Resolve zone N through its packed_1a lane into an a/1/2/6
        sub-file (or report "no encounter table" if the lane is out of
        range) and print it the same way --list does for one sub-file.

    python tools/assets/encounters.py --verify
        Re-pack every sub-file (every block, rates + slots) from parsed
        fields and compare byte-for-byte against the original.
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402

A126_PATH = os.path.join("extract", "data", "a", "1", "2", "6")

BLOCK_SIZE = 232
HEADER_SIZE = 8
N_RATES = 7
SLOT_SIZE = 4
N_SLOTS = 56

METHODS = [
    ("grass", 0, 12),
    ("double_grass", 12, 12),
    ("shaking_grass", 24, 12),
    ("surf", 36, 5),
    ("rippling_water", 41, 5),
    ("fishing", 46, 5),
    ("rippling_fishing", 51, 5),
]

SPECIES_MASK = 0x7FF
FORM_SHIFT = 11

ZONE_LANE_MASK = 0x3FF  # packed_1a bits 0-9


class EncountersError(Exception):
    pass


def load_archive():
    return narc.parse_file(A126_PATH)


# ---------------------------------------------------------------------------
# Parsing / packing
# ---------------------------------------------------------------------------

def parse_slot(raw, off):
    species_and_form, mn, mx = struct.unpack_from("<HBB", raw, off)
    return {
        "species": species_and_form & SPECIES_MASK,
        "form": species_and_form >> FORM_SHIFT,
        "min_level": mn,
        "max_level": mx,
    }


def pack_slot(slot):
    species_and_form = (slot["species"] & SPECIES_MASK) | (
        (slot["form"] << FORM_SHIFT) & 0xFFFF)
    return struct.pack("<HBB", species_and_form, slot["min_level"], slot["max_level"])


def parse_block(raw, base=0):
    rates = list(raw[base:base + N_RATES])
    pad = raw[base + N_RATES]
    methods = {}
    for name, start, count in METHODS:
        slots = [parse_slot(raw, base + HEADER_SIZE + SLOT_SIZE * (start + i))
                  for i in range(count)]
        methods[name] = slots
    return {"rates": rates, "pad": pad, "methods": methods}


def pack_block(block):
    out = bytearray(bytes(block["rates"]) + bytes([block["pad"]]))
    for name, start, count in METHODS:
        slots = block["methods"][name]
        if len(slots) != count:
            raise EncountersError(
                f"method {name} has {len(slots)} slots, expected {count}")
        for slot in slots:
            out += pack_slot(slot)
    if len(out) != BLOCK_SIZE:
        raise EncountersError(f"packed block is {len(out)} bytes, expected {BLOCK_SIZE}")
    return bytes(out)


def parse_table(raw, index):
    if len(raw) % BLOCK_SIZE != 0:
        raise EncountersError(
            f"sub-file {index}: size {len(raw)} is not a multiple of {BLOCK_SIZE}")
    n_blocks = len(raw) // BLOCK_SIZE
    if n_blocks not in (1, 4):
        raise EncountersError(
            f"sub-file {index}: {n_blocks} blocks, expected 1 or 4")
    blocks = [parse_block(raw, b * BLOCK_SIZE) for b in range(n_blocks)]
    return {"index": index, "n_blocks": n_blocks, "blocks": blocks}


def pack_table(table):
    return b"".join(pack_block(b) for b in table["blocks"])


def load_all(a126=None):
    a126 = a126 or load_archive()
    return [parse_table(a126.read(i), i) for i in range(a126.file_count)]


# ---------------------------------------------------------------------------
# Zone resolution
# ---------------------------------------------------------------------------

def zone_encounter_index(record):
    """Return record's packed_1a-derived a/1/2/6 index, or None if it
    does not land inside the archive (see module docstring: 21/427
    zones fall outside 0..111 on this lane, treated as no table)."""
    idx = record["packed_1a"] & ZONE_LANE_MASK
    return idx


def resolve_zone_table(record, a126_file_count):
    idx = zone_encounter_index(record)
    if 0 <= idx < a126_file_count:
        return idx
    return None


# ---------------------------------------------------------------------------
# Printing
# ---------------------------------------------------------------------------

def _format_table(table):
    lines = [f"sub-file {table['index']}: {table['n_blocks']} block(s)"]
    for b, block in enumerate(table["blocks"]):
        lines.append(f"  block {b}: rates(grass,dgrass,sgrass,surf,ripple_surf,"
                      f"fish,ripple_fish)={block['rates']} pad={block['pad']}")
        for name, start, count in METHODS:
            slots = block["methods"][name]
            nonempty = [(i, s) for i, s in enumerate(slots)
                        if s["species"] or s["min_level"] or s["max_level"]]
            if not nonempty:
                lines.append(f"    {name}: (empty)")
                continue
            parts = []
            for i, s in nonempty:
                form_str = f"/form{s['form']}" if s["form"] else ""
                parts.append(f"#{s['species']}{form_str}"
                              f"(Lv{s['min_level']}-{s['max_level']})")
            lines.append(f"    {name}: " + ", ".join(parts))
    return "\n".join(lines)


def cmd_list(args):
    a126 = load_archive()
    print(f"a/1/2/6: {a126.file_count} sub-files")
    for i in range(a126.file_count):
        table = parse_table(a126.read(i), i)
        print(_format_table(table))


def cmd_zone(args):
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import zones as zonesmod  # noqa: E402

    raw = zonesmod.load_table()
    records = zonesmod.parse_table(raw)
    if not (0 <= args.zone < len(records)):
        raise EncountersError(
            f"zone {args.zone} out of range (0..{len(records) - 1})")
    record = records[args.zone]
    a126 = load_archive()
    idx = resolve_zone_table(record, a126.file_count)
    lane_raw = zone_encounter_index(record)
    print(f"zone {args.zone}: packed_1a=0x{record['packed_1a']:04x} "
          f"lane_value={lane_raw}")
    if idx is None:
        print("  no encounter table (lane value out of range for a/1/2/6)")
        return
    table = parse_table(a126.read(idx), idx)
    print(_format_table(table))


# ---------------------------------------------------------------------------
# --verify
# ---------------------------------------------------------------------------

def cmd_verify(args):
    a126 = load_archive()
    ok = fail = 0
    for i in range(a126.file_count):
        raw = a126.read(i)
        try:
            table = parse_table(raw, i)
        except EncountersError as exc:
            print(f"  sub-file {i}: parse error: {exc}", file=sys.stderr)
            fail += 1
            continue
        repacked = pack_table(table)
        if repacked == raw:
            ok += 1
        else:
            fail += 1
            print(f"  sub-file {i}: round-trip MISMATCH "
                  f"(orig {len(raw)} bytes, repacked {len(repacked)} bytes)",
                  file=sys.stderr)
    print(f"a/1/2/6: {ok}/{a126.file_count} sub-files round-trip byte-identical "
          f"({fail} failed)")
    return 0 if fail == 0 else 1


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group()
    g.add_argument("--list", action="store_true",
                    help="print every sub-file's rates and slots")
    g.add_argument("--zone", type=int, metavar="N",
                    help="resolve zone N through the packed_1a lane and print "
                         "its encounter table")
    g.add_argument("--verify", action="store_true",
                    help="byte-identical repack check")
    args = ap.parse_args(argv)

    try:
        if args.zone is not None:
            cmd_zone(args)
        elif args.verify:
            return cmd_verify(args) or 0
        else:
            cmd_list(args)
    except EncountersError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2
    return 0


if __name__ == "__main__":
    sys.exit(main())
