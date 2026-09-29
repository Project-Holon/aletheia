/*
 * function: func_021D29F0
 * address:  0x021D29F0
 * packet:   pkt_ov021_021D29F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045180  0x02045180  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02041300  0x02041300  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_0215A5F4(u32 a);
extern u32 *func_02158F58(u32 a);
extern u32 func_02188C84(u32 a);
extern u32 func_02188C54(u32 a);
extern u32 func_02011330(u32 a);
extern u32 func_02045B38(u32, u32, u32, u32);
extern u32 func_02045180(u32, u32, u32, u32, u32, u32, u32);
extern u32 func_02045770(u32 a);
extern void func_02043B5C(u32 a, u32 b);
extern void func_02045334(u32 w);
extern void func_02045374(u32 w);
extern void func_0201F73C(u32 a, u32 b, u32 c, u32 d);
extern u32 func_020457B0(u32 n, u32 heap);
extern void func_02045CAC(u32, u32, u32);
extern u32 func_021904AC(u32 p);
extern void func_0201C7A4(u32, u32, u32, u32, u32);
extern void func_02041B6C(u32);
extern void func_02045808(u32);
extern void func_02045C04(u32);
extern void func_020452E8(u32);
extern void func_02041300(int, int, int, int, int, int, int);

int func_021D29F0(u32 a, u32 b)
{
    u32 *q;
    u32 heap, m, msg, win, s;

    q = func_02158F58(func_0215A5F4(b));
    heap = func_02188C84(q[1]);
    m = func_02188C54(q[1]);
    if (func_02011330(a)) {
        msg = func_02045B38(0, 2, 0x16, heap);
        win = func_02045180(2, 1, 1, 0x1E, 10, 14, 0x40);
        func_02043B5C(func_02045770(win), 0xF);
        func_02045334(win);
        func_02045374(win);
        func_0201F73C(win, 0, 1, 0xD);
        s = func_020457B0(0xB4, heap);
        func_02045CAC(msg, 3, s);
        func_0201C7A4(func_02045770(win), 0, 0, s, func_021904AC(m));
        func_02045334(win);
        func_02041B6C(2);
        func_02045808(s);
        func_02045C04(msg);
        func_020452E8(win);
    } else {
        func_02041300(2, 0, 0, 0, 0x20, 0xC, 0x11);
        func_02041B6C(2);
    }
    return 0;
}
