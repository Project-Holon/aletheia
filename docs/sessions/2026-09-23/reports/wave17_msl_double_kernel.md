# Wave 17 lane 17F: msl_double_kernel

0x020979BC (entry at the home push; body label func_020979C0): identified as MSL
__ieee754_pow (fdlibm e_pow.c, 5.3 shape with MSL edits). Before: no source
(report-only). After: DIFF, 25 concrete bytes out of 4488. The size is 4488/4488 and
136 of 136 relocations resolve. The residue is one register rotation: the image has
t2 = r4:r6, s = r8:r7, final n = r6, and 1.2 gives t2 hi = r8, s = r7:r6, n = r8.

What moved it (3531 -> 1874 -> 25):
- MSL edits read from the image: EDOM (33) plus the `__float_nan` float for
  (x<0)**non-int; no `s*` in the |y| > 2**31 returns; `t = x-one`; the sign test kept
  in its own variable and `s` computed after the log2 if/else.
- Compiler: dsi/1.2 (1.2p2 gives the same). 1.1p1 uses a push {r4-fp,lr}/0x7c frame
  and does not keep &bp in a register. 1.2 matches the image's push {r3-fp,lr}/0x78
  frame and keeps the base.

20 hand measurements plus one permuter run (800 compiles, nothing under 25), all
logged with the best source in docs/notes/pkt_020979C0.c.txt. Nothing filed in src/;
no shard verified.

Layout: in layout/runtime_arm9.txt, the `020979C0 _msl_double_kernel` row is now
`020979BC`, because the worklist matches runtime rows by exact address. The
02099228 row is unchanged, since nothing was matched.
- 02098B48 _msl_double_fn_1 (__ieee754_rem_pio2) has the same +4 offset: the home
  push is at 0x02098B44. Only the 4-byte push row is open today, but seeding
  0x02098B44 would reopen the whole body, as happened here.
- 0209953C _msl_double_fn_2 is correct: it is preceded by pool data, not a push.

Seeds: none new. The scalbn callee 0x02097990 (bl at 0x02098B14) is already a start;
the data tables are at dp_h 0x020A62F0, bp 0x020A6300, dp_l 0x020A6310.

Integrator:
- Add a FRONTEND-PINS row for this MSL member: dsi/1.2, with the kept table base and
  the image's frame as the tell.
- Re-run the worklist so the layout row change is picked up.
