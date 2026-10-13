/*
 * function: FIELD_PLAYER_SetupGrid
 * address:  0x021A35F0
 * packet:   pkt_021A35F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_PLAYER_GRID_Move  0x021A41B0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18022.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_PLAYER_GRID_Move(u32, u32, u32, u32);

int FIELD_PLAYER_SetupGrid(u32 a, u32 b, u32 c, u32 d)
{
return FIELD_PLAYER_GRID_Move(((struct Obj18022 *)((u8 *)(a)))->f8, b, c, d);
}

