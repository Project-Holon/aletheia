/*
 * function: func_02167444
 * address:  0x02167444
 * packet:   pkt_02167444
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021673E0  0x021673E0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021673E0();

int func_02167444(int a0, int a1, int a2, int a3)
{
    unsigned char fr[4];
    int t4;
    int o4;
t4 = a3 + 0;
a3 = 0xa;
    o4 = a3;
a3 = 0xa;
    a0 = func_021673E0(a0, a1, a2, a3, o4);
loc_02167454:
*(u8 *)((char *)t4) = a0;
a0 = 0xa;
    return a0;
}
