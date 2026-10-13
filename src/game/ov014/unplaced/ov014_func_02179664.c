/*
 * function: WIH_SetScanTimerPaused
 * address:  0x02179664
 * packet:   pkt_02179664
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A8  0x021797A8  data
 */

#include "../../../matched/include/G_S.h"

extern struct S *g_021797A8;

/*
 * Sets the byte at +0x1EDE of the WH work block: nonzero pauses the scan
 * timeout countdown (the pipe sets it while its join lock is active).
 * Home: wih.c, last function after 02179650.
 */
void WIH_SetScanTimerPaused(unsigned char v)
{
    ((unsigned char *)g_021797A8)[0x1EDE] = v;
}
