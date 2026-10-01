/*
 * function: func_021B2AB0
 * address:  0x021B2AB0
 * packet:   pkt_ov021_021B2AB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021C0AA0  0x021C0AA0  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_0215A5DC(u32);
extern u32 func_0215A5F4(u32);
extern u32 func_02158F50(u32);
extern u32 func_021C0AA0(u32, u32);
extern void func_0215897C(u32, u32);

int func_021B2AB0(u32 a, u32 b)
{
    u32 d = func_0215A5DC(b);
    u32 s = func_0215A5F4(b);

    func_0215897C(s, func_021C0AA0(d, func_02158F50(s)));
    return 1;
}
