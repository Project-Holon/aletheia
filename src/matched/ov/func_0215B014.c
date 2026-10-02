/*
 * function: func_0215B014
 * address:  0x0215B014
 * packet:   pkt_0215B014
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA40  0x0200CA40  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5E4();
extern int func_0200CA1C();
extern int func_0200CA40();

int func_0215B014(int a0, int a1)
{

a0 = a1 + 0;
    a0 = func_0215A5E4(a0);
loc_0215B01C:
    a0 = func_0200CA1C(a0);
loc_0215B020:
    a0 = func_0200CA40(a0);
loc_0215B024:
a0 = 0;
    return a0;}
