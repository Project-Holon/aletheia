/*
 * function: FIELD_PLAYER_ResetGridMove
 * address:  0x021A356C
 * packet:   pkt_ov021_021A356C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_PLAYER_GRID_StopForcedMove  0x021A575C  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
u32 FIELDMAP_GetMoveKind(u8 *p);
void FIELD_PLAYER_GRID_StopForcedMove(u32 *x);

void FIELD_PLAYER_ResetGridMove(void **p)
{
    if (FIELDMAP_GetMoveKind(p[0]) == 0)
        FIELD_PLAYER_GRID_StopForcedMove(p[2]);
}
