/*
 * function: FIELD_PLAYER_GRID_GetMoveResult
 * address:  0x021A4444
 * packet:   pkt_ov021_021A4444
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb  ov021
 *   FIELD_PLAYER_GRID_GetMoveResultOnFoot  0x021A44C8  thumb  ov021
 *   FIELD_PLAYER_GRID_GetMoveResultOnCycle  0x021A48C8  thumb  ov021
 *   FIELD_PLAYER_GRID_GetMoveResultOnSurf  0x021A4B00  thumb  ov021
 */
#include "../include/Obj09565.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_PLAYER_CORE_GetFormCode(u8 *p);
extern int FIELD_PLAYER_GRID_GetMoveResultOnFoot(u8 *, u32);
extern int FIELD_PLAYER_GRID_GetMoveResultOnCycle(u8 *, u32);
extern int FIELD_PLAYER_GRID_GetMoveResultOnSurf(u8 *, u32);

int FIELD_PLAYER_GRID_GetMoveResult(u8 *p, u32 s)
{
    int r;

    r = 0;
    switch (FIELD_PLAYER_CORE_GetFormCode((u8 *)(*(u32 *)&((struct Obj09565 *)p)->fC))) {
    case 0:
        r = FIELD_PLAYER_GRID_GetMoveResultOnFoot(p, s);
        break;
    case 1:
        r = FIELD_PLAYER_GRID_GetMoveResultOnCycle(p, s);
        break;
    case 2:
    case 3:
        r = FIELD_PLAYER_GRID_GetMoveResultOnSurf(p, s);
        break;
    }
    return r;
}
