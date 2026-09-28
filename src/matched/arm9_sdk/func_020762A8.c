/*
 * function: func_020762A8
 * address:  0x020762A8
 * packet:   pkt_020762A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_EndTask (libcard.TWL.HYB.a card_task.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_WakeupThread  0x02085800  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
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


extern u32 OS_DisableInterrupts(void);
extern void OS_WakeupThread(OSThreadQueue *queue);
extern u32 OS_RestoreInterrupts(u32 state);

void func_020762A8(CARDiCommon *p)
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
