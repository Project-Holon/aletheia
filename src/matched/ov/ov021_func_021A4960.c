/*
 * function: FIELD_PLAYER_GRID_IsTileBlockingCycle
 * address:  0x021A4960
 * packet:   pkt_ov021_021A4960
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MAP_ATTR_IsTallGrass  0x021AB140  thumb  ov021
 *   MAP_ATTR_IsDeepSand  0x021AB404  thumb  ov021
 *   MAP_ATTR_IsDeepSandB  0x021AB410  thumb  ov021
 *   MAP_ATTR_IsDeepSnow  0x021AB328  thumb  ov021
 */

int MAP_ATTR_IsTallGrass(int a);
int MAP_ATTR_IsDeepSand(int a);
int MAP_ATTR_IsDeepSandB(int a);
int MAP_ATTR_IsDeepSnow(int a);

int FIELD_PLAYER_GRID_IsTileBlockingCycle(int a)
{
    if (MAP_ATTR_IsTallGrass(a) != 0 || MAP_ATTR_IsDeepSand(a) != 0 || MAP_ATTR_IsDeepSandB(a) != 0 || MAP_ATTR_IsDeepSnow(a) != 0)
        return 1;
    return 0;
}
