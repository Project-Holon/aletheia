/*
 * function: FIELD_PLAYER_GetNogridLocationByDir
 * address:  0x021A36C8
 * packet:   pkt_021A5A00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards the field at +0xc of the object to FIELD_PLAYER_NOGRID_GetRailLocationByDir.
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_GetRailLocationByDir  0x021A5A18  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18029.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_PLAYER_NOGRID_GetRailLocationByDir(u8 *p, u32 k, void *buf);

int FIELD_PLAYER_GetNogridLocationByDir(u8 *p, u32 k, void *buf)
{
    return FIELD_PLAYER_NOGRID_GetRailLocationByDir(*(u8 * *)&((struct Obj18029 *)p)->fC, k, buf);
}
