/*
 * file:     snd_alarm.c
 * unit:     yes
 * function: SND_AlarmInit, SNDi_IncAlarmId, SNDi_SetAlarmHandler, SNDi_CallAlarmHandler
 * address:  0x02089F88
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sCallbackTable  0x02152F40  data
 *   g_02152F40 0x02152F40 data
 */
typedef void (*SNDAlarmHandler)(void *arg);

typedef struct AlarmCallbackInfo {
    SNDAlarmHandler func;
    void *arg;
    unsigned char id;
} AlarmCallbackInfo;

void SND_AlarmInit(void);
void SNDi_IncAlarmId(int alarmNo);
unsigned char SNDi_SetAlarmHandler(int alarmNo, SNDAlarmHandler handler, void *arg);
void SNDi_CallAlarmHandler(int msg);
extern AlarmCallbackInfo sCallbackTable[8];


/*
 * sdk:      SND_AlarmInit (snd_alarm.o)
 */
void SND_AlarmInit(void)
{
    AlarmCallbackInfo *info;
    int alarmNo;

    for (alarmNo = 0; alarmNo < 8; alarmNo++) {
        info = &sCallbackTable[alarmNo];
        info->func = 0;
        info->arg = 0;
        info->id = 0;
    }
}


void SNDi_IncAlarmId(int alarmNo)
{
    AlarmCallbackInfo *info = &sCallbackTable[alarmNo];
    info->id++;
}


/*
 * sdk:      SNDi_SetAlarmHandler (snd_alarm.o)
 */
unsigned char SNDi_SetAlarmHandler(int alarmNo, SNDAlarmHandler handler, void *arg)
{
    AlarmCallbackInfo *info = &sCallbackTable[alarmNo];

    info->func = handler;
    info->arg = arg;
    info->id++;
    return info->id;
}


/*
 * sdk:      SNDi_CallAlarmHandler (snd_alarm.o)
 */
void SNDi_CallAlarmHandler(int msg)
{
    AlarmCallbackInfo *info = &sCallbackTable[msg & 0xff];

    if (((msg >> 8) & 0xff) != info->id) {
        return;
    }
    if (info->func == 0) {
        return;
    }
    info->func(info->arg);
}
