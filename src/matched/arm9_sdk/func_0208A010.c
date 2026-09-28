/*
 * function: func_0208A010
 * address:  0x0208A010
 * packet:   pkt_0208A010
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SNDi_CallAlarmHandler (snd_alarm.o)
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

void func_0208A010(int msg)
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
