/*
 * function: func_02161F00
 * address:  0x02161F00
 * packet:   pkt_02161F00
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02082BCC();

int func_02161F00(int a0, int a1, int a2)
{
    int t4;

a1 = 0;
a2 = 4;
t4 = a0 + 0;
    a0 = func_02082BCC(a0, a1, a2);
loc_02161F0C:
a0 = 0xa;
*(u16 *)((char *)t4 + 2) = a0;
    return a0;}
