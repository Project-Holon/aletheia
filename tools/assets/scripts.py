#!/usr/bin/env python3
"""
scripts.py -- decoder for `a/0/5/7` (899 sub-files), the field-script
bytecode archive run by the game's own script virtual machine ("vm.c",
src/matched/unit_0201126C.c and unit_02011330.c), dispatching through the
609-entry handler table at 0x0217062C in overlay 10 (see docs/ASSETS.md,
"Script virtual machine located and decompiled" section).

Written from scratch for the aletheia asset lane. Stdlib only.

--------------------------------------------------------------------------
Container framing (confirmed: 469 / 899 sub-files carry it)
--------------------------------------------------------------------------
A script sub-file is:
    N * u32   entry offset table: table[0], table[1], ..., table[N-1]
    u16       terminator, always 0xFD13, immediately after the table
    ...       code, immediately after the terminator

Entry k's code starts at byte offset `4*k + 4 + table[k]` from the start of
the sub-file. This is exactly what the VM loader does (func_02158BFC,
ov010): `pc = buf + 4*k`, then `func_0201134C` reads a u32 at `pc` and
advances `pc` by 4 -- the word it reads IS `table[k]` -- so the final pc is
`4*k + 4 + table[k]`.

The table length N is found by scanning u32-aligned words from the start of
the file for the first one whose low 16 bits equal the terminator
(0xFD13); N is that word's index. The remaining 428 / 899 sub-files carry
no 0xFD13 anywhere and range 4 to 6020 bytes: small side tables sharing
this archive, not scripts. --list reports both kinds; only the script
sub-files are scored by --check and walked by --disasm.

--------------------------------------------------------------------------
Zone script lane pairs a script sub-file with its side table (CONFIRMED)
--------------------------------------------------------------------------
The zone record's `+0x06`/`+0x08` lane (`field_06`/`field_08` in
tools/assets/zones.py, `field_08 == field_06 + 1` on every one of the 427
zones) indexes this archive directly: `field_06 == 2 * zone_id` on
427/427 zones (never `2 * zone_id + 1`), so the pair is `(2*zone_id,
2*zone_id + 1)`. Read against the real archive, for every one of the 427
zones exactly one of the two sub-files is a script (has the 0xFD13 entry
table) and the other is a side table (427/427, no exceptions, no zone
with both-script or both-side-table) -- this is the "script sub-file
paired with its side table" structure the mission asked to test, and it
holds without exception. 428 side tables exist in the archive but only
427 are reached by a zone's pair; the one extra is sub-file 865 (6020
bytes, itself shaped like a repeating-record table, not a script) --
matching "428 is 427 zones plus one" exactly: 427 are each a zone's
script's side table, the 428th is unpaired and not read through this
lane.

The side tables' own framing (record size, count) is decoded from their
sizes alone, not from any trusted header count: see "Side tables" below.
No code was found that reads archive id 0x39 (`a/0/5/7`) a second time
at a different sub-file index to reach a zone's side table specifically:
`func_02158D78` (ov010) is the only site that loads archive 0x39 anywhere
in the image (grepped archive-wide, ARM9 + every overlay, for the literal
immediate 0x39 ahead of a NARC-family load call), and it is called exactly
once per script start, with the single index that is `field_06`'s value
(the script half of the pair, per `func_02158CD0`'s `sub_02013B5C`
read). `field_08` (`field_06 + 1`, the side-table half) has no accessor
of its own anywhere this pass found -- consistent with zones.py's own
note that +0x08 is read by nothing -- so the side table is reached (if it
is read by the running game at all, rather than being build-time-only
data) through some path this pass did not locate, not through a second
archive-0x39 load next to `func_02158D78`/`func_02158BFC`.

--------------------------------------------------------------------------
Bytecode: one little-endian u16 opcode, then its operand bytes
--------------------------------------------------------------------------
The interpreter (func_02011298, src/matched/unit_0201126C.c) fetches the
opcode with func_02011330 (u16, pc += 2), bounds-checks it against the
609-entry table, then calls `cmds[opcode](vm, user)`. Each handler then
fetches its own operands directly off the same cursor (vm->pc, +0x14 of the
ScriptVm struct) through func_02011330 (u16, +2 bytes) and/or
func_0201134C (u32, +4 bytes), sometimes through one or more levels of
helper (the common "variable id" operand, for instance, is fetched inside
a helper at 0x02159AE8 rather than in the handler itself).

OPERAND_WIDTH below gives, for every opcode 0-608: the total operand byte
count (the opcode's own halfword excluded), the width's source, and one of
four kinds:

    fixed       every reachable path through the handler (and the one or
                more levels of callee inspected) fetches exactly this many
                operand bytes. Source is the handler's own address.
    variable    the handler does not fetch a fixed number of bytes --
                either it reads raw bytes directly off the pc cursor
                (bypassing func_02011330/func_0201134C entirely, usually a
                length-prefixed tail) or it branches through a register
                (an indirect/case-table jump whose targets this pass did
                not enumerate). Source names the address and the rule.
    null        the 609-entry table has a NULL entry at this opcode (9 of
                them); the opcode is never dispatched.
    unresolved  the handler's resolved address falls in an overlay this
                pass did not load (17 of them; all in the 0x0217xxxx/
                0x0218xxxx range, neither ov010 nor ov021 nor the ARM9
                static module).

Opcodes 0-31 are taken verbatim from docs/ASSETS.md's hand-read table (the
ground truth this module extends, not re-derived here). Opcodes 32-608 were
produced by tools' own from-scratch Thumb-1 + 32-bit BL/BLX sweep over the
raw overlay and ARM9 bytes (extract/overlays_dec/y9_0010.bin,
extract/overlays_dec/y9_0021.bin, extract/arm9_dec.bin): a worklist walk of
each handler's reachable instructions, following one-or-more levels of
`bl` callee (capped, with a cycle guard) and summing +2/+4 for every call
that resolves (directly, or through a `ldr r3,[pc,#0]; bx r3` veneer) to
func_02011330 / func_0201134C, plus a dedicated check for the direct
`ldr rD,[rB,#0x14]; ldrb rT,[rD]` idiom (a raw read off ScriptVm.pc that
bypasses both fetch helpers). The sweep is not re-run by this module at
import time -- its result is baked in below as data, per opcode, with the
handler address it was read off so any entry can be re-checked against
asm/overlays/ov010.s / ov021.s by hand.

Opcode 76 is the table's best-understood "variable" case: its handler
(0x021AF75C) reads a length byte directly off the cursor
(`ldr r2,[r5,#0x14]; ldrb r1,[r2]; adds r2,r2,#1; str r2,[r5,#0x14]`) before
any further operand bytes -- a length-prefixed tail whose size --check
cannot predict, consistent with it being the single largest source of
desyncs in the previous pass's decode statistic (100 of 232).

STOP_OPS are opcodes whose handler stops the VM outright (sub_02011290):
{2, 29, 140, 342, 359, 378}. FLOW_END_OPS are opcodes whose handler jumps
or returns through the call-history ring (sub_020113B0 / func_020113C4),
so linear flow cannot continue past them: {5, 30, 31}. CALL_OP (4) fetches
a u32, adds it to the pc and calls func_020113B4 -- execution returns right
after it, but the added target is also a reachable entry point in its own
right, so --disasm follows it.

--------------------------------------------------------------------------
Side tables: framing (CONFIRMED, 428/428) and the pairing test
--------------------------------------------------------------------------
See the "Zone script lane pairs a script sub-file with its side table"
section above for the 427-zone pairing test. The side tables' own byte
framing, read purely from each sub-file's size (`parse_side_table`):

    4-byte header (2 x u16, not a trustworthy record count -- two
    different sub-files of the same size carry different header values,
    e.g. zone 1/8's 16-byte side table has header (4, 10395) while zone
    6/10's has (1, 2))
    (len(raw) - 4) // 4 records, each 2 x u16

`(len(raw) - 4) % 4 == 0` holds on every one of the 428 side tables in
the archive (sizes 4, 8, 12, 16, 20, 24, 28, 36, 40, 48, and the one
6020-byte outlier), so the record count is derived, not guessed. No
semantic meaning is claimed for the header words or the per-record pair.

--------------------------------------------------------------------------
CLI
--------------------------------------------------------------------------
    python tools/assets/scripts.py --list
        Per sub-file: entry count (script) or byte size (side table).

    python tools/assets/scripts.py --disasm N
        Linear-sweep disassembly of every entry in sub-file N, following
        call targets (opcode 4) for reachability. Prints opcode number,
        operand bytes, and target labels.

    python tools/assets/scripts.py --side N
        Decode sub-file N as a side table: header words and every
        (u16, u16) record. Prints an error (no exception) if N is a
        script sub-file instead.

    python tools/assets/scripts.py --verify
        Re-pack every one of the 899 sub-files from its parsed entry
        table (or raw bytes, for a side table) and compare byte-for-byte
        against the original.

    python tools/assets/scripts.py --check
        Archive-wide decode statistic: of every entry point in every
        469 script sub-files, how many land cleanly on a stop/flow-end
        opcode, the next entry point, or the file's end -- versus how many
        desync (opcode >= 609) or hit an unresolved/variable opcode.
"""

import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import narc  # noqa: E402

A0057_PATH = os.path.join("extract", "data", "a", "0", "5", "7")

TERMINATOR = 0xFD13

STOP_OPS = {2, 29, 140, 342, 359, 378}
FLOW_END_OPS = {5, 30, 31}
CALL_OP = 4


class ScriptsError(Exception):
    pass


# opcode -> (kind, width_or_None, source)
#   kind: 'fixed' | 'variable' | 'null' | 'unresolved'
#   source: handler address (0x...) this width was read off, or a rule
OPERAND_WIDTH = {
    0: ('fixed', 0, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    1: ('fixed', 0, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    2: ('fixed', 0, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    3: ('fixed', 2, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    4: ('fixed', 4, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    5: ('fixed', 0, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    6: ('fixed', 2, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    7: ('fixed', 2, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    8: ('fixed', 2, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    9: ('fixed', 2, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    10: ('fixed', 2, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    11: ('fixed', 0, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    12: ('fixed', 0, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    13: ('fixed', 0, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    14: ('fixed', 0, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    15: ('fixed', 0, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    16: ('fixed', 2, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    17: ('fixed', 2, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    18: ('fixed', 4, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    19: ('fixed', 4, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    20: ('fixed', 0, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    21: ('fixed', 4, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    22: ('fixed', 0, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    23: ('fixed', 0, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    24: ('fixed', 0, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    25: ('fixed', 4, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    26: ('fixed', 4, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    27: ('fixed', 6, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    28: ('fixed', 10, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    29: ('fixed', 0, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    30: ('fixed', 4, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    31: ('fixed', 4, 'docs/ASSETS.md operand-width table (handler read, opcodes 0-31)'),
    32: ('variable', None, '0x021596B4: direct cursor byte read at 0x021596B8, bypasses func_02011330/func_0201134C (ldr/ldrb off ScriptVm.pc +0x14)'),
    33: ('fixed', 2, '0x021596E8'),
    34: ('fixed', 2, '0x02159708'),
    35: ('fixed', 2, '0x02159728'),
    36: ('fixed', 2, '0x02159750'),
    37: ('fixed', 4, '0x02159778'),
    38: ('fixed', 4, '0x021597AC'),
    39: ('fixed', 4, '0x021597CC'),
    40: ('fixed', 4, '0x02159894'),
    41: ('fixed', 4, '0x021598AC'),
    42: ('fixed', 4, '0x021598C8'),
    43: ('fixed', 4, '0x021597EC'),
    44: ('fixed', 4, '0x0215980C'),
    45: ('fixed', 4, '0x02159830'),
    46: ('fixed', 0, '0x021B1BB8'),
    47: ('fixed', 0, '0x021598EC'),
    48: ('fixed', 0, '0x02159934'),
    49: ('fixed', 0, '0x02159974'),
    50: ('fixed', 0, '0x02159998'),
    51: ('fixed', 2, '0x021B15C8'),
    52: ('fixed', 4, '0x021B04D8'),
    53: ('fixed', 4, '0x021B0530'),
    54: ('fixed', 0, '0x021B0624'),
    55: ('fixed', 2, '0x021B05AC'),
    56: ('variable', None, '0x021B10D0: indirect branch at 0x021B10D4'),
    57: ('fixed', 0, '0x021B10E8'),
    58: ('fixed', 8, '0x021B1100'),
    59: ('fixed', 2, '0x021B11D8'),
    60: ('fixed', 10, '0x021B0D14'),
    61: ('fixed', 8, '0x021B0D74'),
    62: ('fixed', 0, '0x021B0EDC'),
    63: ('fixed', 0, '0x021B14F4'),
    64: ('fixed', 4, '0x021B063C'),
    65: ('fixed', 0, '0x021B07E0'),
    66: ('fixed', 0, '0x021B0730'),
    67: ('fixed', 4, '0x021B12B0'),
    68: ('fixed', 0, '0x021B13E0'),
    69: ('fixed', 4, '0x021B143C'),
    70: ('fixed', 0, '0x021B14DC'),
    71: ('fixed', 2, '0x021B0130'),
    72: ('fixed', 12, '0x021B0DF0'),
    73: ('fixed', 12, '0x021B0E74'),
    74: ('variable', None, '0x021B10DC: indirect branch at 0x021B10E0'),
    75: ('fixed', 0, '0x021B15B8'),
    76: ('variable', None, '0x021AF75C: direct cursor byte read at 0x021AF780, bypasses func_02011330/func_0201134C (ldr/ldrb off ScriptVm.pc +0x14)'),
    77: ('variable', None, '0x021AF7C4: indirect branch at 0x021AF7C8'),
    78: ('variable', None, '0x021AF7E4: direct cursor byte read at 0x021AF810, bypasses func_02011330/func_0201134C (ldr/ldrb off ScriptVm.pc +0x14)'),
    79: ('variable', None, '0x021AF7D4: indirect branch at 0x021AF7D8'),
    80: ('fixed', 2, '0x021AF844'),
    81: ('fixed', 2, '0x021AF878'),
    82: ('fixed', 2, '0x021AF928'),
    83: ('fixed', 2, '0x021AF958'),
    84: ('fixed', 2, '0x021AF9A4'),
    85: ('fixed', 2, '0x021AF9F0'),
    86: ('fixed', 2, '0x021AF8A8'),
    87: ('variable', None, '0x021AF908: indirect branch at 0x021AF90C'),
    88: ('variable', None, '0x021AF918: indirect branch at 0x021AF91C'),
    89: ('fixed', 2, '0x021AFAC8'),
    90: ('fixed', 2, '0x021AFAFC'),
    91: ('fixed', 2, '0x021AFA38'),
    92: ('fixed', 4, '0x021AFA80'),
    93: ('fixed', 2, '0x0215D884'),
    94: ('fixed', 2, '0x021AFB2C'),
    95: ('fixed', 2, '0x021AFB5C'),
    96: ('fixed', 2, '0x021AFBC4'),
    97: ('variable', None, '0x021AFC18: indirect branch at 0x021AFC1C'),
    98: ('variable', None, '0x021AFC28: indirect branch at 0x021AFC2C'),
    99: ('fixed', 2, '0x021AFB90'),
    100: ('fixed', 6, '0x021B1698'),
    101: ('fixed', 0, '0x021B16F0'),
    102: ('fixed', 4, '0x021B1700'),
    103: ('fixed', 6, '0x021B176C'),
    104: ('fixed', 4, '0x021B17B4'),
    105: ('fixed', 12, '0x021B181C'),
    106: ('fixed', 4, '0x021B19B0'),
    107: ('fixed', 2, '0x021B18E4'),
    108: ('fixed', 2, '0x021B18B8'),
    109: ('fixed', 10, '0x021B1950'),
    110: ('fixed', 2, '0x021B17F8'),
    111: ('fixed', 4, '0x021B1CB0'),
    112: ('fixed', 10, '0x021B1C2C'),
    113: ('fixed', 6, '0x021B2070'),
    114: ('fixed', 8, '0x021B20B0'),
    115: ('fixed', 4, '0x021B1738'),
    116: ('fixed', 0, '0x021B1BF4'),
    117: ('fixed', 2, '0x021B1D20'),
    118: ('fixed', 8, '0x021B1D64'),
    119: ('fixed', 0, '0x021B1E80'),
    120: ('fixed', 2, '0x021B1F60'),
    121: ('fixed', 6, '0x021B19E0'),
    122: ('fixed', 2, '0x021B2104'),
    123: ('fixed', 8, '0x021B1FB8'),
    124: ('fixed', 6, '0x021B2154'),
    125: ('fixed', 8, '0x021B21AC'),
    126: ('fixed', 2, '0x021B2218'),
    127: ('fixed', 4, '0x021AE9F0'),
    128: ('fixed', 2, '0x021AE948'),
    129: ('fixed', 0, '0x021AE994'),
    130: ('fixed', 4, '0x021AEA3C'),
    131: ('fixed', 2, '0x021AE9CC'),
    132: ('fixed', 2, '0x021AEA8C'),
    133: ('fixed', 6, '0x021AEABC'),
    134: ('fixed', 8, '0x021AEB3C'),
    135: ('fixed', 6, '0x021B0EF4'),
    136: ('fixed', 6, '0x021AEBB0'),
    137: ('null', None, 'table entry is NULL'),
    138: ('fixed', 4, '0x021AEC1C'),
    139: ('fixed', 2, '0x021AEC40'),
    140: ('fixed', 0, '0x0215B3AC'),
    141: ('fixed', 2, '0x0215B3DC'),
    142: ('fixed', 0, '0x021AEC84'),
    143: ('null', None, 'table entry is NULL'),
    144: ('null', None, 'table entry is NULL'),
    145: ('null', None, 'table entry is NULL'),
    146: ('fixed', 4, '0x021AECC0'),
    147: ('fixed', 4, '0x021AED00'),
    148: ('fixed', 8, '0x021AED24'),
    149: ('fixed', 2, '0x0215B328'),
    150: ('fixed', 2, '0x0215B350'),
    151: ('fixed', 4, '0x0215B378'),
    152: ('fixed', 2, '0x021AEDE0'),
    153: ('null', None, 'table entry is NULL'),
    154: ('null', None, 'table entry is NULL'),
    155: ('fixed', 4, '0x021AEEC0'),
    156: ('null', None, 'table entry is NULL'),
    157: ('null', None, 'table entry is NULL'),
    158: ('fixed', 0, '0x021AEFD8'),
    159: ('fixed', 2, '0x021AF0BC'),
    160: ('fixed', 0, '0x021AEF00'),
    161: ('fixed', 2, '0x021AF0F8'),
    162: ('fixed', 4, '0x021AF130'),
    163: ('fixed', 2, '0x021AF458'),
    164: ('fixed', 2, '0x021AF484'),
    165: ('fixed', 4, '0x021AF4B0'),
    166: ('fixed', 2, '0x021AF294'),
    167: ('fixed', 0, '0x021AF2BC'),
    168: ('fixed', 0, '0x021AF2E4'),
    169: ('fixed', 2, '0x021AF2F4'),
    170: ('fixed', 0, '0x021AF370'),
    171: ('fixed', 4, '0x021AF380'),
    172: ('fixed', 0, '0x021AF448'),
    173: ('variable', None, '0x021B01DC: direct cursor byte read at 0x021B020E, bypasses func_02011330/func_0201134C (ldr/ldrb off ScriptVm.pc +0x14)'),
    174: ('variable', None, '0x021B024C: direct cursor byte read at 0x021B0280, bypasses func_02011330/func_0201134C (ldr/ldrb off ScriptVm.pc +0x14)'),
    175: ('fixed', 6, '0x021B0344'),
    176: ('fixed', 0, '0x021B0394'),
    177: ('fixed', 0, '0x021B03BC'),
    178: ('variable', None, '0x021B02C8: direct cursor byte read at 0x021B02FC, bypasses func_02011330/func_0201134C (ldr/ldrb off ScriptVm.pc +0x14)'),
    179: ('fixed', 8, '0x021B2830'),
    180: ('fixed', 0, '0x021B2A90'),
    181: ('fixed', 6, '0x021AF544'),
    182: ('fixed', 6, '0x021AF594'),
    183: ('fixed', 6, '0x021AF5E4'),
    184: ('fixed', 6, '0x021AF634'),
    185: ('fixed', 4, '0x021AF684'),
    186: ('fixed', 4, '0x021AF6C4'),
    187: ('fixed', 4, '0x021AF6E8'),
    188: ('fixed', 2, '0x021B5128'),
    189: ('fixed', 4, '0x021AF71C'),
    190: ('fixed', 8, '0x021AFD44'),
    191: ('fixed', 8, '0x021AFE64'),
    192: ('fixed', 10, '0x021AFF7C'),
    193: ('fixed', 6, '0x021AFDAC'),
    194: ('fixed', 8, '0x021AFCD8'),
    195: ('fixed', 0, '0x021AFECC'),
    196: ('fixed', 10, '0x021AFEFC'),
    197: ('fixed', 0, '0x021C459C'),
    198: ('fixed', 2, '0x021C4628'),
    199: ('fixed', 0, '0x021C4678'),
    200: ('fixed', 2, '0x021C46A4'),
    201: ('fixed', 0, '0x0215AA60'),
    202: ('fixed', 2, '0x0215AA90'),
    203: ('fixed', 4, '0x0215AABC'),
    204: ('fixed', 2, '0x0215AADC'),
    205: ('fixed', 2, '0x0215AB18'),
    206: ('fixed', 2, '0x0215AAF4'),
    207: ('fixed', 2, '0x0215AB3C'),
    208: ('fixed', 4, '0x0215AB60'),
    209: ('fixed', 4, '0x0215AB98'),
    210: ('fixed', 2, '0x0215ABD0'),
    211: ('fixed', 2, '0x0215AD38'),
    212: ('fixed', 4, '0x0215ABEC'),
    213: ('fixed', 4, '0x0215AC3C'),
    214: ('fixed', 2, '0x0215AC68'),
    215: ('fixed', 2, '0x0215ACA8'),
    216: ('fixed', 4, '0x0215AEB8'),
    217: ('fixed', 2, '0x0215AD50'),
    218: ('fixed', 6, '0x0215AE34'),
    219: ('fixed', 0, '0x0215AD7C'),
    220: ('fixed', 10, '0x0215ADCC'),
    221: ('fixed', 4, '0x0215AF98'),
    222: ('fixed', 4, '0x0215AEE8'),
    223: ('fixed', 6, '0x0215AF40'),
    224: ('fixed', 2, '0x0215AA50'),
    225: ('fixed', 2, '0x0215AC1C'),
    226: ('fixed', 2, '0x0215B028'),
    227: ('fixed', 0, '0x0215B068'),
    228: ('fixed', 2, '0x0215B084'),
    229: ('fixed', 4, '0x0215B0B4'),
    230: ('fixed', 4, '0x0215B104'),
    231: ('fixed', 2, '0x0215B138'),
    232: ('fixed', 4, '0x0215B158'),
    233: ('fixed', 2, '0x021CFA88'),
    234: ('fixed', 2, '0x0215B190'),
    235: ('fixed', 2, '0x0215CE98'),
    236: ('fixed', 0, '0x0215CEBC'),
    237: ('fixed', 0, '0x0215CEE8'),
    238: ('fixed', 2, '0x0215CFB4'),
    239: ('fixed', 2, '0x0215CFD8'),
    240: ('fixed', 2, '0x0215CF54'),
    241: ('fixed', 2, '0x0215CF84'),
    242: ('fixed', 4, '0x0215CFFC'),
    243: ('fixed', 4, '0x0215D034'),
    244: ('fixed', 4, '0x0215D0A4'),
    245: ('fixed', 4, '0x0215D0D4'),
    246: ('fixed', 4, '0x0215D110'),
    247: ('fixed', 2, '0x0215CF00'),
    248: ('fixed', 4, '0x0215D06C'),
    249: ('fixed', 2, '0x0215C558'),
    250: ('fixed', 2, '0x0215C584'),
    251: ('fixed', 4, '0x0215C5B0'),
    252: ('fixed', 4, '0x0215B704'),
    253: ('fixed', 6, '0x0215B74C'),
    254: ('fixed', 4, '0x0215B7E8'),
    255: ('fixed', 4, '0x0215B824'),
    256: ('fixed', 2, '0x021B627C'),
    257: ('fixed', 4, '0x0215B660'),
    258: ('fixed', 4, '0x0215B6C0'),
    259: ('fixed', 4, '0x0215B888'),
    260: ('fixed', 0, '0x0215B5A8'),
    261: ('fixed', 6, '0x021B631C'),
    262: ('fixed', 2, '0x021B63D4'),
    263: ('fixed', 6, '0x021B5B4C'),
    264: ('fixed', 4, '0x0215BCA0'),
    265: ('fixed', 8, '0x021B636C'),
    266: ('fixed', 6, '0x0215BCE8'),
    267: ('fixed', 6, '0x0215BD2C'),
    268: ('fixed', 8, '0x0215BB50'),
    269: ('fixed', 4, '0x0215B848'),
    270: ('fixed', 18, '0x0215BBD0'),
    271: ('fixed', 6, '0x0215C2D0'),
    272: ('fixed', 6, '0x0215C138'),
    273: ('fixed', 6, '0x0215C0D0'),
    274: ('fixed', 4, '0x0215B5BC'),
    275: ('fixed', 4, '0x0215BE24'),
    276: ('fixed', 4, '0x0215B904'),
    277: ('fixed', 6, '0x0215BAB0'),
    278: ('fixed', 4, '0x0215BAF4'),
    279: ('fixed', 4, '0x0215BF30'),
    280: ('fixed', 6, '0x0215BA18'),
    281: ('fixed', 6, '0x0215C01C'),
    282: ('fixed', 8, '0x0215C064'),
    283: ('fixed', 6, '0x0215B558'),
    284: ('fixed', 6, '0x0215BF7C'),
    285: ('fixed', 2, '0x021B5B8C'),
    286: ('fixed', 2, '0x021B5BFC'),
    287: ('fixed', 4, '0x021B5C80'),
    288: ('fixed', 4, '0x021B65D8'),
    289: ('fixed', 4, '0x0215B994'),
    290: ('fixed', 8, '0x0215C180'),
    291: ('fixed', 18, '0x0215C200'),
    292: ('fixed', 4, '0x021B2E08'),
    293: ('fixed', 0, '0x021B2AB0'),
    294: ('fixed', 8, '0x021B2CE8'),
    295: ('fixed', 8, '0x021B2D34'),
    296: ('fixed', 2, '0x021B2D98'),
    297: ('fixed', 4, '0x021B2DBC'),
    298: ('fixed', 2, '0x021B2E60'),
    299: ('fixed', 6, '0x021B2C08'),
    300: ('fixed', 2, '0x021B2E3C'),
    301: ('fixed', 8, '0x021B2CA0'),
    302: ('fixed', 6, '0x021B2C5C'),
    303: ('fixed', 2, '0x021B2ADC'),
    304: ('fixed', 0, '0x021B2B24'),
    305: ('fixed', 0, '0x021B2B5C'),
    306: ('fixed', 2, '0x021B2B94'),
    307: ('fixed', 2, '0x021B5A18'),
    308: ('fixed', 0, '0x021B69B0'),
    309: ('fixed', 0, '0x021CFA58'),
    310: ('fixed', 4, '0x02166F1C'),
    311: ('fixed', 0, '0x02159A64'),
    312: ('fixed', 6, '0x0215ACC8'),
    313: ('fixed', 2, '0x0215F1C8'),
    314: ('fixed', 2, '0x021B4BEC'),
    315: ('fixed', 2, '0x0215F214'),
    316: ('fixed', 0, '0x0215F228'),
    317: ('fixed', 0, '0x0215F238'),
    318: ('fixed', 0, '0x0215F280'),
    319: ('fixed', 0, '0x021B52FC'),
    320: ('fixed', 0, '0x021B536C'),
    321: ('fixed', 0, '0x021B538C'),
    322: ('fixed', 0, '0x021B53A4'),
    323: ('fixed', 22, '0x021B53BC'),
    324: ('fixed', 2, '0x021B5498'),
    325: ('fixed', 0, '0x021B54FC'),
    326: ('fixed', 4, '0x021B542C'),
    327: ('fixed', 2, '0x021B54D4'),
    328: ('fixed', 16, '0x021B5528'),
    329: ('fixed', 4, '0x021B2FD8'),
    330: ('fixed', 0, '0x0215C5EC'),
    331: ('fixed', 0, '0x0215C610'),
    332: ('fixed', 0, '0x0215C6F0'),
    333: ('fixed', 4, '0x021B4FB0'),
    334: ('fixed', 6, '0x0215C72C'),
    335: ('fixed', 4, '0x021B4D60'),
    336: ('fixed', 2, '0x0215C7E0'),
    337: ('fixed', 4, '0x0215CB08'),
    338: ('fixed', 0, '0x021B4F68'),
    339: ('fixed', 2, '0x0215CBF0'),
    340: ('fixed', 4, '0x0215CA64'),
    341: ('fixed', 2, '0x0215CAB4'),
    342: ('fixed', 2, '0x021B4EE0'),
    343: ('fixed', 0, '0x021CA57C'),
    344: ('fixed', 4, '0x021CA544'),
    345: ('fixed', 0, '0x021CA598'),
    346: ('fixed', 8, '0x021CA5C4'),
    347: ('fixed', 2, '0x021D1A04'),
    348: ('fixed', 0, '0x021D1A54'),
    349: ('fixed', 2, '0x021D1A74'),
    350: ('fixed', 0, '0x021D1AB0'),
    351: ('fixed', 2, '0x021B4C14'),
    352: ('fixed', 2, '0x021B4C34'),
    353: ('fixed', 0, '0x021B4C54'),
    354: ('fixed', 0, '0x021B4C98'),
    355: ('fixed', 0, '0x0215CC38'),
    356: ('fixed', 4, '0x0215CC4C'),
    357: ('fixed', 2, '0x0215CCE8'),
    358: ('fixed', 0, '0x021B4CDC'),
    359: ('variable', None, '0x0215D34C: direct cursor byte read at 0x0215D384, bypasses func_02011330/func_0201134C (ldr/ldrb off ScriptVm.pc +0x14)'),
    360: ('fixed', 2, '0x0215D468'),
    361: ('variable', None, '0x0215D504: direct cursor byte read at 0x0215D512, bypasses func_02011330/func_0201134C (ldr/ldrb off ScriptVm.pc +0x14)'),
    362: ('fixed', 4, '0x0215D7D4'),
    363: ('fixed', 8, '0x0215DB38'),
    364: ('fixed', 2, '0x0215D864'),
    365: ('fixed', 2, '0x0215DADC'),
    366: ('fixed', 4, '0x0215DB00'),
    367: ('unresolved', None, '0x0217CF68: address not in ov010/ov021'),
    368: ('unresolved', None, '0x0217FAE0: address not in ov010/ov021'),
    369: ('unresolved', None, '0x0217CF88: address not in ov010/ov021'),
    370: ('fixed', 0, '0x0215C95C'),
    371: ('unresolved', None, '0x0217F648: address not in ov010/ov021'),
    372: ('unresolved', None, '0x0217FB2C: address not in ov010/ov021'),
    373: ('unresolved', None, '0x0217F8A0: address not in ov010/ov021'),
    374: ('unresolved', None, '0x0217F8D0: address not in ov010/ov021'),
    375: ('unresolved', None, '0x0217F914: address not in ov010/ov021'),
    376: ('fixed', 6, '0x021B503C'),
    377: ('fixed', 0, '0x021B5094'),
    378: ('fixed', 0, '0x0215B408'),
    379: ('fixed', 2, '0x0215B438'),
    380: ('fixed', 2, '0x021B50D0'),
    381: ('fixed', 0, '0x021B50F8'),
    382: ('unresolved', None, '0x021F4650: address not in ov010/ov021'),
    383: ('fixed', 4, '0x0215CD3C'),
    384: ('fixed', 2, '0x021B2380'),
    385: ('fixed', 2, '0x021B23B8'),
    386: ('fixed', 2, '0x0215CD80'),
    387: ('fixed', 0, '0x021B23F0'),
    388: ('fixed', 2, '0x021B240C'),
    389: ('fixed', 2, '0x021B2444'),
    390: ('fixed', 2, '0x0215CDB8'),
    391: ('fixed', 2, '0x021B247C'),
    392: ('fixed', 2, '0x021B24F4'),
    393: ('fixed', 2, '0x021B24B8'),
    394: ('fixed', 0, '0x021B268C'),
    395: ('fixed', 0, '0x021B269C'),
    396: ('fixed', 2, '0x021B252C'),
    397: ('fixed', 2, '0x021B2568'),
    398: ('fixed', 2, '0x021B25A4'),
    399: ('fixed', 16, '0x0215CDF0'),
    400: ('fixed', 2, '0x021B25DC'),
    401: ('fixed', 2, '0x021B2614'),
    402: ('fixed', 2, '0x021B2650'),
    403: ('fixed', 2, '0x021B26AC'),
    404: ('fixed', 2, '0x021B26E4'),
    405: ('fixed', 2, '0x021B271C'),
    406: ('fixed', 0, '0x0215CE70'),
    407: ('fixed', 4, '0x021B273C'),
    408: ('fixed', 2, '0x021B277C'),
    409: ('fixed', 2, '0x021B27F8'),
    410: ('fixed', 4, '0x021B27B4'),
    411: ('fixed', 2, '0x021B4F1C'),
    412: ('fixed', 2, '0x021D1B2C'),
    413: ('fixed', 0, '0x021D1B8C'),
    414: ('fixed', 2, '0x021D29F0'),
    415: ('fixed', 2, '0x021C812C'),
    416: ('fixed', 2, '0x021C8170'),
    417: ('fixed', 2, '0x021C81B4'),
    418: ('fixed', 2, '0x021B5610'),
    419: ('fixed', 2, '0x021B5650'),
    420: ('fixed', 2, '0x021B568C'),
    421: ('fixed', 0, '0x021C881C'),
    422: ('fixed', 0, '0x021C8848'),
    423: ('fixed', 4, '0x021C8868'),
    424: ('fixed', 4, '0x021C88AC'),
    425: ('fixed', 8, '0x02166734'),
    426: ('fixed', 8, '0x021C88EC'),
    427: ('fixed', 2, '0x021667E0'),
    428: ('fixed', 0, '0x021C8960'),
    429: ('fixed', 0, '0x021B2910'),
    430: ('fixed', 0, '0x021B2940'),
    431: ('fixed', 0, '0x021B2970'),
    432: ('fixed', 0, '0x021B29A0'),
    433: ('fixed', 0, '0x021B2AA0'),
    434: ('fixed', 0, '0x021B28E0'),
    435: ('null', None, 'table entry is NULL'),
    436: ('fixed', 0, '0x021B2890'),
    437: ('fixed', 0, '0x021B29D0'),
    438: ('fixed', 0, '0x021B2A00'),
    439: ('fixed', 0, '0x021B2A30'),
    440: ('fixed', 0, '0x021B2A60'),
    441: ('fixed', 4, '0x021B5700'),
    442: ('fixed', 4, '0x021B574C'),
    443: ('fixed', 0, '0x021CC544'),
    444: ('fixed', 2, '0x021B5154'),
    445: ('fixed', 4, '0x0216BF38'),
    446: ('fixed', 4, '0x021B654C'),
    447: ('fixed', 6, '0x021B647C'),
    448: ('fixed', 0, '0x021CC570'),
    449: ('fixed', 2, '0x021CC5D8'),
    450: ('unresolved', None, '0x02186BE4: address not in ov010/ov021'),
    451: ('unresolved', None, '0x02186C44: address not in ov010/ov021'),
    452: ('unresolved', None, '0x02186D48: address not in ov010/ov021'),
    453: ('unresolved', None, '0x02186CC4: address not in ov010/ov021'),
    454: ('unresolved', None, '0x02186EB8: address not in ov010/ov021'),
    455: ('unresolved', None, '0x02186E94: address not in ov010/ov021'),
    456: ('unresolved', None, '0x02187098: address not in ov010/ov021'),
    457: ('unresolved', None, '0x02187000: address not in ov010/ov021'),
    458: ('fixed', 0, '0x02164778'),
    459: ('fixed', 4, '0x021B6AE0'),
    460: ('fixed', 0, '0x021B6AFC'),
    461: ('fixed', 2, '0x021B6B6C'),
    462: ('fixed', 4, '0x021B5EB8'),
    463: ('fixed', 6, '0x021B5DF8'),
    464: ('fixed', 0, '0x0215AFE0'),
    465: ('fixed', 2, '0x0215AFF4'),
    466: ('fixed', 0, '0x0215B014'),
    467: ('fixed', 6, '0x02164910'),
    468: ('fixed', 0, '0x02164994'),
    469: ('fixed', 0, '0x02164978'),
    470: ('fixed', 2, '0x021B6A78'),
    471: ('fixed', 2, '0x021B69D8'),
    472: ('fixed', 4, '0x021CFEA0'),
    473: ('fixed', 2, '0x021CFF28'),
    474: ('fixed', 4, '0x021CFF78'),
    475: ('fixed', 2, '0x021CFFDC'),
    476: ('fixed', 4, '0x021D0084'),
    477: ('fixed', 4, '0x02166980'),
    478: ('fixed', 4, '0x021669C0'),
    479: ('fixed', 6, '0x021D00B8'),
    480: ('fixed', 8, '0x02166A00'),
    481: ('fixed', 2, '0x021CFEF0'),
    482: ('fixed', 2, '0x021D0014'),
    483: ('fixed', 2, '0x021D004C'),
    484: ('fixed', 4, '0x021B60F4'),
    485: ('fixed', 6, '0x021B6164'),
    486: ('fixed', 6, '0x021B6124'),
    487: ('fixed', 6, '0x021B61E8'),
    488: ('fixed', 4, '0x0215BFD4'),
    489: ('fixed', 4, '0x0215C89C'),
    490: ('fixed', 8, '0x0215B214'),
    491: ('fixed', 8, '0x0215B26C'),
    492: ('fixed', 10, '0x0215B2C4'),
    493: ('fixed', 8, '0x02166D30'),
    494: ('fixed', 4, '0x021B6BDC'),
    495: ('fixed', 4, '0x0215E1C0'),
    496: ('fixed', 4, '0x021CC614'),
    497: ('fixed', 4, '0x021CC6A8'),
    498: ('fixed', 0, '0x021CC6FC'),
    499: ('fixed', 8, '0x0215F3A4'),
    500: ('fixed', 0, '0x0215F2F0'),
    501: ('fixed', 0, '0x0215F318'),
    502: ('fixed', 6, '0x0215F33C'),
    503: ('fixed', 12, '0x0215F424'),
    504: ('fixed', 0, '0x0215F4F4'),
    505: ('fixed', 0, '0x0216A3F8'),
    506: ('fixed', 0, '0x0216A420'),
    507: ('fixed', 2, '0x0216A440'),
    508: ('fixed', 6, '0x0216A470'),
    509: ('fixed', 4, '0x0216A4CC'),
    510: ('fixed', 4, '0x0216A510'),
    511: ('fixed', 0, '0x0216A560'),
    512: ('fixed', 2, '0x0216A594'),
    513: ('fixed', 2, '0x0216A5C4'),
    514: ('fixed', 2, '0x0216A5FC'),
    515: ('fixed', 2, '0x0216A634'),
    516: ('fixed', 4, '0x0216A674'),
    517: ('fixed', 2, '0x0216A6B4'),
    518: ('fixed', 2, '0x0216A6EC'),
    519: ('fixed', 4, '0x0216A72C'),
    520: ('fixed', 2, '0x0216A774'),
    521: ('fixed', 8, '0x021D1670'),
    522: ('fixed', 8, '0x021D16D8'),
    523: ('fixed', 4, '0x021D179C'),
    524: ('fixed', 8, '0x021D213C'),
    525: ('fixed', 8, '0x021D2468'),
    526: ('fixed', 4, '0x021B716C'),
    527: ('fixed', 6, '0x021B70D8'),
    528: ('fixed', 8, '0x0216B63C'),
    529: ('fixed', 0, '0x0216B6DC'),
    530: ('fixed', 2, '0x0216B578'),
    531: ('fixed', 6, '0x0216B5AC'),
    532: ('fixed', 4, '0x0216B720'),
    533: ('fixed', 4, '0x0216B81C'),
    534: ('fixed', 2, '0x0216B86C'),
    535: ('fixed', 2, '0x0216B60C'),
    536: ('fixed', 2, '0x021B4E58'),
    537: ('fixed', 2, '0x021B4E9C'),
    538: ('variable', None, '0x021AFC38: direct cursor byte read at 0x021AFC60, bypasses func_02011330/func_0201134C (ldr/ldrb off ScriptVm.pc +0x14)'),
    539: ('variable', None, '0x021AFC88: direct cursor byte read at 0x021AFCB0, bypasses func_02011330/func_0201134C (ldr/ldrb off ScriptVm.pc +0x14)'),
    540: ('fixed', 4, '0x0216B7B0'),
    541: ('fixed', 0, '0x0216B7F8'),
    542: ('fixed', 2, '0x0216B504'),
    543: ('fixed', 0, '0x0216B538'),
    544: ('fixed', 8, '0x0216BD54'),
    545: ('fixed', 12, '0x0216BBD4'),
    546: ('fixed', 8, '0x0216BC88'),
    547: ('fixed', 2, '0x0216BCE4'),
    548: ('fixed', 2, '0x0216BD1C'),
    549: ('fixed', 6, '0x0216A7A0'),
    550: ('fixed', 2, '0x0216A884'),
    551: ('fixed', 8, '0x021D2524'),
    552: ('fixed', 4, '0x0216BEC0'),
    553: ('fixed', 4, '0x021D2710'),
    554: ('fixed', 2, '0x0216AE10'),
    555: ('fixed', 4, '0x0216AD70'),
    556: ('fixed', 4, '0x0216ACCC'),
    557: ('fixed', 4, '0x0216AD1C'),
    558: ('fixed', 0, '0x0216AC40'),
    559: ('fixed', 4, '0x0216ABD8'),
    560: ('fixed', 2, '0x0216AC90'),
    561: ('fixed', 2, '0x021B51BC'),
    562: ('fixed', 4, '0x0215B464'),
    563: ('fixed', 4, '0x0215B488'),
    564: ('fixed', 4, '0x021B7364'),
    565: ('fixed', 2, '0x021B73B8'),
    566: ('fixed', 4, '0x021B62C8'),
    567: ('fixed', 6, '0x021B5CE8'),
    568: ('fixed', 2, '0x021B6590'),
    569: ('fixed', 2, '0x021CF7DC'),
    570: ('fixed', 4, '0x021D2ADC'),
    571: ('fixed', 4, '0x021D2B18'),
    572: ('fixed', 0, '0x0216CC30'),
    573: ('fixed', 4, '0x021D2B54'),
    574: ('fixed', 4, '0x021D2EDC'),
    575: ('fixed', 0, '0x021D2F44'),
    576: ('fixed', 2, '0x021C81F8'),
    577: ('fixed', 2, '0x021B1A20'),
    578: ('fixed', 4, '0x021B6628'),
    579: ('fixed', 4, '0x021B1334'),
    580: ('fixed', 2, '0x021B5008'),
    581: ('fixed', 4, '0x021B66B8'),
    582: ('fixed', 2, '0x021D0114'),
    583: ('fixed', 8, '0x021B229C'),
    584: ('fixed', 4, '0x021AEE28'),
    585: ('fixed', 8, '0x021B721C'),
    586: ('fixed', 4, '0x021B72CC'),
    587: ('fixed', 2, '0x021AF044'),
    588: ('fixed', 2, '0x021B2040'),
    589: ('fixed', 4, '0x021AF3D8'),
    590: ('fixed', 0, '0x0216F8B8'),
    591: ('fixed', 0, '0x0216F8C8'),
    592: ('fixed', 0, '0x0216F8DC'),
    593: ('fixed', 6, '0x0215D14C'),
    594: ('fixed', 0, '0x021B2FB0'),
    595: ('fixed', 4, '0x021AEF10'),
    596: ('fixed', 2, '0x021AEF60'),
    597: ('fixed', 12, '0x021D2F6C'),
    598: ('fixed', 6, '0x021D3018'),
    599: ('fixed', 0, '0x021D3068'),
    600: ('fixed', 0, '0x021D3090'),
    601: ('fixed', 2, '0x021AEE78'),
    602: ('fixed', 10, '0x021B0000'),
    603: ('fixed', 8, '0x021B1DEC'),
    604: ('fixed', 12, '0x0215F52C'),
    605: ('fixed', 2, '0x0215F2B8'),
    606: ('fixed', 0, '0x0215F2DC'),
    607: ('fixed', 0, '0x021AF1B0'),
    608: ('fixed', 0, '0x021B23E0'),
}

# ---------------------------------------------------------------------------
# Container framing: entry table (script sub-files) vs. raw bytes (side
# tables). Both are represented the same way for round-trip purposes: a
# dict with either "offsets" (tuple of u32s) + "term_pos" + "code", or
# just "raw" for a side table.
# ---------------------------------------------------------------------------

def find_entry_table(raw):
    """Scan u32-aligned words from the start of `raw` for the first one
    whose low 16 bits are the terminator (0xFD13). Returns
    (entry_count, terminator_byte_offset), or (None, None) if this
    sub-file is a side table (no terminator found)."""
    n = len(raw)
    p = 0
    while p + 2 <= n:
        if raw[p] == 0x13 and raw[p + 1] == 0xFD:
            return p // 4, p
        p += 4
    return None, None


def parse_subfile(raw):
    """Parse one a/0/5/7 sub-file. Returns a dict:
        kind       'script' or 'side_table'
        raw        the original bytes (side_table only)
        offsets    tuple of N table[] u32s (script only)
        term_pos   byte offset of the 0xFD13 terminator (script only)
        code       bytes from term_pos+2 to end of file (script only)
        entries    list of absolute entry-point byte offsets (script only)
    """
    count, term_pos = find_entry_table(raw)
    if count is None:
        return {"kind": "side_table", "raw": raw}
    offsets = struct.unpack_from("<%dI" % count, raw, 0) if count else ()
    entries = [4 * k + 4 + off for k, off in enumerate(offsets)]
    return {
        "kind": "script",
        "offsets": offsets,
        "term_pos": term_pos,
        "code": raw[term_pos + 2:],
        "entries": entries,
        "size": len(raw),
    }


def pack_subfile(parsed):
    """Inverse of parse_subfile: reconstruct the exact original bytes."""
    if parsed["kind"] == "side_table":
        return parsed["raw"]
    table = struct.pack("<%dI" % len(parsed["offsets"]), *parsed["offsets"])
    term = struct.pack("<H", TERMINATOR)
    return table + term + parsed["code"]


# ---------------------------------------------------------------------------
# Side tables: the 428 `a/0/5/7` sub-files with no 0xFD13 entry table
# ---------------------------------------------------------------------------
#
# Framing (arithmetic only, confirmed on all 428/428 side tables in the
# archive): 4-byte header (two u16 words) followed by (size - 4) / 4
# fixed 4-byte records (two u16 words each). `(len(raw) - 4) % 4 == 0`
# holds on every one of the 428 side tables, with no exception, including
# the one 6020-byte outlier -- this is what justifies calling it a real
# framing rather than a guess at one example's shape. The header's own
# two words are NOT a literal, independently-trustworthy record count
# (zone 1 and zone 8's 16-byte side tables carry the same header word
# pair {4, 10395} while zone 6 and zone 10's use {1, 2} at the same
# size), so the record count used here comes only from the sub-file's
# own length, the same self-describing-by-size convention as `a/0/6/6`'s
# group table and `a/0/0/3`'s record table (see events.py). No semantic
# decode of the header words or the per-record (u16, u16) pair is
# claimed -- only that the arithmetic holds archive-wide and the
# round trip is unaffected (side tables already pack back out as their
# own raw bytes, unchanged by this decoder).

SIDE_HEADER_SIZE = 4
SIDE_RECORD_SIZE = 4


class SideTableError(Exception):
    pass


def parse_side_table(raw):
    """Decode one `a/0/5/7` side-table sub-file's framing: a 4-byte
    header (two u16 words) followed by `(len(raw) - 4) // 4` records of
    two u16 words each. Raises SideTableError if the size does not fit
    the framing (never observed on the real archive: holds 428/428)."""
    if len(raw) < SIDE_HEADER_SIZE or (len(raw) - SIDE_HEADER_SIZE) % SIDE_RECORD_SIZE:
        raise SideTableError(
            f"side table size {len(raw)} does not fit header(4) + "
            f"N*record(4)")
    header = struct.unpack_from("<2H", raw, 0)
    count = (len(raw) - SIDE_HEADER_SIZE) // SIDE_RECORD_SIZE
    records = [struct.unpack_from("<2H", raw, SIDE_HEADER_SIZE + 4 * k)
               for k in range(count)]
    return {"header": header, "records": records}


# ---------------------------------------------------------------------------
# Opcode walk
# ---------------------------------------------------------------------------

def opcode_info(op):
    """(kind, width_or_None, source) for one opcode, or a synthesized
    out-of-range entry for op >= 609 (real desync, not a table gap)."""
    if op in OPERAND_WIDTH:
        return OPERAND_WIDTH[op]
    return ("out_of_range", None, "opcode %d >= 609 (table has 609 entries)" % op)


def walk_entry(raw, start, next_start, max_ops=4096):
    """
    Linear-sweep one entry from byte offset `start` in `raw`, using
    OPERAND_WIDTH to size each opcode's operand. `next_start` is the next
    entry's byte offset in the same sub-file, or None if `start` is the
    last entry (landing exactly on len(raw) counts as clean end-of-file).

    Returns (status, info):
        'ok'           info = None -- landed on a stop/flow-end opcode,
                       exactly on next_start, or exactly on end of file
        'out_of_range' info = (pos, opcode)
        'unresolved'   info = (pos, opcode, kind)   kind: 'variable' |
                       'unresolved' | 'null'-never (null has width 0)
        'eof'          info = pos                   ran past the buffer
        'bound'        info = pos                   op-count safety cap
    """
    pos = start
    n = len(raw)
    ops = 0
    while True:
        if pos == next_start or (next_start is None and pos == n):
            return "ok", None
        if pos + 2 > n:
            return "eof", pos
        op = struct.unpack_from("<H", raw, pos)[0]
        pos += 2
        ops += 1
        if ops > max_ops:
            return "bound", pos
        if op in STOP_OPS or op in FLOW_END_OPS:
            return "ok", None
        kind, width, _src = opcode_info(op)
        if kind == "out_of_range":
            return "out_of_range", (pos - 2, op)
        if kind == "null":
            continue
        if kind != "fixed":
            return "unresolved", (pos - 2, op, kind)
        if pos + width > n:
            return "eof", pos
        pos += width


def disasm_entry(raw, start, next_start, label, max_ops=4096):
    """Yield printable lines for one entry's linear sweep, plus any
    opcode-4 (call) targets found, for the caller to add to a worklist."""
    lines = []
    call_targets = []
    pos = start
    n = len(raw)
    ops = 0
    while True:
        if pos == next_start or (next_start is None and pos == n):
            lines.append("  %06x: -- end of entry (%s) --" %
                          (pos, "next entry" if pos == next_start else "eof"))
            break
        if pos + 2 > n:
            lines.append("  %06x: -- ran past end of file --" % pos)
            break
        op = struct.unpack_from("<H", raw, pos)[0]
        op_pos = pos
        pos += 2
        ops += 1
        if ops > max_ops:
            lines.append("  %06x: -- op-count bound exceeded --" % op_pos)
            break
        kind, width, src = opcode_info(op)
        if kind == "out_of_range":
            lines.append("  %06x: op %-4d OUT OF RANGE (desync)" % (op_pos, op))
            break
        if kind == "null":
            lines.append("  %06x: op %-4d (null handler)" % (op_pos, op))
            continue
        if kind != "fixed":
            lines.append("  %06x: op %-4d variable/unresolved (%s) -- stop" %
                          (op_pos, op, src))
            break
        operand = raw[pos:pos + width] if pos + width <= n else None
        pos += width
        words = []
        if operand is not None:
            for i in range(0, len(operand) - len(operand) % 2, 2):
                words.append("%04x" % struct.unpack_from("<H", operand, i)[0])
            if len(operand) % 2:
                words.append("%02x" % operand[-1])
        lines.append("  %06x: op %-4d operand=[%s] (%d bytes)" %
                      (op_pos, op, " ".join(words), width))
        if op == CALL_OP and operand is not None and len(operand) == 4:
            rel = struct.unpack_from("<i", operand, 0)[0]
            target = pos + rel
            call_targets.append(target)
            lines.append("      -> call target %s+0x%x" % (label, target))
        if kind == "out_of_range":
            break
        if op in STOP_OPS or op in FLOW_END_OPS:
            break
    return lines, call_targets


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def _load():
    return narc.parse_file(A0057_PATH)


def cmd_list(args):
    n = _load()
    scripts = 0
    side = 0
    for i in range(n.file_count):
        raw = n.read(i)
        parsed = parse_subfile(raw)
        if parsed["kind"] == "script":
            scripts += 1
            print(f"{i}\tscript\t{len(raw)} bytes\t{len(parsed['entries'])} entries")
        else:
            side += 1
            print(f"{i}\tside_table\t{len(raw)} bytes")
    print(f"=== a/0/5/7: {n.file_count} sub-files, {scripts} script "
          f"({scripts} with a 0xFD13 entry table), {side} side table ===")


def cmd_disasm(args):
    n = _load()
    raw = n.read(args.index)
    parsed = parse_subfile(raw)
    if parsed["kind"] != "script":
        print(f"sub-file {args.index} is a side table ({len(raw)} bytes), "
              f"not a script -- nothing to disassemble")
        return
    entries = parsed["entries"]
    label = f"a0057#{args.index}"
    print(f"=== {label}: {len(entries)} entries, {len(raw)} bytes ===")
    worklist = list(range(len(entries)))
    seen = set()
    while worklist:
        k = worklist.pop(0)
        if k in seen:
            continue
        seen.add(k)
        start = entries[k]
        next_start = entries[k + 1] if k + 1 < len(entries) else None
        print(f"-- entry {k} @ 0x{start:x} --")
        lines, call_targets = disasm_entry(raw, start, next_start, label)
        for line in lines:
            print(line)
        for tgt in call_targets:
            # a call target is reachable code, not necessarily one of the
            # table's own entries -- disassemble it in place as an extra
            # pseudo-entry if it doesn't already line up with one.
            if tgt not in entries:
                print(f"-- call target @ 0x{tgt:x} (not a table entry) --")
                extra_lines, extra_targets = disasm_entry(raw, tgt, None, label)
                for line in extra_lines:
                    print(line)


def cmd_side(args):
    n = _load()
    raw = n.read(args.side)
    parsed = parse_subfile(raw)
    if parsed["kind"] != "side_table":
        print(f"sub-file {args.side} is a script ({len(raw)} bytes), "
              f"not a side table -- nothing to decode")
        return
    side = parse_side_table(raw)
    print(f"a0057#{args.side}: side table, {len(raw)} bytes, "
          f"header={side['header']}, {len(side['records'])} records")
    for k, rec in enumerate(side["records"]):
        print(f"  [{k}] {rec}")


def cmd_verify(args):
    n = _load()
    ok = 0
    fail = 0
    for i in range(n.file_count):
        raw = n.read(i)
        parsed = parse_subfile(raw)
        repacked = pack_subfile(parsed)
        if repacked == raw:
            ok += 1
        else:
            fail += 1
            print(f"a/0/5/7#{i}: round-trip MISMATCH "
                  f"(orig {len(raw)}, repacked {len(repacked)})")
    print(f"a/0/5/7: {ok}/{n.file_count} round-trip OK ({fail} failed)")


def cmd_check(args):
    n = _load()
    total_entries = 0
    ok = 0
    out_of_range = 0
    unresolved = 0
    eof = 0
    bound = 0
    script_files = 0
    unresolved_ops = {}
    for i in range(n.file_count):
        raw = n.read(i)
        parsed = parse_subfile(raw)
        if parsed["kind"] != "script":
            continue
        script_files += 1
        entries = parsed["entries"]
        for k, start in enumerate(entries):
            next_start = entries[k + 1] if k + 1 < len(entries) else None
            total_entries += 1
            status, info = walk_entry(raw, start, next_start)
            if status == "ok":
                ok += 1
            elif status == "out_of_range":
                out_of_range += 1
            elif status == "unresolved":
                unresolved += 1
                op = info[1]
                unresolved_ops[op] = unresolved_ops.get(op, 0) + 1
            elif status == "eof":
                eof += 1
            elif status == "bound":
                bound += 1
    print(f"a/0/5/7: {script_files} sub-files with a 0xFD13 entry table")
    print(f"entry points decoded: {total_entries}")
    print(f"landed on end/flow opcode, next entry, or file end: "
          f"{ok} ({100.0 * ok / total_entries:.1f}%)")
    print(f"desynced (opcode >= 609): {out_of_range}")
    print(f"hit a variable/unresolved opcode: {unresolved}")
    if unresolved_ops:
        top = sorted(unresolved_ops.items(), key=lambda kv: -kv[1])[:10]
        print("  top opcodes: " +
              ", ".join(f"{op} x{cnt}" for op, cnt in top))
    print(f"ran past end of file mid-opcode/operand: {eof}")
    if bound:
        print(f"op-count bound exceeded (likely a real loop): {bound}")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--list", action="store_true")
    g.add_argument("--disasm", type=int, metavar="N")
    g.add_argument("--side", type=int, metavar="N")
    g.add_argument("--verify", action="store_true")
    g.add_argument("--check", action="store_true")
    args = ap.parse_args(argv)

    if args.list:
        cmd_list(args)
    elif args.disasm is not None:
        args.index = args.disasm
        cmd_disasm(args)
    elif args.side is not None:
        cmd_side(args)
    elif args.verify:
        cmd_verify(args)
    elif args.check:
        cmd_check(args)


if __name__ == "__main__":
    main()
