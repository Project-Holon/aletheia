/*
 * function: CARDi_RequestStreamCommand
 * address:  0x02076AC0
 * packet:   pkt_02076AC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_RequestStreamCommand (libcard.TWL.HYB.a card_backup.o)
 *
 * symbols:
 *   CARDi_BeginBackupCommand  0x02076A70  arm
 *   CARDi_ExecuteOldTypeTask  0x02076170  arm
 *   cardi_common  0x02150200  data
 *   CARDi_RequestStreamCommandCore  0x02076540  arm
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

extern void CARDi_BeginBackupCommand(u32 level, void (*callback)(void *), void *arg);
extern BOOL CARDi_ExecuteOldTypeTask(void (*task)(CARDiCommon *), BOOL async);
extern void CARDi_RequestStreamCommandCore(CARDiCommon *p);

BOOL CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, void (*callback)(void *), void *arg, BOOL is_async,
                   int req_type, int req_retry, int req_mode)
{
    CARDiCommon *p;

    CARDi_BeginBackupCommand((req_mode == 0) ? 1 : 2, callback, arg);
    p = &cardi_common;
    p->src = src;
    p->dst = dst;
    p->len = len;
    p->req_type = req_type;
    p->req_retry = req_retry;
    p->req_mode = req_mode;
    return CARDi_ExecuteOldTypeTask(CARDi_RequestStreamCommandCore, is_async);
}
