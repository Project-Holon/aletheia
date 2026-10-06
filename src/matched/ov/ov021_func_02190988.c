/*
 * function: func_02190988
 * address:  0x02190988
 * packet:   pkt_ov021_02190988
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02020D10  0x02020D10  thumb  arm9
 *   func_02190860  0x02190860  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Handle {
    u16 *owner;
    u32 slot;
    u32 id;
    u32 c;
    u32 obj;
} Handle;

extern Handle *func_02190860(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u16 f, u32 g, u32 h, u32 i);
extern void func_02020D10(u8 *p, u32 v);

Handle *func_02190988(u16 *a, const u8 *b, u32 c, u32 d, u32 x, u16 y, u16 z, u32 w)
{
    Handle *r = func_02190860(a, b, c, y, z, a[3], d, 0, x);
    if (w == 0)
        func_02020D10((u8 *)r->obj, 1);
    return r;
}
