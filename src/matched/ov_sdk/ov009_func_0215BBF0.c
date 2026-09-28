/*
 * function: dacktimer_alarmhandler
 * address:  0x0215BBF0
 * packet:   pkt_ov009_0215BBF0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dacktimer_alarmhandler (libcps.TWL.HYB.a network.o)
 * symbols:
 *   dacktimer_thread                 0x021a8524 data ov009
 *   OS_WakeupThreadDirect            0x02085868 arm
 */

extern void OS_WakeupThreadDirect(void *thread);
extern unsigned char dacktimer_thread[];

void dacktimer_alarmhandler(void)
{
	OS_WakeupThreadDirect(dacktimer_thread);
}
