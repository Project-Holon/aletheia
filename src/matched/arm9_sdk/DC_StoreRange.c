/*
 * function: DC_StoreRange
 * address:  0x020862D4
 * packet:   pkt_020862D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void DC_StoreRange(void)
{
    add	r1, r1, r0
    bic	r0, r0, #0x1f
loc_020862DC:
    mcr p15, 0, r0, c7, c10, 1
    add	r0, r0, #0x20
    cmp	r0, r1
    blt loc_020862DC
    bx	lr
}
