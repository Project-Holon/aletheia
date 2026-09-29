/*
 * function: func_021AED24
 * address:  0x021AED24
 * packet:   pkt_ov021_021AED24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F8C  0x02158F8C  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A4C8  0x0215A4C8  thumb  ov010
 *   func_0215A4B4  0x0215A4B4  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_0216EAB0  0x0216EAB0  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 * The four func_02159B10 results are u16 locals (the callee returns u16):
 * with u32 locals the stack-argument stores for func_0216EAB0 schedule
 * after the r1/r2 setup instead of before it.
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0215A5F4(u32 a);
extern void func_02158F8C(void);
extern u16 func_02159B10(u32 a, u32 b);
extern u32 func_0215A4C8(u32 a);
extern u32 func_0215A4B4(u32 a);
extern u32 func_02158F54(u32 a);
extern u32 *func_02158F58(u32 a);
extern u32 func_0216EAB0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_0215897C(u32 a, u32 b);

int func_021AED24(u32 a, u32 b)
{
    u32 p, t;
    u16 x, y, z, w;

    p = func_0215A5F4(b);
    func_02158F8C();
    x = func_02159B10(a, b);
    y = func_02159B10(a, b);
    z = func_02159B10(a, b);
    w = func_02159B10(a, b);
    t = func_0215A4C8(x);
    if (y == 0 && func_0215A4B4(x) == 1) {
        y = x;
    }
    func_0215897C(p, func_0216EAB0(func_02158F54(p), func_02158F58(p)[1], t, 0, x, y, z, w));
    return 1;
}
