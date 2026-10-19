# Under 2.0 a static inline helper for a repeated block sets the register colours

summary: with the 2.0/sp2 front end, writing a repeated block (a byte swap, a
cipher step) as a `static inline` helper turns its values and addresses into
codegen temporaries that are coloured first; the same block written inline
in the caller gets a rotated colouring that no declaration order fixes.

Found in: src/matched/ov/ov230d_func_0218949C.c (0x0218949C),
src/matched/ov/ov230d_func_021895B8.c (0x021895B8),
src/matched/ov/ov230d_func_021896D0.c (0x021896D0)

The three ov230 cipher functions (2.0/sp2, ARM, -O4,p) had the right
instruction sequence and 21, 32 and 36 words of register colour residue.
None moved by declaration order, loop form or pragmas. What closed them:

  * StreamInit: the swap as `static inline void SwapBytes(u8 *a, u8 *b)`,
    called after j is updated, with the k reset after the swap.
  * SealStream and OpenStream: the per-word step as an inline helper
    (`SealWord`, `OpenWord`) called from each case.

Two companion facts from the same functions:

  * A `long` loop offset avoids the CAST CSE temporary that otherwise takes
    the offset's colour (see a-long-index-colours-apart-from-an-int.md).
  * A redundant copy `*(u32 *)(dst + off) = *(u32 *)(src + off);` followed by
    reads of the destination is forwarded by 2.0, which moves the store after
    the mask instructions; that is the image's bic/and/str order.

tools/mwccdbg models 1.1p1 only, so it cannot trace these colourings.
