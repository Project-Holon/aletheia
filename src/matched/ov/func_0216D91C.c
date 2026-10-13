/*
 * function: FLDMMDL_GetSizeWidth
 * address:  0x0216D91C
 * packet:   pkt_0216D91C
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
#include "../include/Obj17850.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



u8 FLDMMDL_GetSizeWidth(int a0)
{

a0 = a0 + 0x7c;
a0 = ((struct Obj17850 *)((char *)a0))->f0;
    return a0;}
