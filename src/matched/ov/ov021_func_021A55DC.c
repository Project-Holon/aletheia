/*
 * function: FIELD_PLAYER_GRID_IsHopTileKind
 * address:  0x021A55DC
 * packet:   pkt_ov021_021A55DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MAP_ATTR_IsDeepSand  0x021AB404  thumb  ov021
 *   MAP_ATTR_IsDeepSandB  0x021AB410  thumb  ov021
 */

int MAP_ATTR_IsDeepSand(int a);
int MAP_ATTR_IsDeepSandB(int a);

int FIELD_PLAYER_GRID_IsHopTileKind(int a)
{
    if (MAP_ATTR_IsDeepSand(a) == 1 || MAP_ATTR_IsDeepSandB(a) == 1)
        return 1;
    return 0;
}
