/*
 * function: func_021FED24
 * address:  0x021FED24
 * packet:   pkt_021FED24
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FF318  0x021FF318  thumb  ov135
 *   func_021F4E98  0x021F4E98  thumb  ov135

 * Build through func_021FF318 and publish the 0x10/0x8 pair.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021FF318(u8 *p, u32 k, int b, int c, int d);
extern void func_021F4E98(u8 *p, u32 a, u32 b);

int func_021FED24(u8 *p)
{
    func_021FF318(p, 0xa, 1, 0, 0xf0f);
    func_021F4E98(p, 0x17, 0x8);
    return 2;
}
