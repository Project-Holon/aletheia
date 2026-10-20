#ifndef GAME_OV010_CALENDER_H
#define GAME_OV010_CALENDER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of calender.c, prototypes copied from their definitions. */

struct CalenderWork;
struct GameData;
struct ArcFile;
typedef struct CalenderWork CalenderWork;

#include "../types.h"

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
/* END mkheaders: generated region */

#endif
