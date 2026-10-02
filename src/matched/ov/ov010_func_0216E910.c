/*
 * function: func_0216E910
 * address:  0x0216E910
 * packet:   pkt_ov010_0216E910
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
extern int *func_020124E8(int task);
extern void func_0216F02C(int *t, int a, int b);
extern int func_02188CE8(int a);
extern void func_021AAABC(int s);

int func_0216E910(int a0, int a1, int a2)
{
    int h;
    int *t;

    h = func_020122C0(a0, 0, func_0216EB98, 0x28);
    t = func_020124E8(h);
    func_0216F02C(t, a0, a2);
    t[5] = 0;
    t[7] = 1;
    t[6] = 1;
    t[9] = 9;
    *(u16 *)((char *)t[2] + 0x18) = 0x46b;
    func_021AAABC(func_02188CE8(a1));
    return h;
}
