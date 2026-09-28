/*
 * function: func_0207C9D0
 * address:  0x0207C9D0
 * packet:   pkt_0207C9D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      VEC_Add (libfx.TWL.HYB.a fx_vec.o)
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

void func_0207C9D0(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab)
{
    ab->x = a->x + b->x;
    ab->y = a->y + b->y;
    ab->z = a->z + b->z;
}
