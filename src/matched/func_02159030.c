/*
 * function: func_02159030
 * address:  0x02159030
 * packet:   pkt_02159030
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02158FE0  0x02158FE0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020120F4();
extern int func_02158FE0();

int func_02159030(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
a0 = *(int *)((char *)t5 + 0x10);
t6 = a1 + 0;
t4 = a2 + 0;
    a0 = func_020120F4(a0, a1, a2);
loc_0215903E:
a1 = a0 + 0;
a0 = t5 + 0;
a2 = t6 + 0;
    a0 = func_02158FE0(a0, a1, a2);
loc_02159048:
    if (a0 != 0) goto loc_02159050;
loc_0215904C:
a0 = 0;
    return a0;
loc_02159050:
*(u16 *)((char *)a0) = t4;
a0 = 1;
    return a0;}
