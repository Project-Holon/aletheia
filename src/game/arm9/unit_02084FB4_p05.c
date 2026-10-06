/*
 * file:     unit_02084FB4_p05.c
 * unit:     yes
 * function: func_02085560, func_020855BC, func_02085638, func_0208565C, func_020856F8, func_02085710, func_0208574C
 * address:  0x02085560
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
 *   OS_DisableScheduler               0x02085B30  arm
 *   OSi_UnlockAllMutex                0x02086088  arm
 *   OSi_RemoveSpecifiedLinkFromQueue  0x02085078  arm
 *   OSi_RemoveThreadFromList          0x02085158  arm
 *   OS_WakeupThread                   0x02085800  arm
 *   OS_EnableScheduler                0x02085B60  arm
 *   OS_RescheduleThread               0x020858BC  arm
 *   OS_Terminate                      0x02088234  arm
 *   g_02150FD0                        0x02150FD0  data
 *   OS_DisableInterrupts              0x02087988  arm
 *   OS_RestoreInterrupts              0x0208799C  arm
 *   OSi_ExitThread_Destroy            0x02085560  arm
 *   OSi_CancelThreadAlarmForSleep     0x020856F8  arm
 *   OS_GetThreadPriority       0x02085A30  arm
 *   OS_KillThreadWithPriority  0x0208565C  arm
 *   OSi_ExitThread_ArgSpecified    0x020854D0  arm
 *   OS_InitContext                 0x02085B9C  arm
 *   OS_SetThreadPriority           0x02085988  arm
 *   OSi_RescheduleThread           0x020851A0  arm
 *   OSi_ExitThread                 0x02085528  arm
 *   OS_CancelAlarm  0x020873F8  arm
 *   OS_SleepThread        0x020857B0  arm
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

typedef struct _OSThread OSThread_02085560;

typedef struct OSMutex OSMutex;

typedef struct OSiAlarm OSAlarm;

typedef struct _OSThreadQueue {
    OSThread_02085560 *head;
    OSThread_02085560 *tail;
} OSThreadQueue;

typedef struct _OSThreadLink {
    OSThread_02085560 *prev;
    OSThread_02085560 *next;
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
    OSThread_02085560 *thread;
    s32 count;
    OSMutexLink link;
};

struct _OSThread {
    OSContext context;
    OSThreadState state;
    OSThread_02085560 *next;
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
    OSThread_02085560 *current;
    OSThread_02085560 *list;
    void *switchCallback;
} OSThreadInfo;

typedef void (*OSSwitchThreadCallback)(OSThread_02085560 *from, OSThread_02085560 *to);

/* os_thread.o .bss from 0x02150FD0, addressed section-relative from one pool
   word.  +0x14 is the destructor stack (OSi_ExitThread_ArgSpecified passes it
   to OS_InitContext as the new sp); +0x10 is the one 4-byte local left. */
typedef struct OsThreadBss {
    void *OSi_SystemCallbackInSwitchThread;
    u32 OSi_RescheduleCount;
    OSThread_02085560 **OSi_CurrentThreadPtr;
    BOOL OSi_IsThreadInitialized;
    u32 OSi_SystemStackBuffer;
    u32 OSi_StackForDestructor;
    u32 OSi_ThreadIdCount;
    OSThreadInfo OSi_ThreadInfo;
    OSThread_02085560 OSi_IdleThread;
    OSThread_02085560 OSi_LauncherThread;
    u32 OSi_IdleThreadStack[50];
} OsThreadBss;

typedef struct _OSThread OSThread_020855BC;

typedef struct _OSThread OSThread_0208565C;

typedef struct {
    char pad[0xb0];
    void *alarmForSleep;
} OSThread_020856F8;

typedef struct _OSThread OSThread_02085710;

typedef struct {
    char pad[0x64];
    int state;
} OSThread_0208574C;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern u32 OS_DisableScheduler(void);
extern u32 OS_EnableScheduler(void);
extern void OSi_UnlockAllMutex(OSThread_02085560 *thread);
extern OSThread_02085560 *OSi_RemoveSpecifiedLinkFromQueue(OSThreadQueue *queue, OSThread_02085560 *thread);
extern void OSi_RemoveThreadFromList(OSThread_02085560 *thread);
extern void OS_WakeupThread(OSThreadQueue *queue);
extern void OS_RescheduleThread(void);
extern void OS_Terminate(void);
extern void OSi_ExitThread_Destroy(void);
extern void OSi_CancelThreadAlarmForSleep(OSThread_020855BC *thread);
int OS_GetThreadPriority(const void *thread);
void OS_KillThreadWithPriority(void *thread, void *arg, int priority);
extern void OSi_ExitThread_ArgSpecified(OSThread_0208565C *thread, void *arg);
extern void OS_InitContext(OSContext *context, u32 newpc, u32 newsp);
extern BOOL OS_SetThreadPriority(OSThread_0208565C *thread, u32 prio);
extern void OSi_RescheduleThread(void);
extern void OSi_ExitThread(void *arg);
void OS_CancelAlarm(void *alarm);
extern void OS_SleepThread(OSThreadQueue *queue);
void func_02085560(void);
void func_020855BC(OSThread_020855BC *thread);
void func_02085638(void *thread, void *arg);
void func_0208565C(OSThread_0208565C *thread, void *arg, u32 prio);
void func_020856F8(OSThread_020856F8 *thread);
void func_02085710(OSThread_02085710 *thread);
int func_0208574C(const OSThread_0208574C *thread);
extern OsThreadBss g_02150FD0;


/*
 * sdk:      OSi_ExitThread_Destroy (os_thread.o)
 */
void func_02085560(void)
{
    OSThread_02085560 *currentThread = *g_02150FD0.OSi_CurrentThreadPtr;

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
void func_020855BC(OSThread_020855BC *thread)
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
void func_0208565C(OSThread_0208565C *thread, void *arg, u32 prio)
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
void func_020856F8(OSThread_020856F8 *thread)
{
    void *alarm = thread->alarmForSleep;

    if (alarm) {
        OS_CancelAlarm(alarm);
    }
}


/*
 * sdk:      OS_JoinThread (os_thread.o)
 */
void func_02085710(OSThread_02085710 *thread)
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
int func_0208574C(const OSThread_0208574C *thread)
{
    return (thread->state == 2) ? 1 : 0;
}
