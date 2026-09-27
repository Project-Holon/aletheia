/*
 * function: INITi_CallStaticInitializers
 * address:  0x02004DA0
 * packet:   pkt_02004DA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void INITi_CallStaticInitializers(void)
{
    stmfd sp!, {lr}
    ldr r1, =0x02fe0000
    add r1, r1, #0x4000
    sub r1, r1, #0x40
    sub r1, r1, #0x40
    ldr r2, =0x00000800
    sub r1, r1, r2
    add r1, r1, #4
_loop:
    ldr r0, [r1]
    cmp r0, #0
    beq _end
    stmfd sp!, {r1}
    blx r0
    ldmfd sp!, {r1}
    mov r0, #0
    str r0, [r1], #4
    b _loop
_end:
    ldmfd sp!, {lr}
    bx lr
}
