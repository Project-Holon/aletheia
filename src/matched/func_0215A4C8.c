/*
 * function: func_0215A4C8
 * address:  0x0215A4C8
 * packet:   pkt_0215A4C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202A230  0x0202A230  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0202A230();

int func_0215A4C8(int a0, int a1)
{

a1 = 2;
    a0 = func_0202A230(a0, a1);
loc_0215A4D0:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    return a0;}
