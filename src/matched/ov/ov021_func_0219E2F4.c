/*
 * function: func_0219E2F4
 * address:  0x0219E2F4
 * packet:   pkt_ov021_0219E2F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_0216D530  0x0216D530  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_021B7DC0  0x021B7DC0  thumb
 *   func_021B7E60  0x021B7E60  thumb
 *   func_021B8038  0x021B8038  thumb
 *   func_021B8040  0x021B8040  thumb
 *   func_021BB480  0x021BB480  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_0216D67C(void *o);
extern void *func_0216D530(void *p);
extern void *func_021BB480(void *p);
extern void *func_0216D69C(void *p);
extern u8 func_021B8040(u8 *p);
extern u8 func_021B8038(u8 *p);
extern void func_021B7E60(void *p, u32 a, void *out, u32 b);
extern void func_021B7DC0(void *p, void *out);

void func_0219E2F4(void *o, void *out)
{
    void **h;

    func_021BB480(func_0216D530(func_0216D67C(o)));
    h = func_0216D69C(o);
    if (func_021B8040(*h))
        func_021B7E60(*h, func_021B8038(*h), out, 0);
    else
        func_021B7DC0(*h, out);
}
