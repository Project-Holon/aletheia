/*
 * function: DWC_NdCleanupAsync
 * address:  0x021C5B80
 * packet:   pkt_ov114_021C5B80
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_NdCleanupAsync (libdwcnd.TWL.HYB.a dwc_nd.o)
 *
 * symbols:
 *   func_02086028  0x02086028  arm
 *   OS_UnlockMutex 0x02086078  arm
 *   DWCi_NdCleanupCallback  0x021C56CC  arm  ov114
 *   DWCi_NdCleanupAsync  0x021C651C  arm  ov114
 *   gDwcNdState     0x021D3B68  data
 *   gDwcNdMutex     0x021D3B84  data
 */

#include "../include/G_NdState.h"

typedef struct NdParam {
    unsigned char pad0[0x40];
    int f40;
} NdParam;

typedef struct NdState NdState;

extern void func_02086028(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern void DWCi_NdCleanupCallback(void);
extern void DWCi_NdCleanupAsync(void (*callback)(void));
extern struct NdState gDwcNdState;
extern char gDwcNdMutex[];

int DWC_NdCleanupAsync(void)
{
    if (gDwcNdState.f14 == 0)
        return 0;
    func_02086028(gDwcNdMutex);
    if (gDwcNdState.f14 == 0) {
        OS_UnlockMutex(gDwcNdMutex);
        return 0;
    }
    gDwcNdState.f14 = 2;
    OS_UnlockMutex(gDwcNdMutex);
    if (((NdParam *)gDwcNdState.svl)->f40 == 0)
        DWCi_NdCleanupCallback();
    else
        DWCi_NdCleanupAsync(DWCi_NdCleanupCallback);
    return 1;
}
