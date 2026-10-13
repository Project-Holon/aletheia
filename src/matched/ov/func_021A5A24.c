/*
 * function: FIELD_PLAYER_NOGRID_GetRailPos
 * address:  0x021A5A24
 * packet:   pkt_021A5A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the object's word at +0x20 to FIELD_RAIL_WORK_GetPos.
 *
 * symbols:
 *   FIELD_RAIL_WORK_GetPos  0x021B8028  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18058.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_RAIL_WORK_GetPos(u32 v);

void FIELD_PLAYER_NOGRID_GetRailPos(u8 *p)
{
    FIELD_RAIL_WORK_GetPos(((struct Obj18058 *)p)->f20);
}
