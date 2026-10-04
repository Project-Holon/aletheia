/*
 * function: func_0215F608
 * address:  0x0215F608
 * packet:   pkt_0215F608
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none: no relocation site)
 */
#include "../include/Obj17706.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int func_0215F608(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;

t5 = 0;
loc_0215F60C:
a3 = t5 << 3;
t4 = a0 + a3;
a3 = *(u16 *)((char *)a0 + a3);
    if (a1 != a3) goto loc_0215F622;
loc_0215F616:
a3 = ((struct Obj17706 *)t4)->f2;
    if (a2 != a3) goto loc_0215F622;
loc_0215F61C:
a0 = t5 + 0;
    return a0;
loc_0215F622:
t5 = t5 + 1;
    if (t5 < 0x6b) goto loc_0215F60C;
loc_0215F628:
a0 = 0;
    return a0;}
