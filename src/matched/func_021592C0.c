/*
 * function: func_021592C0
 * address:  0x021592C0
 * packet:   pkt_021592C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011398  0x02011398  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02011398();
extern int func_02159B10();

int func_021592C0(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_02011398(a0, a1);
loc_021592CA:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10(a0, a1);
loc_021592D2:
a0 = 0;
    return a0;}
