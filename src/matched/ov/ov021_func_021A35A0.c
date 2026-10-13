/*
 * function: FIELD_PLAYER_SetGridMoveState
 * address:  0x021A35A0
 * packet:   pkt_ov021_021A35A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_PLAYER_GRID_SetHopLanded  0x021A5768  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
u32 FIELDMAP_GetMoveKind(u8 *p);
int FIELD_PLAYER_GRID_SetHopLanded(u32 a, u32 b);

void FIELD_PLAYER_SetGridMoveState(u32 *p, int a)
{
    if (FIELDMAP_GetMoveKind((u8 *)p[0]) == 0)
        FIELD_PLAYER_GRID_SetHopLanded(p[2], a);
}
