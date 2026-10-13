/*
 * function: FIELD_PLAYER_StartFormChange
 * address:  0x021A2F48
 * packet:   pkt_021A2F48
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
 *   FIELD_PLAYER_CORE_StartFormChange  0x021A3CB0  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18007.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_PLAYER_CORE_StartFormChange(u32 a, u32 b);

void FIELD_PLAYER_StartFormChange(u8 *p, u32 a1)
{
    FIELD_PLAYER_CORE_StartFormChange(((struct Obj18007 *)p)->f4, a1);
}
