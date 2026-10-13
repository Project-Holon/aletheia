/*
 * function: FIELD_ENCOUNT_GetStepCount
 * address:  0x021AA778
 * packet:   pkt_021AA778
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x8 of the object.
 */
#include "../include/Obj18071.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_ENCOUNT_GetStepCount(u8 *p)
{
    return ((struct Obj18071 *)p)->f8;
}

