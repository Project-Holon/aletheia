# A two-dimensional array at a byte offset is a struct member, not a cast

summary: when a loop stores or loads `u16` elements at `p + K + row*RS + col*2` and the image keeps `K` as its own register or spilled constant (`strh rX, [rBase, rK]` with rBase = p + row*RS + col*2), declare the array as a member of a padded struct (`u16 unk_K[R][C]`) and index `((struct W *)p)->unk_K[r][c]`; the cast spelling `((u16 (*)[C])(p + K))[r][c]` folds `p + K` into one base kept in `ip` or a spill slot and changes the whole loop.

Found in: src/matched/ov/ov029_func_021F08BC.c (0x021F08BC), src/matched/ov/ov029_func_021F1458.c (0x021F1458)

Spelling (ov029, a u16 [3][5] table at 0x230):

    struct W {
        u8 pad0[0x230];
        u16 unk_230[3][5];
    };

    for (n = 0; n < 5; n++)
        for (m = 0; m < 3; m++)
            ((struct W *)p)->unk_230[m][n] = src[...];

The image computes `r4 = p + n*2` in the outer loop and `r5 = r4 + m*10` in the
inner loop, and stores with `strh r0, [r5, r6]` where `r6 = 0x230` was loaded
once before the loops. Several such tables at different offsets
(0x230, 0x24E, 0x272 in 0x021F08BC) share one row pointer, and each offset
becomes its own spilled constant (`0x24E`, then `0x24E - 0x1E`, `0x24E + 0x1E`,
`0x24E + 0x24` derived by adds from one pool word).

Other spellings:

- `((u16 (*)[5])(p + 0x230))[m][n]` (a cast row pointer): the compiler hoists
  `p + 0x230` into `ip` and spills the source pointer instead (0x021F1458,
  4 bytes short and 134 bytes out); in 0x021F08BC it came out 228 bytes against
  248.
- The struct form with `n = 0` hoisted above the `if`, as in the sibling
  0x021F1574's loop, made it worse (288 bytes); only the struct change was
  needed.
