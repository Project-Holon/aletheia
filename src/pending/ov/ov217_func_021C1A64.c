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
 * Note 2026-10-04 (wD2 lane12): also tried a static inline set3(q,y,x,z) helper with the call args in load order y,x,z: same 8 bytes (our order y,z,x; scheduler hoists movs r2,#4 first).
 *
 * Note 2026-10-02: DIFF, right loads and stores; only register colouring differs (orig y=r4, x=r3, z=r2).
 * Tried s16/int locals, declaration orders, direct stores, struct copy.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 *
 * Note 2026-10-04 (wD1 lane06): raw-offset stores with locals declared z, y, x give the right colours
 *   (y r4, x r3, z r2); residue is load order only (original y, x, z; ours y, z, x, 8 bytes). All 36 declaration/assignment
 *   orders of x,y,z tried.
 */

typedef unsigned char u8;
typedef short s16;
struct Pos { s16 x; s16 y; s16 z; };

void func_021C1A64(u8 *p, struct Pos *v)
{
    s16 z = v->z;
    s16 y = v->y;
    s16 x = v->x;
    *(s16 *)(p + 0x1B4) = x;
    *(s16 *)(p + 0x1B6) = y;
    *(s16 *)(p + 0x1B8) = z;
}
