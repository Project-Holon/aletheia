/*
 * function: OSi_InsertVAlarm
 * address:  0x020875B8
 * packet:   pkt_020875B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_InsertVAlarm (os_valarm.o)
 *
 * symbols:
 *   OSi_SetNextVAlarm  0x02087744  arm
 *   OSi_AppendVAlarm   0x02087634  arm
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

extern void OSi_AppendVAlarm(OSVAlarm *alarm);

void OSi_InsertVAlarm(OSVAlarm *alarm)
{
    OSVAlarm *prev;
    OSVAlarm *next;

    for (next = g_0215134C.OSi_VAlarmQueue_head; next; next = next->next) {
        if (next->frame < alarm->frame) {
            continue;
        }
        if (next->frame == alarm->frame && next->fire <= alarm->fire) {
            continue;
        }

        prev = next->prev;
        alarm->prev = prev;
        alarm->next = next;
        next->prev = alarm;
        if (prev) {
            prev->next = alarm;
        } else {
            g_0215134C.OSi_VAlarmQueue_head = alarm;
            OSi_SetNextVAlarm(alarm);
        }
        return;
    }

    OSi_AppendVAlarm(alarm);
}
