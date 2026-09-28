/*
 * function: func_0216D98C
 * address:  0x0216D98C
 * packet:   pkt_0216D98C
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

int func_0216D98C(int a0, int a1)
{

a1 = 8;
    a0 = func_0216D4D4(a0, a1);
loc_0216D994:
    if (a0 != 0) goto loc_0216D99C;
loc_0216D998:
a0 = 1;
    return a0;
loc_0216D99C:
a0 = 0;
    return a0;}
