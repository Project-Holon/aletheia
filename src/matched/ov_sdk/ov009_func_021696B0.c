/*
 * function: DWCi_RefreshFriendListAll
 * address:  0x021696B0
 * packet:   pkt_ov009_021696B0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RefreshFriendListAll (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * symbols:
 *   DWCi_GetProfileIDFromList  0x02168FF0  arm  ov009
 *   DWCi_Acc_GetFlagDataTypeThunk  0x020591CC  arm
 *   DWC_SetGsProfileId  0x02059A10  arm
 *   func_0205915C  0x0205915C  arm
 *   DWCi_SetBuddyFriendData  0x02059214  arm
 *   DWC_IsBuddyFriendData  0x0205912C  arm
 *   DWCi_SetExpIsBuddyFriendFlag  0x02059270  arm
 *   DWCi_DeleteFriendFromList  0x0216959C  arm  ov009
 *   g_021AA860     0x021AA860  data
 */

#include "../include/G_FriendGlobal.h"

typedef unsigned char u8;

struct Work {
    char pad0[0x18];
    u8 *friendList;
    char pad1c;
    u8 flag;
};
extern struct FriendGlobal g_021AA860;

extern int DWCi_GetProfileIDFromList(int index);
extern int DWCi_Acc_GetFlagDataTypeThunk(void *friendData);
extern void DWC_SetGsProfileId(void *friendData, int pid);
extern int func_0205915C(void *friendData);
extern void DWCi_SetBuddyFriendData(void *friendData);
extern int DWC_IsBuddyFriendData(void *friendData);
extern void DWCi_SetExpIsBuddyFriendFlag(void *friendData, int flag);
extern void DWCi_DeleteFriendFromList(void *friendList, int deleteIndex, int otherIndex);

int DWCi_RefreshFriendListAll(u8 *friendList, int friendListLen, int profileID)
{
    int index = -1;
    int pid_i;
    int i;
    int j;

    for (i = 0; i < friendListLen; i++) {
        pid_i = DWCi_GetProfileIDFromList(i);
        if (pid_i == 0)
            continue;
        if (pid_i == profileID)
            index = i;
        for (j = i + 1; j < friendListLen; j++) {
            if (pid_i != DWCi_GetProfileIDFromList(j))
                continue;
            if (DWCi_Acc_GetFlagDataTypeThunk(friendList + i * 12) == 2 && DWCi_Acc_GetFlagDataTypeThunk(friendList + j * 12) == 3)
                DWC_SetGsProfileId(friendList + i * 12, pid_i);
            if (func_0205915C(friendList + j * 12)) {
                DWCi_SetBuddyFriendData(friendList + i * 12);
                if (DWC_IsBuddyFriendData(g_021AA860.ctl->friendList + i * 12))
                    DWCi_SetExpIsBuddyFriendFlag(g_021AA860.ctl->friendList + i * 12, 1);
            }
            DWCi_DeleteFriendFromList(friendList, j, i);
            g_021AA860.ctl->flag = 1;
        }
    }
    return index;
}
