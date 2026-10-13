/*
 * file:     card_api.c
 * unit:     yes
 * function: func_02075C38, func_02075C90, func_02075CAC, func_02075DA0, func_02075DB0, func_02075DC8, func_02075DD8, func_02075DEC, func_02075DF8, func_02075E04, func_02075E10, func_02075E80, func_02075E9C, func_02075EAC
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
 *   func_02084E38   0x02084E38  arm
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
 *   s_data_0215019C  0x0215019C  data
 *   func_02088234   0x02088234  arm
 *   CARDi_LockResource  0x02075ED4  arm
 *   OS_InitEvent  0x020882DC  arm
 *   OS_CreateVAlarm  0x020876A4  arm
 *   OS_WaitEventEx  0x020882F0  arm
 *   func_02084E10   0x02084E10  arm
 *   func_02075F4C   0x02075F4C  arm
 *   func_02075ED4 0x02075ED4 arm
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

typedef long s32_02075E10;

typedef signed int     s32_4;

typedef signed int     s32_5;

typedef long s32_02075EAC;

extern void OS_SignalEvent(OSEvent *event, u32 setPattern);
extern void OS_SetVAlarm(OSiVAlarm *alarm, s16 count, s16 delay, void (*handler)(void *), void *arg);
extern BOOL func_02084E38(unsigned int lockID);
extern u16 OS_GetBootType(void);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void CARDi_InitResourceLock(void);
extern void OS_CreateThread(OSThread *thread, void (*func_02075C38)(void *), void *arg, void *stack, u32 stackSize, u32 prio);
extern void OS_WakeupThreadDirect(OSThread *thread);
extern void CARDi_InitCommand(void);
extern void CARDi_InitRom(void);
extern void CARD_Enable(BOOL enable);
extern void CARD_InitPulledOutCallback(void);
extern void CARDi_OldTypeTaskThread(void *arg);
extern void func_02088234(void);
extern void CARDi_LockResource(s32_02075E10 owner, int target);
extern void OS_InitEvent(OSEvent *event);
extern void OS_CreateVAlarm(OSiVAlarm *alarm);
extern void CARDi_PeekEventListener(void *arg);
extern u32 OS_WaitEventEx(OSEvent *event, u32 pattern, int mode, u32 clearBit);
extern int func_02084E10(unsigned int id);
extern void func_02075F4C(s32_4 owner, int target);
extern void func_02075ED4(s32_5 owner, int target);
extern BOOL CARD_TryWaitBackupAsync(void);
extern BOOL CARD_WaitBackupAsync(void);
extern void CARDi_UnlockResource(s32_02075EAC owner, int target);
void func_02075C38(void *arg);
BOOL CARDi_LockBusCondition(void *userdata);
void func_02075CAC(void);
void *func_02075DA0(void);
void CARD_CheckEnabled(void);
void func_02075DC8(void *p);
int CARD_GetResultCode(void);
void *CARD_GetRomHeader(void);
void *CARD_GetOwnRomHeader(void);
void *CARD_GetOwnRomHeaderTWL(void);
void func_02075E10(u16 lock_id);
void CARD_UnlockRom(unsigned int id);
void CARD_LockBackup(s32 owner);
void func_02075EAC(u16 lock_id);
extern CARDiCommon cardi_common;
extern CARDiRomState cardi_rom_base;
extern void *s_data_0215019C;



/*
 * sdk:      CARDi_PeekEventListener (libcard.TWL.HYB.a card_api.o)
 */
void func_02075C38(void *arg)
{
    CARDEventListener *el = (CARDEventListener *)arg;

    if ((*el->func)(el->arg))
    {
        OS_SignalEvent(el->event, 1);
    }
    else
    {
        OS_SetVAlarm(el->alarm, 192, 263, func_02075C38, el);
    }
}



BOOL CARDi_LockBusCondition(void *userdata)
{
    return func_02084E38(*(u16 *)userdata) == 0;
}



static inline void OS_InitThreadQueue(OSThreadQueue *queue)
{
    queue->head = queue->tail = 0;
}



/*
 * sdk:      CARD_Init (libcard.TWL.HYB.a card_api.o)
 */
void func_02075CAC(void)
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




void *func_02075DA0(void)
{
    return s_data_0215019C;
}




void CARD_CheckEnabled(void)
{
    if (func_02075DA0() != 0)
        return;
    func_02088234();
}



void func_02075DC8(void *p)
{
    s_data_0215019C = p;
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
void func_02075E10(u16 lock_id)
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
    func_02084E10(id);
    func_02075F4C(id, 1);
}



void CARD_LockBackup(s32 owner)
{
    func_02075ED4(owner, 2);
}




/*
 * sdk:      CARD_UnlockBackup (libcard.TWL.HYB.a card_api.o)
 */
void func_02075EAC(u16 lock_id)
{
    if (!CARD_TryWaitBackupAsync())
    {
        (void)CARD_WaitBackupAsync();
    }
    CARDi_UnlockResource(lock_id, 2);
}
