/*
 * function: func_0219E398
 * address:  0x0219E398
 * packet:   pkt_ov021_0219E398
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D530  0x0216D530  thumb  ov010
 *   func_021B7DE0  0x021B7DE0  thumb  ov021
 *   func_0216DCB4  0x0216DCB4  thumb  ov010
 *   func_021BB3C4  0x021BB3C4  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_0219E498  0x0219E498  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 **func_0216D69C();
extern u32 func_0216D67C();
extern u32 func_0216D530();
extern int func_021B7DE0();
extern int func_0216DCB4();
extern u32 func_021BB3C4();
extern u16 func_021AB0F8(u32 attr);
extern int func_0219E498();

u32 func_0219E398(u32 o, u32 a, u32 b, u32 *out)
{
    u32 r;
    u32 **p;
    u32 v;

    r = 0;
    p = func_0216D69C(o);
    v = func_0216D530(func_0216D67C(o));
    if (!func_021B7DE0(*p, a)) {
        r |= 1;
    }
    if (!func_021B7DE0(*p, b)) {
        r |= 1;
    }
    if (!func_0216DCB4(o)) {
        p = (u32 **)func_021BB3C4(v, b);
        if (func_021AB0F8((u32)p) & 1) {
            r |= 2;
        }
        if (out) {
            *out = (u32)p;
        }
    }
    if (func_0219E498(o, b)) {
        r |= 4;
    }
    return r;
}
