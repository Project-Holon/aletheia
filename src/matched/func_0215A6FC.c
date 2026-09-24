/*
 * function: func_0215A6FC
 * address:  0x0215A6FC
 * packet:   pkt_0215A6FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02197DA0  0x02197DA0  thumb
 *   func_02197DAC  0x02197DAC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02197DA0();
extern int func_02197DAC();

int func_0215A6FC(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;

t5 = a0 + 0;
t7 = 0;
t4 = 0;
loc_0215A704:
a0 = *(int *)((char *)t5 + 0x20);
t6 = t4 << 2;
a0 = a0 + t6;
a0 = *(int *)((char *)a0 + 0x14);
    if (a0 == 0) goto loc_0215A72E;
loc_0215A710:
    a0 = func_02197DA0();
loc_0215A714:
    if (a0 != 1) goto loc_0215A72C;
loc_0215A718:
a0 = *(int *)((char *)t5 + 0x20);
a0 = a0 + t6;
a0 = *(int *)((char *)a0 + 0x14);
    a0 = func_02197DAC(a0);
loc_0215A722:
a0 = *(int *)((char *)t5 + 0x20);
a1 = a0 + t6;
a0 = 0;
*(int *)((char *)a1 + 0x14) = a0;
    goto loc_0215A72E;
loc_0215A72C:
t7 = 1;
loc_0215A72E:
t4 = t4 + 1;
    if (t4 < 8) goto loc_0215A704;
loc_0215A734:
a0 = t7 + 0;
    return a0;}
