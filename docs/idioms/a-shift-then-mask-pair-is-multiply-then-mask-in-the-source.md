# A `lsl`/`and` pair on a tile offset is multiply-then-mask in the source, not mask-then-multiply

summary: `(v & 7) * 8` compiles to a `lsl #0x1d` / `lsr #26` pair, so a
literal `lsl #3` / `and #0x38` in the original means the source wrote
`(v * 8) & 0x38`; the same spelling one field wider, `(v * 8) & 0x7fc0`,
is how a tile index scaled to bytes reaches a single `and Rd, Rmask, Rn, lsl #3`.

Found in: docs/notes/sub_02044CE0.c.txt (0x02044CE0, 0x02044EBC), 0x02044BF0

The tiled-surface routines around 0x02044BF0 address an 8bpp surface as

    pixel = base + (y >> 3) * 64 * tilesWide + (x >> 3) * 64
                 + (y & 7) * 8 + (x & 7)

but none of those terms appears in that shape in the compiled code.  What the
original actually contains is

    lsl r6, r2, #3
    and r6, r6, #0x38          ; the row inside the tile
    and r6, r8, r2, lsl #3     ; r8 = 0x00007fc0 from a pool word

Writing the arithmetic the obvious way does not produce either one:

    (i & 7) * 8      ->  lsl r6, r2, #0x1d   /  lsr ... #26
    (i >> 3) * 64    ->  asr r5, r2, #3      /  lsl r5, r5, #6

Both are two instructions and neither matches.  Writing the multiply first
and masking afterwards does:

    (i * 8) & 0x38   ->  lsl r6, r2, #3      /  and r6, r6, #0x38
    (i * 8) & 0x7fc0 ->  and r6, r8, r2, lsl #3

The second form is the tell worth remembering, because it collapses to one
instruction by folding the shift into the `and`'s operand, and it explains an
otherwise puzzling pool word: 0x7fc0 is not an ARM immediate, so the constant
has to be pooled, and a pooled mask of the shape `0x1ff << 6` or
`0x3ff << 5` next to a `lsl` of the tile shift is this idiom, not evidence
that the source masked a coordinate to nine bits.  The 4bpp sibling at
0x02044BF0 uses 0x00003fe0 and `lsl #2` for exactly the same reason.

The two spellings are not interchangeable for a byte match even though they
compute the same value for the non-negative coordinates these loops guard
for: the mask-then-multiply form keeps the sign bits the multiply-then-mask
form discards, so the compiler cannot rewrite one into the other.
