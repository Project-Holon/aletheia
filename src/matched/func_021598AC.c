/*
 * function: func_021598AC
 * address:  0x021598AC
 * packet:   pkt_021598AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02159AE8();

int func_021598AC(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t6 = a1 + 0;
    a0 = func_02159AE8(a0, a1);
loc_021598B6:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159AE8(a0, a1);
loc_021598C0:
a0 = *(u16 *)((char *)a0);
*(u16 *)((char *)t4) = a0;
a0 = 0;
    return a0;}
