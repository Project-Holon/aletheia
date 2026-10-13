/*
 * function: VEC_Fx16DotProduct
 * address:  0x0207CAA4
 * packet:   pkt_0207CAA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      VEC_Fx16DotProduct (libfx.TWL.HYB.a fx_vec.o)
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

fx32 VEC_Fx16DotProduct(const VecFx16 *a, const VecFx16 *b)
{
    fx32 tmp1, tmp2;

    tmp1 = (a->x * b->x) + (a->y * b->y);
    tmp2 = (a->z * b->z) + (1 << 11);
    return (fx32)(((fx64)tmp1 + tmp2) >> 12);
}
