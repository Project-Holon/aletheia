# Wave 15, mcss.c lane

EXACT 5 worklist rows (3 files, 3408 bytes): 0x02014D2C + 0x02014D90 + 0x02015590 (one unit), 0x020163C4, 0x02016630.
MATCH 0.  DIFF 2 (notes appended with best-source markers): 0x020172D8 (47 out), 0x02016C60 (61 out).

Three-row function: src/matched/func_02014D2C.c, `unit: yes`, function line names func_02014D2C,
func_02014D90, func_02015590.  `match.py tu --addr 0x02014D2C --thumb` compares all 2164 bytes across
the false labels with no refusal; the manifest writes one game_unit entry listing all three names, and
worklist shows every row `matched`.  Lever: G3_TexImageParam as the SDK inline with ENUM parameter
types (int parameters: 2168 bytes, 540 out; hand or-chain: 43 out).

0x020163C4 (16 out) and 0x02016630 (21 out): the descriptor parameter is `const struct Src *`.
New idiom: docs/idioms/const-on-a-descriptor-parameter-orders-the-argument-loads.md.

Near misses:
- 0x020172D8: first divergence +0x04 `adds r2, r0, #0` (compiled `adds r3, r0, #0`), a three-register
  rotation (a0/k/b0).  Block scopes, array lo/hi, const table, enum counters (worse), permuter hill and
  anneal 2000 --types: flat.  docs/notes/pkt_020172D8.c.txt.
- 0x02016C60: first divergence +0x50 `str r3, [sp, #0x10]` (compiled `[sp, #0x18]`), frame-slot order
  only.  const Work (876 bytes), split second-pass locals (90/101), hill 800 at the 870 extent: flat.
  docs/notes/pkt_02016C60.c.txt.

Integrator: seed.  None.  0x02014D90 and 0x02015590 are false starts (bl long branches), not in
layout/function_starts.txt; they are auto labels, so nothing to add.  Dropping them is optional.

Files: src/matched/func_02014D2C.c, src/matched/func_020163C4.c, src/matched/func_02016630.c,
layout/matched/arm9/pkt_02014D2C.json (new), layout/matched/arm9/pkt_020163C4.json, docs/families/mcss.h
(section 10), the idiom above, notes pkt_02014D2C_boundary, func_020163C4, func_02016630, pkt_020172D8,
pkt_02016C60.

Shards verified (each twice): pkt_02014D2C (1 entry EXACT), pkt_020163C4 (5 entries EXACT).
