#!/usr/bin/env python3
"""
evolution.py -- decoder for the evolution table: `a/0/1/9`, 668 sub-files,
each a fixed 42-byte record of 7 rows of (method, param, target species).

Written from scratch for the aletheia asset lane. Stdlib only, depends
only on narc.py.

--------------------------------------------------------------------------
Identifying the archive
--------------------------------------------------------------------------
src/matched/unit_0201B70C.c (shinka_check.c's data layer) gives the
record shape outright:

    struct EvoRow   { u16 method; u16 param; u16 species; };
    struct EvoTable { struct EvoRow rows[7]; u16 unk2A; };

i.e. a 7-row table of 6-byte rows (44 bytes total with the trailing
halfword). `a/0/1/9` has 668 sub-files, every one exactly 42 bytes: that
is the 7-row array (7 * 6 = 42) without the trailing `unk2A` halfword --
sub_0201B718 never reads `unk2A` (its three cases only ever touch
`rows[row].{method,param,species}`), so the archive not carrying it is
consistent with the accessor rather than a contradiction of it.

Sub-file 1 (species 1) decodes to one non-empty row: method=4, param=16,
target=2. Sub-file 2 (species 2) decodes to method=4, param=32, target=3.
Read as "evolve by method 4 (level-up) at the param level, into the
target species id", these are species 1 evolving into species 2 at level
16 and species 2 evolving into species 3 at level 32 -- the real
Bulbasaur -> Ivysaur (level 16) -> Venusaur (level 32) chain. This was
read directly off the bytes and the decompiled row shape, not from any
external evolution-data reference.

668 sub-files (sub-file 0 an all-zero sentinel, 667 real species/form
records) matches `a/0/1/6`'s 667 real Personal records and
`a/0/1/8`'s 667 real learnset sub-files exactly.

--------------------------------------------------------------------------
Record layout (42 bytes: 7 rows x 6 bytes)
--------------------------------------------------------------------------
    row[i] + 0x00  u16  method    evolution method id
    row[i] + 0x02  u16  param     method parameter (e.g. level)
    row[i] + 0x04  u16  species   target species id, 0 = unused row

--------------------------------------------------------------------------
Target-species bound check
--------------------------------------------------------------------------
`--verify-targets` checks every non-zero target species id across all
667 real records against the personal table's real record count (667,
tools/assets/personal.py) -- every target must be <= 667.

--------------------------------------------------------------------------
CLI
--------------------------------------------------------------------------
    python tools/assets/evolution.py --list [--limit N]
    python tools/assets/evolution.py --dump N
    python tools/assets/evolution.py --verify
    python tools/assets/evolution.py --verify-targets
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402

ARCHIVE = "a/0/1/9"
DATA_ROOT = os.path.join("extract", "data")
RECORD_STRIDE = 42
ROWS = 7
MAX_SPECIES = 667  # tools/assets/personal.py's real record count


class EvolutionError(Exception):
    pass


def _open():
    return narc.parse_file(os.path.join(DATA_ROOT, *ARCHIVE.split("/")))


def parse_record(raw):
    if len(raw) != RECORD_STRIDE:
        raise EvolutionError(f"expected {RECORD_STRIDE}-byte record, got {len(raw)}")
    vals = struct.unpack("<21H", raw)
    return [tuple(vals[i * 3:i * 3 + 3]) for i in range(ROWS)]


def pack_record(rows):
    flat = []
    for method, param, species in rows:
        flat.extend((method, param, species))
    return struct.pack("<21H", *flat)


def load_all():
    n = _open()
    return n, [parse_record(n.read(i)) for i in range(n.file_count)]


def cmd_list(args):
    _, recs = load_all()
    limit = args.limit if args.limit else len(recs)
    for idx, rows in enumerate(recs[:limit]):
        active = [(m, p, s) for m, p, s in rows if s != 0]
        print(f"#{idx:3d}: " +
              ", ".join(f"method={m} param={p} -> #{s}" for m, p, s in active))


def cmd_dump(args):
    n, _ = load_all()
    idx = args.dump
    if idx < 0 or idx >= n.file_count:
        print(f"record index must be 0..{n.file_count - 1}")
        return 1
    rows = parse_record(n.read(idx))
    for i, (m, p, s) in enumerate(rows):
        print(f"  row {i}: method={m:5d} param={p:5d} species={s:5d}")
    return 0


def cmd_verify(args):
    n = _open()
    ok = 0
    bad = 0
    for i in range(n.file_count):
        raw = n.read(i)
        rows = parse_record(raw)
        repacked = pack_record(rows)
        if repacked == raw:
            ok += 1
        else:
            bad += 1
            print(f"MISMATCH at #{i}: {raw.hex()} != {repacked.hex()}")
    total = ok + bad
    print(f"[*] {ok}/{total} records round-trip byte-identical "
          f"({ok * RECORD_STRIDE}/{total * RECORD_STRIDE} bytes)")
    return 0 if bad == 0 else 1


def cmd_verify_targets(args):
    _, recs = load_all()
    total = 0
    bad = 0
    for rows in recs:
        for m, p, s in rows:
            if s == 0:
                continue
            total += 1
            if s > MAX_SPECIES:
                bad += 1
    print(f"[*] {total - bad}/{total} non-empty evolution targets are "
          f"<= {MAX_SPECIES} (the real personal-table record count)")
    return 0 if bad == 0 else 1


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--dump", type=int, metavar="N")
    ap.add_argument("--verify", action="store_true")
    ap.add_argument("--verify-targets", action="store_true")
    args = ap.parse_args(argv)

    if not (args.list or args.dump is not None or args.verify or args.verify_targets):
        ap.error("give --list, --dump N, --verify, or --verify-targets")

    rc = 0
    if args.list:
        cmd_list(args)
    if args.dump is not None:
        rc = cmd_dump(args) or rc
    if args.verify:
        rc = cmd_verify(args) or rc
    if args.verify_targets:
        rc = cmd_verify_targets(args) or rc
    return rc


if __name__ == "__main__":
    sys.exit(main())
