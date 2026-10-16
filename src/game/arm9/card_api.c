/*
 * file:     card_api.c
 * unit:     yes
 * function: CARDi_PeekEventListener, CARDi_LockBusCondition, CARD_Init, CARD_IsEnabled, CARD_CheckEnabled, CARD_Enable, CARD_GetResultCode, CARD_GetRomHeader, CARD_GetOwnRomHeader, CARD_GetOwnRomHeaderTWL, CARD_LockRom, CARD_UnlockRom, CARD_LockBackup, CARD_UnlockBackup
 * address:  0x02075C38
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
 *   OS_SignalEvent  0x02088398  arm
 *   OS_SetVAlarm  0x020876B8  arm
 *   CARDi_PeekEventListener  0x02075C38  arm
 *   OS_TryLockCard   0x02084E38  arm
 *   OS_GetBootType  0x02087B04  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   CARDi_InitResourceLock  0x0207608C  arm
 *   OS_CreateThread  0x020853C0  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   CARDi_InitCommand  0x020760B4  arm
 *   CARDi_InitRom  0x0207733C  arm
 *   CARD_Enable  0x02075DC8  arm
 *   CARD_InitPulledOutCallback  0x020773DC  arm
 *   cardi_common  0x02150200  data
 *   cardi_rom_base  0x02150840  data
 *   CARDi_OldTypeTaskThread  0x020761E4  arm
 *   sCardEnabled  0x0215019C  data
 *   OS_Terminate   0x02088234  arm
 *   CARDi_LockResource  0x02075ED4  arm
 *   OS_InitEvent  0x020882DC  arm
 *   OS_CreateVAlarm  0x020876A4  arm
 *   OS_WaitEventEx  0x020882F0  arm
 *   OS_UnlockCard   0x02084E10  arm
 *   CARDi_UnlockResource   0x02075F4C  arm
 *   CARDi_LockResource 0x02075ED4 arm
 *   CARD_TryWaitBackupAsync  0x02076B8C  arm
 *   CARD_WaitBackupAsync  0x02076B80  arm
 *   CARDi_UnlockResource  0x02075F4C  arm
 *   .word 0x02FFFA80
 *
 */
typedef unsigned char u8;

typedef unsigned long u32;

typedef short s16;

typedef unsigned short u16;

typedef int BOOL;

typedef struct OSEvent
{
    u8 data[0xC];
} OSEvent;

typedef struct OSiVAlarm
{
    u8 data[0x28];
} OSiVAlarm;

typedef struct CARDEventListener
{
    OSEvent event[1];
    OSiVAlarm alarm[1];
    BOOL (*func)(void *);
    void *arg;
    u16 lockID;
    u8 padding[2];
} CARDEventListener;

typedef long s32;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue
{
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct CARDiCommandArg
{
    int result;
} CARDiCommandArg;

typedef struct CARDDmaInterface CARDDmaInterface;

typedef struct CARDiCommon
{
    CARDiCommandArg *cmd;
    u32 flag;
    u32 priority;
    u32 flush_threshold_ic;
    u32 flush_threshold_dc;
    s32 lock_owner;
    int lock_ref;
    OSThreadQueue lock_queue[1];
    int lock_target;
    struct
    {
        u8 thread[0xC0];
        u8 stack[0x400];
    } thread;
    void (*task_func)(struct CARDiCommon *);
    void (*callback)(void *);
    void *callback_arg;
    OSThreadQueue busy_q[1];
    u32 src;
    u32 dst;
    u32 len;
    u32 dma;
    CARDDmaInterface *DmaCall;
    int req_type;
    int req_retry;
    int req_mode;
    OSThread *current_thread_9;
} CARDiCommon;

typedef struct CARDiRomState
{
    u32 rom_base;
} CARDiRomState;

typedef long s32;

extern void OS_SignalEvent(OSEvent *event, u32 setPattern);
extern void OS_SetVAlarm(OSiVAlarm *alarm, s16 count, s16 delay, void (*handler)(void *), void *arg);
extern BOOL OS_TryLockCard(unsigned int lockID);
extern u16 OS_GetBootType(void);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void CARDi_InitResourceLock(void);
extern void OS_CreateThread(OSThread *thread, void (*CARDi_PeekEventListener)(void *), void *arg, void *stack, u32 stackSize, u32 prio);
extern void OS_WakeupThreadDirect(OSThread *thread);
extern void CARDi_InitCommand(void);
extern void CARDi_InitRom(void);
extern void CARD_Enable(BOOL enable);
extern void CARD_InitPulledOutCallback(void);
extern void CARDi_OldTypeTaskThread(void *arg);
extern void OS_Terminate(void);
extern void CARDi_LockResource(s32 owner, int target);
extern void OS_InitEvent(OSEvent *event);
extern void OS_CreateVAlarm(OSiVAlarm *alarm);
extern void CARDi_PeekEventListener(void *arg);
extern u32 OS_WaitEventEx(OSEvent *event, u32 pattern, int mode, u32 clearBit);
extern int OS_UnlockCard(unsigned int id);
extern void CARDi_UnlockResource(s32 owner, int target);
extern BOOL CARD_TryWaitBackupAsync(void);
extern BOOL CARD_WaitBackupAsync(void);
BOOL CARDi_LockBusCondition(void *userdata);
void CARD_Init(void);
BOOL CARD_IsEnabled(void);
void CARD_CheckEnabled(void);
int CARD_GetResultCode(void);
void *CARD_GetRomHeader(void);
void *CARD_GetOwnRomHeader(void);
void *CARD_GetOwnRomHeaderTWL(void);
void CARD_LockRom(u16 lock_id);
void CARD_UnlockRom(unsigned int id);
void CARD_LockBackup(s32 owner);
void CARD_UnlockBackup(u16 lock_id);
extern CARDiCommon cardi_common;
extern CARDiRomState cardi_rom_base;
extern BOOL sCardEnabled;



/*
 * sdk:      CARDi_PeekEventListener (libcard.TWL.HYB.a card_api.o)
 */
void CARDi_PeekEventListener(void *arg)
{
    CARDEventListener *el = (CARDEventListener *)arg;

    if ((*el->func)(el->arg))
    {
        OS_SignalEvent(el->event, 1);
    }
    else
    {
        OS_SetVAlarm(el->alarm, 192, 263, CARDi_PeekEventListener, el);
    }
}



BOOL CARDi_LockBusCondition(void *userdata)
{
    return OS_TryLockCard(*(u16 *)userdata) == 0;
}



static inline void OS_InitThreadQueue(OSThreadQueue *queue)
{
    queue->head = queue->tail = 0;
}



/*
 * sdk:      CARD_Init (libcard.TWL.HYB.a card_api.o)
 */
void CARD_Init(void)
{
    CARDiCommon *p = &cardi_common;

    if (p->flag)
    {
        return;
    }
    p->flag = 1;
    if (OS_GetBootType() == 1)
    {
        MI_CpuCopy8((const void *)0x02FFFE00, (void *)0x02FFFA80, 0x160);
    }
    p->src = 0;
    p->dst = 0;
    p->len = 0;
    p->dma = (u32)-1;
    p->DmaCall = 0;
    p->flush_threshold_ic = 0x400;
    p->flush_threshold_dc = 0x2400;
    cardi_rom_base.rom_base = 0;
    p->priority = 4;
    CARDi_InitResourceLock();
    p->callback = 0;
    p->callback_arg = 0;
    OS_InitThreadQueue(p->busy_q);
    OS_CreateThread((OSThread *)p->thread.thread, CARDi_OldTypeTaskThread, 0,
                    p->thread.stack + sizeof(p->thread.stack), sizeof(p->thread.stack), p->priority);
    OS_WakeupThreadDirect((OSThread *)p->thread.thread);
    CARDi_InitCommand();
    CARDi_InitRom();
    if (OS_GetBootType() == 1)
    {
        CARD_Enable(1);
    }
    CARD_InitPulledOutCallback();
}




BOOL CARD_IsEnabled(void)
{
    return sCardEnabled;
}




void CARD_CheckEnabled(void)
{
    if (CARD_IsEnabled() != 0)
        return;
    OS_Terminate();
}



void CARD_Enable(BOOL enable)
{
    sCardEnabled = enable;
}




int CARD_GetResultCode(void)
{
    return cardi_common.cmd->result;
}



void *CARD_GetRomHeader(void)
{
    return (void *)0x02FFFA80;
}



void *CARD_GetOwnRomHeader(void)
{
    return (void *)0x02FFFE00;
}



void *CARD_GetOwnRomHeaderTWL(void)
{
    return (void *)0x02FFE000;
}




/*
 * sdk:      CARD_LockRom (libcard.TWL.HYB.a card_api.o)
 */
void CARD_LockRom(u16 lock_id)
{
    CARDEventListener el[1];

    CARDi_LockResource(lock_id, 1);
    OS_InitEvent(el->event);
    OS_CreateVAlarm(el->alarm);
    el->func = CARDi_LockBusCondition;
    el->arg = &lock_id;
    CARDi_PeekEventListener(el);
    (void)OS_WaitEventEx(el->event, 1, 0, 1);
}




void CARD_UnlockRom(unsigned int id)
{
    OS_UnlockCard(id);
    CARDi_UnlockResource(id, 1);
}



void CARD_LockBackup(s32 owner)
{
    CARDi_LockResource(owner, 2);
}




/*
 * sdk:      CARD_UnlockBackup (libcard.TWL.HYB.a card_api.o)
 */
void CARD_UnlockBackup(u16 lock_id)
{
    if (!CARD_TryWaitBackupAsync())
    {
        (void)CARD_WaitBackupAsync();
    }
    CARDi_UnlockResource(lock_id, 2);
}
