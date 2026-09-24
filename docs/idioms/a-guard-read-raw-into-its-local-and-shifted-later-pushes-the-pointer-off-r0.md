# A guard read raw into its local and shifted later pushes the pointer off r0

summary: when a guarded block starts with `if (p->f != 0) { v = p->f >> 12; ...` and the image keeps the record pointer out of r0 (r0 holds the guard value and the header temporaries), read the field raw into the local before the guard (`v = p->f; if (v != 0) {`) and put `v >>= 12;` after some of the other header reads. The raw web then spans those reads and is coloured before the pointer.

Found in: src/matched/func_02016C60.c (0x02016C60)

The image (mcss.c, dsi/1.1p1, Thumb) builds the pass-2 record pointer into
r1 and uses r0 for the guard value, then for the header temporaries:

    ldr  r1, [r0, #0x2c]     ; a0->f2c
    ldr  r0, [sp, #0x10]     ; k * 0x30
    adds r1, r1, r0          ; the pointer, in r1
    ldr  r0, [r1, #0x2c]     ; guard value, r0
    cmp  r0, #0
    beq  ...
    asrs r0, r0, #0xc        ; w2
    ...                      ; sx2/sy2 in r3, both zeros in r0

With `if (R->f2c != 0) { w2 = R->f2c >> 12; ... }` the pointer is coloured
first and takes r0 (`adds r0, r1, r0`), under every header order (120 of
them), pointer spelling, dead definition and self-assignment. Wave 21 lane B
reached 16 bytes out by splitting a different local (h2) across the header,
but then i2's zero landed in r3.

The spelling that matches keeps the pass-1 header order and moves only the
shift of w2:

    w2 = R->f2c;
    if (w2 != 0) {
        sx2 = R->f34 >> 12;
        sy2 = R->f38 >> 12;
        w2 >>= 12;
        h2 = (R->f30 >> 12) << 1;
        i2 = 0;
        y = 0;

This source is EXACT*. Where the shift goes matters. Of the 24 orders of
{h2, sx2, sy2, `w2 >>= 12`} before the zeros, only sx2, sy2, shift, h2 is
exact. sy2, sx2, shift, h2 is 4 bytes out, and the shift before both reads
is 30 to 36. Moving the shift late does not change the compiled instruction
order: `asrs r0` still follows the compare. So the lever is the length of
the raw web, not where the shift appears.
