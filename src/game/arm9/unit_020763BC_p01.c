/*
 * file:     unit_020763BC_p01.c
 * unit:     yes
 * function: func_02076A20, func_02076A70, func_02076AC0, func_02076B2C, func_02076B6C
 * address:  0x02076A20
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
 *   CARDi_Request  0x020763F0  arm
 *   CARDi_backup_cache_page_buf  0x02150740  data
 *   OSi_ReferSymbol  0x02004EB0  arm
 *   CARD_CheckEnabled  0x02075DB0  arm
 *   CARDi_GetAccessLevel  0x02075FCC  arm
 *   OS_Terminate  0x02088234  arm
 *   CARDi_WaitForTask  0x02076230  arm
 *   cardi_backup_assert  0x02005094  data
 *   cardi_common  0x02150200  data
 *   CARDi_BeginBackupCommand  0x02076A70  arm
 *   CARDi_ExecuteOldTypeTask  0x02076170  arm
 *   CARDi_RequestStreamCommandCore  0x02076540  arm
 *   CARDi_IdentifyBackupCore2  0x020766D8  arm
 *   CARDi_IdentifyBackupCore  0x02076A20  arm
 *   g_02150200 0x02150200 data
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

typedef struct CARDiCommandArg_02076A20
{
    int result;
    u32 type;
    u32 total_size;
    u32 src;
    u32 dst;
    u32 len;
} CARDiCommandArg_02076A20;

typedef struct CARDDmaInterface CARDDmaInterface;

typedef struct CARDiCommon
{
    CARDiCommandArg_02076A20 *cmd;
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

typedef struct CARDiCommandArg_02076A70 CARDiCommandArg_02076A70;

typedef struct CARDiCommandArg_02076AC0 CARDiCommandArg_02076AC0;

typedef struct CARDiCommon CARDiCommon;

extern BOOL CARDi_Request(CARDiCommon *p, int req_type, int retry_count);
extern void OSi_ReferSymbol(const void *symbol);
extern void CARD_CheckEnabled(void);
extern u32 CARDi_GetAccessLevel(void);
extern void OS_Terminate(void);
extern BOOL CARDi_WaitForTask(CARDiCommon *p, BOOL restart, void (*callback)(void *), void *callback_arg);
extern void CARDi_BeginBackupCommand(u32 level, void (*callback)(void *), void *arg);
extern BOOL CARDi_ExecuteOldTypeTask(void (*task)(CARDiCommon *), BOOL async);
extern void CARDi_RequestStreamCommandCore(CARDiCommon *p);
extern void CARDi_IdentifyBackupCore2(int type);
extern void CARDi_IdentifyBackupCore(CARDiCommon *p);
extern void g_02150200(void);
void func_02076A20(CARDiCommon *p);
void func_02076A70(u32 level, void (*callback)(void *), void *arg);
BOOL func_02076AC0(u32 src, u32 dst, u32 len, void (*callback)(void *), void *arg, BOOL is_async, int req_type, int req_retry, int req_mode);
BOOL func_02076B2C(int type);
asm void CARD_GetBackupSectorSize(void);
extern u8 CARDi_backup_cache_page_buf[256];
extern CARDiCommon cardi_common;
extern const char cardi_backup_assert[22];


/*
 * sdk:      CARDi_IdentifyBackupCore (libcard.TWL.HYB.a card_backup.o)
 */
void func_02076A20(CARDiCommon *p)
{
    (void)CARDi_Request(p, 2, 1);
    p->cmd->src = 0;
    p->cmd->dst = (u32)CARDi_backup_cache_page_buf;
    p->cmd->len = 1;
    (void)CARDi_Request(p, 6, 1);
}


/*
 * sdk:      CARDi_BeginBackupCommand (libcard.TWL.HYB.a card_backup.o)
 */
void func_02076A70(u32 level, void (*callback)(void *), void *arg)
{
    OSi_ReferSymbol(cardi_backup_assert);
    CARD_CheckEnabled();
    if ((level & CARDi_GetAccessLevel()) != level)
    {
        OS_Terminate();
    }
    (void)CARDi_WaitForTask(&cardi_common, 1, callback, arg);
}


/*
 * sdk:      CARDi_RequestStreamCommand (libcard.TWL.HYB.a card_backup.o)
 */
BOOL func_02076AC0(u32 src, u32 dst, u32 len, void (*callback)(void *), void *arg, BOOL is_async,
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


/*
 * sdk:      CARD_IdentifyBackup (libcard.TWL.HYB.a card_backup.o)
 */
BOOL func_02076B2C(int type)
{
    if (type == 0)
    {
        OS_Terminate();
    }
    CARDi_BeginBackupCommand(0, 0, 0);
    CARDi_IdentifyBackupCore2(type);
    return CARDi_ExecuteOldTypeTask(CARDi_IdentifyBackupCore, 0);
}


asm void CARD_GetBackupSectorSize(void)
{
    ldr r0, =g_02150200
    ldr	r0, [r0]
    ldr	r0, [r0, #0x1c]
    bx	lr
}
