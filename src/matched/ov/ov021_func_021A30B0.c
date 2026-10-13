/*
 * function: FIELD_PLAYER_GetSex
 * address:  0x021A30B0
 * packet:   pkt_ov021_021A30B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Forwards the +4 member to 0x021A398C (unlabelled start).
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetSex  0x021A398C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19766.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_PLAYER_CORE_GetSex(u8 *p);

u32 FIELD_PLAYER_GetSex(u8 *p)
{
    return FIELD_PLAYER_CORE_GetSex((u8 *)(((struct Obj19766 *)p)->f4));
}
