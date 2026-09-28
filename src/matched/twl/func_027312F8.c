/*
 * function: func_027312F8
 * address:  0x027312F8
 * packet:   pkt_027312F8
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void func_027312F8(void)
{
    ldr r0, =0x02FFFD68
    ldrb r0, [r0, #4]
    mov r0, r0, lsl #0x1f
    mov r0, r0, lsr #0x1f
    cmp r0, #1
    moveq r0, #1
    movne r0, #0
    bx lr
}
