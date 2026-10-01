# An enum-typed mask local keeps `ands` with a materialised complement instead of folding to `bics`

summary: when a source masks with `& -32` / `& ~0x1f` on an `int`, mwccarm
recognises the complement of a power of two and lowers it to `bics rD, rN`
(two instructions fewer in Thumb). Declaring the mask as a local of enum type
(`AlignMask am = ALIGN_MASK;` with `ALIGN_MASK = -32`) makes the value opaque to
the folder, so the backend materialises the complement and uses `ands`, which is
the image's form. This is the same "enum type keeps a value out of constant
folding" lever as an-enum-type-keeps-values-out-of-constant-folding.md and
an-enum-local-materialises-a-large-complement-constant.md, applied to a small
mask rather than a large bound.

Found in: src/pending/ov_sdk/ov016_func_021B97A8.c (0x021B97A8)

The image aligns an allocation to 32:

```
021B97D8  movs r1, #0x1f
021B97DA  adds r2, r0, r1
021B97DC  adds r0, r1, #0
021B97DE  subs r0, #0x3f        /* 0x1f - 0x3f == -0x20 */
021B97E0  adds r3, r2, #0
021B97E2  ands r3, r0
```

With the obvious `(x + 0x1f) & -32` the backend folds it to `adds r0,#0x1f` then
`movs r3,#0x1f / bics`, two instructions fewer (the 4-byte size gap). Every
arithmetic spelling of the mask (`& -32`, `& ~0x1f`, `& -0x20`,
`& (int)0xffffffe0`, `& (unsigned long)-32`, `& 0 - 32`) is byte-identical.

Declaring the mask as an enum local stops the fold:

```c
typedef enum { ALIGN_MASK = -32 } AlignMask;
...
AlignMask am = ALIGN_MASK;
g_work = (x + 0x1f) & am;
g_work2 = (y + 0x1f) & am;
```

The backend must materialise `am` and, finding `0x1f` (or another small live
constant) already in a scratch register, derives `-0x20` from it and uses
`ands`, matching the image's shape (its exact source register for the
derivation, and whether it derives off `0x1f` or another live constant, still
depends on the surrounding allocation).

The residual hazard: the enum local is itself an IR value, so it can perturb
register colouring elsewhere; the lever fixes the `bics`-vs-`ands` encoding and
the byte count, not the whole function.
