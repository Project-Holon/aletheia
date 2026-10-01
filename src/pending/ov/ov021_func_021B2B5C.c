/*
 * function: func_021B2B5C
 * address:  0x021B2B5C
 * packet:   pkt_ov021_021B2B5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021C9828  0x021C9828  thumb  ov093
 */

typedef unsigned int u32;

extern u32 func_0215A5DC(u32);
extern u32 func_0215A5F4(u32);
extern u32 func_0201210C(u32);
extern u32 func_02158F50(u32);
extern u32 func_021C9828(u32, u32, u32);
extern void func_0215897C(u32, u32);

int func_021B2B5C(u32 a, u32 b)
{
    u32 d = func_0215A5DC(b);
    u32 s = func_0215A5F4(b);
    u32 w = func_0201210C(d);

    func_0215897C(s, func_021C9828(func_02158F50(s), d, w));
    return 1;
}
