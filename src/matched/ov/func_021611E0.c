/*
 * function: func_021611E0
 * address:  0x021611E0
 * packet:   pkt_021611E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02012134  0x02012134  thumb
 *   func_02029DD8  0x02029DD8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020120F4();
extern int func_02012A30();
extern int func_02012134();
extern int func_02029DD8();

int func_021611E0(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
a0 = *(int *)((char *)t5 + 0x18);
t4 = a1 + 0;
a0 = *(int *)((char *)a0);
    a0 = func_020120F4(a0);
loc_021611EE:
    a0 = func_02012A30(a0);
loc_021611F2:
t6 = a0 + 0;
a0 = *(int *)((char *)t5 + 0x18);
a0 = *(int *)((char *)a0);
    a0 = func_02012134(a0);
loc_021611FC:
a1 = a0 + 0;
a0 = t6 + 0;
    a0 = func_02029DD8(a0, a1);
loc_02161204:
a0 = *(int *)((char *)t4 + 0x10);
    if (a0 != 1) goto loc_0216120E;
loc_0216120A:
a0 = 1;
    return a0;
loc_0216120E:
a0 = 0;
    return a0;}
