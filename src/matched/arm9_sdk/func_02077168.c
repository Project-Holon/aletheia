/*
 * function: func_02077168
 * address:  0x02077168
 * packet:   pkt_02077168
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_ReadRomSyncCore (libcard.TWL.HYB.a card_rom.o)
 *
 * symbols:
 *   CARDi_ReadRomIDCore  0x02076CD0  arm
 *   CARDi_CheckPulledOutCore  0x02077518  arm
 *   CARDi_RefreshRom  0x02076DA0  arm
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

typedef struct CARDiRomState
{
    u32 rom_base;
    int (*read_func)(void *userdata, void *buffer, u32 offset, u32 length);
} CARDiRomState;

extern CARDiRomState cardi_rom_base;

extern u32 CARDi_ReadRomIDCore(void);
extern void CARDi_CheckPulledOutCore(u32 id);
extern void CARDi_RefreshRom(u32 warn_mask);

void func_02077168(CARDiCommon *c)
{
    (void)(*cardi_rom_base.read_func)(0, (void *)c->dst, c->src, c->len);
    CARDi_CheckPulledOutCore(CARDi_ReadRomIDCore());
    CARDi_RefreshRom(8);
    cardi_common.cmd->result = 0;
}
