/*
 * function: func_021636A8
 * address:  0x021636A8
 * packet:   pkt_021636A8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D98C  0x0216D98C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D67C();
extern int func_0216D98C();

int func_021636A8(int a0, int a1)
{
    int t4;

t4 = a1 + 0;
    a0 = func_0216D67C(a0);
loc_021636B0:
    a0 = func_0216D98C(a0);
loc_021636B4:
    if (a0 == 0) goto loc_021636C0;
loc_021636B8:
a0 = *(int *)((char *)t4 + 0x10);
a0 = *(u8 *)((char *)a0 + 4);
    if (a0 != 0) goto loc_021636C4;
loc_021636C0:
a0 = 0;
    return a0;
loc_021636C4:
a0 = 1;
    return a0;}
