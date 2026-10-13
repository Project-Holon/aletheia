/*
 * function: FIELD_PLAYER_NOGRID_GetRailLocationByDir
 * address:  0x021A5A18
 * packet:   pkt_021A5A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the object's word at +0x1c to FLDMMDL_RAIL_GetLocationByDir.
 *
 * symbols:
 *   FLDMMDL_RAIL_GetLocationByDir  0x0219E664  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18057.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FLDMMDL_RAIL_GetLocationByDir(void *o, u32 k, void *buf);

int FIELD_PLAYER_NOGRID_GetRailLocationByDir(u8 *p, u32 k, void *buf)
{
    return FLDMMDL_RAIL_GetLocationByDir(((struct Obj18057 *)p)->f1C, k, buf);
}
