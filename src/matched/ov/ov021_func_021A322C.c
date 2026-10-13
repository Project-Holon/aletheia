/*
 * function: FIELD_PLAYER_ClearRememberedObjCode
 * address:  0x021A322C
 * packet:   pkt_ov021_021A322C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov018 func_0217BCDC: tail call on the object's
 * word at +0x4, the same shape as FIELD_PLAYER_GetPos.
 * symbols:
 *   FIELD_PLAYER_CORE_ClearRememberedObjCode  0x021A394C  thumb  ov021
 */
#include "../include/Obj19769.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void FIELD_PLAYER_CORE_ClearRememberedObjCode(u8 *p);

void FIELD_PLAYER_ClearRememberedObjCode(u8 *p)
{
    FIELD_PLAYER_CORE_ClearRememberedObjCode((u8 *)(((struct Obj19769 *)p)->f4));
}
