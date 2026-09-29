# A one-trip loop survives only when a signed counter is compared against an unsigned (sizeof) bound

summary: when the original keeps a loop whose bound is 1 (`cmp rN,#1; blo`,
often with the counter spilled to the stack), write the counter as `int` and
the bound as `sizeof(tbl) / sizeof(tbl[0])` (or `1u`); an `int` counter
against `1`, or an `unsigned` counter against any bound, is folded into a
single straight-line pass.

Found in: src/matched/ov/ov048_func_021F4590.c (0x021F4590)

The original walks a one-element u16 table in an outer loop and a three-byte
table in an inner one:

    movs r0,#0; str r0,[sp,#4]         ; i = 0, kept on the stack
    ldr  r0,[sp,#4]; lsls r1,r0,#1     ; loop top: tbl16[i]
    ...
    ldr  r0,[sp,#4]; adds r0,#1; str r0,[sp,#4]
    cmp  r0,#1; blo top

1.1p1 at `-O4,p` deletes a loop it can prove runs once. Every spelling that
gives it a signed compare against a literal (`int i; i < 1`, `1 > i`,
`i != 1`), or an unsigned counter (`unsigned i; i < 1`, `i < sizeof ...`),
comes out 68-72 bytes with no outer loop, so the register pressure that
spills `i` and the parameter never appears. `unsigned i; i <= 0` (or `i ==
0`, `!i`) keeps the loop but tests with `beq` (92 bytes).

Mixing the signedness is what defeats the trip-count proof while keeping the
unsigned `blo`: `int i` with `i < sizeof(d_021F4E5C) / sizeof(d_021F4E5C[0])`
(the table declared `extern u16 d_021F4E5C[1];`), `i < 1u` and `(unsigned)i
< 1` all give the original's 96 bytes. The sizeof form is the natural
source.
