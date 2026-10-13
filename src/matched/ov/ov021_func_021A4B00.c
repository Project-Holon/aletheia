/*
 * function: ov021_func_021A4B00
 * address:  0x021A4B00
 * packet:   pkt_ov021_021A4B00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELD_PLAYER_GRID_GetStandResultOnSurf  0x021A4B54  thumb  ov021
 *   FIELD_PLAYER_GRID_GetWalkResultOnSurf  0x021A4B98  thumb  ov021
 *   FIELD_PLAYER_GRID_GetTurnResultOnSurf  0x021A4C1C  thumb  ov021
 *   FIELD_PLAYER_GRID_GetBlockedResultOnSurf  0x021A4C50  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12738.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern int FIELD_PLAYER_GRID_GetStandResultOnSurf(u8 *, void *, u32);
extern int FIELD_PLAYER_GRID_GetWalkResultOnSurf(u8 *, void *, u32);
extern int FIELD_PLAYER_GRID_GetTurnResultOnSurf(int a, int b, u8 *c);
extern int FIELD_PLAYER_GRID_GetBlockedResultOnSurf(u8 *, void *, u32);

int ov021_func_021A4B00(u8 *a, u32 b)
{
    void *r = FIELD_PLAYER_CORE_GetMmdl(((struct Obj12738 *)a)->fC);
    int ret = 0;
    switch (((struct Obj12738 *)a)->f0) {
    case 0:
        ret = FIELD_PLAYER_GRID_GetStandResultOnSurf(a, r, b);
        break;
    case 1:
        ret = FIELD_PLAYER_GRID_GetWalkResultOnSurf(a, r, b);
        break;
    case 2:
        ret = FIELD_PLAYER_GRID_GetTurnResultOnSurf((int)a, (int)r, (u8 *)b);
        break;
    case 3:
        ret = FIELD_PLAYER_GRID_GetBlockedResultOnSurf(a, r, b);
        break;
    }
    return ret;
}
