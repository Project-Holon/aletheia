/*
 * function: DWC_NdProcess
 * address:  0x021C5AB8
 * packet:   pkt_ov114_021C5AB8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_NdProcess (libdwcnd.TWL.HYB.a dwc_nd.o)
 *
 * symbols:
 *   OS_LockMutex  0x02086028  arm
 *   OS_UnlockMutex 0x02086078  arm
 *   gDwcNdMutex     0x021D3B84  data
 *   gDwcNdState     0x021D3B68  data
 */

#include "../include/G_NdState.h"

typedef struct NdState NdState;

extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern char gDwcNdMutex[];
extern struct NdState gDwcNdState;

void DWC_NdProcess(void)
{
    int needCallback = 0;
    int needCleanUpCallback = 0;
    int reason;

    OS_LockMutex(gDwcNdMutex);
    reason = gDwcNdState.f10;
    if (reason == 0 && gDwcNdState.f14 == 4) {
        if (gDwcNdState.f4 == 0) {
            needCallback = 1;
            gDwcNdState.f4 = 1;
        }
    } else if ((unsigned int)(gDwcNdState.f14 - 3) <= 1) {
        needCallback = 1;
        gDwcNdState.f14 = 1;
    }
    if (reason == 4) {
        gDwcNdState.f14 = 0;
        gDwcNdState.f10 = 0;
        needCleanUpCallback = 1;
    }
    OS_UnlockMutex(gDwcNdMutex);
    if (gDwcNdState.cb == 0)
        return;
    if (needCleanUpCallback) {
        gDwcNdState.cb(4, 0, -1);
    } else if (needCallback) {
        gDwcNdState.cb(gDwcNdState.f10, gDwcNdState.fC, gDwcNdState.f8);
    }
}
