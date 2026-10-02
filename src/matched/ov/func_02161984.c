/*
 * function: func_02161984
 * address:  0x02161984
 * packet:   pkt_02161984
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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

int func_02161984(int a0)
{
    int t4;
    int t5;
    int t6;
    int t7;

t6 = a0 + 0;
t7 = 0;
t4 = 0;
loc_0216198C:
a0 = t4 << 2;
t5 = t6 + a0;
a0 = *(int *)((char *)t5 + 0x14);
    if (a0 == 0) goto loc_021619AC;
loc_02161996:
    a0 = func_02197DA0(a0);
loc_0216199A:
    if (a0 != 1) goto loc_021619AA;
loc_0216199E:
a0 = *(int *)((char *)t5 + 0x14);
    a0 = func_02197DAC(a0);
loc_021619A4:
a0 = 0;
*(int *)((char *)t5 + 0x14) = a0;
    goto loc_021619AC;
loc_021619AA:
t7 = 1;
loc_021619AC:
t4 = t4 + 1;
    if (t4 < 8) goto loc_0216198C;
loc_021619B2:
a0 = t7 + 0;
    return a0;}
