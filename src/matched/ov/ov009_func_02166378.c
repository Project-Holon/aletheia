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
 *   gWcmCpsifWork  0x021AA7DC  data
 */

#include "../include/G_WCMCpsifWork.h"

extern struct WCMCpsifWork gWcmCpsifWork;

void *WCMi_GetCpsifWork(void)
{
    return ((char *)&gWcmCpsifWork);
}

