/*
 * file:     unit_02085A38.c
 * unit:     yes
 * function: func_02085A38, func_02085AD8, func_02085AF8
 * address:  0x02085A38
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
 *   OS_CreateAlarm          0x02087254  arm
 *   OS_SetAlarm             0x0208738C  arm
 *   OS_SleepThread          0x020857B0  arm
 *   OS_DisableInterrupts    0x02087988  arm
 *   OS_RestoreInterrupts    0x0208799C  arm
 *   OSi_SleepAlarmCallback  0x02085AD8  arm
 *   g_02150FD0              0x02150FD0  data
 *   OS_WakeupThreadDirect  0x02085868  arm
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
extern void OS_CreateAlarm(OSAlarm *alarm);
extern void OS_SetAlarm(OSAlarm *alarm, u64 tick, OSAlarmHandler handler, void *arg);
extern void OS_SleepThread(OSThreadQueue *queue);
extern void OSi_SleepAlarmCallback(void *arg);
extern void OS_WakeupThreadDirect(OSThread *thread);
void func_02085A38(u32 msec);
void func_02085AD8(void *arg);
OSSwitchThreadCallback func_02085AF8(OSSwitchThreadCallback callback);
extern OsThreadBss g_02150FD0;


/*
 * sdk:      OS_Sleep (os_thread.o)
 */
void func_02085A38(u32 msec)
{
    OSAlarm alarm;
    OSThread *volatile p_thread;
    OSIntrMode bak_cpsr;

    OS_CreateAlarm(&alarm);
    p_thread = *g_02150FD0.OSi_CurrentThreadPtr;
    bak_cpsr = OS_DisableInterrupts();
    p_thread->alarmForSleep = &alarm;
    OS_SetAlarm(&alarm, ((u64)33514 * msec) / 64, &OSi_SleepAlarmCallback, (void *)&p_thread);
    while (p_thread != 0) {
        OS_SleepThread(0);
    }
    (void)OS_RestoreInterrupts(bak_cpsr);
}


/*
 * sdk:      OSi_SleepAlarmCallback (os_thread.o)
 */
void func_02085AD8(void *arg)
{
    OSThread **pp_thread = (OSThread **)arg;
    OSThread *p_thread = *pp_thread;

    *pp_thread = 0;
    p_thread->alarmForSleep = 0;
    OS_WakeupThreadDirect(p_thread);
}


/*
 * sdk:      OS_SetSwitchThreadCallback (os_thread.o)
 */
OSSwitchThreadCallback func_02085AF8(OSSwitchThreadCallback callback)
{
    OSIntrMode enabled;
    OSSwitchThreadCallback prev;

    enabled = OS_DisableInterrupts();
    prev = (OSSwitchThreadCallback)g_02150FD0.OSi_ThreadInfo.switchCallback;
    g_02150FD0.OSi_ThreadInfo.switchCallback = (void *)callback;
    (void)OS_RestoreInterrupts(enabled);
    return prev;
}
