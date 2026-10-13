/*
 * function: FIELD_PLAYER_GetStepPhase
 * address:  0x021A308C
 * packet:   pkt_021A3080
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x4.
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetStepPhase  0x021A3970  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18016.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_PLAYER_CORE_GetStepPhase(u32 *p);

u32 FIELD_PLAYER_GetStepPhase(u8 *p)
{
    return FIELD_PLAYER_CORE_GetStepPhase((u32 *)(((struct Obj18016 *)p)->f4));
}
