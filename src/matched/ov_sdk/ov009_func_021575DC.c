/*
 * function: CPS_CalmDown
 * address:  0x021575DC
 * packet:   pkt_ov009_021575DC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_CalmDown (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gCpsScavengerThread  0x021A85E4  data
 *   gCpsNetVars  0x021A826C  data
 */

#include "../include/G_021A85E4.h"

struct net_vars {
    char pad0[0x58];
    unsigned long calm;
};

extern struct G_021A85E4 gCpsScavengerThread;
extern struct net_vars gCpsNetVars;
extern unsigned long OS_DisableInterrupts(void);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_WakeupThreadDirect(void *thread);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

int CPS_CalmDown(void)
{
    unsigned long enable = OS_DisableInterrupts();
    int result = OS_IsThreadTerminated(((char *)&gCpsScavengerThread));

    if (result == 0 && gCpsNetVars.calm == 0) {
        gCpsNetVars.calm = 1;
        OS_WakeupThreadDirect(((char *)&gCpsScavengerThread));
    }
    OS_RestoreInterrupts(enable);
    return result;
}
