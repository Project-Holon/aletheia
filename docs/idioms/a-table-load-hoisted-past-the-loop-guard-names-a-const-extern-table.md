# A table load hoisted past the loop guard names a const extern table

summary: when two `tbl[k]` loads sit after a `for` loop's entry guard but before the loop label (in the preheader), and the body stores through a pointer, the tables are `extern const`; a plain `extern int tbl[]` keeps the loads inside the loop, and assigning them to locals above the `for` puts them before the guard.

Found in: src/matched/ov/ov025_func_021EEE04.c (0x021EEE04)

The image (Thumb, 1.1p1 -O4,p) computes `k = q[1] / 256`, stores `i = 0`,
tests `n > 0`, and only then loads `d_021EF780[k]` (spilled) and
`d_021EF770[k]` (r4) once, ahead of the loop label; the body stores through
`e = func_021A2630(obj)` and calls several functions.

Spellings tried:

- locals `va = d_021EF780[k]; vb = d_021EF770[k];` inside the loop, tables
  non-const: 121 concrete bytes out (loads stay in the body, `k * 4` spilled);
- the same locals assigned above the `for`: 47 out (loads land before the
  `i = 0` store and the guard, and the frame grows by a slot);
- locals inside the loop with `extern const int d_...[]`: 34 out;
- `d_021EF770[k]` written out at each use inside the loop with
  `extern const int d_...[]`: 6 out, all of it the parameter home-store order
  (closed by a narrow third parameter, see
  a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).

Non-const tables can alias the stores through `e`, so mwcc reloads them per
iteration; `const` lets loop-invariant code motion lift them into the
preheader, which sits after the rotated loop's entry guard.
