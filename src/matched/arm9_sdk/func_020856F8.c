/*
 * function: OSi_CancelThreadAlarmForSleep
 * address:  0x020856F8
 * packet:   pkt_020856F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_thread.o OSi_CancelThreadAlarmForSleep.
 *
 * symbols:
 *   OS_CancelAlarm  0x020873F8  arm
 */

typedef struct {
    char pad[0xb0];
    void *alarmForSleep;
} OSThread;

void OS_CancelAlarm(void *alarm);

void OSi_CancelThreadAlarmForSleep(OSThread *thread)
{
    void *alarm = thread->alarmForSleep;

    if (alarm) {
        OS_CancelAlarm(alarm);
    }
}
