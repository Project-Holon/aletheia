/*
 * function: OS_EnableProtectionUnit
 * address:  0x02086CF4
 * packet:   pkt_02086CF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void OS_EnableProtectionUnit(void)
{
    mrc p15, 0, r0, c1, c0, 0
    orr	r0, r0, #1
    mcr p15, 0, r0, c1, c0, 0
    bx	lr
}
