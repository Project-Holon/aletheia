/*
 * function: func_021B5008
 * address:  0x021B5008
 * packet:   pkt_ov021_021B5008
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021D30B8  0x021D30B8  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0215A5DC(u32);
extern u32 func_0215A5F4(u32);
extern u16 *func_02159AE8(u32, u32);
extern u32 func_021D30B8(u32, u16 *);
extern void func_0215897C(u32, u32);

int func_021B5008(u32 a, u32 b)
{
    u32 d = func_0215A5DC(b);
    u32 s = func_0215A5F4(b);

    func_0215897C(s, func_021D30B8(d, func_02159AE8(a, b)));
    return 1;
}
