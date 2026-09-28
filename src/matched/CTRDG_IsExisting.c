/*
 * function: CTRDG_IsExisting
 * address:  0x02090F50
 * packet:   pkt_02090F50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libctrdg ctrdg.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  The
 * module-info pointer is one local held in r5 for every access; ctrdg.o
 * .bss (CTRDGi_EnableFlag at +0, CTRDGi_Work at +4) is one pool word.
 *
 * symbols:
 *   g_02153B80                     0x02153B80  data
 *   CTRDG_IsExistedAtInit          0x02090EF4  arm
 *   CTRDGi_LockByProcessor         0x020910D0  arm
 *   CTRDGi_ChangeLatestAccessCycle 0x02091054  arm
 *   CTRDGi_RestoreAccessCycle      0x0209109C  arm
 *   CTRDGi_UnlockByProcessor       0x0209112C  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef struct CTRDGRomCycle {
    int c1;
    int c2;
} CTRDGRomCycle;

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
    u8 pad0[0xAC];
    u32 gameCode;
    u16 makerCode;
    u8 fixed;
    u8 pad1[0xB];
    u16 moduleID;
} CTRDGHeader;

/* ctrdg.o .bss: CTRDGi_EnableFlag at +0, CTRDGi_Work (lockID at +2) at +4 */
typedef struct CtrdgBss {
    BOOL enableFlag;
    u16 subpInit;
    u16 lockID;
} CtrdgBss;

extern CtrdgBss g_02153B80;

#define CTRDGi_ROM   ((CTRDGHeader *)0x08000000)
#define CTRDGi_INFO  ((CTRDGModuleInfo *)0x02FFFC30)
#define CTRDGi_AGB_MODULE_ID (*(u16 *)0x0801FFFE)

extern BOOL CTRDG_IsExistedAtInit(void);
extern void CTRDGi_LockByProcessor(u16 lockID, CTRDGLockByProc *info);
extern void CTRDGi_ChangeLatestAccessCycle(CTRDGRomCycle *r);
extern void CTRDGi_RestoreAccessCycle(CTRDGRomCycle *r);
extern void CTRDGi_UnlockByProcessor(u16 lockID, CTRDGLockByProc *info);

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

    CTRDGi_LockByProcessor(g_02153B80.lockID, &lockInfo);
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
