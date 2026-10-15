/*
 * function: OS_SetDeliverArgStateInvalid
 * address:  0x02088118
 * packet:   pkt_02088118
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     ctrdg_proc.o CTRDGi_CallbackForSetPhi.
 *
 * symbols:
 *   g_02151384  0x02151384  data  a4
 */

#include "../include/G_OsArgumentBss.h"

extern struct OsArgumentBss g_02151384;

void OS_SetDeliverArgStateInvalid(void)
{
    ((int *)&g_02151384)[1] = 0;
}
