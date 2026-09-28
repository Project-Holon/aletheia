/*
 * function: func_0207ADC4
 * address:  0x0207ADC4
 * packet:   pkt_0207ADC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MTX_Identity33_ (libfx.TWL.HYB.a fx_mtx33.o)
 * asm:      fixed-register stm with writeback (stmia r0!, {r2, r3}); no C spelling.
 *
 * void MTX_Identity33_(MtxFx33 *pDst)
 *
 * symbols:
 *   (none)
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
