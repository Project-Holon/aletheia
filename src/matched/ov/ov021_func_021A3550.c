/*
 * function: FIELD_PLAYER_SetGridMoveFlag
 * address:  0x021A3550
 * packet:   pkt_ov021_021A3550
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_PLAYER_GRID_ResetHold  0x021A5738  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
u32 FIELDMAP_GetMoveKind(u8 *p);
void FIELD_PLAYER_GRID_ResetHold(u32 x, int a);

void FIELD_PLAYER_SetGridMoveFlag(u32 *p, int a)
{
    if (FIELDMAP_GetMoveKind((u8 *)p[0]) == 0)
        FIELD_PLAYER_GRID_ResetHold(p[2], a);
}
