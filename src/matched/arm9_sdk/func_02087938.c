/*
 * function: func_02087938
 * address:  0x02087938
 * packet:   pkt_02087938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_GetVFrame (os_valarm.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_0215134C            0x0215134C  data
 */

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
typedef struct OsVAlarmBss {
    u16 OSi_UseVAlarm;
    s32 OSi_PreviousVCount;
    s32 OSi_VFrameCount;
    OSVAlarmQueue OSi_VAlarmQueue;
} OsVAlarmBss;

extern OsVAlarmBss g_0215134C;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void OSi_SetNextVAlarm(OSVAlarm *alarm);

#define reg_GX_VCOUNT (*(volatile u16 *)0x04000006)

s32 func_02087938(s32 vcount)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (vcount < g_0215134C.OSi_PreviousVCount) {
        g_0215134C.OSi_VFrameCount++;
    }
    g_0215134C.OSi_PreviousVCount = vcount;

    (void)OS_RestoreInterrupts(enabled);
    return g_0215134C.OSi_VFrameCount;
}
