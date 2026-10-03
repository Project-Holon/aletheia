/*
 * function: func_021C3270
 * address:  0x021C3270
 * packet:   pkt_ov021_021C3270
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200BCA8  0x0200BCA8  thumb
 *   func_0200BC2C  0x0200BC2C  thumb
 *   func_0200BCD8  0x0200BCD8  thumb
 *   func_021C3530  0x021C3530  thumb  ov021
 *   func_021C32BC  0x021C32BC  thumb  ov021
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0200BC88  0x0200BC88  thumb
 *   func_021C36B0  0x021C36B0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int func_0200BCA8(u32, u32);
extern u32 func_0200BC2C(u32, u32);
extern u32 func_0200BCD8(u32, u32);
extern void func_021C3530(u32, u32);
extern void func_021C32BC(u32 *, u32);
extern u32 func_0201A98C(u32, u32);
extern void func_0200BC88(u32, u32);
extern void func_021C36B0(u32);

void func_021C3270(u32 *p, u32 b, u32 c)
{
    u32 m;

    if (func_0200BCA8(p[2], b) == 1) {
        m = func_0200BC2C(p[2], b);
        func_021C3530(m, func_0200BCD8(p[2], b));
        func_021C32BC(p, m);
        func_0201A98C(c, m);
        func_0200BC88(p[2], b);
        func_021C36B0(p[2]);
    }
}
