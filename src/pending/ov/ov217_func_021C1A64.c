/*
 * function: func_021C1A64
 * address:  0x021C1A64
 * packet:   pkt_ov217_021C1A64
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Note 2026-10-02: DIFF, right loads and stores; only register colouring differs (orig y=r4, x=r3, z=r2).
 * Tried s16/int locals, declaration orders, direct stores, struct copy.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef short s16;
struct Pos { s16 x; s16 y; s16 z; };

void func_021C1A64(u8 *p, struct Pos *v)
{
    struct Pos *d = (struct Pos *)(p + 0x1B4);
    d->x = v->x;
    d->y = v->y;
    d->z = v->z;
}
