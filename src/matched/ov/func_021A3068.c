/*
 * function: FIELD_PLAYER_GetFieldMap
 * address:  0x021A3068
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
 *   FIELD_PLAYER_CORE_GetFieldMap  0x021A395C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18014.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_PLAYER_CORE_GetFieldMap(u8 *p);

u32 FIELD_PLAYER_GetFieldMap(u8 *p)
{
    return FIELD_PLAYER_CORE_GetFieldMap((u8 *)(((struct Obj18014 *)p)->f4));
}
