/*
 * function: func_021C58C8
 * address:  0x021C58C8
 * packet:   pkt_ov114_021C58C8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NdCallback (libdwcnd.TWL.HYB.a dwc_nd.o)
 *
 * symbols:
 *   DWCi_NdSetError  0x021C659C  arm  ov114
 *   func_02086028  0x02086028  arm
 *   OS_UnlockMutex 0x02086078  arm
 *   gDwcNdMutex     0x021D3B84  data
 *   gDwcNdState     0x021D3B68  data
 */

#include "../include/G_NdState.h"

typedef struct NdState NdState;

extern void DWCi_NdSetError(int err, int servererror);
extern void func_02086028(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern char gDwcNdMutex[];
extern struct NdState gDwcNdState;

void func_021C58C8(int reason, int error, int servererror)
{
    if (error != 0)
        DWCi_NdSetError(error, servererror);
    func_02086028(gDwcNdMutex);
    gDwcNdState.f14 = 3;
    gDwcNdState.f10 = reason;
    gDwcNdState.fC = error;
    gDwcNdState.f8 = servererror;
    if (error != 0)
        gDwcNdState.f14 = 4;
    OS_UnlockMutex(gDwcNdMutex);
}
