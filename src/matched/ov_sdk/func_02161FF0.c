/*
 * function: func_02161FF0
 * address:  0x02161FF0
 * packet:   pkt_02161FF0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216210C  0x0216210C  thumb  ov010
 *   func_0216220C  0x0216220C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216210C(int a0);
extern int func_0216220C();

void func_02161FF0(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_0216210C(a0);
loc_02161FFA:
    if (a0 != 0) goto loc_02162006;
loc_02161FFE:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216220C(a0, a1);
loc_02162006:
    return;}
