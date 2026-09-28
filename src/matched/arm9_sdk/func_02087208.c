/*
 * function: func_02087208
 * address:  0x02087208
 * packet:   pkt_02087208
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_InitAlarm (os_alarm.o)
 *
 * symbols:
 *   OSi_SetTimerReserved  0x02086FC4  arm
 *   OS_DisableIrqMask     0x02084998  arm
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

extern void OSi_SetTimerReserved(int timerNum);
extern u32 OS_DisableIrqMask(u32 intr);

void func_02087208(void)
{
    if (!g_02151340.OSi_UseAlarm) {
        g_02151340.OSi_UseAlarm = 1;

        OSi_SetTimerReserved(1);

        g_02151340.OSi_AlarmQueue.head = 0;
        g_02151340.OSi_AlarmQueue.tail = 0;

        (void)OS_DisableIrqMask(0x10);
    }
}
