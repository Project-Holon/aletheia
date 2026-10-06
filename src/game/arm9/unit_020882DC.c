/*
 * file:     unit_020882DC.c
 * unit:     yes
 * function: func_020882DC, func_020882F0, func_02088398
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
typedef unsigned long u32;

typedef u32 OSIntrMode;

typedef struct OSThreadQueue {
    void *head;
    void *tail;
} OSThreadQueue;

typedef struct OSEvent {
    volatile u32 flag;
    OSThreadQueue queue;
} OSEvent;

typedef enum OSEventMode {
    OS_EVENT_MODE_AND = 0,
    OS_EVENT_MODE_OR = 1
} OSEventMode;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void OS_SleepThread(OSThreadQueue *queue);
extern void OS_WakeupThread(OSThreadQueue *queue);
asm void OS_InitEvent(void);
u32 func_020882F0(OSEvent *event, u32 pattern, OSEventMode mode, u32 clearBit);
void func_02088398(OSEvent *event, u32 setPattern);

asm void OS_InitEvent(void)
{
    mov	r1, #0
    str	r1, [r0, #8]
    str	r1, [r0, #4]
    str	r1, [r0]
    bx	lr
}


/*
 * sdk:      OS_WaitEventEx (os_event.o)
 */
u32 func_020882F0(OSEvent *event, u32 pattern, OSEventMode mode, u32 clearBit)
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
void func_02088398(OSEvent *event, u32 setPattern)
{
    OSIntrMode enable = OS_DisableInterrupts();

    if (setPattern) {
        event->flag |= setPattern;
        OS_WakeupThread(&event->queue);
    }
    (void)OS_RestoreInterrupts(enable);
}
