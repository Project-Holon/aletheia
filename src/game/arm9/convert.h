#ifndef GAME_ARM9_CONVERT_H
#define GAME_ARM9_CONVERT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of convert.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../sdk_rtc.h"

s32 RTC_ConvertDateToDay(RTCDate *date);
s32 RTCi_ConvertTimeToSecond(RTCTime *time);
s64 RTC_ConvertDateTimeToSecond(RTCDate *date, RTCTime *time);
void RTC_ConvertDayToDate(RTCDate *date, s32 day);
void RTCi_ConvertSecondToTime(RTCTime *time, s32 sec);
void RTC_ConvertSecondToDateTime(RTCDate *date, RTCTime *time, s64 sec);
RTCWeek RTC_GetDayOfWeek(RTCDate *date);
/* END mkheaders: generated region */

#endif
