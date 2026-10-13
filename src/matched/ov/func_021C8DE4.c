/*
 * function: FIELD_TILE_MOVE_SlideShowSurfPokemon
 * address:  0x021C8DE4
 * packet:   pkt_021C8DE4
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
 *   FIELD_PLAYER_GetRideEffect  0x021A2F98  thumb  ov021
 *   FLDEFF_NAMIPOKE_SetWakeEnabled  0x021ACBC8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18342.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_PLAYER_GetRideEffect(u8 *p);
extern u32 FLDEFF_NAMIPOKE_SetWakeEnabled(u32, u32);

int FIELD_TILE_MOVE_SlideShowSurfPokemon(u32 a)
{
return FLDEFF_NAMIPOKE_SetWakeEnabled(FIELD_PLAYER_GetRideEffect((u8 *)(((struct Obj18342 *)((u8 *)(a)))->f8)), 1);
}

