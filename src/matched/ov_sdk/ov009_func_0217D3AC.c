/*
 * function: gsiLargeIntTimerEnter
 * address:  0x0217D3AC
 * packet:   pkt_ov009_0217D3AC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiLargeIntTimerEnter (gslargeint.o)
 *
 * Note: DWARF names the fields started/total/entries/running, but the code
 * shows the flag lives at +0xc and the start timestamp at +0x0; the struct
 * below is ordered to reproduce the accesses. Not version-specific.
 *
 * symbols:
 *   current_time_hires               0x0217f28c arm
 *   gTimers                          0x021ad064 data
 */

#include "../include/G_GSLintTimer.h"

extern struct GSLintTimer gTimers[9];
extern unsigned int current_time_hires(void);

static void gsiLargeIntTimerEnter(int id)
{
    if (gTimers[id].started == 0)
    {
        gTimers[id].entries++;
        gTimers[id].start = current_time_hires();
        gTimers[id].started = 1;
    }
}
