/*
 * function: func_020876B8
 * address:  0x020876B8
 * packet:   pkt_020876B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_SetVAlarm (os_valarm.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OS_Terminate          0x02088234  arm
 *   OSi_GetVFrame         0x02087938  arm
 *   OSi_InsertVAlarm      0x020875B8  arm
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

extern void OS_Terminate(void);
extern s32 OSi_GetVFrame(s32 vcount);
extern void OSi_InsertVAlarm(OSVAlarm *alarm);

void func_020876B8(OSVAlarm *alarm, s16 count, s16 delay, OSVAlarmHandler handler, void *arg)
{
    OSIntrMode enabled = OS_DisableInterrupts();
    s32 currentVFrame;
    s32 currentVCount;

    if (!alarm || alarm->handler) {
        OS_Terminate();
    }

    currentVCount = reg_GX_VCOUNT;
    currentVFrame = OSi_GetVFrame(currentVCount);

    alarm->period = 0;
    alarm->frame = (u32)((count <= currentVCount) ? currentVFrame + 1 : currentVFrame);
    alarm->fire = count;
    alarm->delay = delay;
    alarm->handler = handler;
    alarm->arg = arg;
    alarm->canceled = 0;

    OSi_InsertVAlarm(alarm);
    (void)OS_RestoreInterrupts(enabled);
}
