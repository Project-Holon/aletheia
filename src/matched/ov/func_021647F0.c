/*
 * function: CALENDER_ClearResources
 * address:  0x021647F0
 * packet:   pkt_021647F0
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
#include "../include/Obj04133.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int CALENDER_ClearResources(int a0)
{
    int a1;

a1 = 0;
((struct Obj04133 *)((char *)a0))->f0 = a1;
*(int *)&((struct Obj04133 *)a0)->f4 = a1;
*(int *)&((struct Obj04133 *)a0)->f8 = a1;
    return a0;}
