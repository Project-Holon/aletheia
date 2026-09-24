/*
 * function: func_02159894
 * address:  0x02159894
 * packet:   pkt_02159894
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02011330  0x02011330  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02159AE8();
extern int func_02011330();

int func_02159894(int a0)
{
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = func_02159AE8();
loc_0215989C:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02011330(a0);
loc_021598A4:
*(u16 *)((char *)t4) = a0;
a0 = 0;
    return a0;}
