/*
 * function: VEC_Subtract
 * address:  0x0207CA00
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Original (48 bytes, no relocation): the same shape as VEC_Add with the
 * three component differences subtracted.
 */

typedef int s32;

typedef struct
{
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *c)
{
    c->x = a->x - b->x;
    c->y = a->y - b->y;
    c->z = a->z - b->z;
}
