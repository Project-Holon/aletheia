/*
 * function: FIELD_PLAYER_GRID_GetTurnResultOnSurf
 * address:  0x021A4C1C
 * packet:   pkt_ov021_021A4C1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_GRID_GetStandResultOnSurf  0x021A4B54  thumb  ov021
 *   FIELD_PLAYER_GRID_GetWalkResultOnSurf  0x021A4B98  thumb  ov021
 */
#include "../include/Obj19789.h"

typedef unsigned char  u8;
typedef unsigned short u16;

int FLDMMDL_CheckPossibleAcmd(int b);
int FIELD_PLAYER_GRID_GetStandResultOnSurf(int a, int b, u8 *c);
int FIELD_PLAYER_GRID_GetWalkResultOnSurf(int a, int b, u8 *c);

int FIELD_PLAYER_GRID_GetTurnResultOnSurf(int a, int b, u8 *c)
{
    if (FLDMMDL_CheckPossibleAcmd(b) == 0)
        return 0;
    if (((struct Obj19789 *)c)->f8 == 9)
        return FIELD_PLAYER_GRID_GetStandResultOnSurf(a, b, c);
    return FIELD_PLAYER_GRID_GetWalkResultOnSurf(a, b, c);
}
