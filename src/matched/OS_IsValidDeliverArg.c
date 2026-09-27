/*
 * function: OS_IsValidDeliverArg
 * address:  0x02088150
 * packet:   pkt_02088150
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void OS_IsValidDeliverArg(void)
{
    mov	r0, #0x2000000
    ldrb	r0, [r0, #9]
    tst	r0, #2
    movne	r0, #1
    moveq	r0, #0
    bx	lr
}
