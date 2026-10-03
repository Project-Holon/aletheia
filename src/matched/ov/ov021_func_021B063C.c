/*
 * function: func_021B063C
 * address:  0x021B063C
 * packet:   pkt_ov021_021B063C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02188D48  0x02188D48  thumb  ov021
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02158F7C  0x02158F7C  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C274  0x0200C274  thumb
 *   func_02190728  0x02190728  thumb  ov021
 *   func_02190708  0x02190708  thumb  ov021
 *   func_02188D4C  0x02188D4C  thumb  ov021
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02190758  0x02190758  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_02159B10(u32, u32);
extern void *func_0215A5DC(void *a0);
extern u32 func_020120F4(void *);
extern u32 func_020127A4(u32);
typedef unsigned char  u8;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188C54(u8 *p);
extern u32 func_02188D48(u8 *p);
extern void *func_0215A5F4(void *p);
extern u32 func_02158F74(void *);
extern u32 func_02158F7C(u8 *p);
extern u16 func_02188C84(u8 *p);
extern u32 func_02045B38(u32, u32, u32, u32);
extern u32 func_020457B0(u32, u32);
extern u32 func_02012F08(u32);
extern u32 func_0200C274(u32);
extern int func_02190728(u32 a);
extern u32 func_02190708(u32, u32, u16, u16, u16, u16);
extern void func_02188D4C(u8 *p, u32 v);
extern void func_0201EFA4(u32, u32, u32, u32, u32, u32);
extern void func_02045CAC(u32, u32, u32);
extern void func_0201F250(u32, u32, u32);
extern int func_02190758(u32 a, u32 b, u32 c, u32 d);
extern void func_02045808(u32);
extern void func_02045C04(u32);

int func_021B063C(u32 a, u32 b)
{
    u16 v1, v2;
    void *t;
    void *y;
    u32 x, m, w, r6, r7, h, z, obj, g;

    v1 = func_02159B10(a, b);
    v2 = func_02159B10(a, b);
    t = func_0215A5DC((void *)b);
    x = func_020120F4(t);
    func_020127A4(x);
    y = func_0201210C(t);
    m = func_02188C54(y);
    w = func_02188D48(y);
    t = func_0215A5F4((void *)b);
    r6 = func_02158F74(t);
    r7 = func_02158F7C(t);
    h = func_02188C84(y);
    z = func_02045B38(0, 3, 0x9e, h);
    h = func_020457B0(0x80, h);
    g = func_0200C274(func_02012F08(x));
    if (w != 0)
        func_02190728(w);
    obj = func_02190708(m, z, v1 - 9, v2, 9, 2);
    func_02188D4C(y, obj);
    func_0201EFA4(r6, 2, g, 7, 1, 1);
    func_02045CAC(z, 1, r7);
    func_0201F250(r6, h, r7);
    func_02190758(obj, 0, 0, h);
    func_02045808(h);
    func_02045C04(z);
    return 0;
}
