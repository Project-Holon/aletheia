/*
 * function: func_02167154
 * address:  0x02167154
 * packet:   pkt_02167154
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02045B38();

int func_02167154(int a0, int a1, int a2, int a3)
{
    int t4;

t4 = a0 + 0;
a3 = *(u16 *)((char *)t4);
a0 = 0;
a1 = 3;
a2 = 0x2f;
    a0 = func_02045B38(a0, a1, a2, a3);
loc_02167164:
*(int *)((char *)t4 + 0x18) = a0;
    return a0;}
