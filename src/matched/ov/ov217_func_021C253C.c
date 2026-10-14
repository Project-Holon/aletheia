/*
 * function: ARROW_InitPart
 * address:  0x021C253C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Initialise the header: two mode bytes, two u16 fields, three cleared words.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04642.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void ARROW_InitPart(void *p, u8 a, u8 b, u32 c, u32 d)
{
    ((struct Obj04642 *)p)->fE = a;
    ((struct Obj04642 *)p)->f0 = 0;
    ((struct Obj04642 *)p)->f8 = 0;
    ((struct Obj04642 *)p)->fC = 0;
    ((struct Obj04642 *)p)->fF = b;
    ((struct Obj04642 *)p)->f4 = c;
    ((struct Obj04642 *)p)->f10 = d;
}
