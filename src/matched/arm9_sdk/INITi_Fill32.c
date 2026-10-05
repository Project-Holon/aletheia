/*
 * function: INITi_Fill32
 * address:  0x02004F20
 * packet:   pkt_02004F20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 */

asm void INITi_Fill32(void)
{
    stmfd sp!, {r3-r11}
    mov r4, r1
    mov r5, r1
    mov r6, r1
    mov r7, r1
    mov r8, r1
    mov r9, r1
    mov r10, r1
    mov r11, r1
    bics r3, r2, #0x1f
    beq _next
    add r3, r0, r3
_loop:
    stmia r0!, {r4, r5, r6, r7, r8, r9, r10, r11}
    cmp r3, r0
    bgt _loop
_next:
    tst r2, #0x10
    stmneia r0!, {r4, r5, r6, r7}
    tst r2, #8
    stmneia r0!, {r4, r5}
    tst r2, #4
    stmneia r0!, {r4}
    ldmfd sp!, {r3-r11}
    bx lr
}
