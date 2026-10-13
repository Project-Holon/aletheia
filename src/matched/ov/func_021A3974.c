/*
 * function: FIELD_PLAYER_CORE_GetFormCode
 * address:  0x021A3974
 * packet:   pkt_021A3810
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
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18041.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec44;
extern u32 GAME_DATA_GetPlayerObjectCode(const struct Rec44 *p);

u32 FIELD_PLAYER_CORE_GetFormCode(u8 *p)
{
    return GAME_DATA_GetPlayerObjectCode((const struct Rec44 *)(((struct Obj18041 *)p)->fC));
}
