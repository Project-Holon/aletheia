/*
 * function: func_02088398
 * address:  0x02088398
 * packet:   pkt_02088398
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_SignalEvent (os_event.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
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

extern void OS_WakeupThread(OSThreadQueue *queue);

void func_02088398(OSEvent *event, u32 setPattern)
{
    OSIntrMode enable = OS_DisableInterrupts();

    if (setPattern) {
        event->flag |= setPattern;
        OS_WakeupThread(&event->queue);
    }
    (void)OS_RestoreInterrupts(enable);
}
