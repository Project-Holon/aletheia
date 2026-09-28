/*
 * function: func_0215F2B8
 * address:  0x0215F2B8
 * packet:   pkt_0215F2B8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0201214C  0x0201214C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5DC();
extern int func_02159AE8();
extern int func_0201214C();

int func_0215F2B8(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    a0 = func_0215A5DC(a0);
loc_0215F2C4:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0215F2CE:
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0201214C(a0);
loc_0215F2D6:
*(u16 *)((char *)t5) = a0;
a0 = 0;
    return a0;}
