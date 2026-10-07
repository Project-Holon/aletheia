/*
 * function: func_020878EC
 * address:  0x020878EC
 * packet:   pkt_020878EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_CompareVCount (os_valarm.o)
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

int func_020878EC(OSVAlarm *alarm, s32 currentVFrame, s32 currentVCount)
{
    s32 delayVFrame = currentVFrame - (s32)alarm->frame;
    s32 delayVCount = currentVCount - alarm->fire;

    if (delayVFrame < 0 || (delayVFrame == 0 && delayVCount < 0)) {
        return 0;
    }

    if (delayVCount < 0) {
        delayVCount += 263;
    }
    return (delayVCount <= alarm->delay) ? 1 : 2;
}
