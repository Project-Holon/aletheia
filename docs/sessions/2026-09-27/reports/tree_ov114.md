# tree_ov114 report (2026-09-27)

## Root 1: func_021CDB9C (listed 7620 bytes)

Real function, but only 64 bytes: it is the last labelled function in ov114, and the rest of the listed extent is the string/data tail starting at 0x021CDBDC. It is the SDK symbol CRYPTOi__bn_sub_words (libcrypto crypto_bobj2.o), a leaf with no callees, so the tree is 1 function. crypto_bobj2.o is hand-written ARM (adcs/umlal carry chains), so every function in it was filed as an `asm` body.

| file | address | verdict |
|---|---|---|
| src/matched/ov114_func_021CDB9C.c | CRYPTOi__bn_sub_words | EXACT |
| src/matched/ov114_func_021CD984.c | CRYPTOi__bn_mul_add_words | EXACT |
| src/matched/ov114_func_021CDA38.c | CRYPTOi__bn_mul_words | EXACT |
| src/matched/ov114_func_021CDAC0.c | CRYPTOi__bn_sqr_words | EXACT |
| src/matched/ov114_func_021CDAE8.c | CRYPTOi__bn_div_words | EXACT (asm, `bl _ll_udiv` resolves as runtime; the nearest C is 9 bytes out) |
| src/matched/ov114_func_021CDB08.c | CRYPTOi__bn_add_words | EXACT |

Shards pkt_ov114_021CD984, _021CDA38, _021CDAC0, _021CDAE8, _021CDB08, _021CDB9C: each verified twice, and the second pass rewrote nothing. `manifest --check` is clean.

## Root 2: func_021C7C1C (2608-byte body)

Its callee tree was already closed by an earlier lane (func_021C8EB4 EXACT, the rest SDK). I wrote a fresh draft from the image. It is DIFF at the exact size (2620/2620), with 73/73 relocations resolved. The only residue is a rotation of the five values hoisted into the prologue: the image puts 24 in r4, my build puts it in r8. About 15 levers, 4 front ends and one permuter run (seed 6301) did not move it. The best source and every measurement are in docs/notes/pkt_ov114_021C7C1C.c.txt. No source file is filed.

## Next lane list (ov114 open, large first)

- func_021CD210: CRYPTOi__BN_mod_exp_mont, 1908 bytes, SDK C
- func_021CBB80: BN_div, 1404 bytes
- func_021CCE7C: BN_mod_exp_recp, 916 bytes
- func_021CCB88: BN_div_recp, 628 bytes
- The crypto_bobj1.o run 0x021CAB34..0x021CC80C: many small BN functions
- The large DWC/NHTTP functions: 0x021C3218, 0x021C4E7C, 0x021C6C0C, 0x021C8FA8, 0x021BB3CC, 0x021BDFF8

## For the integrator

Nothing required: there are no unlabelled followers and no new idiom.
