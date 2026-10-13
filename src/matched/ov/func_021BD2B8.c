/*
 * function: PLACE_NAME_LETTER_GetHeapId
 * address:  0x021BD2B8
 * packet:   pkt_021BD2B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter at +0x0.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18217.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 PLACE_NAME_LETTER_GetHeapId(u8 *p)
{
    return ((struct Obj18217 *)p)->f0;
}
