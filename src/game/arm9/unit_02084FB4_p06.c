/*
 * file:     unit_02084FB4_p06.c
 * unit:     yes
 * function: func_02085760, func_020857B0, func_02085800, func_02085868, func_02085890, func_020858BC, func_020858D8, func_02085988
 * address:  0x02085760
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
 *   OS_DisableInterrupts   0x02087988  arm
 *   OS_RestoreInterrupts   0x0208799C  arm
 *   OSi_InsertLinkToQueue  0x02084FCC  arm
 *   OSi_RescheduleThread   0x020851A0  arm
 *   g_02150FD0             0x02150FD0  data
 *   OSi_RemoveLinkFromQueue  0x02085044  arm
 *   OSi_InsertThreadToList  0x020850FC  arm
 *   OSi_IdleThread          0x02150FFC  data
 */
typedef unsigned long long u64;

typedef unsigned long u32;

typedef long s32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef int BOOL;

typedef u32 OSIntrMode;

typedef enum OSThreadState {
    OS_THREAD_STATE_WAITING = 0,
    OS_THREAD_STATE_READY = 1,
    OS_THREAD_STATE_TERMINATED = 2
} OSThreadState;

typedef struct CPContext {
    u8 opaque[0x1C];
} CPContext;

typedef struct OSContext_02085760 {
    u32 cpsr;
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pc_plus4;
    u32 sp_svc;
    CPContext cp_context;
} OSContext_02085760;

typedef struct _OSThread_02085760 OSThread;

typedef struct OSMutex OSMutex;

typedef struct OSiAlarm OSAlarm;

typedef struct _OSThreadQueue {
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct _OSThreadLink {
    OSThread *prev;
    OSThread *next;
} OSThreadLink;

typedef struct _OSMutexQueue {
    OSMutex *head;
    OSMutex *tail;
} OSMutexQueue;

typedef struct _OSMutexLink {
    OSMutex *next;
    OSMutex *prev;
} OSMutexLink;

typedef void (*OSAlarmHandler)(void *arg);

struct OSiAlarm {
    OSAlarmHandler handler;
    void *arg;
    u32 tag;
    u64 fire;
    OSAlarm *prev;
    OSAlarm *next;
    u64 period;
    u64 start;
};

struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    s32 count;
    OSMutexLink link;
};

struct _OSThread_02085760 {
    OSContext_02085760 context;
    OSThreadState state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;
    OSThreadQueue *queue;
    OSThreadLink link;
    OSMutex *mutex;
    OSMutexQueue mutexQueue;
    u32 stackTop;
    u32 stackBottom;
    u32 stackWarningOffset;
    OSThreadQueue joinQueue;
    void *specific[3];
    OSAlarm *alarmForSleep;
    void (*destructor)(void *);
    void *userParameter;
    int systemErrno;
};

typedef struct OSThreadInfo {
    u16 isNeedRescheduling;
    u16 irqDepth;
    OSThread *current;
    OSThread *list;
    void *switchCallback;
} OSThreadInfo;

typedef void (*OSSwitchThreadCallback)(OSThread *from, OSThread *to);

/* os_thread.o .bss from 0x02150FD0, addressed section-relative from one pool
   word.  +0x14 is the destructor stack (OSi_ExitThread_ArgSpecified passes it
   to OS_InitContext as the new sp); +0x10 is the one 4-byte local left. */
typedef struct OsThreadBss_02085760 {
    void *OSi_SystemCallbackInSwitchThread;
    u32 OSi_RescheduleCount;
    OSThread **OSi_CurrentThreadPtr;
    BOOL OSi_IsThreadInitialized;
    u32 OSi_SystemStackBuffer;
    u32 OSi_StackForDestructor;
    u32 OSi_ThreadIdCount;
    OSThreadInfo OSi_ThreadInfo;
    OSThread OSi_IdleThread;
    OSThread OSi_LauncherThread;
    u32 OSi_IdleThreadStack[50];
} OsThreadBss_02085760;

typedef struct OSContext_1 {
    u8 opaque[0x64];
} OSContext_1;

struct _OSThread_1 {
    OSContext_1 context;
    OSThreadState state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;
    OSThreadQueue *queue;
    OSThreadLink link;
};

/* os_thread.o .bss from 0x02150FD0, addressed section-relative from one pool
   word (see OSi_RescheduleThread). */
typedef struct OsThreadBss_1 {
    void *OSi_SystemCallbackInSwitchThread;
    u32 OSi_RescheduleCount;
    OSThread **OSi_CurrentThreadPtr;
    u32 other[4];
    OSThreadInfo OSi_ThreadInfo;
} OsThreadBss_1;

typedef struct OSContext_2 {
    u8 opaque[0x64];
} OSContext_2;

struct _OSThread_2 {
    OSContext_2 context;
    OSThreadState state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;
    OSThreadQueue *queue;
    OSThreadLink link;
};

typedef struct OSContext_02085868 {
    u32 cpsr;
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pc_plus4;
    u32 sp_svc;
    CPContext cp_context;
} OSContext_02085868;

struct _OSThread_02085868 {
    OSContext_02085868 context;
    OSThreadState state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;
    OSThreadQueue *queue;
    OSThreadLink link;
    OSMutex *mutex;
    OSMutexQueue mutexQueue;
    u32 stackTop;
    u32 stackBottom;
    u32 stackWarningOffset;
    OSThreadQueue joinQueue;
    void *specific[3];
    OSAlarm *alarmForSleep;
    void (*destructor)(void *);
    void *userParameter;
    int systemErrno;
};

typedef struct OsThreadBss_02085868 {
    void *OSi_SystemCallbackInSwitchThread;
    u32 OSi_RescheduleCount;
    OSThread **OSi_CurrentThreadPtr;
    BOOL OSi_IsThreadInitialized;
    u32 OSi_SystemStackBuffer;
    u32 OSi_StackForDestructor;
    u32 OSi_ThreadIdCount;
    OSThreadInfo OSi_ThreadInfo;
    OSThread OSi_IdleThread;
    OSThread OSi_LauncherThread;
    u32 OSi_IdleThreadStack[50];
} OsThreadBss_02085868;

typedef struct OSContext_4 {
    u8 opaque[0x64];
} OSContext_4;

struct _OSThread_4 {
    OSContext_4 context;
    OSThreadState state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;
    OSThreadQueue *queue;
    OSThreadLink link;
};

/* os_thread.o .bss from 0x02150FD0, addressed section-relative from one pool
   word.  +0, +4, +8 and +0x1C are fixed by the accesses; the four words at
   +0x0C are the object's other 4-byte data in an order no access here reads. */
typedef struct OsThreadBss_4 {
    void *OSi_SystemCallbackInSwitchThread;
    u32 OSi_RescheduleCount;
    OSThread **OSi_CurrentThreadPtr;
    u32 other[4];
    OSThreadInfo OSi_ThreadInfo;
} OsThreadBss_4;

typedef struct OSContext_020858D8 {
    u32 cpsr;
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pc_plus4;
    u32 sp_svc;
    CPContext cp_context;
} OSContext_020858D8;

struct _OSThread_020858D8 {
    OSContext_020858D8 context;
    OSThreadState state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;
    OSThreadQueue *queue;
    OSThreadLink link;
    OSMutex *mutex;
    OSMutexQueue mutexQueue;
    u32 stackTop;
    u32 stackBottom;
    u32 stackWarningOffset;
    OSThreadQueue joinQueue;
    void *specific[3];
    OSAlarm *alarmForSleep;
    void (*destructor)(void *);
    void *userParameter;
    int systemErrno;
};

typedef struct OsThreadBss_020858D8 {
    void *OSi_SystemCallbackInSwitchThread;
    u32 OSi_RescheduleCount;
    OSThread **OSi_CurrentThreadPtr;
    BOOL OSi_IsThreadInitialized;
    u32 OSi_SystemStackBuffer;
    u32 OSi_StackForDestructor;
    u32 OSi_ThreadIdCount;
    OSThreadInfo OSi_ThreadInfo;
    OSThread OSi_IdleThread;
    OSThread OSi_LauncherThread;
    u32 OSi_IdleThreadStack[50];
} OsThreadBss_020858D8;

typedef struct OSContext_02085988 {
    u32 cpsr;
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pc_plus4;
    u32 sp_svc;
    CPContext cp_context;
} OSContext_02085988;

struct _OSThread_02085988 {
    OSContext_02085988 context;
    OSThreadState state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;
    OSThreadQueue *queue;
    OSThreadLink link;
    OSMutex *mutex;
    OSMutexQueue mutexQueue;
    u32 stackTop;
    u32 stackBottom;
    u32 stackWarningOffset;
    OSThreadQueue joinQueue;
    void *specific[3];
    OSAlarm *alarmForSleep;
    void (*destructor)(void *);
    void *userParameter;
    int systemErrno;
};

typedef struct OsThreadBss_02085988 {
    void *OSi_SystemCallbackInSwitchThread;
    u32 OSi_RescheduleCount;
    OSThread **OSi_CurrentThreadPtr;
    BOOL OSi_IsThreadInitialized;
    u32 OSi_SystemStackBuffer;
    u32 OSi_StackForDestructor;
    u32 OSi_ThreadIdCount;
    OSThreadInfo OSi_ThreadInfo;
    OSThread OSi_IdleThread;
    OSThread OSi_LauncherThread;
    u32 OSi_IdleThreadStack[50];
} OsThreadBss_02085988;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void OSi_InsertLinkToQueue(OSThreadQueue *queue, OSThread *thread);
extern void OSi_RescheduleThread(void);
extern OSThread *OSi_RemoveLinkFromQueue(OSThreadQueue *queue);
extern void OSi_InsertThreadToList(OSThread *thread);
void func_02085760(OSThread *thread, OSThreadQueue *queue);
void OS_SleepThread(OSThreadQueue *queue);
void OS_WakeupThread(OSThreadQueue *queue);
void func_02085868(OSThread *thread);
OSThread *OS_SelectThread(void);
void func_020858BC(void);
void func_020858D8(void);
BOOL func_02085988(OSThread *thread, u32 prio);
extern OsThreadBss_02085760 g_02150FD0;
extern OSThread OSi_IdleThread;


/*
 * sdk:      OS_SleepThreadDirect (os_thread.o)
 */
void func_02085760(OSThread *thread, OSThreadQueue *queue)
{
    OSIntrMode bak_intr = OS_DisableInterrupts();

    if (thread->state == OS_THREAD_STATE_READY) {
        if (queue) {
            thread->queue = queue;
            OSi_InsertLinkToQueue(queue, thread);
        }
        thread->state = OS_THREAD_STATE_WAITING;
        OSi_RescheduleThread();
    }
    (void)OS_RestoreInterrupts(bak_intr);
}


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


/*
 * sdk:      OS_WakeupThreadDirect (os_thread.o)
 */
void func_02085868(OSThread *thread)
{
    OSIntrMode enable = OS_DisableInterrupts();

    thread->state = OS_THREAD_STATE_READY;
    OSi_RescheduleThread();
    (void)OS_RestoreInterrupts(enable);
}


OSThread *OS_SelectThread(void)
{
    OSThread *t = g_02150FD0.OSi_ThreadInfo.list;

    while (t && t->state != OS_THREAD_STATE_READY) {
        t = t->next;
    }
    return t;
}


/*
 * note:     os_thread.o OS_RescheduleThread.
 */
void func_020858BC(void)
{
    int bak_intr = OS_DisableInterrupts();
    OSi_RescheduleThread();
    (void)OS_RestoreInterrupts(bak_intr);
}


/*
 * sdk:      OS_YieldThread (os_thread.o)
 */
void func_020858D8(void)
{
    OSThread *pre = 0;
    OSThread *lastThread = 0;
    int samePriorityThread = 0;
    OSIntrMode enable;
    OSThread *t;
    OSThread *tPre;
    OSThread *current;

    current = g_02150FD0.OSi_ThreadInfo.current;
    enable = OS_DisableInterrupts();
    t = g_02150FD0.OSi_ThreadInfo.list;
    tPre = 0;

    while (t) {
        if (t == current) {
            pre = tPre;
        }
        if (current->priority == t->priority) {
            lastThread = t;
            samePriorityThread++;
        }
        tPre = t;
        t = t->next;
    }

    if (samePriorityThread <= 1 || lastThread == current) {
        (void)OS_RestoreInterrupts(enable);
        return;
    }

    if (!pre) {
        g_02150FD0.OSi_ThreadInfo.list = current->next;
    } else {
        pre->next = current->next;
    }
    current->next = lastThread->next;
    lastThread->next = current;

    OSi_RescheduleThread();
    (void)OS_RestoreInterrupts(enable);
}


/*
 * sdk:      OS_SetThreadPriority (os_thread.o)
 */
BOOL func_02085988(OSThread *thread, u32 prio)
{
    OSThread *t = g_02150FD0.OSi_ThreadInfo.list;
    OSThread *pre = 0;
    OSIntrMode enable = OS_DisableInterrupts();

    while (t && t != thread) {
        pre = t;
        t = t->next;
    }

    if (!t || t == &OSi_IdleThread) {
        (void)OS_RestoreInterrupts(enable);
        return 0;
    }

    if (t->priority != prio) {
        if (!pre) {
            g_02150FD0.OSi_ThreadInfo.list = thread->next;
        } else {
            pre->next = thread->next;
        }
        thread->priority = prio;
        OSi_InsertThreadToList(thread);
        OSi_RescheduleThread();
    }
    (void)OS_RestoreInterrupts(enable);
    return 1;
}
