# tree_ov021 (relaunch)

## Salvage

Nothing from the cut run was left uncommitted. The earlier ov021 files, including the pending ov021_func_021CB8AC.c (MATCH*, blocked on the unlabelled ov010 leaf 0x02167B18), had already been committed. I re-verified CB8AC and it is unchanged.

## Trees

- 0x021CA5C4 (1454 B) is not a unit. It is a single switch function of about 4.4 KB, from 0x021CA5C4 to about 0x021CB6D0, and its long `bl` branches jump into the stale labels 0x021CAB72 (not 4-aligned) and 0x021CB4BC. It needs an integrator relabel, so I skipped it.
- 0x02195938 (1308 B, window frame drawing, leaf): EXACT. It closed with u16 geometry locals and `(pal & 0xF) << 12` in an int.
- 0x02189BD0 (1188 B, field input dispatcher): 34 functions.
  - 29 EXACT/EXACT\*: 0218A4E0 A738 A76C A784 A7F0 A824 A878 A8BC A9B0 AA2C AA74 AAD0 AB0C AB50 AB9C AC08 AC4C AC84 AD28 ADC8 AE04 AEAC B56C B630, plus 021AB0D4 021C8A30 021C8C88 021D220C, plus 02195938 above.
  - 4 MATCH in src/pending/ov, each blocked by an unlabelled callee: 0218AD80 (ov010 veneer 0x021626A8), 0218ACD0 (ov010 0x021626EC), 0218B208 (arm9 veneer 0x02013DD0), 0218B4B0 (ov010 0x02164294 and 0x02164240).
  - The root is a near miss: 4 bytes out, from one scheduling swap. The permuter (seed 10101) did not close it. Notes are in docs/notes/pkt_ov021_02189BD0.c.txt. Even if it closes, it caps at MATCH because of ov010 0x02158D90 and 0x02162A54.

## Files

- src/matched/ov/ov021_func_*.c: 29 files.
- src/pending/ov/ov021_func_{0218AD80,0218ACD0,0218B208,0218B4B0}.c
- docs/notes/pkt_ov021_02189BD0.c.txt
- Shards: layout/matched/ov021/pkt_ov021_<addr>.json, one per EXACT. Each was verified twice and the second pass rewrote nothing. `manifest --check` is clean.

## Seeds for the integrator

Unlabelled starts, each with a witness:

| Start | Region | Witness |
| --- | --- | --- |
| 0x021626A8 (veneer) | ov010 | 0x0218AD9A |
| 0x021626EC | ov010 | 0x0218ACF6 |
| 0x02164294 | ov010 | 0x0218B4E2 |
| 0x02164240 | ov010 | 0x0218B50A |
| 0x02158D90 | ov010 | 0x02189E18 |
| 0x02162A54 | ov010 | 0x02189E58 |
| 0x02013DD0 (veneer) | arm9 | 0x0218B224 |

## Remainder for the next lane

- Open subtrees below filed callers: 021AA944, 021AA80C, 021AA248, 021A9F40, 021A2FE4, 021A30C8, 021A3128, 021A3504, 021A3524, 021C868C, 021AE0CC, 021CFAC0, 021CFC14, 021CD440, 021A2F20, 021A2F6C, 0218DAEC, 0218B408, 0218AED4, 0218AF90, 0218ACA8, 021C3378 (children 021C385C, 021C33A4).
- 0x021B88DC: I did not have the budget for a fresh draft.
- ov021 bands >= 512 still open: 021CD6D0, 0218E7DC, 021C1E7C, 021955EC, 0218F460, 021C82C4, and others.
