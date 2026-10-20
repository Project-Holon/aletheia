#ifndef GAME_ARM9_OS_VALARM_H
#define GAME_ARM9_OS_VALARM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_valarm.c, prototypes copied from their definitions. */

#include "../sdk_os.h"
#include "../types.h"

void OS_InitVAlarm(void);
void OSi_InsertVAlarm(OSVAlarm *alarm);
void OSi_AppendVAlarm(OSVAlarm *alarm);
void OSi_DetachVAlarm(OSVAlarm *alarm);
void OS_CreateVAlarm(OSVAlarm *alarm);
void OS_SetVAlarm(OSVAlarm *alarm, s16 count, s16 delay, OSVAlarmHandler handler, void *arg);
void OSi_SetNextVAlarm(OSVAlarm *alarm);
void OSi_VAlarmHandler(void);
int OSi_CompareVCount(OSVAlarm *alarm, s32 currentVFrame, s32 currentVCount);
s32 OSi_GetVFrame(s32 vcount);
/* END mkheaders: generated region */

#endif
