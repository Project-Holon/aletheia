/*
 * function: FIELD_NOGRID_MAPPER_UnbindCameraWork
 * address:  0x021BB3B8
 * packet:   pkt_021BB3AC
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
 *   FIELD_RAIL_ClearFocusWork  0x021B79CC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18169.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_RAIL_ClearFocusWork(u32 *p);

void FIELD_NOGRID_MAPPER_UnbindCameraWork(u8 *p)
{
    FIELD_RAIL_ClearFocusWork((u32 *)(((struct Obj18169 *)p)->f0));
}
