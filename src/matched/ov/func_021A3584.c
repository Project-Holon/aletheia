/*
 * function: FIELD_PLAYER_GetGridMoveState
 * address:  0x021A3584
 * packet:   pkt_021A3584
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
 *   FIELD_PLAYER_GRID_GetHopLanded  0x021A5764  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12087.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern u32 FIELD_PLAYER_GRID_GetHopLanded(u8 *p);

int FIELD_PLAYER_GetGridMoveState(void *a)
{
if (FIELDMAP_GetMoveKind((u8 *)(((struct Obj12087 *)((u8 *)(a)))->f0)) == 0) {
    return FIELD_PLAYER_GRID_GetHopLanded((u8 *)(((struct Obj12087 *)((u8 *)(a)))->f8));
}
return 0;
}

