# Wave 14, infowin.c lane

EXACT 4 / MATCH 0 / DIFF 0. The family is closed: all 8 members of infowin.c (0x02024A20..0x020252D8) are EXACT.

- 0x02024A20 (140 B, constructor), src/matched/func_02024A20.c, pkt_02024A20. The lever was the heap id as `u16`, found by permuter --types in hill; the 17-byte spill/reload residue closed with it.
- 0x02025154 (126 B, tile-rect writer), src/matched/func_02025154.c, pkt_02024DFC. x/y/w/h are u8, matching func_020410D0's real u8 prototype. `j * 16`, not `j << 4`, fixes the last `adds` operand order.
- 0x02024ABC (764 B + 20 B mid-function pool, per-frame poll), src/matched/func_02024ABC.c, pkt_02024ABC. Flag updates are spelled out as `f = (u16)(f | X)`, which reuses the tested load. Clear masks are u16 constants (the pool holds 0x0000EFFF).
- 0x02024DFC (818 B, redraw task), src/matched/func_02024DFC.c, pkt_02024DFC. Levers: `/ 10` for the tens digit and `% 10` for the ones digit; direct global access everywhere; the two six-entry tables as struct copies; ternaries for the three tile selectors; the draw call written in each arm of the 0x10 block; `done = 1` after the block-0 draw.

Correction to older notes: the singleton is 0x0214693C, the only global. The 2026-09-21 notes named 0x0202693C and 0x02020214, which was a misreading. The callback word is 0x02024DFD (func_02024DFC), not func_02024ABC. The seven 0x0209F8xx tables now resolve as sole-ref/self.

Written: docs/families/infowin.h (new). A "closed" line was appended to docs/notes/func_02024A20.c.txt, func_02024DFC.c.txt and pkt_02024DFC.c.txt.

Seeds: none. All four starts were already labelled.

Near misses: none left.

Compilers: every closure is 1.1p1. On the residues, sp2 and sp2p2 were the same or worse.

Shards verified twice: pkt_02024A20, pkt_02024ABC, pkt_02024DFC. pkt_02024ABC also carries the existing 0x02025508 EXACT* entry, which this lane did not touch.
