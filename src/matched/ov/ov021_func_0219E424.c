/*
 * function: func_0219E424
 * address:  0x0219E424
 * packet:   pkt_ov021_0219E424
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D530  0x0216D530  thumb  ov010
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_021B7DC0  0x021B7DC0  thumb  ov021
 *   func_021B7E60  0x021B7E60  thumb  ov021
 *   func_021B7CD8  0x021B7CD8  thumb  ov021
 *   func_0219E938  0x0219E938  thumb  ov021
 *   func_0219E398  0x0219E398  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0216D67C();
extern u32 func_0216D530();
extern u32 **func_0216D69C();
extern u32 func_0216D5F8();
extern u32 func_021BB480();
extern void func_021B7DC0();
extern int func_021B7E60();
extern int func_021B7CD8();
extern u32 func_0219E938();
extern int func_0219E398();

int func_0219E424(u32 o, u32 k, u32 x)
{
    u32 v;
    u32 **p;
    u32 a[2];
    u32 b[2];
    int r;
    u32 t;

    v = func_021BB480(func_0216D530(func_0216D67C(o)));
    p = func_0216D69C(o);
    func_021B7DC0(*p, a);
    t = func_0216D5F8(o);
    if (t == k) {
        r = func_021B7E60(*p, func_0219E938(k), b, 0);
    } else {
        r = func_021B7CD8(v, a, func_0219E938(k), b);
    }
    if (r) {
        return func_0219E398(o, a, b, x);
    }
    return 1;
}
