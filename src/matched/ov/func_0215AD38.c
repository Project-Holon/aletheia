/*
 * function: func_0215AD38
 * address:  0x0215AD38
 * packet:   pkt_0215AD38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5D0  0x0215A5D0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02159AE8();
extern int func_0215A5D0();

int func_0215AD38(int a0, int a1)
{
    int t4;
    int t5;

t5 = a1 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0215AD40:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0215A5D0(a0);
loc_0215AD48:
*(u16 *)((char *)t4) = a0;
a0 = 0;
    return a0;}
