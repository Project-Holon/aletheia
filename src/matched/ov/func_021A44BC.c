/*
 * function: FIELD_PLAYER_GRID_CheckCoreAction
 * address:  0x021A44BC
 * packet:   pkt_021A44BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0xc.
 *
 * symbols:
 *   FIELD_PLAYER_CORE_CheckAcmdPossible  0x021A3AA0  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18048.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_PLAYER_CORE_CheckAcmdPossible(u32 a);

void FIELD_PLAYER_GRID_CheckCoreAction(u8 *p)
{
    FIELD_PLAYER_CORE_CheckAcmdPossible(((struct Obj18048 *)p)->fC);
}
