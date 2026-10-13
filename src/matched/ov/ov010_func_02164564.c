/*
 * function: EVENTDATA_SYSTEM_CheckWeatherZone
 * address: 0x02164564
 * packet: pkt_ov010_02164564
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   func_02013E04 0x02013E04 thumb
 *   func_02013C50 0x02013C50 thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;
struct Rec44;
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 func_02013E04(u32 id);
extern u32 func_02013C50(u32 id);
int EVENTDATA_SYSTEM_CheckWeatherZone(void *a, void *b, void *c) { u16 v=GAME_DATA_GetPlayerZoneId(c); if (!func_02013E04(v)) return 0; if (func_02013C50(v)) return 1; return 0; }
