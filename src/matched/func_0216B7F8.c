/*
 * function: func_0216B7F8
 * address:  0x0216B7F8
 * packet:   pkt_0216B7F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_021670F8  0x021670F8  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5DC();
extern int func_021670F8();
extern int func_0215897C();

int func_0216B7F8(int a0, int a1)
{
    int t4;
    int t5;

t5 = a1 + 0;
a0 = t5 + 0;
    a0 = func_0215A5F4(a0);
loc_0216B802:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0215A5DC(a0);
loc_0216B80A:
    a0 = func_021670F8();
loc_0216B80E:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215897C(a0, a1);
loc_0216B816:
a0 = 1;
    return a0;}
