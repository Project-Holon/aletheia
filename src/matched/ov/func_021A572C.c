/*
 * function: FIELD_PLAYER_GRID_GetMmdl
 * address:  0x021A572C
 * packet:   pkt_021A572C
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
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09570.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);

void *FIELD_PLAYER_GRID_GetMmdl(u8 *p)
{
    return FIELD_PLAYER_CORE_GetMmdl(((struct Obj09570 *)p)->fC);
}
