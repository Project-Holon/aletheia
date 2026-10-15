/*
 * function: MTX_RotAxis33
 * address:  0x0207AF50
 * packet:   pkt_0207AF50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MTX_RotAxis33 (libfx.TWL.HYB.a fx_mtx33.o)
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
