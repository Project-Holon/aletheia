# Wave 15, palanm/areaman bundle lane (procsys, msgdata, tr_tool, textprint, areaman, palanm)

EXACT 8 (3432 bytes), MATCH 0, DIFF unchanged 4.

- procsys.c: 0x020315F0 (216 B, first write) EXACT. 0x020314F4 72/68, 45 out -> EXACT: `if (buf == 0) { call } else { stores }` predicates the else arm and emits it first. 0x020313EC 12 out -> EXACT: the parent load written as the first statement of both arms is hoisted below the compare.
- msgdata.c: 0x02046110 108/112, 77 out -> EXACT: the archive member declared volatile keeps the `ldreq` reload. 0x02045F5C 11 out -> EXACT: same polarity lever as 0x020314F4 (`mode == 0` with the file arm first).
- tr_tool.c: 0x0202A9F4 248/256 -> EXACT: the "counter copy" in r6 is the constant 0 (NULL argument and `found = 0`), tail is `% 25`. 0x0202A4B4 (1248 B, first write) EXACT: 64-bit LCG, draw as `((u64)(u32)(seed >> 32) * 0x10000) >> 32`, one `pid` variable for sum, draw and personality, no typed local pointer, case 3 passes species as a fresh read, and pid/seed/j/iv at function scope with dv/level/species per case (the last lever closed a 4-byte spill-slot swap).
- textprint.c: 0x0204E180 (424 B, first write) EXACT: case 2 is `x = x + width` (not `+=`), `eom != *str`, locals declared eom, glyph, width, height.
- areaman.c: 0x0203422C DIFF 17 and 0x020343C0 DIFF 44, unchanged. 20 levers tried, all flat or worse. Stopped as instructed.
- palanm.c: 0x02021848 and 0x0202173C DIFF 33, unchanged. Narrowing `a` (the other lane's narrow-parameter idiom) moves the home store two slots but gives 34. Recorded.

Per family: procsys 3/0/0, msgdata 2/0/0, tr_tool 2/0/0, textprint 1/0/0, areaman 0/0/2, palanm 0/0/2 (EXACT/MATCH/DIFF).

New files: docs/families/procsys.h, msgdata.h, tr_tool.h, textprint.h; idioms an-else-arm-is-predicated-and-placed-before-the-then-arm.md, function-scope-versus-block-scope-decides-spill-slot-order.md. Notes appended: pkt_020313EC, pkt_020314F4, func_02046110, pkt_02046110, pkt_02045F5C, func_0202A9F4 (closures), pkt_0203422C, func_0202173C (DIFF).

Integrator: seed: none. Every filed address already has a label. The palanm home-area starts are already in function_starts.txt, but show still gives them a 2-byte extent until the listings are regenerated.
Integrator: pending: src/pending/func_02013284.c calls sub_0202A4B4, which is now EXACT, so it may promote.
Integrator: `match.py idioms --check` flags docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md (another lane's file) for having no `summary:` line.

Shards verified twice: pkt_020315F0, pkt_020314F4, pkt_020313EC, pkt_02046110, pkt_02045F5C, pkt_0202A9F4, pkt_0202A4B4, pkt_0204E180, pkt_0204E130. All entries are EXACT.
