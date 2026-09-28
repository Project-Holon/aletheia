/*
 * function: func_02076A20
 * address:  0x02076A20
 * packet:   pkt_02076A20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_IdentifyBackupCore (libcard.TWL.HYB.a card_backup.o)
 *
 * symbols:
 *   CARDi_Request  0x020763F0  arm
 *   CARDi_backup_cache_page_buf  0x02150740  data
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
    u32 type;
    u32 total_size;
    u32 src;
    u32 dst;
    u32 len;
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


extern u8 CARDi_backup_cache_page_buf[256];
extern BOOL CARDi_Request(CARDiCommon *p, int req_type, int retry_count);

void func_02076A20(CARDiCommon *p)
{
    (void)CARDi_Request(p, 2, 1);
    p->cmd->src = 0;
    p->cmd->dst = (u32)CARDi_backup_cache_page_buf;
    p->cmd->len = 1;
    (void)CARDi_Request(p, 6, 1);
}
