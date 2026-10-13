/*
 * function: MIi_CpuClearFast
 * address:  0x02082AC0
 * packet:   pkt_02082AC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MIi_CpuClearFast (libmi.TWL.HYB.a mi_memory.o)
 * asm:      eight-register fixed stm block fill (stmlt r1!, {r0, r2-r8}); DWARF subprogram has no variables.
 *
 * void MIi_CpuClearFast(u32 data, void *destp, u32 size).
 */

asm void MIi_CpuClearFast(void)
{
    stmfd sp!, {r4, r5, r6, r7, r8, r9}
    add r9, r1, r2
    mov r12, r2, lsr #5
    add r12, r1, r12, lsl #5
    mov r2, r0
    mov r3, r2
    mov r4, r2
    mov r5, r2
    mov r6, r2
    mov r7, r2
    mov r8, r2
@loop32:
    cmp r1, r12
    stmltia r1!, {r0, r2, r3, r4, r5, r6, r7, r8}
    blt @loop32
@loop4:
    cmp r1, r9
    stmltia r1!, {r0}
    blt @loop4
    ldmfd sp!, {r4, r5, r6, r7, r8, r9}
    bx lr
}
