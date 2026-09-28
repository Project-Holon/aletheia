/*
 * function: GetNotFoundAP
 * address:  0x0205D1C4
 * packet:   pkt_0205D1C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void GetNotFoundAP(void)
{
    ldrb r0, [r0, #0xb]
    mov r0, r0, lsl #28
    movs r0, r0, lsr #28
    ldreq r0, =0xFFFF3C4D
    ldrne r0, =0xFFFF3865
    bx lr
}
