/*
 * function: WmSleepCallback
 * address:  0x0208EA94
 * packet:   pkt_0208EA94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm system.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   OS_Terminate                   0x02088234  arm
 */

extern void OS_Terminate(void);

void WmSleepCallback(void *arg)
{
    OS_Terminate();
}
