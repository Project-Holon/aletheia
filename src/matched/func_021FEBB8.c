/*
 * function: func_021FEBB8
 * address:  0x021FEBB8
 * packet:   pkt_021FEBB8
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

 * Build through func_021FF318 and publish the 0x10/0x5 pair.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021FF318(u8 *p, u32 a, u32 b, u32 c, u32 d);
extern void func_021F4E98(u8 *p, u32 a, u32 b);

int func_021FEBB8(u8 *p)
{
    func_021FF318(p, 0x9, 1, 0, 0xf0f);
    func_021F4E98(p, 0x17, 0x5);
    return 2;
}
