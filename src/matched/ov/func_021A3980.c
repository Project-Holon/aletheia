/*
 * function: FIELD_PLAYER_CORE_SetFormCode
 * address:  0x021A3980
 * packet:   pkt_021A3810
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
 *   GAME_DATA_SetPlayerObjectCode  0x02012B2C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18042.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec44;
extern void GAME_DATA_SetPlayerObjectCode(struct Rec44 *p, u32 v);

void FIELD_PLAYER_CORE_SetFormCode(u8 *p, u32 a1)
{
    GAME_DATA_SetPlayerObjectCode((struct Rec44 *)(((struct Obj18042 *)p)->fC), a1);
}
