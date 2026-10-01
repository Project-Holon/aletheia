/*
 * function: func_021B4EE0
 * address:  0x021B4EE0
 * packet:   pkt_ov021_021B4EE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011290  0x02011290  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0215898C  0x0215898C  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215F8A8  0x0215F8A8  thumb  ov010
 */

typedef unsigned int u32;

extern u32 func_0215A5F4(u32);
extern u32 func_0215A5DC(u32);
extern u32 func_0201210C(u32);
extern u32 func_02159B10(u32, u32);
extern u32 func_0215F8A8(u32, u32);
extern void func_0215898C(u32, u32);
extern void func_02011290(u32);

int func_021B4EE0(u32 a, u32 b)
{
    u32 s = func_0215A5F4(b);
    u32 d = func_0215A5DC(b);

    func_0201210C(d);
    func_0215898C(s, func_0215F8A8(d, func_02159B10(a, b)));
    func_02011290(a);
    return 1;
}
