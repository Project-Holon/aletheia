/*
 * function: OS_SetAlarm
 * address:  0x0208738C
 * packet:   pkt_0208738C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_alarm.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   OS_Terminate          0x02088234  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_GetTick            0x020870D0  arm
 *   OSi_InsertAlarm       0x02087264  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef long long s64;
typedef unsigned long long u64;
typedef u64 OSTick;
typedef u32 OSIntrMode;
typedef void (*OSAlarmHandler)(void *);

typedef struct OSiAlarm {
    OSAlarmHandler handler;
    void *arg;
    u32 tag;
    OSTick fire;
    struct OSiAlarm *prev;
    struct OSiAlarm *next;
    OSTick period;
    OSTick start;
} OSAlarm;

extern void OS_Terminate(void);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern OSTick OS_GetTick(void);
extern void OSi_InsertAlarm(OSAlarm *alarm, OSTick fire);

void OS_SetAlarm(OSAlarm *alarm, OSTick tick, OSAlarmHandler handler, void *arg)
{
    OSIntrMode enabled;

    if (!alarm || alarm->handler) {
        OS_Terminate();
    }

    enabled = OS_DisableInterrupts();

    alarm->period = 0;
    alarm->handler = handler;
    alarm->arg = arg;

    OSi_InsertAlarm(alarm, OS_GetTick() + tick);

    (void)OS_RestoreInterrupts(enabled);
}
