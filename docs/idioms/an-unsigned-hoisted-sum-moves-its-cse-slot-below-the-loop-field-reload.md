# An unsigned hoisted sum moves its CSE slot below the loop's field reload

summary: a loop body with `(a + b)` used twice (a fixed-point multiply and an
index product) hoists the sum into a spilled CSE temporary. When `a + b` is
`int`, that temporary takes a slot above the per-iteration reload of a field
(`p->w` read for `%` and `/`); in the image it sits one slot lower. Making
the sum unsigned (here a `u32 layer` with an `int dir`) swaps the two slots.
The instructions stay the same.

Found in: src/matched/ov/ov021_func_0218D570.c (0x0218D570)

The second loop of func_0218D570 computes `FX_MUL((layer + dir) << 12, h)` and
`(layer + dir) * total`. With `int layer` the build differed only in
`sp+0x20` and `sp+0x24` (the sum temporary and the `p->w` CSE). With
`u32 layer` it is EXACT. Two related points from the same function:
- the `i / p->w` call goes to `_s32_div_f` (0x0209C0A4), so `i` is `int` even
  though the bound `total` is `u32` (the `blo` loop test comes from `total`);
- `FX_Div(p->size, ..)` with a separate `size = p->size` local keeps the
  sign-extension pair off `size`'s slot (see
  an-unused-frame-word-under-a-sign-extension-spill-is-a-field-passed-to-an-earlier-call.md).
