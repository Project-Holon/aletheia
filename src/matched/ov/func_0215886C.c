/*
 * function: SCRIPT_SYS_AddVm
 * address:  0x0215886C
 * packet:   pkt_0215886C
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
#include "../include/Obj09153.h"
#include "../include/Obj12029.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int SCRIPT_SYS_AddVm(int a0, int a1)
{
    int a2;
    int a3;
    int t4;

t4 = 0;
loc_02158870:
a2 = t4 << 2;
a3 = a0 + a2;
a2 = ((struct Obj12029 *)a3)->f4;
    if (a2 != 0) goto loc_02158888;
loc_0215887A:
((struct Obj12029 *)a3)->f4 = a1;
a1 = ((struct Obj09153 *)a0)->f2;
a1 = a1 + 1;
((struct Obj09153 *)a0)->f2 = a1;
a0 = t4 + 0;
    return a0;
loc_02158888:
t4 = t4 + 1;
    if (t4 < 3) goto loc_02158870;
loc_0215888E:
a0 = 3;
    return a0;}
