/*
 * function: FIELD_NOGRID_MAPPER_DeleteRailWork
 * address:  0x021BB3A0
 * packet:   pkt_021BB394
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x0.
 *
 * symbols:
 *   FIELD_RAIL_ReleaseWork  0x021B79AC  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18167.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_RAIL_ReleaseWork();

void FIELD_NOGRID_MAPPER_DeleteRailWork(u8 *p, u32 a1)
{
    FIELD_RAIL_ReleaseWork(((struct Obj18167 *)p)->f0);
}
