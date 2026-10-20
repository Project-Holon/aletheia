/*
 * file:     os_vramexclusive.c
 * unit:     yes
 * function: OSi_InitVramExclusive, OSi_UnlockVram
 * address:  0x02087EA8
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
 *   OSi_vramExclusive  0x0215136C  data
 *   OSi_vramLockId     0x02151370  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OSi_CountLeadingZeros       0x02087EA0  arm
 */
#include "../types.h"

#include "../sdk_os.h"

#include "os_system.h"
#include "os_clz.h"
void OSi_InitVramExclusive(void);
void OSi_UnlockVram(u16 bank, u16 lockId);
extern char SDK_AUTOLOAD_DTCM_START[];
extern u32 OSi_vramExclusive;
extern u16 OSi_vramLockId[9];

/*
 * sdk:      OSi_InitVramExclusive (os_vramexclusive.o)
 */
void OSi_InitVramExclusive(void)
{
    s32 i;

    OSi_vramExclusive = 0;
    for (i = 0; i < 9; i++) {
        OSi_vramLockId[i] = 0;
    }
}

/*
 * sdk:      OSi_UnlockVram (os_vramexclusive.o)
 */
void OSi_UnlockVram(u16 bank, u16 lockId)
{
    u32 workMap;
    s32 zeroBits;
    OSIntrMode enabled = OS_DisableInterrupts();

    workMap = (u32)(bank & OSi_vramExclusive) & 0x1FF;

    while (1) {
        zeroBits = (s32)(31 - OSi_CountLeadingZeros(workMap));
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
