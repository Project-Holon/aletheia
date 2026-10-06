/*
 * file:     unit_02084FB4_p04.c
 * unit:     yes
 * function: func_020853C0, func_020854B0, func_020854D0, func_02085528
 * address:  0x020853C0
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
 *   OS_DisableInterrupts    0x02087988  arm
 *   OS_RestoreInterrupts    0x0208799C  arm
 *   OSi_GetUnusedThreadId   0x02084FB4  arm
 *   OSi_InsertThreadToList  0x020850FC  arm
 *   OS_InitContext          0x02085B9C  arm
 *   MIi_CpuClear32          0x02082A7C  arm
 *   OS_SetThreadDestructor  0x02085B94  arm
 *   func_02087988 0x02087988 arm
 *   g_02150FD0 0x02150FD0 data
 *   OS_LoadContext  0x02085C54  arm
 *   OSi_ExitThread  0x02085528  arm
 *   OSi_ExitThread_Destroy  0x02085560  arm
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
extern int OSi_GetUnusedThreadId(void);
extern void OSi_InsertThreadToList(OSThread *thread);
extern void OS_InitContext(OSContext *context, u32 newpc, u32 newsp);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void OS_SetThreadDestructor(OSThread *thread, void (*dtor)(void *));
extern void func_02087988(void);
extern void OS_LoadContext(OSContext *context);
extern void OSi_ExitThread(void *arg);
extern void OSi_ExitThread_Destroy(void);
void func_020853C0(OSThread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio);
asm void OS_ExitThread(void);
void func_020854D0(OSThread *thread, void *arg);
void func_02085528(void *arg);
extern OsThreadBss g_02150FD0;


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


asm void OS_ExitThread(void)
{
    stmfd sp!, {r3, lr}
    bl	func_02087988
    ldr r0, =g_02150FD0
    mov	r1, #0
    ldr	r0, [r0, #0x20]
    bl	func_020854D0
    ldmfd sp!, {r3, pc}
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
