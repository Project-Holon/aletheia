/*
 * file:     fx_mtx22.c
 * unit:     yes
 * function: MTX_Scale22_, MTX_Rot22_, MTX_ScaleApply22
 * address:  0x0207AD58
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../types.h"

#include "../sdk_fx.h"

asm void MTX_Scale22_(MtxFx22 *pDst, fx32 x, fx32 y);
asm void MTX_Rot22_(MtxFx22 *dst, fx32 sin, fx32 cos);

/*
 * sdk:      MTX_Scale22_ (libfx.TWL.HYB.a fx_mtx22.o)
 * asm:      fixed-register stm with writeback (stmia r0!, {r1, r2}); no C spelling.
 *
 * void MTX_Scale22_(MtxFx22 *pDst, fx32 x, fx32 y)
 * hand-written in the original: register-passed matrix helper, one SDK line-table row per instruction
 */
asm void MTX_Scale22_(MtxFx22 *pDst, fx32 x, fx32 y)
{
    stmia r0!, {r1}
    mov r1, #0
    str r2, [r0, #8]
    mov r2, #0
    stmia r0!, {r1, r2}
    bx lr
}

/* hand-written in the original: fx_mtx22.o (libfx) has one .debug_line row per instruction for MTX_Rot22_ (lines 65-69, 71), the neg on its own line, no DW_TAG_variable; the C ScaleApply22 beside it interleaves lines */
asm void MTX_Rot22_(MtxFx22 *dst, fx32 sin, fx32 cos)
{
    str r2, [r0]
    str r1, [r0, #4]
    neg r1, r1
    str r1, [r0, #8]
    str r2, [r0, #0xc]
    bx lr
}

#pragma thumb off
typedef union {
    struct {
        fx32 _00, _01;
        fx32 _10, _11;
    };
    fx32 m[2][2];
    fx32 a[4];
} MtxFx22b;

void MTX_ScaleApply22(const MtxFx22b *pSrc, MtxFx22b *pDst, fx32 x, fx32 y)
{
    pDst->_00 = (fx32)(((fx64)x * pSrc->_00) >> 12);
    pDst->_01 = (fx32)(((fx64)x * pSrc->_01) >> 12);
    pDst->_10 = (fx32)(((fx64)y * pSrc->_10) >> 12);
    pDst->_11 = (fx32)(((fx64)y * pSrc->_11) >> 12);
}

#pragma thumb reset
