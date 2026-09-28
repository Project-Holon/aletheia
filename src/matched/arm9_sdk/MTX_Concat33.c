/*
 * function: MTX_Concat33
 * address:  0x0207B388
 * packet:   pkt_0207B388
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfx fx_mtx33.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * ab = a * b for 3x3 matrices, through a stack copy when ab aliases b.
 */

typedef long fx32;
typedef long long fx64;

#define FX32_SHIFT 12

typedef union {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
    };
    fx32 m[3][3];
    fx32 a[9];
} MtxFx33;

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
