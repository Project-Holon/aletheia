/*
 * function: EVENT_FIELD_PROCLINK_IsSpecialZone
 * address: 0x02160FB4
 * packet: pkt_ov010_02160FB4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GAMESYSTEM_GetMyPlayerWork 0x020120F8 thumb
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   ZONEDATA_IsUnionRoom 0x02013CC8 thumb
 *   ZONEDATA_IsZone96Pair 0x02013CE0 thumb
 */

typedef unsigned int u32;
typedef unsigned char  u8;
struct Ctx;
extern u8 *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
typedef unsigned short u16;
struct Rec44;
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 ZONEDATA_IsUnionRoom(u32);
extern u32 ZONEDATA_IsZone96Pair(u32);
int EVENT_FIELD_PROCLINK_IsSpecialZone(void *p) { unsigned short id=GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAMESYSTEM_GetMyPlayerWork(p)); if(ZONEDATA_IsUnionRoom(id)==1) return 1; if(ZONEDATA_IsZone96Pair(id)==1) return 3; return 0; }
