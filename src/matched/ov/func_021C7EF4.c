/*
 * function: FIELD_FLASH_GetTweenAlpha
 * address:  0x021C7EF4
 * packet:   pkt_021C7EF4
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the byte at +0x4 of the object.
 */
#include "../include/Obj18328.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 FIELD_FLASH_GetTweenAlpha(u8 *p)
{
    return ((struct Obj18328 *)p)->f4;
}

