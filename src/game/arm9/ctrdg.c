/*
 * file:     ctrdg.c
 * unit:     yes
 * function: CTRDG_IsExistedAtInit, CTRDGi_InitCommon, CTRDG_IsExisting, CTRDGi_ChangeLatestAccessCycle, CTRDGi_RestoreAccessCycle, CTRDGi_LockByProcessor, CTRDGi_UnlockByProcessor, CTRDGi_SendtoPxi
 * address:  0x02090EF4
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
 *   g_02153B80     0x02153B80  data
 *   SVC_CpuSet  0x0200421A  thumb
 *   OS_GetLockID  0x02084EB8  arm
 *   CTRDGi_LockByProcessor         0x020910D0  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_ReadOwnerOfLockWord  0x02084EB0  arm
 *   OS_TryLockCartridge  0x02084DA4  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   SVC_WaitByLoop  0x02004490  thumb
 *   OS_UnLockCartridge             0x02084D98  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   PXI_SendWordByFifo  0x02088610  arm
 */
#include "../types.h"

#include "../sdk_os.h"

typedef struct CTRDGLockByProc {
    BOOL locked;
    OSIntrMode irq;
} CTRDGLockByProc;

typedef struct CTRDGModuleInfo {
    u16 moduleID;
    u8 exLsiID[3];
    u8 isAgbCartridge:1;
    u8 detectPullOut:1;
    u8 :0;
    u16 makerCode;
    u32 gameCode;
} CTRDGModuleInfo;

typedef struct CTRDGHeader {
    u8 titleArea[0xAC];
    u32 gameCode;
    u16 makerCode;
    u8 fixed;
    u8 reservedArea[0xB];
    u16 moduleID;
} CTRDGHeader;

/* ctrdg.o .bss: CTRDGi_EnableFlag at +0, CTRDGi_Work (lockID at +2) at +4 */
typedef struct CtrdgBss {
    BOOL enableFlag;
    u16 subpInit;
    u16 lockID;
} CtrdgBss;

typedef enum { MI_CTRDG_ROMCYCLE1_10 = 0, MI_CTRDG_ROMCYCLE1_8 = 1, MI_CTRDG_ROMCYCLE1_6 = 2, MI_CTRDG_ROMCYCLE1_18 = 3 } MICartridgeRomCycle1st;

typedef enum { MI_CTRDG_ROMCYCLE2_6 = 0, MI_CTRDG_ROMCYCLE2_4 = 1 } MICartridgeRomCycle2nd;

typedef struct CTRDGRomCycle {
    MICartridgeRomCycle1st c1;
    MICartridgeRomCycle2nd c2;
} CTRDGRomCycle;

#include "svc_cpu_set.h"
extern u16 OS_GetLockID(void);
extern void CTRDGi_LockByProcessor(u32 lockID, u32 *info);
#include "os_system.h"
extern unsigned short OS_ReadOwnerOfLockWord(char *lock);
extern u32 OS_TryLockCartridge(u32 lockID);
#include "svc_wait_by_loop.h"
extern void OS_UnLockCartridge(u16 lockID);

#include "pxi_fifo.h"
BOOL CTRDG_IsExistedAtInit(void);
void CTRDGi_InitCommon(void);
BOOL CTRDG_IsExisting(void);
void CTRDGi_ChangeLatestAccessCycle(CTRDGRomCycle *r);
void CTRDGi_RestoreAccessCycle(CTRDGRomCycle *r);
void CTRDGi_UnlockByProcessor(u16 lockID, CTRDGLockByProc *info);
void CTRDGi_SendtoPxi(u32 data);
extern CtrdgBss g_02153B80;

BOOL CTRDG_IsExistedAtInit(void)
{
    return ((CTRDGModuleInfo *)0x02FFFC30)->moduleID != 0xFFFF;
}

void CTRDGi_InitCommon(void)
{
    u32 tmp = 0;

    SVC_CpuSet(&tmp, &g_02153B80.subpInit, 0x05000001);
    g_02153B80.lockID = OS_GetLockID();
}

#define CTRDGi_ROM   ((CTRDGHeader *)0x08000000)

#define CTRDGi_INFO  ((CTRDGModuleInfo *)0x02FFFC30)

#define CTRDGi_AGB_MODULE_ID (*(u16 *)0x0801FFFE)

BOOL CTRDG_IsExisting(void)
{
    BOOL retval = 1;
    CTRDGLockByProc lockInfo;
    CTRDGRomCycle rc;
    u8 isRomCode;
    CTRDGHeader *chp = CTRDGi_ROM;
    CTRDGModuleInfo *cip = CTRDGi_INFO;

    if (!CTRDG_IsExistedAtInit()) {
        return 0;
    }
    if (cip->detectPullOut == 1) {
        return 0;
    }

    CTRDGi_LockByProcessor(g_02153B80.lockID, (u32 *)&lockInfo);
    CTRDGi_ChangeLatestAccessCycle(&rc);

    isRomCode = chp->fixed;

    if ((isRomCode == 0x96 && cip->moduleID != chp->moduleID)
        || (isRomCode != 0x96 && cip->moduleID != CTRDGi_AGB_MODULE_ID)
        || (cip->gameCode != chp->gameCode && cip->isAgbCartridge)) {
        cip->detectPullOut = 1;
        retval = 0;
    }

    CTRDGi_RestoreAccessCycle(&rc);
    CTRDGi_UnlockByProcessor(g_02153B80.lockID, &lockInfo);
    return retval;
}

#define reg_MI_EXMEMCNT (*(vu16 *)0x04000204)

static inline void MI_SetCartridgeRomCycle1st(MICartridgeRomCycle1st c1)
{
    reg_MI_EXMEMCNT = (u16)((reg_MI_EXMEMCNT & ~0xC) | (c1 << 2));
}

static inline void MI_SetCartridgeRomCycle2nd(MICartridgeRomCycle2nd c2)
{
    reg_MI_EXMEMCNT = (u16)((reg_MI_EXMEMCNT & ~0x10) | (c2 << 4));
}

void CTRDGi_ChangeLatestAccessCycle(CTRDGRomCycle *r)
{
    r->c1 = (MICartridgeRomCycle1st)((reg_MI_EXMEMCNT & 0xC) >> 2);
    r->c2 = (MICartridgeRomCycle2nd)((reg_MI_EXMEMCNT & 0x10) >> 4);
    MI_SetCartridgeRomCycle1st(MI_CTRDG_ROMCYCLE1_18);
    MI_SetCartridgeRomCycle2nd(MI_CTRDG_ROMCYCLE2_6);
}

void CTRDGi_RestoreAccessCycle(CTRDGRomCycle *r)
{
    MI_SetCartridgeRomCycle1st(r->c1);
    MI_SetCartridgeRomCycle2nd(r->c2);
}

/*
 *           callee OS_TryLockCartridge (the only branch to it in the whole image
 *           is the one inside this file) has no witness outside
 *           020910D0..0209112C, so that one call site stays wildcarded.
 *           The C is byte-correct at every other offset: the file becomes
 *           EXACT with no edit once 0x02084DA4 has a shard entry of its
 *           own (it is a 0x02084xxx packet, outside this window).
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 */
void CTRDGi_LockByProcessor(u32 lockID, u32 *lockInfo)
{
    u32 owner;

    while (1) {
        lockInfo[1] = OS_DisableInterrupts();
        owner = OS_ReadOwnerOfLockWord((void *)0x02FFFFE8) & 0x40;
        lockInfo[0] = owner;
        if (owner != 0)
            return;
        if (OS_TryLockCartridge(lockID) == 0)
            return;
        OS_RestoreInterrupts(lockInfo[1]);
        SVC_WaitByLoop(1);
    }
}

void CTRDGi_UnlockByProcessor(u16 lockID, CTRDGLockByProc *info)
{
    if (!info->locked) {
        OS_UnLockCartridge(lockID);
    }
    (void)OS_RestoreInterrupts(info->irq);
}

void CTRDGi_SendtoPxi(u32 data)
{
    if (PXI_SendWordByFifo(0xd, data, 0) == 0)
        return;

    do {
        SVC_WaitByLoop(1);
    } while (PXI_SendWordByFifo(0xd, data, 0) != 0);
}
