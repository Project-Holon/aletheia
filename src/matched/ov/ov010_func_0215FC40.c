/*
 * function: func_0215FC40
 * address:  0x0215FC40
 * packet:   pkt_ov010_0215FC40
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
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0215FD0C  0x0215FD0C  thumb  ov010
 *   func_0215FED4  0x0215FED4  thumb  ov010
 *   func_0215FEF0  0x0215FEF0  thumb  ov010
 *   func_0215FEF4  0x0215FEF4  thumb  ov010
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_021A0EE4  0x021A0EE4  thumb  ov021
 *   func_020355D8  0x020355D8  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_02188CCC();
extern int func_020122C0();
extern u32 *func_020124E8();
extern void func_02082BCC();
extern void func_0215FD0C();
extern void func_0215FED4();
extern void func_0215FEF0();
extern void func_0215FEF4();
extern int func_021A0F90();
extern int func_021A0EE4();
extern void func_020355D8();

int func_0215FC40(int a0, int a1, u16 a2)
{
    int x;
    int sz = 0x5c;
    int r7;
    u32 *p;
    int r;

    x = func_02188CCC(a1);
    r7 = func_020122C0(a0, 0, func_0215FD0C, sz);
    p = func_020124E8(r7);
    func_02082BCC(p, 0, sz);
    p[2] = a0;
    p[1] = r7;
    p[3] = a1;
    *(u16 *)p = a2;
    p[5] = 0;
    p[7] = a0;
    p[8] = a1;
    p[9] = r7;
    p[12] = (u32)func_0215FED4;
    p[13] = (u32)func_0215FEF0;
    p[14] = (u32)func_0215FEF4;
    p[15] = (u32)p;
    p[11] = sz - 0x5d;
    r = func_021A0F90(x);
    switch (r) {
    case 3:
        r = 3;
        break;
    case 4:
        r = 4;
        break;
    default:
        r = func_021A0EE4(func_02188CCC(p[3]), 0);
        break;
    }
    p[6] = r;
    func_020355D8(1);
    return r7;
}
