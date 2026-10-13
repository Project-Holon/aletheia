/*
 * function: FIELD_RAIL_WORK_HasStepped
 * address:  0x021B8048
 * packet:   pkt_021B8038
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Loads the byte at byte +0x34 of the object.
 */
#include "../include/Obj18104.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 FIELD_RAIL_WORK_HasStepped(u8 *p)
{
    return ((struct Obj18104 *)p)->f34;
}

