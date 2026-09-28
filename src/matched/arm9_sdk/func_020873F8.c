/*
 * function: func_020873F8
 * address:  0x020873F8
 * packet:   pkt_020873F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_CancelAlarm (os_alarm.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OSi_SetTimer          0x02087180  arm
 *   g_02151340            0x02151340  data
 */

typedef unsigned long long u64;
typedef unsigned long u32;
typedef unsigned short u16;
typedef int BOOL;
typedef u32 OSIntrMode;
typedef u64 OSTick;

typedef struct OSiAlarm OSAlarm;
typedef void (*OSAlarmHandler)(void *arg);

struct OSiAlarm {
    OSAlarmHandler handler;
    void *arg;
    u32 tag;
    OSTick fire;
    OSAlarm *prev;
    OSAlarm *next;
    OSTick period;
    OSTick start;
};

typedef struct OSAlarmQueue {
    OSAlarm *head;
    OSAlarm *tail;
} OSAlarmQueue;

/* os_alarm.o .bss from 0x02151340, addressed from one pool word. */
typedef struct OsAlarmBss {
    u16 OSi_UseAlarm;
    OSAlarmQueue OSi_AlarmQueue;
} OsAlarmBss;

extern OsAlarmBss g_02151340;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void OSi_SetTimer(OSAlarm *alarm);

void func_020873F8(OSAlarm *alarm)
{
    OSAlarm *next;
    OSIntrMode enabled = OS_DisableInterrupts();

    if (alarm->handler == 0) {
        (void)OS_RestoreInterrupts(enabled);
        return;
    }

    next = alarm->next;
    if (next == 0) {
        g_02151340.OSi_AlarmQueue.tail = alarm->prev;
    } else {
        next->prev = alarm->prev;
    }

    if (alarm->prev) {
        alarm->prev->next = next;
    } else {
        g_02151340.OSi_AlarmQueue.head = next;
        if (next) {
            OSi_SetTimer(next);
        }
    }

    alarm->handler = 0;
    alarm->period = 0;

    (void)OS_RestoreInterrupts(enabled);
}
