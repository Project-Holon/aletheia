/*
 * function: MTX_Scale22_
 * address:  0x0207AD58
 * packet:   pkt_0207AD58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * sdk:      MTX_Scale22_ (libfx.TWL.HYB.a fx_mtx22.o)
 * asm:      fixed-register stm with writeback (stmia r0!, {r1, r2}); no C spelling.
 *
 * void MTX_Scale22_(MtxFx22 *pDst, fx32 x, fx32 y)
 *
 * symbols:
 *   (none)
 */

asm void MTX_Scale22_(void)
{
    stmia r0!, {r1}
    mov r1, #0
    str r2, [r0, #8]
    mov r2, #0
    stmia r0!, {r1, r2}
    bx lr
}
