/*
 * function: func_021C459C
 * address:  0x021C459C
 * packet:   pkt_ov021_021C459C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021A3364  0x021A3364  thumb  ov021
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021C1024  0x021C1024  thumb  ov021
 *   func_0215A644  0x0215A644  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 *   func_021C457C  0x021C457C  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_0215A5DC(u32 a);
extern u32 func_0201210C(void);
extern u32 func_02188CB4(void);
extern u32 func_021A3074(void);
extern u32 func_0216D5F8(void);
extern u32 func_02188C98(u32 a);
extern u32 func_0215A5CC(u32 a);
extern void func_021A3364(u32 a, u32 b, u32 *c);
extern u32 func_021AB0D4(u32 a, u32 *b);
extern u32 func_021C1024(u32 a, u32 b, u32 c, u32 d);
extern void func_0215A644(u32 a, u32 b);
extern void func_020113D0(u32 a, int (*f)(int, int));
extern int func_021C457C(int a, int b);

u32 func_021C459C(u32 a, u32 b)
{
    u32 buf[3];
    u32 x, y, z, w, t;

    func_0215A5DC(b);
    x = func_0201210C();
    y = func_02188CB4();
    func_021A3074();
    z = func_0216D5F8();
    x = func_02188C98(x);
    w = func_0215A5CC(b);
    func_021A3364(y, z, buf);
    t = func_021AB0D4(x, buf);
    t = func_021C1024(y, z, t, w);
    func_0215A644(b, t);
    func_020113D0(a, func_021C457C);
    return 1;
}
