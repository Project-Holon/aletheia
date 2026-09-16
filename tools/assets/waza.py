#!/usr/bin/env python3
"""
waza.py -- decoder for the move data table: `a/0/2/1`, 36-byte records
(struct Waza, per waza_tool.c's accessors), one record per move id.

Written from scratch for aletheia. Stdlib only, depends
only on narc.py.

--------------------------------------------------------------------------
Which 36-byte archive is the move table: `a/0/2/1`, not `a/0/2/4`
--------------------------------------------------------------------------
Both `a/0/2/1` (560 sub-files) and `a/0/2/4` (627 sub-files) hold 36-byte
fixed records. `a/0/2/1` is the move table: record 1's first six bytes
decode (per the field map below) to type=0 (Normal), category=1, power=40,
accuracy=100, pp=35, priority=0 -- Pound's real type/power/accuracy/PP,
found by decoding the bytes with no outside reference beyond the struct
layout waza_tool.c's accessors attest.

`a/0/2/4` is NOT the move table: its records have no plausible
power/accuracy/PP triple (see tools/assets/items.py, which identifies it
as the item data table instead, by the same kind of direct numeric
cross-check -- item 2's price field decodes to 1200, item 3's to 600,
item 4's to 200, which are real Black/White shop prices, and `a/0/2/4`'s
record layout also matches the real item accessor in
src/matched/unit_02021014.c field-for-field).

--------------------------------------------------------------------------
Record layout (36 bytes, struct Waza)
--------------------------------------------------------------------------
Combined from the two partial `struct Waza` declarations in
src/matched/unit_0201BD28.c (offsets 0x00-0x1E, the dense-switch getter)
and src/matched/unit_0201BEB8.c (offset 0x20, the flag-bit test and the
packed-triple reader). Field names follow those files' `unkXX` spelling;
a label is given only where a file's own comment or an accessor name
confirms it.

    0x00  u8   unk00
    0x01  u8   type                  move type id (case 0; Pound -> 0,
                                      Normal, matching waza_tool's own
                                      type-id space)
    0x02  u8   category              case 1, no label in source but reads
                                      as physical/special/status here
    0x03  u8   power                 case 2 (Pound -> 40)
    0x04  u8   accuracy              case 3; sub_0201BDB4 substitutes 0x64
                                      for a stored 0x65 (101 -> 100, an
                                      "always hits" sentinel normalised on
                                      read) (Pound -> 100)
    0x05  u8   pp                    base PP, case 5 and the PP-with-PP-Up
                                      calculation in
                                      src/matched/unit_0201C158.c
                                      (Pound -> 35)
    0x06  s8   priority               case 6, signed
    0x07  u8   bitfield: lo:4 hi:4    case 9 (lo), case 8 (hi)
    0x08  u16  effect                 case 11 (the only 16-bit field in the
                                      low half, large enough to be an
                                      effect id)
    0x0A  u8   unk0A                  case 12
    0x0B  u8   unk0B                  case 13
    0x0C  u8   unk0C                  case 14
    0x0D  u8   unk0D                  case 15
    0x0E  u8   unk0E                  case 7; sub_0201BDB4 substitutes 0
                                      for a stored 6
    0x0F  u8   unk0F                  case 10
    0x10  u16  unk10                  case 28
    0x12  s8   recoil_drain           cases 25 (positive part) / 30
                                      (negated, if negative); data check,
                                      see below
    0x13  s8   unk13                  cases 26 (positive part) / 31
                                      (negated, if negative)
    0x14  u8   unk14                  case 27
    0x15  u8[3] hit_flags             cases 16,19,22; count of set bytes
                                      read by src/matched/unit_0201C020.c's
                                      sub_0201C020
    0x18  s8[3] hit_values            cases 17,20,23, signed (register
                                      ldrsb in sub_0201C0BC)
    0x1B  u8[3] unk1B                 cases 18,21,24
    0x1E  u16   unk1E                 not reached by any case id in
                                      sub_0201BD28 (id 29 is a gap in the
                                      switch); no accessor attests it, and a
                                      data check (below) finds it is not
                                      per-move data either
    0x20  u32   flags                 bit-tested by sub_0201BF44; three
                                      bits identified by data check, see
                                      below (bit 0 = contact, bit 3 =
                                      protectable, bit 5 = heal)

--------------------------------------------------------------------------
Sanity check (move 1, Pound)
--------------------------------------------------------------------------
    type=0 (Normal)  category=1  power=40  accuracy=100  pp=35  priority=0

All four of the task's named Pound values (Normal/40/100/35) decode
exactly from the raw bytes with no substitution needed (the stored
accuracy byte is already 100, not 101).

--------------------------------------------------------------------------
0x1E: a data check, not just a code gap
--------------------------------------------------------------------------
`sub_0201BD28`'s case-id switch has no case for id 29, so no accessor in
this pass reads +0x1E through the field-id interface. A data check closes
the question a different way: decoded across every one of the archive's
560 records, +0x1E is the constant value 21331 (0x5353, i.e. the two
bytes 'S','S') with zero exceptions. A per-move field would vary; a
constant that is the same on Pound, Karate Chop, Tackle, Take Down, Ember,
Recover, Softboiled, Double-Edge, Absorb and Giga Drain (and every other
record checked) is not move data, it is a fixed pad/marker value left in
the two bytes the switch's own gap already said nothing reads. Decoded
and round-tripped as `unk1E`, not renamed, because "always 0x5353" is not
a semantic label.

--------------------------------------------------------------------------
Contact, protect, recoil and heal: a data check against Pound, Karate
Chop and eight other moves with known real values
--------------------------------------------------------------------------
The mission asked for contact/protect/recoil/heal specifically. Pound and
Karate Chop alone cannot separate these (both are ordinary contact
physical attacks, so every flag they'd need is identical between the
two), so this check adds eight more moves chosen because their real
values are unambiguous and pairwise distinguish the candidates: Tackle
(id 33), Take Down (id 36, 25% recoil), Ember (id 52, ranged, no
contact), Recover (id 105, pure self-heal), Softboiled (id 111, pure
self-heal), Counter (id 68, contact but fixed-value damage),
Double-Edge (id 38, 33% recoil) and Absorb / Giga Drain (ids 71 / 202,
50% HP-drain). Every move's power/accuracy/pp/priority decodes to its
real Black/White value first (e.g. Take Down 90/85/20, Double-Edge
120/100/15, Giga Drain 75/100/10), which is what pins each id to the real
move before its flags are read.

**Recoil and drain are the signed byte at +0x12, not a flags bit.**
Tackle (no recoil) and Take Down (25% recoil) have byte-identical +0x20
flags words (0x49), so recoil cannot be a bit in that word. +0x12 is 0 for
every non-recoil, non-drain move checked, -25 for Take Down, -33 for
Double-Edge (33% recoil, matches exactly) and +50 for both Absorb and
Giga Drain (50% HP drain, matches exactly for both). Negative = recoil
percent taken by the user, positive = drain percent healed to the user;
same signed field, opposite sign. This is `recoil_drain` in the field map
above, sourced from cases 25/30 (the "positive part" / "negated if
negative" pair `sub_0201BD28`'s own comment already describes for this
byte, just not by name).

**+0x20 bit 0 is contact.** Set on Pound, Karate Chop, Tackle, Take Down
and Counter (all real contact moves); clear on Ember, Recover and
Softboiled (none of which touch the target). `flags` bit 0 in the module
below.

**+0x20 bit 3 is protectable.** Set on every damaging move checked,
contact or not (Pound, Karate Chop, Tackle, Take Down, Ember, Counter);
clear on the two pure self-target heals (Recover, Softboiled), which
Protect has nothing to block since they never target an opponent.

**+0x20 bit 5 is heal.** Clear on every damaging move checked; set only
on Recover and Softboiled, the two moves in this sample whose entire
effect is restoring the user's own HP.

Bit 6 is also seen to vary (set on Pound/Karate Chop/Tackle/Take
Down/Ember, clear on Counter/Recover/Softboiled) but is not one of the
four the mission named, and nothing checked here pins a single semantic
label to it (Counter's fixed, non-`power`-derived damage is the one
obvious property that sets it apart from the other contact moves in the
sample, but that is a hypothesis, not an attested reading), so it stays
an unnamed bit in `flags`.

--------------------------------------------------------------------------
CLI
--------------------------------------------------------------------------
    python tools/assets/waza.py --list [--limit N]
    python tools/assets/waza.py --dump N
    python tools/assets/waza.py --verify
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402

ARCHIVE = "a/0/2/1"
DATA_ROOT = os.path.join("extract", "data")
RECORD_STRIDE = 36

FIELDS = [
    ("unk00", "B"), ("type", "B"), ("category", "B"), ("power", "B"),
    ("accuracy", "B"), ("pp", "B"), ("priority", "b"),
    ("lohi", "B"),
    ("effect", "H"),
    ("unk0A", "B"), ("unk0B", "B"), ("unk0C", "B"), ("unk0D", "B"),
    ("unk0E", "B"), ("unk0F", "B"),
    ("unk10", "H"),
    ("recoil_drain", "b"), ("unk13", "b"), ("unk14", "B"),
    ("hit_flags", "3s"), ("hit_values", "3s"), ("unk1B", "3s"),
    ("unk1E", "H"),
    ("flags", "I"),
]
RECORD_FMT = "<" + "".join(f for _, f in FIELDS)
assert struct.calcsize(RECORD_FMT) == RECORD_STRIDE


class WazaError(Exception):
    pass


def _open():
    return narc.parse_file(os.path.join(DATA_ROOT, *ARCHIVE.split("/")))


def parse_record(raw):
    if len(raw) != RECORD_STRIDE:
        raise WazaError(f"expected {RECORD_STRIDE}-byte record, got {len(raw)}")
    vals = struct.unpack(RECORD_FMT, raw)
    rec = dict(zip((name for name, _ in FIELDS), vals))
    lohi = rec.pop("lohi")
    rec["lo"] = lohi & 0xF
    rec["hi"] = (lohi >> 4) & 0xF
    rec["hit_flags"] = list(rec["hit_flags"])
    rec["hit_values"] = list(struct.unpack("<3b", rec["hit_values"]))
    rec["unk1B"] = list(rec["unk1B"])
    return rec


def pack_record(rec):
    lohi = (rec["lo"] & 0xF) | ((rec["hi"] & 0xF) << 4)
    vals = []
    for name, _ in FIELDS:
        if name == "lohi":
            vals.append(lohi)
        elif name == "hit_flags":
            vals.append(bytes(rec["hit_flags"]))
        elif name == "hit_values":
            vals.append(struct.pack("<3b", *rec["hit_values"]))
        elif name == "unk1B":
            vals.append(bytes(rec["unk1B"]))
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
        print(f"#{idx:3d}: type={r['type']:2d} category={r['category']} "
              f"power={r['power']:3d} accuracy={r['accuracy']:3d} "
              f"pp={r['pp']:2d} priority={r['priority']:2d} "
              f"effect={r['effect']:4d} flags=0x{r['flags']:08x}")


def cmd_dump(args):
    n, _ = load_records()
    idx = args.dump
    if idx < 0 or idx >= n.file_count:
        print(f"record index must be 0..{n.file_count - 1}")
        return 1
    r = parse_record(n.read(idx))
    for name, _ in FIELDS:
        if name == "lohi":
            continue
        print(f"  {name:12s} = {r[name]}")
    print(f"  lo           = {r['lo']}")
    print(f"  hi           = {r['hi']}")
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
