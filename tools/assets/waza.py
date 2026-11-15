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
decode (per the field map below) to type=0 (Normal), damageType=1,
power=40, accuracy=100, basePP=35, priority=0: Pound's real
type/power/accuracy/PP.

`a/0/2/4` is NOT the move table: its records have no plausible
power/accuracy/PP triple (see tools/assets/items.py, which identifies it
as the item data table instead, by the same kind of direct numeric
cross-check -- item 2's price field decodes to 1200, item 3's to 600,
item 4's to 200, which are real Black/White shop prices, and `a/0/2/4`'s
record layout also matches the real item accessor in
src/matched/unit_02021014.c field-for-field).

--------------------------------------------------------------------------
Record layout (36 bytes, struct WazaData)
--------------------------------------------------------------------------
The game's own `struct WazaData` in src/game/arm9/waza_tool.c (matched
code). The field names are the struct's names. "case N" is the param id
that WAZA_TOOL_GetParam returns the field for.

    0x00  u8    type            case 0 (Normal 0, Fighting 1, Fire 9,
                                Electric 12, Ice 14)
    0x01  u8    category        case 1, the effect group (4 for Fire,
                                Ice and Thunder Punch, Flamethrower and
                                Thunderbolt: damage with a status chance)
    0x02  u8    damageType      case 2: 0 status, 1 physical, 2 special
    0x03  u8    power           case 3
    0x04  u8    accuracy        case 4; a stored 101 (always hits) reads
                                as 100
    0x05  u8    basePP          case 5
    0x06  s8    priority        case 6
    0x07  u8    hitMin:4        case 9 (low nibble)
          u8    hitMax:4        case 8 (high nibble)
    0x08  u16   sickId          case 11
    0x0A  u8    sickPercent     case 12
    0x0B  u8    sickContType    case 13
    0x0C  u8    sickTurnMin     case 14
    0x0D  u8    sickTurnMax     case 15
    0x0E  u8    criticalRank    case 7; a stored 6 reads as 0
    0x0F  u8    shrinkPercent   case 10
    0x10  u16   effectSequence  case 28
    0x12  s8    drainRatio      case 25 (positive: drain) / 30 (negative,
                                negated: recoil); data check below
    0x13  s8    healRatio       case 26 (positive) / 31 (negative, negated)
    0x14  u8    target          case 27
    0x15  u8[3] rankType        cases 16, 19, 22
    0x18  s8[3] rankValue       cases 17, 20, 23
    0x1B  u8[3] rankPercent     cases 18, 21, 24
    0x1E  u8[2] pad             no case reads it (id 29 has no label);
                                the data check below finds 'SS' in every
                                record
    0x20  u32   flags           read by WAZA_TOOL_GetFlag; three bits
                                identified by the data check below (bit 0
                                contact, bit 3 protectable, bit 5 heal)

An earlier version of this tool started the map one byte late: it read
`category` as the type, `damageType` as the category and `sickId` as the
effect. Pound, the old sanity check, has 0 in both of the first two
bytes, so the check could not see it. Karate Chop (type 1, category 0)
and the three elemental punches (types 9, 14, 12, category 4) do.

--------------------------------------------------------------------------
Sanity check (moves 1, 2 and 7: Pound, Karate Chop, Fire Punch)
--------------------------------------------------------------------------
    Pound        type=0 (Normal)    damageType=1  power=40  accuracy=100  basePP=35
    Karate Chop  type=1 (Fighting)  damageType=1  power=50  accuracy=100  basePP=25
    Fire Punch   type=9 (Fire)      damageType=1  power=75  accuracy=100  basePP=15

`--verify` checks these three records as well as the round trip.

--------------------------------------------------------------------------
0x1E: a data check, not just a code gap
--------------------------------------------------------------------------
WAZA_TOOL_GetParam's switch has no case for id 29, so no param id reads
+0x1E. A data check closes
the question a different way: decoded across every one of the archive's
560 records, +0x1E is the constant value 21331 (0x5353, i.e. the two
bytes 'S','S') with zero exceptions. A per-move field would vary; a
constant that is the same on Pound, Karate Chop, Tackle, Take Down, Ember,
Recover, Softboiled, Double-Edge, Absorb and Giga Drain (and every other
record checked) is not move data, it is a fixed pad/marker value left in
the two bytes the switch's own gap already said nothing reads. The game's
struct calls them `pad[2]`.

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
same signed field, opposite sign. This is the game's `drainRatio`
(param 25 returns the positive part, param 30 the negated negative part).

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
    ("type", "B"), ("category", "B"), ("damageType", "B"), ("power", "B"),
    ("accuracy", "B"), ("basePP", "B"), ("priority", "b"),
    ("hitMinMax", "B"),
    ("sickId", "H"),
    ("sickPercent", "B"), ("sickContType", "B"), ("sickTurnMin", "B"),
    ("sickTurnMax", "B"), ("criticalRank", "B"), ("shrinkPercent", "B"),
    ("effectSequence", "H"),
    ("drainRatio", "b"), ("healRatio", "b"), ("target", "B"),
    ("rankType", "3s"), ("rankValue", "3s"), ("rankPercent", "3s"),
    ("pad", "2s"),
    ("flags", "I"),
]
RECORD_FMT = "<" + "".join(f for _, f in FIELDS)
assert struct.calcsize(RECORD_FMT) == RECORD_STRIDE

# Records the --verify sanity check decodes: (move id, name, type,
# damageType, power, accuracy, basePP).
KNOWN = [
    (1, "Pound", 0, 1, 40, 100, 35),
    (2, "Karate Chop", 1, 1, 50, 100, 25),
    (7, "Fire Punch", 9, 1, 75, 100, 15),
]


class WazaError(Exception):
    pass


def _open():
    return narc.parse_file(os.path.join(DATA_ROOT, *ARCHIVE.split("/")))


def parse_record(raw):
    if len(raw) != RECORD_STRIDE:
        raise WazaError(f"expected {RECORD_STRIDE}-byte record, got {len(raw)}")
    vals = struct.unpack(RECORD_FMT, raw)
    rec = dict(zip((name for name, _ in FIELDS), vals))
    hit = rec.pop("hitMinMax")
    rec["hitMin"] = hit & 0xF
    rec["hitMax"] = (hit >> 4) & 0xF
    rec["rankType"] = list(rec["rankType"])
    rec["rankValue"] = list(struct.unpack("<3b", rec["rankValue"]))
    rec["rankPercent"] = list(rec["rankPercent"])
    return rec


def pack_record(rec):
    vals = []
    for name, _ in FIELDS:
        if name == "hitMinMax":
            vals.append((rec["hitMin"] & 0xF) | ((rec["hitMax"] & 0xF) << 4))
        elif name in ("rankType", "rankPercent"):
            vals.append(bytes(rec[name]))
        elif name == "rankValue":
            vals.append(struct.pack("<3b", *rec["rankValue"]))
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
        print(f"#{idx:3d}: type={r['type']:2d} category={r['category']:2d} "
              f"damageType={r['damageType']} "
              f"power={r['power']:3d} accuracy={r['accuracy']:3d} "
              f"basePP={r['basePP']:2d} priority={r['priority']:2d} "
              f"sickId={r['sickId']:4d} flags=0x{r['flags']:08x}")


def cmd_dump(args):
    n, _ = load_records()
    idx = args.dump
    if idx < 0 or idx >= n.file_count:
        print(f"record index must be 0..{n.file_count - 1}")
        return 1
    r = parse_record(n.read(idx))
    for name, _ in FIELDS:
        if name == "hitMinMax":
            print(f"  {'hitMin':14s} = {r['hitMin']}")
            print(f"  {'hitMax':14s} = {r['hitMax']}")
            continue
        print(f"  {name:14s} = {r[name]}")
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
    for move, name, *want in KNOWN:
        r = parse_record(n.read(move))
        got = [r["type"], r["damageType"], r["power"], r["accuracy"], r["basePP"]]
        if got != want:
            bad += 1
            print(f"SANITY #{move} {name}: type/damageType/power/accuracy/basePP "
                  f"{got} != {want}")
    if not bad:
        print(f"[*] {len(KNOWN)} known moves decode to their real values")
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
