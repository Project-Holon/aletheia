/*
 * function: MTX_RotAxis33
 * address:  0x0207AF50
 * packet:   pkt_0207AF50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * TwlSDK libfx fx_mtx33.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Rotation about the unit axis vec by the angle given as (sinVal, cosVal):
 * the diagonal is t*v*v + cos and each off-diagonal pair is t*vi*vj -/+
 * sin*vk, with t = 1 - cos, all in 64-bit fixed point.
 */

typedef long fx32;
typedef long long fx64;

typedef union {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
    };
    fx32 m[3][3];
    fx32 a[9];
} MtxFx33;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

void MTX_RotAxis33(MtxFx33 *pDst, const VecFx32 *vec, fx32 sinVal, fx32 cosVal)
{
    fx64 t;
    fx64 ss;
    fx64 xx;
    fx64 yy;
    fx64 zz;
    fx32 t01;
    fx32 s2;

    t = (fx64)(0x1000 - cosVal);
    ss = sinVal;
    xx = (fx64)vec->x * vec->x;
    yy = (fx64)vec->y * vec->y;
    zz = (fx64)vec->z * vec->z;

    pDst->_00 = (fx32)((t * xx) >> 24) + cosVal;
    pDst->_11 = (fx32)((t * yy) >> 24) + cosVal;
    pDst->_22 = (fx32)((t * zz) >> 24) + cosVal;

    t01 = (fx32)((t * vec->x * vec->y) >> 24);
    s2 = (fx32)((ss * vec->z) >> 12);
    pDst->_01 = t01 + s2;
    pDst->_10 = t01 - s2;

    t01 = (fx32)((t * vec->x * vec->z) >> 24);
    s2 = (fx32)((ss * vec->y) >> 12);
    pDst->_02 = t01 - s2;
    pDst->_20 = t01 + s2;

    t01 = (fx32)((t * vec->y * vec->z) >> 24);
    s2 = (fx32)((ss * vec->x) >> 12);
    pDst->_12 = t01 + s2;
    pDst->_21 = t01 - s2;
}
