/*
 * function: FIELD_PLAYER_ResetNogrid
 * address:  0x021A368C
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
 *   FIELD_PLAYER_NOGRID_ClearRailWork  0x021A5964  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18025.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_PLAYER_NOGRID_ClearRailWork(u32 *p);

void FIELD_PLAYER_ResetNogrid(u8 *p)
{
    FIELD_PLAYER_NOGRID_ClearRailWork((u32 *)(((struct Obj18025 *)p)->fC));
}
