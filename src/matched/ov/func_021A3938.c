/*
 * function: FIELD_PLAYER_CORE_SetObjCode
 * address:  0x021A3938
 * packet:   pkt_021A3938
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_PLAYER_CORE_ChangeModel  0x021A3AD8  thumb  ov021
 *   GAME_DATA_SetPlayerPalaceZoneId  0x02012B30  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18034.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 GAME_DATA_SetPlayerPalaceZoneId(u32, u32);
extern void FIELD_PLAYER_CORE_ChangeModel(u8 *p, int a);

int FIELD_PLAYER_CORE_SetObjCode(u32 a, u32 b)
{
FIELD_PLAYER_CORE_ChangeModel((u8 *)a, b);
return GAME_DATA_SetPlayerPalaceZoneId(((struct Obj18034 *)((u8 *)(a)))->fC, b);
}

