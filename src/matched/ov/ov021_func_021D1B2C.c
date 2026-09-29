/*
 * function: func_021D1B2C
 * address:  0x021D1B2C
 * packet:   pkt_ov021_021D1B2C
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
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021D1AEC  0x021D1AEC  thumb  ov021
 *   d_021DD608     0x021DD608  data  a4
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159144  0x02159144  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 d_021DD608[];

extern u32 func_0215A5F4(u32 b);
extern u32 func_02158F58(void);
extern u32 func_02159B10(u32 a, u32 b);
extern u32 func_02188CCC(u32 a);
extern u32 func_0215A5DC(u32 b);
extern u32 func_020122C0(u32 a, u32 b, void *c, u32 d);
extern u32 *func_020124E8(void);
extern int func_021D1AEC(int a, int *seq, u32 *c);
extern void func_0215897C(u32 a, u32 b);
extern void func_02159144(u32 a);

int func_021D1B2C(u32 a, u32 b)
{
    u32 r7, r4, r5, r6;
    u32 *p;

    r7 = func_0215A5F4(b);
    r4 = func_02158F58();
    r5 = func_02159B10(a, b);
    r4 = func_02188CCC(((u32 *)r4)[1]);
    r6 = func_0215A5DC(b);
    r6 = func_020122C0(r6, 0, func_021D1AEC, 8);
    p = func_020124E8();
    r5 = d_021DD608[r5];
    p[0] = r4;
    p[1] = r5;
    func_0215897C(r7, r6);
    func_02159144(8);
    return 1;
}
