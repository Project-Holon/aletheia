/*
 * function: ghttpStartup
 * address:  0x021C1FF8
 * packet:   pkt_ov114_021C1FF8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghttpStartup (libdwcgsghttp.TWL.HYB.a(ghttpmain.o))
 *
 * symbols:
 *   ghiLock  0x021C0370  arm  ov114
 *   ghiInitLock  0x021C0368  arm  ov114
 *   ghiUnlock  0x021C0374  arm  ov114
 *   gGhttpInitCount  0x021D3B64  data
 *   gGhttpThrottle  0x021CE5AC  data
 *   gGhttpThrottleBufferSize  0x021CE5B0  data
 */

#include "../include/G_GHIThrottle.h"

extern void ghiLock(void);
extern void ghiInitLock(void);
extern void ghiUnlock(void);
extern int gGhttpInitCount;
extern struct GHIThrottle gGhttpThrottle;
extern int gGhttpThrottleBufferSize;

void ghttpStartup(void)
{
	ghiLock();
	if (++gGhttpInitCount == 1) {
		ghiInitLock();
		gGhttpThrottleBufferSize = 125;
		(*(int *)&gGhttpThrottle) = 250;
	} else {
		ghiUnlock();
	}
}
