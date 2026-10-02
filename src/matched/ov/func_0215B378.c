/*
 * function: func_0215B378
 * address:  0x0215B378
 * packet:   pkt_0215B378
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A4D8  0x0215A4D8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5E4();
extern int func_0201296C(int a0);
extern int func_02159B10();
extern int func_02159AE8();
extern int func_0215A4D8();

int func_0215B378(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215A5E4(a0);
loc_0215B384:
    a0 = func_0201296C(a0);
loc_0215B388:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10(a0, a1);
loc_0215B392:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0215B39C:
t4 = a0 + 0;
a0 = t6 + 0;
a1 = t7 + 0;
    a0 = func_0215A4D8(a0, a1);
loc_0215B3A6:
*(u16 *)((char *)t4) = a0;
a0 = 0;
    return a0;}
