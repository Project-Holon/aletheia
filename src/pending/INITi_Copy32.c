/*
 * function: INITi_Copy32
 * address:  0x02004ED4
 * packet:   pkt_02004ED4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void INITi_Copy32(void)
{
    stmfd sp!, {r3-r11}
    bics r3, r2, #0x1f
    beq _next
    add r3, r0, r3
_loop:
    ldmia r1!, {r4, r5, r6, r7, r8, r9, r10, r11}
    stmia r0!, {r4, r5, r6, r7, r8, r9, r10, r11}
    cmp r3, r0
    bgt _loop
_next:
    tst r2, #0x10
    ldmneia r1!, {r4, r5, r6, r7}
    stmneia r0!, {r4, r5, r6, r7}
    tst r2, #8
    ldmneia r1!, {r4, r5}
    stmneia r0!, {r4, r5}
    tst r2, #4
    ldmneia r1!, {r4}
    stmneia r0!, {r4}
    ldmfd sp!, {r3-r11}
    bx lr
}
