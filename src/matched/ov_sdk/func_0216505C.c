/*
 * function: func_0216505C
 * address:  0x0216505C
 * packet:   pkt_0216505C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202708C  0x0202708C  thumb
 *   func_02165104  0x02165104  thumb  ov010
 *   func_02165094  0x02165094  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0202708C();
extern int func_02165104();
extern int func_02165094();

int func_0216505C(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0202708C(a0);
loc_02165064:
    if (a0 == 0) goto loc_02165070;
loc_02165068:
a0 = t4 + 0;
    a0 = func_02165104(a0);
loc_0216506E:
    return a0;
loc_02165070:
a0 = t4 + 0;
    a0 = func_02165094(a0);
loc_02165076:
    return a0;}
