# Wave 14 lane: btl_setup, game_data, musical_dist_save, game_beacon

EXACT 1 / MATCH 0 new / DIFF 3 (plus 4 walls re-verified unchanged).

- btl_setup.c: EXACT 0x02013360 (src/matched/func_02013360.c). Levers: 0x02082D44 is
  MI_CpuCopy8 (src, dst, size), and the first loop counter initialised at its declaration so
  the shared zero is created first and takes r0. DIFF 0x02013528, 6 bytes: the single
  diverging instruction is the prologue `str r3, [sp]` (image +0x04, compile +0x0A); 1.1 to
  1.3 and every 2.0 build tried, parameter types, memory homes, early references, counter
  placement all flat.
- game_data.c: 0x02012704 (MATCH, 5 sites) and 0x020124F4 (MATCH, 4 sites) re-verified; ov010
  callees have no branch outside the range, wall unchanged.
- musical_dist_save.c: DIFF 0x0200C52C (120/120, 56 out): first divergence is the entry spill,
  image homes sys (`str r0, [sp, #4]`), compile keeps sys in r6. Permuter hill 800 + anneal 2000
  flat, 48-way prototype grid flat. DIFF 0x0200CA98 (392/392, 147 out): first divergence
  `str r1, [sp, #4]` vs `str r2, [sp, #8]` order at +0x0A; tail reorderings no better.
- game_beacon.c: 0x020274C8 (MATCH, absolute 0xE7 symbol) and 0x0202685C (MATCH, 4 x
  0x02167394) re-verified. The ov010 callee 0x02167394 compiles byte-exact
  (`id > 0x1d ? 0 : data_02171F3C[id]`) but only MATCH: its table pool has no class for overlay
  data, so it was not filed (note appended); needs an overlay data map in sole-ref, not C.

Seeds: none filed. (0x02167394 thumb ov010 would be a start, but seeding alone does not
attest the calls.)

Near misses: 0x02013528 `str r3, [sp]` position; 0x0200C52C `str r0, [sp, #4]` vs
`adds r6, r0, #0` at +0x04; 0x0200CA98 id/sel home-store order at +0x0A.

Notes appended: docs/notes/pkt_02013360, pkt_02013528, pkt_0200C52C, pkt_0200CA98,
pkt_0202685C (.c.txt); docs/families/btl_setup.h wave-14 block.

Shards verified: pkt_02013360 (twice; 3 entries, func_0201347C stays EXACT*).
