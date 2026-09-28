/*
 * function: OS_SleepThread
 * address:  0x020857B0
 * packet:   pkt_020857B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_thread.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  The
 * current thread is read through OSi_CurrentThreadPtr, addressed from the
 * .bss section base (0x02150FD0) as in OSi_RescheduleThread.
 *
 * symbols:
 *   g_02150FD0             0x02150FD0  data
 *   OS_DisableInterrupts   0x02087988  arm
 *   OS_RestoreInterrupts   0x0208799C  arm
 *   OSi_InsertLinkToQueue  0x02084FCC  arm
 *   OSi_RescheduleThread   0x020851A0  arm
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


/* os_thread.o .bss from 0x02150FD0, addressed section-relative from one pool
   word (see OSi_RescheduleThread). */
typedef struct OsThreadBss {
    void *OSi_SystemCallbackInSwitchThread;
    u32 OSi_RescheduleCount;
    OSThread **OSi_CurrentThreadPtr;
    u32 other[4];
    OSThreadInfo OSi_ThreadInfo;
} OsThreadBss;

extern OsThreadBss g_02150FD0;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void OSi_InsertLinkToQueue(OSThreadQueue *queue, OSThread *thread);
extern void OSi_RescheduleThread(void);

void OS_SleepThread(OSThreadQueue *queue)
{
    OSIntrMode enable;
    OSThread *currentThread;

    enable = OS_DisableInterrupts();
    currentThread = *g_02150FD0.OSi_CurrentThreadPtr;

    if (queue) {
        currentThread->queue = queue;
        OSi_InsertLinkToQueue(queue, currentThread);
    }
    currentThread->state = OS_THREAD_STATE_WAITING;
    OSi_RescheduleThread();
    (void)OS_RestoreInterrupts(enable);
}
