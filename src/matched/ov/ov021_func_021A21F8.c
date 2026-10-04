/*
 * function: func_021A21F8
 * address:  0x021A21F8
 * packet:   pkt_ov021_021A21F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A2A84  0x021A2A84  thumb  ov021
 */

typedef unsigned char u8;

typedef unsigned int   u32;
int func_021A2A84(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u32 e2, u32 e3, u32 e4, u32 e5);

void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h)
{
    func_021A2A84((u32)(p + 0x4C), (u32)p, b, a, c, d, e, f, g, h);
}
