/*
 * function: FIELD_PLAYER_GRID_SetHopFlag
 * address:  0x021A53A4
 * packet:   pkt_ov021_021A53A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_GRID_SetFlag  0x021A5304  thumb  ov021
 *   FIELD_PLAYER_GRID_ClearFlag  0x021A530C  thumb  ov021
 */

typedef unsigned int u32;

int FIELD_PLAYER_GRID_SetFlag(u32 a, u32 b);
int FIELD_PLAYER_GRID_ClearFlag(u32 a, u32 b);

void FIELD_PLAYER_GRID_SetHopFlag(u32 *p, int on)
{
    if (on == 1)
        FIELD_PLAYER_GRID_SetFlag((u32)p, 0x10);
    else
        FIELD_PLAYER_GRID_ClearFlag((u32)p, 0x10);
}
