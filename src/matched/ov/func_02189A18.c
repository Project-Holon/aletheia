/*
 * function: func_02189A18
 * address:  0x02189A18
 * packet:   pkt_02189A00
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x40 of the object.
 */
#include "../include/Obj17887.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_02189A18(u8 *p)
{
    return ((struct Obj17887 *)p)->f40;
}

