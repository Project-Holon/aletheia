/*
 * function: FIELD_PLAYER_GRID_ReleaseForcedMove
 * address:  0x021A550C
 * packet:   pkt_ov021_021A550C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GRID_IsForcedMoveFlagSet  0x021A5340  thumb  ov021
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FIELD_PLAYER_GRID_ClearForcedMoveFlag  0x021A5334  thumb  ov021
 */
#include "../include/Obj06014.h"

typedef unsigned int u32;

int FIELD_PLAYER_GRID_IsForcedMoveFlagSet(u32 *p);
void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
u32 *FLDMMDL_ClearStatusBit(u32 *p, u32 v);
void FIELD_PLAYER_GRID_ClearForcedMoveFlag(u32 a);

void FIELD_PLAYER_GRID_ReleaseForcedMove(u32 *p)
{
    if (FIELD_PLAYER_GRID_IsForcedMoveFlagSet(p) == 1) {
        FLDMMDL_ClearStatusBit(FIELD_PLAYER_CORE_GetMmdl(*(unsigned char * *)&((struct Obj06014 *)p)->fC), 0x18);
        FIELD_PLAYER_GRID_ClearForcedMoveFlag((u32)p);
    }
}
