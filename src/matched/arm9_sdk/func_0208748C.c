/*
 * function: OSi_ArrangeTimer
 * address:  0x0208748C
 * packet:   pkt_0208748C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_ArrangeTimer (os_alarm.o)
 *
 * symbols:
 *   OS_DisableIrqMask        0x02084998  arm
 *   OS_GetTick               0x020870D0  arm
 *   OSi_SetTimer             0x02087180  arm
 *   OSi_InsertAlarm          0x02087264  arm
 *   SDK_AUTOLOAD_DTCM_START  0x02FE0000  data
 *   g_02151340               0x02151340  data
 */

#include "../include/G_OsAlarmBss.h"

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
typedef struct OsAlarmBss OsAlarmBss;

extern struct OsAlarmBss g_02151340;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void OSi_SetTimer(OSAlarm *alarm);

extern char SDK_AUTOLOAD_DTCM_START[];

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

extern u32 OS_DisableIrqMask(u32 intr);
extern OSTick OS_GetTick(void);
extern void OSi_InsertAlarm(OSAlarm *alarm, OSTick fire);

void OSi_ArrangeTimer(void)
{
    OSTick tick;
    OSAlarm *alarm;
    OSAlarm *next;
    OSAlarmHandler handler;

    *(volatile u16 *)0x04000106 = 0;
    (void)OS_DisableIrqMask(0x10);
    OSi_IRQ_CHECK_FLAG |= 0x10;

    tick = OS_GetTick();
    alarm = g_02151340.OSi_AlarmQueue_head;

    if (alarm == 0) {
        return;
    }

    if (tick < alarm->fire) {
        OSi_SetTimer(alarm);
        return;
    }

    next = alarm->next;
    g_02151340.OSi_AlarmQueue_head = next;
    if (next == 0) {
        g_02151340.OSi_AlarmQueue_tail = 0;
    } else {
        next->prev = 0;
    }

    handler = alarm->handler;
    if (!alarm->period) {
        alarm->handler = 0;
    }
    if (handler) {
        handler(alarm->arg);
    }

    if (alarm->period) {
        alarm->handler = handler;
        OSi_InsertAlarm(alarm, 0);
    }

    if (g_02151340.OSi_AlarmQueue_head) {
        OSi_SetTimer(g_02151340.OSi_AlarmQueue_head);
    }
}
