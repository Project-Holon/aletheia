/*
 * file:     field_clock.c
 * unit:     yes
 * function: FIELD_CLOCK_Update, FIELD_CLOCK_CalcElapsed, FIELD_CLOCK_UpdateDays, FIELD_CLOCK_UpdateMinutes, FIELD_CLOCK_GetDate, FIELD_CLOCK_GetTimeZone, FIELD_CLOCK_GetMonth, FIELD_CLOCK_GetDay, FIELD_CLOCK_GetWeek, FIELD_CLOCK_GetHour, FIELD_CLOCK_GetMinute, FIELD_CLOCK_SaveTimestamp, FIELD_CLOCK_GetCounter
 * address:  0x02168EEC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from fld_btl_inst_tool.c by tools/splitfile.py.
 *
 * symbols:
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   CONSOLE_STAMP_GetDailyClock  0x02008B14  thumb
 *   GF_STANDARD_CopyCachedRtc  0x0203F49C  arm
 *   DAILY_CLOCK_Spend  0x02008BE0  thumb
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   RTC_ConvertDateToDay  0x02088F58  arm
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_ClearTimeFlags  0x020143F0  thumb
 *   MOVE_POKEMON_SAVE_RollStartLocation  0x0200D440  thumb
 *   POKERUS_DecreaseDays  0x0201B100  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   RECORD_FoldPairs  0x02008E30  thumb
 *   WIFI_HISTORY_GetBlock  0x02009470  thumb
 *   WIFI_HISTORY_PromoteVisitedStates  0x0200952C  thumb
 *   FIELD_WFBC_DATA_LOCAL_AdvanceDays  0x021862A8  thumb
 *   SYMBOL_SAVE_GetBitBlock  0x0200E394  thumb
 *   MISC_SAVEDATA_FoldTally  0x0200E518  thumb
 *   IRC_RANKING_GetFromSave  0x0200A8A0  thumb
 *   IRC_RANKING_ClearNewFlags  0x0200AB04  thumb
 *   POKEPARTY_GetSaveData 0x0201AD0C thumb
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   BEACON_GetBlock 0x0200C0F0 thumb
 *   BEACON_SubGatePoints 0x0200C3C0 thumb
 *   TIMEZONE_GetTimeZoneOfHour  0x020113F0  thumb
 *   GF_STANDARD_GetRtcTimestamp 0x0203F524 arm
 *   DAILY_CLOCK_HasAllowance  0x02008BD0  thumb
 *   FORMCHANGE_RevertShayminIfTimeOfDayChanged  0x0216A2EC  thumb  ov010
 */
#include "fld_btl_inst_tool_shared_types.h"

typedef long long s64;

typedef struct PartySave PartySave;

/* ---- Field clock ---- */
typedef struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
} RTCDate;

typedef struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
} RTCTime;

/* Clock checkpoint kept in the save (reached through the save control). */
typedef struct FieldClock {
    int valid;                  /* 0x00 */
    RTCDate date;               /* 0x04 */
    RTCTime time;               /* 0x14 */
    int dayNumber;              /* 0x20 */
    u8 reserved24[8];
    u8 timestamp[8];            /* 0x2C: u64 stored unaligned */
} FieldClock;

extern Party *GAME_DATA_GetMyParty(GameData *gameData);

extern SaveControl *GAME_DATA_GetSaveControl(GameData *gameData);

extern FieldClock *CONSOLE_STAMP_GetDailyClock(SaveControl *saveControl);

extern void GF_STANDARD_CopyCachedRtc(RTCDate *date, RTCTime *time);

extern void DAILY_CLOCK_Spend(FieldClock *clock, u32 minutes);

extern long long RTC_ConvertDateTimeToSecond(RTCDate *date, RTCTime *time);

extern int RTC_ConvertDateToDay(RTCDate *date);

extern u32 GAME_DATA_GetEventWork(GameData *gameData);

extern void ZONEDATA_ClearTimeFlags(u32 eventWork);

extern void MOVE_POKEMON_SAVE_RollStartLocation(SaveControl *saveControl);

extern void POKERUS_DecreaseDays(Party *party, int days);

extern void *GAME_DATA_GetTrainerRecord(GameData *gameData);

extern void RECORD_FoldPairs(void *trainerRecord);

extern void *WIFI_HISTORY_GetBlock(SaveControl *saveControl);

extern void WIFI_HISTORY_PromoteVisitedStates(void *obj);

extern void FIELD_WFBC_DATA_LOCAL_AdvanceDays(GameData *gameData, int days, int a);

extern void *SYMBOL_SAVE_GetBitBlock(SaveControl *saveControl);

extern void MISC_SAVEDATA_FoldTally(void *obj);

extern void *IRC_RANKING_GetFromSave(SaveControl *saveControl);

extern void IRC_RANKING_ClearNewFlags(void *obj);

extern PartySave *POKEPARTY_GetSaveData(SaveControl *saveControl);

extern u8 GAME_DATA_GetSeason(GameData *gameData);

extern void *BEACON_GetBlock(SaveControl *saveControl);

extern void BEACON_SubGatePoints(void *obj, u16 v);

extern int TIMEZONE_GetTimeZoneOfHour(int season, int hour);

extern u64 GF_STANDARD_GetRtcTimestamp(void);

extern int DAILY_CLOCK_HasAllowance(const FieldClock *clock);

int FORMCHANGE_RevertShayminIfTimeOfDayChanged(GameData *gameData, PartySave *partySave, int minutes, RTCTime *time, int season);

void FIELD_CLOCK_Update(GameData *gameData);

int FIELD_CLOCK_CalcElapsed(FieldClock *clock, RTCDate *date, RTCTime *time, int *outDays, int *outMinutes);

void FIELD_CLOCK_UpdateDays(GameData *gameData, int days);

void FIELD_CLOCK_UpdateMinutes(GameData *gameData, int minutes, RTCTime *time);

RTCDate *FIELD_CLOCK_GetDate(GameData *gameData);

int FIELD_CLOCK_GetTimeZone(GameData *gameData);

int FIELD_CLOCK_GetMonth(GameData *gameData);

int FIELD_CLOCK_GetDay(GameData *gameData);

int FIELD_CLOCK_GetWeek(GameData *gameData);

int FIELD_CLOCK_GetHour(GameData *gameData);

int FIELD_CLOCK_GetMinute(GameData *gameData);

void FIELD_CLOCK_SaveTimestamp(GameData *gameData);

int FIELD_CLOCK_GetCounter(GameData *gameData);

/*
 * Field clock update (called from the field map on every day or minute
 * change check): compares the RTC with the saved checkpoint and runs the
 * minute and day updates for the time that has passed.
 */
void FIELD_CLOCK_Update(GameData *gameData)
{
    RTCDate date;
    RTCTime time;
    int days;
    int minutes;
    FieldClock *clock = CONSOLE_STAMP_GetDailyClock(GAME_DATA_GetSaveControl(gameData));
    if (clock->valid == 0)
        return;
    GF_STANDARD_CopyCachedRtc(&date, &time);
    if (FIELD_CLOCK_CalcElapsed(clock, &date, &time, &days, &minutes) == 0)
        return;
    if (minutes == 0 && days != 0)
        return;
    if (minutes != 0) {
        DAILY_CLOCK_Spend(clock, minutes);
        FIELD_CLOCK_UpdateMinutes(gameData, minutes, &time);
    }
    if (days != 0)
        FIELD_CLOCK_UpdateDays(gameData, days);
}

/*
 * Compares the RTC with the checkpoint. Returns 0 when the clock went
 * backwards (the checkpoint is reset to now), otherwise 1 with the whole
 * minutes passed and the day number difference (0 when the day is the same).
 */
int FIELD_CLOCK_CalcElapsed(FieldClock *clock, RTCDate *date, RTCTime *time, int *outDays, int *outMinutes)
{
    s64 savedSeconds = RTC_ConvertDateTimeToSecond(&clock->date, &clock->time);
    s64 nowSeconds = RTC_ConvertDateTimeToSecond(date, time);
    int dayNumber = RTC_ConvertDateToDay(date);
    int minutes;
    *outDays = 0;
    *outMinutes = 0;
    if (nowSeconds < savedSeconds) {
        clock->date = *date;
        clock->time = *time;
        clock->dayNumber = dayNumber;
        return 0;
    }
    minutes = (int)((nowSeconds - savedSeconds) / 60);
    if (minutes > 0) {
        int dayDiff;
        *outMinutes = minutes;
        clock->date = *date;
        clock->time = *time;
        dayDiff = dayNumber - clock->dayNumber;
        if (dayDiff != 0) {
            *outDays = dayDiff;
            clock->dayNumber = dayNumber;
        }
    }
    return 1;
}

/*
 * Day update: clears the day flags and ages the party and the other
 * per-day state.
 *
 * evidence: 0x0200E518 is an unlabelled ARM9 leaf ("push {r4, r5, r6, r7}",
 * no lr, right after the "pop {r4, pc}" at 0x0200E516) that the prologue
 * sweep misses.  The bl at +0x52 is its only reference in the image; its
 * start is seeded in layout/function_starts.txt, and the callee itself is
 * matched EXACT* (src/matched/arm9/MISC_SAVEDATA_FoldTally.c), so +0x52 attests as
 * `matched`.
 */
void FIELD_CLOCK_UpdateDays(GameData *gameData, int days)
{
    SaveControl *saveControl;
    FIELD_CLOCK_GetCounter(gameData);
    saveControl = GAME_DATA_GetSaveControl(gameData);
    ZONEDATA_ClearTimeFlags(GAME_DATA_GetEventWork(gameData));
    MOVE_POKEMON_SAVE_RollStartLocation(saveControl);
    POKERUS_DecreaseDays(GAME_DATA_GetMyParty(gameData), days);
    RECORD_FoldPairs(GAME_DATA_GetTrainerRecord(gameData));
    WIFI_HISTORY_PromoteVisitedStates(WIFI_HISTORY_GetBlock(saveControl));
    FIELD_WFBC_DATA_LOCAL_AdvanceDays(gameData, days, 4);
    MISC_SAVEDATA_FoldTally(SYMBOL_SAVE_GetBitBlock(saveControl));
    IRC_RANKING_ClearNewFlags(IRC_RANKING_GetFromSave(saveControl));
}

/*
 * Minute update: runs the Shaymin form check with the current time and
 * passes the current time on to the save.
 *
 * extent: trailing two-byte alignment padding.
 * interface: final u16 argument follows the original lsls/lsrs #16 pair.
 */
void FIELD_CLOCK_UpdateMinutes(GameData *gameData, int minutes, RTCTime *time) { PartySave *partySave=POKEPARTY_GetSaveData(GAME_DATA_GetSaveControl(gameData)); FORMCHANGE_RevertShayminIfTimeOfDayChanged(gameData,partySave,minutes,time,GAME_DATA_GetSeason(gameData)); BEACON_SubGatePoints(BEACON_GetBlock(GAME_DATA_GetSaveControl(gameData)),minutes); }

/*
 * Date of the clock checkpoint.
 */
RTCDate *FIELD_CLOCK_GetDate(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;


    saveControl = GAME_DATA_GetSaveControl(gameData);
    clock = CONSOLE_STAMP_GetDailyClock(saveControl);
    return &clock->date;
}

/*
 * Time zone of the day (by season and hour of the checkpoint).
 */
int FIELD_CLOCK_GetTimeZone(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;

    saveControl = GAME_DATA_GetSaveControl(gameData);
    clock = CONSOLE_STAMP_GetDailyClock(saveControl);
    return TIMEZONE_GetTimeZoneOfHour(GAME_DATA_GetSeason(gameData), clock->time.hour);
}

int FIELD_CLOCK_GetMonth(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;


    saveControl = GAME_DATA_GetSaveControl(gameData);
    clock = CONSOLE_STAMP_GetDailyClock(saveControl);
    return clock->date.month;
}

int FIELD_CLOCK_GetDay(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;


    saveControl = GAME_DATA_GetSaveControl(gameData);
    clock = CONSOLE_STAMP_GetDailyClock(saveControl);
    return clock->date.day;
}

int FIELD_CLOCK_GetWeek(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;


    saveControl = GAME_DATA_GetSaveControl(gameData);
    clock = CONSOLE_STAMP_GetDailyClock(saveControl);
    return clock->date.week;
}

int FIELD_CLOCK_GetHour(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;


    saveControl = GAME_DATA_GetSaveControl(gameData);
    clock = CONSOLE_STAMP_GetDailyClock(saveControl);
    return clock->time.hour;
}

int FIELD_CLOCK_GetMinute(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;


    saveControl = GAME_DATA_GetSaveControl(gameData);
    clock = CONSOLE_STAMP_GetDailyClock(saveControl);
    return clock->time.minute;
}

void FIELD_CLOCK_SaveTimestamp(GameData *gameData) { FieldClock *clock = CONSOLE_STAMP_GetDailyClock(GAME_DATA_GetSaveControl(gameData)); *(u64 *)(clock->timestamp) = GF_STANDARD_GetRtcTimestamp(); }

int FIELD_CLOCK_GetCounter(GameData *gameData)
{
    SaveControl *saveControl;
    FieldClock *clock;


    saveControl = GAME_DATA_GetSaveControl(gameData);
    clock = CONSOLE_STAMP_GetDailyClock(saveControl);
    return DAILY_CLOCK_HasAllowance(clock);
}
