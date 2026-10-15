/*
 * function: DWCi_Netcheck_StartThread
 * address:  0x0217AAF4
 * packet:   pkt_ov009_0217AAF4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Netcheck_StartThread (dwc_netcheck.o)
 *
 * symbols:
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_CreateThread        0x020853C0  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   func_0217AB78          0x0217AB78  arm  ov009
 *   g_021ACE5C             0x021ACE5C  data
 */

#include "../include/G_G.h"

typedef struct {
    void *http;
    char *nc;
} G;
extern struct G g_021ACE5C;
extern int OS_IsThreadTerminated(void *thread);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long size, unsigned long prio);
extern void OS_WakeupThreadDirect(void *thread);
extern void func_0217AB78(void *arg);

void DWCi_Netcheck_StartThread(void)
{
    if (*(int *)(g_021ACE5C.nc + 0x1188) != 0 &&
        !OS_IsThreadTerminated(g_021ACE5C.nc + 0x111c)) {
        return;
    }
    OS_CreateThread(g_021ACE5C.nc + 0x111c, func_0217AB78, g_021ACE5C.nc,
                    g_021ACE5C.nc + 0x1000, 0x1000, 16);
    OS_WakeupThreadDirect(g_021ACE5C.nc + 0x111c);
}
