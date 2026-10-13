/*
 * function: FIELD_RAIL_WORK_GetUnitScale
 * address:  0x021B8308
 * packet:   pkt_021B8038
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x1c of the object.
 */
#include "../include/Obj18117.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_RAIL_WORK_GetUnitScale(u8 *p)
{
    return ((struct Obj18117 *)p)->f1C;
}

