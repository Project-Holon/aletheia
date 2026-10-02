/*
 * function: func_0216AF74
 * address:  0x0216AF74
 * packet:   pkt_ov010_0216AF74
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020173EC  0x020173EC  thumb
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E2BC  0x0200E2BC  thumb
 *   func_021AA304  0x021AA304  thumb
 *   func_0216B004  0x0216B004  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020120F4();
extern int func_020122C0();
extern u8 *func_020124E8(int p);
extern void func_02082BCC();
extern int func_020173EC();
extern int func_0203F1FC();
extern int func_02012EBC();
extern int func_0200E2BC();
extern void func_021AA304();
extern int func_0216B004();

int func_0216AF74(int a0, int a1, int a2, int a3, int a4, u16 a5)
{
    int h;
    int r;
    u8 *p;

    h = func_020120F4(a0);
    r = func_020122C0(a0, 0, func_0216B004, 0x3C);
    p = func_020124E8(r);
    func_02082BCC(p, 0, 0x3C);
    *(int *)p = a1;
    *(int *)(p + 0x28) = a4;
    *(u16 *)(p + 0x24) = a5;
    *(int *)(p + 0xC) = a2;
    *(int *)(p + 0x20) = a3;
    *(u16 *)(p + 0x2C) = func_0203F1FC(a2, func_020173EC());
    if (func_0200E2BC(func_02012EBC(h), &a3, a5, 0) == 0)
        *(u32 *)(p + 0x20) = (*(u32 *)(p + 0x20) & 0xFFFFF800) | 0x28B;
    func_021AA304(p + 0x10, h, a1);
    return r;
}
