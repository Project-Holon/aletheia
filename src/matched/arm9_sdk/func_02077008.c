/*
 * function: func_02077008
 * address:  0x02077008
 * packet:   pkt_02077008
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_ReadRomWithDMA (libcard.TWL.HYB.a card_rom.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_SetIrqFunction  0x02084774  arm
 *   OS_ResetRequestIrqMask  0x020849C8  arm
 *   OS_EnableIrqMask  0x02084968  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   CARDi_StartRomPageTransfer  0x02076C88  arm
 *   cardi_rom_base  0x02150840  data
 *   CARDi_DmaReadPageCallback  0x02076F68  arm
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
typedef struct CARDDmaInterface
{
    void (*Recv)(u32 channel, const void *src, void *dst, u32 len);
} CARDDmaInterface;

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

typedef struct CARDTransferInfo
{
    u32 command;
    void (*callback)(void *);
    void *userdata;
    u32 src;
    u32 dst;
    u32 len;
    u32 work;
} CARDTransferInfo;

typedef struct CARDiRomState
{
    u32 rom_base;
    void *read_func;
    u32 unk08;
    CARDTransferInfo *transfer_info;
} CARDiRomState;

extern CARDiRomState cardi_rom_base;

extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern void OS_SetIrqFunction(u32 intrBit, void (*function)(void));
extern u32 OS_ResetRequestIrqMask(u32 intr);
extern u32 OS_EnableIrqMask(u32 intr);
extern void CARDi_StartRomPageTransfer(u32 offset);
extern void CARDi_DmaReadPageCallback(void);

void func_02077008(CARDTransferInfo *info)
{
    u32 bak_psr = OS_DisableInterrupts();

    cardi_rom_base.transfer_info = info;
    OS_SetIrqFunction(0x80000, CARDi_DmaReadPageCallback);
    (void)OS_ResetRequestIrqMask(0x80000);
    (void)OS_EnableIrqMask(0x80000);
    (void)OS_RestoreInterrupts(bak_psr);
    {
        CARDiCommon *const p = &cardi_common;

        (*p->DmaCall->Recv)(p->dma, (const void *)0x04100010, (void *)info->dst, 0x200);
    }
    CARDi_StartRomPageTransfer(info->src);
}
