/*
 * function: func_0215FBF4
 * address:  0x0215FBF4
 * packet:   pkt_ov010_0215FBF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_0201232C  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0215FA54  0x0215FA54  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02188CCC();
extern int func_020122C0();
extern void func_0201232C();
extern u32 *func_020124E8();
extern int func_020120F4();
extern int func_02012EBC();
extern void func_0215FA54();

int func_0215FBF4(int a0, int a1, int a2, int a3)
{
    u32 *p;
    int t;

    func_02188CCC(a1);
    if (a3 != 0) {
        a2 = func_020122C0(a0, 0, func_0215FA54, 0x34);
    } else {
        func_0201232C(a2, func_0215FA54, 0x34);
    }
    p = func_020124E8(a2);
    t = func_020120F4(a0);
    p[1] = t;
    p[2] = func_02012EBC(t);
    p[0] = a0;
    return a2;
}
