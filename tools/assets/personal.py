#!/usr/bin/env python3
"""
personal.py -- decoder for the Pokemon personal data table: `a/0/1/6`,
60-byte records (struct Personal, 0x3C bytes), one record per species/form.

Written from scratch for the aletheia asset lane. Stdlib only, depends
only on narc.py.

--------------------------------------------------------------------------
Archive framing
--------------------------------------------------------------------------
`a/0/1/6` has 669 sub-files:
  - sub-file 0 is a 56-byte all-zero sentinel (shorter than the 60-byte
    stride, the same "sentinel shorter than the real record" shape
    trainer_data.py documents for a/0/9/2).
  - sub-files 1..667 (667 records) are 60-byte Personal records.
  - sub-file 668 is a 1300-byte outlier, clearly not a 60-byte Personal
    record; left undecoded here (see "What is not decoded" below).

667 records against 649 species is +18, consistent with a small number
of species carrying extra form entries (this pass does not attempt to
name which species own which extra slot; that would need the form-table
cross-reference at record offset 0x1C/0x1E/0x20, not attempted here).

--------------------------------------------------------------------------
Record layout (60 bytes, struct Personal, src/matched/unit_0201AE14.c)
--------------------------------------------------------------------------
Field names and offsets are exactly the `struct Personal` declaration in
src/matched/unit_0201AE14.c (the 44-case field-getter sub_0201AE1C), which
is attested by the jump table at ARM9 0x0201AE2E. Only the fields that
file's comments name explicitly are given a semantic label; everything
else keeps the source's `unkXX` spelling. Interface ids (the sub_0201AE1C
`case N`) are noted per field for traceability, not used by this decoder.

    0x00  u8   hp                    base HP             (case 0)
    0x01  u8   atk                   base Attack         (case 1)
    0x02  u8   def                   base Defense        (case 2)
    0x03  u8   spe                   base Speed          (case 3)
    0x04  u8   spa                   base Sp. Atk        (case 4)
    0x05  u8   spd                   base Sp. Def        (case 5)
    0x06  u8   type0                 primary type id     (case 6)
    0x07  u8   type1                 secondary type id   (case 7)
    0x08  u8   catch_rate                                (case 8)
    0x09  u8   unk09                                     (case 36)
    0x0A  u16  bitfield: ev0:2 ev1:2 ev2:2 ev3:2 ev4:2 ev5:2 (EV yield,
               one 2-bit field per stat, cases 10-15) unk0A_12:1 (case 16)
               unk0A_13:3 (unused bits, no case)
    0x0C  u16  item0                 held item slot 0    (case 17)
    0x0E  u16  item1                 held item slot 1    (case 18)
    0x10  u16  item2                 held item slot 2    (case 19)
    0x12  u8   unk12                                     (case 20)
    0x13  u8   unk13                                     (case 21)
    0x14  u8   unk14                                     (case 22)
    0x15  u8   unk15                                     (case 23)
    0x16  u8   unk16                                     (case 24)
    0x17  u8   unk17                                     (case 25)
    0x18  u8   unk18                                     (case 26)
    0x19  u8   unk19                                     (case 27)
    0x1A  u8   unk1A                                     (case 28)
    0x1B  u8   unk1B                                     (case 29)
    0x1C  u16  form_table_base       form-table index    (case 30)
    0x1E  u16  form_table_companion                      (case 31)
    0x20  u8   form_count                                (case 32)
    0x21  u8   bitfield: unk21_0:6 (case 33) unk21_6:1 (case 34)
               unk21_7:1 (case 35)
    0x22  u16  unk22                                     (case 9)
    0x24  u16  unk24                                     (case 37)
    0x26  u16  unk26                                     (case 38)
    0x28  u32  unk28                                     (case 39)
    0x2C  u32  unk2C                                     (case 40)
    0x30  u32  unk30                                     (case 41)
    0x34  u32  unk34                                     (case 42)
    0x38  u32  unk38                                     (case 43)

No field is named "gender ratio", "hatch cycles", "friendship", "growth
rate", "egg group" or "colour" in unit_0201AE14.c's comments -- those
categories from the mission are NOT separately attested by any accessor
read in this pass, so they are left as `unkXX` rather than guessed. The
only semantic labels above are the ones the source comments give
outright: the six base stats, the two types, catch rate, the three held
items, the EV-yield bitfield, and the form-table base/companion/count.

--------------------------------------------------------------------------
Sanity check (species 1, Bulbasaur-shaped)
--------------------------------------------------------------------------
Record 1's first eight bytes decode to hp=45 atk=49 def=49 spe=45 spa=65
spd=65 type0=11 type1=3, catch_rate=45. Types 11/3 are Grass/Poison under
the type-id ordering `tools/assets/waza.py`'s own sanity check (Pound's
move-type field) does not fix on its own, but which the EV-yield/base-stat
match alone already confirms beyond reasonable doubt: HP 45, Atk 49, Def
49, Spe 45, SpA 65, SpD 65 is Bulbasaur's real base stat line, and
catch_rate 45 is Bulbasaur's real catch rate. No external reference data
was consulted for this -- only the bytes and the decompiled field map.

--------------------------------------------------------------------------
CLI
--------------------------------------------------------------------------
    python tools/assets/personal.py --list [--limit N]
    python tools/assets/personal.py --dump N
    python tools/assets/personal.py --verify
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402

ARCHIVE = "a/0/1/6"
DATA_ROOT = os.path.join("extract", "data")
RECORD_STRIDE = 60
FIRST_RECORD = 1
LAST_RECORD = 667  # inclusive; sub-file 668 is the 1300-byte outlier

FIELDS = [
    ("hp", "B"), ("atk", "B"), ("def_", "B"), ("spe", "B"),
    ("spa", "B"), ("spd", "B"), ("type0", "B"), ("type1", "B"),
    ("catch_rate", "B"), ("unk09", "B"),
    ("ev_bits", "H"),
    ("item0", "H"), ("item1", "H"), ("item2", "H"),
    ("unk12", "B"), ("unk13", "B"), ("unk14", "B"), ("unk15", "B"),
    ("unk16", "B"), ("unk17", "B"), ("unk18", "B"), ("unk19", "B"),
    ("unk1A", "B"), ("unk1B", "B"),
    ("form_table_base", "H"), ("form_table_companion", "H"),
    ("form_count", "B"), ("unk21", "B"),
    ("unk22", "H"), ("unk24", "H"), ("unk26", "H"),
    ("unk28", "I"), ("unk2C", "I"), ("unk30", "I"), ("unk34", "I"),
    ("unk38", "I"),
]
RECORD_FMT = "<" + "".join(f for _, f in FIELDS)
assert struct.calcsize(RECORD_FMT) == RECORD_STRIDE


class PersonalError(Exception):
    pass


def _open():
    return narc.parse_file(os.path.join(DATA_ROOT, *ARCHIVE.split("/")))


def parse_record(raw):
    if len(raw) != RECORD_STRIDE:
        raise PersonalError(f"expected {RECORD_STRIDE}-byte record, got {len(raw)}")
    vals = struct.unpack(RECORD_FMT, raw)
    rec = dict(zip((name for name, _ in FIELDS), vals))
    ev = rec.pop("ev_bits")
    rec["ev_hp"] = ev & 0x3
    rec["ev_atk"] = (ev >> 2) & 0x3
    rec["ev_def"] = (ev >> 4) & 0x3
    rec["ev_spe"] = (ev >> 6) & 0x3
    rec["ev_spa"] = (ev >> 8) & 0x3
    rec["ev_spd"] = (ev >> 10) & 0x3
    rec["unk0A_12"] = (ev >> 12) & 0x1
    rec["unk0A_13"] = (ev >> 13) & 0x7
    u21 = rec.pop("unk21")
    rec["unk21_0"] = u21 & 0x3F
    rec["unk21_6"] = (u21 >> 6) & 0x1
    rec["unk21_7"] = (u21 >> 7) & 0x1
    return rec


def pack_record(rec):
    ev = (rec["ev_hp"] & 0x3) | ((rec["ev_atk"] & 0x3) << 2) | \
         ((rec["ev_def"] & 0x3) << 4) | ((rec["ev_spe"] & 0x3) << 6) | \
         ((rec["ev_spa"] & 0x3) << 8) | ((rec["ev_spd"] & 0x3) << 10) | \
         ((rec["unk0A_12"] & 0x1) << 12) | ((rec["unk0A_13"] & 0x7) << 13)
    u21 = (rec["unk21_0"] & 0x3F) | ((rec["unk21_6"] & 0x1) << 6) | \
          ((rec["unk21_7"] & 0x1) << 7)
    vals = []
    for name, _ in FIELDS:
        if name == "ev_bits":
            vals.append(ev)
        elif name == "unk21":
            vals.append(u21)
        else:
            vals.append(rec[name])
    return struct.pack(RECORD_FMT, *vals)


def load_records():
    n = _open()
    return n, [parse_record(n.read(i)) for i in range(FIRST_RECORD, LAST_RECORD + 1)]


def cmd_list(args):
    _, recs = load_records()
    limit = args.limit if args.limit else len(recs)
    for idx, r in enumerate(recs[:limit], start=FIRST_RECORD):
        print(f"#{idx:3d}: hp={r['hp']:3d} atk={r['atk']:3d} def={r['def_']:3d} "
              f"spe={r['spe']:3d} spa={r['spa']:3d} spd={r['spd']:3d} "
              f"type0={r['type0']:2d} type1={r['type1']:2d} "
              f"catch_rate={r['catch_rate']:3d} "
              f"ev=({r['ev_hp']},{r['ev_atk']},{r['ev_def']},{r['ev_spe']},"
              f"{r['ev_spa']},{r['ev_spd']}) "
              f"items=({r['item0']},{r['item1']},{r['item2']}) "
              f"form_table=({r['form_table_base']},{r['form_table_companion']},"
              f"{r['form_count']})")


def cmd_dump(args):
    n, _ = load_records()
    idx = args.dump
    if idx < FIRST_RECORD or idx > LAST_RECORD:
        print(f"record index must be {FIRST_RECORD}..{LAST_RECORD}")
        return 1
    r = parse_record(n.read(idx))
    for name, _ in FIELDS:
        if name in ("ev_bits", "unk21"):
            continue
        print(f"  {name:24s} = {r[name]}")
    for name in ("ev_hp", "ev_atk", "ev_def", "ev_spe", "ev_spa", "ev_spd",
                 "unk0A_12", "unk0A_13", "unk21_0", "unk21_6", "unk21_7"):
        print(f"  {name:24s} = {r[name]}")
    return 0


def cmd_verify(args):
    n = _open()
    ok = 0
    bad = 0
    for i in range(FIRST_RECORD, LAST_RECORD + 1):
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
