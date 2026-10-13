/*
 * function: FIELD_PLAYER_CheckMoveBusy
 * address:  0x021A2FB0
 * packet:   pkt_021A2FB0
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
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_PLAYER_GRID_IsBlocked  0x021A5778  thumb  ov021
 *   FIELD_PLAYER_NOGRID_IsBlocked  0x021A59DC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09180.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern int FIELD_PLAYER_GRID_IsBlocked(u32 a);
extern int FIELD_PLAYER_NOGRID_IsBlocked(u32 a);

u32 FIELD_PLAYER_CheckMoveBusy(u32 a)
{
if (FIELDMAP_GetMoveKind((u8 *)(((struct Obj09180 *)((u8 *)(a)))->f0)) == 0) {
    return FIELD_PLAYER_GRID_IsBlocked(((struct Obj09180 *)((u8 *)(a)))->f8);
}
return FIELD_PLAYER_NOGRID_IsBlocked(((struct Obj09180 *)((u8 *)(a)))->fC);
}

