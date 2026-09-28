/*
 * function: INITi_IsRunOnTwl
 * address:  0x02004EB4
 * packet:   pkt_02004EB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void INITi_IsRunOnTwl(void)
{
    ldr r0, =0x04004000
    ldrb r0, [r0]
    and r0, r0, #3
    cmp r0, #1
    moveq r0, #1
    movne r0, #0
    bx lr
}
