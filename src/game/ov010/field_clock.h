#ifndef GAME_OV010_FIELD_CLOCK_H
#define GAME_OV010_FIELD_CLOCK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_clock.c, prototypes copied from their definitions. */

struct FieldClock;
typedef struct FieldClock FieldClock;

#include "../ov010/fld_btl_inst_tool_shared_types.h"
#include "../sdk_rtc.h"
#include "../sdk_rtc.h"

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
/* END mkheaders: generated region */

#endif
