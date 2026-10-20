/*
 * file:     formchange_shaymin.c
 * unit:     yes
 * function: FORMCHANGE_RevertShaymin, FORMCHANGE_RevertShayminIfTimeOfDayChanged, FORMCHANGE_RevertShayminAtNight, FORMCHANGE_RevertShayminAndRegister
 * address:  0x0216A298
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from scrcmd_trialhouse.c by tools/splitfile.py.
 *
 * symbols:
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   TIMEZONE_GetLight  0x02011400  thumb
 *   ZUKAN_SAVE_RegisterSeen  0x0200CFA0  thumb
 */
#include "script_work_types.h"
#include "formchange_shaymin_shared_types.h"

/* Hour and minute as the RTC code lays them out. */
typedef struct TimeOfDay {
    int hour;
    int minute;
} TimeOfDay;

#include "../arm9/zukan_save.h"
struct ZukanSave;


/* Party and Pokemon. */
#include "../arm9/pokeparty.h"


#include "../arm9/poke_tool.h"


#include "../arm9/timezone.h"

void FORMCHANGE_RevertShaymin(struct GameData *gameData, struct Party *party);

int FORMCHANGE_RevertShayminIfTimeOfDayChanged(struct GameData *gameData, struct Party *party, int elapsedMinutes, TimeOfDay *time, int season);

int FORMCHANGE_RevertShayminAtNight(struct GameData *gameData, struct Party *party, u32 *hour, int season);

void FORMCHANGE_RevertShayminAndRegister(struct GameData *gameData, struct Party *party);

/* Species and form ids. */
#define SPECIES_SHAYMIN 0x1EC

#define SHAYMIN_FORM_SKY 1

#define SHAYMIN_FORM_LAND 0

/* Table columns of TIMEZONE_GetLight: first hour of the day and first hour of the night. */
#define TIME_ZONE_DAY_START 0

#define TIME_ZONE_NIGHT_START 3

/* Shaymin sky forme back to land forme for every Shaymin in the party. */
void FORMCHANGE_RevertShaymin(struct GameData *gameData, struct Party *party)
{
    int i;
    int count;
    struct PokemonParam *mon;
    int species;
    int form;

    count = POKEPARTY_GetCount(party);
    for (i = 0; i < count; i++) {
        mon = POKEPARTY_GetMember(party, i);
        species = POKE_TOOL_GetPartyValue(mon, PARAM_SPECIES, 0);
        form = POKE_TOOL_GetPartyValue(mon, PARAM_FORM, 0);
        if (species == SPECIES_SHAYMIN && form == SHAYMIN_FORM_SKY)
            POKE_TOOL_ChangeForm(mon, SHAYMIN_FORM_LAND);
    }
}

/*
 * Reverts Shaymin when more time has passed than the current time of day has
 * lasted so far (elapsedMinutes against the minutes since the day or night began).
 * Returns 1 when the party was changed.
 */
int FORMCHANGE_RevertShayminIfTimeOfDayChanged(struct GameData *gameData, struct Party *party, int elapsedMinutes, TimeOfDay *time, int season)
{
    int nightStart;
    int dayStart;
    int hour;
    int hoursSince;

    nightStart = TIMEZONE_GetLight(season, TIME_ZONE_NIGHT_START);
    dayStart = TIMEZONE_GetLight(season, TIME_ZONE_DAY_START);
    hour = time->hour;
    if (!((u32)hour < (u32)nightStart && (u32)hour >= (u32)dayStart)) {
        hoursSince = hour;
        if (hoursSince < dayStart) {
            hoursSince += 24;
        }
        hoursSince = hoursSince - nightStart;
        if (time->minute + hoursSince * 60 < elapsedMinutes + 1) {
            FORMCHANGE_RevertShaymin(gameData, party);
            return 1;
        }
        return 0;
    }
    hoursSince = hour - dayStart;
    if (time->minute + hoursSince * 60 < elapsedMinutes) {
        FORMCHANGE_RevertShaymin(gameData, party);
        return 1;
    }
    return 0;
}

/* At night: reverts Shaymin and records the form change. Returns 1 at night. */
int FORMCHANGE_RevertShayminAtNight(struct GameData *gameData, struct Party *party, u32 *hour, int season)
{
    u32 nightStart;
    u32 dayStart;
    int result;

    nightStart = TIMEZONE_GetLight(season, TIME_ZONE_NIGHT_START);
    dayStart = TIMEZONE_GetLight(season, TIME_ZONE_DAY_START);
    result = 0;
    if (!(*hour < nightStart && *hour >= dayStart)) {
        FORMCHANGE_RevertShayminAndRegister(gameData, party);
        result = 1;
    }
    return result;
}

/* Reverts every sky forme Shaymin, registering the first one in the Pokedex. */
void FORMCHANGE_RevertShayminAndRegister(struct GameData *gameData, struct Party *party)
{
    int registered;
    int count;
    struct PokedexSave *pokedex;
    int i;
    struct PokemonParam *mon;
    int species;
    int form;

    pokedex = ZUKAN_SAVE_GetFromGameData(gameData);
    registered = 0;
    count = POKEPARTY_GetCount(party);
    for (i = 0; i < count; i++) {
        mon = POKEPARTY_GetMember(party, i);
        species = POKE_TOOL_GetPartyValue(mon, PARAM_SPECIES, 0);
        form = POKE_TOOL_GetPartyValue(mon, PARAM_FORM, 0);
        if (species == SPECIES_SHAYMIN && form == SHAYMIN_FORM_SKY) {
            POKE_TOOL_ChangeForm(mon, SHAYMIN_FORM_LAND);
            if (registered == 0) {
                ZUKAN_SAVE_RegisterSeen((struct ZukanSave *)pokedex, mon);
                registered = 1;
            }
        }
    }
}
