/*
 * function: OSi_VAlarmHandler
 * address:  0x02087784
 * packet:   pkt_02087784
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_VAlarmHandler (os_valarm.o)
 *
 * symbols:
 *   OS_DisableIrqMask        0x02084998  arm
 *   OS_ResetRequestIrqMask   0x020849C8  arm
 *   OSi_GetVFrame            0x02087938  arm
 *   OSi_CompareVCount        0x020878EC  arm
 *   OSi_SetNextVAlarm        0x02087744  arm
 *   OSi_DetachVAlarm         0x0208766C  arm
 *   OSi_InsertVAlarm         0x020875B8  arm
 *   SDK_AUTOLOAD_DTCM_START  0x02FE0000  data
 *   g_0215134C               0x0215134C  data
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

extern char SDK_AUTOLOAD_DTCM_START[];
extern u32 OS_DisableIrqMask(u32 intr);
extern u32 OS_ResetRequestIrqMask(u32 intr);
extern s32 OSi_GetVFrame(s32 vcount);
extern int OSi_CompareVCount(OSVAlarm *alarm, s32 currentVFrame, s32 currentVCount);
extern void OSi_DetachVAlarm(OSVAlarm *alarm);
extern void OSi_InsertVAlarm(OSVAlarm *alarm);

#define reg_GX_DISPSTAT (*(volatile u16 *)0x04000004)
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

void OSi_VAlarmHandler(void)
{
    OSVAlarm *alarm;
    OSVAlarmHandler handler;
    int check;
    s32 currentVFrame;

    (void)OS_DisableIrqMask(4);
    reg_GX_DISPSTAT &= (u16)~0x20;
    OSi_IRQ_CHECK_FLAG |= 4;

    {
        u16 dispstat = reg_GX_DISPSTAT;

        (void)OSi_GetVFrame((((dispstat >> 8) & 0xFF) | ((dispstat << 1) & 0x100)) - 1);
    }

    while ((alarm = g_0215134C.OSi_VAlarmQueue_head) != 0) {
        s32 currentVCount = reg_GX_VCOUNT;

        currentVFrame = OSi_GetVFrame(currentVCount);
        check = OSi_CompareVCount(alarm, currentVFrame, currentVCount);

        switch (check) {
        case 0:
            OSi_SetNextVAlarm(alarm);
            currentVCount = reg_GX_VCOUNT;
            if (alarm->fire != currentVCount || alarm->frame != currentVFrame) {
                return;
            }
            (void)OS_DisableIrqMask(4);
            reg_GX_DISPSTAT &= (u16)~0x20;
            (void)OS_ResetRequestIrqMask(4);
            /* fall through */
        case 1:
            handler = alarm->handler;
            OSi_DetachVAlarm(alarm);
            alarm->handler = 0;
            if (handler) {
                handler(alarm->arg);
            }
            if (alarm->period && !alarm->canceled) {
                alarm->handler = handler;
                alarm->frame = (u32)(g_0215134C.OSi_VFrameCount + 1);
                OSi_InsertVAlarm(alarm);
            }
            break;
        case 2:
            OSi_DetachVAlarm(alarm);
            alarm->frame = (u32)(g_0215134C.OSi_VFrameCount + 1);
            OSi_InsertVAlarm(alarm);
            break;
        }
    }
}
