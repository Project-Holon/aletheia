/*
 * function: func_0215C6F0
 * address:  0x0215C6F0
 * packet:   pkt_0215C6F0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158FBC  0x02158FBC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_02158FBC();

int func_0215C6F0(int a0, int a1)
{

a0 = a1 + 0;
    a0 = func_0215A5F4(a0);
loc_0215C6F8:
    a0 = func_02158FBC(a0);
loc_0215C6FC:
a0 = 1;
    return a0;}
