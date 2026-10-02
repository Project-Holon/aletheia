/*
 * function: func_0216E7C8
 * address:  0x0216E7C8
 * packet:   pkt_ov010_0216E7C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates a 0x10-byte task record (handler func_0216E68C) and fills it
 * from the arguments.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0216E68C  0x0216E68C  thumb  ov010
 *   func_0216EE40  0x0216EE40  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAABC  0x021AAABC  thumb  ov021
 */

typedef unsigned int u32;

extern void func_0216E68C();
extern int func_020122C0(int a, int b, void (*fn)(), int c);
extern u32 *func_020124E8(int task);
extern void func_0216EE40(int a, int b);
extern int func_020120F4(int a);
extern int func_02012F2C(int p);
extern void func_02008DF0(int a, int b);
extern int func_02188CE8(int a);
extern void func_021AAABC(int s);

int func_0216E7C8(int a0, int a1, int a2, int a3, int a4)
{
    int h;
    u32 *t;

    h = func_020122C0(a0, 0, func_0216E68C, 0x10);
    t = func_020124E8(h);
    t[0] = a0;
    t[1] = a2;
    t[2] = a3;
    t[3] = a4;
    func_0216EE40(a2, 0);
    func_02008DF0(func_02012F2C(func_020120F4(a0)), 5);
    func_021AAABC(func_02188CE8(a1));
    return h;
}
