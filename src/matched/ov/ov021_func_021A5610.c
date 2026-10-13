/*
 * function: FIELD_PLAYER_GRID_IsOnHopStartTile
 * address:  0x021A5610
 * packet:   pkt_ov021_021A5610
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GRID_GetAttrAtDir  0x021A5788  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   FIELD_PLAYER_GRID_IsHopStartTileKind  0x021A55FC  thumb  ov021
 */

typedef unsigned int u32;

void FIELD_PLAYER_GRID_GetAttrAtDir(u32 *p, int k, int *out);
typedef unsigned short u16;
u16 MAP_ATTR_GetTerrainId(u32 attr);
int FIELD_PLAYER_GRID_IsHopStartTileKind(int x);

int FIELD_PLAYER_GRID_IsOnHopStartTile(u32 *p)
{
    int x;

    FIELD_PLAYER_GRID_GetAttrAtDir(p, 9, &x);
    if (FIELD_PLAYER_GRID_IsHopStartTileKind(MAP_ATTR_GetTerrainId(x)) == 1)
        return 1;
    return 0;
}
