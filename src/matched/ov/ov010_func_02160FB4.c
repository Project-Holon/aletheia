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
 *   func_02013CC8 0x02013CC8 thumb
 *   func_02013CE0 0x02013CE0 thumb
 */

typedef unsigned int u32;
typedef unsigned char  u8;
struct Ctx;
extern u8 *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
typedef unsigned short u16;
struct Rec44;
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 func_02013CC8(u32);
extern u32 func_02013CE0(u32);
int EVENT_FIELD_PROCLINK_IsSpecialZone(void *p) { unsigned short id=GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAMESYSTEM_GetMyPlayerWork(p)); if(func_02013CC8(id)==1) return 1; if(func_02013CE0(id)==1) return 3; return 0; }
