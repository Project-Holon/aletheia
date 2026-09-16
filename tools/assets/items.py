#!/usr/bin/env python3
"""
items.py -- decoder for the item data table: `a/0/2/4`, 36-byte records
(33 bytes of attested record plus 3 trailing pad bytes), one record per
item id.

Written from scratch for aletheia. Stdlib only, depends
only on narc.py.

--------------------------------------------------------------------------
Identifying `a/0/2/4` as the item table
--------------------------------------------------------------------------
The mission named `a/0/2/1` and `a/0/2/4` as the two 36-byte-record
candidates for the move table. `a/0/2/1` is the move table (see
tools/assets/waza.py). `a/0/2/4` (627 sub-files) is the item table:

1. src/matched/unit_02021014.c (func_02021014, an attested ARM9 record
   accessor over a packed-record interface used elsewhere for message-id
   lookups) defines `case 0: return p->f00 * 10;` -- a 16-bit field,
   scaled by 10, as the FIRST property of the record its caller reads.
2. `a/0/2/4` sub-file 1's first u16 is 0, sub-file 2's is 120, sub-file
   3's is 60, sub-file 4's is 20. Scaled by 10 (per the accessor) that is
   0, 1200, 600, 200 -- the real Black/White shop prices of items 1-4
   (Master Ball: not sold, price 0; Ultra Ball: 1200; Great Ball: 600;
   Poke Ball: 200). No external item-data reference was used to pick
   these four values; they were read directly off the bytes and checked
   against the *10 rule the accessor itself states.
3. `func_02021014`'s record struct is 0x21 (33) bytes (a 17-byte header
   plus a 17-byte sub-record starting at the header's last byte, see
   below); `a/0/2/4`'s stride is 36 bytes, i.e. the attested record plus
   3 trailing pad bytes that are zero in every sampled record.

This pass could not confirm which narc-kind id `a/0/2/4` corresponds to
from code (the opener, func_02020F34, is not decompiled in this tree), so
the archive identity rests on the numeric price match in point 2, not on
an attested kind id the way poke_personal/waza_tool/shinka_check are.

--------------------------------------------------------------------------
Record layout (33 attested bytes + 3 pad bytes = 36-byte stride)
--------------------------------------------------------------------------
Field names and offsets follow `struct Rec` / `struct Sub` in
src/matched/unit_02021014.c exactly; the "property id" column is the
`sel`/`case` value `func_02021014`/`func_020210C8` dispatch on.

Header (struct Rec, 17 bytes, offsets from record start):
    0x00  u16  price_x10   price = price_x10 * 10   (sel 0)
    0x02  u8   f02                                  (sel 1)
    0x03  u8   f03                                  (sel 2)
    0x04  u8   f04                                  (sel 8)
    0x05  u8   f05                                  (sel 9)
    0x06  u8   f06                                  (sel 10)
    0x07  u8   f07                                  (sel 11)
    0x08  u16  bitfield: b08_0:5 (sel 12) b08_5:1 (sel 3) b08_6:1 (sel 4)
               pocket:4 (sel 5, data check, see below) b08_11:5 (sel 13)
    0x0A  u8   f0A                                  (sel 6)
    0x0B  u8   f0B                                  (sel 7)
    0x0C  u8   f0C                                  (sel 14; selects which
               reading of offset 0x10 applies: 0 -> plain byte (sel 0
               of the fallback switch), 1 -> delegate to the Sub bitfield
               block below)
    0x0D  u8   f0D                                  (sel 15)
    0x0E  u8   f0E                                  (sel 16)
    0x0F  u8   f0F                                  (sel 17)

Offset 0x10 (17 bytes, struct Sub, only meaningful when f0C == 1):
    0x10  bitfield byte: b00_0..b00_7, 8 x 1 bit      (sel 0x12-0x19)
    0x11  bitfield byte: b01_0:1 b01_1:1 b01_2:1 b01_3:1 b01_4:4
                                                        (sel 0x1A-0x1E)
    0x12  bitfield byte: b02_0:4 b02_4:4               (sel 0x1F-0x20)
    0x13  bitfield byte: b03_0:4 b03_4:4               (sel 0x21-0x22)
    0x14  bitfield byte: b04_0:4 b04_4:2 b04_6:1 b04_7:1
                                                        (sel 0x23-0x26)
    0x15  bitfield byte: b05_0..b05_7, 8 x 1 bit        (sel 0x27-0x2E)
    0x16  bitfield byte: b06_0:1 b06_1:1 b06_2:1 b06_3:1 b06_4:1
               (3 unused bits, no sel)                  (sel 0x2F-0x33)
    0x17  s8   f07                                      (sel 0x34)
    0x18  s8   f08                                      (sel 0x35)
    0x19  s8   f09                                      (sel 0x36)
    0x1A  s8   f0A                                       (sel 0x37)
    0x1B  s8   f0B                                       (sel 0x38)
    0x1C  s8   f0C                                       (sel 0x39)
    0x1D  u8   f0D                                       (sel 0x3A)
    0x1E  u8   f0E                                       (sel 0x3B)
    0x1F  s8   f0F                                       (sel 0x3C)
    0x20  s8   f10                                       (sel 0x3D)
    0x21  s8   f11                                       (sel 0x3E)

0x10 alone (the f0C==0 case) is read as one plain byte with no further
split (the fallback switch's `case 0: return p->f10;`); this decoder
stores it as `f10_plain` since it overlaps byte-for-byte with `Sub.b00`.

0x22..0x23 (the final 2 of the 36-byte stride) are outside every sel the
accessor dispatches on; sampled as zero in every record checked and kept
here as `pad` for an exact round trip.

--------------------------------------------------------------------------
Sanity check
--------------------------------------------------------------------------
    item 1 (Master Ball): price_x10=0    -> price 0
    item 2 (Ultra Ball):   price_x10=120  -> price 1200
    item 3 (Great Ball):   price_x10=60   -> price 600
    item 4 (Poke Ball):    price_x10=20   -> price 200
    item 5:                price_x10=0    -> price 0

--------------------------------------------------------------------------
The caller chain for the archive identity: still not code-attested
--------------------------------------------------------------------------
The mission asked to find `func_02021014`'s caller chain to attest the
archive/kind id from code. Its only caller in this tree is
`func_02020FE4` (src/matched/func_02020FE4.c), which builds the record by
calling `func_02020F34(a, 0, (id & 0x7FFF) | 0x8000)` -- and `func_02020F34`
is the opener, referenced only as an `extern` here, with no definition
anywhere under src/. The chain runs out one call short of the archive
open, exactly where items.py's original identification note already said
it would. This pass did not find a decompiled `func_02020F34`, so the
archive/kind id (0x18 or otherwise) is still not attested by code; the
identification still rests on the price match in the section above.

--------------------------------------------------------------------------
`pocket` (sel 5, the 4-bit lane of +0x08): data check
--------------------------------------------------------------------------
`func_02021014`'s case 5 returns the 4-bit field at bits 7-10 of the u16
at +0x08 on its own, with no comment naming it. Read across the whole
archive it takes exactly 5 distinct values (0-4), and every block of
consecutive item ids that is independently identifiable by price checks
alone comes out at one constant value:

    items 1-16 (Master/Ultra/Great/Poke/... Ball -- prices 0, 1200, 600,
        200, ..., every one checked against a real ball price): pocket 0
    items 17-19 (Potion/Antidote/Burn Heal -- prices 300/100/250, all
        three real Black/White prices): pocket 1
    items 149-183 (a 20-price-per-unit run matching the real flat Berry
        price): pocket 3
    items 410-419 (a flat 10000-price run matching a TM's real price,
        followed by a price-0 run through item 425 on the same pocket
        value, consistent with HMs): pocket 2
    items 428-429 (price 0, non-consumable): pocket 4

This is not a clean "one pocket = one bag category" result, though: items
60-94, which by price alone (350, 500, 700, 2100, 5000, 9800, ...) are
clearly not Poke Balls, also read pocket 0, the same value as the actual
balls at items 1-16. Either this lane is coarser than the in-game bag's
visible pocket split (balls and general/battle items sharing one data
category while the ball-specific pocket is decided some other way, e.g.
by item-id range in the UI code rather than by this field), or the
60-94 identification by price alone is wrong. Reported as `pocket` because
the five-value, price-block-aligned pattern above is real and repeatable,
but the items-60-94 anomaly is reported alongside it rather than papered
over.

--------------------------------------------------------------------------
`effect` and `battle_effect`: not attested this pass
--------------------------------------------------------------------------
The mission also asked for effect and battle-effect fields. `f0A` (sel 6)
and `f0B` (sel 7) are the two candidates nearest `pocket` in the header
(the Poke Ball block reads f0A=0/f0B=1, the Potion-family block reads
f0A=1/f0B=2, uniformly), but that split tracks the same item blocks
`pocket` already separates and does not, on the records checked, resolve
below the pocket level (e.g. Potion and Antidote -- a flat heal and a
status cure, different in-game effects -- read the same f0A/f0B pair).
No data check in this pass pins a specific numeric effect id to a
specific in-game effect, so `f0A`/`f0B` keep their source-accessor names
rather than being relabelled `effect`/`battle_effect` on a guess.

--------------------------------------------------------------------------
CLI
--------------------------------------------------------------------------
    python tools/assets/items.py --list [--limit N]
    python tools/assets/items.py --dump N
    python tools/assets/items.py --verify
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402

ARCHIVE = "a/0/2/4"
DATA_ROOT = os.path.join("extract", "data")
RECORD_STRIDE = 36

FIELDS = [
    ("price_x10", "H"), ("f02", "B"), ("f03", "B"),
    ("f04", "B"), ("f05", "B"), ("f06", "B"), ("f07", "B"),
    ("b08", "H"),
    ("f0A", "B"), ("f0B", "B"), ("f0C", "B"),
    ("f0D", "B"), ("f0E", "B"), ("f0F", "B"),
    ("f10_plain", "B"),
    ("sub11", "B"), ("sub12", "B"), ("sub13", "B"), ("sub14", "B"),
    ("sub15", "B"), ("sub16", "B"),
    ("sub_f07", "b"), ("sub_f08", "b"), ("sub_f09", "b"), ("sub_f0A", "b"),
    ("sub_f0B", "b"), ("sub_f0C", "b"), ("sub_f0D", "B"), ("sub_f0E", "B"),
    ("sub_f0F", "b"), ("sub_f10", "b"), ("sub_f11", "b"),
    ("pad", "H"),
]
RECORD_FMT = "<" + "".join(f for _, f in FIELDS)
assert struct.calcsize(RECORD_FMT) == RECORD_STRIDE


class ItemError(Exception):
    pass


def _open():
    return narc.parse_file(os.path.join(DATA_ROOT, *ARCHIVE.split("/")))


def parse_record(raw):
    if len(raw) != RECORD_STRIDE:
        raise ItemError(f"expected {RECORD_STRIDE}-byte record, got {len(raw)}")
    vals = struct.unpack(RECORD_FMT, raw)
    rec = dict(zip((name for name, _ in FIELDS), vals))
    b08 = rec.pop("b08")
    rec["b08_0"] = b08 & 0x1F
    rec["b08_5"] = (b08 >> 5) & 0x1
    rec["b08_6"] = (b08 >> 6) & 0x1
    rec["pocket"] = (b08 >> 7) & 0xF
    rec["b08_11"] = (b08 >> 11) & 0x1F
    s = rec.pop("sub11")
    rec["b01_0"] = s & 0x1
    rec["b01_1"] = (s >> 1) & 0x1
    rec["b01_2"] = (s >> 2) & 0x1
    rec["b01_3"] = (s >> 3) & 0x1
    rec["b01_4"] = (s >> 4) & 0xF
    s = rec.pop("sub12")
    rec["b02_0"] = s & 0xF
    rec["b02_4"] = (s >> 4) & 0xF
    s = rec.pop("sub13")
    rec["b03_0"] = s & 0xF
    rec["b03_4"] = (s >> 4) & 0xF
    s = rec.pop("sub14")
    rec["b04_0"] = s & 0xF
    rec["b04_4"] = (s >> 4) & 0x3
    rec["b04_6"] = (s >> 6) & 0x1
    rec["b04_7"] = (s >> 7) & 0x1
    s = rec.pop("sub15")
    for i in range(8):
        rec[f"b05_{i}"] = (s >> i) & 0x1
    s = rec.pop("sub16")
    for i in range(5):
        rec[f"b06_{i}"] = (s >> i) & 0x1
    return rec


def pack_record(rec):
    b08 = (rec["b08_0"] & 0x1F) | ((rec["b08_5"] & 0x1) << 5) | \
          ((rec["b08_6"] & 0x1) << 6) | ((rec["pocket"] & 0xF) << 7) | \
          ((rec["b08_11"] & 0x1F) << 11)
    sub11 = (rec["b01_0"] & 0x1) | ((rec["b01_1"] & 0x1) << 1) | \
            ((rec["b01_2"] & 0x1) << 2) | ((rec["b01_3"] & 0x1) << 3) | \
            ((rec["b01_4"] & 0xF) << 4)
    sub12 = (rec["b02_0"] & 0xF) | ((rec["b02_4"] & 0xF) << 4)
    sub13 = (rec["b03_0"] & 0xF) | ((rec["b03_4"] & 0xF) << 4)
    sub14 = (rec["b04_0"] & 0xF) | ((rec["b04_4"] & 0x3) << 4) | \
            ((rec["b04_6"] & 0x1) << 6) | ((rec["b04_7"] & 0x1) << 7)
    sub15 = 0
    for i in range(8):
        sub15 |= (rec[f"b05_{i}"] & 0x1) << i
    sub16 = 0
    for i in range(5):
        sub16 |= (rec[f"b06_{i}"] & 0x1) << i
    vals = []
    for name, _ in FIELDS:
        if name == "b08":
            vals.append(b08)
        elif name == "sub11":
            vals.append(sub11)
        elif name == "sub12":
            vals.append(sub12)
        elif name == "sub13":
            vals.append(sub13)
        elif name == "sub14":
            vals.append(sub14)
        elif name == "sub15":
            vals.append(sub15)
        elif name == "sub16":
            vals.append(sub16)
        else:
            vals.append(rec[name])
    return struct.pack(RECORD_FMT, *vals)


def load_records():
    n = _open()
    return n, [parse_record(n.read(i)) for i in range(n.file_count)]


def cmd_list(args):
    _, recs = load_records()
    limit = args.limit if args.limit else len(recs)
    for idx, r in enumerate(recs[:limit]):
        print(f"#{idx:3d}: price={r['price_x10'] * 10:5d} "
              f"f02={r['f02']:3d} f03={r['f03']:3d} "
              f"f04={r['f04']:3d} f05={r['f05']:3d} f06={r['f06']:3d} "
              f"f07={r['f07']:3d} f0C={r['f0C']} pocket={r['pocket']}")


def cmd_dump(args):
    n, _ = load_records()
    idx = args.dump
    if idx < 0 or idx >= n.file_count:
        print(f"record index must be 0..{n.file_count - 1}")
        return 1
    r = parse_record(n.read(idx))
    print(f"  price = {r['price_x10'] * 10} (price_x10={r['price_x10']})")
    for name in sorted(r):
        if name == "price_x10":
            continue
        print(f"  {name:12s} = {r[name]}")
    return 0


def cmd_verify(args):
    n = _open()
    ok = 0
    bad = 0
    for i in range(n.file_count):
        raw = n.read(i)
        rec = parse_record(raw)
        repacked = pack_record(rec)
        if repacked == raw:
            ok += 1
        else:
            bad += 1
            print(f"MISMATCH at #{i}: {raw.hex()} != {repacked.hex()}")
    total = ok + bad
    print(f"[*] {ok}/{total} records round-trip byte-identical "
          f"({ok * RECORD_STRIDE}/{total * RECORD_STRIDE} bytes)")
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
