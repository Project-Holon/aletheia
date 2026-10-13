/*
 * function: func_020860D0
 * address:  0x020860D0
 * packet:   pkt_020860D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_TryLockMutex (os_mutex.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OSi_EnqueueTail       0x0208623C  arm
 *   OSi_ThreadInfo        0x02150FEC  data
 *   gOsThreadBss  0x02150FD0  data
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

extern OSThreadInfo OSi_ThreadInfo;


/* OSMutex.count carries the lock depth in bits 0..23 and the lock type in
   bits 24..31; the object reads and writes both halves with explicit masks. */
#define OSi_MUTEX_TYPE_MASK   0xFF000000
#define OSi_MUTEX_COUNT_MASK  0x00FFFFFF
#define OSi_MUTEX_TYPE_STD    0x10000000
#define OSi_MUTEX_TYPE_R      0x20000000
#define OSi_MUTEX_TYPE_W      0x30000000

#define OSi_GetMutexType(m)       ((u32)(m)->count & OSi_MUTEX_TYPE_MASK)
#define OSi_GetMutexCount(m)      ((u32)(m)->count & OSi_MUTEX_COUNT_MASK)
#define OSi_SetMutexType(m, t)    ((m)->count = (s32)(((u32)(m)->count & OSi_MUTEX_COUNT_MASK) | (t)))
#define OSi_SetMutexCount(m, c)   ((m)->count = (s32)(((u32)(m)->count & OSi_MUTEX_TYPE_MASK) | ((c) & OSi_MUTEX_COUNT_MASK)))
#define OSi_IncreaseMutexCount(m) OSi_SetMutexCount(m, (u32)(m)->count + 1)
#define OSi_DecreaseMutexCount(m) OSi_SetMutexCount(m, (u32)(m)->count - 1)

extern void OSi_EnqueueTail(OSThread *thread, OSMutex *mutex);

BOOL func_020860D0(OSMutex *mutex)
{
    OSIntrMode saved = OS_DisableInterrupts();
    OSThread *currentThread = OSi_ThreadInfo.current;
    BOOL locked;

    if (mutex->thread == 0) {
        mutex->thread = currentThread;
        OSi_SetMutexType(mutex, OSi_MUTEX_TYPE_STD);
        OSi_IncreaseMutexCount(mutex);
        OSi_EnqueueTail(currentThread, mutex);
        locked = 1;
    } else if (mutex->thread == currentThread) {
        OSi_IncreaseMutexCount(mutex);
        locked = 1;
    } else {
        locked = 0;
    }
    (void)OS_RestoreInterrupts(saved);
    return locked;
}
