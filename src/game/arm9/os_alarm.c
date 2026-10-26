/*
 * file:     os_alarm.c
 * unit:     yes
 * function: OSi_SetTimer, OS_InitAlarm, OS_IsAlarmAvailable, OS_CreateAlarm, OSi_InsertAlarm, OS_SetAlarm, OS_CancelAlarm, OSi_AlarmHandler, OSi_ArrangeTimer
 * address:  0x02087180
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_GetTick              0x020870D0  arm
 *   OSi_EnterTimerCallback  0x020848F8  arm
 *   OS_EnableIrqMask        0x02084968  arm
 *   OSi_AlarmHandler        0x0208747C  arm
 *   OSi_SetTimerReserved  0x02086FC4  arm
 *   OS_DisableIrqMask     0x02084998  arm
 *   g_02151340            0x02151340  data
 *   _ll_udiv      0x0209C00C  arm
 *   OS_Terminate          0x02088234  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   SDK_AUTOLOAD_DTCM_START  0x02FE0000  data
 */
#include "../types.h"
#include "../sdk_ioreg.h"

#include "../sdk_os.h"


typedef struct OSAlarmQueue {
    OSAlarm *head;
    OSAlarm *tail;
} OSAlarmQueue;

/* os_alarm.o .bss from 0x02151340, addressed from one pool word. */
typedef struct OsAlarmBss {
    u16 OSi_UseAlarm;
    OSAlarmQueue OSi_AlarmQueue;
} OsAlarmBss;

#include "os_tick.h"
#include "os_interrupt.h"
extern void OSi_AlarmHandler(void *arg);
#include "os_system.h"
#include "os_timer.h"
#include "os_terminate_processor.h"
void OSi_SetTimer(OSAlarm *alarm);
void OS_InitAlarm(void);
BOOL OS_IsAlarmAvailable(void);
void OS_CreateAlarm(OSAlarm *alarm);
void OSi_InsertAlarm(OSAlarm *alarm, OSTick fire);
void OS_SetAlarm(OSAlarm *alarm, OSTick tick, OSAlarmHandler handler, void *arg);
void OS_CancelAlarm(OSAlarm *alarm);
void OSi_ArrangeTimer(void);
extern OsAlarmBss g_02151340;
extern char SDK_AUTOLOAD_DTCM_START[];

#define reg_OS_TM1CNT_L (*(vu16 *)REG_TM1CNT_L_ADDR)

#define reg_OS_TM1CNT_H (*(vu16 *)REG_TM1CNT_H_ADDR)

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

/*
 * sdk:      OS_InitAlarm (os_alarm.o)
 */
void OS_InitAlarm(void)
{
    if (!g_02151340.OSi_UseAlarm) {
        g_02151340.OSi_UseAlarm = 1;

        OSi_SetTimerReserved(1);

        g_02151340.OSi_AlarmQueue.head = 0;
        g_02151340.OSi_AlarmQueue.tail = 0;

        (void)OS_DisableIrqMask(0x10);
    }
}

BOOL OS_IsAlarmAvailable(void)
{
    return g_02151340.OSi_UseAlarm;
}

void OS_CreateAlarm(OSAlarm *alarm)
{
    alarm->handler = 0;
    alarm->tag = 0;
}

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

    for (next = g_02151340.OSi_AlarmQueue.head; next; next = next->next) {
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
            g_02151340.OSi_AlarmQueue.head = alarm;
            OSi_SetTimer(alarm);
        }
        return;
    }

    alarm->next = 0;
    prev = g_02151340.OSi_AlarmQueue.tail;
    g_02151340.OSi_AlarmQueue.tail = alarm;
    alarm->prev = prev;
    if (prev) {
        prev->next = alarm;
    } else {
        g_02151340.OSi_AlarmQueue.head = g_02151340.OSi_AlarmQueue.tail = alarm;
        OSi_SetTimer(alarm);
    }
}

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

/*
 * sdk:      OS_CancelAlarm (os_alarm.o)
 */
void OS_CancelAlarm(OSAlarm *alarm)
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

/* hand-written in the original: OSi_AlarmHandler (os_alarm.o). C was tried: mwccarm always makes the call a tail call (ldr ip,=f; bx ip) at -O2/-O4, and with -O0 or a non-tail call it pads the stack with r3 (push {r3,lr}) and returns with pop {r3,pc}. It never pads with r0 or returns with ldmia + bx lr. The only other code with the {r0,lr} pad is SDK asm (OS_SaveContext, OS_LoadContext, OSi_GetAndDisplayContext). */
asm void OSi_AlarmHandler(void *arg)
{
    stmdb	sp!, {r0, lr}
    bl	OSi_ArrangeTimer
    ldmia	sp!, {r0, lr}
    bx	lr
}

#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((uptr)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

/*
 * sdk:      OSi_ArrangeTimer (os_alarm.o)
 */
void OSi_ArrangeTimer(void)
{
    OSTick tick;
    OSAlarm *alarm;
    OSAlarm *next;
    OSAlarmHandler handler;

    *(volatile u16 *)REG_TM1CNT_H_ADDR = 0;
    (void)OS_DisableIrqMask(0x10);
    OSi_IRQ_CHECK_FLAG |= 0x10;

    tick = OS_GetTick();
    alarm = g_02151340.OSi_AlarmQueue.head;

    if (alarm == 0) {
        return;
    }

    if (tick < alarm->fire) {
        OSi_SetTimer(alarm);
        return;
    }

    next = alarm->next;
    g_02151340.OSi_AlarmQueue.head = next;
    if (next == 0) {
        g_02151340.OSi_AlarmQueue.tail = 0;
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

    if (g_02151340.OSi_AlarmQueue.head) {
        OSi_SetTimer(g_02151340.OSi_AlarmQueue.head);
    }
}
