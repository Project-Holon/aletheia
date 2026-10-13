/*
 * function: FLDMMDL_SysSetStatusBit
 * address:  0x0216D4DC
 * packet:   pkt_0216D4DC
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
#include "../include/Obj12057.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int FLDMMDL_SysSetStatusBit(int a0, int a1, int a2)
{

a2 = ((struct Obj12057 *)((char *)a0))->f0;
a1 = a1 | a2;
((struct Obj12057 *)((char *)a0))->f0 = a1;
    return a0;}
