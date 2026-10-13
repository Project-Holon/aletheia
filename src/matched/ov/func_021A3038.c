/*
 * function: FIELD_PLAYER_GetPos
 * address:  0x021A3038
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
 *   FIELD_PLAYER_CORE_GetPos  0x021A3898  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18011.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct VecFx32;
extern void FIELD_PLAYER_CORE_GetPos(u8 *p, struct VecFx32 *out);

void FIELD_PLAYER_GetPos(u8 *p, struct VecFx32 *out)
{
    FIELD_PLAYER_CORE_GetPos((u8 *)((struct Obj18011 *)p)->f4, out);
}
