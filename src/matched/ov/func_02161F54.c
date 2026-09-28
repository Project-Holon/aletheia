/*
 * function: func_02161F54
 * address:  0x02161F54
 * packet:   pkt_02161F54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02039338  0x02039338  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02082BCC();
extern int func_02039338();

int func_02161F54(int a0, int a1, int a2)
{
    int t4;

a1 = 0;
a2 = 0x48;
t4 = a0 + 0;
    a0 = func_02082BCC(a0, a1, a2);
loc_02161F60:
    a0 = func_02039338();
loc_02161F64:
*(u16 *)((char *)t4) = a0;
    return a0;}
