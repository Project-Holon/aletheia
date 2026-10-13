/*
 * function: FIELD_GROUND_ANIME_KeyTableGetDuration
 * address:  0x021A7A8C
 * packet:   pkt_021A7A88
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x18 of the object.
 */
#include "../include/Obj18067.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_GROUND_ANIME_KeyTableGetDuration(u8 *p)
{
    return ((struct Obj18067 *)p)->f18;
}

