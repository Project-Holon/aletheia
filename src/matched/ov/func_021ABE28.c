/*
 * function: FIELD_EFFECT_GetModelBaseOffset
 * address:  0x021ABE28
 * packet:   pkt_021AB764
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the byte at +0x16 of the object.
 */
#include "../include/Obj18082.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 FIELD_EFFECT_GetModelBaseOffset(u8 *p)
{
    return ((struct Obj18082 *)p)->f16;
}

