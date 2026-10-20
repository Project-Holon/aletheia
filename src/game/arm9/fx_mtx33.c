/*
 * file:     fx_mtx33.c
 * unit:     yes
 * function: MTX_Identity33_, MTX_Copy33To44_, MTX_Scale33_, MTX_ScaleApply33, MTX_RotX33_, MTX_RotY33_, MTX_RotZ33_, MTX_RotAxis33, MTX_Inverse33, MTX_Concat33, MTX_MultVec33
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
#include "../types.h"
#include "../sdk_fx.h"

asm void MTX_Identity33_(MtxFx33 *pDst);
asm void MTX_Copy33To44_(const MtxFx33 *pSrc, MtxFx44 *pDst);

/*
 * sdk:      MTX_Identity33_ (libfx.TWL.HYB.a fx_mtx33.o)
 * asm:      fixed-register stm with writeback (stmia r0!, {r2, r3}); no C spelling.
 *
 * void MTX_Identity33_(MtxFx33 *pDst)
 * hand-written in the original: register-passed matrix helper, one SDK line-table row per instruction
 */
asm void MTX_Identity33_(MtxFx33 *pDst)
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
 * hand-written in the original: register-passed matrix helper, one SDK line-table row per instruction
 */
asm void MTX_Copy33To44_(const MtxFx33 *pSrc, MtxFx44 *pDst)
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

#pragma thumb on

/* hand-written in the original: register-passed matrix helper, one SDK line-table row per instruction */
asm void MTX_Scale33_(void)
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

#pragma thumb reset

void MTX_ScaleApply33(const MtxFx33 *pSrc, MtxFx33 *pDst, fx32 x, fx32 y, fx32 z)
{
    pDst->_00 = (fx32)(((fx64)x * pSrc->_00) >> 12);
    pDst->_01 = (fx32)(((fx64)x * pSrc->_01) >> 12);
    pDst->_02 = (fx32)(((fx64)x * pSrc->_02) >> 12);
    pDst->_10 = (fx32)(((fx64)y * pSrc->_10) >> 12);
    pDst->_11 = (fx32)(((fx64)y * pSrc->_11) >> 12);
    pDst->_12 = (fx32)(((fx64)y * pSrc->_12) >> 12);
    pDst->_20 = (fx32)(((fx64)z * pSrc->_20) >> 12);
    pDst->_21 = (fx32)(((fx64)z * pSrc->_21) >> 12);
    pDst->_22 = (fx32)(((fx64)z * pSrc->_22) >> 12);
}

#pragma thumb on

asm void MTX_RotX33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal);
asm void MTX_RotY33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal);
asm void MTX_RotZ33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal);

/* hand-written in the original: fx_mtx33.o (libfx) has one .debug_line row per instruction for MTX_RotX33_ (lines 151-163, 165), mov/lsl of 0x1000 on two lines, no DW_TAG_variable; the C ScaleApply33 beside it interleaves lines */
asm void MTX_RotX33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal)
{
    mov r3, #1
    lsl r3, r3, #12
    str r3, [r0]
    mov r3, #0
    str r3, [r0, #4]
    str r3, [r0, #8]
    str r3, [r0, #0xc]
    str r2, [r0, #0x10]
    str r1, [r0, #0x14]
    str r3, [r0, #0x18]
    neg r1, r1
    str r1, [r0, #0x1c]
    str r2, [r0, #0x20]
    bx lr
}

/* hand-written in the original: fx_mtx33.o (libfx) has one .debug_line row per instruction for MTX_RotY33_ (lines 172-184, 186), mov/lsl of 0x1000 on two lines, no DW_TAG_variable; the C ScaleApply33 beside it interleaves lines */
asm void MTX_RotY33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal)
{
    str r2, [r0]
    str r2, [r0, #0x20]
    mov r3, #0
    str r3, [r0, #4]
    str r3, [r0, #0xc]
    str r3, [r0, #0x14]
    str r3, [r0, #0x1c]
    neg r2, r1
    mov r3, #1
    lsl r3, r3, #12
    str r1, [r0, #0x18]
    str r2, [r0, #8]
    str r3, [r0, #0x10]
    bx lr
}

/* hand-written in the original: register-passed matrix helper, one SDK line-table row per instruction */
asm void MTX_RotZ33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal)
{
    stmia r0!, {r2}
    mov r3, #0
    stmia r0!, {r1, r3}
    neg r1, r1
    stmia r0!, {r1, r2}
    mov r1, #1
    lsl r1, r1, #12
    str r3, [r0]
    str r3, [r0, #4]
    str r3, [r0, #8]
    str r1, [r0, #0xc]
    bx lr
}

#pragma thumb reset

#include "fx_cp.h"
#include "mi_memory.h"
void MTX_RotAxis33(MtxFx33 *pDst, const VecFx32 *vec, fx32 sinVal, fx32 cosVal);
int MTX_Inverse33(const MtxFx33 *pSrc, MtxFx33 *pDst);
void MTX_Concat33(const MtxFx33 *a, const MtxFx33 *b, MtxFx33 *ab);
void MTX_MultVec33(const VecFx32 *vec, const MtxFx33 *m, VecFx32 *dst);

/*
 * sdk:      MTX_RotAxis33 (libfx.TWL.HYB.a fx_mtx33.o)
 */
void MTX_RotAxis33(MtxFx33 *pDst, const VecFx32 *vec, fx32 sinVal, fx32 cosVal)
{
    fx64 t, ss, xx, yy, zz;
    fx32 t01;
    fx32 s2;

    t = (fx64)(0x1000 - cosVal);
    ss = sinVal;
    xx = vec->x;
    yy = vec->y;
    zz = vec->z;

    t01 = (fx32)((xx * xx * t) >> 24);
    pDst->_00 = t01 + cosVal;
    t01 = (fx32)((yy * yy * t) >> 24);
    pDst->_11 = t01 + cosVal;
    t01 = (fx32)((zz * zz * t) >> 24);
    pDst->_22 = t01 + cosVal;

    t01 = (fx32)((t * xx * yy) >> 24);
    s2 = (fx32)((ss * zz) >> 12);
    pDst->_01 = t01 + s2;
    pDst->_10 = t01 - s2;

    t01 = (fx32)((t * xx * zz) >> 24);
    s2 = (fx32)((ss * yy) >> 12);
    pDst->_02 = t01 - s2;
    pDst->_20 = t01 + s2;

    t01 = (fx32)((t * yy * zz) >> 24);
    s2 = (fx32)((ss * xx) >> 12);
    pDst->_12 = t01 + s2;
    pDst->_21 = t01 - s2;
}

#define FX32_SHIFT 12

#define FX32_ONE   4096

int MTX_Inverse33(const MtxFx33 *pSrc, MtxFx33 *pDst)
{
    MtxFx33 tmp;
    MtxFx33 *p;
    fx32 det;
    fx32 cofactor01, cofactor02, cofactor11, cofactor12;

    if (pSrc == pDst) {
        p = &tmp;
    } else {
        p = pDst;
    }

    {
        fx32 det00, det10, det20;

        det00 = (fx32)(((fx64)pSrc->_11 * pSrc->_22 - (fx64)pSrc->_12 * pSrc->_21 + (fx64)(FX32_ONE >> 1)) >> FX32_SHIFT);
        det10 = (fx32)(((fx64)pSrc->_10 * pSrc->_22 - (fx64)pSrc->_12 * pSrc->_20 + (fx64)(FX32_ONE >> 1)) >> FX32_SHIFT);
        det20 = (fx32)(((fx64)pSrc->_10 * pSrc->_21 - (fx64)pSrc->_11 * pSrc->_20 + (fx64)(FX32_ONE >> 1)) >> FX32_SHIFT);

        det = (fx32)(((fx64)pSrc->_00 * det00 - (fx64)pSrc->_01 * det10 + (fx64)pSrc->_02 * det20 + (fx64)(FX32_ONE >> 1)) >> FX32_SHIFT);

        if (det == 0) {
            return -1;
        }

        FX_InvAsync(det);

        cofactor01 = (fx32)(((fx64)pSrc->_01 * pSrc->_22 - (fx64)pSrc->_21 * pSrc->_02) >> FX32_SHIFT);
        cofactor02 = (fx32)(((fx64)pSrc->_01 * pSrc->_12 - (fx64)pSrc->_11 * pSrc->_02) >> FX32_SHIFT);
        cofactor11 = (fx32)(((fx64)pSrc->_00 * pSrc->_22 - (fx64)pSrc->_20 * pSrc->_02) >> FX32_SHIFT);
        cofactor12 = (fx32)(((fx64)pSrc->_00 * pSrc->_12 - (fx64)pSrc->_10 * pSrc->_02) >> FX32_SHIFT);

        det = FX_GetDivResult();
        p->_00 = (fx32)(((fx64)det * det00) >> FX32_SHIFT);
        p->_01 = -(fx32)(((fx64)det * cofactor01) >> FX32_SHIFT);
        p->_02 = (fx32)(((fx64)det * cofactor02) >> FX32_SHIFT);

        p->_10 = -(fx32)(((fx64)det * det10) >> FX32_SHIFT);
        p->_11 = (fx32)(((fx64)det * cofactor11) >> FX32_SHIFT);
        p->_12 = -(fx32)(((fx64)det * cofactor12) >> FX32_SHIFT);

        p->_20 = (fx32)(((fx64)det * det20) >> FX32_SHIFT);
    }
    p->_21 = -(fx32)(((fx64)det * (fx32)(((fx64)pSrc->_00 * pSrc->_21 - (fx64)pSrc->_20 * pSrc->_01) >> FX32_SHIFT)) >> FX32_SHIFT);
    p->_22 = (fx32)(((fx64)det * (fx32)(((fx64)pSrc->_00 * pSrc->_11 - (fx64)pSrc->_10 * pSrc->_01) >> FX32_SHIFT)) >> FX32_SHIFT);

    if (p == &tmp) {
        MI_Copy36B(&tmp, pDst);
    }
    return 0;
}

#define FX32_SHIFT 12

void MTX_Concat33(const MtxFx33 *a, const MtxFx33 *b, MtxFx33 *ab)
{
    MtxFx33 tmp;
    MtxFx33 *p;
    fx32 x, y, z;
    fx32 xx, yy, zz;

    if (ab == b) {
        p = &tmp;
    } else {
        p = ab;
    }

    x = a->_00;
    y = a->_01;
    z = a->_02;

    p->_00 = (fx32)(((fx64)x * b->_00 + (fx64)y * b->_10 + (fx64)z * b->_20) >> FX32_SHIFT);
    p->_01 = (fx32)(((fx64)x * b->_01 + (fx64)y * b->_11 + (fx64)z * b->_21) >> FX32_SHIFT);

    xx = b->_02;
    yy = b->_12;
    zz = b->_22;

    p->_02 = (fx32)(((fx64)x * xx + (fx64)y * yy + (fx64)z * zz) >> FX32_SHIFT);

    x = a->_10;
    y = a->_11;
    z = a->_12;

    p->_12 = (fx32)(((fx64)x * xx + (fx64)y * yy + (fx64)z * zz) >> FX32_SHIFT);
    p->_11 = (fx32)(((fx64)x * b->_01 + (fx64)y * b->_11 + (fx64)z * b->_21) >> FX32_SHIFT);

    xx = b->_00;
    yy = b->_10;
    zz = b->_20;

    p->_10 = (fx32)(((fx64)x * xx + (fx64)y * yy + (fx64)z * zz) >> FX32_SHIFT);

    x = a->_20;
    y = a->_21;
    z = a->_22;

    p->_20 = (fx32)(((fx64)x * xx + (fx64)y * yy + (fx64)z * zz) >> FX32_SHIFT);
    p->_21 = (fx32)(((fx64)x * b->_01 + (fx64)y * b->_11 + (fx64)z * b->_21) >> FX32_SHIFT);

    xx = b->_02;
    yy = b->_12;
    zz = b->_22;

    p->_22 = (fx32)(((fx64)x * xx + (fx64)y * yy + (fx64)z * zz) >> FX32_SHIFT);

    if (p == &tmp) {
        *ab = tmp;
    }
}

/*
 * sdk:      MTX_MultVec33 (libfx.TWL.HYB.a fx_mtx33.o)
 */
void MTX_MultVec33(const VecFx32 *vec, const MtxFx33 *m, VecFx32 *dst)
{
    fx32 x = vec->x;
    fx32 y = vec->y;
    fx32 z = vec->z;

    dst->x = (fx32)(((fx64)x * m->_00 + (fx64)y * m->_10 + (fx64)z * m->_20) >> 12);
    dst->y = (fx32)(((fx64)x * m->_01 + (fx64)y * m->_11 + (fx64)z * m->_21) >> 12);
    dst->z = (fx32)(((fx64)x * m->_02 + (fx64)y * m->_12 + (fx64)z * m->_22) >> 12);
}
