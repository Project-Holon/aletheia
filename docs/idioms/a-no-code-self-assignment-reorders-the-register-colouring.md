# A no-code self-assignment reorders the register colouring

summary: `s = s;` compiles to nothing but still changes the colouring order of the callee-saved registers around it. When a same-width permutation of three or four registers survives every declaration-order, scope and front-end lever, a self-assignment of one of the rotated variables at the point where its live range meets the others' can settle it. Declaration order does not help here because the colouring order does not follow it.

Found in: src/matched/unit_020979BC.c (0x020979BC, MSL __ieee754_pow, dsi/1.2, ARM)

The residue was a 3-cycle of r6/r7/r8 over 23 words (0x0BC8..0x1170): the
image has t2 (hi) = r6, s = r8:r7 and the final exponent n = r6, while the
fdlibm transcription gave t2 (hi) = r8, s = r7:r6, n = r8. Two earlier lanes
measured more than 40 levers (declaration order of every double and int,
block scope for s, n, z_h/z_l and the log2 temporaries, the scalbn tail in
both orders, 1.2p1, 1.2p2, 1.3, 1.3p1, 1.6sp1, -O3) and none moved it.

The permuter (anneal, seed 1902) found `s = s;` inserted directly after
`p_h = y1*t1;` (after s's last definition, before the overflow tests that
read it). Removing the permuter's two other mutations in the same run
(a `do { } while (0)` around the SET_HIGH_WORD line and a copy of n) keeps
EXACT; removing `s = s;` alone brings back the 25 bytes. Moving the whole
sign computation to that position instead gives 190 bytes out, so the
statement counts only as a reference that produces no code.

It is a matching aid, not a claim about what the original source said. The
original might have had a statement there that the optimiser removed, such as
a debug or macro remnant. Try it after the declaration-order levers and
before a permuter run: put one self-assignment of each rotated variable at
the boundary between their live ranges.
