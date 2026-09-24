/*
 * function: func_0216B504
 * address:  0x0216B504
 * packet:   pkt_0216B504
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0200C224  0x0200C224  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5E4();
extern int func_02012EBC();
extern int func_0200C0F0();
extern int func_02159AE8();
extern int func_0200C224();

int func_0216B504(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215A5F4(a0);
loc_0216B510:
a0 = t4 + 0;
    a0 = func_0215A5E4(a0);
loc_0216B516:
    a0 = func_02012EBC();
loc_0216B51A:
    a0 = func_0200C0F0();
loc_0216B51E:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0216B528:
t4 = a0 + 0;
a0 = t6 + 0;
    a0 = func_0200C224(a0);
loc_0216B530:
*(u16 *)((char *)t4) = a0;
a0 = 0;
    return a0;}
