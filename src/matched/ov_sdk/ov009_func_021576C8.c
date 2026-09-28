/*
 * function: CPS_SetThreadPriority
 * address:  0x021576C8
 * packet:   pkt_ov009_021576C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_SetThreadPriority (libcps.TWL.HYB.a network.o)
 * symbols:
 *   OS_SetThreadPriority             0x02085988 arm
 *   helper_threads_priority          0x021a1c98 data
 *   tcpip_thread                     0x021a86a4 data
 *   scavenger_thread                 0x021a85e4 data
 */

extern int OS_SetThreadPriority(void *thread, unsigned long prio);
extern unsigned long helper_threads_priority;
extern int tcpip_thread;
extern int scavenger_thread;

void CPS_SetThreadPriority(unsigned long new_prio)
{
	helper_threads_priority = new_prio;
	OS_SetThreadPriority(&tcpip_thread, new_prio);
	OS_SetThreadPriority(&scavenger_thread, new_prio);
}

