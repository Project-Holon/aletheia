#!/usr/bin/env python3
"""
zones.py -- decoder for the zone header table: sub-file 0 of `a/0/1/2`,
427 records of 48 bytes, one record per zone id.

Written from scratch for aletheia. Stdlib only.

This is a rewrite of an earlier version of this module that only reported
a NARC-wide survey and a code lead, without a confirmed table (see the
"Zone table hunt" section of docs/ASSETS.md for that history). The table
has since been located by code, not by a stride scan: docs/ASSETS.md,
"Zone header table located by code", walks the decompiled path from
`func_020139B0` (`src/pending/func_020139B0.c`) through `sub_02013AD0`
(`src/matched/unit_02013AD0.c`) to the 48-byte-stride random-access read,
and the per-field accessors are `sub_02013Bxx`/`sub_02013Cxx`/
`sub_02013Dxx`/`sub_02013Exx`/`sub_02013Fxx` (see the field map below and
in ASSETS.md) plus the indexed array reader `func_02013BDC`
(`src/matched/func_02013BDC.c`). The id substitution hook is
`sub_02013A94` (`src/pending/sub_02013A94.c`). This module does not
re-derive any of that from scratch; it only decodes the bytes the way
those accessors already prove they are decoded.

Address-base note carried over from ASSETS.md: `extract/arm9_dec.bin`
loads at ARM9 address 0x02004000, not 0x02000000 -- any tool that turns a
file offset in that blob into an ARM9 address (or vice versa) needs that
0x4000 bias, which is why an earlier pass "found nothing" scanning near
0x020a2500 for a table that is actually installed from 0x020054FA/
0x020055FA.

--------------------------------------------------------------------------
Record layout (48 bytes, offsets from the record start)
--------------------------------------------------------------------------
Only lanes docs/ASSETS.md attests a name for are named below; everything
else is labelled by its offset, per the field-map table in that section:

    0x00  u8      field_00
    0x01  u8      field_01
    0x02  u16     field_02
    0x04  u16     field_04           grouping key (func_02013E90 treats
                                      0 and 0xaf as one group)
    0x06  u16     field_06           even half of the +0x06/+0x08 pair
    0x08  u16     field_08           == field_06 + 1 on every record;
                                      no accessor of its own
    0x0a  u16     script_id          script lane, max 468 < a/0/0/3's 472
    0x0c  u16[4]  conn               one array of four, func_02013BDC
                                      index 0..3, 0 for any other index
    0x14  u16     field_14
    0x16  u16     zone_perm          bijection onto 0..426 (a permutation
                                      of the zone ids themselves)
    0x18  u16     field_18
    0x1a  u16     packed_1a          two packed lanes, bits 0-9 / 10-15
    0x1c  u16     packed_1c          three packed lanes, bits 0-5 / 6-8 /
                                      9-15
    0x1e  u16     flags              flag word, seven packed bit lanes
                                      (bits 0-4, 5-9, 10, 12, 13, 14, 15;
                                      bit 11 unused)
    0x20  u16     field_20
    0x22  u16     reserved_22        zero on all 427 records
    0x24  s32     fx_24              sub_02013B74 returns it shifted left
                                      16, i.e. plain int stored, Fx32 on
                                      read
    0x28  s32     fx_28              same reader pair as fx_24
    0x2c  s32     fx_2c              same reader pair as fx_24

`fx_24`/`fx_28`/`fx_2c` being 32-bit is also why their own upper
halfwords (bytes 0x26, 0x2a, 0x2e) are zero on every record: those are
not separate fields, just the high 16 bits of an always-small int.

--------------------------------------------------------------------------
The map-lane question (this pass's main result)
--------------------------------------------------------------------------
docs/ASSETS.md already ruled out +0x02 and +0x04 as attested map-model
lanes (numerically plausible against a/0/0/8's 649 and a/0/0/9's 255
sub-file counts, but not attested by any accessor in range, and
`func_02013E90` reads +0x04 as a grouping/equivalence key, not an index).
This pass tests every other numeric candidate the mission asked about,
computationally, against `extract/data/a/0/0/8` (649 sub-files):

  +0x06 / +0x08 (raw, no offset): only 325/427 and 324/427 records land
      under 649 at all -- most of the archive-wide pair range (0..853,
      2*427 exactly, see ASSETS.md) simply doesn't fit inside a
      649-file archive, offset or not. Tried offsets 0, 204, 205, 206
      (the gap between 854 and 649): none brings the full 427 records
      into 0..648, and the model-name-based indoor/outdoor classifier
      below (see `_classify_a008`) shows no correlation between any
      flags bit and whether the resulting index lands on a
      house-prefixed model, for any offset tried.

  +0x0c/+0x0e/+0x10/+0x12 (the `conn` array) minus 1001 (their observed
      min): bounded under 649 for 426/427 or 427/427 records depending
      on the lane, but zero correlation with any flags bit against the
      indoor/outdoor classifier (score 0.00 -- house-rate identical
      whether the bit is set or clear). The array shape itself argues
      against this being a map lane on structural grounds too: a zone
      has one map, and `func_02013BDC` is documented as the ONLY indexed
      accessor in the whole subsystem, selecting one of four values by a
      caller-supplied 0..3 argument -- the shape a set of directional
      neighbour pointers takes, not a single map-model index. 381/427
      records also have all four array slots equal, which is a strange
      pattern for four independent map pointers but an ordinary one for
      four neighbour slots that mostly recheck the same zone.

  The three side tables named in the mission (`a/0/8/1` sub-file 13,
  `a/0/8/2` sub-file 1, `a/1/4/9` sub-file 0): read directly, their
  value ranges are 0..12 (26 entries), empty (0 entries, the loop is
  never entered in this build, see ASSETS.md), and 0..1 (8 entries).
  None of those ranges can index a 649-file archive; ruled out on value
  range alone, no correlation test needed.

  The script lane, by contrast, DOES pass its test: +0x0a is checked
  against `a/0/0/3` (`tools/assets/events.parse_0003`) and every one of
  the 427 referenced sub-files parses without error (427/427).

Net result: this pass adds three more ruled-out candidates (+0x06/+0x08
with four different offsets, the conn array, and all three side tables)
to the two already ruled out in ASSETS.md (+0x02, +0x04), and confirms
+0x0a as the script lane. No lane in the 48-byte record is the map
lane; see docs/ASSETS.md's new "Zone header table decoder" section for
the numbers this module reproduces.

--------------------------------------------------------------------------
NARC survey fix (--survey)
--------------------------------------------------------------------------
The earlier version of this module's survey only considered NARCs with
100-1000 sub-files (treating each sub-file as one record). That method
structurally cannot find `a/0/1/2`: it has exactly ONE sub-file (the
whole 427-record table lives inside that single sub-file as a flat
byte blob), so it reads as a 1-file archive to a sub-file-count survey
and gets filed away, which is exactly what happened (see ASSETS.md).
`--survey` here re-runs the archive-wide scan with that gap fixed: it
also treats every single-sub-file NARC's blob as a candidate record
array, and reports one whose size divides evenly by a stride in
[16, 64] with a plausible record count.

--------------------------------------------------------------------------
CLI
--------------------------------------------------------------------------
    python tools/assets/zones.py --list
        Print all 427 records with the field map above. Record +0x04 is
        printed as `matrix_id` (see docs/ASSETS.md, "Zone to map model
        SOLVED" and tools/assets/matrix.py); add --resolve to also print
        each zone's resolved a/0/0/8 map ids.

    python tools/assets/zones.py --resolve-summary
        Count zones resolving to exactly one map file (houses/interiors)
        vs several (overworld chunks on the two mode-1 matrices).

    python tools/assets/zones.py --stats
        Per-lane min/max/distinct-count/injective, for every lane.

    python tools/assets/zones.py --verify
        Re-pack the table from parsed records and compare byte-for-byte
        against the original. Acceptance bar for the framing above.

    python tools/assets/zones.py --survey
        Re-run the NARC-wide survey with the single-sub-file-blob gap
        fixed (see above).
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import events  # noqa: E402
import narc  # noqa: E402
import matrix as matrixmod  # noqa: E402

A012_PATH = os.path.join("extract", "data", "a", "0", "1", "2")
A008_PATH = os.path.join("extract", "data", "a", "0", "0", "8")
A003_PATH = os.path.join("extract", "data", "a", "0", "0", "3")
DATA_ROOT = os.path.join("extract", "data", "a")

RECORD_COUNT = 427
RECORD_STRIDE = 48

# Field order matches byte offset exactly, so this one format string both
# parses and (via struct.pack with the same tuple order) re-packs a
# record byte-for-byte. See the module docstring for what each name
# means and which ones are attested vs offset-labelled.
FIELDS = [
    ("field_00", "B"),
    ("field_01", "B"),
    ("field_02", "H"),
    ("field_04", "H"),
    ("field_06", "H"),
    ("field_08", "H"),
    ("script_id", "H"),
    ("conn0", "H"),
    ("conn1", "H"),
    ("conn2", "H"),
    ("conn3", "H"),
    ("field_14", "H"),
    ("zone_perm", "H"),
    ("field_18", "H"),
    ("packed_1a", "H"),
    ("packed_1c", "H"),
    ("flags", "H"),
    ("field_20", "H"),
    ("reserved_22", "H"),
    ("fx_24", "i"),
    ("fx_28", "i"),
    ("fx_2c", "i"),
]
RECORD_FMT = "<" + "".join(f for _, f in FIELDS)
assert struct.calcsize(RECORD_FMT) == RECORD_STRIDE


class ZonesError(Exception):
    pass


def load_table():
    n = narc.parse_file(A012_PATH)
    if n.file_count != 1:
        raise ZonesError(f"expected a/0/1/2 to have 1 sub-file, found {n.file_count}")
    raw = n.read(0)
    if len(raw) != RECORD_COUNT * RECORD_STRIDE:
        raise ZonesError(
            f"a/0/1/2 sub-file 0 is {len(raw)} bytes, expected "
            f"{RECORD_COUNT * RECORD_STRIDE} ({RECORD_COUNT} * {RECORD_STRIDE})")
    return raw


def parse_record(raw, zone_id):
    off = zone_id * RECORD_STRIDE
    vals = struct.unpack_from(RECORD_FMT, raw, off)
    rec = dict(zip((name for name, _ in FIELDS), vals))
    rec["zone_id"] = zone_id
    return rec


def parse_table(raw):
    return [parse_record(raw, i) for i in range(RECORD_COUNT)]


def pack_record(rec):
    vals = tuple(rec[name] for name, _ in FIELDS)
    return struct.pack(RECORD_FMT, *vals)


def pack_table(records):
    return b"".join(pack_record(r) for r in records)


# ---------------------------------------------------------------------------
# --list
# ---------------------------------------------------------------------------

def unpack_1a(v):
    return {"bits0_9": v & 0x3FF, "bits10_15": (v >> 10) & 0x3F}


def unpack_1c(v):
    return {"bits0_5": v & 0x3F, "bits6_8": (v >> 6) & 0x7, "bits9_15": (v >> 9) & 0x7F}


def unpack_flags(v):
    return {
        "bits0_4": v & 0x1F,
        "bits5_9": (v >> 5) & 0x1F,
        "bit10": (v >> 10) & 1,
        "bit12": (v >> 12) & 1,
        "bit13": (v >> 13) & 1,
        "bit14": (v >> 14) & 1,
        "bit15": (v >> 15) & 1,
    }


def resolve_zone_maps(record, matrices_by_id):
    """Return the sorted list of distinct a/0/0/8 map ids zone `record`
    reaches, via its +0x04 matrix id (see docs/ASSETS.md, "Zone to map
    model SOLVED"). For a mode-0 matrix the whole grid belongs to this
    one zone, so every non-empty cell counts; for a mode-1 matrix (the
    overworld) only cells whose zone grid entry equals this zone's id
    count -- the matrix is shared across many zones, one chunk each."""
    matrix_id = record["field_04"]
    m = matrices_by_id.get(matrix_id)
    if m is None:
        return []
    zone_id = record["zone_id"]
    maps = set()
    if m["mode"] == 1:
        for cell, zid in zip(m["map_grid"], m["zone_grid"]):
            if cell != matrixmod.EMPTY_CELL and zid == zone_id:
                maps.add(cell)
    else:
        for cell in m["map_grid"]:
            if cell != matrixmod.EMPTY_CELL:
                maps.add(cell)
    return sorted(maps)


def cmd_list(args):
    raw = load_table()
    records = parse_table(raw)
    matrices_by_id = None
    if getattr(args, "resolve", False):
        matrices_by_id = {m["matrix_id"]: m for m in matrixmod.load_all()}
    for r in records:
        conn = (r["conn0"], r["conn1"], r["conn2"], r["conn3"])
        p1a = unpack_1a(r["packed_1a"])
        p1c = unpack_1c(r["packed_1c"])
        fl = unpack_flags(r["flags"])
        line = (
            f"zone {r['zone_id']:3d}: "
            f"field_00={r['field_00']:3d} field_01={r['field_01']:3d} "
            f"field_02={r['field_02']:5d} "
            f"matrix_id={r['field_04']:5d} "
            f"field_06={r['field_06']:5d} field_08={r['field_08']:5d} "
            f"script_id={r['script_id']:4d} conn={conn} "
            f"field_14={r['field_14']:5d} zone_perm={r['zone_perm']:3d} "
            f"field_18={r['field_18']:5d} "
            f"packed_1a=0x{r['packed_1a']:04x}{p1a} "
            f"packed_1c=0x{r['packed_1c']:04x}{p1c} "
            f"flags=0x{r['flags']:04x}{fl} "
            f"field_20={r['field_20']:5d} "
            f"fx_24={r['fx_24']} fx_28={r['fx_28']} fx_2c={r['fx_2c']}"
        )
        if matrices_by_id is not None:
            maps = resolve_zone_maps(r, matrices_by_id)
            line += f" maps={maps}"
        print(line)


def cmd_resolve_summary(args):
    """Counts requested by the mission: how many zones resolve to exactly
    one a/0/0/8 map file (houses/interiors) vs several (only possible on
    a mode-1 matrix, where a zone's chunk can span more than one map
    model)."""
    raw = load_table()
    records = parse_table(raw)
    matrices_by_id = {m["matrix_id"]: m for m in matrixmod.load_all()}
    one = several = zero = 0
    for r in records:
        maps = resolve_zone_maps(r, matrices_by_id)
        if len(maps) == 0:
            zero += 1
        elif len(maps) == 1:
            one += 1
        else:
            several += 1
    print(f"zones resolving to exactly one map file: {one}/{RECORD_COUNT}")
    print(f"zones resolving to several map files: {several}/{RECORD_COUNT}")
    print(f"zones resolving to zero map files: {zero}/{RECORD_COUNT}")


# ---------------------------------------------------------------------------
# --stats
# ---------------------------------------------------------------------------

def cmd_stats(args):
    raw = load_table()
    records = parse_table(raw)
    names = [name for name, _ in FIELDS]
    print(f"records {RECORD_COUNT}   stride {RECORD_STRIDE}   "
          f"bytes {RECORD_COUNT * RECORD_STRIDE}")
    for name in names:
        vals = [r[name] for r in records]
        mn, mx = min(vals), max(vals)
        distinct = len(set(vals))
        injective = distinct == len(vals)
        print(f"  {name:12s} min={mn:6d} max={mx:6d} distinct={distinct:4d} "
              f"injective={injective}")


# ---------------------------------------------------------------------------
# --verify
# ---------------------------------------------------------------------------

def cmd_verify(args):
    raw = load_table()
    records = parse_table(raw)
    repacked = pack_table(records)
    if repacked == raw:
        print(f"a/0/1/2 sub-file 0: round-trip OK "
              f"({RECORD_COUNT} records, {len(raw)} bytes)")
        return 0
    else:
        print(f"a/0/1/2 sub-file 0: round-trip MISMATCH "
              f"(orig {len(raw)}, repacked {len(repacked)})", file=sys.stderr)
        for i, r in enumerate(records):
            packed = pack_record(r)
            orig = raw[i * RECORD_STRIDE:(i + 1) * RECORD_STRIDE]
            if packed != orig:
                print(f"  record {i} differs", file=sys.stderr)
        return 1


# ---------------------------------------------------------------------------
# --map-lane-check: reproduce the map-lane test in the module docstring
# ---------------------------------------------------------------------------

_HOUSE_PREFIXES = ("pl_", "c0", "c1")
_OUTDOOR_PREFIXES = ("map", "leagin", "winter", "autumn", "summer", "t0",
                      "white", "palace")


def _classify_a008(a008, cache, index):
    """'house', 'outdoor' or 'other', by model name prefix (same
    classifier as tools/assets/map_grid.py's attribute-hunt pass)."""
    if index not in cache:
        try:
            sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
            import map_grid as mg  # noqa: E402
            nm = mg.model_name(a008, index) or "?"
        except Exception:
            nm = "?"
        if nm.startswith(_HOUSE_PREFIXES):
            cache[index] = "house"
        elif nm.startswith(_OUTDOOR_PREFIXES):
            cache[index] = "outdoor"
        else:
            cache[index] = "other"
    return cache[index]


def _bit_correlation(records, get_index, a008, cache):
    """For every flags bit, compare the house-rate of records with the
    bit set vs clear, among records whose candidate index lands on a
    house/outdoor-classified a/0/0/8 file. Returns the best (score, bit,
    ...) tuple, or None if no record classified."""
    results = []
    for r in records:
        idx = get_index(r)
        if idx is None or not (0 <= idx < a008.file_count):
            continue
        c = _classify_a008(a008, cache, idx)
        if c == "other":
            continue
        results.append((r["flags"], c == "house"))
    if not results:
        return None, 0
    best = None
    for bit in range(16):
        yes = [e for fw, e in results if (fw >> bit) & 1]
        no = [e for fw, e in results if not ((fw >> bit) & 1)]
        if not yes or not no:
            continue
        yr = sum(yes) / len(yes)
        nr = sum(no) / len(no)
        score = abs(yr - nr)
        if best is None or score > best[0]:
            best = (score, bit, sum(yes), len(yes), sum(no), len(no))
    return best, len(results)


def cmd_map_lane_check(args):
    raw = load_table()
    records = parse_table(raw)
    a008 = narc.parse_file(A008_PATH)
    cache = {}

    candidates = [
        ("field_06 - 0", lambda r: r["field_06"]),
        ("field_06 - 204", lambda r: r["field_06"] - 204),
        ("field_06 - 205", lambda r: r["field_06"] - 205),
        ("field_06 - 206", lambda r: r["field_06"] - 206),
        ("field_08 - 0", lambda r: r["field_08"]),
        ("conn0 - 1001", lambda r: r["conn0"] - 1001),
        ("conn1 - 1001", lambda r: r["conn1"] - 1001),
        ("conn2 - 1001", lambda r: r["conn2"] - 1001),
        ("conn3 - 1001", lambda r: r["conn3"] - 1001),
        ("field_02 - 0", lambda r: r["field_02"]),
        ("field_04 - 0", lambda r: r["field_04"]),
    ]
    print(f"a/0/0/8 sub-files: {a008.file_count}")
    for name, fn in candidates:
        best, n_classified = _bit_correlation(records, fn, a008, cache)
        if best is None:
            print(f"  {name}: no record classified as house/outdoor, no test possible")
            continue
        score, bit, ye, yt, ne, nt = best
        print(f"  {name}: classified {n_classified}/{RECORD_COUNT}, "
              f"best bit {bit} set->{ye}/{yt} house clear->{ne}/{nt} house "
              f"score={score:.2f}")

    # Side tables: ruled out on value range alone.
    a081 = narc.parse_file(os.path.join(DATA_ROOT, "0", "8", "1"))
    sub13 = a081.read(13)
    vals081 = [struct.unpack_from("<HH", sub13, i)[1] for i in range(0, len(sub13), 4)]
    print(f"  a/0/8/1#13 side table: {len(vals081)} entries, "
          f"value range {min(vals081)}..{max(vals081)} (too small to index "
          f"a/0/0/8's {a008.file_count} files)")

    a149 = narc.parse_file(os.path.join(DATA_ROOT, "1", "4", "9"))
    sub0 = a149.read(0)
    vals149 = [struct.unpack_from("<HH", sub0, i)[1] for i in range(0, len(sub0), 4)]
    print(f"  a/1/4/9#0 side table: {len(vals149)} entries, "
          f"value range {min(vals149)}..{max(vals149)} (too small to index "
          f"a/0/0/8's {a008.file_count} files)")

    a082 = narc.parse_file(os.path.join(DATA_ROOT, "0", "8", "2"))
    sub1 = a082.read(1)
    print(f"  a/0/8/2#1 side table: {len(sub1)} bytes (0 entries, loop never "
          f"entered in this build)")


def cmd_script_lane_check(args):
    raw = load_table()
    records = parse_table(raw)
    a003 = narc.parse_file(A003_PATH)
    ok = fail = 0
    for r in records:
        idx = r["script_id"]
        if not (0 <= idx < a003.file_count):
            fail += 1
            print(f"  zone {r['zone_id']}: script_id {idx} out of range "
                  f"(a/0/0/3 has {a003.file_count} sub-files)")
            continue
        try:
            events.parse_0003(a003.read(idx))
            ok += 1
        except events.EventsError as exc:
            fail += 1
            print(f"  zone {r['zone_id']}: script_id {idx} failed to parse: {exc}")
    print(f"script lane: {ok}/{RECORD_COUNT} parse OK ({fail} failed), "
          f"a/0/0/3 has {a003.file_count} sub-files")


# ---------------------------------------------------------------------------
# --survey: NARC-wide survey with the single-sub-file-blob gap fixed
# ---------------------------------------------------------------------------

def _iter_archives():
    """Yield (rel_path, abs_path) for every 'a/x/y/z' archive file under
    extract/data/a, without assuming any particular id range."""
    if not os.path.isdir(DATA_ROOT):
        return
    for d0 in sorted(os.listdir(DATA_ROOT)):
        p0 = os.path.join(DATA_ROOT, d0)
        if not os.path.isdir(p0):
            continue
        for d1 in sorted(os.listdir(p0)):
            p1 = os.path.join(p0, d1)
            if not os.path.isdir(p1):
                continue
            for d2 in sorted(os.listdir(p1)):
                p2 = os.path.join(p1, d2)
                if os.path.isfile(p2):
                    yield f"a/{d0}/{d1}/{d2}", p2


def cmd_survey(args):
    """Re-run the archive-wide survey, fixed to also catch single-sub-file
    NARCs whose one blob divides evenly by a plausible record stride --
    the case that made the original survey miss a/0/1/2 (see module
    docstring)."""
    print("[*] NARC-wide survey, single-sub-file blobs divisible by a "
          "16..64-byte stride, record count in [100, 1000]:")
    found_a012 = False
    for rel, path in _iter_archives():
        try:
            with open(path, "rb") as f:
                data = f.read()
            n = narc.parse(data, path=path)
        except Exception:
            continue
        if n.file_count != 1:
            continue
        blob = n.read(0)
        size = len(blob)
        if size == 0:
            continue
        for stride in range(16, 65):
            if size % stride == 0:
                count = size // stride
                if 100 <= count <= 1000:
                    marker = "  <-- a/0/1/2, the zone header table" \
                        if rel == "a/0/1/2" else ""
                    print(f"    {rel}: 1 sub-file, {size} bytes, "
                          f"stride {stride} -> {count} records{marker}")
                    if rel == "a/0/1/2":
                        found_a012 = True
    if not found_a012:
        print("    a/0/1/2 not found by this pass (unexpected -- check "
              "extract/data/a/0/1/2 exists)")
    print("[*] extract/arm9_dec.bin loads at ARM9 address 0x02004000, not "
          "0x02000000; any file-offset<->address conversion needs that bias.")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group()
    g.add_argument("--list", action="store_true", help="print all 427 records")
    g.add_argument("--stats", action="store_true",
                    help="per-lane min/max/distinct/injective")
    g.add_argument("--verify", action="store_true",
                    help="byte-identical repack check")
    g.add_argument("--survey", action="store_true",
                    help="NARC-wide survey, fixed for single-sub-file blobs")
    g.add_argument("--map-lane-check", action="store_true",
                    help="test every candidate map lane against a/0/0/8")
    g.add_argument("--script-lane-check", action="store_true",
                    help="test the script lane against a/0/0/3")
    g.add_argument("--resolve-summary", action="store_true",
                    help="count zones resolving to one vs several map files")
    ap.add_argument("--resolve", action="store_true",
                     help="with --list, also print each zone's resolved "
                          "a/0/0/8 map ids (via its matrix id, see matrix.py)")
    args = ap.parse_args(argv)

    try:
        if args.stats:
            cmd_stats(args)
        elif args.verify:
            return cmd_verify(args) or 0
        elif args.survey:
            cmd_survey(args)
        elif args.map_lane_check:
            cmd_map_lane_check(args)
        elif args.script_lane_check:
            cmd_script_lane_check(args)
        elif args.resolve_summary:
            cmd_resolve_summary(args)
        else:
            cmd_list(args)
    except ZonesError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 2
    return 0


if __name__ == "__main__":
    sys.exit(main())
