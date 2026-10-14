/*
 * function: CircleGraph_StoreCenter
 * address:  0x021C1A64
 * packet:   pkt_ov217_021C1A64
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A const source pointer fixes the load order (y, x, z).
 *
 * symbols:
 */

typedef unsigned char u8;
typedef short s16;
struct Pos { s16 x; s16 y; s16 z; };

void CircleGraph_StoreCenter(u8 *p, const struct Pos *v)
{
    s16 z = v->z;
    s16 y = v->y;
    s16 x = v->x;
    *(s16 *)(p + 0x1B4) = x;
    *(s16 *)(p + 0x1B6) = y;
    *(s16 *)(p + 0x1B8) = z;
}
