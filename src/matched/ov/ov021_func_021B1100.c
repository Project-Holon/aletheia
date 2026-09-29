/*
 * function: func_021B1100
 * address:  0x021B1100
 * packet:   pkt_ov021_021B1100
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B1100  0x021B1100  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_020457B0  0x020457B0  arm
 *   func_0215A60C  0x0215A60C  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02158F7C  0x02158F7C  thumb  ov010
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02191830  0x02191830  thumb  ov021
 *   func_021918DC  0x021918DC  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_02159144  0x02159144  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0215A5F4(u32);
extern u16 **func_02158F58(u32);
extern u16 func_02011330(void *);
extern u32 func_02159B10(void *, u32);
extern u32 func_0215A5CC(u32);
extern u32 func_020457B0(u32 n, u32 heap);
extern u32 func_0215A60C(u32);
extern u32 func_02158F74(u32);
extern u32 func_02158F7C(u32);
extern void func_02045CAC(u32, u32, u32);
extern void func_0201F250(u32, u32, u32);
extern void func_02191830(u16 *, u32, u8 *, u8 *);
extern void func_021918DC(u16 *a, u32 b, u32 c, u8 d, u8 e, u8 f, u8 g);
extern void func_02045808(u32);
extern void func_02159144(u32);

int func_021B1100(void *a, u32 b)
{
    u32 o, h, y, z, w;
    u16 x1, x2;
    u16 **q;
    int k0, k1;
    u8 buf[2];
    u8 t;

    o = func_0215A5F4(b);
    q = func_02158F58(o);
    x1 = func_02011330(a);
    k0 = func_02159B10(a, b);
    k1 = func_02159B10(a, b);
    x2 = func_02011330(a);
    buf[0] = 2;
    h = func_020457B0(0x40, func_0215A5CC(b));
    y = func_0215A60C(b);
    z = func_02158F74(o);
    w = func_02158F7C(o);
    func_02045CAC(y, x1, w);
    func_0201F250(z, h, w);
    func_02191830(*q, h, &buf[1], &buf[0]);
    t = buf[1];
    if (k0 + t > 0x1f) {
        k0 = (u16)(0x1f - t);
    }
    if (k1 + buf[0] > 0x18) {
        k1 = 4;
        buf[0] = k1;
    }
    func_021918DC(*q, h, x2, k0, k1, t, buf[0]);
    func_02045808(h);
    func_02159144(5);
    return 0;
}
