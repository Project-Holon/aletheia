# tree_ov111 (ov111, then ov118), relaunch

## Salvaged from the cut run (re-verified; shards verified twice, 0 rewritten)

- EXACT/EXACT*, src/matched: 67 ov111 files, 0x021C3CC0..0x021C6FA0, with shards pkt_ov111_* for the same addresses. All headers agreed with the verdicts.
- MATCH, src/pending: ov111 40DC, 61EC (0x02012F5C, plus 0x02025C9C for 61EC), 4B9C, 60CC (0x0202DCB0). Blockers unchanged.

## Tree

Root 0x021C3F54 (the ov111 main proc step, 392 B) is EXACT. `lane.py` now lists 0 open ov111 functions.

## New EXACT (53)

- ov111 (49): 3F54 6000 6A84 6FC4 705C 7098 70EC 71CC 7208 7228 72C8 74D0 7504 75E4 7658 76A4 7730 7744 7808 78C4 78F8 7908 7934 795C 7970 79A0 79B8 79D0 79F4 7A44 7A70 7AD4 7C78 7C94 7CD0 7E48 7EF8 7F2C 8078 80B4 80E8 810C 81A4 81C0 8208 829C 82C0 832C 8364. 0x021C7EF8 is unlabelled (it sits inside 7E48's listing extent); its witness is 0x021C7F2C.
- ov118 (4): 4B14, 5A60, 6F90 (twins of ov117 4BF4, macro style, `ov119` hints on 2FB0/35A0/8AA8/DFA60), and 6F2C.

## MATCH (src/pending)

- 7130, 5718: 0x02012F5C.
- 7830: 0x02047828, an unlabelled arm9 ARM function.
- 7B20: sub_02008A54, the arm9 near miss in unit_020089A8.c.

## DIFF near misses (notes in docs/notes/pkt_ov111_*.c.txt)

- 72FC: 3 instructions, one scheduled stack store.
- 4E0C: 17, register choice in case 0 only.
- 5CF4: 25, guard trampolines.

Permuter seeds 8501 (72FC) and 8502 (5CF4) gave no gain.

## Levers and idioms

Levers that closed functions: SDK inline register-update shape, flat `row*3+i` subscript, declaration order (7744, 7E48), a table-base local (6000), a lim local (832C), negated guard placement (7A70), and s64 `hours*2` inside the loop (8208). Two new idiom files: a-u16-cast-over-the-whole-register-update-keeps-the-full-complement-mask.md and a-flat-row-times-three-index-is-shift-and-add-a-two-dimensional-subscript-is-muls.md.

## Seeds

0x021C7EF8 (ov111, done); arm9 0x02012F5C, 0x0202DCB0, 0x02025C9C, 0x02047828.

## Integrator

Stage the `ov111`/`ov118` files under src/matched, src/pending, and layout/matched/ov111 and ov118. Also stage the two idioms and the three notes. `manifest --check` is clean. Regenerate the idiom index.
