# Wave 21, lane G: 0x02069BA0, 0x02071104, 0x0209D7D4

All three targets closed. About 50 manual compiles and 117 permuter compiles (one anneal, stopped early).

| address | before | after | compiler | lever |
|---|---|---|---|---|
| 0x02069BA0 | DIFF 6 | EXACT | ../2.0/sp2 | Written as NitroSystem g2d `NNSi_G2dBitReaderRead` in the library's own shape. The same C under 1.1p1 still gives 6 out, the known `mov r1, r6` / `mov r2, #8` swap. sp2 and sp1 give 0 out. |
| 0x02071104 | DIFF 6 | EXACT | ../2.0/sp2 (the family's existing pin) | NitroSystem g3d maya.c `texmtxCalc_flagR_`, with the _31 term spelled `-scaleT - scaleT + 0x1000 * 2` instead of any shift or `* 2` form. 1.1p1: 116 bytes. sp2, sp2p2 and sp1: 0 out. |
| 0x0209D7D4 | DIFF 43 | EXACT* | dsi/1.1p1 | `func_0209D778` takes one argument. The image's `mov r1, #0` is the register holding the terminator store's zero, not a second argument. Output is 68 bytes, 0 out. |

## Method
- Library identification: `ntrtwl/NitroSystem`, the 071126 reconstruction that pokeplatinum builds against, was read-only cloned outside the repo. `libraries/g2d/src/internal/g2di_BitReader.c` and `libraries/g3d/src/cgtool/maya.c` gave both NitroSystem bodies directly. No MSL source was found for 0x0209D7D4.
- 0x0209D7D4: about 35 spellings aimed at the zero were measured before the arity lever: CSE-defeating constants, inline helpers, argument-embedded stores, unprototyped callees, callees defined in the same TU, and optimisation-flag probes. All gave 43, and none moved the zero out of r2. The full list is in the dated note section.

## Files touched
- src/matched/func_02069BA0.c (new), shard layout/matched/arm9/pkt_02069BA0.json (verified twice)
- src/matched/func_02071104.c (new), shard layout/matched/arm9/pkt_02071104.json (verified twice)
- src/matched/func_0209D7D4.c (new), shard layout/matched/arm9/pkt_0209D7D4.json (new, verified twice, EXACT*)
- docs/notes/func_02069BA0.c.txt, docs/notes/pkt_02071104.c.txt, docs/notes/func_0209D7D4.c.txt (dated sections appended)

## For the integrator
- docs/FRONTEND-PINS.md needs rows for the two new sp2 pins. The evidence is in each file's header. For 0x02069BA0 it is `mov r1, r6` (06 10 a0 e1) at 0x02069BD8 before `mov r2, #8` (08 20 a0 e3) at 0x02069BDC. For 0x02071104 it is a size tell: 1.1p1 gives 116 bytes against the image's 124. This lane did not edit FRONTEND-PINS.md because it is outside the write set.
- Seed the unlabelled leaf at 0x0209D818 (`mov r0, #0; bx lr`, 8 bytes) into layout/function_starts.txt.
- `python3 tools/selfcheck.py` passes (2/2).
