# Wave 16, declaration-facts lane (clact.c and pkt_0206EB00 ties, plus six singles)

EXACT 4 / MATCH 0 / DIFF 10.

Per function, concrete bytes out before -> after, and the fact that moved it:
- 0x0204C2C8 (260): 58 -> 0 EXACT. The two OBJ size tables declared `extern const u16 [4][4]` (read-only data, not a parameter). src/matched/func_0204C2C8.c.
- 0x0206A12C (80): 9 -> 0 EXACT. Callee bodies: GX_BeginLoadTexPltt / GX_EndLoadTexPltt take no argument, GX_LoadTexPltt(const void *, u32, u32); NNSG3dResPlttInfo at +0x2c (NNS_G3dPlttLoad shape). src/matched/func_0206A12C.c.
- 0x02075968 (44): 2 -> 0 EXACT. Not a declaration: ../2.0/sp2 pin (fresh register on the first bic); filed with the signed 1-bit bitfields at +0x118. src/matched/func_02075968.c.
- 0x02069C00 (20): new, EXACT. Typed u16 post-increment of the cursor. src/matched/func_02069C00.c.
- 0x02069BA0 (96): 14 -> 8 only with a `volatile Bits *b` device (anneal find); not filed, best source in the note.
- 0x0204A7A0 (308): 37 -> 37. sub_0204DACC arity/types fixed; template typed as NNSG2dCharacterData with the GX inline.
- 0x0204A6C8 (216): 4 -> 4. Real prototypes of func_0204D9D4 / func_0204E0D0.
- 0x0204B49C (80): 20 -> 20 (76 bytes). Callee arities already right.
- 0x0206F4C8 7 -> 7, 0x0206ECE0 14 -> 14, 0x0206FC5C 8 -> 8 (const s16 * in func_0206FFA0's prototype, const Root/Bank: flat).
- 0x02067080 (704): 2 -> 2. const pBaseTrans, const RndCore: flat.
- 0x02051C88 (352): 19 -> 19. const struct Ctx * is wrong (356: the image reloads n/slots after the slot stores).
- 0x02071104 (124): 6 -> 6.

Levers that moved something: const on read-only extern data (1), real callee arity from the SDK bodies (1), a front-end pin (1). const on pointer parameters moved nothing this wave.
New idiom: docs/idioms/const-on-a-read-only-extern-table-settles-a-register-tie.md. clact.h: tables declared const, wave-16 block.
Notes appended (each with a best-source marker where DIFF): func_0204A7A0, sub_0204A6C8, sub_0204B49C, pkt_0204C060, pkt_0206A12C, pkt_02075794, pkt_0206EB00, pkt_0206F4C8, pkt_02066E30, pkt_02051C88, pkt_02071104, func_02069BA0.
Permuter seeds (anneal 2000, --types): 1601 A6C8, 1602 A7A0, 1603 B49C, 1604 F4C8, 1605 ECE0, 1606 FC5C, 1607 7080, 1608 1C88, 1609 and 1611 9BA0, 1610 1104, 1613 5968 (1.1p1, before the pin). C2C8, A12C, 9C00 closed before an anneal.
Shards verified twice, 0 rewritten on the second pass: pkt_0204C2C8 (2, EXACT), pkt_02069BA0 (1, new), pkt_0206A12C (6), pkt_02075968 (1, new).

Integrator:
- run `python tools/match.py idioms` (index stale after the new idiom).
- FRONTEND-PINS row for src/matched/func_02075968.c (../2.0/sp2), not added by this lane.
- src/pending/func_02075A2C.c was waiting on PC24 0x02075968; re-verify it (its other wall, g_02150190, may remain).
