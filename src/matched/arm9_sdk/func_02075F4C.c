/*
 * function: CARDi_UnlockResource
 * address:  0x02075F4C
 * packet:   pkt_02075F4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_UnlockResource (libcard.TWL.HYB.a card_common.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_Terminate  0x02088234  arm
 *   OS_WakeupThread  0x02085800  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
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

typedef enum CARDTarget
{
    CARD_TARGET_NONE,
    CARD_TARGET_ROM,
    CARD_TARGET_BACKUP
} CARDTarget;

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
    CARDTarget lock_target;
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
extern void OS_Terminate(void);
extern void OS_WakeupThread(OSThreadQueue *queue);
extern u32 OS_RestoreInterrupts(u32 state);

void CARDi_UnlockResource(s32 owner, CARDTarget target)
{
    CARDiCommon *const p = &cardi_common;
    u32 bak_psr = OS_DisableInterrupts();

    if ((p->lock_owner != owner) || !p->lock_ref)
    {
        OS_Terminate();
    }
    else
    {
        if (p->lock_target != target)
        {
            OS_Terminate();
        }
        if (--p->lock_ref == 0)
        {
            p->lock_owner = -3;
            p->lock_target = CARD_TARGET_NONE;
            OS_WakeupThread(p->lock_queue);
        }
    }
    (void)OS_RestoreInterrupts(bak_psr);
}
