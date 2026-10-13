/*
 * function: FIELD_PLAYER_GRID_StartHold
 * address:  0x021A56F4
 * packet:   pkt_021A56F4
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
 *   FIELD_PLAYER_GRID_SetHoldFlag  0x021A5378  thumb  ov021
 *   FIELD_PLAYER_CORE_SetFormSlotModel  0x021A39AC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18049.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_PLAYER_CORE_SetFormSlotModel(u32, u32);
extern void FIELD_PLAYER_GRID_SetHoldFlag(u32 *p, int on);

int FIELD_PLAYER_GRID_StartHold(u32 a)
{
FIELD_PLAYER_GRID_SetHoldFlag((u32 *)a, 1);
return FIELD_PLAYER_CORE_SetFormSlotModel(((struct Obj18049 *)((u8 *)(a)))->fC, 7);
}

