/*
 * function: DWC_NdCancelAsync
 * address:  0x021C5DB4
 * packet:   pkt_ov114_021C5DB4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_NdCancelAsync (libdwcnd.TWL.HYB.a dwc_nd.o)
 *
 * symbols:
 *   func_02059F38  0x02059F38  arm
 *   func_02086028  0x02086028  arm
 *   OS_UnlockMutex 0x02086078  arm
 *   DWCi_NdCancelAsync  0x021C666C  arm  ov114
 *   gDwcNdMutex     0x021D3B84  data
 *   gDwcNdState     0x021D3B68  data
 */

#include "../include/G_NdState.h"

typedef struct NdState NdState;

extern int func_02059F38(void);
extern void func_02086028(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern int DWCi_NdCancelAsync(void);
extern char gDwcNdMutex[];
extern struct NdState gDwcNdState;

int DWC_NdCancelAsync(void)
{
    if (func_02059F38())
        return 0;
    func_02086028(gDwcNdMutex);
    if (gDwcNdState.f14 != 2) {
        OS_UnlockMutex(gDwcNdMutex);
        return 0;
    }
    OS_UnlockMutex(gDwcNdMutex);
    return DWCi_NdCancelAsync() != 0;
}
