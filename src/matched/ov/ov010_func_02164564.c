/*
 * function: FIELD_SKILL_CHECK_WeatherZone
 * address: 0x02164564
 * packet: pkt_ov010_02164564
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   ZONEDATA_IsNormalFieldZone 0x02013E04 thumb
 *   ZONEDATA_IsWeatherEnabled 0x02013C50 thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;
struct Rec44;
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 ZONEDATA_IsNormalFieldZone(u32 id);
extern u32 ZONEDATA_IsWeatherEnabled(u32 id);
int FIELD_SKILL_CHECK_WeatherZone(void *a, void *b, void *c) { u16 v=GAME_DATA_GetPlayerZoneId(c); if (!ZONEDATA_IsNormalFieldZone(v)) return 0; if (ZONEDATA_IsWeatherEnabled(v)) return 1; return 0; }
