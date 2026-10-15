/*
 * function: CARDi_OnFifoRecv
 * address:  0x020763BC
 * packet:   pkt_020763BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_OnFifoRecv (libcard.TWL.HYB.a card_backup.o)
 *
 * symbols:
 *   OS_WakeupThreadDirect  0x02085868  arm
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

extern void OS_WakeupThreadDirect(OSThread *thread);

void CARDi_OnFifoRecv(int tag, u32 data, BOOL err)
{
#pragma unused(data)
    if ((tag == 11) && err)
    {
        CARDiCommon *const p = &cardi_common;

        p->flag &= ~0x20;
        OS_WakeupThreadDirect(p->current_thread_9);
    }
}
