/*
 * function: FIELD_NOGRID_MAPPER_CreateRailWork
 * address:  0x021BB394
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
 *   FIELD_RAIL_ActivateFreeWork  0x021B7970  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18166.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_RAIL_ActivateFreeWork();

void FIELD_NOGRID_MAPPER_CreateRailWork(u8 *p)
{
    FIELD_RAIL_ActivateFreeWork(((struct Obj18166 *)p)->f0);
}
