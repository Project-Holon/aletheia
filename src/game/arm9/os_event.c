/*
 * file:     os_event.c
 * unit:     yes
 * function: OS_InitEvent, OS_WaitEventEx, OS_SignalEvent
 * address:  0x020882DC
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
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OS_SleepThread        0x020857B0  arm
 *   OS_WakeupThread       0x02085800  arm
 */
#include "../types.h"

#include "../sdk_os.h"

#include "../sdk_os_thread.h"

#include "os_system.h"
#include "os_thread.h"
void OS_InitEvent(OSEvent *event);
u32 OS_WaitEventEx(OSEvent *event, u32 pattern, OSEventMode mode, u32 clearBit);
void OS_SignalEvent(OSEvent *event, u32 setPattern);

void OS_InitEvent(OSEvent *event)
{
    event->queue.head = event->queue.tail = 0;
    event->flag = 0;
}

/*
 * sdk:      OS_WaitEventEx (os_event.o)
 */
u32 OS_WaitEventEx(OSEvent *event, u32 pattern, OSEventMode mode, u32 clearBit)
{
    u32 retval = 0;
    OSIntrMode enable = OS_DisableInterrupts();

    switch (mode) {
    case OS_EVENT_MODE_AND:
        while ((event->flag & pattern) != pattern) {
            OS_SleepThread(&event->queue);
        }
        retval = event->flag;
        break;
    case OS_EVENT_MODE_OR:
        while (!(event->flag & pattern)) {
            OS_SleepThread(&event->queue);
        }
        retval = event->flag;
        break;
    }

    if (retval) {
        event->flag &= ~clearBit;
    }

    (void)OS_RestoreInterrupts(enable);
    return retval;
}

/*
 * sdk:      OS_SignalEvent (os_event.o)
 */
void OS_SignalEvent(OSEvent *event, u32 setPattern)
{
    OSIntrMode enable = OS_DisableInterrupts();

    if (setPattern) {
        event->flag |= setPattern;
        OS_WakeupThread(&event->queue);
    }
    (void)OS_RestoreInterrupts(enable);
}
