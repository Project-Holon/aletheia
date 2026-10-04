/*
 * function: func_02167168
 * address:  0x02167168
 * packet:   pkt_02167168
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045C04  0x02045C04  arm
 */
#include "../include/Obj00565.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02045C04();

int func_02167168(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)&((struct Obj00565 *)t4)->f18;
    a0 = func_02045C04(a0);
loc_02167172:
a0 = 0;
*(int *)&((struct Obj00565 *)t4)->f18 = a0;
    return a0;}
