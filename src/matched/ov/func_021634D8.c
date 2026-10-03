/*
 * function: func_021634D8
 * address:  0x021634D8
 * packet:   pkt_021634D8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02163464  0x02163464  thumb  ov010
 *   func_021AC760  0x021AC760  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02163464(int a0, int a1);
extern int func_021AC760();

void func_021634D8(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;

t4 = a1 + 0;
a1 = *(u16 *)((char *)t4 + 0xe);
t5 = a0 + 0;
a0 = 0x20;
    if ((a0 & a1) == 0) goto loc_021634FA;
loc_021634E6:
a0 = *(u16 *)((char *)t4 + 0xa);
a1 = *(u8 *)((char *)t4 + 0x18);
    a0 = func_02163464(a0, a1);
loc_021634EE:
a3 = a0 + 0;
a0 = *(int *)((char *)t4 + 0x14);
a1 = t5 + 0;
a2 = 0;
    a0 = func_021AC760(a0, a1, a2, a3);
loc_021634FA:
    return;}
