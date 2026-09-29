/*
 * function: func_021AEB3C
 * address:  0x021AEB3C
 * packet:   pkt_ov021_021AEB3C
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
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_0216E818  0x0216E818  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021AEDAC  0x021AEDAC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_0215A5F4(u32 a);
extern void func_02158F8C(void);
extern u32 func_02159B10(u32 a, u32 b);
extern u32 func_02158F54(u32 a);
extern u32 *func_02158F58(u32 a);
extern u32 func_0216E818(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_0215897C(u32 a, u32 b);
extern void func_021AEDAC(u32 a);

int func_021AEB3C(u32 a, u32 b)
{
    u32 p, x, y, z, w;

    p = func_0215A5F4(b);
    func_02158F8C();
    x = func_02159B10(a, b);
    y = func_02159B10(a, b);
    z = func_02159B10(a, b);
    w = func_02159B10(a, b);
    func_0215897C(p, func_0216E818(func_02158F54(p), func_02158F58(p)[1], 1, x, y, z, w));
    func_021AEDAC(b);
    return 1;
}
