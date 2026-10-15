/*
 * file:     card_task.c
 * unit:     yes
 * function: CARDi_ExecuteOldTypeTask, CARDi_OldTypeTaskThread, CARDi_WaitForTask, CARDi_EndTask
 * address:  0x02076170
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
 *   OS_SetThreadPriority  0x02085988  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   CARDi_EndTask  0x020762A8  arm
 *   cardi_common  0x02150200  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_SleepThread  0x020857B0  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   CARDi_ExecuteOldTypeTask  0x02076170  arm
 *   OS_WakeupThread  0x02085800  arm
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
    u8 thread[1216];
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

typedef enum CARDTarget
{
    CARD_TARGET_NONE,
    CARD_TARGET_ROM,
    CARD_TARGET_BACKUP
} CARDTarget;

extern BOOL OS_SetThreadPriority(OSThread *thread, u32 prio);
extern void OS_WakeupThreadDirect(OSThread *thread);
extern void CARDi_EndTask(CARDiCommon *p);
extern u32 OS_DisableInterrupts(void);
extern void OS_SleepThread(OSThreadQueue *queue);
extern u32 OS_RestoreInterrupts(u32 state);
extern BOOL CARDi_ExecuteOldTypeTask(void (*task)(CARDiCommon *), BOOL async);
extern void OS_WakeupThread(OSThreadQueue *queue);
void CARDi_OldTypeTaskThread(void);
BOOL CARDi_WaitForTask(CARDiCommon *p, BOOL restart, void (*callback)(void *), void *callback_arg);
extern CARDiCommon cardi_common;




/*
 * sdk:      CARDi_ExecuteOldTypeTask (libcard.TWL.HYB.a card_task.o)
 */
BOOL CARDi_ExecuteOldTypeTask(void (*task)(CARDiCommon *), BOOL async)
{
    CARDiCommon *p = &cardi_common;

    if (async)
    {
        (void)OS_SetThreadPriority((OSThread *)p->thread, p->priority);
        p->task_func = task;
        p->flag |= 8;
        OS_WakeupThreadDirect((OSThread *)p->thread);
    }
    else
    {
        (*task)(p);
        CARDi_EndTask(p);
    }
    return async ? 1 : (p->cmd->result == 0);
}




/*
 * sdk:      CARDi_OldTypeTaskThread (libcard.TWL.HYB.a card_task.o)
 */
void CARDi_OldTypeTaskThread(void)
{
    CARDiCommon *p = &cardi_common;

    for (;;)
    {
        u32 bak_psr = OS_DisableInterrupts();

        for (;;)
        {
            if ((p->flag & 0x8) != 0)
            {
                break;
            }
            OS_SleepThread(0);
        }
        (void)OS_RestoreInterrupts(bak_psr);
        (void)CARDi_ExecuteOldTypeTask(p->task_func, 0);
    }
}



/*
 * sdk:      CARDi_WaitForTask (libcard.TWL.HYB.a card_task.o)
 */
BOOL CARDi_WaitForTask(CARDiCommon *p, BOOL restart, void (*callback)(void *), void *callback_arg)
{
    u32 bak_psr = OS_DisableInterrupts();

    while ((p->flag & 4) != 0)
    {
        OS_SleepThread(p->busy_q);
    }
    if (restart)
    {
        p->flag |= 4;
        p->callback = callback;
        p->callback_arg = callback_arg;
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return (p->cmd->result == 0);
}


/*
 * sdk:      CARDi_EndTask (libcard.TWL.HYB.a card_task.o)
 */
void CARDi_EndTask(CARDiCommon *p)
{
    void (*const callback)(void *) = p->callback;
    void *const userdata = p->callback_arg;
    u32 bak_psr = OS_DisableInterrupts();

    p->flag &= ~(0x04 | 0x08 | 0x40);
    OS_WakeupThread(p->busy_q);
    (void)OS_RestoreInterrupts(bak_psr);
    if (callback)
    {
        (*callback)(userdata);
    }
}
