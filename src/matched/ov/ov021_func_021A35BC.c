/*
 * function: FIELD_PLAYER_CheckMoveRestrictFlag
 * address:  0x021A35BC
 * packet:   pkt_ov021_021A35BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GetGameSystem  0x021A30BC  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 */

typedef unsigned char  u8;
int FIELD_PLAYER_GetGameSystem(u8 *p);
typedef signed int     s32;
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
u32 GAME_DATA_GetEventWork(const struct BigObj *p);
u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);

int FIELD_PLAYER_CheckMoveRestrictFlag(int a)
{
    if (ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData((const struct Ctx *)FIELD_PLAYER_GetGameSystem((u8 *)a))), 0x963) != 0)
        return 1;
    return 0;
}
