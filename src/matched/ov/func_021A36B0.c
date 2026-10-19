/*
 * function: FIELD_PLAYER_SetNogridRailLocation
 * address:  0x021A36B0
 * packet:   pkt_021A5A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the field at +0xc of the object to FIELD_PLAYER_NOGRID_SetRailLocation.
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_SetRailLocation  0x021A5A00  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00614.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_PLAYER_NOGRID_SetRailLocation(u8 *p, void *r);

void FIELD_PLAYER_SetNogridRailLocation(u8 *p, void *r)
{
    FIELD_PLAYER_NOGRID_SetRailLocation(*(u8 * *)&((struct Obj00614 *)p)->fC, r);
}
