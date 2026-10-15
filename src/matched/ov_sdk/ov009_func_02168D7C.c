/*
 * function: DWCi_IsServerUpdating
 * address:  0x02168D7C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * True when the object at +0xc of the current root exists and its first word
 * is 1.
 *
 * symbols:
 *   g_021AA860  0x021AA860  data

 */

#include "../include/G_FriendGlobal.h"

extern struct FriendGlobal g_021AA860;

int DWCi_IsServerUpdating(void)
{
    int r = 0;
    char *p = *(char **)(((char *)&g_021AA860) + 0xc);

    if (p != 0 && *(int *)p == 1) r = 1;
    return r;
}


