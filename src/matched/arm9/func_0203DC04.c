/*
 * function: GFL_NET_IRC_WIRELESS_OnSyncReady
 * address:  0x0203DC04
 * packet:   pkt_0203DAC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified EXACT* - every byte compares equal; the extent runs long only
 * because the follower at 0x0203DC48 carries no `func_` label (it saves no
 * lr and disasm.py does not auto-label it).  That follower is for the
 * integrator's layout/function_starts.txt, not for this file.
 *
 * symbols:
 *   gNetIrcWirelessLink     0x021469F0  data
 *   func_02039338  0x02039338  arm
 */

#include "../include/G_Ctx.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Ctx *gNetIrcWirelessLink;
typedef unsigned short u16;
extern u16 func_02039338(void);

void GFL_NET_IRC_WIRELESS_OnSyncReady(void)
{
    if (gNetIrcWirelessLink == 0)
        return;
    gNetIrcWirelessLink->f102 = 1;
    if (gNetIrcWirelessLink->f106 != 0) {
        gNetIrcWirelessLink->f105 = gNetIrcWirelessLink->f106 - 1;
    } else {
        gNetIrcWirelessLink->f105 = func_02039338();
    }
}
