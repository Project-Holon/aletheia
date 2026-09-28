/*
 * function: func_020855BC
 * address:  0x020855BC
 * packet:   pkt_020855BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_DestroyThread (os_thread.o)
 *
 * symbols:
 *   OS_DisableInterrupts              0x02087988  arm
 *   OS_RestoreInterrupts              0x0208799C  arm
 *   OSi_ExitThread_Destroy            0x02085560  arm
 *   OS_DisableScheduler               0x02085B30  arm
 *   OSi_UnlockAllMutex                0x02086088  arm
 *   OSi_CancelThreadAlarmForSleep     0x020856F8  arm
 *   OSi_RemoveSpecifiedLinkFromQueue  0x02085078  arm
 *   OSi_RemoveThreadFromList          0x02085158  arm
 *   OS_WakeupThread                   0x02085800  arm
 *   OS_EnableScheduler                0x02085B60  arm
 *   OS_RescheduleThread               0x020858BC  arm
 *   g_02150FD0                        0x02150FD0  data
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

extern OsThreadBss g_02150FD0;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);

extern void OSi_ExitThread_Destroy(void);
extern u32 OS_DisableScheduler(void);
extern u32 OS_EnableScheduler(void);
extern void OSi_UnlockAllMutex(OSThread *thread);
extern void OSi_CancelThreadAlarmForSleep(OSThread *thread);
extern OSThread *OSi_RemoveSpecifiedLinkFromQueue(OSThreadQueue *queue, OSThread *thread);
extern void OSi_RemoveThreadFromList(OSThread *thread);
extern void OS_WakeupThread(OSThreadQueue *queue);
extern void OS_RescheduleThread(void);

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
