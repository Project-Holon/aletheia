/*
 * file:     unit_021B23C8.c
 * function: VCT_ResetPeerPool
 * address:  0x021B23C8
 * packet:   pkt_ov013_021B23C8
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVctPeerPool 0x021B4BE0 data
 */

#include "vct_types.h"

/* Empty the free and active peer lists of the peer pool. */
void VCT_ResetPeerPool(void)
{
    gVctPeerPool.activeHead = 0;
    gVctPeerPool.freePeers = 0;
}
