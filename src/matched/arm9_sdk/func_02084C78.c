/*
 * function: func_02084C78
 * address:  0x02084C78
 * packet:   pkt_02084C78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      OSi_DoUnlockByWord (os_spinlock.o)
 *
 * symbols:
 *   OS_DisableInterrupts            0x02087988  arm
 *   OS_RestoreInterrupts            0x0208799C  arm
 *   OS_DisableInterrupts_IrqAndFiq  0x020879B4  arm
 *   OS_RestoreInterrupts_IrqAndFiq  0x020879C8  arm
 */

typedef unsigned long u32;
typedef long s32;
typedef unsigned short u16;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef struct OSLockWord {
    volatile u32 lockFlag;
    volatile u16 ownerID;
    volatile u16 extension;
} OSLockWord;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern OSIntrMode OS_DisableInterrupts_IrqAndFiq(void);
extern OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state);

s32 func_02084C78(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ)
{
    OSIntrMode enabled;

    if (lockID != lockp->ownerID) {
        return -2;
    }

    if (disableFIQ) {
        enabled = OS_DisableInterrupts_IrqAndFiq();
    } else {
        enabled = OS_DisableInterrupts();
    }

    lockp->ownerID = 0;
    if (ctrlFuncp) {
        ctrlFuncp();
    }
    lockp->lockFlag = 0;

    if (disableFIQ) {
        (void)OS_RestoreInterrupts_IrqAndFiq(enabled);
    } else {
        (void)OS_RestoreInterrupts(enabled);
    }
    return 0;
}
