/*
 * function: FIELD_PLACE_NAME_RequestForceShow
 * address:  0x021BCA64
 * packet:   pkt_021BCA64
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
#include "../include/Obj18195.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void FIELD_PLACE_NAME_RequestForceShow(u8 *p)
{
    ((struct Obj18195 *)p)->f4C = 1;
}
