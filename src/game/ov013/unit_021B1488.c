/*
 * file:     unit_021B1488.c
 * function: OS_IsThreadAvailable
 * address:  0x021B1488
 * packet:   pkt_ov013_021B1488
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVctPendingList  0x021B4B98  data
 */

#include "vct_types.h"

/* Head of the list of received packets that wait for decoding. */
VctRxPacket *OS_IsThreadAvailable(void)
{
    return gVctPendingList.head;
}
