/*
 * function: func_021C4628
 * address:  0x021C4628
 * packet:   pkt_ov021_021C4628
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021C1228  0x021C1228  thumb  ov021
 *   func_0215A644  0x0215A644  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 *   func_021C4608  0x021C4608  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_0215A5CC(u32 a);
extern u32 func_0215A5DC(u32 a);
extern u32 func_0201210C(u32 a);
extern u32 func_02188CB4(u32 a);
extern u32 func_021A3050(u32 a);
extern u32 func_02159B10(u32 a, u32 b);
extern u32 func_021C1228(u32 a, u32 b, u32 c, u32 d);
extern void func_0215A644(u32 a, u32 b);
extern void func_020113D0(u32 a, int (*f)(int, int));
extern int func_021C4608(int a, int b);

u32 func_021C4628(u32 a, u32 b)
{
    u32 w, x, y, t;

    w = func_0215A5CC(b);
    x = func_02188CB4(func_0201210C(func_0215A5DC(b)));
    y = func_021A3050(x);
    t = func_02159B10(a, b);
    t = func_021C1228(x, y, t, w);
    func_0215A644(b, t);
    func_020113D0(a, func_021C4608);
    return 1;
}
