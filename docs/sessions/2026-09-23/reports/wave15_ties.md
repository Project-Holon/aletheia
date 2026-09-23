# Wave 15, register-tie lane (clact.c and pkt_0206EB00 ties)

EXACT 4 (3 territory rows plus 1 witness leaf) / MATCH 0 / DIFF 7.

Per function, concrete bytes out before -> after, and the lever:
- 0x0204D18C (152): 10 -> 0 EXACT. `const struct A *a` on the read-only source. src/matched/func_0204D18C.c.
- 0x0204D224 (164): the old "2-byte" source stored f14/f0c into the wrong fields (honest residue 9) -> 0, EXACT*. `const struct A *a1`, direct field stores, fresh a1->f14 for the size call, the volatile device dropped. src/matched/func_0204D224.c.
- 0x0204D2C8 (leaf, 20): new, EXACT. fill(anim, 0, 0x7c) tail call; the follower that makes D224 read EXACT*.
- 0x0204BE84 (164): 104 (160/164) -> 0 EXACT. Callee arity (func_0204BF28 takes (a0, a1->f8)) gives 35, const T *a1 gives 8, s16 locals for f2/f6 (permuter anneal) give 0.
- 0x0204B49C (80): 20 (76/80) -> 20. Nothing moved it; permuter again only the invalid ret-var point.
- 0x0204A6C8 (216): 4 -> 4. 126 variants (casts, 120 declaration orders, const, prototypes, flags reuse), anneal flat.
- 0x0204C2C8 (260): 58 -> 58. 80 index casts, 120 declaration orders, const, shift placement, table forms; anneal 57 (noise).
- 0x0204A7A0 (308): 103 -> 37. New reading: the [sp,#0x18] "spill" is template word 5 (t.w5 = alloc; free(t.w5)), giving 47; i declared before slot (declaration-order lever) gives 37. Best source appended to the note.
- 0x0206ECE0 (384): 14 -> 14. Casts, enum k, const node/p/out, u16 f; anneal flat.
- 0x0206F4C8 (488): 7 valid (2 with the invalid volatile) -> unchanged. 16 index casts, value casts, const; anneal flat.
- 0x0206FC5C (836): 8 -> 8. const r/h/p, u16 id, enum k; anneal flat.

Levers that moved something: const on a read-only source pointer (3 closures), real callee arity (1), a reading fix (A7A0), declaration order (A7A0). The wave-14 cast, enum, initialised-array, u16 and `f = (u16)(f | X)` levers moved nothing here.
New idiom: docs/idioms/const-on-a-read-only-source-parameter-settles-a-register-tie.md. clact.h: wave-15 block (func_0204BF28 arity, the const lever, the 0x0204D2C8 leaf).
Notes appended (each with a best-source marker): sub_0204B49C, pkt_0204D18C.func_0204D224 (correction), pkt_0204BE84, sub_0204A6C8, pkt_0204C060, func_0204A7A0 (new source), pkt_0206EB00, pkt_0206F4C8.
Permuter seeds (anneal 2000, --types): 1501 B49C, 1502 BE84, 1503 A6C8, 1504 C2C8, 1505 A7A0, 1506 ECE0, 1507 F4C8, 1508 FC5C. D18C and D224 closed on levers before their anneal.
Shards verified twice, stable (0 rewritten on the second pass): pkt_0204D18C (3 entries: EXACT, EXACT*, EXACT), pkt_0204BE84 (6 entries, all EXACT or EXACT*).

Integrator: seed
- 0x0204D2C8 arm, witness src/matched/func_0204D2C8.c (turns func_0204D224's EXACT* into EXACT).

Verdict: worth one more lane, but only for "declaration facts" (const on read-only pointer parameters, callee arity checked against the callee's body), swept over every documented tie that has a pointer parameter. Ties with no such parameter (A6C8, B49C, ECE0, FC5C) did not move under any lever and are not worth another pass.
