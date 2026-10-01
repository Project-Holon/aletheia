/*
 * function: func_021B162C
 * address:  0x021B162C
 * packet:   pkt_ov021_021B162C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F250  0x0201F250  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_02158F7C  0x02158F7C  thumb  ov010
 *   func_0215A60C  0x0215A60C  thumb  ov010
 */

typedef unsigned int u32;

extern u32 func_0215A60C(u32);
extern u32 func_02158F78(u32);
extern u32 func_02158F74(u32);
extern u32 func_02158F7C(u32);
extern void func_02045CAC(u32, u32, u32);
extern void func_0201F250(u32, u32, u32);

u32 func_021B162C(u32 a, u32 b, u32 c)
{
    u32 x, r, s, n;

    x = func_0215A60C(a);
    r = func_02158F78(b);
    s = func_02158F74(b);
    n = func_02158F7C(b);
    func_02045CAC(x, c, n);
    func_0201F250(s, r, n);
    return r;
}
