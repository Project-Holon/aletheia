/*
 * function: dacktimer
 * address:  0x0215BBB0
 * packet:   pkt_ov009_0215BBB0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dacktimer (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   dacktimer_reschedule  0x0215BAC0  arm  ov009
 *   OS_SleepThread  0x020857B0  arm
 *   gCpsScavengerThread  0x021A85E4  data
 */

#include "../include/G_021A85E4.h"

extern struct G_021A85E4 gCpsScavengerThread;
extern int OS_IsThreadTerminated(void *thread);
extern void dacktimer_reschedule(void);
extern void OS_SleepThread(void *queue);

void dacktimer(void)
{
    if (OS_IsThreadTerminated(((char *)&gCpsScavengerThread)))
        return;
    do {
        dacktimer_reschedule();
        OS_SleepThread(0);
    } while (!OS_IsThreadTerminated(((char *)&gCpsScavengerThread)));
}
