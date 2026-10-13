/*
 * function: FIELD_PLAYER_GRID_EndHold
 * address:  0x021A5708
 * packet:   pkt_021A5708
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
 *   FIELD_PLAYER_GRID_SetHopFlag  0x021A53A4  thumb  ov021
 *   FIELD_PLAYER_GRID_SetHoldFlag  0x021A5378  thumb  ov021
 *   FIELD_PLAYER_CORE_ApplyFormCodeModel  0x021A3998  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02083.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FIELD_PLAYER_CORE_ApplyFormCodeModel(u8 *a);
extern void FIELD_PLAYER_GRID_SetHoldFlag(u32 *p, int on);
extern void FIELD_PLAYER_GRID_SetHopFlag(u32 *p, int on);

int FIELD_PLAYER_GRID_EndHold(u32 a)
{
((struct Obj02083 *)((u8 *)(a)))->f14 = 0;
((struct Obj02083 *)((u8 *)(a)))->f16 = 0;
FIELD_PLAYER_GRID_SetHopFlag((u32 *)a, 0);
FIELD_PLAYER_GRID_SetHoldFlag((u32 *)a, 0);
return FIELD_PLAYER_CORE_ApplyFormCodeModel((u8 *)(((struct Obj02083 *)((u8 *)(a)))->fC));
}

