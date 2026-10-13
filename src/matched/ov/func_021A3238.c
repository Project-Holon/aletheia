/*
 * function: FIELD_PLAYER_CheckFormModel
 * address:  0x021A3238
 * packet:   pkt_021A3238
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
 *   FIELD_PLAYER_CORE_CheckFormModel  0x021A3A20  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18019.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_PLAYER_CORE_CheckFormModel(u32 a);

int FIELD_PLAYER_CheckFormModel(u8 *p)
{
    return FIELD_PLAYER_CORE_CheckFormModel(((struct Obj18019 *)p)->f4);
}
