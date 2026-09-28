/*
 * function: func_02156914
 * address:  0x02156914
 * packet:   pkt_02156914
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045C44  0x02045C44  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02045C44();
extern int func_02045EC0();
extern int func_02045C04();

int func_02156914(int a0, int a1)
{
    int t4;
    int t5;

a0 = *(int *)((char *)a0 + 0x24);
a0 = *(int *)((char *)a0 + 8);
    a0 = func_02045C44(a0, a1);
loc_0215691E:
t5 = a0 + 0;
a1 = 0;
    a0 = func_02045EC0(a0, a1);
loc_02156926:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02045C04(a0);
loc_0215692E:
a0 = t4 + 0;
    return a0;}
