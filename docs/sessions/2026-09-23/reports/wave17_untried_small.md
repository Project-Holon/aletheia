# Wave 17 lane 17H (untried_small) report

Per address (bytes out before -> after, verdict, lever):
- 0x0201A4D4: 6 halfwords -> EXACT. Heap id parameter a2 declared u16 (homed and reloaded).
- 0x02036568: 25 -> EXACT. `const NetRingBuff *` in the function and in func_02036624's prototype.
- 0x0200E0E8: 37 -> EXACT. Rec {u16 a, b} table, u32:11 bitfield (lsls/lsrs pair), element pointer in a while loop.
- 0x02072F5C: 11 -> EXACT. Callee arity: third parameter forwarded to func_02075BAC, so the null test lands in r3.
- 0x02072EA8: 15 -> EXACT, ../2.0/sp2 (kept `bxeq` branch is the tell; every dsi front end predicates).
- 0x02075BAC: 9 -> EXACT, ../2.0/sp2 (cluster pin); func_02075BD4 declared with one parameter, from its body.
- 0x02084D98: 2 -> EXACT. `asm void` `ldr r1, =func_02084D78; bx r1` (even, in-range target: SDK asm, not a veneer). Removed src/pending/func_02084D98.c.
- 0x0200AD78, 0x020141DC: EXACT* (4-byte bodies; the extent runs over unlabelled neighbours).
- 0x0200E0BC 9, 0x020111BC 3, 0x0209128C 1, 0x02034D60 5 (permuter 800, flat), 0x0204EEC8 58: unchanged DIFF, measurements in the notes.
- 0x02094534: not a function. The real start 0x02094530 is already EXACT (src/matched/func_02094530.c).
- 0x020911F0, 0x02091220, 0x0209124C: not functions. Each is the `bx pc; nop` Thumb head of a 16-byte Thumb-to-ARM veneer (`ldr ip, [pc]; bx ip; .word 0x0273xxxx`, which points outside every region).

Files written: src/matched/func_0201A4D4.c, func_02036568.c, func_0200E0E8.c, func_02072F5C.c, func_02072EA8.c, func_02075BAC.c, func_02084D98.c, func_0200AD78.c, func_020141DC.c; docs/idioms/a-ldr-r1-bx-r1-stub-with-an-even-target-is-hand-written-sdk-asm.md; notes appended (pkt_02084D98, func_0209128C, pkt_0200E0BC, pkt_02072F5C, pkt_02075BAC, pkt_02072EA8, func_02073438, func_020111BC, sub_02034D60, pkt_0204EEC8, pkt_0201A3F4.func_0201A4D4, pkt_02036568).

Shards verified (second pass rewrote nothing): pkt_02084D98, pkt_0200AD78, pkt_020141DC, pkt_0200E0BC, pkt_02072F5C, pkt_02072EA8, pkt_02075BAC, pkt_0201A4D4, pkt_02036568.

Seeds: 0x0200AD7C (tail call to MIi_CpuClearFast, pool 0x02082AC0), 0x0200AD8C and 0x0200AD94 (ldrh/strh at +0xEC getter/setter); 0x020141E0 and 0x020141F0 (3-word getter and setter).

Integrator: layout fixes. Drop the label at 0x02094534 and seed 0x02094530. Reclassify 0x020911F0, 0x02091220 and 0x0209124C as 16-byte veneers, not 2-byte functions.
