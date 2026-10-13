/*
 * function: FIELD_PLACE_NAME_ClearForceShowRequest
 * address:  0x021BCA6C
 * packet:   pkt_021BCA6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:

 * Addresses are Black-image addresses.
 */
#include "../include/Obj18196.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u8 *FIELD_PLACE_NAME_ClearForceShowRequest(u8 *p)
{
    ((struct Obj18196 *)p)->f4C = 0;
    return p;
}
