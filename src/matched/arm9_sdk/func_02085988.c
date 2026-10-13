/*
 * function: OS_SetThreadPriority
 * address:  0x02085988
 * packet:   pkt_02085988
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_SetThreadPriority (os_thread.o)
 *
 * symbols:
 *   OS_DisableInterrupts    0x02087988  arm
 *   OS_RestoreInterrupts    0x0208799C  arm
 *   OSi_InsertThreadToList  0x020850FC  arm
 *   OSi_RescheduleThread    0x020851A0  arm
 *   OSi_IdleThread          0x02150FFC  data
 *   gOsThreadBss              0x02150FD0  data
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

extern OsThreadBss gOsThreadBss;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);

extern void OSi_InsertThreadToList(OSThread *thread);
extern void OSi_RescheduleThread(void);
extern OSThread OSi_IdleThread;

BOOL OS_SetThreadPriority(OSThread *thread, u32 prio)
{
    OSThread *t = gOsThreadBss.OSi_ThreadInfo.list;
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
            gOsThreadBss.OSi_ThreadInfo.list = thread->next;
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
