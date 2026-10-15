/*
 * function: CARDi_Request
 * address:  0x020763F0
 * packet:   pkt_020763F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_Request (libcard.TWL.HYB.a card_backup.o)
 *
 * symbols:
 *   PXI_IsCallbackReady  0x020885EC  arm
 *   OS_SpinWaitSysCycles  0x02087A04  arm
 *   CARDi_Request  0x020763F0  arm
 *   DC_FlushRange  0x020862F0  arm
 *   DC_WaitWriteBufferEmpty  0x02086314  arm
 *   PXI_SendWordByFifo  0x02088610  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_SleepThread  0x020857B0  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   DC_InvalidateRange  0x020862B8  arm
 *   OSi_ThreadInfo  0x02150FEC  data
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
    u8 data[0x5C];
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


typedef struct OSThreadInfo
{
    u16 isNeedRescheduling;
    u16 irqDepth;
    OSThread *current;
} OSThreadInfo;

extern OSThreadInfo OSi_ThreadInfo;

extern BOOL PXI_IsCallbackReady(int fifotag, int proc);
extern void OS_SpinWaitSysCycles(u32 cycle);
extern void DC_FlushRange(void *startAddr, u32 nBytes);
extern void DC_WaitWriteBufferEmpty(void);
extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
extern u32 OS_DisableInterrupts(void);
extern void OS_SleepThread(OSThreadQueue *queue);
extern u32 OS_RestoreInterrupts(u32 state);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);

static inline OSThread *OS_GetCurrentThread(void)
{
    return OSi_ThreadInfo.current;
}

BOOL CARDi_Request(CARDiCommon *p, int req_type, int retry_count);

BOOL CARDi_Request(CARDiCommon *p, int req_type, int retry_count)
{
    if ((*(volatile u32 *)&p->flag & 2) == 0)
    {
        p->flag |= 2;
        while (!PXI_IsCallbackReady(11, 1))
        {
            OS_SpinWaitSysCycles(50);
        }
        (void)CARDi_Request(p, 0, 1);
    }
    DC_FlushRange(p->cmd, sizeof(*p->cmd));
    DC_WaitWriteBufferEmpty();
    p->current_thread_9 = OS_GetCurrentThread();
    do
    {
        p->flag |= 0x20;
        while (PXI_SendWordByFifo(11, (u32)req_type, 1) < 0)
        {
        }
        if (req_type == 0)
        {
            const u32 arg = (u32)p->cmd;

            while (PXI_SendWordByFifo(11, arg, 1) < 0)
            {
            }
        }
        {
            u32 bak_psr = OS_DisableInterrupts();

            while ((p->flag & 0x20) != 0)
            {
                OS_SleepThread(0);
            }
            (void)OS_RestoreInterrupts(bak_psr);
        }
        DC_InvalidateRange(p->cmd, sizeof(*p->cmd));
    } while ((p->cmd->result == 4) && (--retry_count > 0));
    return (p->cmd->result == 0);
}
