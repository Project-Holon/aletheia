/*
 * function: FIELD_EFFECT_GetModelBaseOffsetAlt
 * address:  0x021ABE2C
 * packet:   pkt_021AB764
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the byte at +0x17 of the object.
 */
#include "../include/Obj18083.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 FIELD_EFFECT_GetModelBaseOffsetAlt(u8 *p)
{
    return ((struct Obj18083 *)p)->f17;
}

