/*
 * function: MTX_Inverse43
 * address:  0x0207B67C
 * packet:   pkt_0207B67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfx fx_mtx43.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Inverts a 4x3 affine matrix: the 3x3 cofactors, the determinant through
 * the divider (FX_InvAsync / FX_GetDivResult), then the translation row.
 * Returns -1 when the determinant is zero.  Works through a stack copy when
 * the source and destination alias.  Closed with the three cofactors
 * computed in declaration order (det00, det10, det20) and det10 spelled
 * `_10 * _22 - _12 * _20`; the high words spilled across FX_InvAsync are
 * the compiler's own sign extensions, not fx64 locals.
 *
 * symbols:
 *   FX_InvAsync                      0x0207C8A0  arm
 *   FX_GetDivResult                  0x0207C86C  arm
 *   MI_Copy48B                       0x02082B7C  arm
 */

typedef long fx32;
typedef long long fx64;

#define FX32_SHIFT 12
#define FX32_ONE   4096

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

void FX_InvAsync(fx32 denom);
fx32 FX_GetDivResult(void);
void MI_Copy48B(const void *pSrc, void *pDest);

int MTX_Inverse43(const MtxFx43 *pSrc, MtxFx43 *pDst)
{
    MtxFx43 tmp;
    MtxFx43 *p;
    fx32 det;
    fx32 tmp01, tmp02, tmp11, tmp12;

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

        tmp01 = (fx32)(((fx64)pSrc->_01 * pSrc->_22 - (fx64)pSrc->_21 * pSrc->_02) >> FX32_SHIFT);
        tmp02 = (fx32)(((fx64)pSrc->_01 * pSrc->_12 - (fx64)pSrc->_11 * pSrc->_02) >> FX32_SHIFT);
        tmp11 = (fx32)(((fx64)pSrc->_00 * pSrc->_22 - (fx64)pSrc->_20 * pSrc->_02) >> FX32_SHIFT);
        tmp12 = (fx32)(((fx64)pSrc->_00 * pSrc->_12 - (fx64)pSrc->_10 * pSrc->_02) >> FX32_SHIFT);

        det = FX_GetDivResult();
        p->_00 = (fx32)(((fx64)det * det00) >> FX32_SHIFT);
        p->_01 = -(fx32)(((fx64)det * tmp01) >> FX32_SHIFT);
        p->_02 = (fx32)(((fx64)det * tmp02) >> FX32_SHIFT);

        p->_10 = -(fx32)(((fx64)det * det10) >> FX32_SHIFT);
        p->_11 = (fx32)(((fx64)det * tmp11) >> FX32_SHIFT);
        p->_12 = -(fx32)(((fx64)det * tmp12) >> FX32_SHIFT);

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
