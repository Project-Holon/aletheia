/*
 * function: func_02161964
 * address:  0x02161964
 * packet:   pkt_02161964
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none: no relocation site)
 */
#include "../include/Obj12046.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int func_02161964(int a0, int a1, int a2, int a3)
{
    int t4;

t4 = 0;
loc_02161968:
a2 = t4 << 2;
a3 = a0 + a2;
a2 = ((struct Obj12046 *)a3)->f14;
    if (a2 != 0) goto loc_02161978;
loc_02161972:
((struct Obj12046 *)a3)->f14 = a1;
    return a0;
loc_02161978:
t4 = t4 + 1;
    if (t4 < 8) goto loc_02161968;
loc_0216197E:
    return a0;}
