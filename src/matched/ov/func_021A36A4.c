/*
 * function: FIELD_PLAYER_GetNogridRailWork
 * address:  0x021A36A4
 * packet:   pkt_021A368C
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
 *   FIELD_PLAYER_NOGRID_GetRailWork  0x021A5A30  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18027.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_PLAYER_NOGRID_GetRailWork(u32 *p);

u32 FIELD_PLAYER_GetNogridRailWork(u8 *p)
{
    return FIELD_PLAYER_NOGRID_GetRailWork((u32 *)(((struct Obj18027 *)p)->fC));
}
