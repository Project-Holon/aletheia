/*
 * function: func_02082B0C
 * address:  0x02082B0C
 * packet:   pkt_02082B0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      MIi_CpuCopyFast (libmi.TWL.HYB.a mi_memory.o)
 * asm:      eight-register fixed ldm/stm block copy (ldmlt r0!, {r2-r9}); DWARF subprogram has no variables.
 *
 * void MIi_CpuCopyFast(const void *srcp, void *destp, u32 size).
 */

asm void func_02082B0C(void)
{
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10}
    add r10, r1, r2
    mov r12, r2, lsr #5
    add r12, r1, r12, lsl #5
@loop32:
    cmp r1, r12
    ldmltia r0!, {r2, r3, r4, r5, r6, r7, r8, r9}
    stmltia r1!, {r2, r3, r4, r5, r6, r7, r8, r9}
    blt @loop32
@loop4:
    cmp r1, r10
    ldmltia r0!, {r2}
    stmltia r1!, {r2}
    blt @loop4
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10}
    bx lr
}
