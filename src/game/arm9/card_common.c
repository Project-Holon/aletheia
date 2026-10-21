/*
 * file:     card_common.c
 * unit:     yes
 * function: CARDi_LockResource, CARDi_UnlockResource, CARDi_GetAccessLevel, CARDi_WaitAsync, CARDi_TryWaitAsync, CARDi_InitResourceLock, CARDi_InitCommand
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
 * A permission mask built from the TWL ROM header.  CARD_GetOwnRomHeaderTWL returns the
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
 *   CARD_GetOwnRomHeaderTWL   0x02075E04  arm
 *   CARDi_WaitForTask 0x02076230  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   DC_FlushRange  0x020862F0  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   cardi_arg  0x021501A0  data
 *   CARDi_OnFifoRecv  0x020763BC  arm
 */
#include "../types.h"

#include "card_common.h"

#include "../sdk_os.h"

#include "../sdk_card.h"

#include "os_system.h"
#include "os_terminate_processor.h"
#include "os_thread.h"
#include "os_systemwork.h"
#include "os_emulator.h"
#include "card_api.h"
#include "card_task.h"
#include "mi_memory.h"
#include "os_cache.h"
#include "pxi_fifo.h"
#include "card_backup.h"
void CARDi_LockResource(s32 owner, CARDTarget target);
void CARDi_UnlockResource(s32 owner, CARDTarget target);
u32 CARDi_GetAccessLevel(void);
BOOL CARDi_WaitAsync(void);
int CARDi_TryWaitAsync(void);
void CARDi_InitResourceLock(void);
void CARDi_InitCommand(void);
extern CARDiCommon cardi_common;
extern CARDiCommandArg cardi_arg;

/*
 * sdk:      CARDi_LockResource (libcard.TWL.HYB.a card_common.o)
 */
void CARDi_LockResource(s32 owner, CARDTarget target)
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
void CARDi_UnlockResource(s32 owner, CARDTarget target)
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
    const CARDRomHeaderTWL *romHeader;
    BOOL accessGranted;
    if (OS_GetBootType() == 1) {
        accessLevel = 7;
    } else if (!OS_IsRunOnTwl()) {
        accessLevel = 7;
    } else {
        romHeader = CARD_GetOwnRomHeaderTWL();
        accessGranted = 0;
        if (romHeader->access_control.gameCardNitroMode) {
            accessLevel |= 4;
            accessGranted = 1;
        } else if (romHeader->access_control.gameCardPowerOn) {
            accessGranted = 1;
        }
        if (accessGranted) {
            if (romHeader->access_control.backupAccess) accessLevel |= 1;
            if (romHeader->access_control.romAccess) accessLevel |= 2;
        }
    }
    return accessLevel;
}

BOOL CARDi_WaitAsync(void) { return CARDi_WaitForTask(&cardi_common, 0, 0, 0); }

/*
 * Unlabelled leaf: disasm.py only labels a prologue that saves lr, and this
 * one saves nothing, so it never appears in the worklist.  It sits inside
 * pkt_02075FCC's range (0x02075FCC..0x0207608C) after the 0x02075FCC extent
 * and its pool.  It is the sole caller-side witness for CARD_TryWaitBackupAsync's
 * one-word veneer, so filing it and then re-running that wrapper is the
 * bottom-up promotion for this pair.
 */
int CARDi_TryWaitAsync(void)
{
    return (cardi_common.flag & 4) ? 0 : 1;
}

static inline void OS_InitThreadQueue(OSThreadQueue *queue)
{
    queue->head = queue->tail = (OSThread *)0;
}

/*
 * sdk:      CARDi_InitResourceLock (libcard.TWL.HYB.a card_common.o)
 */
void CARDi_InitResourceLock(void)
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
void CARDi_InitCommand(void)
{
    CARDiCommon *p = &cardi_common;

    p->cmd = &cardi_arg;
    MIi_CpuClearFast(0, &cardi_arg, sizeof(cardi_arg));
    DC_FlushRange(&cardi_arg, sizeof(cardi_arg));
    PXI_SetFifoRecvCallback(11, CARDi_OnFifoRecv);
}
