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
 *   func_021C659C  0x021C659C  arm  ov114
 *   func_02086028  0x02086028  arm
 *   OS_UnlockMutex 0x02086078  arm
 *   g_021D3B84     0x021D3B84  data
 *   g_021D3B68     0x021D3B68  data
 */

#include "../include/G_NdState.h"

typedef struct NdState NdState;

extern void func_021C659C(int err, int servererror);
extern void func_02086028(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern char g_021D3B84[];
extern struct NdState g_021D3B68;

void func_021C58C8(int reason, int error, int servererror)
{
    if (error != 0)
        func_021C659C(error, servererror);
    func_02086028(g_021D3B84);
    g_021D3B68.f14 = 3;
    g_021D3B68.f10 = reason;
    g_021D3B68.fC = error;
    g_021D3B68.f8 = servererror;
    if (error != 0)
        g_021D3B68.f14 = 4;
    OS_UnlockMutex(g_021D3B84);
}
