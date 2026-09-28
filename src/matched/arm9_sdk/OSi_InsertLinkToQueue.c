/*
 * function: OSi_InsertLinkToQueue
 * address:  0x02084FCC
 * packet:   pkt_02084FCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_thread.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static
 * in the vendor object: inserts a thread into a wait queue in priority order,
 * returning early if the thread is already queued.
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

void OSi_InsertLinkToQueue(OSThreadQueue *queue, OSThread *thread)
{
    OSThread *next = queue->head;

    while (next && next->priority <= thread->priority) {
        if (next == thread)
            return;
        next = next->link.next;
    }

    if (next == 0) {
        OSThread *prev = queue->tail;

        if (prev == 0)
            queue->head = thread;
        else
            prev->link.next = thread;
        thread->link.prev = prev;
        thread->link.next = 0;
        queue->tail = thread;
    } else {
        OSThread *prev = next->link.prev;

        if (prev == 0)
            queue->head = thread;
        else
            prev->link.next = thread;
        thread->link.prev = prev;
        thread->link.next = next;
        next->link.prev = thread;
    }
}
