/*
 * function: OS_WakeupThread
 * address:  0x02085800
 * packet:   pkt_02085800
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_thread.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   OS_DisableInterrupts     0x02087988  arm
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   OSi_RemoveLinkFromQueue  0x02085044  arm
 *   OSi_RescheduleThread     0x020851A0  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef enum OSThreadState {
    OS_THREAD_STATE_WAITING = 0,
    OS_THREAD_STATE_READY = 1,
    OS_THREAD_STATE_TERMINATED = 2
} OSThreadState;

typedef struct OSContext {
    u8 opaque[0x64];
} OSContext;

typedef struct _OSThread OSThread;

typedef struct _OSThreadQueue {
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct _OSThreadLink {
    OSThread *prev;
    OSThread *next;
} OSThreadLink;

struct _OSThread {
    OSContext context;
    OSThreadState state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;
    OSThreadQueue *queue;
    OSThreadLink link;
};

typedef struct OSThreadInfo {
    u16 isNeedRescheduling;
    u16 irqDepth;
    OSThread *current;
    OSThread *list;
    void *switchCallback;
} OSThreadInfo;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern OSThread *OSi_RemoveLinkFromQueue(OSThreadQueue *queue);
extern void OSi_RescheduleThread(void);

void OS_WakeupThread(OSThreadQueue *queue)
{
    OSIntrMode enable = OS_DisableInterrupts();

    if (queue->head) {
        while (queue->head) {
            OSThread *thread = OSi_RemoveLinkFromQueue(queue);

            thread->state = OS_THREAD_STATE_READY;
            thread->queue = 0;
            thread->link.prev = thread->link.next = 0;
        }
        queue->tail = 0;
        queue->head = 0;
        OSi_RescheduleThread();
    }
    (void)OS_RestoreInterrupts(enable);
}
