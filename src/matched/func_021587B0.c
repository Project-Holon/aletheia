/*
 * function: func_021587B0
 * address:  0x021587B0
 * packet:   pkt_021587B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02158920  0x02158920  thumb  ov010
 *   func_020124E8  0x020124E8  thumb
 *   func_0201235C  0x0201235C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020124E4();
extern int func_02158920();
extern int func_020124E8();
extern int func_0201235C();

int func_021587B0(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int t6;
    int t7;
    int o4;
t7 = a0 + 0;
t5 = a1 + 0;
t4 = a2 + 0;
t6 = a3 + 0;
    a0 = func_020124E4(a0);
loc_021587BE:
a1 = 0;
    o4 = a1;
a1 = t6 + 0;
a2 = t5 + 0;
a3 = t4 + 0;
    a0 = func_02158920(a0, a1, a2, a3, o4);
loc_021587CC:
t5 = a0 + 0;
    a0 = func_020124E8();
loc_021587D2:
t4 = a0 + 0;
a0 = t7 + 0;
a1 = t5 + 0;
    a0 = func_0201235C(a0, a1);
loc_021587DC:
a0 = *(int *)((char *)t4);
    return a0;
}
