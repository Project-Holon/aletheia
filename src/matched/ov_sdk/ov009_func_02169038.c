/*
 * function: DWCi_GetFriendListIndex
 * address:  0x02169038
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_GetFriendListIndex: the friend list index holding a profile id, or -1.
 *
 * symbols:
 *   g_021AA860  0x021AA860  data
 *   DWCi_GetProfileIDFromList  0x02168FF0  arm  ov009
 */

#include "../include/G_FriendGlobal.h"

extern struct FriendGlobal g_021AA860;
extern int DWCi_GetProfileIDFromList(int index);

int DWCi_GetFriendListIndex(int pid)
{
    int i;

    if (*(char **)(((char *)&g_021AA860) + 0xc) == 0 || pid == 0) {
        return -1;
    }
    for (i = 0; i < *(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x14); i++) {
        if (pid == DWCi_GetProfileIDFromList(i)) {
            return i;
        }
    }
    return -1;
}
