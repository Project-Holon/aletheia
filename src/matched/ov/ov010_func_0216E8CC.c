/*
 * function: func_0216E8CC
 * address:  0x0216E8CC
 * packet:   pkt_ov010_0216E8CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0216F02C  0x0216F02C  thumb  ov010
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAABC  0x021AAABC  thumb  ov021
 *   func_0216EB98  0x0216EB98  thumb  ov010
 */

typedef unsigned short u16;

extern void func_0216EB98();
extern int func_020122C0(int a, int b, void (*fn)(), int c);
extern int *func_020124E8(void);
extern void func_0216F02C(int *t, int a, int b);
extern int func_02188CE8(int a);
extern void func_021AAABC(void);

int func_0216E8CC(int a0, int a1, int a2)
{
    int h;
    int *t;

    h = func_020122C0(a0, 0, func_0216EB98, 0x28);
    t = func_020124E8();
    func_0216F02C(t, a0, a2);
    t[5] = 0;
    t[6] = 1;
    t[8] = 1;
    t[9] = 9;
    func_02188CE8(a1);
    func_021AAABC();
    return h;
}
