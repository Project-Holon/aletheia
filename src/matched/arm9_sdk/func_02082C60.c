/*
 * function: MI_CpuFill
 * address:  0x02082C60
 * packet:   pkt_02082C60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MI_CpuFill (libmi.TWL.HYB.a mi_memory.o)
 * asm:      computed jump into a strb run (add pc, pc, r3, lsl #2) and a mid-body push around an eight-register stm; DWARF subprogram has no variables.
 *
 * void MI_CpuFill(void *dstp, u8 data, u32 size).
 */

asm void MI_CpuFill(void)
{
    cmp r2, #0
    bxeq lr
    cmp r2, #8
    bgt @_large
    rsb r3, r2, #8
    add pc, pc, r3, lsl #2
    mov r0, r0
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    bx lr
@_large:
    orr r1, r1, r1, lsl #8
    orr r1, r1, r1, lsl #16
    tst r0, #1
    subne r2, r2, #1
    strneb r1, [r0], #1
    tst r0, #2
    subne r2, r2, #2
    strneh r1, [r0], #2
    tst r0, #4
    subne r2, r2, #4
    strne r1, [r0], #4
    cmp r2, #32
    blt @_words
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10}
    mov r4, r1
    mov r5, r1
    mov r6, r1
    mov r7, r1
    mov r8, r1
    mov r9, r1
    mov r10, r1
    subs r2, r2, #32
@_loop32:
    stmgeia r0!, {r1, r4, r5, r6, r7, r8, r9, r10}
    subges r2, r2, #32
    bge @_loop32
    add r2, r2, #32
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10}
@_words:
    cmp r2, #4
    blt @_bytes
    subs r2, r2, #4
@_loop4:
    strge r1, [r0], #4
    subs r2, r2, #4
    bge @_loop4
    add r2, r2, #4
@_bytes:
    subs r2, r2, #1
    strgeb r1, [r0], #1
    subges r2, r2, #1
    strgeb r1, [r0], #1
    subges r2, r2, #1
    strgeb r1, [r0], #1
    bx lr
}
