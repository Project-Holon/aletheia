/*
 * function: FIELD_PLACE_NAME_GetHeapId
 * address:  0x021BD090
 * packet:   pkt_021BCA74
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 16-bit halfword at +0xc of the object.
 */
#include "../include/Obj18206.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 FIELD_PLACE_NAME_GetHeapId(u8 *p)
{
    return ((struct Obj18206 *)p)->fC;
}

