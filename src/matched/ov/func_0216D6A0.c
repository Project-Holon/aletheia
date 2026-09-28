/*
 * function: func_0216D6A0
 * address:  0x0216D6A0
 * packet:   pkt_0216D6A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6B8  0x0216D6B8  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D6B8();
extern int func_02082BCC();

int func_0216D6A0(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a1 + 0;
    a0 = func_0216D6B8(a0);
loc_0216D6A8:
a1 = 0;
a2 = t5 + 0;
t4 = a0 + 0;
    a0 = func_02082BCC(a0, a1, a2);
loc_0216D6B2:
a0 = t4 + 0;
    return a0;}
