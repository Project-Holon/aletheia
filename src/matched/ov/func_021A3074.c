/*
 * function: FIELD_PLAYER_GetMmdl
 * address:  0x021A3074
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
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00614.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);

void *FIELD_PLAYER_GetMmdl(u8 *p)
{
    return FIELD_PLAYER_CORE_GetMmdl(*(u8 * *)&((struct Obj00614 *)p)->f4);
}
