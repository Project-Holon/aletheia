/*
 * function: FIELD_PLAYER_IsGridHopping
 * address:  0x021A3624
 * packet:   pkt_021A3624
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
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_PLAYER_GRID_IsHopping  0x021A54A0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06010.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern int FIELD_PLAYER_GRID_IsHopping(u32 a);

int FIELD_PLAYER_IsGridHopping(void *a)
{
if (FIELDMAP_GetMoveKind((u8 *)(*(u32 *)&((struct Obj06010 *)((u8 *)(a)))->f0)) == 0) {
    if (FIELD_PLAYER_GRID_IsHopping(*(u32 *)&((struct Obj06010 *)((u8 *)(a)))->f8) == 1) {
        return 1;
    }
}
return 0;
}

