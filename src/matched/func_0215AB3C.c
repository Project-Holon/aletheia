/*
 * function: func_0215AB3C
 * address:  0x0215AB3C
 * packet:   pkt_0215AB3C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021690F0  0x021690F0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5E4();
extern int func_02159AE8();
extern int func_021690F0();

int func_0215AB3C(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    a0 = func_0215A5E4(a0);
loc_0215AB48:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0215AB52:
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_021690F0(a0);
loc_0215AB5A:
*(u16 *)((char *)t5) = a0;
a0 = 0;
    return a0;}
