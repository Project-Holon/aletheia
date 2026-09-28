/*
 * function: func_02167B34
 * address:  0x02167B34
 * packet:   pkt_02167B34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D5A0  0x0203D5A0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020399A8();
extern int func_0203D5A0();

int func_02167B34(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
    a0 = func_020399A8();
loc_02167B3C:
a1 = t4 + 0;
    a0 = func_0203D5A0(a0, a1);
loc_02167B42:
    return a0;}
