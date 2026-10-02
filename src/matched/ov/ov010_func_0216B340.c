/*
 * function: func_0216B340
 * address:  0x0216B340
 * packet:   pkt_ov010_0216B340
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
 *   func_02012138  0x02012138  thumb
 *   func_021767A0  0x021767A0  thumb  ov011
 *   func_0216B3EC  0x0216B3EC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int a, b, c; } V12;

extern int func_020120F4();
extern int func_020122C0();
extern u8 *func_020124E8(int p);
extern void func_02082BCC();
extern int func_02012138();
extern int func_021767A0();
extern int func_0216B3EC();

int func_0216B340(int a0, int a1, V12 *a2, int a3, int a4)
{
    int h;
    int r;
    u8 *p;

    h = func_020120F4(a0);
    r = func_020122C0(a0, 0, func_0216B3EC, 0x24);
    p = func_020124E8(r);
    func_02082BCC(p, 0, 0x24);
    *(V12 *)(p + 8) = *a2;
    *(u16 *)(p + 0x14) = a3;
    *(u32 *)p = 0;
    p[0x16] = a4;
    *(int *)(p + 0x1c) = a1;
    if (func_021767A0(func_02012138(a0), h) == 4)
        *(u32 *)(p + 0x20) = 1;
    return r;
}
