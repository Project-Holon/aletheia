/*
 * function: func_0216E818
 * address:  0x0216E818
 * packet:   pkt_ov010_0216E818
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
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02013090  0x02013090  thumb
 *   func_021AA5CC  0x021AA5CC  thumb  ov021
 *   func_0216EE20  0x0216EE20  thumb  ov010
 *   func_02008DF0  0x02008DF0  thumb
 *   func_0216F02C  0x0216F02C  thumb  ov010
 *   func_02013144  0x02013144  thumb
 *   func_021CF748  0x021CF748  thumb  ov021
 *   func_021AAABC  0x021AAABC  thumb  ov021
 *   func_0216EB98  0x0216EB98  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0216EB98();
extern int func_020122C0(int a, int b, void (*fn)(), int c);
extern int *func_020124E8(void);
extern int func_02188CE8(int a);
extern void func_020120F4(int a);
extern int func_02012F2C(void);
extern int func_02013090(int a);
extern void func_021AA5CC(int a, int b, int c, int d, int e, int f, int g);
extern void func_0216EE20(u16 id, int col);
extern void func_02008DF0(int a, int b);
extern void func_0216F02C(int *t, int a, int b);
extern void func_02013144(int a, int b);
extern void func_021CF748(int a, int b, int c, int d);
extern void func_021AAABC(void);

int func_0216E818(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    int h;
    int *t;
    int v;
    int w;
    int x;

    h = func_020122C0(a0, 0, func_0216EB98, 0x28);
    t = func_020124E8();
    v = func_02188CE8(a1);
    func_020120F4(a0);
    w = func_02012F2C();
    x = func_02013090(4);
    func_021AA5CC(v, x, a2, a3, a4, a5, 4);
    func_0216EE20(a4, 0);
    func_02008DF0(w, 6);
    func_02008DF0(w, 0x56);
    func_0216F02C(t, a0, x);
    t[5] = 1;
    if (a6 & 1) {
        func_02013144(x, 0x100);
        t[6] = 1;
    }
    func_021CF748(a4, a1, (int)t + 0x24, t[2] + 0x18);
    func_02188CE8(a1);
    func_021AAABC();
    return h;
}
