/*
 * function: FIELD_PLAYER_GetNogridRailPos
 * address:  0x021A36D4
 * packet:   pkt_021A5A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the field at +0xc of the object to FIELD_PLAYER_NOGRID_GetRailPos.
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_GetRailPos  0x021A5A24  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18030.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_PLAYER_NOGRID_GetRailPos(u8 *p);

void FIELD_PLAYER_GetNogridRailPos(u8 *p, u32 v)
{
    FIELD_PLAYER_NOGRID_GetRailPos((u8 *)(((struct Obj18030 *)p)->fC));
}
