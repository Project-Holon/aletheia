/*
 * function: DWC_NdGetProgress
 * address:  0x021C5E14
 * packet:   pkt_ov114_021C5E14
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_NdGetProgress (libdwcnd.TWL.HYB.a dwc_nd.o)
 *
 * symbols:
 *   DWCi_IsError  0x02059F38  arm
 *   OS_LockMutex  0x02086028  arm
 *   OS_UnlockMutex 0x02086078  arm
 *   DWCi_NdGetProgress  0x021C757C  arm  ov114
 *   gDwcNdMutex     0x021D3B84  data
 *   gDwcNdState     0x021D3B68  data
 */

#include "../include/G_NdState.h"

typedef struct NdState NdState;

extern int DWCi_IsError(void);
extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern int DWCi_NdGetProgress(unsigned long *received, unsigned long *contentlen);
extern char gDwcNdMutex[];
extern struct NdState gDwcNdState;

int DWC_NdGetProgress(unsigned long *received, unsigned long *contentlen)
{
    if (DWCi_IsError())
        return 0;
    OS_LockMutex(gDwcNdMutex);
    if (gDwcNdState.f14 != 2) {
        OS_UnlockMutex(gDwcNdMutex);
        return 0;
    }
    OS_UnlockMutex(gDwcNdMutex);
    return DWCi_NdGetProgress(received, contentlen);
}
