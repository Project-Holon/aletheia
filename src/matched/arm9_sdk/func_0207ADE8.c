/*
 * function: func_0207ADE8
 * address:  0x0207ADE8
 * packet:   pkt_0207ADE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      MTX_Copy33To44_ (libfx.TWL.HYB.a fx_mtx33.o)
 * asm:      fixed-register ldm/stm block copy with writeback (ldmia r0!, stmia r1!); no C spelling.
 *
 * void MTX_Copy33To44_(const MtxFx33 *pSrc, MtxFx44 *pDst)
 *
 * symbols:
 *   (none)
 */

asm void func_0207ADE8(void)
{
    stmfd sp!, {r4}
    mov r12, #0
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, r12}
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, r12}
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, r12}
    mov r2, #0x1000
    str r12, [r1]
    str r12, [r1, #4]
    str r12, [r1, #8]
    str r2, [r1, #0xc]
    ldmfd sp!, {r4}
    bx lr
}
