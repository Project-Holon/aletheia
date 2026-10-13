/*
 * function: EVENT_MAPCHANGE_RefreshUnionInfo
 * address: 0x02183DD4
 * packet: pkt_ov020_02183DD4
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetSecondUnionInfo 0x020127C4 thumb
 *   EVENT_FIELD_PROCLINK_CheckZoneFlag 0x02161D64 thumb ov010
 * interface: 020127C4 forwards 020127D0's returned pointer in r0.
 */
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef unsigned char  u8;
extern u8 *GAME_DATA_GetSecondUnionInfo(void *p);
extern int EVENT_FIELD_PROCLINK_CheckZoneFlag(int a0);
void EVENT_MAPCHANGE_RefreshUnionInfo(void *p)
{
    EVENT_FIELD_PROCLINK_CheckZoneFlag((int)GAME_DATA_GetSecondUnionInfo(GAMESYSTEM_GetGameData(p)));
}
