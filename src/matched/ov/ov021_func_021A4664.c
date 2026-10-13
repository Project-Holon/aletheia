/*
 * function: FIELD_PLAYER_GRID_GetTurnResultOnFoot
 * address:  0x021A4664
 * packet:   pkt_ov021_021A4664
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_GRID_GetStandResultOnFoot  0x021A4544  thumb  ov021
 *   FIELD_PLAYER_GRID_GetWalkResultOnFoot  0x021A4598  thumb  ov021
 */
#include "../include/Obj01657.h"

typedef unsigned char  u8;
typedef unsigned short u16;

int FLDMMDL_CheckPossibleAcmd(int b);
typedef unsigned int   u32;
int FIELD_PLAYER_GRID_GetStandResultOnFoot(u8 *p, u32 r, u8 *q);
int FIELD_PLAYER_GRID_GetWalkResultOnFoot(u8 *a, void *b, u8 *c);

int FIELD_PLAYER_GRID_GetTurnResultOnFoot(int a, int b, u8 *c)
{
    if (FLDMMDL_CheckPossibleAcmd(b) == 0)
        return 0;
    if (((struct Obj01657 *)c)->f8 == 9)
        return FIELD_PLAYER_GRID_GetStandResultOnFoot((u8 *)a, b, c);
    return FIELD_PLAYER_GRID_GetWalkResultOnFoot((u8 *)a, (void *)b, c);
}
