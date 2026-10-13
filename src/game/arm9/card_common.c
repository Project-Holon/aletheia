/*
 * file:     card_common.c
 * unit:     yes
 * function: func_02075ED4, func_02075F4C, CARDi_GetAccessLevel, func_02076050, func_02076070, func_0207608C, func_020760B4
 * address:  0x02075ED4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * A permission mask built from the TWL ROM header.  func_02075E04 returns the
 * header buffer (its pool word is 0x02FFE000), and the four one-bit extracts
 * of the word at +0x1B4 are its access-control flags, read as u32 bitfields
 * (bits 5, 8, 15, 16).  A ROM boot (OS_GetBootType() == 1) or a non-TWL run
 * grants everything (7).  Otherwise bit 8 grants 4 and enables the other two
 * checks, bit 5 only enables them, and bits 15/16 grant 1/2.  Byte-exact under
 * both 1.1p1 and ../2.0/sp2 on the first compile; EXACT* because the follower
 * 0x02076050 (already filed) carries no label.
 * Verified with:
 *   python3 tools/match.py one --src src/matched/CARDi_GetAccessLevel.c \
 *       --func CARDi_GetAccessLevel --addr 0x02075FCC --arm --cc 1.1p1
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_Terminate  0x02088234  arm
 *   OS_SleepThread  0x020857B0  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   cardi_common  0x02150200  data
 *   OS_WakeupThread  0x02085800  arm
 *   OS_GetBootType  0x02087B04  arm
 *   OS_IsRunOnTwl   0x02085D3C  arm
 *   func_02075E04   0x02075E04  arm
 *   g_02150200    0x02150200  data
 *   func_02076230 0x02076230  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   DC_FlushRange  0x020862F0  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   cardi_arg  0x021501A0  data
 *   CARDi_OnFifoRecv  0x020763BC  arm
 */
struct CARDiCommon;
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

typedef unsigned int u32;

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
    CARDTarget lock_target;
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

typedef struct {
    u32 keyAndSlotAccess    : 5;
    u32 gameCardPowerOn     : 1;
    u32 sharedFileAccess    : 2;
    u32 gameCardNitroMode   : 1;
    u32 sdAndPhotoAccess    : 6;
    u32 backupAccess        : 1;
    u32 romAccess           : 1;
    u32 reserved            : 15;
} TwlAccessControl;

typedef struct { u8 pad00[0x1b4]; TwlAccessControl access; } TwlRomHeader;

extern u32 OS_DisableInterrupts(void);
extern void OS_Terminate(void);
extern void OS_SleepThread(OSThreadQueue *queue);
extern u32 OS_RestoreInterrupts(u32 state);
extern void OS_WakeupThread(OSThreadQueue *queue);
extern int OS_GetBootType(void);
extern BOOL OS_IsRunOnTwl(void);
extern TwlRomHeader *func_02075E04(void);
extern int func_02076230(struct CARDiCommon *p, int restart, void (*callback)(void *), void *callback_arg);
extern void MIi_CpuClearFast(u32 data, void *destp, u32 size);
extern void DC_FlushRange(void *startAddr, u32 nBytes);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int, u32, BOOL));
extern void CARDi_OnFifoRecv(int tag, u32 data, BOOL err);
void func_02075ED4(s32 owner, CARDTarget target);
void func_02075F4C(s32 owner, CARDTarget target);
u32 CARDi_GetAccessLevel(void);
void func_02076050(void);
int func_02076070(void);
void func_0207608C(void);
void func_020760B4(void);
extern CARDiCommon cardi_common;
extern u32 g_02150200;
extern CARDiCommandArg cardi_arg;



/*
 * sdk:      CARDi_LockResource (libcard.TWL.HYB.a card_common.o)
 */
void func_02075ED4(s32 owner, CARDTarget target)
{
    CARDiCommon *const p = &cardi_common;
    u32 bak_psr = OS_DisableInterrupts();

    if (p->lock_owner == owner)
    {
        if (p->lock_target != target)
        {
            OS_Terminate();
        }
    }
    else
    {
        while ((p->lock_owner != -3) ? 1 : 0)
        {
            OS_SleepThread(p->lock_queue);
        }
        p->lock_owner = owner;
        p->lock_target = target;
    }
    ++p->lock_ref;
    (void)OS_RestoreInterrupts(bak_psr);
}



/*
 * sdk:      CARDi_UnlockResource (libcard.TWL.HYB.a card_common.o)
 */
void func_02075F4C(s32 owner, CARDTarget target)
{
    CARDiCommon *const p = &cardi_common;
    u32 bak_psr = OS_DisableInterrupts();

    if ((p->lock_owner != owner) || !p->lock_ref)
    {
        OS_Terminate();
    }
    else
    {
        if (p->lock_target != target)
        {
            OS_Terminate();
        }
        if (--p->lock_ref == 0)
        {
            p->lock_owner = -3;
            p->lock_target = CARD_TARGET_NONE;
            OS_WakeupThread(p->lock_queue);
        }
    }
    (void)OS_RestoreInterrupts(bak_psr);
}

u32 CARDi_GetAccessLevel(void)
{
    u32 accessLevel = 0;
    TwlRomHeader *romHeader;
    BOOL accessGranted;
    if (OS_GetBootType() == 1) {
        accessLevel = 7;
    } else if (!OS_IsRunOnTwl()) {
        accessLevel = 7;
    } else {
        romHeader = func_02075E04();
        accessGranted = 0;
        if (romHeader->access.gameCardNitroMode) {
            accessLevel |= 4;
            accessGranted = 1;
        } else if (romHeader->access.gameCardPowerOn) {
            accessGranted = 1;
        }
        if (accessGranted) {
            if (romHeader->access.backupAccess) accessLevel |= 1;
            if (romHeader->access.romAccess) accessLevel |= 2;
        }
    }
    return accessLevel;
}




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
