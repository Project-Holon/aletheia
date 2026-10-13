/*
 * unit:     no
 * function: GFL_NET_IRC_WIRELESS_GetBeaconCompare
 * address:  0x0203E458
 * packet:   pkt_0203DA7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   gNetIrcWirelessLink      0x021469F0  data
 */

#include "../include/G_Ctx.h"

extern struct Ctx *gNetIrcWirelessLink;
void *GFL_NET_IRC_WIRELESS_GetBeaconCompare(void *arg)
{
    void *r;
    if (gNetIrcWirelessLink == 0)
        return 0;
    r = gNetIrcWirelessLink->fn(arg);
    return (char *)r + 0x24;
}
