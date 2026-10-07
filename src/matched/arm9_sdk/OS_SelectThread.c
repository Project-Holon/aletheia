/*
 * function: OS_SelectThread
 * address:  0x02085890
 * packet:   pkt_02085890
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_thread.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * The thread list is read through the section-relative .bss base.
 *
 * symbols:
 *   g_02150FD0  0x02150FD0  data
 */

#include "../include/G_OsThreadBss.h"

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
typedef struct OsThreadBss OsThreadBss;

extern struct OsThreadBss g_02150FD0;

OSThread *OS_SelectThread(void)
{
    OSThread *t = g_02150FD0.OSi_ThreadInfo_list;

    while (t && t->state != OS_THREAD_STATE_READY) {
        t = t->next;
    }
    return t;
}
