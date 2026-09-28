/*
 * function: OSi_SetTimer
 * address:  0x02087180
 * packet:   pkt_02087180
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_alarm.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static
 * in the vendor object.  Timer 1 drives the alarm queue.
 *
 * symbols:
 *   OS_GetTick              0x020870D0  arm
 *   OSi_EnterTimerCallback  0x020848F8  arm
 *   OS_EnableIrqMask        0x02084968  arm
 *   OSi_AlarmHandler        0x0208747C  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef long long s64;
typedef unsigned long long u64;
typedef volatile u16 vu16;
typedef u64 OSTick;
typedef u32 OSIrqMask;
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

#define reg_OS_TM1CNT_L (*(vu16 *)0x04000104)
#define reg_OS_TM1CNT_H (*(vu16 *)0x04000106)

extern OSTick OS_GetTick(void);
extern void OSi_EnterTimerCallback(u32 timerNo, void (*callback)(void *), void *arg);
extern OSIrqMask OS_EnableIrqMask(OSIrqMask intr);
extern void OSi_AlarmHandler(void *arg);

void OSi_SetTimer(OSAlarm *alarm)
{
    s64 delta;
    OSTick tick = OS_GetTick();
    u16 timerCount;

    reg_OS_TM1CNT_H = 0;

    delta = (s64)(alarm->fire - tick);

    OSi_EnterTimerCallback(1, OSi_AlarmHandler, 0);

    if (delta < 0) {
        timerCount = (u16)~1;
    } else if (delta < 0x10000) {
        timerCount = (u16)(~delta);
    } else {
        timerCount = 0;
    }

    reg_OS_TM1CNT_L = timerCount;
    reg_OS_TM1CNT_H = (u16)(0x0080 | 0x0040 | 0x0001);

    (void)OS_EnableIrqMask(0x10);
}
