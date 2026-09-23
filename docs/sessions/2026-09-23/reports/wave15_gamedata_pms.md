# Wave 15 lane: musical_dist_save, bmp_win, pms_draw, bmp_oam (game_data/game_beacon re-verified)

EXACT 3 / MATCH 0 new / DIFF 2 (plus 4 walls re-verified).

- musical_dist_save.c 0x0200C52C (Thumb, 120 B): 56 out -> EXACT, src/matched/func_0200C52C.c. The func_020073D8
  call written in BOTH arms of the `r == 1` test (tail-merged); that is what keeps 6 in r7, the zero in r2 and spills sys.
- bmp_oam.c 0x020255A0 (Thumb, 364 B): 8 out -> EXACT, src/matched/func_020255A0.c. `const struct Param *param`
  closes both scheduling swaps at once.
- bmp_win.c 0x020454E0 (ARM, 536 B): 2 out -> EXACT, src/matched/func_020454E0.c. Palette bits built in place in pal
  (`pal &= 0xf; pal <<= 12;`), which coalesces pal with the result in r6, plus a u16 base parameter (permuter hill
  --types found the second half; either lever alone is 55 or 2 out).
- musical_dist_save.c 0x0200CA98 (Thumb, 392 B): DIFF 147 -> 147. Declaration positions, parameter and local type grids,
  15 const combinations, tail order, permuter anneal 1500: all flat. Home-store order id/sel and acc r1 vs r2.
- pms_draw.c 0x0202E1F0 (Thumb, 412 B): DIFF 400/412, 371 -> 371. New: `const u32 c2` gives the image frame
  (0x48, push r3) but by spilling c2 instead of n (378 out). 42 declaration orders, 36 const combinations, wp pointer
  shapes, permuter hill 600: flat or not value-preserving.
- game_beacon.c 0x020274C8 (report only): MATCH*, capped by the absolute overlay-id symbol ov231_id (0xE7).

Re-verified (not worked), fresh verdicts: game_data 0x020124F4 EXACT (39/39 sites resolved; still in src/pending,
for the owning lane to move and shard); game_data 0x02012704 MATCH* (func_0215E334, func_02159BBC: ov009/ov010
overlap, needs a region hint); game_beacon 0x0202685C MATCH (4 x func_02167394, ov009/ov010 overlap).

Levers new this wave: a call written in both arms of a test (tail merge) changes allocation across the whole function;
`const` on a read-only struct parameter reorders loads around stores; in-place compound update of a parameter coalesces it.

Notes appended: docs/notes/pkt_0200C52C, pkt_0200CA98, pkt_020255A0, pkt_020454E0, pkt_0202E1F0 (.c.txt).
Family headers: bmp_win.h, musical_dist_save.h updated.

Seeds: none (all three closures are labelled starts; plain EXACT, no follower).

Shards verified (twice each, 0 rewritten on the second pass): pkt_0200C52C (4 entries EXACT), pkt_020255A0
(func_020255A0 EXACT, func_0202570C EXACT* unchanged), pkt_020454E0 (new, 1 entry EXACT).
