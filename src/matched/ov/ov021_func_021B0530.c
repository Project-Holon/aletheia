/*
 * function: func_021B0530
 * address:  0x021B0530
 * packet:   pkt_ov021_021B0530
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_021B03E4  0x021B03E4  thumb  ov021
 *   func_0215A60C  0x0215A60C  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02158F7C  0x02158F7C  thumb  ov010
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02191164  0x02191164  thumb  ov021
 *   func_02191184  0x02191184  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern u32 func_0215A5F4(u32);
extern u32 func_02158F78(u32);
extern u32 func_02159B10(u32, u32);
extern u32 func_02011330(u32);
extern void func_021B03E4(u32, u32);
extern u32 func_0215A60C(u32);
extern u32 func_02158F74(u32);
extern u32 func_02158F7C(u32);
extern void func_02045CAC(u32, u32, u32);
extern void func_0201F250(u32, u32, u32);
extern u32 func_0215A61C(u32);
extern void func_02191164(void);
extern void func_02191184(u32, u32, u32, u32);

int func_021B0530(u32 a, u32 b)
{
    u32 t, s, x, y, z, w;

    t = func_0215A5F4(b);
    s = func_02158F78(t);
    x = func_02159B10(a, b);
    func_021B03E4(b, (u8)func_02011330(a));
    y = func_0215A60C(b);
    z = func_02158F74(t);
    w = func_02158F7C(t);
    func_02045CAC(y, x, w);
    func_0201F250(z, s, w);
    y = func_0215A61C(b);
    func_02191164();
    func_02191184(y, 0, 0, s);
    return 0;
}
