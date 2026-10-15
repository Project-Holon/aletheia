/*
 * function: CARDi_InitCommand
 * address:  0x020760B4
 * packet:   pkt_020760B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_InitCommand (libcard.TWL.HYB.a card_common.o)
 *
 * symbols:
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   DC_FlushRange  0x020862F0  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   cardi_arg  0x021501A0  data
 *   cardi_common  0x02150200  data
 *   CARDi_OnFifoRecv  0x020763BC  arm
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
    u8 data[0x60];
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

extern CARDiCommandArg cardi_arg;

extern void MIi_CpuClearFast(u32 data, void *destp, u32 size);
extern void DC_FlushRange(void *startAddr, u32 nBytes);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int, u32, BOOL));
extern void CARDi_OnFifoRecv(int tag, u32 data, BOOL err);

void CARDi_InitCommand(void)
{
    CARDiCommon *p = &cardi_common;

    p->cmd = &cardi_arg;
    MIi_CpuClearFast(0, &cardi_arg, sizeof(cardi_arg));
    DC_FlushRange(&cardi_arg, sizeof(cardi_arg));
    PXI_SetFifoRecvCallback(11, CARDi_OnFifoRecv);
}
