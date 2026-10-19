/*
 * file:     fx_mtx44.c
 * unit:     yes
 * function: MTX_Identity44_, MTX_Copy44To43_, MTX_Concat44, MTX_FrustumW, MTX_PerspectiveW, MTX_OrthoW
 * address:  0x0207BDB4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FX_InvAsync                    0x0207C8A0  arm
 *   FX_GetDivResultFx64c           0x0207C848  arm
 *   _ll_sdiv                       0x0209BE5C  arm
 *   FX_Div                         0x0207C768  arm
 *   FX_GetDivResult                0x0207C86C  arm
 */
#include "../types.h"

typedef long long fx64c;

#include "../sdk_fx.h"

void FX_InvAsync(fx32 denom);
u64 FX_GetDivResultFx64c(void);
u32 FX_Div(u32 numer, u32 denom);
u32 FX_GetDivResult(void);
asm void MTX_Identity44_(MtxFx44 *pDst);
asm void MTX_Copy44To43_(MtxFx44 *pSrc, MtxFx43 *pDst);
void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);
void MTX_FrustumW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
void MTX_PerspectiveW(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);
void MTX_OrthoW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx);

/*
 * sdk:      MTX_Identity44_ (fx_mtx44.o)
 *
 * asm:      fixed-register stm block (stmia r0!, {r1, r2, r3} runs) has no C spelling
 * hand-written in the original: register-passed matrix helper, one SDK line-table row per instruction
 */
asm void MTX_Identity44_(MtxFx44 *pDst)
{
    mov r2, #0x1000
    mov r3, #0
    stmia r0!, {r2, r3}
    mov r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2}
    bx lr
}

/*
 * sdk:      MTX_Copy44To43_ (fx_mtx44.o)
 *
 * asm:      fixed-register ldm/stm block copy (ldmia r0!/stmia r1!, {r2, r3, r12}) has no C spelling
 * hand-written in the original: register-passed matrix helper, one SDK line-table row per instruction
 */
asm void MTX_Copy44To43_(MtxFx44 *pSrc, MtxFx43 *pDst)
{
    ldmia r0!, {r2, r3, r12}
    add r0, r0, #4
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    add r0, r0, #4
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    add r0, r0, #4
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    add r0, r0, #4
    stmia r1!, {r2, r3, r12}
    bx lr
}

#define FX32_SHIFT 12

void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab)
{
    MtxFx44 tmp;
    MtxFx44 *p;

    register fx32 x, y, z, w;
    register fx32 xx, yy, zz, ww;

    if (ab == b)
    {
        p = &tmp;
    }
    else
    {
        p = ab;
    }

    x = a->_00;
    y = a->_01;
    z = a->_02;
    w = a->_03;

    p->_00 =
        (fx32)(((fx64)x * b->_00 + (fx64)y * b->_10 + (fx64)z * b->_20 +
                (fx64)w * b->_30) >> FX32_SHIFT);
    p->_01 =
        (fx32)(((fx64)x * b->_01 + (fx64)y * b->_11 + (fx64)z * b->_21 +
                (fx64)w * b->_31) >> FX32_SHIFT);
    p->_03 =
        (fx32)(((fx64)x * b->_03 + (fx64)y * b->_13 + (fx64)z * b->_23 +
                (fx64)w * b->_33) >> FX32_SHIFT);

    xx = b->_02;
    yy = b->_12;
    zz = b->_22;
    ww = b->_32;

    p->_02 = (fx32)(((fx64)x * xx + (fx64)y * yy + (fx64)z * zz + (fx64)w * ww) >> FX32_SHIFT);

    x = a->_10;
    y = a->_11;
    z = a->_12;
    w = a->_13;

    p->_12 = (fx32)(((fx64)x * xx + (fx64)y * yy + (fx64)z * zz + (fx64)w * ww) >> FX32_SHIFT);
    p->_11 =
        (fx32)(((fx64)x * b->_01 + (fx64)y * b->_11 + (fx64)z * b->_21 +
                (fx64)w * b->_31) >> FX32_SHIFT);
    p->_13 =
        (fx32)(((fx64)x * b->_03 + (fx64)y * b->_13 + (fx64)z * b->_23 +
                (fx64)w * b->_33) >> FX32_SHIFT);

    xx = b->_00;
    yy = b->_10;
    zz = b->_20;
    ww = b->_30;

    p->_10 = (fx32)(((fx64)x * xx + (fx64)y * yy + (fx64)z * zz + (fx64)w * ww) >> FX32_SHIFT);

    x = a->_20;
    y = a->_21;
    z = a->_22;
    w = a->_23;

    p->_20 = (fx32)(((fx64)x * xx + (fx64)y * yy + (fx64)z * zz + (fx64)w * ww) >> FX32_SHIFT);
    p->_21 =
        (fx32)(((fx64)x * b->_01 + (fx64)y * b->_11 + (fx64)z * b->_21 +
                (fx64)w * b->_31) >> FX32_SHIFT);
    p->_23 =
        (fx32)(((fx64)x * b->_03 + (fx64)y * b->_13 + (fx64)z * b->_23 +
                (fx64)w * b->_33) >> FX32_SHIFT);

    xx = b->_02;
    yy = b->_12;
    zz = b->_22;
    ww = b->_32;

    p->_22 = (fx32)(((fx64)x * xx + (fx64)y * yy + (fx64)z * zz + (fx64)w * ww) >> FX32_SHIFT);

    x = a->_30;
    y = a->_31;
    z = a->_32;
    w = a->_33;

    p->_32 = (fx32)(((fx64)x * xx + (fx64)y * yy + (fx64)z * zz + (fx64)w * ww) >> FX32_SHIFT);
    p->_31 =
        (fx32)(((fx64)x * b->_01 + (fx64)y * b->_11 + (fx64)z * b->_21 +
                (fx64)w * b->_31) >> FX32_SHIFT);
    p->_30 =
        (fx32)(((fx64)x * b->_00 + (fx64)y * b->_10 + (fx64)z * b->_20 +
                (fx64)w * b->_30) >> FX32_SHIFT);
    p->_33 =
        (fx32)(((fx64)x * b->_03 + (fx64)y * b->_13 + (fx64)z * b->_23 +
                (fx64)w * b->_33) >> FX32_SHIFT);

    if (p == &tmp)
    {
        *ab = tmp;
    }
}

#define FX32_ONE 4096

#define REG_DIV_NUMER (*(u64 *)0x04000290)

#define REG_DIV_DENOM (*(u64 *)0x04000298)

static inline void FX_InvAsyncImm(fx32 denom)
{
    REG_DIV_NUMER = (fx64)FX32_ONE << 32;
    REG_DIV_DENOM = (u32)denom;
}

static inline fx32 FX_Mul(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> 12);
}

static inline fx32 FX_Mul32x64c(fx32 v32, fx64c v64c)
{
    return (fx32)((v64c * v32 + 0x80000000LL) >> 32);
}

void MTX_FrustumW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx)
{
    fx64c inv1;
    fx64c inv2;
    fx32 dblN;

    FX_InvAsync(r - l);

    mtx->_01 = 0;
    mtx->_02 = 0;
    mtx->_03 = 0;
    mtx->_10 = 0;
    mtx->_12 = 0;
    mtx->_13 = 0;
    mtx->_23 = -scaleW;
    mtx->_30 = 0;
    mtx->_31 = 0;
    mtx->_33 = 0;

    dblN = n << 1;

    inv1 = FX_GetDivResultFx64c();
    FX_InvAsyncImm(t - b);
    if (scaleW != FX32_ONE) {
        inv1 = (inv1 * scaleW) / FX32_ONE;
    }
    mtx->_00 = FX_Mul32x64c(dblN, inv1);

    inv2 = FX_GetDivResultFx64c();
    FX_InvAsyncImm(n - f);
    if (scaleW != FX32_ONE) {
        inv2 = (inv2 * scaleW) / FX32_ONE;
    }
    mtx->_11 = FX_Mul32x64c(dblN, inv2);
    mtx->_20 = FX_Mul32x64c(r + l, inv1);
    mtx->_21 = FX_Mul32x64c(t + b, inv2);

    inv1 = FX_GetDivResultFx64c();
    if (scaleW != FX32_ONE) {
        inv1 = (inv1 * scaleW) / FX32_ONE;
    }
    mtx->_22 = FX_Mul32x64c(f + n, inv1);
    mtx->_32 = FX_Mul32x64c(FX_Mul(dblN, f), inv1);
}

static inline void FX_DivAsyncImm(fx32 numer, fx32 denom)
{
    REG_DIV_NUMER = (fx64)numer << 32;
    REG_DIV_DENOM = (u32)denom;
}

void MTX_PerspectiveW(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx)
{
    fx32 one_tan;
    fx64c t;

    one_tan = FX_Div(fovyCos, fovySin);
    FX_InvAsyncImm(n - f);
    if (scaleW != FX32_ONE) {
        one_tan = (one_tan * scaleW) / FX32_ONE;
    }

    mtx->_01 = 0;
    mtx->_02 = 0;
    mtx->_03 = 0;
    mtx->_10 = 0;
    mtx->_11 = one_tan;
    mtx->_12 = 0;
    mtx->_13 = 0;
    mtx->_20 = 0;
    mtx->_21 = 0;
    mtx->_23 = -scaleW;
    mtx->_30 = 0;
    mtx->_31 = 0;
    mtx->_33 = 0;

    t = FX_GetDivResultFx64c();
    FX_DivAsyncImm(one_tan, aspect);
    if (scaleW != FX32_ONE) {
        t = (t * scaleW) / FX32_ONE;
    }
    mtx->_22 = FX_Mul32x64c(f + n, t);
    mtx->_32 = FX_Mul32x64c(FX_Mul(n << 1, f), t);

    mtx->_00 = FX_GetDivResult();
}

void MTX_OrthoW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx)
{
    fx64c inv1;
    fx64c inv2;
    fx64c inv3;

    FX_InvAsync(r - l);

    mtx->_01 = 0;
    mtx->_02 = 0;
    mtx->_03 = 0;
    mtx->_10 = 0;
    mtx->_12 = 0;
    mtx->_13 = 0;
    mtx->_20 = 0;
    mtx->_21 = 0;
    mtx->_23 = 0;
    mtx->_33 = scaleW;

    inv1 = FX_GetDivResultFx64c();
    FX_InvAsyncImm(t - b);
    if (scaleW != FX32_ONE) {
        inv1 = (inv1 * scaleW) / FX32_ONE;
    }
    mtx->_00 = FX_Mul32x64c(FX32_ONE * 2, inv1);

    inv2 = FX_GetDivResultFx64c();
    FX_InvAsyncImm(n - f);
    if (scaleW != FX32_ONE) {
        inv2 = (inv2 * scaleW) / FX32_ONE;
    }
    mtx->_11 = FX_Mul32x64c(FX32_ONE * 2, inv2);

    inv3 = FX_GetDivResultFx64c();
    if (scaleW != FX32_ONE) {
        inv3 = (inv3 * scaleW) / FX32_ONE;
    }
    mtx->_22 = FX_Mul32x64c(FX32_ONE * 2, inv3);
    mtx->_30 = FX_Mul32x64c(-(r + l), inv1);
    mtx->_31 = FX_Mul32x64c(-(t + b), inv2);
    mtx->_32 = FX_Mul32x64c(f + n, inv3);
}
