/*
 * function: func_0215EC54
 * address:  0x0215EC54
 * packet:   pkt_0215EC54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02165534  0x02165534  thumb  ov010
 *   func_021C8268  0x021C8268  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02165534();
extern int func_021C8268();

int func_0215EC54(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
a0 = 0x13;
    a0 = func_02165534(a0);
loc_0215EC60:
a0 = *(int *)((char *)t4 + 8);
a1 = *(int *)((char *)t4 + 0x10);
a2 = *(int *)((char *)t5 + 4);
    a0 = func_021C8268(a0, a1, a2);
loc_0215EC6A:
    return a0;}
