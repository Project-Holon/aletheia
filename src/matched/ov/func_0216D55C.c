/*
 * function: FLDMMDL_CheckStatusBit
 * address:  0x0216D55C
 * packet:   pkt_0216D55C
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
#include "../include/Obj17788.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int FLDMMDL_CheckStatusBit(int a0, int a1)
{

a0 = ((struct Obj17788 *)((char *)a0))->f0;
a0 = a0 & a1;
    return a0;}
