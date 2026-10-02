/*
 * function: func_021621E8
 * address:  0x021621E8
 * packet:   pkt_021621E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02161DC4  0x02161DC4  thumb  ov010
 *   func_02161E78  0x02161E78  thumb  ov010
 *   func_02161E60  0x02161E60  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02161DC4();
extern int func_02161E78();
extern int func_02161E60();

int func_021621E8(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a1 + 0;
a1 = *(u16 *)((char *)a2 + 4);
a0 = t5 + 0;
a2 = 1;
t4 = 1;
    a0 = func_02161DC4(a0, a1, a2);
loc_021621F8:
    if (a0 == 0) goto loc_02162208;
loc_021621FC:
    a0 = func_02161E78(a0);
loc_02162200:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02161E60(a0, a1);
loc_02162208:
a0 = 0;
    return a0;}
