/*
 * function: func_02159A64
 * address:  0x02159A64
 * packet:   pkt_ov010_02159A64
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C84  0x02188C84  thumb
 *   func_02188CCC  0x02188CCC  thumb
 *   func_021D1164  0x021D1164  thumb
 *   func_021D11B0  0x021D11B0  thumb
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_021A1524  0x021A1524  thumb  ov021
 *   func_021A1530  0x021A1530  thumb  ov021
 *   func_021590F4  0x021590F4  thumb  ov010
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02012DAC  0x02012DAC  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_021599A8  0x021599A8  thumb  ov010
 */

extern void *func_0215A5E4(void *a0);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
typedef unsigned int   u32;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188C84(void *);
extern int func_02188CCC(void *);
extern int func_021D1164(int, void *);
extern void func_021D11B0(int);
extern int func_021A0F90(int);
extern void func_021A1524(int);
extern void func_021A1530(int);
extern void func_021590F4(void *p, u32 v);
extern int func_02012F2C(void *);
extern void func_02008DF0(int, int);
extern void func_02012DAC(void *);
extern void func_020113D0(int, int (*)(int, int));
extern int func_021599A8(int, int);

int func_02159A64(int a, int b)
{
    void *s0 = func_0215A5F4((void *)b);
    void *s4 = func_0215A5E4((void *)b);
    int y, z, t;
    void *x;
    x = func_0201210C(func_0215A5DC((void *)b));
    y = func_02188C84(x);
    z = func_02188CCC(x);
    t = func_021D1164(y, x);
    func_021D11B0(t);
    if (func_021A0F90(z) == 7) {
        func_021A1524(z);
        func_021A1530(z);
    }
    func_021590F4(s0, t);
    func_02008DF0(func_02012F2C(s4), 1);
    func_02012DAC(s4);
    func_020113D0(a, func_021599A8);
    return 1;
}
