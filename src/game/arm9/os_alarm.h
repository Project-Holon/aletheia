#ifndef GAME_ARM9_OS_ALARM_H
#define GAME_ARM9_OS_ALARM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_alarm.c, prototypes copied from their definitions. */

#include "../sdk_os.h"
#include "../types.h"

void OSi_SetTimer(OSAlarm *alarm);
void OS_InitAlarm(void);
BOOL OS_IsAlarmAvailable(void);
void OS_CreateAlarm(OSAlarm *alarm);
void OSi_InsertAlarm(OSAlarm *alarm, OSTick fire);
void OS_SetAlarm(OSAlarm *alarm, OSTick tick, OSAlarmHandler handler, void *arg);
void OS_CancelAlarm(OSAlarm *alarm);
void OSi_AlarmHandler(void *arg);
void OSi_ArrangeTimer(void);
/* END mkheaders: generated region */

#endif
