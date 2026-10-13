/*
 * function: FLDMMDL_SetDirDisp
 * address:  0x0216D5D8
 * packet:   pkt_0216D5D8
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
#include "../include/Obj00113.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int FLDMMDL_SetDirDisp(int a0, int a1)
{
    int a2;

a2 = ((struct Obj00113 *)a0)->f18;
((struct Obj00113 *)a0)->f1C = a2;
((struct Obj00113 *)a0)->f18 = a1;
    return a0;}
