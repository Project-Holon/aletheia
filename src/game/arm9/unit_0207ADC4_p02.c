/*
 * function: func_0207AE24
 * address:  0x0207AE24
 * packet:   pkt_0207AE24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * sdk:      MTX_Scale33_ (libfx.TWL.HYB.a fx_mtx33.o)
 * asm:      fixed-register stm with writeback (stmia r0!, {r1, r2, r3}); no C spelling.
 *
 * void MTX_Scale33_(MtxFx33 *pDst, fx32 x, fx32 y, fx32 z)
 *
 * symbols:
 *   (none)
 */

asm void func_0207AE24(void)
{
    stmia r0!, {r1}
    mov r1, #0
    str r3, [r0, #0x1c]
    mov r3, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    mov r2, #0
    stmia r0!, {r1, r3}
    bx lr
}
