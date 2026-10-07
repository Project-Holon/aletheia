/*
 * function: func_02159C2C
 * address:  0x02159C2C
 * packet:   pkt_02159C2C
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
#include "../../../matched/include/Obj12037.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int func_02159C2C(int a0, int a1, int a2, int a3)
{

    if (a2 < 0) goto loc_02159C44;
loc_02159C30:
a3 = ((struct Obj12037 *)a0)->fA;
    if (a2 >= a3) goto loc_02159C44;
loc_02159C36:
    if (a1 < 0) goto loc_02159C44;
loc_02159C3A:
a0 = ((struct Obj12037 *)a0)->f8;
    if (a1 >= a0) goto loc_02159C44;
loc_02159C40:
a0 = 1;
    return a0;
loc_02159C44:
a0 = 0;
    return a0;}
