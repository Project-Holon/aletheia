/*
 * function: func_021671EC
 * address:  0x021671EC
 * packet:   pkt_021671EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201ED04  0x0201ED04  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0201ED04();

int func_021671EC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)((char *)t4 + 0x1c);
    a0 = func_0201ED04(a0);
loc_021671F6:
a0 = 0;
*(int *)((char *)t4 + 0x1c) = a0;
    return a0;}
