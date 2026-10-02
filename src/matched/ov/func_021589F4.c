/*
 * function: func_021589F4
 * address:  0x021589F4
 * packet:   pkt_021589F4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02014368  0x02014368  thumb
 *   func_020143D8  0x020143D8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02014368();
extern int func_020143D8();

int func_021589F4(int a0)
{
    int a1;
    int a2;
    int t4;

a1 = 0;
a2 = 0x63;
t4 = a0 + 0;
    a0 = func_02014368(a0, a1, a2);
loc_02158A00:
a1 = 1;
a1 = a1 << 0xe;
a2 = a1 + 0;
a0 = t4 + 0;
a2 = a2 + 0x1f;
    a0 = func_020143D8(a0, a1, a2);
loc_02158A0E:
    return a0;}
