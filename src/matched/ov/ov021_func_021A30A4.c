/*
 * function: FIELD_PLAYER_SetFormCode
 * address:  0x021A30A4
 * packet:   pkt_ov021_021A30A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf: tail-calls 0x021A3980 with the +4 member and the second argument.
 *
 * symbols:
 *   FIELD_PLAYER_CORE_SetFormCode  0x021A3980  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19765.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void FIELD_PLAYER_CORE_SetFormCode(u8 *p, u32 a1);

void FIELD_PLAYER_SetFormCode(u8 *p, u32 b)
{
    FIELD_PLAYER_CORE_SetFormCode((u8 *)(((struct Obj19765 *)p)->f4), b);
}
