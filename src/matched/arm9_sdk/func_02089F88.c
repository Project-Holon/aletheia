/*
 * function: func_02089F88
 * address:  0x02089F88
 * packet:   pkt_02089F88
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_AlarmInit (snd_alarm.o)
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

void func_02089F88(void)
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
