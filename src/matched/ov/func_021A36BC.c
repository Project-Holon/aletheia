/*
 * function: FIELD_PLAYER_GetNogridNextRailLocation
 * address:  0x021A36BC
 * packet:   pkt_021A5A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the field at +0xc of the object to FIELD_PLAYER_NOGRID_GetNextRailLocation.
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_GetNextRailLocation  0x021A5A0C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18028.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_PLAYER_NOGRID_GetNextRailLocation(u8 *p, void *a1);

void FIELD_PLAYER_GetNogridNextRailLocation(struct Obj18028 *p, void *a1)
{
    FIELD_PLAYER_NOGRID_GetNextRailLocation((u8 *)(p->fC), a1);
}
