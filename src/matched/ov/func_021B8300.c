/*
 * function: FIELD_RAIL_WORK_GetWidthOffsetRaw
 * address:  0x021B8300
 * packet:   pkt_021B8038
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x14 of the object.
 */
#include "../include/Obj18115.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_RAIL_WORK_GetWidthOffsetRaw(u8 *p)
{
    return ((struct Obj18115 *)p)->f14;
}

