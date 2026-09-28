/*
 * function: func_02169580
 * address:  0x02169580
 * packet:   pkt_02169580
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02169A68  0x02169A68  thumb  ov010
 *   func_02169928  0x02169928  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02169A68();
extern int func_02169928();

int func_02169580(int a0, int a1, int a2)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02169A68(a0);
loc_02169588:
a2 = a0 + 0;
a0 = *(int *)((char *)t4 + 0x2c);
t4 = t4 + 0x84;
a1 = *(int *)((char *)t4);
    a0 = func_02169928(a0, a1, a2);
loc_02169594:
    return a0;}
