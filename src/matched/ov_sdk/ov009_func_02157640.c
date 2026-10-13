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
 *   func_020873F8  0x020873F8  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_02157290  0x02157290  arm  ov009
 *   g_021A85E4  0x021A85E4  data
 *   g_021A86A4  0x021A86A4  data
 *   g_021A82FC  0x021A82FC  data
 *   g_021A8524  0x021A8524  data
 *   g_021A826C  0x021A826C  data
 */

#include "../include/G_021A85E4.h"
#include "../include/G_021A86A4.h"
#include "../include/G__OSThread.h"

extern struct G_021A85E4 g_021A85E4;
extern struct G_021A86A4 g_021A86A4;
extern char g_021A82FC[];
extern struct _OSThread g_021A8524;
extern char g_021A826C[];
extern int CPS_CalmDown(void);
extern void OS_JoinThread(void *thread);
extern void OS_DestroyThread(void *thread);
extern void func_020873F8(void *alarm);
extern unsigned long OS_DisableInterrupts(void);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_WakeupThreadDirect(void *thread);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void func_02157290(int arg);

void CPS_Cleanup(void)
{
    unsigned long enable;

    CPS_CalmDown();
    OS_JoinThread(((char *)&g_021A85E4));
    OS_DestroyThread(((char *)&g_021A86A4));
    func_020873F8(g_021A82FC);
    enable = OS_DisableInterrupts();
    if (!OS_IsThreadTerminated(((char *)&g_021A8524)))
        OS_WakeupThreadDirect(((char *)&g_021A8524));
    OS_RestoreInterrupts(enable);
    OS_JoinThread(((char *)&g_021A8524));
    *(unsigned long *)(g_021A826C + 0x54) = 0;
    func_02157290(0);
    *(unsigned long *)(g_021A826C + 0x20) = 0;
    *(unsigned long *)(g_021A826C + 0x5c) = 0;
}
