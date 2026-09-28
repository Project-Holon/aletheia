/*
 * function: OS_GetOwnerRtcOffset
 * address:  0x02087D08
 * packet:   pkt_02087D08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void OS_GetOwnerRtcOffset(void)
{
    ldr r1, =0x02FFFC80
    ldr	r0, [r1, #0x68]
    ldr	r1, [r1, #0x6c]
    bx	lr
}
