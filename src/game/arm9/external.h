#ifndef GAME_ARM9_EXTERNAL_H
#define GAME_ARM9_EXTERNAL_H

#include "../sdk_rtc.h"

/* Asynchronous reads: the callback type RTCCallback is private to external.c, so the header spells it out. */
int RTC_GetDateTimeAsync(RTCDate *date, RTCTime *time, void (*callback)(int result, void *arg), void *arg);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of external.c, prototypes copied from their definitions. */

#include "../sdk_rtc.h"
#include "../types.h"

void RTC_Init(void);
RTCResult RTC_GetDate(RTCDate *date);
RTCResult RTC_GetTime(RTCTime *time);
RTCResult RTC_GetDateTime(RTCDate *date, RTCTime *time);
void *RTCEXi_GetCommonCallback(void);
void RtcCommonCallback(int tag, u32 data, int err);
unsigned long RtcBCD2HEX(unsigned long bcd);
void RtcGetResultCallback(RTCResult result, void *arg);
void RtcWaitBusy(void);
/* END mkheaders: generated region */

#endif
