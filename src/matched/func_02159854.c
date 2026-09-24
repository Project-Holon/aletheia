/*
 * function: func_02159854
 * address:  0x02159854
 * packet:   pkt_02159854
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02159AE8();
extern int func_02159B10();

int func_02159854(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t6 = a1 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0215985E:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10(a0, a1);
loc_02159868:
a1 = *(u16 *)((char *)t4);
a0 = a0 & a1;
*(u16 *)((char *)t4) = a0;
a0 = 0;
    return a0;}
