# Wave 14: pms_draw.c, bmp_win.c, bmp_oam.c

EXACT 1 / MATCH 0 / DIFF 3.

- EXACT* 0x0202DD24 (pms_draw, Thumb, 310 B): src/matched/func_0202DD24.c. Wave-12 residue was 8 bytes (dst/dy spill slots). Closed by reading the handles through src->handle / dst->handle (no `e` local), dx declared before dy, and the loop counter `k` declared first. The * is the listing extent running over the setters of unit_0202DE5C.
- DIFF 0x0202E1F0 (pms_draw, Thumb, 400/412, 371 out). New facts: `u32 marks[2] = {0, 0}` gives the image's base-register stores, and c3 is read twice (reproduced with `volatile u16 c3`). What is left is one callee-saved value: the image keeps &ws in r7 as a real value across both loops, hoists the constant 1 into r5 and spills n. The compile rematerialises &ws and keeps n in r7. Ruled out: 14 spellings, compilers sp2/sp2p2/1.2p2/1.3p1, and permuter anneal 2000 and hill 800 --types. Recorded in docs/notes/pkt_0202E1F0.c.txt.
- DIFF 0x020255A0 (bmp_oam, Thumb, 364/364, 8 out). Still two one-instruction scheduling swaps: +010A `adds r3,r5,r3` / `ldr r2,[r4,#8]`, and +012C `str r0,[r6,#4]` / `movs r2,#0`. Same result under sp2, sp2p2 and 1.2. A slot local at 6 positions was worse every time. Recorded in the note.
- DIFF 0x020454E0 (bmp_win, ARM, 536/536, 2 out). Still +0014 `mov r6,r2` against `mov r4,r2` (the pal copy). Permuter anneal 2000 --types was flat at 2. Recorded in the note.

Near misses, diverging instruction:
- 0x020454E0: +0014 `mov r6, r2` (compile `mov r4, r2`); its use at +0028 follows.
- 0x020255A0: +010A `adds r3, r5, r3` is scheduled after `ldr r2, [r4, #8]` instead of before it, and +012C `str r0, [r6, #4]` is scheduled after `movs r2, #0` instead of before it.

Seeds: none new. 0x0202DE5C, 0x0202DE64 and 0x0202DE68 (Thumb, witness src/matched/unit_0202DE5C.c) are still unlabelled, which is why 0x0202DD24 reads EXACT*. Seeding 0x0202DE5C would make it plain EXACT.

Shards verified: pkt_0202DD24, run twice (func_0202DD24 EXACT*, unit_0202DE5C EXACT; 0 rewritten on the second pass).

Other files: docs/families/pms_draw.h (func_0202DD24 entry updated); wave-14 sections appended to docs/notes/pkt_0202DD24.c.txt, pkt_0202E1F0.c.txt, pkt_020255A0.c.txt and pkt_020454E0.c.txt.
Idiom candidate (not written): the declaration position of a loop counter decides which of two callee-saved registers a long-lived pointer gets.
