#!/usr/bin/env python3
"""
zones.py -- search results for a per-zone (map-file/script-file/text bank/
encounter table/music/neighbour) index table.

Written from scratch for the aletheia asset lane. Stdlib only.

This pass did NOT confirm a per-zone index table. See docs/ASSETS.md, the
"Zone table hunt" section, for the full writeup. In short:

  (1) A stride/lane brute-force scan of extract/arm9_dec.bin and every
      extract/overlays_dec/*.bin (stride 16-64, looking for one u16 lane
      < 649 -- a/0/0/8's map-file count -- and another u16 lane < 472 --
      a/0/0/3's script-file count -- held with real value variation over
      >=100 consecutive records) came back negative. One apparent hit
      (y9_0203.bin, stride 60) was hand-checked and is variable-length
      event-shaped data, not a real stride-60 array.

  (2) A NARC-wide survey for archives whose sub-file count is a plausible
      zone count (100-1000) with one dominant sub-file size in [16, 64]
      bytes (treating each sub-file itself as one record) found 6
      candidates, listed in CANDIDATES below with the reason each was
      ruled out. One of them, a/0/9/2, is the already-confirmed trdata
      table -- kept here as a sanity check that this method reliably
      re-finds a real, known record array.

  (3) The one genuine new lead: the literal debug string "zonedata.c" is
      embedded at ARM9 address 0x020A72B0, and is referenced (as a heap
      allocator's debug filename argument) from the function at ARM9
      address 0x020139B0 (asm/arm9/src/005_020132F4.s, not yet in
      src/matched or src/pending). That function lazily allocates a
      76-byte (0x4C) singleton "ZoneData manager" struct (a global slot at
      0x02146264) and fills 7 scalar fields via a generic const-lookup
      helper (func_0204A298, called with (category, sub_id) pairs
      (0x51, 0xd), (0x52, 1), (0x95, 0), plus one literal constant 0x1AB
      = 427 stored directly). This confirms a "ZoneData" subsystem exists
      in the original source and pins down where its runtime state lives,
      but the manager struct itself holds only small counts/config
      values, not a raw per-zone array -- the actual table (if it is a
      flat array at all) was not traced to its source this pass; that is
      the next step for whoever picks this up.

Usage:
    python tools/assets/zones.py --list
"""
import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402

DATA_ROOT = os.path.join("extract", "data")

MAP_COUNT = 649      # a/0/0/8's sub-file count
SCRIPT_COUNT = 472   # a/0/0/3's sub-file count

# (narc path relative to extract/data/, dominant sub-file size in bytes,
#  verdict string)
CANDIDATES = [
    ("a/0/1/6", 60,
     "ruled out: records fall in groups of 3 sharing a near-identical "
     "header with only a small incrementing sub-index, and a handful of "
     "sub-files in this archive carry non-uniform magics (\"dddd\", "
     "\"2AkV\") -- not a flat zone-record array"),
    ("a/0/2/1", 36,
     "ruled out: every record ends in the ASCII tag \"SS\" (bytes 0x53 "
     "0x53), consistent with a sound/SE test-tag table"),
    ("a/0/2/4", 36,
     "ruled out: every record shares a constant 8-byte header "
     "(1f 08 00 01 00 04 00 ..) with only a small incrementing tail "
     "counter -- an index/pointer table, not zone data"),
    ("a/0/9/2", 20,
     "CONFIRMED as something else already: this is trdata, the trainer "
     "data table (see \"Trainer data table located by reference\" in "
     "docs/ASSETS.md) -- kept here as a sanity check that this method "
     "reliably re-finds a known real record array"),
    ("a/1/0/8", 28,
     "ruled out: no byte lane in this record satisfies both the <649 and "
     "<472 bound"),
    ("a/1/6/9", 16,
     "ruled out: same record shape as a/2/1/4 (8 x u16, see below); field "
     "0 increases in tight groups of 3 (a plausible per-icon/frame table, "
     "e.g. a world-map icon placement list), not an injective per-zone "
     "id, and no lane is simultaneously bounded <649 and <472"),
    ("a/2/1/4", 16,
     "ruled out: same reasoning as a/1/6/9 above -- same record shape, "
     "same grouped-by-3 field 0 pattern"),
]

CODE_LEAD = """\
Code lead (not a confirmed table, see module docstring):
  string   "zonedata.c" at ARM9 0x020A72B0
  used by  func at ARM9 0x020139B0 (asm/arm9/src/005_020132F4.s)
  that fn  lazily heap-allocates a 76-byte singleton "ZoneData manager"
           (global slot 0x02146264) via func_02030734(heap, size=0x4C,
           .., filename="zonedata.c", line=0x60), then fills fields at
           offsets 0x34 (u16, literal 0x1AB = 427), 0x38, 0x3c, 0x40 (u16),
           0x42 (u8), 0x43 (u8), 0x44 via func_0204A298(category, sub_id,
           ..) with (category, sub_id) = (0x51, 0xd), (0x52, 1), (0x95, 0)
  status   the manager holds small scalar counts/config, not a raw
           per-zone array; func_0204A298's own data source (where those
           counts ultimately come from) was not traced further this pass
"""


def lane_stats(records, stride):
    """For a list of same-size byte records, return {byte_offset:
    (min, max, distinct_count)} for every u16 lane."""
    stats = {}
    for c in range(0, stride - 1):
        vals = [struct.unpack_from("<H", r, c)[0] for r in records]
        stats[c] = (min(vals), max(vals), len(set(vals)))
    return stats


def cmd_list(args):
    for rel, stride, verdict in CANDIDATES:
        path = os.path.join(DATA_ROOT, *rel.split("/"))
        if not os.path.exists(path):
            print(f"=== {rel}: NOT FOUND at {path} ===")
            continue
        with open(path, "rb") as f:
            data = f.read()
        n = narc.parse(data, path=path)
        recs = [bytes(data[sf.offset:sf.offset + sf.size])
                for sf in n.subfiles if sf.size == stride]
        print(f"=== {rel}: {len(recs)}/{len(n.subfiles)} sub-files of size "
              f"{stride} bytes ===")
        stats = lane_stats(recs, stride)
        for c, (mn, mx, distinct) in stats.items():
            tag = []
            if mx < MAP_COUNT:
                tag.append(f"<{MAP_COUNT} (map-count bound)")
            if mx < SCRIPT_COUNT:
                tag.append(f"<{SCRIPT_COUNT} (script-count bound)")
            tagstr = f"  [{', '.join(tag)}]" if tag else ""
            print(f"  lane @byte {c:2d}: min={mn:5d} max={mx:5d} "
                  f"distinct={distinct:4d}{tagstr}")
        print(f"  verdict: {verdict}")
        print()
    print(CODE_LEAD)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--list", action="store_true",
                     help="print the surveyed candidates, their per-lane "
                          "stats, and the verdict for each, plus the code "
                          "lead")
    args = ap.parse_args(argv)
    if args.list or not any(vars(args).values()):
        cmd_list(args)
    return 0


if __name__ == "__main__":
    sys.exit(main())
