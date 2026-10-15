/*
 * function: DWCi_EndCloseStatsConnection
 * address:  0x0216A00C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the word at +0x10 of the module state block.
 *
 * symbols:
 *   g_021AA860  0x021AA860  data
 */

#include "../include/G_FriendGlobal.h"

extern struct FriendGlobal g_021AA860;

void DWCi_EndCloseStatsConnection(void)
{
    *(int *)(((char *)&g_021AA860) + 0x10) = 0;
}

