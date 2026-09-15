#!/usr/bin/env python3
"""
learnsets.py -- decoder for the level-up learnset table: `a/0/1/8`,
668 sub-files, one per species/form, each a list of (move id, level)
u16 pairs terminated by a (0xFFFF, 0xFFFF) sentinel pair.

Written from scratch for the aletheia asset lane. Stdlib only, depends
only on narc.py.

--------------------------------------------------------------------------
Identifying the archive
--------------------------------------------------------------------------
Of the ~650-670-sub-file archives, `a/0/1/8` is the only one whose every
sub-file, read as u16 LE, ends in 0xFFFF (668/668); the two other
same-size candidates in range, `a/0/1/9` and `a/0/2/0`, have 0/668 and
0/650 respectively (see tools/assets/evolution.py for what `a/0/1/9`
turns out to be).

Reading `a/0/1/8` as (move, level) pairs: sub-file 0 is empty (just the
terminator, the species-0 sentinel the same way `a/0/1/6`/`a/0/1/9`
reserve sub-file 0). Sub-file 1 decodes to 14 (move, level) pairs ending
in the sentinel; the first three are (move 33, level 1), (move 45, level
3), (move 73, level 7). Sub-file 2 (species 2, the evolved form) decodes
to the same three moves but with the first one moved to level 1 and two
more at level 1 ahead of it: (33,1), (45,1), (73,1), (33,3), (45,7)... --
exactly the shape a starter's evolved form takes (it already knows the
moves the base form's first few level-ups would teach, because it starts
at a higher level than the base form's move-learning schedule assumes).
This is read directly off the bytes, not from any external learnset
reference.

667 real species/form sub-files (indices 1..667) against `a/0/1/6`'s 667
real Personal records is an exact match, which is the strongest evidence
this is indexed the same way as the personal table.

--------------------------------------------------------------------------
Record layout
--------------------------------------------------------------------------
Each sub-file is a flat array of u16 pairs:
    u16 move
    u16 level
repeated until a pair reads (0xFFFF, 0xFFFF), which is included as the
last pair of the decoded list (needed for an exact round trip: a
sub-file's byte length is always 4 * (len(pairs))).

--------------------------------------------------------------------------
CLI
--------------------------------------------------------------------------
    python tools/assets/learnsets.py --list [--limit N]
    python tools/assets/learnsets.py --dump N
    python tools/assets/learnsets.py --verify
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402

ARCHIVE = "a/0/1/8"
DATA_ROOT = os.path.join("extract", "data")
TERMINATOR = (0xFFFF, 0xFFFF)


class LearnsetError(Exception):
    pass


def _open():
    return narc.parse_file(os.path.join(DATA_ROOT, *ARCHIVE.split("/")))


def parse_subfile(raw):
    if len(raw) % 4 != 0:
        raise LearnsetError(f"sub-file length {len(raw)} is not a multiple of 4")
    n = len(raw) // 4
    pairs = list(struct.iter_unpack("<HH", raw))
    if len(pairs) != n:
        raise LearnsetError("unpack count mismatch")
    if not pairs or pairs[-1] != TERMINATOR:
        raise LearnsetError("sub-file does not end in the 0xFFFF,0xFFFF terminator")
    return pairs


def pack_subfile(pairs):
    return b"".join(struct.pack("<HH", move, level) for move, level in pairs)


def load_all():
    n = _open()
    return n, [parse_subfile(n.read(i)) for i in range(n.file_count)]


def cmd_list(args):
    _, tables = load_all()
    limit = args.limit if args.limit else len(tables)
    for idx, pairs in enumerate(tables[:limit]):
        moves = [(m, l) for m, l in pairs if (m, l) != TERMINATOR]
        print(f"#{idx:3d}: {len(moves):2d} moves: " +
              ", ".join(f"{m}@{l}" for m, l in moves))


def cmd_dump(args):
    n, _ = load_all()
    idx = args.dump
    if idx < 0 or idx >= n.file_count:
        print(f"record index must be 0..{n.file_count - 1}")
        return 1
    pairs = parse_subfile(n.read(idx))
    for m, l in pairs:
        if (m, l) == TERMINATOR:
            print("  -- end --")
        else:
            print(f"  move {m:4d}  level {l:3d}")
    return 0


def cmd_verify(args):
    n = _open()
    ok = 0
    bad = 0
    total_bytes = 0
    for i in range(n.file_count):
        raw = n.read(i)
        pairs = parse_subfile(raw)
        repacked = pack_subfile(pairs)
        total_bytes += len(raw)
        if repacked == raw:
            ok += 1
        else:
            bad += 1
            print(f"MISMATCH at #{i}: {raw.hex()} != {repacked.hex()}")
    total = ok + bad
    print(f"[*] {ok}/{total} sub-files round-trip byte-identical "
          f"({total_bytes} bytes checked)")
    return 0 if bad == 0 else 1


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--dump", type=int, metavar="N")
    ap.add_argument("--verify", action="store_true")
    args = ap.parse_args(argv)

    if not (args.list or args.dump is not None or args.verify):
        ap.error("give --list, --dump N, or --verify")

    rc = 0
    if args.list:
        cmd_list(args)
    if args.dump is not None:
        rc = cmd_dump(args) or rc
    if args.verify:
        rc = cmd_verify(args) or rc
    return rc


if __name__ == "__main__":
    sys.exit(main())
