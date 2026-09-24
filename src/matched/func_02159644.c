/*
 * function: func_02159644
 * address:  0x02159644
 * packet:   pkt_02159644
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02011290  0x02011290  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_02011290();

int func_02159644(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = a1 + 0;
    a0 = func_0215A5F4(a0);
loc_0215964E:
a0 = t4 + 0;
    a0 = func_02011290(a0);
loc_02159654:
a0 = 1;
    return a0;}
