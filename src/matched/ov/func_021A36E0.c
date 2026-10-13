/*
 * function: FIELD_PLAYER_GetGrid
 * address:  0x021A36E0
 * packet:   pkt_021A36E0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x8 of the object.
 */
#include "../include/Obj18031.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_PLAYER_GetGrid(u8 *p)
{
    return ((struct Obj18031 *)p)->f8;
}

