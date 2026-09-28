/*
 * function: func_0207B51C
 * address:  0x0207B51C
 * packet:   pkt_0207B51C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MTX_MultVec33 (libfx.TWL.HYB.a fx_mtx33.o)
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

void func_0207B51C(const VecFx32 *vec, const MtxFx33 *m, VecFx32 *dst)
{
    fx32 x = vec->x;
    fx32 y = vec->y;
    fx32 z = vec->z;

    dst->x = (fx32)(((fx64)x * m->_00 + (fx64)y * m->_10 + (fx64)z * m->_20) >> 12);
    dst->y = (fx32)(((fx64)x * m->_01 + (fx64)y * m->_11 + (fx64)z * m->_21) >> 12);
    dst->z = (fx32)(((fx64)x * m->_02 + (fx64)y * m->_12 + (fx64)z * m->_22) >> 12);
}
