/*
 * file:     os_valarm.c
 * unit:     yes
 * function: OS_InitVAlarm, OSi_InsertVAlarm, OSi_AppendVAlarm, OSi_DetachVAlarm, OS_CreateVAlarm, OS_SetVAlarm, OSi_SetNextVAlarm, OSi_VAlarmHandler, OSi_CompareVCount, OSi_GetVFrame
 * address:  0x02087578
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableIrqMask  0x02084998  arm
 *   g_0215134C         0x0215134C  data
 *   OSi_SetNextVAlarm  0x02087744  arm
 *   OSi_AppendVAlarm   0x02087634  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OS_Terminate          0x02088234  arm
 *   OSi_GetVFrame         0x02087938  arm
 *   OSi_InsertVAlarm      0x020875B8  arm
 *   OS_SetIrqFunction  0x02084774  arm
 *   GX_SetVCountEqVal  0x0207D384  arm
 *   OS_EnableIrqMask   0x02084968  arm
 *   OSi_VAlarmHandler  0x02087784  arm
 *   OS_ResetRequestIrqMask   0x020849C8  arm
 *   OSi_CompareVCount        0x020878EC  arm
 *   OSi_DetachVAlarm         0x0208766C  arm
 *   SDK_AUTOLOAD_DTCM_START  0x02FE0000  data
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

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern void OSi_SetNextVAlarm(OSVAlarm *alarm);
extern u32 OS_DisableIrqMask(u32 intr);
extern void OSi_AppendVAlarm(OSVAlarm *alarm);
extern void OS_Terminate(void);
extern s32 OSi_GetVFrame(s32 vcount);
extern void OSi_InsertVAlarm(OSVAlarm *alarm);
extern void OS_SetIrqFunction(u32 intrBit, void (*function)(void));
extern void GX_SetVCountEqVal(s32 val);
extern u32 OS_EnableIrqMask(u32 intr);
extern void OSi_VAlarmHandler(void);
extern u32 OS_ResetRequestIrqMask(u32 intr);
extern int OSi_CompareVCount(OSVAlarm *alarm, s32 currentVFrame, s32 currentVCount);
extern void OSi_DetachVAlarm(OSVAlarm *alarm);
void OS_InitVAlarm(void);
void OS_CreateVAlarm(OSVAlarm *alarm);
void OS_SetVAlarm(OSVAlarm *alarm, s16 count, s16 delay, OSVAlarmHandler handler, void *arg);
extern OsVAlarmBss g_0215134C;
extern char SDK_AUTOLOAD_DTCM_START[];


#define reg_GX_VCOUNT (*(volatile u16 *)0x04000006)


/*
 * sdk:      OS_InitVAlarm (os_valarm.o)
 */
void OS_InitVAlarm(void)
{
    if (!g_0215134C.OSi_UseVAlarm) {
        g_0215134C.OSi_UseVAlarm = 1;

        g_0215134C.OSi_VAlarmQueue.head = 0;
        g_0215134C.OSi_VAlarmQueue.tail = 0;

        (void)OS_DisableIrqMask(4);

        g_0215134C.OSi_VFrameCount = 0;
        g_0215134C.OSi_PreviousVCount = 0;
    }
}


#define reg_GX_VCOUNT (*(volatile u16 *)0x04000006)


/*
 * sdk:      OSi_InsertVAlarm (os_valarm.o)
 */
void OSi_InsertVAlarm(OSVAlarm *alarm)
{
    OSVAlarm *prev;
    OSVAlarm *next;

    for (next = g_0215134C.OSi_VAlarmQueue.head; next; next = next->next) {
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
            g_0215134C.OSi_VAlarmQueue.head = alarm;
            OSi_SetNextVAlarm(alarm);
        }
        return;
    }

    OSi_AppendVAlarm(alarm);
}


#define reg_GX_VCOUNT (*(volatile u16 *)0x04000006)


/*
 * sdk:      OSi_AppendVAlarm (os_valarm.o)
 */
void OSi_AppendVAlarm(OSVAlarm *alarm)
{
    OSVAlarm *prev = g_0215134C.OSi_VAlarmQueue.tail;

    alarm->prev = prev;
    alarm->next = 0;
    g_0215134C.OSi_VAlarmQueue.tail = alarm;

    if (prev) {
        prev->next = alarm;
    } else {
        g_0215134C.OSi_VAlarmQueue.head = alarm;
        OSi_SetNextVAlarm(alarm);
    }
}


#define reg_GX_VCOUNT (*(volatile u16 *)0x04000006)


/*
 * sdk:      OSi_DetachVAlarm (os_valarm.o)
 */
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
        g_0215134C.OSi_VAlarmQueue.tail = prev;
    }

    if (prev) {
        prev->next = next;
    } else {
        g_0215134C.OSi_VAlarmQueue.head = next;
    }
}


/*
 * note:     os_valarm.o OS_CreateVAlarm.
 */
void OS_CreateVAlarm(OSVAlarm *alarm)
{
    alarm->handler = 0;
    alarm->tag = 0;
    alarm->finish = 0;
}


#define reg_GX_VCOUNT (*(volatile u16 *)0x04000006)


/*
 * sdk:      OS_SetVAlarm (os_valarm.o)
 */
void OS_SetVAlarm(OSVAlarm *alarm, s16 count, s16 delay, OSVAlarmHandler handler, void *arg)
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


#define reg_GX_VCOUNT (*(volatile u16 *)0x04000006)


/*
 * sdk:      OSi_SetNextVAlarm (os_valarm.o)
 */
void OSi_SetNextVAlarm(OSVAlarm *alarm)
{
    OS_SetIrqFunction(4, OSi_VAlarmHandler);
    GX_SetVCountEqVal(alarm->fire);
    *(volatile u16 *)0x04000004 = (u16)(*(volatile u16 *)0x04000004 | 0x20);
    (void)OS_EnableIrqMask(4);
}


#define reg_GX_VCOUNT (*(volatile u16 *)0x04000006)


#define reg_GX_DISPSTAT (*(volatile u16 *)0x04000004)

#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))


/*
 * sdk:      OSi_VAlarmHandler (os_valarm.o)
 */
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

    while ((alarm = g_0215134C.OSi_VAlarmQueue.head) != 0) {
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


#define reg_GX_VCOUNT (*(volatile u16 *)0x04000006)


/*
 * sdk:      OSi_CompareVCount (os_valarm.o)
 */
int OSi_CompareVCount(OSVAlarm *alarm, s32 currentVFrame, s32 currentVCount)
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


#define reg_GX_VCOUNT (*(volatile u16 *)0x04000006)


/*
 * sdk:      OSi_GetVFrame (os_valarm.o)
 */
s32 OSi_GetVFrame(s32 vcount)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (vcount < g_0215134C.OSi_PreviousVCount) {
        g_0215134C.OSi_VFrameCount++;
    }
    g_0215134C.OSi_PreviousVCount = vcount;

    (void)OS_RestoreInterrupts(enabled);
    return g_0215134C.OSi_VFrameCount;
}
