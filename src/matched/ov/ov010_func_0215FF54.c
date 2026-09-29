/*
 * function: func_0215FF54
 * address:  0x0215FF54
 * packet:   pkt_ov010_0215FF54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C404  0x0200C404  thumb
 *   func_0200C468  0x0200C468  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_020355D8  0x020355D8  arm
 *   func_0216025C  0x0216025C  thumb  ov010
 *   func_02160018  0x02160018  thumb  ov010
 *   d_02172960     0x02172960  data  a4
 *   func_02160668  0x02160668  thumb  ov010
 *   func_021606D0  0x021606D0  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_020120F4();
extern int func_02012EBC();
extern int func_0200C404();
extern int func_0200C468();
extern int func_020122C0();
extern u32 *func_020124E8();
extern void func_02082BCC();
extern u32 *func_02030734();
extern void func_02188C7C();
extern void func_0216D9A0();
extern void func_020355D8();
extern void func_0216025C();
extern void func_02160018();
extern u8 d_02172960[];
extern void func_02160668();
extern void func_021606D0();

int func_0215FF54(int a0, int a1, u16 a2)
{
    int sp8;
    int r5;
    u32 *p;

    func_020120F4(a0);
    func_02012EBC();
    sp8 = func_0200C404();
    if (func_0200C468() == 1) {
        r5 = func_020122C0(a0, 0, func_0216025C, 0x20);
    } else {
        r5 = func_020122C0(a0, 0, func_02160018, 0x20);
    }
    p = func_020124E8(r5);
    func_02082BCC(p, 0, 0x20);
    p[1] = a0;
    p[0] = r5;
    p[2] = a1;
    *(u16 *)((u8 *)p + 0x14) = a2;
    p[6] = 0;
    p[4] = (u32)func_02030734(4, 0x40, 0, d_02172960, 0xc2);
    func_02082BCC(p[4], 0, 0x40);
    ((u32 *)p[4])[0] = p[1];
    ((u32 *)p[4])[1] = p[2];
    ((u32 *)p[4])[2] = r5;
    if (func_0200C468(sp8) != 1) {
        ((u32 *)p[4])[5] = (u32)func_02160668;
        ((u32 *)p[4])[6] = (u32)func_021606D0;
        ((u32 *)p[4])[8] = (u32)p;
    }
    func_02188C7C(p[2]);
    func_0216D9A0();
    func_020355D8(0);
    return r5;
}
