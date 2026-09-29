# A flag bit at bit N of a word is a bitfield declared low bits first

summary: mwcc allocates bitfields from bit 0 upward, so a flag read as `lsls #(31-N); lsrs #31` (or written through a `bics`/`ands` with a pooled `~(1<<N)`) is `u32 lo:N; u32 f:1; u32 hi:31-N`, low padding declared first; MSB-first padding gives the mirrored shift.

Found in: src/matched/ov/ov094_func_022005C4.c (bit 9, `lsls #0x16`),
src/matched/ov/ov094_func_02200608.c (bit 10 write),
src/matched/ov/ov094_func_02200654.c (bits 5 and 10),
src/matched/ov/ov094_func_02200344.c (a 1-bit field at bit 31 beside a 31-bit field)

Declaring the padding after the flag (`hi:22; f:1; lo:9`) compiles to
`lsls #9` instead of `lsls #0x16`: the diff is the shift count and the pooled
mask only. Reorder the padding, not the types.

When a 1-bit field at bit 31 sits above a 31-bit sibling and the image shows
`and #0x80000000; and #0x7fffffff; ... lsls #0x1f; orrs`, two statements wrote
it: `o->a = 0; o->flag = flag;` (the first clears the 31-bit field, the second
is the flag insert). One statement gives half of that.
