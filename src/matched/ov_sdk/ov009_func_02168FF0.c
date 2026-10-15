/*
 * function: DWCi_GetProfileIDFromList
 * address:  0x02168FF0
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_GetProfileIDFromList: the profile id of a friend list entry, zero when unset or invalid.
 *
 * symbols:
 *   g_021AA860  0x021AA860  data
 *   DWCi_GetUserData  0x0216A39C  arm  ov009
 *   DWC_GetGsProfileId  0x020598EC  arm
 */

#include "../include/G_FriendGlobal.h"

extern struct FriendGlobal g_021AA860;
extern int DWCi_GetUserData(void);
extern int DWC_GetGsProfileId(void *user, void *data);

int DWCi_GetProfileIDFromList(int index)
{
    char *list = *(char **)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x18);
    int pid;

    if (list == 0) {
        return 0;
    }
    pid = DWC_GetGsProfileId((void *)DWCi_GetUserData(), list + index * 0xc);
    if (pid != 0 && pid != -1) {
        return pid;
    }
    return 0;
}
