/*
 * function: FIELD_PLACE_NAME_GetArcHandle
 * address:  0x021BD094
 * packet:   pkt_021BCA74
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x10 of the object.
 */
#include "../include/Obj18207.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_PLACE_NAME_GetArcHandle(u8 *p)
{
    return ((struct Obj18207 *)p)->f10;
}

