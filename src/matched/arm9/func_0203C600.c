/*
 * function: GFL_NET_STATE_IsWifiLoginState
 * address:  0x0203C600
 * packet:   pkt_0203C600
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM predicate: the callback at +8 of the card task object is GFL_NET_STATE_WifiLoginMain.
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   GFL_NET_STATE_WifiLoginMain  0x0203C0F4  arm
 */

#include "../include/G_Sys.h"

extern struct Sys *_pNetState;
extern void GFL_NET_STATE_WifiLoginMain(void *p);

int GFL_NET_STATE_IsWifiLoginState(void)
{
    return _pNetState->cb == (void *)GFL_NET_STATE_WifiLoginMain;
}
