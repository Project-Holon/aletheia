/*
 * function: func_02076170
 * address:  0x02076170
 * packet:   pkt_02076170
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_ExecuteOldTypeTask (libcard.TWL.HYB.a card_task.o)
 *
 * symbols:
 *   OS_SetThreadPriority  0x02085988  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   CARDi_EndTask  0x020762A8  arm
 *   cardi_common  0x02150200  data
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

extern CARDiCommon cardi_common;

extern BOOL OS_SetThreadPriority(OSThread *thread, u32 prio);
extern void OS_WakeupThreadDirect(OSThread *thread);
extern void CARDi_EndTask(CARDiCommon *p);

BOOL func_02076170(void (*task)(CARDiCommon *), BOOL async)
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
