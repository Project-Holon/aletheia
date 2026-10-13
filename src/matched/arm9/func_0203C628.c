/*
 * function: GFL_NET_STATE_IsWifiLoginOrConnected
 * address:  0x0203C628
 * packet:   pkt_0203C628
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM predicate: the callback at +8 of the card task object is GFL_NET_STATE_WifiLoginMain or GFL_NET_STATE_WifiConnected.
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   GFL_NET_STATE_WifiLoginMain  0x0203C0F4  arm
 *   GFL_NET_STATE_WifiConnected  0x0203C464  arm
 */

#include "../include/G_Sys.h"

extern struct Sys *_pNetState;
extern void GFL_NET_STATE_WifiLoginMain(void *p);
extern int GFL_NET_STATE_WifiConnected(int a0, int a1, int a2, int a3);

int GFL_NET_STATE_IsWifiLoginOrConnected(void)
{
    void *cb = _pNetState->cb;
    return cb == (void *)GFL_NET_STATE_WifiLoginMain || cb == (void *)GFL_NET_STATE_WifiConnected;
}
