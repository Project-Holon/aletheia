/*
 * function: CARDi_BeginBackupCommand
 * address:  0x02076A70
 * packet:   pkt_02076A70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_BeginBackupCommand (libcard.TWL.HYB.a card_backup.o)
 *
 * symbols:
 *   OSi_ReferSymbol  0x02004EB0  arm
 *   CARD_CheckEnabled  0x02075DB0  arm
 *   CARDi_GetAccessLevel  0x02075FCC  arm
 *   OS_Terminate  0x02088234  arm
 *   CARDi_WaitForTask  0x02076230  arm
 *   cardi_backup_assert  0x02005094  data
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

extern const char cardi_backup_assert[22];

extern void OSi_ReferSymbol(const void *symbol);
extern void CARD_CheckEnabled(void);
extern u32 CARDi_GetAccessLevel(void);
extern void OS_Terminate(void);
extern BOOL CARDi_WaitForTask(CARDiCommon *p, BOOL restart, void (*callback)(void *), void *callback_arg);

void CARDi_BeginBackupCommand(u32 level, void (*callback)(void *), void *arg)
{
    OSi_ReferSymbol(cardi_backup_assert);
    CARD_CheckEnabled();
    if ((level & CARDi_GetAccessLevel()) != level)
    {
        OS_Terminate();
    }
    (void)CARDi_WaitForTask(&cardi_common, 1, callback, arg);
}
