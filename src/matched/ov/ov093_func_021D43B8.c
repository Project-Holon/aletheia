/*
 * function: func_021D43B8
 * address:  0x021D43B8
 * packet:   pkt_ov093_021D43B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F3B88     0x021F3B88  data  ov093
 *   func_0203D3F8  0x0203D3F8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 f00;
};

extern struct S *d_021F3B88;
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

u32 func_021D43B8(u32 a)
{
    return func_0203D3F8(d_021F3B88->f00, 0xff, 0x101, 0x20, a, 0, 0, 0);
}
