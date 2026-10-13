/*
 * function: FIELD_PLAYER_GetFormCode
 * address:  0x021A3098
 * packet:   pkt_021A2F48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x4.
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18017.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_PLAYER_CORE_GetFormCode(u8 *p);

u32 FIELD_PLAYER_GetFormCode(u8 *p)
{
    return FIELD_PLAYER_CORE_GetFormCode((u8 *)(((struct Obj18017 *)p)->f4));
}
