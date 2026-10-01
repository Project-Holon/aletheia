/*
 * function: func_021D1A74
 * address:  0x021D1A74
 * packet:   pkt_ov021_021D1A74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   func_0215910C  0x0215910C  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021D1894  0x021D1894  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0215A5F4(u32 a);
extern u32 func_0215910C(u32 a);
extern u32 func_02159B10(u32 a, u32 b);
extern void func_021D1894(u32 a, u32 b);

int func_021D1A74(u32 a, u32 b)
{
    u32 x = func_0215A5F4(b);
    u32 k = func_02159B10(a, b);

    func_021D1894(func_0215910C(x), k);
    return 0;
}
