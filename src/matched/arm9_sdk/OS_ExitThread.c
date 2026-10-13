/*
 * function: OS_ExitThread
 * address:  0x020854B0
 * packet:   pkt_020854B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020854D0 0x020854D0 arm
 *   func_02087988 0x02087988 arm
 *   g_02150FD0 0x02150FD0 data
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef struct _OSThread OSThread;

typedef struct OSThreadInfo {
    u16 isNeedRescheduling;
    u16 irqDepth;
    OSThread *current;
    OSThread *list;
    void *switchCallback;
} OSThreadInfo;

typedef struct OsThreadBss {
    void *OSi_SystemCallbackInSwitchThread;
    u32 OSi_RescheduleCount;
    OSThread **OSi_CurrentThreadPtr;
    int OSi_IsThreadInitialized;
    u32 OSi_SystemStackBuffer;
    u32 OSi_StackForDestructor;
    u32 OSi_ThreadIdCount;
    OSThreadInfo OSi_ThreadInfo;
} OsThreadBss;

extern void func_020854D0(OSThread *thread, void *arg);
extern void func_02087988(void);
extern OsThreadBss g_02150FD0;

void OS_ExitThread(void)
{
    func_02087988();
    func_020854D0(g_02150FD0.OSi_ThreadInfo.current, 0);
}
