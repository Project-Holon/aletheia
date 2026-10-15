/*
 * function: MTX_ScaleApply33
 * address:  0x0207AE38
 * packet:   pkt_0207AE38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MTX_ScaleApply33 (libfx.TWL.HYB.a fx_mtx33.o)
 *
 * symbols:
 *   (none)
 */

typedef long fx32;
typedef long long fx64;
typedef short fx16;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    fx16 x, y, z;
} VecFx16;

typedef union {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
    };
    fx32 m[3][3];
    fx32 a[9];
} MtxFx33;

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
