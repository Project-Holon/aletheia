/*
 * function: func_021690B4
 * address:  0x021690B4
 * packet:   pkt_021690B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B14  0x02008B14  thumb
 *   func_02012984  0x02012984  thumb
 *   func_020113F0  0x020113F0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02012EBC();
extern int func_02008B14();
extern int func_02012984();
extern int func_020113F0();

int func_021690B4(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = func_02012EBC(a0);
loc_021690BC:
    a0 = func_02008B14(a0);
loc_021690C0:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02012984(a0);
loc_021690C8:
a1 = *(int *)((char *)t4 + 0x14);
    a0 = func_020113F0(a0, a1);
loc_021690CE:
    return a0;}
