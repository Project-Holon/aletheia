/*
 * function: func_02076F68
 * address:  0x02076F68
 * packet:   pkt_02076F68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_DmaReadPageCallback (libcard.TWL.HYB.a card_rom.o)
 *
 * symbols:
 *   CARDi_StartRomPageTransfer  0x02076C88  arm
 *   OS_DisableIrqMask  0x02084998  arm
 *   OS_ResetRequestIrqMask  0x020849C8  arm
 *   CARDi_ReadRomIDCore  0x02076CD0  arm
 *   CARDi_CheckPulledOutCore  0x02077518  arm
 *   cardi_rom_base  0x02150840  data
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
    void (*Stop)(u32 channel);
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

extern void CARDi_StartRomPageTransfer(u32 offset);
extern u32 OS_DisableIrqMask(u32 intr);
extern u32 OS_ResetRequestIrqMask(u32 intr);
extern u32 CARDi_ReadRomIDCore(void);
extern void CARDi_CheckPulledOutCore(u32 id);

void func_02076F68(void)
{
    CARDTransferInfo *const info = cardi_rom_base.transfer_info;

    if (info)
    {
        info->src += 512;
        info->dst += 512;
        info->len -= 512;
        if (info->len != 0)
        {
            CARDi_StartRomPageTransfer(info->src);
        }
        else
        {
            (*cardi_common.DmaCall->Stop)(cardi_common.dma);
            (void)OS_DisableIrqMask(0x80000);
            (void)OS_ResetRequestIrqMask(0x80000);
            cardi_rom_base.transfer_info = 0;
            CARDi_CheckPulledOutCore(CARDi_ReadRomIDCore());
            if (info->callback)
            {
                (*info->callback)(info->userdata);
            }
        }
    }
}
