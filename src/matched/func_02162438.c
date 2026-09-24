/*
 * function: func_02162438
 * address:  0x02162438
 * packet:   pkt_02162438
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215E2B8  0x0215E2B8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215E2B8();

void func_02162438(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;

t4 = a0 + 0;
t5 = a1 + 0;
a3 = a2 + 0;
a1 = *(int *)((char *)t4 + 8);
a0 = a0 + 0x38;
a2 = t5 + 0;
    a0 = func_0215E2B8(a0, a1, a2, a3);
loc_0216244A:
a0 = 1;
*(int *)((char *)t4 + 0x34) = a0;
    return;}
