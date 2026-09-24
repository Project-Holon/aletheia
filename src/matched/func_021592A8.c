/*
 * function: func_021592A8
 * address:  0x021592A8
 * packet:   pkt_021592A8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5E4();
extern int func_02159B10();

int func_021592A8(int a0, int a1)
{
    int t4;
    int t5;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215A5E4(a0);
loc_021592B4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10(a0, a1);
loc_021592BC:
a0 = 0;
    return a0;}
