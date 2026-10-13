/*
 * function: GFL_NET_IRC_WIRELESS_OnConnectEnd
 * address:  0x0203DC4C
 * packet:   pkt_0203DAC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * net_irc_wireless.c.  Callback installed at +0x2C by GFL_NET_IRC_WIRELESS_Create and
 * by states 4 and 14 of GFL_NET_IRC_WIRELESS_Main: flags +0x103 of the live context.
 * An unlabelled ARM leaf.
 *
 * symbols:
 *   gNetIrcWirelessLink     0x021469F0  data
 */

#include "../include/G_Ctx.h"

typedef unsigned char u8;

extern struct Ctx *gNetIrcWirelessLink;

void GFL_NET_IRC_WIRELESS_OnConnectEnd(void)
{
    struct Ctx *p = gNetIrcWirelessLink;

    if (p != 0)
        p->f103 = 1;
}
