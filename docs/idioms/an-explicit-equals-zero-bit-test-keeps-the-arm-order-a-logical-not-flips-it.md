# An explicit `== 0` bit test keeps the source arm order; a logical `!` on the same test flips it

summary: for two returning arms guarded by one bit, `if ((f & 1) == 0) return A; return B;` puts A on the fall-through after `tst; bne`, while `if (!(f & 1))`, `if (f & 1)` with the arms swapped and the ternary all normalise to `tst; beq` with the set-bit arm first.

Found in: src/matched/ov093_func_021B8C20.c (0x021B8C20), src/matched/ov093_func_021B8C38.c (0x021B8C38)

The original is `movs rK, #1; tst rF, rK; bne L; <arm A>; bx lr; L: <arm B>; bx lr`,
with arm A the value for the clear bit. Every form that tests the bit as a truth value
(`!(f & 1)`, `f & 1` with the arms written the other way round, `(f & 1) ? B : A`)
compiles to `beq` with arm B on the fall-through: the front end canonicalises a
truth test so the set-bit arm comes first, whatever order the source used. Only the
comparison form `(f & 1) == 0` (or `f % 2 == 0`, or `switch (f & 1) { case 0: ... }`)
keeps arm A first. When a one-bit dispatch comes out with the arms swapped and no
reordering of the source helps, spell the test as an explicit comparison against zero.

The same normalisation stopped func_021B9A40 (`x >= 12` with the true arm on the
branch target), where no comparison spelling reproduced the original; see
docs/notes/pkt_ov093_021B9A40.c.txt.
