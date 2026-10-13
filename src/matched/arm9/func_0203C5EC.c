/*
 * function: GFL_NET_STATE_IsWifiDisconnectFinal
 * address:  0x0203C5EC
 * packet:   pkt_0203C5EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf: byte at +0x4a of the card task object.
 *
 * symbols:
 *   _pNetState  0x021469DC  data
 */

#include "../include/G_Sys.h"

extern struct Sys *_pNetState;

int GFL_NET_STATE_IsWifiDisconnectFinal(void)
{
    return _pNetState->f4a;
}
