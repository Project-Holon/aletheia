/*
 * function: FIELD_GIMMICK_BRIDGE_IsOnSwayTile
 * address:  0x021F381C
 * packet:   pkt_ov047_021F381C
 * region:   ov047
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb  ov021
 *   MAP_ATTR_IsPresent  0x021AB100  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   func_021AB44C  0x021AB44C  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern u32 FIELD_PLAYER_GetNowAttribute(void **ctx);
extern int MAP_ATTR_IsPresent(u32 attr);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int func_021AB44C(u16 id);

int FIELD_GIMMICK_BRIDGE_IsOnSwayTile(int *p)
{
    int r4 = FIELD_PLAYER_GetNowAttribute((void **)(*p));
    if (MAP_ATTR_IsPresent(r4) == 0) {
        return 0;
    }
    return func_021AB44C(MAP_ATTR_GetTerrainId(r4));
}
