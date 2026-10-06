/*
 * file:     unit_02084FB4_p01.c
 * unit:     yes
 * function: func_02084FB4, func_02084FCC, func_02085044
 * address:  0x02084FB4
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
 *   g_02150FD0  0x02150FD0  data  a4
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

int func_02084FB4(void);
void OSi_InsertLinkToQueue(OSThreadQueue *queue, OSThread *thread);
OSThread *OSi_RemoveLinkFromQueue(OSThreadQueue *queue);
extern int g_02150FD0[];


/*
 * note:     os_thread.o OSi_GetUnusedThreadId.
 */
int func_02084FB4(void)
{
    return ++g_02150FD0[6];
}


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


OSThread *OSi_RemoveLinkFromQueue(OSThreadQueue *queue)
{
    OSThread *t = queue->head;

    if (t) {
        OSThread *next = t->link.next;

        queue->head = next;
        if (next) {
            next->link.prev = 0;
        } else {
            queue->tail = 0;
            t->queue = 0;
        }
    }
    return t;
}
