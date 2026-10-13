/*
 * function: FIELD_PLAYER_NOGRID_SetRailLocation
 * address:  0x021A5A00
 * packet:   pkt_021A5A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the object's word at +0x1c to FLDMMDL_RAIL_SetLocation.
 *
 * symbols:
 *   FLDMMDL_RAIL_SetLocation  0x0219E2C0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18055.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FLDMMDL_RAIL_SetLocation(void *a, void *r);

void FIELD_PLAYER_NOGRID_SetRailLocation(u8 *p, void *r)
{
    FLDMMDL_RAIL_SetLocation(((struct Obj18055 *)p)->f1C, r);
}
