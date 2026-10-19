/*
 * function: FIELD_PLAYER_CheckWaterfallClimbAttr
 * address:  0x021A3524
 * packet:   pkt_ov021_021A3524
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb  ov021
 *   MAP_ATTR_IsBlocked  0x021AB11C  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_IsWaterfall  0x021AB310  thumb  ov021
 */

typedef unsigned char  u8;
unsigned int FIELD_PLAYER_GetFormCode(u8 *p);
typedef unsigned short u16;
typedef unsigned int   u32;
int MAP_ATTR_IsBlocked(u32 attr);
u16 MAP_ATTR_GetTerrainId(u32 attr);
int MAP_ATTR_IsWaterfall(u16 id);

int FIELD_PLAYER_CheckWaterfallClimbAttr(u8 *a, int b, int c)
{
    int r = FIELD_PLAYER_GetFormCode(a);

    if (MAP_ATTR_IsBlocked(b) != 0 || r != 2)
        return 0;
    return MAP_ATTR_IsWaterfall(MAP_ATTR_GetTerrainId(c));
}
