/*
 * function: FIELD_ENCOUNT_SetFieldSituation
 * address:  0x021AA304
 * packet:   pkt_ov021_021AA304
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   ZONEDATA_GetFieldEffectSetId  0x02013ED8  thumb
 *   func_0203F4CC  0x0203F4CC  arm
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb
 *   FIELD_ENCOUNT_GetBattleWeather  0x021AA69C  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb
 *   MAP_ATTR_GetBattleBackground  0x021AB580  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct RtcTime { u32 hour; u32 minute; u32 second; };
struct Info {
    u32 f00;
    u32 f04;
    u8 f08;
    u8 f09;
    u16 f0A;
    u8 f0C;
    u8 f0D;
};

struct BigObj;
extern u16 FIELDMAP_GetZoneId(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u8 ZONEDATA_GetFieldEffectSetId(u32 id);
extern u32 FIELD_PLAYER_GetNowAttribute(void **ctx);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern u8 MAP_ATTR_GetBattleBackground(u16 x);
extern void func_0203F4CC(struct RtcTime *time);
extern u8 FIELD_ENCOUNT_GetBattleWeather(void *p);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);

void FIELD_ENCOUNT_SetFieldSituation(struct Info *out, void *a1, void *a2)
{
    struct RtcTime t;
    u16 x = FIELDMAP_GetZoneId(a2);
    void *y = FIELDMAP_GetFieldPlayer(a2);

    out->f00 = ZONEDATA_GetFieldEffectSetId(x);
    out->f04 = MAP_ATTR_GetBattleBackground(MAP_ATTR_GetTerrainId(FIELD_PLAYER_GetNowAttribute(y)));
    out->f0A = x;
    func_0203F4CC(&t);
    out->f0C = t.hour;
    out->f0D = t.minute;
    out->f08 = FIELD_ENCOUNT_GetBattleWeather(a2);
    out->f09 = GAME_DATA_GetSeason(a1);
}
