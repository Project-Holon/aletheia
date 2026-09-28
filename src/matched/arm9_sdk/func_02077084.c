/*
 * function: func_02077084
 * address:  0x02077084
 * packet:   pkt_02077084
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_DmaReadDone (libcard.TWL.HYB.a card_rom.o)
 *
 * symbols:
 *   CARDi_ReadRomIDCore  0x02076CD0  arm
 *   CARDi_CheckPulledOutCore  0x02077518  arm
 *   CARDi_RefreshRom  0x02076DA0  arm
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

struct CARDiCommandArg
{
    int result;
};

extern u32 CARDi_ReadRomIDCore(void);
extern void CARDi_CheckPulledOutCore(u32 id);
extern void CARDi_RefreshRom(u32 warn_mask);
extern void CARDi_EndTask(CARDiCommon *p);

void func_02077084(void)
{
    CARDi_CheckPulledOutCore(CARDi_ReadRomIDCore());
    CARDi_RefreshRom(8);
    cardi_common.cmd->result = 0;
    CARDi_EndTask(&cardi_common);
}
