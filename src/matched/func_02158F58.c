/*
 * function: func_02158F58
 * address:  0x02158F58
 * packet:   pkt_02158F58
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158E54  0x02158E54  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02158E54();

int func_02158F58(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a1 = *(int *)((char *)t4 + 0x10);
a0 = a0 + 0x18;
    a0 = func_02158E54(a0, a1);
loc_02158F64:
t4 = t4 + 0x18;
a0 = t4 + 0;
    return a0;}
