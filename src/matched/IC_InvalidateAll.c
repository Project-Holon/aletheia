/*
 * function: IC_InvalidateAll
 * address:  0x02086320
 * packet:   pkt_02086320
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void IC_InvalidateAll(void)
{
    mov r0, #0
    mcr p15, 0, r0, c7, c5, 0
    bx lr
}
