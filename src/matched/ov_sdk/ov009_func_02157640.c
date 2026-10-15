/*
 * function: CPS_Cleanup
 * address:  0x02157640
 * packet:   pkt_ov009_02157640
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_Cleanup (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   CPS_CalmDown  0x021575DC  arm  ov009
 *   OS_JoinThread  0x02085710  arm
 *   OS_DestroyThread  0x020855BC  arm
 *   OS_CancelAlarm  0x020873F8  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_02157290  0x02157290  arm  ov009
 *   gCpsScavengerThread  0x021A85E4  data
 *   gCpsTcpipThread  0x021A86A4  data
 *   gCpsDackTimerAlarm  0x021A82FC  data
 *   gCpsDackTimerThread  0x021A8524  data
 *   gCpsNetVars  0x021A826C  data
 */

#include "../include/G_021A85E4.h"
#include "../include/G_021A86A4.h"
#include "../include/G__OSThread.h"

extern struct G_021A85E4 gCpsScavengerThread;
extern struct G_021A86A4 gCpsTcpipThread;
extern char gCpsDackTimerAlarm[];
extern struct _OSThread gCpsDackTimerThread;
extern char gCpsNetVars[];
extern int CPS_CalmDown(void);
extern void OS_JoinThread(void *thread);
extern void OS_DestroyThread(void *thread);
extern void OS_CancelAlarm(void *alarm);
extern unsigned long OS_DisableInterrupts(void);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_WakeupThreadDirect(void *thread);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void func_02157290(int arg);

void CPS_Cleanup(void)
{
    unsigned long enable;

    CPS_CalmDown();
    OS_JoinThread(((char *)&gCpsScavengerThread));
    OS_DestroyThread(((char *)&gCpsTcpipThread));
    OS_CancelAlarm(gCpsDackTimerAlarm);
    enable = OS_DisableInterrupts();
    if (!OS_IsThreadTerminated(((char *)&gCpsDackTimerThread)))
        OS_WakeupThreadDirect(((char *)&gCpsDackTimerThread));
    OS_RestoreInterrupts(enable);
    OS_JoinThread(((char *)&gCpsDackTimerThread));
    *(unsigned long *)(gCpsNetVars + 0x54) = 0;
    func_02157290(0);
    *(unsigned long *)(gCpsNetVars + 0x20) = 0;
    *(unsigned long *)(gCpsNetVars + 0x5c) = 0;
}
