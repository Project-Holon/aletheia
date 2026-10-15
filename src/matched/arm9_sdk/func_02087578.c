/*
 * function: OS_InitVAlarm
 * address:  0x02087578
 * packet:   pkt_02087578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_InitVAlarm (os_valarm.o)
 *
 * symbols:
 *   OS_DisableIrqMask  0x02084998  arm
 *   g_0215134C         0x0215134C  data
 */

#include "../include/G_OsVAlarmBss.h"

typedef unsigned long u32;
typedef long s32;
typedef short s16;
typedef unsigned short u16;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef struct OSiVAlarm OSVAlarm;
typedef void (*OSVAlarmHandler)(void *arg);

struct OSiVAlarm {
    OSVAlarmHandler handler;
    void *arg;
    u32 tag;
    u32 frame;
    s16 fire;
    s16 delay;
    OSVAlarm *prev;
    OSVAlarm *next;
    BOOL period;
    BOOL finish;
    BOOL canceled;
};

typedef struct OSVAlarmQueue {
    OSVAlarm *head;
    OSVAlarm *tail;
} OSVAlarmQueue;

/* os_valarm.o .bss from 0x0215134C, addressed from one pool word. */
typedef struct OsVAlarmBss OsVAlarmBss;

extern struct OsVAlarmBss g_0215134C;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void OSi_SetNextVAlarm(OSVAlarm *alarm);

#define reg_GX_VCOUNT (*(volatile u16 *)0x04000006)

extern u32 OS_DisableIrqMask(u32 intr);

void OS_InitVAlarm(void)
{
    if (!g_0215134C.OSi_UseVAlarm) {
        g_0215134C.OSi_UseVAlarm = 1;

        g_0215134C.OSi_VAlarmQueue_head = 0;
        g_0215134C.OSi_VAlarmQueue_tail = 0;

        (void)OS_DisableIrqMask(4);

        g_0215134C.OSi_VFrameCount = 0;
        g_0215134C.OSi_PreviousVCount = 0;
    }
}
