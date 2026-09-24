/*
 * function: func_0215AA24
 * address:  0x0215AA24
 * packet:   pkt_0215AA24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215909C  0x0215909C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215909C();

int func_0215AA24(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0215A5F4();
loc_0215AA2C:
    a0 = func_0215909C();
loc_0215AA30:
*(int *)((char *)t4 + 0x1c) = a0;
    return a0;}
