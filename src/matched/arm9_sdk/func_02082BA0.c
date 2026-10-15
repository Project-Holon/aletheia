/*
 * function: MI_Copy64B
 * address:  0x02082BA0
 * packet:   pkt_02082BA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MI_Copy64B (libmi.TWL.HYB.a mi_memory.o)
 * asm:      fixed-register ldm/stm block copy (r2, r3, r12, then r0 reused as a fourth data register); the DWARF subprogram has no DW_TAG_variable children.
 *
 * symbols:
 *   (none)
 */

asm void MI_Copy64B(void *pSrc, void *pDest)
{
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0, {r0, r2, r3, r12}
    stmia r1!, {r0, r2, r3, r12}
    bx lr
}
