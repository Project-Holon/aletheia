/*
 * function: FIELD_PLAYER_SetNogridParam
 * address:  0x021A3680
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
 *   FIELD_PLAYER_NOGRID_AttachMmdl  0x021A5928  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18024.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_PLAYER_NOGRID_AttachMmdl(u8 *p, int v);

void FIELD_PLAYER_SetNogridParam(u8 *p, int a1)
{
    FIELD_PLAYER_NOGRID_AttachMmdl((u8 *)(((struct Obj18024 *)p)->fC), a1);
}
