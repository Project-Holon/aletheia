/*
 * function: func_02087EDC
 * address:  0x02087EDC
 * packet:   pkt_02087EDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_UnlockVram (os_vramexclusive.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OsCountZeroBits       0x02087EA0  arm
 *   OSi_vramExclusive     0x0215136C  data
 *   OSi_vramLockId        0x02151370  data
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef int BOOL;
typedef u32 OSIntrMode;

extern char SDK_AUTOLOAD_DTCM_START[];

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

typedef long s32;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern u32 OsCountZeroBits(u32 bitmap);
extern u32 OSi_vramExclusive;
extern u16 OSi_vramLockId[9];

void func_02087EDC(u16 bank, u16 lockId)
{
    u32 workMap;
    s32 zeroBits;
    OSIntrMode enabled = OS_DisableInterrupts();

    workMap = (u32)(bank & OSi_vramExclusive) & 0x1FF;

    while (1) {
        zeroBits = (s32)(31 - OsCountZeroBits(workMap));
        if (zeroBits < 0) {
            break;
        }
        workMap &= ~(1 << zeroBits);
        if (OSi_vramLockId[zeroBits] == lockId) {
            OSi_vramLockId[zeroBits] = 0;
            OSi_vramExclusive &= ~(1 << zeroBits);
        }
    }

    (void)OS_RestoreInterrupts(enabled);
}
