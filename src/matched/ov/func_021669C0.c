/*
 * function: func_021669C0
 * address:  0x021669C0
 * packet:   pkt_021669C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 64 compiled 62
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02166834  0x02166834  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5DC();
extern int func_020120F4();
extern int func_02012F38();
extern int func_02159B10();
extern int func_02159AE8();
extern int func_02166834();

int func_021669C0(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215A5F4(a0);
loc_021669CC:
a0 = t4 + 0;
    a0 = func_0215A5DC(a0);
loc_021669D2:
    a0 = func_020120F4(a0);
loc_021669D6:
    a0 = func_02012F38(a0);
loc_021669DA:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10(a0, a1);
loc_021669E4:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159AE8(a0, a1);
loc_021669EE:
t4 = a0 + 0;
a0 = t6 + 0;
a1 = t7 + 0;
    a0 = func_02166834(a0, a1);
loc_021669F8:
*(u16 *)((char *)t4) = a0;
a0 = 0;
    return a0;}
