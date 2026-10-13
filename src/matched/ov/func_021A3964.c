/*
 * function: FIELD_PLAYER_CORE_SetStepKind
 * address:  0x021A3964
 * packet:   pkt_021A3964
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x14.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18037.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELD_PLAYER_CORE_SetStepKind(u8 *p, u32 v)
{
    ((struct Obj18037 *)p)->f14 = v;
}
