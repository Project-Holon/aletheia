/*
 * function: func_0216DA30
 * address:  0x0216DA30
 * packet:   pkt_0216DA30
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D55C  0x0216D55C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D55C();

int func_0216DA30(int a0, int a1)
{
    int t4;

a1 = 1;
t4 = 1;
    a0 = func_0216D55C(a0, a1);
loc_0216DA3A:
    if (a0 != 0) goto loc_0216DA40;
loc_0216DA3E:
t4 = 0;
loc_0216DA40:
a0 = t4 + 0;
    return a0;}
