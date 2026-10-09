/*
 * function: func_0207AD70
 * address:  0x0207AD70
 * packet:   pkt_0207AD70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MTX_ScaleApply22 (libfx.TWL.HYB.a fx_mtx22.o)
 *
 * symbols:
 *   (none)
 */

typedef long fx32;
typedef long long fx64;

typedef union {
    struct {
        fx32 _00, _01;
        fx32 _10, _11;
    };
    fx32 m[2][2];
    fx32 a[4];
} MtxFx22;

void func_0207AD70(const MtxFx22 *pSrc, MtxFx22 *pDst, fx32 x, fx32 y)
{
    pDst->_00 = (fx32)(((fx64)x * pSrc->_00) >> 12);
    pDst->_01 = (fx32)(((fx64)x * pSrc->_01) >> 12);
    pDst->_10 = (fx32)(((fx64)y * pSrc->_10) >> 12);
    pDst->_11 = (fx32)(((fx64)y * pSrc->_11) >> 12);
}
