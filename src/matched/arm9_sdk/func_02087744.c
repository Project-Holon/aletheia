/*
 * function: OSi_SetNextVAlarm
 * address:  0x02087744
 * packet:   pkt_02087744
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_SetNextVAlarm (os_valarm.o)
 *
 * symbols:
 *   OS_SetIrqFunction  0x02084774  arm
 *   GX_SetVCountEqVal  0x0207D384  arm
 *   OS_EnableIrqMask   0x02084968  arm
 *   OSi_VAlarmHandler  0x02087784  arm
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

extern void OS_SetIrqFunction(u32 intrBit, void (*function)(void));
extern void GX_SetVCountEqVal(s32 val);
extern u32 OS_EnableIrqMask(u32 intr);
extern void OSi_VAlarmHandler(void);

void OSi_SetNextVAlarm(OSVAlarm *alarm)
{
    OS_SetIrqFunction(4, OSi_VAlarmHandler);
    GX_SetVCountEqVal(alarm->fire);
    *(volatile u16 *)0x04000004 = (u16)(*(volatile u16 *)0x04000004 | 0x20);
    (void)OS_EnableIrqMask(4);
}
