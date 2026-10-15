/*
 * function: DWCi_CloseFriendProcess
 * address:  0x02169294
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the word and the two bytes at +0x1e and +0x1f of the object at
 * +0xc of the current root.
 *
 * symbols:
 *   g_021AA860  0x021AA860  data

 */

#include "../include/G_FriendGlobal.h"

extern struct FriendGlobal g_021AA860;

void DWCi_CloseFriendProcess(void)
{
    char *p = *(char **)(((char *)&g_021AA860) + 0xc);
    char *q;

    if (p == 0) return;
    *(int *)p = 0;
    q = *(char **)(((char *)&g_021AA860) + 0xc);
    *(unsigned char *)(q + 0x1e) = 0;
    q = *(char **)(((char *)&g_021AA860) + 0xc);
    *(unsigned char *)(q + 0x1f) = 0;
}


