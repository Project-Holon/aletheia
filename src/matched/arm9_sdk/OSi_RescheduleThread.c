/*
 * function: OSi_RescheduleThread
 * address:  0x020851A0
 * packet:   pkt_020851A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_thread.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Static in the vendor object.  &OSi_ThreadInfo (the local `info`) is its own
 * pool word at 0x02150FEC; the direct reads and the current-thread store go
 * through the section base.
 *
 * symbols:
 *   gOsThreadBss            0x02150FD0  data
 *   OSi_ThreadInfo        0x02150FEC  data
 *   OS_GetProcMode        0x020879EC  arm
 *   OS_SelectThread       0x02085890  arm
 *   OS_SaveContext        0x02085C08  arm
 *   OS_LoadContext        0x02085C54  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef enum OSThreadState {
    OS_THREAD_STATE_WAITING = 0,
    OS_THREAD_STATE_READY = 1,
    OS_THREAD_STATE_TERMINATED = 2
} OSThreadState;

typedef struct OSContext {
    u8 opaque[0x64];
} OSContext;

typedef struct _OSThread OSThread;

typedef struct _OSThreadQueue {
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct _OSThreadLink {
    OSThread *prev;
    OSThread *next;
} OSThreadLink;

struct _OSThread {
    OSContext context;
    OSThreadState state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;
    OSThreadQueue *queue;
    OSThreadLink link;
};

typedef struct OSThreadInfo {
    u16 isNeedRescheduling;
    u16 irqDepth;
    OSThread *current;
    OSThread *list;
    void *switchCallback;
} OSThreadInfo;

/* os_thread.o .bss from 0x02150FD0, addressed section-relative from one pool
   word.  +0, +4, +8 and +0x1C are fixed by the accesses; the four words at
   +0x0C are the object's other 4-byte data in an order no access here reads. */
typedef struct OsThreadBss {
    void *OSi_SystemCallbackInSwitchThread;
    u32 OSi_RescheduleCount;
    OSThread **OSi_CurrentThreadPtr;
    u32 other[4];
    OSThreadInfo OSi_ThreadInfo;
} OsThreadBss;

extern OsThreadBss gOsThreadBss;

typedef void (*OSSwitchThreadCallback)(OSThread *from, OSThread *to);

extern OSThreadInfo OSi_ThreadInfo;
extern int OS_GetProcMode(void);
extern OSThread *OS_SelectThread(void);
extern BOOL OS_SaveContext(OSContext *context);
extern void OS_LoadContext(OSContext *context);

void OSi_RescheduleThread(void)
{
    if (gOsThreadBss.OSi_RescheduleCount == 0) {
        OSThreadInfo *info = &OSi_ThreadInfo;

        if (gOsThreadBss.OSi_ThreadInfo.irqDepth > 0 || OS_GetProcMode() == 0x12) {
            info->isNeedRescheduling = 1;
        } else {
            OSThread *currentThread, *nextThread;

            currentThread = *gOsThreadBss.OSi_CurrentThreadPtr;
            nextThread = OS_SelectThread();

            if (currentThread == nextThread || !nextThread) {
                return;
            }

            if (currentThread->state != OS_THREAD_STATE_TERMINATED
                && OS_SaveContext(&currentThread->context)) {
                return;
            }

            if (gOsThreadBss.OSi_SystemCallbackInSwitchThread) {
                ((OSSwitchThreadCallback)gOsThreadBss.OSi_SystemCallbackInSwitchThread)(currentThread, nextThread);
            }

            if (info->switchCallback) {
                ((OSSwitchThreadCallback)info->switchCallback)(currentThread, nextThread);
            }

            gOsThreadBss.OSi_ThreadInfo.current = nextThread;

            OS_LoadContext(&nextThread->context);
        }
    }
}
