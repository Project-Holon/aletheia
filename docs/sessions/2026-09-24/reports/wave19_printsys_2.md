# Wave 19 lane printsys_2 (19I)

Per address, bytes out before -> after, verdict, what moved it:

- 0x0201C8BC (184 bytes): 17 -> 0, EXACT. Two changes, both required: `done` is a plain `u8` (u16 and signed char also work), not a volatile int; and the rewrite mask is 0xFF0FFFFF, not 0xFFFF0FFF (the image pool word is ff ff 0f ff). The mask accounted for 2 bytes that were present under every spelling since wave 3. The narrow flag is a spilled register candidate whose zero 1.1p1 does not propagate, so buf gets its own `add r1, sp, #8` base. A plain int is 180 bytes because the zero is forwarded; a volatile int still gives 15.
- 0x0201C7D0: 2 (sp2) / 37 (1.1p1), unchanged, DIFF. Mechanism: in the image the address would interfere with r4..r7, so it is rematerialised at each call. 1.1p1 stores z early, frees r4 and caches the address there. 14 measurements: volatile extern, `g[1]`, optimiser pragmas, -O levels, inline wrappers, `register`, a volatile local, labels. All 37, except that -O0 reloads per site but is 68 bytes.
- 0x0201D768: 66, unchanged. A 180-compile sweep (long/ulong total and head, every declaration order): 66 to 68. Also measured: const head read, do/while, for, operand order, `&base[...]` (66). New reading: the image keeps the returned base as the spilled variable, and every compile rematerialises it as p+0x18.
- 0x0201DB20: 15, unchanged. Sweeps of long hi/lo/mid by order, and m as an integer type: 15 or 18. Five chain-step spellings: 15, 16 and 26. Permuter seed 2901: it chases the 156-byte extent (156/40).

Files written: src/matched/func_0201C8BC.c; docs/idioms/a-narrow-flag-local-is-spilled-not-constant-propagated.md; a "2026-09-24, wave 19 (lane printsys_2)" section in each of the four notes; layout/matched/arm9/pkt_0201C8BC.json (rewritten by manifest).

Shards verified: pkt_0201C8BC, manifest --verify twice (1 rewritten, then 0). Both entries are EXACT.

Seeds: none new. Permuter seed used: 2901.

For the integrator: stage src/matched/func_0201C8BC.c, the idiom, the four notes and layout/matched/arm9/pkt_0201C8BC.json. docs/families/printsys.h (PrintCtx+0x04 comment, line 91) still says 0xFFFF0FFF, and it should say 0xFF0FFFFF. Also worth trying on other near misses that were closed as "volatile flag" scaffolding: a plain u8 flag.
