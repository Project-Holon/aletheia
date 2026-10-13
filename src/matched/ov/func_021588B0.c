/*
 * function: SCRIPT_SYS_CallEndCallback
 * address:  0x021588B0
 * packet:   pkt_021588B0
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
#include "../include/Obj00105.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int SCRIPT_SYS_CallEndCallback(int a0, int a1, int a2)
{

a2 = a0 + 0;
a0 = a1 + 0;
a1 = *(int *)&((struct Obj00105 *)a2)->f14;
a2 = *(int *)&((struct Obj00105 *)a2)->f10;
    a0 = ((int (*)())a2)(a0, a1, a2);
loc_021588BC:
    return a0;}
