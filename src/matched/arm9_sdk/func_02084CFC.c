/*
 * function: func_02084CFC
 * address:  0x02084CFC
 * packet:   pkt_02084CFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      OSi_DoTryLockByWord (os_spinlock.o)
 *
 * symbols:
 *   OS_DisableInterrupts            0x02087988  arm
 *   OS_RestoreInterrupts            0x0208799C  arm
 *   OS_DisableInterrupts_IrqAndFiq  0x020879B4  arm
 *   OS_RestoreInterrupts_IrqAndFiq  0x020879C8  arm
 *   MI_SwapWord                     0x020834B8  arm
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

extern u32 MI_SwapWord(u32 setData, volatile u32 *destp);

s32 func_02084CFC(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFIQ)
{
    s32 lastLockFlag;
    OSIntrMode enabled;

    if (disableFIQ) {
        enabled = OS_DisableInterrupts_IrqAndFiq();
    } else {
        enabled = OS_DisableInterrupts();
    }

    lastLockFlag = (s32)MI_SwapWord(lockID, &lockp->lockFlag);

    if (!lastLockFlag) {
        if (ctrlFuncp) {
            ctrlFuncp();
        }
        lockp->ownerID = lockID;
    }

    if (disableFIQ) {
        (void)OS_RestoreInterrupts_IrqAndFiq(enabled);
    } else {
        (void)OS_RestoreInterrupts(enabled);
    }
    return lastLockFlag;
}
