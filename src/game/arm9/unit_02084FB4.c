/*
 * file:     unit_02084FB4.c
 * unit:     yes
 * function: func_02084FB4, func_02084FCC, func_02085044, func_02085078, func_020850CC, func_020850FC, func_02085158, OSi_RescheduleThread, func_02085264, func_020853B0, func_020853C0, func_020854B0, func_020854D0, func_02085528, func_02085560, func_020855BC, func_02085638, func_0208565C, func_020856F8, func_02085710, func_0208574C, func_02085760, func_020857B0, func_02085800, func_02085868, func_02085890, func_020858BC, func_020858D8, func_02085988
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
 *   OSi_ThreadInfo        0x02150FEC  data
 *   OS_GetProcMode        0x020879EC  arm
 *   OS_SaveContext        0x02085C08  arm
 *   OS_LoadContext        0x02085C54  arm
 *   OS_SetSwitchThreadCallback    0x02085AF8  arm
 *   OS_CreateThread               0x020853C0  arm
 *   OSi_IdleThreadProc            0x02085B20  arm
 *   OSi_IdleThread                0x02150FFC  data
 *   OSi_LauncherThread            0x021510BC  data
 *   OSi_IdleThreadStack           0x0215117C  data
 *   SDK_SYS_STACKSIZE             0x00001800  data
 *   SDK_IRQ_STACKSIZE             0x00000800  data
 *   SDK_AUTOLOAD_DTCM_START       0x02FE0000  data
 *   SDK_SECTION_ARENA_DTCM_START  0x02FE00C0  data
 *   OSi_IsThreadInitialized  0x02150FDC  data
 *   OS_DisableInterrupts    0x02087988  arm
 *   OS_RestoreInterrupts    0x0208799C  arm
 *   OSi_GetUnusedThreadId   0x02084FB4  arm
 *   OSi_InsertThreadToList  0x020850FC  arm
 *   OS_InitContext          0x02085B9C  arm
 *   MIi_CpuClear32          0x02082A7C  arm
 *   OS_SetThreadDestructor  0x02085B94  arm
 *   func_02087988 0x02087988 arm
 *   OSi_ExitThread  0x02085528  arm
 *   OSi_ExitThread_Destroy  0x02085560  arm
 *   OS_DisableScheduler               0x02085B30  arm
 *   OSi_UnlockAllMutex                0x02086088  arm
 *   OSi_RemoveSpecifiedLinkFromQueue  0x02085078  arm
 *   OSi_RemoveThreadFromList          0x02085158  arm
 *   OS_EnableScheduler                0x02085B60  arm
 *   OS_RescheduleThread               0x020858BC  arm
 *   OS_Terminate                      0x02088234  arm
 *   OSi_CancelThreadAlarmForSleep     0x020856F8  arm
 *   OS_GetThreadPriority       0x02085A30  arm
 *   OS_KillThreadWithPriority  0x0208565C  arm
 *   OSi_ExitThread_ArgSpecified    0x020854D0  arm
 *   OS_SetThreadPriority           0x02085988  arm
 *   OS_CancelAlarm  0x020873F8  arm
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

typedef struct OSContext {
    u32 cpsr;
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pc_plus4;
    u32 sp_svc;
    CPContext cp_context;
} OSContext;

typedef struct _OSThread OSThread;

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

struct _OSThread {
    OSContext context;
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
typedef struct OsThreadBss {
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
} OsThreadBss;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern int OS_GetProcMode(void);
extern BOOL OS_SaveContext(OSContext *context);
extern void OS_LoadContext(OSContext *context);
extern OSSwitchThreadCallback OS_SetSwitchThreadCallback(OSSwitchThreadCallback callback);
extern void OS_CreateThread(OSThread *thread, void (*func)(void *), void *arg, void *stack,
                            u32 stackSize, u32 prio);
extern void OSi_IdleThreadProc(void *arg);
extern int OSi_GetUnusedThreadId(void);
extern void OSi_InsertThreadToList(OSThread *thread);
extern void OS_InitContext(OSContext *context, u32 newpc, u32 newsp);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void OS_SetThreadDestructor(OSThread *thread, void (*dtor)(void *));
extern void func_02087988(void);
extern void OSi_ExitThread(void *arg);
extern void OSi_ExitThread_Destroy(void);
extern u32 OS_DisableScheduler(void);
extern u32 OS_EnableScheduler(void);
extern void OSi_UnlockAllMutex(OSThread *thread);
extern OSThread *OSi_RemoveSpecifiedLinkFromQueue(OSThreadQueue *queue, OSThread *thread);
extern void OSi_RemoveThreadFromList(OSThread *thread);
extern void OS_RescheduleThread(void);
extern void OS_Terminate(void);
extern void OSi_CancelThreadAlarmForSleep(OSThread *thread);
int OS_GetThreadPriority(const void *thread);
void OS_KillThreadWithPriority(void *thread, void *arg, int priority);
extern void OSi_ExitThread_ArgSpecified(OSThread *thread, void *arg);
extern BOOL OS_SetThreadPriority(OSThread *thread, u32 prio);
void OS_CancelAlarm(void *alarm);
int func_02084FB4(void);
void OSi_InsertLinkToQueue(OSThreadQueue *queue, OSThread *thread);
OSThread *OSi_RemoveLinkFromQueue(OSThreadQueue *queue);
OSThread *func_02085078(OSThreadQueue *queue, OSThread *thread);
OSMutex *func_020850CC(OSMutexQueue *queue);
void func_020850FC(OSThread *thread);
void func_02085158(OSThread *thread);
void OSi_RescheduleThread(void);
void func_02085264(void);
BOOL func_020853B0(void);
void func_020853C0(OSThread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio);
void OS_ExitThread(void);
void func_020854D0(OSThread *thread, void *arg);
void func_02085528(void *arg);
void func_02085560(void);
void func_020855BC(OSThread *thread);
void func_02085638(void *thread, void *arg);
void func_0208565C(OSThread *thread, void *arg, u32 prio);
void func_020856F8(OSThread *thread);
void func_02085710(OSThread *thread);
int func_0208574C(const OSThread *thread);
void func_02085760(OSThread *thread, OSThreadQueue *queue);
void OS_SleepThread(OSThreadQueue *queue);
void OS_WakeupThread(OSThreadQueue *queue);
void func_02085868(OSThread *thread);
OSThread *OS_SelectThread(void);
void func_020858BC(void);
void func_020858D8(void);
BOOL func_02085988(OSThread *thread, u32 prio);
extern OsThreadBss g_02150FD0;
extern OSThreadInfo OSi_ThreadInfo;
extern OSThread OSi_IdleThread;
extern OSThread OSi_LauncherThread;
extern u32 OSi_IdleThreadStack[50];
extern char SDK_SYS_STACKSIZE[];
extern char SDK_IRQ_STACKSIZE[];
extern char SDK_AUTOLOAD_DTCM_START[];
extern char SDK_SECTION_ARENA_DTCM_START[];
extern BOOL OSi_IsThreadInitialized;






/*
 * note:     os_thread.o OSi_GetUnusedThreadId.
 */
int func_02084FB4(void)
{
    return ++g_02150FD0.OSi_ThreadIdCount;
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






/*
 * sdk:      OSi_RemoveSpecifiedLinkFromQueue (os_thread.o)
 */
OSThread *func_02085078(OSThreadQueue *queue, OSThread *thread)
{
    OSThread *t = queue->head;
    OSThread *next;
    OSThread *prev;

    while (t) {
        next = t->link.next;

        if (t == thread) {
            prev = t->link.prev;

            if (queue->head == t) {
                queue->head = next;
            } else {
                prev->link.next = next;
            }

            if (queue->tail == t) {
                queue->tail = prev;
            } else {
                next->link.prev = prev;
            }
            break;
        }
        t = next;
    }
    return t;
}






/*
 * sdk:      OSi_RemoveMutexLinkFromQueue (os_thread.o)
 */
OSMutex *func_020850CC(OSMutexQueue *queue)
{
    OSMutex *t = queue->head;

    if (t) {
        OSMutex *next = t->link.next;

        queue->head = next;
        if (next) {
            next->link.prev = 0;
        } else {
            queue->tail = 0;
        }
    }
    return t;
}






/*
 * sdk:      OSi_InsertThreadToList (os_thread.o)
 */
void func_020850FC(OSThread *thread)
{
    OSThread *t = g_02150FD0.OSi_ThreadInfo.list;
    OSThread *pre = 0;

    while (t && t->priority < thread->priority) {
        pre = t;
        t = t->next;
    }

    if (!pre) {
        thread->next = g_02150FD0.OSi_ThreadInfo.list;
        g_02150FD0.OSi_ThreadInfo.list = thread;
    } else {
        thread->next = pre->next;
        pre->next = thread;
    }
}






/*
 * sdk:      OSi_RemoveThreadFromList (os_thread.o)
 */
void func_02085158(OSThread *thread)
{
    OSThread *t = g_02150FD0.OSi_ThreadInfo.list;
    OSThread *pre = 0;

    while (t && t != thread) {
        pre = t;
        t = t->next;
    }

    if (!pre) {
        g_02150FD0.OSi_ThreadInfo.list = thread->next;
    } else {
        pre->next = thread->next;
    }
}





void OSi_RescheduleThread(void)
{
    if (g_02150FD0.OSi_RescheduleCount == 0) {
        OSThreadInfo *info = &OSi_ThreadInfo;

        if (g_02150FD0.OSi_ThreadInfo.irqDepth > 0 || OS_GetProcMode() == 0x12) {
            info->isNeedRescheduling = 1;
        } else {
            OSThread *currentThread, *nextThread;

            currentThread = *g_02150FD0.OSi_CurrentThreadPtr;
            nextThread = OS_SelectThread();

            if (currentThread == nextThread || !nextThread) {
                return;
            }

            if (currentThread->state != OS_THREAD_STATE_TERMINATED
                && OS_SaveContext(&currentThread->context)) {
                return;
            }

            if (g_02150FD0.OSi_SystemCallbackInSwitchThread) {
                ((OSSwitchThreadCallback)g_02150FD0.OSi_SystemCallbackInSwitchThread)(currentThread, nextThread);
            }

            if (info->switchCallback) {
                ((OSSwitchThreadCallback)info->switchCallback)(currentThread, nextThread);
            }

            g_02150FD0.OSi_ThreadInfo.current = nextThread;

            OS_LoadContext(&nextThread->context);
        }
    }
}




/*
 * sdk:      OS_InitThread (os_thread.o)
 *
 * notes:    code bytes identical; the linker absolutes SDK_SYS_STACKSIZE
 *           (0x1800) and SDK_SECTION_ARENA_DTCM_START (0x02FE00C0) resolve
 *           under the `linker` class: os_thread.o leaves both undefined, and
 *           OS_GetInitArenaHi/Lo (os_arena.o, located with 0 mismatches)
 *           relocate the same symbols at 0x02086684, 0x0208668C and
 *           0x02086758, which hold these values.
 */
void func_02085264(void)
{
    u32 stackBottom;
    u32 stackTop;

    if (g_02150FD0.OSi_IsThreadInitialized) {
        return;
    }
    g_02150FD0.OSi_IsThreadInitialized = 1;
    g_02150FD0.OSi_CurrentThreadPtr = &OSi_ThreadInfo.current;

    OSi_LauncherThread.priority = 16;
    OSi_LauncherThread.id = 0;
    OSi_LauncherThread.state = OS_THREAD_STATE_READY;
    OSi_LauncherThread.next = 0;
    OSi_LauncherThread.profiler = 0;

    g_02150FD0.OSi_ThreadInfo.list = &OSi_LauncherThread;
    g_02150FD0.OSi_ThreadInfo.current = &OSi_LauncherThread;

    stackTop = ((s32)SDK_SYS_STACKSIZE <= 0)
        ? (u32)SDK_SECTION_ARENA_DTCM_START - (s32)SDK_SYS_STACKSIZE
        : (u32)SDK_AUTOLOAD_DTCM_START + 0x3F80 - (u32)SDK_IRQ_STACKSIZE - (s32)SDK_SYS_STACKSIZE;
    stackBottom = (u32)SDK_AUTOLOAD_DTCM_START + 0x3F80 - (u32)SDK_IRQ_STACKSIZE;

    OSi_LauncherThread.stackBottom = stackBottom;
    OSi_LauncherThread.stackTop = stackTop;
    OSi_LauncherThread.stackWarningOffset = 0;

    *(u32 *)(OSi_LauncherThread.stackBottom - sizeof(u32) * 2) = 0xFDDB597D;
    *(u32 *)OSi_LauncherThread.stackTop = 0x7BF9DD5B;

    OSi_LauncherThread.joinQueue.head = OSi_LauncherThread.joinQueue.tail = 0;

    g_02150FD0.OSi_ThreadInfo.isNeedRescheduling = 0;
    g_02150FD0.OSi_ThreadInfo.irqDepth = 0;

    *(OSThreadInfo **)0x02FFFFA0 = &OSi_ThreadInfo;

    (void)OS_SetSwitchThreadCallback(0);

    OS_CreateThread(&OSi_IdleThread, OSi_IdleThreadProc, 0,
                    OSi_IdleThreadStack + 50, 200, 31);
    OSi_IdleThread.priority = 32;
    OSi_IdleThread.state = OS_THREAD_STATE_READY;
}




/*
 * sdk:      OS_IsThreadAvailable (os_thread.o)
 */
BOOL func_020853B0(void)
{
    return OSi_IsThreadInitialized;
}




/*
 * sdk:      OS_CreateThread (os_thread.o)
 */
void func_020853C0(OSThread *thread, void (*func)(void *), void *arg, void *stack,
                   u32 stackSize, u32 prio)
{
    OSIntrMode enable;
    int index;

    enable = OS_DisableInterrupts();

    index = OSi_GetUnusedThreadId();
    thread->id = (u32)index;
    thread->priority = prio;
    thread->state = OS_THREAD_STATE_WAITING;
    thread->profiler = 0;
    OSi_InsertThreadToList(thread);

    thread->stackBottom = (u32)stack;
    thread->stackTop = (u32)stack - stackSize;
    thread->stackWarningOffset = 0;

    *(u32 *)(thread->stackBottom - sizeof(u32) * 2) = 0xFDDB597D;
    *(u32 *)thread->stackTop = 0x7BF9DD5B;

    thread->joinQueue.head = thread->joinQueue.tail = 0;

    OS_InitContext(&thread->context, (u32)func, (u32)stack - sizeof(u32) * 2);
    thread->context.r[0] = (u32)arg;
    thread->context.lr = (u32)OS_ExitThread;

    MIi_CpuClear32(0, (void *)((u32)stack - stackSize + sizeof(u32)), stackSize - sizeof(u32) * 3);

    thread->mutex = 0;
    thread->mutexQueue.head = 0;
    thread->mutexQueue.tail = 0;

    OS_SetThreadDestructor(thread, 0);

    thread->queue = 0;
    thread->link.prev = thread->link.next = 0;

    MIi_CpuClear32(0, thread->specific, sizeof(thread->specific));
    thread->alarmForSleep = 0;

    (void)OS_RestoreInterrupts(enable);
}




void OS_ExitThread(void)
{
    func_02087988();
    func_020854D0(g_02150FD0.OSi_ThreadInfo.current, 0);
}




/*
 * sdk:      OSi_ExitThread_ArgSpecified (os_thread.o)
 */
void func_020854D0(OSThread *thread, void *arg)
{
    if (g_02150FD0.OSi_StackForDestructor) {
        OS_InitContext(&thread->context, (u32)OSi_ExitThread, g_02150FD0.OSi_StackForDestructor);
        thread->context.r[0] = (u32)arg;
        thread->context.cpsr |= 0x80;
        thread->state = OS_THREAD_STATE_READY;
        OS_LoadContext(&thread->context);
    } else {
        OSi_ExitThread(arg);
    }
}




/*
 * sdk:      OSi_ExitThread (os_thread.o)
 */
void func_02085528(void *arg)
{
    OSThread *currentThread = *g_02150FD0.OSi_CurrentThreadPtr;
    void (*destructor)(void *) = currentThread->destructor;

    if (destructor) {
        currentThread->destructor = 0;
        destructor(arg);
        (void)OS_DisableInterrupts();
    }
    OSi_ExitThread_Destroy();
}



/*
 * sdk:      OSi_ExitThread_Destroy (os_thread.o)
 */
void func_02085560(void)
{
    OSThread *currentThread = *g_02150FD0.OSi_CurrentThreadPtr;

    (void)OS_DisableScheduler();
    OSi_UnlockAllMutex(currentThread);

    if (currentThread->queue) {
        (void)OSi_RemoveSpecifiedLinkFromQueue(currentThread->queue, currentThread);
    }
    OSi_RemoveThreadFromList(currentThread);
    currentThread->state = OS_THREAD_STATE_TERMINATED;
    OS_WakeupThread(&currentThread->joinQueue);
    (void)OS_EnableScheduler();
    OS_RescheduleThread();
    OS_Terminate();
}



/*
 * sdk:      OS_DestroyThread (os_thread.o)
 */
void func_020855BC(OSThread *thread)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (g_02150FD0.OSi_ThreadInfo.current == thread) {
        OSi_ExitThread_Destroy();
    }

    (void)OS_DisableScheduler();
    OSi_UnlockAllMutex(thread);
    OSi_CancelThreadAlarmForSleep(thread);

    if (thread->queue) {
        (void)OSi_RemoveSpecifiedLinkFromQueue(thread->queue, thread);
    }
    OSi_RemoveThreadFromList(thread);
    thread->state = OS_THREAD_STATE_TERMINATED;
    OS_WakeupThread(&thread->joinQueue);
    (void)OS_EnableScheduler();
    (void)OS_RestoreInterrupts(enabled);
    OS_RescheduleThread();
}



/*
 * note:     os_thread.o OS_KillThread.
 */
void func_02085638(void *thread, void *arg)
{
    OS_KillThreadWithPriority(thread, arg, OS_GetThreadPriority(thread));
}



/*
 * sdk:      OS_KillThreadWithPriority (os_thread.o)
 */
void func_0208565C(OSThread *thread, void *arg, u32 prio)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (thread == g_02150FD0.OSi_ThreadInfo.current) {
        OSi_ExitThread_ArgSpecified(thread, arg);
    }

    OSi_CancelThreadAlarmForSleep(thread);

    OS_InitContext(&thread->context, (u32)OSi_ExitThread,
                   g_02150FD0.OSi_StackForDestructor ? g_02150FD0.OSi_StackForDestructor
                                                     : thread->stackBottom - 8);
    thread->context.r[0] = (u32)arg;
    thread->context.cpsr |= 0x80;
    thread->state = OS_THREAD_STATE_READY;

    (void)OS_DisableScheduler();
    (void)OS_SetThreadPriority(thread, prio);
    (void)OS_EnableScheduler();
    OSi_RescheduleThread();
    (void)OS_RestoreInterrupts(enabled);
}



/*
 * note:     os_thread.o OSi_CancelThreadAlarmForSleep.
 */
void func_020856F8(OSThread *thread)
{
    void *alarm = thread->alarmForSleep;

    if (alarm) {
        OS_CancelAlarm(alarm);
    }
}



/*
 * sdk:      OS_JoinThread (os_thread.o)
 */
void func_02085710(OSThread *thread)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    while (thread->state != OS_THREAD_STATE_TERMINATED) {
        OS_SleepThread(&thread->joinQueue);
    }
    (void)OS_RestoreInterrupts(enabled);
}



/*
 * note:     os_thread.o OS_IsThreadTerminated.
 */
int func_0208574C(const OSThread *thread)
{
    return (thread->state == 2) ? 1 : 0;
}


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
