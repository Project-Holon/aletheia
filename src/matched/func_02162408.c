/*
 * function: func_02162408
 * address:  0x02162408
 * packet:   pkt_02162408
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021623DC  0x021623DC  thumb  ov010
 *   func_0216242C  0x0216242C  thumb  ov010
 *   func_02162438  0x02162438  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021623DC();
extern int func_0216242C();
extern int func_02162438();

int func_02162408(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a1 + 0;
t6 = a2 + 0;
    a0 = func_021623DC();
loc_02162414:
a0 = t5 + 0;
a1 = t4 + 0;
a2 = t6 + 0;
    a0 = func_0216242C(a0, a1, a2);
loc_0216241E:
a0 = t5 + 0;
a1 = t4 + 0;
a2 = t6 + 0;
    a0 = func_02162438(a0, a1, a2);
loc_02162428:
    return a0;}
