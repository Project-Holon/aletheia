# A compound product on a byte-offset local gives the index the late colour

summary: when a Thumb record-array address copies the index before `muls` (`adds r1,r4,#0; muls r1,r0,r1`) and the image has the index in a higher register than the product, every `p->arr[idx]` spelling colours the index first (index r1, product r4). Write the index as a u32 byte offset that is multiplied in place and added to a `(u32)p` base: `off = mode - 7; off *= 0x38; *(int *)(base + off + 0x14) = 1; base += off;`.

Found in: src/matched/ov/ov112_func_021F546C.c (0x021F546C)

The image (slot block of a callback, mode in r0, in in r3, p in r2):

    subs r4, r0, #7
    movs r0, #0x38
    adds r1, r4, #0      ; copy of the index into the LOWER register
    muls r1, r0, r1
    adds r2, r2, r1
    movs r0, #1
    adds r4, r2, #0
    adds r5, r3, #0
    str  r0, [r2, #0x14] ; enabled = 1 at base + 0x14

Over waves D5 to D9r about 60 spellings left 5 bytes (index r1, product r4): array subscripts through
a struct member, pointer locals, inline getters, `mode -= 7`, long and unsigned indices, idx before the
compare (6 bytes), later uses of idx. Raw byte-offset forms with a pointer cast lose the copy
(`muls r0,r1,r0`, 157 bytes out). Two things together give the image:

    u32 off = mode - 7;
    u32 base = (u32)p;
    off *= 0x38;                       /* compound product: index and product are one web */
    *(int *)(base + off + 0x14) = 1;   /* first store addresses base + off + K */
    base += off;                       /* later stores use base + K */

A separate `idx` and `off = idx * 0x38` (with the same first store) keeps the copy but still gives the wrong
colours (5 bytes). `off = (mode - 7) * 0x38` in one expression: 5 bytes. Folding the offset into the base
before the first store (`base = (u32)p + off`) loses the copy (157). The compound `off *= 0x38` makes the
index and the product one web, which the allocator colours after the short-lived constant and copy.

Tell: the copy goes from a higher register to a lower one with no loop or call between, and array-subscript
spellings all give the registers the other way round.

Related: a-thumb-multiply-into-the-reloaded-operand-is-a-compound-assignment.md,
a-product-kept-in-its-parameter-multiplies-in-place.md, an-integer-table-base-multiplies-into-a-copy-of-the-index.md.
