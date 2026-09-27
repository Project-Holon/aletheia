/*
 * function: IC_InvalidateRange
 * address:  0x0208632C
 * packet:   pkt_0208632C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void IC_InvalidateRange(void)
{
    add	r1, r1, r0
    bic	r0, r0, #0x1f
loc_02086334:
    mcr p15, 0, r0, c7, c5, 1
    add	r0, r0, #0x20
    cmp	r0, r1
    blt loc_02086334
    bx	lr
}
