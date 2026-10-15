/*
 * function: OSi_DetachVAlarm
 * address:  0x0208766C
 * packet:   pkt_0208766C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_DetachVAlarm (os_valarm.o)
 *
 * symbols:
 *   g_0215134C  0x0215134C  data
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

void OSi_DetachVAlarm(OSVAlarm *alarm)
{
    OSVAlarm *prev;
    OSVAlarm *next;

    if (!alarm) {
        return;
    }

    next = alarm->next;
    prev = alarm->prev;

    if (next) {
        next->prev = prev;
    } else {
        g_0215134C.OSi_VAlarmQueue_tail = prev;
    }

    if (prev) {
        prev->next = next;
    } else {
        g_0215134C.OSi_VAlarmQueue_head = next;
    }
}
