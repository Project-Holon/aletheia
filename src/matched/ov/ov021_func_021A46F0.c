/*
 * function: ov021_func_021A46F0
 * address:  0x021A46F0
 * packet:   pkt_ov021_021A46F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELD_PLAYER_GRID_GetStandResultOnFootHop  0x021A4768  thumb  ov021
 *   FIELD_PLAYER_GRID_GetWalkResultOnFootHop  0x021A47B4  thumb  ov021
 *   FIELD_PLAYER_GRID_GetTurnResultOnFoot  0x021A4664  thumb  ov021
 *   FIELD_PLAYER_GRID_GetBlockedResultOnFoot  0x021A4698  thumb  ov021
 *   FIELD_PLAYER_GRID_GetHoldResultOnFootHop  0x021A482C  thumb  ov021
 *   FIELD_PLAYER_GRID_GetHopAirResult  0x021A4890  thumb  ov021
 *   FIELD_PLAYER_GRID_GetHopFallResult  0x021A48A4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12735.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern int FIELD_PLAYER_GRID_GetStandResultOnFootHop(u8 *, void *, u32);
extern int FIELD_PLAYER_GRID_GetWalkResultOnFootHop(u8 *, void *, u32);
extern int FIELD_PLAYER_GRID_GetTurnResultOnFoot(int a, int b, u8 *c);
extern int FIELD_PLAYER_GRID_GetBlockedResultOnFoot(u8 *, void *, u32);
extern int FIELD_PLAYER_GRID_GetHoldResultOnFootHop(u8 *, void *, u32);
extern int FIELD_PLAYER_GRID_GetHopAirResult(u8 *a, u32 b, u32 c);
extern int FIELD_PLAYER_GRID_GetHopFallResult(u32 a, u32 b, u32 c);

int ov021_func_021A46F0(u8 *a, u32 b)
{
    void *r = FIELD_PLAYER_CORE_GetMmdl(((struct Obj12735 *)a)->fC);
    int ret = 0;
    switch (((struct Obj12735 *)a)->f0) {
    case 0:
        ret = FIELD_PLAYER_GRID_GetStandResultOnFootHop(a, r, b);
        break;
    case 1:
        ret = FIELD_PLAYER_GRID_GetWalkResultOnFootHop(a, r, b);
        break;
    case 2:
        ret = FIELD_PLAYER_GRID_GetTurnResultOnFoot((int)a, (int)r, (u8 *)b);
        break;
    case 3:
        ret = FIELD_PLAYER_GRID_GetBlockedResultOnFoot(a, r, b);
        break;
    case 4:
        ret = FIELD_PLAYER_GRID_GetHoldResultOnFootHop(a, r, b);
        break;
    case 5:
    case 6:
        ret = FIELD_PLAYER_GRID_GetHopAirResult(a, (u32)r, b);
        break;
    case 7:
        ret = FIELD_PLAYER_GRID_GetHopFallResult((u32)a, (u32)r, b);
        break;
    }
    return ret;
}
