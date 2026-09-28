/*
 * function: func_027312D0
 * address:  0x027312D0
 * packet:   pkt_027312D0
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void func_027312D0(void)
{
    ldr r0, =0x02FFFDFC
    ldr r0, [r0]
    ldr r0, [r0]
    mov r0, r0, lsl #0x1c
    mov r0, r0, lsr #0x1f
    cmp r0, #1
    moveq r0, #1
    movne r0, #0
    bx lr
}
