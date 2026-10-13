/*
 * function: DWC_NdGetFileAsync
 * address:  0x021C5CFC
 * packet:   pkt_ov114_021C5CFC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_NdGetFileAsync (libdwcnd.TWL.HYB.a dwc_nd.o)
 *
 * symbols:
 *   func_02059F38  0x02059F38  arm
 *   func_02086028  0x02086028  arm
 *   DWCi_NdSetError  0x021C659C  arm  ov114
 *   OS_UnlockMutex 0x02086078  arm
 *   DWCi_NdGetFileAsync  0x021C73C0  arm  ov114
 *   gDwcNdMutex     0x021D3B84  data
 *   gDwcNdState     0x021D3B68  data
 */

#include "../include/G_NdState.h"

typedef struct NdState NdState;

extern int func_02059F38(void);
extern void func_02086028(void *mutex);
extern void DWCi_NdSetError(int err, int servererror);
extern void OS_UnlockMutex(void *mutex);
struct DWCNdFileInfo;
extern int DWCi_NdGetFileAsync(struct DWCNdFileInfo *filelist, char *buf, unsigned int bufsize, char *opt);
extern char gDwcNdMutex[];
extern struct NdState gDwcNdState;

int DWC_NdGetFileAsync(void *fileinfo, char *buf, unsigned int size)
{
    if (func_02059F38())
        return 0;
    func_02086028(gDwcNdMutex);
    if (gDwcNdState.f14 != 1) {
        DWCi_NdSetError(2, 0);
        OS_UnlockMutex(gDwcNdMutex);
        return 0;
    }
    gDwcNdState.f14 = 2;
    OS_UnlockMutex(gDwcNdMutex);
    if (DWCi_NdGetFileAsync(fileinfo, buf, size, 0))
        return 1;
    func_02086028(gDwcNdMutex);
    gDwcNdState.f14 = 1;
    OS_UnlockMutex(gDwcNdMutex);
    return 0;
}
