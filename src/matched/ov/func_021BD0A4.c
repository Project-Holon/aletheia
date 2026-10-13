/*
 * function: FIELD_PLACE_NAME_GetState
 * address:  0x021BD0A4
 * packet:   pkt_021BCA74
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x3c of the object.
 */
#include "../include/Obj18209.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_PLACE_NAME_GetState(u8 *p)
{
    return ((struct Obj18209 *)p)->f3C;
}

