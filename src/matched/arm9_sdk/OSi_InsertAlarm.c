/*
 * function: OSi_InsertAlarm
 * address:  0x02087264
 * packet:   pkt_02087264
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_alarm.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static
 * in the vendor object.  The object's .bss holds OSi_UseAlarm (u16) at +0 and
 * OSi_AlarmQueue {head, tail} at +4, addressed section-relative from one pool
 * word (OsAlarmBss).
 *
 * symbols:
 *   g_02151340    0x02151340  data
 *   OS_GetTick    0x020870D0  arm
 *   _ll_udiv      0x0209C00C  arm
 *   OSi_SetTimer  0x02087180  arm
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

typedef struct OSAlarmQueue {
    OSAlarm *head;
    OSAlarm *tail;
} OSAlarmQueue;

typedef struct OsAlarmBss {
    u16 OSi_UseAlarm;
    OSAlarmQueue OSi_AlarmQueue;
} OsAlarmBss;

extern OsAlarmBss g_02151340;
#define OSi_AlarmQueue (g_02151340.OSi_AlarmQueue)

extern OSTick OS_GetTick(void);
extern void OSi_SetTimer(OSAlarm *alarm);

void OSi_InsertAlarm(OSAlarm *alarm, OSTick fire)
{
    OSAlarm *prev;
    OSAlarm *next;

    if (alarm->period > 0) {
        OSTick tick = OS_GetTick();

        fire = alarm->start;
        if (alarm->start < tick) {
            fire += alarm->period * ((tick - alarm->start) / alarm->period + 1);
        }
    }

    alarm->fire = fire;

    for (next = OSi_AlarmQueue.head; next; next = next->next) {
        if ((s64)(fire - next->fire) >= 0) {
            continue;
        }

        alarm->prev = next->prev;
        next->prev = alarm;
        alarm->next = next;
        prev = alarm->prev;
        if (prev) {
            prev->next = alarm;
        } else {
            OSi_AlarmQueue.head = alarm;
            OSi_SetTimer(alarm);
        }
        return;
    }

    alarm->next = 0;
    prev = OSi_AlarmQueue.tail;
    OSi_AlarmQueue.tail = alarm;
    alarm->prev = prev;
    if (prev) {
        prev->next = alarm;
    } else {
        OSi_AlarmQueue.head = OSi_AlarmQueue.tail = alarm;
        OSi_SetTimer(alarm);
    }
}
