/*
 * function: func_021C2758
 * address:  0x021C2758
 * packet:   pkt_ov093_021C2758
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C27A0  0x021C27A0  thumb  ov093
 *   func_021C2910  0x021C2910  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021C27A0(u8 *p, u32 x, u32 y, u32 z, u32 a, u32 zero, u32 b);
extern void func_021C2910(u8 *p, u32 x, u32 y, u32 z, u32 a, u32 c, u32 d, u32 e);

int func_021C2758(u8 *p, u32 x, u32 y, u32 z, u32 a, u32 b, u32 c)
{
    if (func_021C27A0(p, x, y, z, a, 0, b) == 0) {
        func_021C2910(p, x, y, z, a, c, 0, 0);
        return 1;
    }
    return 0;
}
