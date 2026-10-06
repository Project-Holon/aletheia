/*
 * file:     unit_02084FB4_p03.c
 * unit:     yes
 * function: func_02085264, func_020853B0
 * address:  0x02085264
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
 *   OS_SetSwitchThreadCallback    0x02085AF8  arm
 *   OS_CreateThread               0x020853C0  arm
 *   OSi_IdleThreadProc            0x02085B20  arm
 *   g_02150FD0                    0x02150FD0  data
 *   OSi_ThreadInfo                0x02150FEC  data
 *   OSi_IdleThread                0x02150FFC  data
 *   OSi_LauncherThread            0x021510BC  data
 *   OSi_IdleThreadStack           0x0215117C  data
 *   SDK_SYS_STACKSIZE             0x00001800  data
 *   SDK_IRQ_STACKSIZE             0x00000800  data
 *   SDK_AUTOLOAD_DTCM_START       0x02FE0000  data
 *   SDK_SECTION_ARENA_DTCM_START  0x02FE00C0  data
 *   OSi_IsThreadInitialized  0x02150FDC  data
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
extern OSSwitchThreadCallback OS_SetSwitchThreadCallback(OSSwitchThreadCallback callback);
extern void OS_CreateThread(OSThread *thread, void (*func)(void *), void *arg, void *stack,
                            u32 stackSize, u32 prio);
extern void OSi_IdleThreadProc(void *arg);
void func_02085264(void);
BOOL func_020853B0(void);
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
