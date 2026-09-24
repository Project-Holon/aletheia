/*
 * function: func_0215CC38
 * address:  0x0215CC38
 * packet:   pkt_0215CC38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5DC();

int func_0215CC38(int a0, int a1)
{
    int t4;

t4 = a1 + 0;
a0 = t4 + 0;
    a0 = func_0215A5F4(a0);
loc_0215CC42:
a0 = t4 + 0;
    a0 = func_0215A5DC(a0);
loc_0215CC48:
a0 = 1;
    return a0;}
