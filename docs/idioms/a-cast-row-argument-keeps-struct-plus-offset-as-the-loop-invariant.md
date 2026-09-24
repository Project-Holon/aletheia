# A `(u8 *)` cast on an array-row argument keeps p + K as the loop invariant

summary: an inlined bit helper called as `Reset(p->row[i], x)` (or
`p->row[2]`) lets 1.1p1 reassociate the address as (p + x>>3) + K and keep K
in a register; the same call with a redundant `(u8 *)` cast on the row keeps
p + K as one operand, so p + K is hoisted out of the loop and indexed
`[base, off]`, and p itself can then leave the register file.

Found in: src/matched/func_0200CA98.c (0x0200CA98)

The original computes `p + 0x30E` and `p + 0x317` once before the form loop
and `p + 0x1AC` once before the four-row clear loop (row = base + k * 0x54,
`ldrb [row, off]`), and keeps p spilled at [sp]. With `u8 unk1AC[4][0x54]`
and `ResetBit(p->unk1AC[i], id)` the compiler instead forms `p + off`, holds
0x1AC (and 0x30E / 0x317 in ip/lr) as register constants, keeps p in r7 and
spills other parameters, a rotation five lanes chased as an allocator order
problem (89 bytes out). `ResetBit((u8 *)p->unk1AC[i], id)`, with the cast on
every row argument, is EXACT. The cast changes no type (the row already
decays to `u8 *`); it is a separate tree node that the reassociation does not
look through. Related: a-char-cast-on-the-base-pins-the-base-plus-index-sum.md.
