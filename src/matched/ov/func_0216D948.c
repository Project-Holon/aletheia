/*
 * function: func_0216D948
 * address:  0x0216D948
 * packet:   pkt_0216D948
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D4D4  0x0216D4D4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D4D4();

int func_0216D948(int a0, int a1)
{
    int t4;

a1 = 1;
t4 = 1;
    a0 = func_0216D4D4(a0, a1);
loc_0216D952:
    if (a0 != 0) goto loc_0216D958;
loc_0216D956:
t4 = 0;
loc_0216D958:
a0 = t4 + 0;
    return a0;}
