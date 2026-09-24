/*
 * function: func_0215A738
 * address:  0x0215A738
 * packet:   pkt_0215A738
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02197DAC  0x02197DAC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02197DAC();

int func_0215A738(int a0)
{
    int t4;
    int t5;
    int t6;
    int t7;

t4 = 0;
t5 = a0 + 0;
t7 = t4 + 0;
loc_0215A740:
a0 = *(int *)((char *)t5 + 0x20);
t6 = t4 << 2;
a0 = a0 + t6;
a0 = *(int *)((char *)a0 + 0x14);
    if (a0 == 0) goto loc_0215A756;
loc_0215A74C:
    a0 = func_02197DAC();
loc_0215A750:
a0 = *(int *)((char *)t5 + 0x20);
a0 = a0 + t6;
*(int *)((char *)a0 + 0x14) = t7;
loc_0215A756:
t4 = t4 + 1;
    if (t4 < 8) goto loc_0215A740;
loc_0215A75C:
    return a0;}
