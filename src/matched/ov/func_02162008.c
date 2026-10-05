/*
 * function: func_02162008
 * address:  0x02162008
 * packet:   pkt_02162008
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216210C  0x0216210C  thumb  ov010
 *   func_02162230  0x02162230  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216210C();
extern int func_02162230();

void func_02162008(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a1 + 0;
t6 = a2 + 0;
    a0 = func_0216210C();
loc_02162014:
    if (a0 != 0) goto loc_02162022;
loc_02162018:
a0 = t5 + 0;
a1 = t4 + 0;
a2 = t6 + 0;
    a0 = func_02162230(a0, a1, a2);
loc_02162022:
    return;}
