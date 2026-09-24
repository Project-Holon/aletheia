/*
 * function: func_02165D50
 * address:  0x02165D50
 * packet:   pkt_02165D50
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204581C  0x0204581C  arm
 *   func_02045994  0x02045994  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0204581C();
extern int func_02045994();

int func_02165D50(int a0, int a1, int a2)
{
    int t4;
    int t5;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0204581C(a0);
loc_02165D5C:
t5 = t5 + 0x20;
a0 = t4 + 0;
a1 = t5 + 0;
a2 = 9;
    a0 = func_02045994(a0, a1, a2);
loc_02165D68:
    return a0;}
