/*
 * file:     unit_02086CE0.c
 * function: OS_GetDTCMAddress
 * address:  0x02086CE0
 * packet:   pkt_02086CE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void OS_GetDTCMAddress(void)
{
    mrc p15, 0, r0, c9, c1, 0
    ldr r1, =0xFFFFF000
    and	r0, r0, r1
    bx	lr
}
