/*
 * function: DWCi_ShutdownFriend
 * address:  0x021691FC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the word at +0xc of the module state block.
 *
 * symbols:
 *   g_021AA860  0x021AA860  data
 */

#include "../include/G_FriendGlobal.h"

extern struct FriendGlobal g_021AA860;

void DWCi_ShutdownFriend(void)
{
    *(int *)(((char *)&g_021AA860) + 0xc) = 0;
}

