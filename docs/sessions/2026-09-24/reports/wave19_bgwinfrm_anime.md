# Wave 19, lane bgwinfrm_anime (19N)

0x0202CC70 (bgwinfrm.c, Thumb, 244 bytes): 47 -> 0 bytes out, EXACT.
What moved it, all four required:
- a named local `xmax = win->xmax`, read by the first guard and the right clip;
- a declaration-order sweep with sx, h, y, sy kept in their relative order
  (their spill slots). Some orders close the r1/r2 swap (47 -> 12). long vs
  s32 xmax makes no difference; the named local plus the order does;
- `sx = win->x;` before `ow = w;` (12 -> 8);
- `s8 sy` (8 -> 0). This is value-preserving because sy only ever holds
  win->y or win->ymin. The permuter (anneal 1500, --types, seed 3304) found
  it; hand minimisation showed the type alone closes the ymin reload and the
  argument-store order. No compare changed signedness.
The callee prototype is the one func_02041300's own body declares (flat
either way). 24 hand measurements, two sweeps, one permuter run.

0x02011688 (ica_anime.c): 14 holds (50 bytes against 56). 15 measurements,
including u8 ret, long i, explicit two returns in three placements, a
remainder copy j, idx %= n combinations, and a declaration-order sweep. The
`if (==) {...; return 1;} return 0;` form with a named i gives the image's
block layout and both epilogues (52/31). It lacks only the pre-compare
r1 -> r2 copy. The permuter (seed 3306) gave nothing usable; it drifted into
truncated 4-28 byte compiles that its score ranked above the baseline (a
tools/permuter.py scoring issue for the tool owner).

Files written:
- src/matched/func_0202CC70.c (new, EXACT)
- layout/matched/arm9/pkt_0202CC70.json (rewritten by manifest --verify)
- docs/notes/func_0202CC70.c.txt, docs/notes/pkt_02011688.c.txt (wave 19
  sections appended)
- docs/idioms/an-s8-local-holding-only-s8-fields-reloads-a-spilled-value-instead-of-copying.md

Shards verified: pkt_0202CC70, manifest --verify twice (second pass 0
rewritten).

Seeds: none noticed.

Integrator: stage src/matched/func_0202CC70.c,
layout/matched/arm9/pkt_0202CC70.json, the idiom and the two notes; update
coverage and README milestones. Nothing committed.
