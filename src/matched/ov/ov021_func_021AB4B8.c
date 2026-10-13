/*
 * function: MAP_ATTR_IsRoughGround
 * address:  0x021AB4B8
 * packet:   pkt_ov021_021AB4B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MAP_ATTR_IsTallGrass  0x021AB140  thumb
 *   MAP_ATTR_IsDeepSand  0x021AB404  thumb
 *   MAP_ATTR_IsDeepSandB  0x021AB410  thumb
 *   MAP_ATTR_IsDeepSnow  0x021AB328  thumb
 */

extern int MAP_ATTR_IsTallGrass(int id);
extern int MAP_ATTR_IsDeepSand(int id);
extern int MAP_ATTR_IsDeepSandB(int id);
extern int MAP_ATTR_IsDeepSnow(int id);

int MAP_ATTR_IsRoughGround(int id)
{
    if (MAP_ATTR_IsTallGrass(id) || MAP_ATTR_IsDeepSand(id) || MAP_ATTR_IsDeepSandB(id) || MAP_ATTR_IsDeepSnow(id))
        return 1;
    return 0;
}
