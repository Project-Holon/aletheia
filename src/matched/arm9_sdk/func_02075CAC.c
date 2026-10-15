/*
 * function: CARD_Init
 * address:  0x02075CAC
 * packet:   pkt_02075CAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARD_Init (libcard.TWL.HYB.a card_api.o)
 *
 * symbols:
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
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef int BOOL;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue
{
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct CARDiCommandArg CARDiCommandArg;
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

extern CARDiCommon cardi_common;

typedef struct CARDiRomState
{
    u32 rom_base;
} CARDiRomState;

extern CARDiRomState cardi_rom_base;

extern u16 OS_GetBootType(void);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void CARDi_InitResourceLock(void);
extern void OS_CreateThread(OSThread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio);
extern void OS_WakeupThreadDirect(OSThread *thread);
extern void CARDi_InitCommand(void);
extern void CARDi_InitRom(void);
extern void CARD_Enable(BOOL enable);
extern void CARD_InitPulledOutCallback(void);
extern void CARDi_OldTypeTaskThread(void *arg);

static inline void OS_InitThreadQueue(OSThreadQueue *queue)
{
    queue->head = queue->tail = 0;
}

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
