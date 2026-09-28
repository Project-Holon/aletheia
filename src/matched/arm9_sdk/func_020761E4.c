/*
 * function: func_020761E4
 * address:  0x020761E4
 * packet:   pkt_020761E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_OldTypeTaskThread (libcard.TWL.HYB.a card_task.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_SleepThread  0x020857B0  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   CARDi_ExecuteOldTypeTask  0x02076170  arm
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

extern u32 OS_DisableInterrupts(void);
extern void OS_SleepThread(OSThreadQueue *queue);
extern u32 OS_RestoreInterrupts(u32 state);
extern BOOL CARDi_ExecuteOldTypeTask(void (*task)(CARDiCommon *), BOOL async);

void func_020761E4(void)
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
