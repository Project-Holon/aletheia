/*
 * function: FIELD_PLAYER_NOGRID_GetNextRailLocation
 * address:  0x021A5A0C
 * packet:   pkt_021A5A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the object's word at +0x1c to FLDMMDL_RAIL_GetNextLocation.
 *
 * symbols:
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18056.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FLDMMDL_RAIL_GetNextLocation(void *o, void *out);

void FIELD_PLAYER_NOGRID_GetNextRailLocation(u8 *p, void *a1)
{
    FLDMMDL_RAIL_GetNextLocation((void *)(((struct Obj18056 *)p)->f1C), a1);
}
