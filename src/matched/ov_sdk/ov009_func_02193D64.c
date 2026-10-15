/*
 * function: IsStatsConnected
 * address:  0x02193D64
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Set while the word at +4 of the state object is not -1.
 *
 * symbols:
 *   gGstatsSocket  0x021A57C8  data
 */

#include "../include/G_StatsSocket.h"

extern struct StatsSocket gGstatsSocket;

int IsStatsConnected(void)
{
    return *(int *)(((char *)&gGstatsSocket) + 4) != -1;
}

