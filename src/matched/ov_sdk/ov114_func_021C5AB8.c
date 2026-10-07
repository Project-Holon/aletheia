/*
 * function: func_021C5AB8
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
 *   func_02086028  0x02086028  arm
 *   OS_UnlockMutex 0x02086078  arm
 *   g_021D3B84     0x021D3B84  data
 *   g_021D3B68     0x021D3B68  data
 */

#include "../include/G_NdState.h"

typedef struct NdState NdState;

extern void func_02086028(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern char g_021D3B84[];
extern struct NdState g_021D3B68;

void func_021C5AB8(void)
{
    int needCallback = 0;
    int needCleanUpCallback = 0;
    int reason;

    func_02086028(g_021D3B84);
    reason = g_021D3B68.f10;
    if (reason == 0 && g_021D3B68.f14 == 4) {
        if (g_021D3B68.f4 == 0) {
            needCallback = 1;
            g_021D3B68.f4 = 1;
        }
    } else if ((unsigned int)(g_021D3B68.f14 - 3) <= 1) {
        needCallback = 1;
        g_021D3B68.f14 = 1;
    }
    if (reason == 4) {
        g_021D3B68.f14 = 0;
        g_021D3B68.f10 = 0;
        needCleanUpCallback = 1;
    }
    OS_UnlockMutex(g_021D3B84);
    if (g_021D3B68.cb == 0)
        return;
    if (needCleanUpCallback) {
        g_021D3B68.cb(4, 0, -1);
    } else if (needCallback) {
        g_021D3B68.cb(g_021D3B68.f10, g_021D3B68.fC, g_021D3B68.f8);
    }
}
