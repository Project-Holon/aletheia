/*
 * function: func_021BD134
 * address:  0x021BD134
 * packet:   pkt_021BCA74
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x1c of the object.
 */
#include "../include/Obj18214.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021BD134(u8 *p)
{
    return ((struct Obj18214 *)p)->f1C;
}

