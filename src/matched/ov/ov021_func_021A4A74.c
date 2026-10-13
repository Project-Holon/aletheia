/*
 * function: FIELD_PLAYER_GRID_GetTurnResultOnCycle
 * address:  0x021A4A74
 * packet:   pkt_ov021_021A4A74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_GRID_GetStandResultOnCycle  0x021A491C  thumb  ov021
 *   FIELD_PLAYER_GRID_GetWalkResultOnCycle  0x021A4994  thumb  ov021
 */
#include "../include/Obj02084.h"

typedef unsigned char  u8;
typedef unsigned short u16;

int FLDMMDL_CheckPossibleAcmd(int b);
int FIELD_PLAYER_GRID_GetStandResultOnCycle(int a, int b, u8 *c);
int FIELD_PLAYER_GRID_GetWalkResultOnCycle(u8 *a, void *b, u8 *c);

int FIELD_PLAYER_GRID_GetTurnResultOnCycle(int a, int b, u8 *c)
{
    if (FLDMMDL_CheckPossibleAcmd(b) == 0)
        return 0;
    if (((struct Obj02084 *)c)->f8 == 9)
        return FIELD_PLAYER_GRID_GetStandResultOnCycle(a, b, c);
    return FIELD_PLAYER_GRID_GetWalkResultOnCycle((u8 *)a, (void *)b, c);
}
