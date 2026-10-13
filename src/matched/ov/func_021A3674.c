/*
 * function: FIELD_PLAYER_SetupNogrid
 * address:  0x021A3674
 * packet:   pkt_021A3674
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
 *   FIELD_PLAYER_NOGRID_Update  0x021A596C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18023.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_PLAYER_NOGRID_Update(u8 *p, u32 b, u32 c);

void FIELD_PLAYER_SetupNogrid(u8 *p, u32 b, u32 c)
{
    FIELD_PLAYER_NOGRID_Update((u8 *)(((struct Obj18023 *)p)->fC), b, c);
}
