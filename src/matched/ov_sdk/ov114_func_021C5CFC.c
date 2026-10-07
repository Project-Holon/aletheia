/*
 * function: func_021C5CFC
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
 *   func_021C659C  0x021C659C  arm  ov114
 *   OS_UnlockMutex 0x02086078  arm
 *   func_021C73C0  0x021C73C0  arm  ov114
 *   g_021D3B84     0x021D3B84  data
 *   g_021D3B68     0x021D3B68  data
 */

#include "../include/G_NdState.h"

typedef struct NdState NdState;

extern int func_02059F38(void);
extern void func_02086028(void *mutex);
extern void func_021C659C(int err, int servererror);
extern void OS_UnlockMutex(void *mutex);
struct DWCNdFileInfo;
extern int func_021C73C0(struct DWCNdFileInfo *filelist, char *buf, unsigned int bufsize, char *opt);
extern char g_021D3B84[];
extern struct NdState g_021D3B68;

int func_021C5CFC(void *fileinfo, char *buf, unsigned int size)
{
    if (func_02059F38())
        return 0;
    func_02086028(g_021D3B84);
    if (g_021D3B68.f14 != 1) {
        func_021C659C(2, 0);
        OS_UnlockMutex(g_021D3B84);
        return 0;
    }
    g_021D3B68.f14 = 2;
    OS_UnlockMutex(g_021D3B84);
    if (func_021C73C0(fileinfo, buf, size, 0))
        return 1;
    func_02086028(g_021D3B84);
    g_021D3B68.f14 = 1;
    OS_UnlockMutex(g_021D3B84);
    return 0;
}
