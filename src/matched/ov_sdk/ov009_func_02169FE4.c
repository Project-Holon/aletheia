/*
 * function: DWCi_GetPersCallbackLevel
 * address:  0x02169FE4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The word at +0x20 of the block held at +0xc of the module state block.
 *
 * symbols:
 *   g_021AA860  0x021AA860  data
 */

#include "../include/G_FriendGlobal.h"

extern struct FriendGlobal g_021AA860;

int DWCi_GetPersCallbackLevel(void)
{
    int blk = *(int *)(((char *)&g_021AA860) + 0xc);

    return *(int *)(blk + 0x20);
}

