/*
 * file:     unit_0207ADC4_p01.c
 * unit:     yes
 * function: func_0207ADC4, func_0207ADE8
 * address:  0x0207ADC4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
asm void func_0207ADC4(void);
asm void func_0207ADE8(void);

/*
 * sdk:      MTX_Identity33_ (libfx.TWL.HYB.a fx_mtx33.o)
 * asm:      fixed-register stm with writeback (stmia r0!, {r2, r3}); no C spelling.
 *
 * void MTX_Identity33_(MtxFx33 *pDst)
 */
asm void func_0207ADC4(void)
{
    mov r2, #0x1000
    str r2, [r0, #0x20]
    mov r3, #0
    stmia r0!, {r2, r3}
    mov r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r3}
    bx lr
}

/*
 * sdk:      MTX_Copy33To44_ (libfx.TWL.HYB.a fx_mtx33.o)
 * asm:      fixed-register ldm/stm block copy with writeback (ldmia r0!, stmia r1!); no C spelling.
 *
 * void MTX_Copy33To44_(const MtxFx33 *pSrc, MtxFx44 *pDst)
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
