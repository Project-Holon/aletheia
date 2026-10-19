/*
 * file:     fx_mtx43.c
 * unit:     yes
 * function: MTX_Identity43_, MTX_Copy43To44_, MTX_Scale43_, MTX_ScaleApply43, MTX_RotY43_, MTX_RotAxis43, MTX_Inverse43, MTX_Concat43, MTX_MultVec43, MTX_LookAt
 * address:  0x0207B598
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
 *   MTX_RotAxis33  0x0207AF50  arm
 */
typedef long fx32;
typedef long long fx64;
typedef union {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
        fx32 _30, _31, _32;
    };
    fx32 m[4][3];
    fx32 a[12];
} MtxFx43;
typedef struct {
    fx32 x, y, z;
} VecFx32;
typedef union {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
    };
    fx32 m[3][3];
    fx32 a[9];
} MtxFx33;

asm void MTX_Identity43_(void);
asm void MTX_Copy43To44_(void);

/*
 * sdk:      MTX_Identity43_ (libfx.TWL.HYB.a fx_mtx43.o)
 * asm:      fixed-register stm with writeback (stmia r0!, {r2, r3}); no C spelling.
 * hand-written in the original: register-passed matrix helper, one SDK line-table row per instruction
 */
asm void MTX_Identity43_(void)
{
    mov r2, #0x1000
    mov r3, #0
    stmia r0!, {r2, r3}
    mov r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r3}
    bx lr
}

/*
 * sdk:      MTX_Copy43To44_ (libfx.TWL.HYB.a fx_mtx43.o)
 * asm:      fixed-register ldm/stm block copy with writeback (ldmia r0!, stmia r1!); no C spelling.
 * hand-written in the original: register-passed matrix helper, one SDK line-table row per instruction
 */
asm void MTX_Copy43To44_(void)
{
    stmfd sp!, {r4}
    mov r12, #0
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, r12}
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, r12}
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, r12}
    mov r12, #0x1000
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, r12}
    ldmfd sp!, {r4}
    bx lr
}

#pragma thumb on

/* hand-written in the original: register-passed matrix helper, one SDK line-table row per instruction */
asm void MTX_Scale43_(void)
{
    stmia r0!, {r1}
    mov r1, #0
    str r3, [r0, #0x1c]
    mov r3, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    mov r2, #0
    stmia r0!, {r1, r3}
    add r0, #4
    stmia r0!, {r1, r2, r3}
    bx lr
}

#pragma thumb reset

extern void MTX_ScaleApply33(const MtxFx33 *pSrc, MtxFx33 *pDst, fx32 x, fx32 y, fx32 z);

void MTX_ScaleApply43(const MtxFx43 *pSrc, MtxFx43 *pDst, fx32 x, fx32 y, fx32 z)
{
    MTX_ScaleApply33((const MtxFx33 *)pSrc, (MtxFx33 *)pDst, x, y, z);
    pDst->_30 = pSrc->_30;
    pDst->_31 = pSrc->_31;
    pDst->_32 = pSrc->_32;
}

#pragma thumb on

/* hand-written in the original: register-passed matrix helper, one SDK line-table row per instruction */
asm void MTX_RotY43_(void)
{
    str r1, [r0, #0x18]
    mov r3, #0
    stmia r0!, {r2, r3}
    neg r1, r1
    stmia r0!, {r1, r3}
    mov r1, #1
    lsl r1, r1, #0xc
    stmia r0!, {r1, r3}
    add r0, #4
    mov r1, #0
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    bx lr
}

#pragma thumb reset

extern void MTX_RotAxis33(void *m, void *v);
void FX_InvAsync(fx32 denom);
fx32 FX_GetDivResult(void);
void MI_Copy48B(const void *pSrc, void *pDest);
extern void VEC_Normalize(const VecFx32 *pSrc, VecFx32 *pDst);
extern void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
extern fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b);
void MTX_RotAxis43(void *m, void *v);
int MTX_Inverse43(const MtxFx43 *pSrc, MtxFx43 *pDst);
void MTX_Concat43(const MtxFx43 *a, const MtxFx43 *b, MtxFx43 *ab);
void MTX_MultVec43(const VecFx32 *vec, const MtxFx43 *m, VecFx32 *dst);
void MTX_LookAt(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, MtxFx43 *mtx);

void MTX_RotAxis43(void *m, void *v)
{
    MTX_RotAxis33(m, v);
    *(unsigned int *)((char *)m + 0x24) = 0;
    *(unsigned int *)((char *)m + 0x28) = 0;
    *(unsigned int *)((char *)m + 0x2c) = 0;
}

#define FX32_SHIFT 12

#define FX32_ONE   4096

int MTX_Inverse43(const MtxFx43 *pSrc, MtxFx43 *pDst)
{
    MtxFx43 tmp;
    MtxFx43 *p;
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

    p->_30 = -(fx32)(((fx64)p->_00 * pSrc->_30 + (fx64)p->_10 * pSrc->_31 + (fx64)p->_20 * pSrc->_32) >> FX32_SHIFT);
    p->_31 = -(fx32)(((fx64)p->_01 * pSrc->_30 + (fx64)p->_11 * pSrc->_31 + (fx64)p->_21 * pSrc->_32) >> FX32_SHIFT);
    p->_32 = -(fx32)(((fx64)p->_02 * pSrc->_30 + (fx64)p->_12 * pSrc->_31 + (fx64)p->_22 * pSrc->_32) >> FX32_SHIFT);

    if (p == &tmp) {
        MI_Copy48B(&tmp, pDst);
    }
    return 0;
}

#define FX32_SHIFT 12

void MTX_Concat43(const MtxFx43 *a, const MtxFx43 *b, MtxFx43 *ab)
{
    MtxFx43 tmp;
    MtxFx43 *p;
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

    x = a->_30;
    y = a->_31;
    z = a->_32;

    p->_32 = (fx32)(b->_32 + (((fx64)x * xx + (fx64)y * yy + (fx64)z * zz) >> FX32_SHIFT));
    p->_31 = (fx32)(b->_31 + (((fx64)x * b->_01 + (fx64)y * b->_11 + (fx64)z * b->_21) >> FX32_SHIFT));
    p->_30 = (fx32)(b->_30 + (((fx64)x * b->_00 + (fx64)y * b->_10 + (fx64)z * b->_20) >> FX32_SHIFT));

    if (p == &tmp) {
        *ab = tmp;
    }
}

/*
 * sdk:      MTX_MultVec43 (libfx.TWL.HYB.a fx_mtx43.o)
 */
void MTX_MultVec43(const VecFx32 *vec, const MtxFx43 *m, VecFx32 *dst)
{
    fx32 x = vec->x;
    fx32 y = vec->y;
    fx32 z = vec->z;

    dst->x = (fx32)(((fx64)x * m->_00 + (fx64)y * m->_10 + (fx64)z * m->_20) >> 12);
    dst->x += m->_30;
    dst->y = (fx32)(((fx64)x * m->_01 + (fx64)y * m->_11 + (fx64)z * m->_21) >> 12);
    dst->y += m->_31;
    dst->z = (fx32)(((fx64)x * m->_02 + (fx64)y * m->_12 + (fx64)z * m->_22) >> 12);
    dst->z += m->_32;
}

/*
 * sdk:      MTX_LookAt (libfx.TWL.HYB.a fx_mtx43.o)
 */
void MTX_LookAt(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, MtxFx43 *mtx)
{
    VecFx32 vLook, vRight, vUp;

    vLook.x = camPos->x - target->x;
    vLook.y = camPos->y - target->y;
    vLook.z = camPos->z - target->z;
    VEC_Normalize(&vLook, &vLook);
    VEC_CrossProduct(camUp, &vLook, &vRight);
    VEC_Normalize(&vRight, &vRight);
    VEC_CrossProduct(&vLook, &vRight, &vUp);

    mtx->_00 = vRight.x;
    mtx->_01 = vUp.x;
    mtx->_02 = vLook.x;
    mtx->_10 = vRight.y;
    mtx->_11 = vUp.y;
    mtx->_12 = vLook.y;
    mtx->_20 = vRight.z;
    mtx->_21 = vUp.z;
    mtx->_22 = vLook.z;
    mtx->_30 = -VEC_DotProduct(camPos, &vRight);
    mtx->_31 = -VEC_DotProduct(camPos, &vUp);
    mtx->_32 = -VEC_DotProduct(camPos, &vLook);
}
