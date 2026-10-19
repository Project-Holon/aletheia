/*
 * file:     zone_weather.c
 * unit:     yes
 * function: WEATHER_GetZoneWeatherId, WEATHER_IsSeasonSynced, WEATHER_StoreZoneWeatherId, WEATHER_RefreshStoredWeatherId, WEATHER_GetAreaOwnerWeather, WEATHER_GetSpecialPowerWeather, WEATHER_GetBirthdayWeather
 * address:  0x0202C794
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from iss_switch_set.c, iss_switch.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMusicalWork  0x0201297C  thumb
 *   MOVE_POKEMON_FindEntryByZone  0x0215E6A8  thumb
 *   CALENDER_GetWeatherThunk  0x021647E8  thumb  ov010
 *   ZONEDATA_GetWeatherId  0x02013C10  thumb
 *   MOVE_POKEMON_IsAnyEntryActive  0x0215E6F8  thumb ov010
 *   GAME_DATA_GetWeatherId  0x02012994  thumb
 *   GAME_DATA_SetWeatherId  0x020129A0  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   ZONEDATA_IsZoneGroup118To13C  0x02013D74  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   INTRUDE_COMM_GetAreaOwnerVersion  0x0215843C  thumb
 *   gTbl_0209FFF4  0x0209FFF4  data
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   ZONEDATA_IsRawZone176Or17A   0x02014044  thumb
 *   GF_STANDARD_GetCachedDate  0x0203F4E4  arm
 *   APP_ENV_GetOwnerColorAndBirthMonth   0x0202EB60  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   COMM_PLAYER_SUPPORT_GetSeasonFromClock  0x0202E888  thumb
 */
#include "iss_switch_sys_shared_types.h"
#include "iss_switch_set_shared_types.h"
#include "iss_switch_shared_types.h"

struct Ctx;

struct Pair {
    u16 a;
    u16 b;
};

struct RtcDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);

extern u32 GAME_DATA_GetMusicalWork(const struct BigObj *p);

extern u32 MOVE_POKEMON_FindEntryByZone(void *a, u16 b);

extern u32 CALENDER_GetWeatherThunk(void *arg, unsigned int b);

extern u32 ZONEDATA_GetWeatherId(u32 id);

extern void GAME_DATA_SetWeatherId(struct BigObj *p, u8 v);

extern int MOVE_POKEMON_IsAnyEntryActive(int gameData);

extern u8 GAME_DATA_GetWeatherId(const struct BigObj *p);

extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);

extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);

extern int ZONEDATA_IsZoneGroup118To13C(u32 key);

extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);

extern s32 INTRUDE_COMM_GetAreaOwnerVersion(u32 a);

extern u32 GPOWER_GetSpecialPowerId(void);

extern u32 ZONEDATA_IsRawZone176Or17A(u32 id);

extern void GF_STANDARD_GetCachedDate(struct RtcDate *date);

extern void APP_ENV_GetOwnerColorAndBirthMonth(u8 *out1, u8 *out2);

u32 WEATHER_GetZoneWeatherId(void *fieldSys, u32 zoneId);

int WEATHER_IsSeasonSynced(int gameData);

void WEATHER_StoreZoneWeatherId(struct Ctx *p, u32 zoneId);

void WEATHER_RefreshStoredWeatherId(u8 *gameData, int zoneId);

s32 WEATHER_GetAreaOwnerWeather(void *fieldSys, u32 gameData, u32 zoneId);

s32 WEATHER_GetSpecialPowerWeather(void *fieldSys, u32 gameData, u32 zoneId);

u32 WEATHER_GetBirthdayWeather(void *a, void *b, u32 c);

extern struct Pair gTbl_0209FFF4[];

/*
 * note:     wave 16: promoted.  0x021647E8 is the unlabelled ov010 tail-call
 *           thunk matched in src/matched/CALENDER_GetWeatherThunk.c (`matched, overlay`
 *           under the ov010 hint); 0x0202C8B8 now resolves as `matched`.
 *
 * A chain of four probes, each returning a u8 reason code unless it comes
 * back 0xffff ("nothing to say"); the sentinel is kept in a callee-saved
 * register, which is why it is one pool word and four `cmp r0, r7`.
 */
u32 WEATHER_GetZoneWeatherId(void *fieldSys, u32 zoneId)
{
    u32 ctx = (u32)GAMESYSTEM_GetGameData(fieldSys);
    u32 saved = GAME_DATA_GetMusicalWork((const struct BigObj *)ctx);
    u32 r;

    r = MOVE_POKEMON_FindEntryByZone((void *)ctx, (u16)zoneId);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = WEATHER_GetAreaOwnerWeather(fieldSys, ctx, zoneId);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = WEATHER_GetSpecialPowerWeather(fieldSys, ctx, zoneId);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = WEATHER_GetBirthdayWeather(fieldSys, (void *)ctx, zoneId);
    if (r != 0xffff) {
        return (u8)r;
    }
    if (WEATHER_IsSeasonSynced(ctx) != 0) {
        return (u8)CALENDER_GetWeatherThunk((void *)saved, (u16)zoneId);
    }
    return (u8)ZONEDATA_GetWeatherId((u16)zoneId);
}

int WEATHER_IsSeasonSynced(int gameData){ int season, clockSeason; season = GAME_DATA_GetSeason(gameData); clockSeason = COMM_PLAYER_SUPPORT_GetSeasonFromClock((int)season); if ((unsigned int)((season + 0)) == (unsigned int)(clockSeason)) {  return 1; } else {  return 0; } }

void WEATHER_StoreZoneWeatherId(struct Ctx *fieldSys, u32 zoneId)
{
    struct BigObj *obj = GAMESYSTEM_GetGameData(fieldSys);
    u32 r = WEATHER_GetZoneWeatherId(fieldSys, zoneId);

    GAME_DATA_SetWeatherId(obj, (u8)r);
}

/*
 * note:     2026-09-23 (wave 15): EXACT with no C change; the ov010 call
 *           at +0x34 now resolves sole-ref/code.  The MATCH text below is history.
 *
 * Blocked at MATCH on the `label`/`matched` classes: all 82 concrete bytes
 * are correct (88-byte extent, the last 6 bytes being the pool word 0xffff),
 * but the PC-relative call at +0x0034 to MOVE_POKEMON_IsAnyEntryActive in ov010 has no
 * witness: 0x0215E6F8 has exactly one branch reference image-wide and it is
 * that call, so no cut frees it, and the address is inside BOTH ov009's and
 * ov010's windows, so the `label` class refuses it even with the ov010 hint
 * on the symbols: line.  The unblock is a `matched` entry at 0x0215E6F8
 * (or any additional caller of it anywhere in the image).
 *
 * The range check must wrap in 32 bits: `(u32)(r - 6) > 1`, `(r - 6) > 1u`
 * and `(unsigned)(r - 6) > 1` all give the original's bare
 * `subs r0, r1, #6; cmp r0, #1; bhi`.  The u16-cast spelling
 * `(u16)(r - 6) > 1` is wrong by two instructions: it re-truncates the
 * difference with `lsls r0, r0, #0x10; lsrs r0, r0, #0x10` first.
 *
 * The first call takes the actor pointer as well as the truncated id,
 * `MOVE_POKEMON_FindEntryByZone(a0, (u16)a1)`: r0 is still r0 at the call and the id is
 * built in r1.  Declaring it as a one-argument call puts the id in r0 and
 * shifts the whole prologue.
 */
void WEATHER_RefreshStoredWeatherId(u8 *gameData, int zoneId)
{
    u32 v;
    u16 r;

    v = MOVE_POKEMON_FindEntryByZone(gameData, (u16)zoneId);
    r = (u16)(u32)GAME_DATA_GetWeatherId((const struct BigObj *)gameData);
    if (v != 0xffff) {
        GAME_DATA_SetWeatherId((struct BigObj *)gameData, (u8)v);
        return;
    }
    if ((u32)(r - 6) > 1) {
        return;
    }
    if (MOVE_POKEMON_IsAnyEntryActive((int)gameData) != 1) {
        return;
    }
    GAME_DATA_SetWeatherId((struct BigObj *)gameData, (u8)ZONEDATA_GetWeatherId((u16)zoneId));
}

/*
 * The two ABS32 pool words holding 0x0209FFF4 / 0x0209FFF6 are both inside
 * this function; grep over asm/ finds no third pool word anywhere in the
 * image, so the data table has no witness outside the compared range and
 * both relocation sites stay wildcarded. Unstuck by any other function that
 * also points at gTbl_0209FFF4, or by a data-symbol table entry.
 */
s32 WEATHER_GetAreaOwnerWeather(void *fieldSys, u32 gameData, u32 zoneId)
{
    u32 eventWork;
    u32 areaOwner;
    u32 i;

    eventWork = GAME_DATA_GetEventWork((const struct BigObj *)gameData);
    areaOwner = GAMESYSTEM_GetGameComm(fieldSys);
    if (ZONEDATA_IsZoneGroup118To13C((u16)zoneId) == 0 || areaOwner == 0) {
        goto done;
    }
    for (i = 0; i < 0x19; i++) {
        if (zoneId == gTbl_0209FFF4[i].a) {
            if (ZONEDATA_CheckEventFlag((void *)eventWork, gTbl_0209FFF4[i].b) == 0) {
                if (INTRUDE_COMM_GetAreaOwnerVersion(areaOwner) == 0x14) return 0xd;
                return 0xe;
            }
            if (INTRUDE_COMM_GetAreaOwnerVersion(areaOwner) == 0x14) return 0xa;
            return 0xb;
        }
    }
done:
    return 0xffff;
}

s32 WEATHER_GetSpecialPowerWeather(void *fieldSys, u32 gameData, u32 zoneId)
{
    u32 eventWork = GAME_DATA_GetEventWork((const struct BigObj *)gameData);

    if (zoneId == 0x151) {
        if (ZONEDATA_CheckEventFlag((void *)eventWork, 0x96f) != 0) {
            if (GPOWER_GetSpecialPowerId() == 0x15) return 7;
            return 6;
        }
    }
    return 0xffff;
}

u32 WEATHER_GetBirthdayWeather(void *fieldSys, void *gameData, u32 zoneId)
{
    u8 buf[2];
    struct RtcDate date;

    if (!ZONEDATA_IsRawZone176Or17A((u16)zoneId)) {
        goto fail;
    }
    GF_STANDARD_GetCachedDate(&date);
    APP_ENV_GetOwnerColorAndBirthMonth(&buf[1], &buf[0]);
    if (date.month != buf[1]) {
        goto fail;
    }
    if (date.day != buf[0]) {
        goto fail;
    }
    return 0;

fail:
    return 0xFFFF;
}
