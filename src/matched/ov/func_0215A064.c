/*
 * function: func_0215A064
 * address:  0x0215A064
 * packet:   pkt_0215A064
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159F84  0x02159F84  thumb  ov010
 *   func_02159F80  0x02159F80  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02159F84();
extern int func_02159F80();

int func_0215A064(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02159F84(a0);
loc_0215A06C:
    if (a0 != 0) goto loc_0215A076;
loc_0215A070:
    a0 = func_02159F80();
loc_0215A074:
t4 = a0 + 0;
loc_0215A076:
a0 = t4 - 1;
    return a0;}
