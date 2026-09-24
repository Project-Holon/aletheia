/*
 * function: func_021F651C
 * address:  0x021F651C
 * packet:   pkt_021F651C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F663C  0x021F663C  thumb  ov135
 *   func_021F4E98  0x021F4E98  thumb  ov135

 * Build through func_021F663C and publish the 3/0xf pair.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021F663C(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_021F4E98(u8 *p, u32 a, u32 b);

int func_021F651C(u8 *p)
{
    func_021F663C(p, 0x19, 1, 0, 0xf0f, 1);
    func_021F4E98(p, 3, 0xf);
    return 2;
}
