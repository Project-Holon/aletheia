/*
 * function: FIELD_PLAYER_ResetMoveWork
 * address:  0x021A2F6C
 * packet:   pkt_ov021_021A2F6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_PLAYER_GRID_ResetBlockedPose  0x021A53D0  thumb  ov021
 *   FIELD_PLAYER_NOGRID_EndBlockedWalk  0x021A5A34  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
u32 FIELDMAP_GetMoveKind(u8 *p);
void FIELD_PLAYER_GRID_ResetBlockedPose(u32 *p);
void FIELD_PLAYER_NOGRID_EndBlockedWalk(u32 *p);

void FIELD_PLAYER_ResetMoveWork(u32 *p)
{
    if (FIELDMAP_GetMoveKind((u8 *)p[0]) == 0)
        FIELD_PLAYER_GRID_ResetBlockedPose((u32 *)p[2]);
    else
        FIELD_PLAYER_NOGRID_EndBlockedWalk((u32 *)p[3]);
}
