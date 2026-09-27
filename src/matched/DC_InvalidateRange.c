/*
 * function: DC_InvalidateRange
 * address:  0x020862B8
 * packet:   pkt_020862B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void DC_InvalidateRange(void)
{
    add	r1, r1, r0
    bic	r0, r0, #0x1f
loc_020862C0:
    mcr p15, 0, r0, c7, c6, 1
    add	r0, r0, #0x20
    cmp	r0, r1
    blt loc_020862C0
    bx	lr
}
