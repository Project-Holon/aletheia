/*
 * file:     card_common_3.c
 * unit:     yes
 * function: func_02076050, func_02076070, func_0207608C, func_020760B4
 * address:  0x02076050
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02150200    0x02150200  data
 *   func_02076230 0x02076230  arm
 *   cardi_common  0x02150200  data
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   DC_FlushRange  0x020862F0  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   cardi_arg  0x021501A0  data
 *   CARDi_OnFifoRecv  0x020763BC  arm
 */
struct CARDiCommon;
typedef unsigned long u32;

typedef unsigned char u8;

typedef unsigned short u16;

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

extern int func_02076230(struct CARDiCommon *p, int restart, void (*callback)(void *), void *callback_arg);
extern void MIi_CpuClearFast(u32 data, void *destp, u32 size);
extern void DC_FlushRange(void *startAddr, u32 nBytes);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int, u32, BOOL));
extern void CARDi_OnFifoRecv(int tag, u32 data, BOOL err);
void func_02076050(void);
int func_02076070(void);
void func_0207608C(void);
void func_020760B4(void);
extern u32 g_02150200;
extern CARDiCommon cardi_common;
extern CARDiCommandArg cardi_arg;



void func_02076050(void) { func_02076230((struct CARDiCommon *)((u32)&g_02150200), 0, 0, 0); }




/*
 * Unlabelled leaf: disasm.py only labels a prologue that saves lr, and this
 * one saves nothing, so it never appears in the worklist.  It sits inside
 * pkt_02075FCC's range (0x02075FCC..0x0207608C) after the 0x02075FCC extent
 * and its pool.  It is the sole caller-side witness for CARD_TryWaitBackupAsync's
 * one-word veneer, so filing it and then re-running that wrapper is the
 * bottom-up promotion for this pair.
 */
int func_02076070(void)
{
    return (*(u32 *)((char *)&g_02150200 + 4) & 4) ? 0 : 1;
}



static inline void OS_InitThreadQueue(OSThreadQueue *queue)
{
    queue->head = queue->tail = (OSThread *)0;
}



/*
 * sdk:      CARDi_InitResourceLock (libcard.TWL.HYB.a card_common.o)
 */
void func_0207608C(void)
{
    CARDiCommon *p = (CARDiCommon *)&cardi_common;

    p->lock_owner = -3;
    p->lock_ref = 0;
    p->lock_target = CARD_TARGET_NONE;
    OS_InitThreadQueue(p->lock_queue);
}


/*
 * sdk:      CARDi_InitCommand (libcard.TWL.HYB.a card_common.o)
 */
void func_020760B4(void)
{
    CARDiCommon *p = &cardi_common;

    p->cmd = &cardi_arg;
    MIi_CpuClearFast(0, &cardi_arg, sizeof(cardi_arg));
    DC_FlushRange(&cardi_arg, sizeof(cardi_arg));
    PXI_SetFifoRecvCallback(11, CARDi_OnFifoRecv);
}
