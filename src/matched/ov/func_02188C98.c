/*
 * function: FIELDMAP_GetG3dMapper
 * address:  0x02188C98
 * packet:   pkt_02188C54
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x48 of the object.
 */
#include "../include/Obj17865.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELDMAP_GetG3dMapper(u8 *p)
{
    return ((struct Obj17865 *)p)->f48;
}

