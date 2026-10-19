/*
 * function: FIELD_PLAYER_GRID_GetMoveResultOnCycle
 * address:  0x021A48C8
 * packet:   pkt_ov021_021A48C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELD_PLAYER_GRID_GetStandResultOnCycle  0x021A491C  thumb  ov021
 *   FIELD_PLAYER_GRID_GetWalkResultOnCycle  0x021A4994  thumb  ov021
 *   FIELD_PLAYER_GRID_GetTurnResultOnCycle  0x021A4A74  thumb  ov021
 *   FIELD_PLAYER_GRID_GetBlockedResultOnCycle  0x021A4AA8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12737.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern int FIELD_PLAYER_GRID_GetStandResultOnCycle(u8 *, void *, u32);
extern int FIELD_PLAYER_GRID_GetWalkResultOnCycle(u8 *a, void *b, u8 *c);
extern int FIELD_PLAYER_GRID_GetTurnResultOnCycle(int a, int b, u8 *c);
extern int FIELD_PLAYER_GRID_GetBlockedResultOnCycle(u8 *, void *, u32);

int FIELD_PLAYER_GRID_GetMoveResultOnCycle(u8 *a, u32 b)
{
    void *r = FIELD_PLAYER_CORE_GetMmdl(((struct Obj12737 *)a)->fC);
    int ret = 0;
    switch (((struct Obj12737 *)a)->f0) {
    case 0:
        ret = FIELD_PLAYER_GRID_GetStandResultOnCycle(a, r, b);
        break;
    case 1:
        ret = FIELD_PLAYER_GRID_GetWalkResultOnCycle(a, r, (u8 *)b);
        break;
    case 2:
        ret = FIELD_PLAYER_GRID_GetTurnResultOnCycle((int)a, (int)r, (u8 *)b);
        break;
    case 3:
        ret = FIELD_PLAYER_GRID_GetBlockedResultOnCycle(a, r, b);
        break;
    }
    return ret;
}
