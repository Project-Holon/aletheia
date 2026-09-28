/*
 * function: CTRDGi_UnlockByProcessor
 * address:  0x0209112C
 * packet:   pkt_0209112C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libctrdg ctrdg.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   OS_UnLockCartridge             0x02084D98  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef struct CTRDGLockByProc {
    BOOL locked;
    OSIntrMode irq;
} CTRDGLockByProc;

extern void OS_UnLockCartridge(u16 lockID);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);

void CTRDGi_UnlockByProcessor(u16 lockID, CTRDGLockByProc *info)
{
    if (!info->locked) {
        OS_UnLockCartridge(lockID);
    }
    (void)OS_RestoreInterrupts(info->irq);
}
