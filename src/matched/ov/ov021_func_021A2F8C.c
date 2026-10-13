/*
 * function: FIELD_PLAYER_SetRideEffect
 * address:  0x021A2F8C
 * packet:   pkt_ov021_021A2F8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x4, second argument forwarded.
 * Unlabelled leaf; its only blocker-caller is FIELD_PLAYER_GRID_EVENT_HopTask.
 *
 * symbols:
 *   FIELD_PLAYER_CORE_SetRideEffect  0x021A3AD0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19763.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_PLAYER_CORE_SetRideEffect(u8 *p, u32 v);

void FIELD_PLAYER_SetRideEffect(u8 *p, u32 b)
{
    FIELD_PLAYER_CORE_SetRideEffect((u8 *)(((struct Obj19763 *)p)->f4), b);
}
