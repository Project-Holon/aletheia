/*
 * function: FIELD_PLAYER_GRID_RunForcedMove
 * address:  0x021A55A8
 * packet:   pkt_ov021_021A55A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GRID_CheckForcedMoveTile  0x021A5458  thumb  ov021
 *   FIELD_PLAYER_GRID_ClearForcedMoveFlag  0x021A5334  thumb  ov021
 *   gFieldPlayerGridForcedMoveFuncs  0x021D89EC  data  a4
 */

typedef unsigned int u32;

typedef int (*Fn021A55A8)(u32 *p, int a);

extern Fn021A55A8 const gFieldPlayerGridForcedMoveFuncs[];

int FIELD_PLAYER_GRID_CheckForcedMoveTile(u32 *p);
void FIELD_PLAYER_GRID_ClearForcedMoveFlag(u32 a);

int FIELD_PLAYER_GRID_RunForcedMove(u32 *p, u32 a, int b)
{
    if (b == 0) {
        if (gFieldPlayerGridForcedMoveFuncs[FIELD_PLAYER_GRID_CheckForcedMoveTile(p)](p, a) == 1)
            return 1;
    }
    FIELD_PLAYER_GRID_ClearForcedMoveFlag((u32)p);
    return 0;
}
