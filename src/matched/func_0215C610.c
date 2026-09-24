/*
 * function: func_0215C610
 * address:  0x0215C610
 * packet:   pkt_0215C610
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
 *   func_0201210C  0x0201210C  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5DC();
extern int func_0201210C();
extern int func_020144DC();
extern int func_0215897C();

int func_0215C610(int a0, int a1)
{
    int t4;
    int t5;

t4 = a1 + 0;
a0 = t4 + 0;
    a0 = func_0215A5F4(a0);
loc_0215C61A:
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215A5DC(a0);
loc_0215C622:
t4 = a0 + 0;
    a0 = func_0201210C();
loc_0215C628:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_020144DC(a0, a1);
loc_0215C630:
a1 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0215897C(a0, a1);
loc_0215C638:
a0 = 1;
    return a0;}
