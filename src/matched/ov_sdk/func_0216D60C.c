/*
 * function: func_0216D60C
 * address:  0x0216D60C
 * packet:   pkt_0216D60C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D600  0x0216D600  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D5E0();
extern int func_0216D600(int a0, int a1);

int func_0216D60C(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_0216D5E0(a0, a1);
loc_0216D616:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216D600(a0, a1);
loc_0216D61E:
    return a0;}
