/*
 * function: OS_InitEvent
 * address:  0x020882DC
 * packet:   pkt_020882DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void OS_InitEvent(void)
{
    mov	r1, #0
    str	r1, [r0, #8]
    str	r1, [r0, #4]
    str	r1, [r0]
    bx	lr
}
