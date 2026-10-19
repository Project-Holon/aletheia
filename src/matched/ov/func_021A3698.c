/*
 * function: FIELD_PLAYER_IsNogridForcedMove
 * address:  0x021A3698
 * packet:   pkt_021A3674
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0xc.
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_IsForcedMove  0x021A59EC  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18026.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_PLAYER_NOGRID_IsForcedMove(u32 p);

u32 FIELD_PLAYER_IsNogridForcedMove(u8 *p)
{
    return FIELD_PLAYER_NOGRID_IsForcedMove(((struct Obj18026 *)p)->fC);
}
