#ifndef GAME_ARM9_SND_ALARM_H
#define GAME_ARM9_SND_ALARM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of snd_alarm.c, prototypes copied from their definitions. */

void SND_AlarmInit(void);
void SNDi_IncAlarmId(int alarmNo);
void SNDi_CallAlarmHandler(int msg);
/* END mkheaders: generated region */

#endif
