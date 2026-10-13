/*
 * function: FIELD_PLAYER_GRID_GetHopStepHitFlags
 * address:  0x021A569C
 * packet:   pkt_ov021_021A569C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_GRID_GetStepHitFlags  0x021A5264  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   FIELD_PLAYER_GRID_IsHopTileKind  0x021A55DC  thumb  ov021
 */

typedef unsigned char  u8;
int FIELD_PLAYER_GRID_GetStepHitFlags(u8 *a, void *b, unsigned int c, int *d);
typedef unsigned short u16;
typedef unsigned int   u32;
u16 MAP_ATTR_GetTerrainId(u32 attr);
int FIELD_PLAYER_GRID_IsHopTileKind(int x);

int FIELD_PLAYER_GRID_GetHopStepHitFlags(u8 *a, void *b, int c, int *d)
{
    int r = FIELD_PLAYER_GRID_GetStepHitFlags(a, b, c, d);

    if (FIELD_PLAYER_GRID_IsHopTileKind(MAP_ATTR_GetTerrainId(*d)) == 1)
        r |= 0x100;
    return r;
}
