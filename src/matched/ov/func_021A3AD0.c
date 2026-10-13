/*
 * function: FIELD_PLAYER_CORE_SetRideEffect
 * address:  0x021A3AD0
 * packet:   pkt_021A3AD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x28.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18046.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELD_PLAYER_CORE_SetRideEffect(u8 *p, u32 v)
{
    ((struct Obj18046 *)p)->f28 = v;
}
