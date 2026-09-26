/*
 * function: func_0272FC90
 * address:  0x0272FC90
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm unsigned int func_0272FC90(int ch)
{
    mov r1, #0x1c
    mul r1, r0, r1
    add r0, r1, #0x4000000
    add r0, r0, #0x4000
    ldr r0, [r0, #0x11c]
    and r0, r0, #0x80000000
    mov r0, r0, lsr #0x1f
    bx lr
}
