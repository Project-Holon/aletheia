/*
 * file:     calender.c
 * unit:     yes
 * function: CALENDER_Create, CALENDER_Delete, CALENDER_GetWeatherThunk, CALENDER_ClearResources, CALENDER_OpenArchive, CALENDER_CloseArchive, CALENDER_GetWeather, CALENDER_GetWeatherOnDate, CALENDER_LoadZoneTable, CALENDER_FindZoneOffset, CALENDER_GetDayOfYear
 * address:  0x021647A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_skill_check.c, calender.c, game_beacon_search.c, game_beacon_accessor.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   CalenderFileName 0x021729B0 data ov010 a1
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   FIELD_CLOCK_GetMonth 0x021690D0 thumb ov010
 *   FIELD_CLOCK_GetDay 0x021690E0 thumb ov010
 *   ZONEDATA_GetWeatherId  0x02013C10  thumb
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 *   DaysPerMonthTable  0x02171C20  data  ov010  a1
 */
#include "field_skill_check_shared_types.h"

struct ArcFile;

#define CALENDER_ZONE_MAX 68

#define CALENDER_ARC_ID 0x61

/* Days per month: index 0 is unused, February has 29 days. */
typedef struct DaysPerMonth {
    u8 days[13];
} DaysPerMonth;

typedef struct CalenderZoneEntry {
    u16 zoneId;
    u16 offset;       /* offset of the zone's 366 daily weather bytes in the archive */
} CalenderZoneEntry;

/* Weather calendar, 0x11C bytes. */
typedef struct CalenderWork {
    u16 heapId;
    struct GameData *gameData;
    struct ArcFile *arc;
    CalenderZoneEntry zones[CALENDER_ZONE_MAX];
} CalenderWork;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);

extern u32 GFL_HEAP_Free(void *ptr);

extern void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID);

extern void ARC_TOOL_DeleteHandle(void *handle);

extern int FIELD_CLOCK_GetMonth(struct GameData *gameData);

extern int FIELD_CLOCK_GetDay(struct GameData *gameData);

extern u8 ZONEDATA_GetWeatherId(u32 zoneId);
struct ArcHandle;

extern void ARC_TOOL_ReadHandleMemberRange(struct ArcHandle *arc, u32 memberIdx, u32 offset, u32 size, void *dst);

extern const char CalenderFileName[];

extern const DaysPerMonth DaysPerMonthTable;

CalenderWork *CALENDER_Create(struct GameData *gameData, u32 heapId);

void CALENDER_Delete(CalenderWork *calender);

u32 CALENDER_GetWeatherThunk(CalenderWork *calender, unsigned int zoneId);

void CALENDER_ClearResources(CalenderWork *calender);

struct ArcFile *CALENDER_OpenArchive(CalenderWork *calender);

void CALENDER_CloseArchive(CalenderWork *calender);

u8 CALENDER_GetWeather(CalenderWork *calender, u32 zoneId);

u8 CALENDER_GetWeatherOnDate(CalenderWork *calender, u32 zoneId, u8 month, u8 day);

void CALENDER_LoadZoneTable(CalenderWork *calender);

u32 CALENDER_FindZoneOffset(CalenderWork *calender, u32 zoneId);

u16 CALENDER_GetDayOfYear(int month, int day);

/*
 * Allocates the weather calendar and loads its archive and zone table.
 * The file name and line (0x53) given to the allocator are those of the
 * original call site.
 */
CalenderWork *CALENDER_Create(struct GameData *gameData, u32 heapId)
{
    CalenderWork *calender;

    calender = GFL_HEAP_Alloc(heapId, sizeof(CalenderWork), 0, CalenderFileName, 0x53);
    CALENDER_ClearResources(calender);
    calender->heapId = heapId;
    calender->gameData = gameData;
    CALENDER_OpenArchive(calender);
    CALENDER_LoadZoneTable(calender);
    return calender;
}

/* Closes the archive and frees the weather calendar. */
void CALENDER_Delete(CalenderWork *calender)
{
    CALENDER_CloseArchive(calender);
    GFL_HEAP_Free(calender);
}

/*
 * Tail call to CALENDER_GetWeather through a pool word and `bx r3`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Unlabelled in the
 * listing: no prologue, and its only caller is ISS_SWITCH_GetSubscreenMode in arm9.
 */
u32 CALENDER_GetWeatherThunk(CalenderWork *calender, unsigned int zoneId)
{
    return CALENDER_GetWeather(calender, zoneId);
}

/* Clears the calendar fields that hold resources. */
void CALENDER_ClearResources(CalenderWork *calender)
{

    calender->heapId = 0;
    calender->gameData = 0;
    calender->arc = 0;
}

/* Opens the calendar archive. */
struct ArcFile *CALENDER_OpenArchive(CalenderWork *calender)
{
    struct ArcFile *arc;

    arc = ARC_TOOL_CreateHandle(CALENDER_ARC_ID, calender->heapId);
    calender->arc = arc;
    return arc;
}

/* Closes the calendar archive. */
void CALENDER_CloseArchive(CalenderWork *calender)
{
    ARC_TOOL_DeleteHandle(calender->arc);
    calender->arc = 0;
}

/* Weather of a zone on the current date. */
u8 CALENDER_GetWeather(CalenderWork *calender, u32 zoneId)
{
    int month = FIELD_CLOCK_GetMonth(calender->gameData);
    int day = FIELD_CLOCK_GetDay(calender->gameData);

    return CALENDER_GetWeatherOnDate(calender, zoneId, month, day);
}

/*
 * Weather of a zone on a date: reads the byte at the zone's offset plus
 * the day of the year. A zone without a calendar entry takes its default
 * weather.
 */
u8 CALENDER_GetWeatherOnDate(CalenderWork *calender, u32 zoneId, u8 month, u8 day)
{
    u32 zoneOffset = CALENDER_FindZoneOffset(calender, zoneId);
    u8 weather;
    u16 position;

    if (zoneOffset == 0xffff) {
        return ZONEDATA_GetWeatherId(zoneId);
    }
    position = zoneOffset + CALENDER_GetDayOfYear(month, day);
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)calender->arc, 0, position, 1, &weather);
    return weather;
}

/* Loads the zone offset table (archive file 1, from byte 2). */
void CALENDER_LoadZoneTable(CalenderWork *calender)
{
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)calender->arc, 1, 2, sizeof(calender->zones), calender->zones);
}

/* Archive offset of a zone's calendar, or 0xFFFF when the zone has none. */
u32 CALENDER_FindZoneOffset(CalenderWork *calender, u32 zoneId)
{
    int i;
    u32 zoneOffset = 0xffff;

    for (i = 0; i < CALENDER_ZONE_MAX; i++) {
        if (zoneId == calender->zones[i].zoneId) {
            zoneOffset = calender->zones[i].offset;
            break;
        }
    }
    return zoneOffset;
}

/*
 * Zero-based day of the year (leap year layout): the days of the months
 * before `month`, plus day - 1. The month table is copied to the stack
 * from the pool copy at DaysPerMonthTable.
 */
u16 CALENDER_GetDayOfYear(int month, int day)
{
    DaysPerMonth daysPerMonth = DaysPerMonthTable;
    int i;
    u16 sum = 0;

    for (i = 0; i < month; i++) {
        sum = sum + daysPerMonth.days[i];
    }
    return sum + (u16)(day - 1);
}
