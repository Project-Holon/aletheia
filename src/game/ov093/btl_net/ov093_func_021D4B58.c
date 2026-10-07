/*
 * function: func_021D4B58
 * address:  0x021D4B58
 * packet:   pkt_ov093_021D4B58
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F3B88     0x021F3B88  data  ov093
 *   func_021D4394  0x021D4394  thumb ov093
 *   func_0203D3F8  0x0203D3F8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 f00;
};

extern struct S *d_021F3B88;
extern u8 func_021D4394(u32 a);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

u32 func_021D4B58(u32 a, u32 b, u32 c)
{
    u32 r = func_021D4394(a);

    if (r != 0x28) {
        return func_0203D3F8(d_021F3B88->f00, r, 0x107, c, b, 0, 0, 1);
    }
    return 1;
}
