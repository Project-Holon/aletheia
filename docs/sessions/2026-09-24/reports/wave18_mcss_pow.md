# Wave 18, lane 18D (mcss_pow)

## 0x020979BC, MSL __ieee754_pow: 25 -> 0, EXACT, filed
- Filed `src/matched/unit_020979BC.c` (dsi/1.2, 4488/4488 bytes, 136/136 relocations). The fix is one line added to the wave-17 source: `s = s;` after `p_h = y1*t1;`. It emits no code and settles the r6/r7/r8 rotation. Permuter (anneal, 1500 budget, seed 1902) found it at compile 1002, and I reduced its other two mutations by hand.
- `manifest --verify --shard pkt_020979BC` run twice: EXACT, the second pass rewrote nothing.
- Brief levers, all measured and worse or flat: tail declaration order 65/146, n after the doubles 77, scalbn guard reversed 25, ../1.2/base SIZE, 1.3 65; s is a double. 25 measurements.
- FRONTEND-PINS: the row `pkt_020979BC (not filed) | dsi/1.2` should now read `src/matched/unit_020979BC.c | dsi/1.2`, with 4488 bytes and 0 mismatches. The tell is unchanged (`push {r3-fp, lr}`, 0x78 frame, bp base kept across three uses). 1.1p1 gives 1874 out.
- New idiom: `docs/idioms/a-no-code-self-assignment-reorders-the-register-colouring.md`.

## 0x02016C60, mcss.c block stamper: 61 -> 29, DIFF
- Read the frame off the image: named locals at the top in declaration order, second webs of shared variables at the bottom, loop invariants between.
- Levers that moved it: pass 2 has its own i2/j2 but shares x/y; a separate `nib` holds the (u8) value; hi/hi2 block-local; inner loop written as `for (j = 0, x = 0; ...)` (76 -> 50, every stack slot right). Permuter (870-extent wrapper, seed 1901, 1500 compiles): 29.
- Residue: only the pass-2 record-pointer register (r1 in the image, r0 here); nine pointer spellings did not move it. 30 measurements recorded; best source in docs/notes/pkt_02016C60.c.txt under the 2026-09-24 marker.

## Files
src/matched/unit_020979BC.c, layout/matched/arm9/pkt_020979BC.json, docs/notes/pkt_020979C0.c.txt, docs/notes/pkt_02016C60.c.txt, the idiom file, this report.

## Seeds
None noticed.

## Integrator
- Update the FRONTEND-PINS row for pkt_020979BC.
- Regenerate the idiom index.
- layout/runtime_arm9.txt already drops 0x020979BC, so it needs no layout change.
