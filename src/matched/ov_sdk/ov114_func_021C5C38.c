/*
 * function: DWC_NdGetFileListAsync
 * address:  0x021C5C38
 * packet:   pkt_ov114_021C5C38
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_NdGetFileListAsync (libdwcnd.TWL.HYB.a dwc_nd.o)
 *
 * symbols:
 *   func_02059F38  0x02059F38  arm
 *   func_02086028  0x02086028  arm
 *   DWCi_NdSetError  0x021C659C  arm  ov114
 *   OS_UnlockMutex 0x02086078  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   DWCi_NdGetFileListAsync  0x021C7124  arm  ov114
 *   gDwcNdMutex     0x021D3B84  data
 *   gDwcNdState     0x021D3B68  data
 */

#include "../include/G_NdState.h"

typedef struct NdState NdState;

extern int func_02059F38(void);
extern void func_02086028(void *mutex);
extern void DWCi_NdSetError(int err, int servererror);
extern void OS_UnlockMutex(void *mutex);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int DWCi_NdGetFileListAsync(void *filelist, int offset, int num);
extern char gDwcNdMutex[];
extern struct NdState gDwcNdState;

int DWC_NdGetFileListAsync(void *filelist, unsigned int offset, unsigned int num)
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
    MI_CpuFill8(filelist, 0, num * 0xB0);
    if (DWCi_NdGetFileListAsync(filelist, offset, num))
        return 1;
    func_02086028(gDwcNdMutex);
    gDwcNdState.f14 = 1;
    OS_UnlockMutex(gDwcNdMutex);
    return 0;
}
