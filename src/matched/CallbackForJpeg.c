/*
 * function: CallbackForJpeg
 * address:  0x02008500
 * packet:   pkt_02008500
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

asm void CallbackForJpeg(void)
{
    mov r2, r0
    mov r0, r1
    ldr r3, =0x02045924
    mov r1, r2
    bx r3
}
