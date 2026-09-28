/*
 * function: func_02089FE0
 * address:  0x02089FE0
 * packet:   pkt_02089FE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SNDi_SetAlarmHandler (snd_alarm.o)
 *
 * symbols:
 *   sCallbackTable  0x02152F40  data
 */

typedef void (*SNDAlarmHandler)(void *arg);

typedef struct AlarmCallbackInfo {
    SNDAlarmHandler func;
    void *arg;
    unsigned char id;
} AlarmCallbackInfo;

extern AlarmCallbackInfo sCallbackTable[8];

unsigned char func_02089FE0(int alarmNo, SNDAlarmHandler handler, void *arg)
{
    AlarmCallbackInfo *info = &sCallbackTable[alarmNo];

    info->func = handler;
    info->arg = arg;
    info->id++;
    return info->id;
}
