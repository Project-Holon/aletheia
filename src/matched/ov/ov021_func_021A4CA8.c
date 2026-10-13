/*
 * function: FIELD_PLAYER_GRID_ApplyMoveResult
 * address:  0x021A4CA8
 * packet:   pkt_ov021_021A4CA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb  ov021
 *   FIELD_PLAYER_GRID_ApplyMoveResultOnFoot  0x021A4CF4  thumb  ov021
 *   FIELD_PLAYER_GRID_ApplyMoveResultOnCycle  0x021A4FA8  thumb  ov021
 *   FIELD_PLAYER_GRID_ApplyMoveResultOnSurf  0x021A5148  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00262.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_PLAYER_CORE_GetFormCode(u8 *p);
extern void FIELD_PLAYER_GRID_ApplyMoveResultOnFoot(u32, u32, u32);
extern void FIELD_PLAYER_GRID_ApplyMoveResultOnCycle(u32, u32, u32);
extern void FIELD_PLAYER_GRID_ApplyMoveResultOnSurf(u32, u32, u32);

void FIELD_PLAYER_GRID_ApplyMoveResult(u32 a, u32 b, u32 c)
{
    switch (FIELD_PLAYER_CORE_GetFormCode((u8 *)(*(u32 *)&((struct Obj00262 *)a)->fC))) {
    case 0:
        FIELD_PLAYER_GRID_ApplyMoveResultOnFoot(a, b, c);
        return;
    case 1:
        FIELD_PLAYER_GRID_ApplyMoveResultOnCycle(a, b, c);
        return;
    case 2:
    case 3:
        FIELD_PLAYER_GRID_ApplyMoveResultOnSurf(a, b, c);
        break;
    }
}
