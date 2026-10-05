# A halfword compared with a small constant branches unsigned unless the operand is int-typed

summary: dsi/1.1p1 turns a compare of a zero-extended u16 value against a non-negative
constant into an unsigned branch (`bhs`/`blo`). When the image has the signed branch
(`bge`/`blt`) on a plain `ldrh` value, the operand was int-typed in the source: an
int-returning accessor, an int local, or a cast. The reverse also holds: an unsigned branch
against a constant held in an int local needs an unsigned local.

Found in: src/pending/ov/ov133_func_021B765C.c (0x021B765C)

Measured under dsi/1.1p1 -O4,p, same body, one change at a time:

* `*(u16 *)(p + 0x94) < 45`: `ldrh; cmp r0, #0x2d; bhs`. The image has `bge`.
* `GetTimer(p) < 45` with `static inline int GetTimer(u8 *p) { return *(u16 *)(p + 0x94); }`:
  `bge`, other bytes unchanged. `int c; ... (c = *(u16 *)(p + 0x94)) < 45` and
  `(int)*(u16 *)(p + 0x94) < 45` give the same bytes (the cast is a stand-in; prefer a real
  int-typed source).
* A u16 angle `a` against `int h = 0x8000` (h kept as a variable, see the D3 local-constant
  lever): `a >= h` and `a < (h >> 1)` compile `blt`/`bge`. With `u32 h = 0x8000` they compile
  `blo`/`bhs` as in the image. `u16 h` fixes only `a >= h` (h >> 1 is int again).
  With u32 h, any other use of h in a signed division (`(sh - (v.y + h)) / 16`) becomes an
  unsigned shift; write the literal there.

A 2-byte code shift elsewhere in the function hides these one-byte condition differences in
the diff. After a shift fix, recheck every conditional branch.
