/*
 * function: CircleGraph_SetCenter
 * address:  0x021C1194
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   CircleGraph_BuildVertices  0x021C18F8  thumb  ov217
 *   CircleGraph_StoreCenter  0x021C1A64  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Pos;
extern void CircleGraph_BuildVertices(u8 *p);
extern void CircleGraph_StoreCenter(u8 *p, const struct Pos *v);
void CircleGraph_SetCenter(u8 *p, struct Pos *v)
{
    CircleGraph_StoreCenter(p, v);
    CircleGraph_BuildVertices(p);
}

