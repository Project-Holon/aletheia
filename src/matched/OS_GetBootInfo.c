/*
 * function: OS_GetBootInfo
 * address:  0x02087B14
 * packet:   pkt_02087B14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void *OS_GetBootInfo(void)
{
    ldr r0, =0x02FFFC40
    bx lr
}
