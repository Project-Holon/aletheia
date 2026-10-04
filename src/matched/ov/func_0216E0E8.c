/*
 * function: func_0216E0E8
 * address:  0x0216E0E8
 * packet:   pkt_0216E0E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D71C  0x0216D71C  thumb  ov010
 *   func_0216D59C  0x0216D59C  thumb  ov010
 *   func_0216D230  0x0216D230  thumb  ov010
 *   func_0216D268  0x0216D268  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0216D67C(void *a0);
extern int func_0216D71C();
extern int func_0216D59C();
extern int func_0216D230(int a0);
extern int func_0216D268(int a0, int a1);

int func_0216E0E8(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = (int)func_0216D67C((void *)a0);
loc_0216E0F2:
t6 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0216D71C(a0);
loc_0216E0FA:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216D59C(a0, a1);
loc_0216E102:
a0 = t5 + 0;
    a0 = func_0216D230(a0);
loc_0216E108:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = func_0216D268(a0, a1);
loc_0216E110:
    return a0;}
