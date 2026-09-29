/*
 * function: func_021B2218
 * address:  0x021B2218
 * packet:   pkt_ov021_021B2218
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021C7878  0x021C7878  thumb  ov021
 *   func_021C7220  0x021C7220  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0215A5F4(u32);
extern u32 func_0215A5EC(u32);
extern u32 func_02159B10(u32, u32);
extern u32 func_0216DE94(u32, u32);
extern u32 *func_02158F58(u32);
extern u32 func_02188D38(u32);
extern void func_020061E4(u32);
extern u32 func_021C7878(u32, u32, void *, u32);
extern u32 func_021C7220(u32, u32, u32, u32);
extern void func_021C6DE0(u32, u32, u32);

int func_021B2218(u32 a, u32 b)
{
    int v[3];
    u32 t;
    u32 o;
    u32 e;
    u32 g;
    u32 p;

    t = func_0215A5F4(b);
    o = func_02159B10(a, b);
    o = func_0216DE94(func_0215A5EC(b), o);
    e = func_02158F58(t)[1];
    g = func_02188D38(e);
    func_020061E4(0x676);
    v[0] = 0;
    v[1] = 0x96 << 12;
    v[2] = 0;
    p = func_021C7878(e, 0x18, v, o);
    func_021C6DE0(g, func_021C7220(e, 0x18, 3, o), 0);
    func_021C6DE0(g, p, 0);
    return 0;
}
