/*
 * function: DSPi_PreSleepCallback
 * address: 0x02705320
 * packet: pkt_twl_02705320
 * region: twl
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/twl/unit_02705320.c and filed here.
 *
 * symbols:
 *   OS_Terminate 0x02088234 arm
 */

void OS_Terminate(void);

/* Tail stub: forwards to OS_Terminate. */
void DSPi_PreSleepCallback(void)
{
    OS_Terminate();
}
