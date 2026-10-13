/*
 * function: FIELD_PLAYER_GetDirDisp
 * address:  0x021A3050
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
 *   FIELD_PLAYER_CORE_GetDirDisp  0x021A3920  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18013.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 FIELD_PLAYER_CORE_GetDirDisp(u8 *p);

u16 FIELD_PLAYER_GetDirDisp(u8 *p)
{
    return FIELD_PLAYER_CORE_GetDirDisp((u8 *)(((struct Obj18013 *)p)->f4));
}
