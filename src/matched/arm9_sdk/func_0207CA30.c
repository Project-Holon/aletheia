/*
 * function: func_0207CA30
 * address:  0x0207CA30
 * packet:   pkt_0207CA30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      VEC_Fx16Add (libfx.TWL.HYB.a fx_vec.o)
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

void func_0207CA30(const VecFx16 *a, const VecFx16 *b, VecFx16 *ab)
{
    ab->x = (fx16)(a->x + b->x);
    ab->y = (fx16)(a->y + b->y);
    ab->z = (fx16)(a->z + b->z);
}
