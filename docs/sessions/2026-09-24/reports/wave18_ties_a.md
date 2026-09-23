# Wave 18, lane 18E (ties_a)

Four closed EXACT, one near miss moved 37 -> 1, thirteen unchanged. Every measurement is recorded in the function's note under a 2026-09-24 section.

| address | before -> after | verdict | what moved it |
|---|---|---|---|
| 0x02051C88 | 19 -> 0 | EXACT, 1.1p1 | `unsigned long i` (loop index) |
| 0x0206ECE0 | 14 -> 0 | EXACT, ../2.0/sp2p2 (sp2 too) | `long k` (pivot index) |
| 0x0203F0A8 | 16 -> 0 | EXACT, dsi/1.2 (1.2p1, 1.2p2, 1.3 too) | front end only; C unchanged |
| 0x0201FDA0 | 2 -> 0 | EXACT, 1.1p1 | u16 heap parameter plus u16 heap on every callee (the ties_b idiom) |
| 0x0204A7A0 | 37 -> 1 | DIFF | `return i;` for the early return, `slot` declared before `i`; the 1 byte left is `moveq r0, sb` (the image returns the -1 constant) |
| 0x02067080 | 2 | DIFF | |
| 0x0206F4C8 | 7 | DIFF | |
| 0x02048744 | 14 | DIFF | |
| 0x0202E1F0 | 21 | DIFF | |
| 0x0200CA98 | 147 | DIFF | |
| 0x0201C8BC | 17 | DIFF | |
| 0x0202627C | 10 | DIFF | |
| 0x0202173C / 0x02021848 | 33 / 33 | DIFF | re-measured on the corrected 268/232 extents: the old figures stand |
| 0x020681E4 | 10 | DIFF | |
| 0x0202CC70 | 176 (236/244) | DIFF | |
| 0x02011D9C | 8 | DIFF, overlay-capped | |
| 0x0204A6C8 | 4 | DIFF | |

## Files written
- New sources in src/matched: func_02051C88.c, func_0206ECE0.c, func_0203F0A8.c, func_0201FDA0.c.
- New idiom file: docs/idioms/a-long-index-colours-apart-from-an-int.md.
- 17 notes got a dated section. The new best source for 0x0204A7A0 is in docs/notes/func_0204A7A0.c.txt.

## Shards
I ran `manifest --verify` twice on each of pkt_02051C88, pkt_0206EB00, pkt_0203F0A8 and pkt_0201FC5C, and the second pass rewrote nothing. pkt_0203F0A8.json and pkt_02051C88.json are new files under layout/matched/arm9/.

## For the integrator
- 0x0203F0A8 is the only dsi/1.2 function in a 1.1p1 neighbourhood: 0x0203F034, 0x0203F1FC and 0x0203F258 are 1.1p1. Its evidence is a scaled-register load of mt[kk] that 1.1p1 never produces. That residue did not move under a 3314-compile permuter run or about forty hand spellings. It needs a FRONTEND-PINS row, which I did not write.
- 0x02048744 already uses the long lever and was still 14 after this wave's levers.
- No seeds found.
