/*
 * function: PLACE_NAME_LETTER_GetActive
 * address:  0x021BD2D8
 * packet:   pkt_021BCA74
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x44 of the object.
 */
#include "../include/Obj18223.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 PLACE_NAME_LETTER_GetActive(u8 *p)
{
    return ((struct Obj18223 *)p)->f44;
}

