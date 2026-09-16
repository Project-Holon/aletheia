#!/usr/bin/env python3
"""
fixtures.py -- generate the expected values port/tests/ asserts against.

The two port tests are data driven: they run matched game C over the
player's own extracted assets and compare against numbers produced here,
independently, in Python.  This file is the "independently" half.  It is
run at build time by port/CMakeLists.txt and writes one header into the
build directory; nothing it produces is committed, because the expected
values are derived from game data.

Two fixtures:

  text    a few (sub-file, entry) pairs of a/0/0/2 decoded with
          tools/assets/text.py, emitted as their u16 code-unit runs.
          text.py's cipher is itself read off src/matched/func_02045E3C.c,
          so this is not an independent derivation of the *cipher*; what
          the test proves is that the compiled matched C, run on the host
          against the real archive, reproduces it code unit for code unit,
          including the descriptor arithmetic and the terminator search.

  stats   three (species, level, IVs, EVs, nature) cases put through a
          transcription of the formula documented in
          src/matched/sub_02018A7C.c:

              maxHP = (base*2 + iv + ev/4) * level / 100 + level + 10
              stat  = ((base*2 + iv + ev/4) * level / 100 + 5) scaled

          with the scale taken from the 25 x 5 nature table at ARM9
          0x0209E324 exactly as src/matched/unit_02019B04.c indexes it,
          including its two u16 truncations.  Base stats come from the
          first six bytes of the 0x3C-byte personal record in a/0/1/6, the
          same record the C reads.  The transcription is written from
          those two matched sources and from nothing else.

Usage:

    python tools/port/fixtures.py --data-root extract/data \\
        --out build/port/bw_fixtures.h
"""

from __future__ import annotations

import argparse
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "tools", "assets"))

import narc  # noqa: E402  (tools/assets/narc.py)
import text  # noqa: E402  (tools/assets/text.py)

# The entries the text fixture covers.  Sub-file 70 is the species-name bank
# (tools/assets/text.py's own worked example); the indices are the four that
# file names, plus entry 0, which is the bank's placeholder run.
TEXT_CASES = [
    (70, 0),
    (70, 1),
    (70, 19),
    (70, 51),
    (70, 100),
]

# (species, level, ivs, evs, nature).  IVs and EVs are in the stat order the
# matched C reads them in: HP, attack, defence, speed, sp. attack, sp. defence.
# The natures are picked so that one case is neutral, one raises attack and
# lowers sp. attack, and one raises sp. defence and lowers defence, so that
# both arms of unit_02019B04.c's switch and its default are exercised.
STAT_CASES = [
    (1,   50,  (31, 31, 31, 31, 31, 31), (0, 0, 0, 0, 0, 0),        0),
    (25, 100,  (31, 30, 29, 28, 27, 26), (252, 252, 4, 0, 0, 0),    3),
    (384, 70,  (20, 15, 10, 25, 5, 0),   (0, 100, 200, 8, 12, 60),  21),
]

NATURE_TABLE_ADDRESS = 0x0209E324
ARM9_LOAD_ADDRESS = 0x02004000
NATURE_COUNT = 25
NATURE_STATS = 5
PERSONAL_RECORD_SIZE = 0x3C

# func_02019B04's `n` per stat, from the five `movs r2, #k` immediates in
# src/matched/sub_02018A7C.c: attack 1, defence 2, speed 5, sp. attack 3,
# sp. defence 4.  base[] is indexed 1..5 in that same visiting order.
STAT_N = [1, 2, 5, 3, 4]


def u16(x):
    return x & 0xFFFF


def nature_scale(value, nature, n, table):
    """src/matched/unit_02019B04.c, transcribed."""
    if n >= 6:
        return value
    v = table[nature][n - 1]
    if v == 1:
        return u16(u16(value * 0x6E) // 100)
    if v == -1:
        return u16(u16(value * 0x5A) // 100)
    return value


def compute_stats(species, base, level, ivs, evs, nature, table):
    """src/matched/sub_02018A7C.c, transcribed.  Returns the six writes in
    field-id order 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, plus current HP."""
    if len(base) < 6:
        raise SystemExit("fixtures.py: personal record too short")

    # The one content constant in the function: species 292 has max HP 1
    # whatever its level, IVs or EVs are.  No fixture case uses it; the arm is
    # transcribed anyway so the transcription is the whole function.
    if species == 292:
        new_max = 1
    else:
        new_max = (base[0] * 2 + ivs[0] + evs[0] // 4) * level // 100 + level
        new_max = new_max + 10

    out = [new_max]
    for i in range(1, 6):
        stat = (base[i] * 2 + ivs[i] + evs[i] // 4) * level // 100 + 5
        out.append(nature_scale(u16(stat), nature, STAT_N[i - 1], table))

    # cur and oldMax both start at 0 in the test harness, so the tail takes
    # `cur == 0 -> cur = newMax` and writes it.
    cur = new_max
    return out, cur


def read_nature_table(data_root):
    arm9 = os.path.join(os.path.dirname(os.path.abspath(data_root)), "arm9_dec.bin")
    if not os.path.exists(arm9):
        raise SystemExit("fixtures.py: %s not found; run tools/ndsrom.py extract first" % arm9)
    with open(arm9, "rb") as fh:
        blob = fh.read()
    off = NATURE_TABLE_ADDRESS - ARM9_LOAD_ADDRESS
    raw = blob[off:off + NATURE_COUNT * NATURE_STATS]
    if len(raw) != NATURE_COUNT * NATURE_STATS:
        raise SystemExit("fixtures.py: nature table out of range of arm9_dec.bin")
    return [
        list(struct.unpack("<5b", raw[i * NATURE_STATS:(i + 1) * NATURE_STATS]))
        for i in range(NATURE_COUNT)
    ]


def read_personal(data_root, species):
    path = os.path.join(data_root, "a", "0", "1", "6")
    arc = narc.parse_file(path)
    rec = arc.read(species)
    if len(rec) < PERSONAL_RECORD_SIZE:
        raise SystemExit("fixtures.py: personal record %d is %d bytes" % (species, len(rec)))
    return rec[:PERSONAL_RECORD_SIZE]


def emit(out, data_root):
    lines = []
    w = lines.append

    w("/*")
    w(" * bw_fixtures.h -- GENERATED, do not edit and do not commit.")
    w(" *")
    w(" * Written by tools/port/fixtures.py from the player's own extracted")
    w(" * assets.  Holds decoded text and computed stat totals only: no ROM")
    w(" * bytes, no archive images, no tables.")
    w(" */")
    w("#ifndef BW_FIXTURES_H")
    w("#define BW_FIXTURES_H")
    w("")

    # ---- text -------------------------------------------------------
    w("typedef struct BwTextFixture {")
    w("    unsigned int    subfile;")
    w("    unsigned int    entry;")
    w("    unsigned int    length;      /* code units, terminator excluded */")
    w("    const unsigned short *units; /* terminator excluded             */")
    w("} BwTextFixture;")
    w("")

    narc_path = os.path.join(data_root, "a", "0", "0", "2")
    banks = {}
    for i, (sub, entry) in enumerate(TEXT_CASES):
        if sub not in banks:
            banks[sub] = text.load_message_file(narc_path, sub)
        plain = banks[sub].decode(entry)
        if plain is None:
            raise SystemExit("fixtures.py: a/0/0/2 sub-file %d entry %d did not decode"
                             % (sub, entry))
        if plain and plain[-1] == text.TERMINATOR:
            plain = plain[:-1]
        body = ", ".join("0x%04X" % c for c in plain) or "0"
        w("static const unsigned short bw_text_units_%d[] = { %s };" % (i, body))
    w("")
    w("static const BwTextFixture bw_text_fixtures[] = {")
    for i, (sub, entry) in enumerate(TEXT_CASES):
        w("    { %du, %du, (unsigned int)(sizeof(bw_text_units_%d) / sizeof(unsigned short)), bw_text_units_%d },"
          % (sub, entry, i, i))
    w("};")
    w("#define BW_TEXT_FIXTURE_COUNT (sizeof(bw_text_fixtures) / sizeof(bw_text_fixtures[0]))")
    w("")

    # ---- stats ------------------------------------------------------
    table = read_nature_table(data_root)

    w("typedef struct BwStatFixture {")
    w("    unsigned int species;")
    w("    int          level;")
    w("    int          nature;")
    w("    int          iv[6];   /* hp, atk, def, spe, spa, spd */")
    w("    int          ev[6];")
    w("    int          base[6]; /* what a/0/1/6 says, for the report line */")
    w("    int          expect[6];  /* field 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6 */")
    w("    int          expect_cur; /* field 0xA0 */")
    w("} BwStatFixture;")
    w("")
    w("static const BwStatFixture bw_stat_fixtures[] = {")
    for species, level, ivs, evs, nature in STAT_CASES:
        rec = read_personal(data_root, species)
        base = list(rec[:6])
        expect, cur = compute_stats(species, base, level, ivs, evs, nature, table)
        w("    { %du, %d, %d, { %s }, { %s }, { %s }, { %s }, %d }," % (
            species, level, nature,
            ", ".join(str(v) for v in ivs),
            ", ".join(str(v) for v in evs),
            ", ".join(str(v) for v in base),
            ", ".join(str(v) for v in expect),
            cur,
        ))
    w("};")
    w("#define BW_STAT_FIXTURE_COUNT (sizeof(bw_stat_fixtures) / sizeof(bw_stat_fixtures[0]))")
    w("")
    w("#endif /* BW_FIXTURES_H */")

    body = "\n".join(lines) + "\n"
    parent = os.path.dirname(os.path.abspath(out))
    if parent:
        os.makedirs(parent, exist_ok=True)
    with open(out, "w", encoding="utf-8") as fh:
        fh.write(body)
    print("[*] wrote %s (%d text, %d stat fixtures)"
          % (out, len(TEXT_CASES), len(STAT_CASES)))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[1])
    ap.add_argument("--data-root", default=os.path.join(ROOT, "extract", "data"))
    ap.add_argument("--out", required=True)
    args = ap.parse_args(argv)

    if not os.path.isdir(args.data_root):
        raise SystemExit("fixtures.py: data root %s does not exist; run "
                         "`python tools/ndsrom.py extract <your-rom>.nds -o extract` first"
                         % args.data_root)
    emit(args.out, args.data_root)
    return 0


if __name__ == "__main__":
    sys.exit(main())
