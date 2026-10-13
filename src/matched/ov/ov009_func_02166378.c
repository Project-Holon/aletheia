/*
 * function: WCMi_GetCpsifWork
 * address:  0x02166378
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Address of the module state object.
 *
 * symbols:
 *   g_021AA7DC  0x021AA7DC  data
 */

#include "../include/G_WCMCpsifWork.h"

extern struct WCMCpsifWork g_021AA7DC;

void *WCMi_GetCpsifWork(void)
{
    return ((char *)&g_021AA7DC);
}

