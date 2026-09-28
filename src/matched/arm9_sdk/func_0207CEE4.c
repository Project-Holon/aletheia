/*
 * function: func_0207CEE4
 * address:  0x0207CEE4
 * packet:   pkt_0207CEE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      VEC_MultAdd (libfx.TWL.HYB.a fx_vec.o)
 *
 * symbols:
 *   (none)
 */

typedef long fx32;
typedef short fx16;
typedef long long fx64;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    fx16 x, y, z;
} VecFx16;

void func_0207CEE4(fx32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest)
{
    pDest->x = (fx32)(((fx64)a * v1->x) >> 12) + v2->x;
    pDest->y = (fx32)(((fx64)a * v1->y) >> 12) + v2->y;
    pDest->z = (fx32)(((fx64)a * v1->z) >> 12) + v2->z;
}
