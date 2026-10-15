/*
 * function: DWCi_RefreshFriendListForth
 * address:  0x021695F0
 * packet:   pkt_ov009_021695F0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RefreshFriendListForth (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * symbols:
 *   DWCi_Acc_GetFlagDataTypeThunk  0x020591CC  arm
 *   DWCi_GetProfileIDFromList  0x02168FF0  arm  ov009
 *   func_0205915C  0x0205915C  arm
 *   DWCi_DeleteFriendFromList  0x0216959C  arm  ov009
 *   g_021AA860  0x021AA860  data
 */

#include "../include/G_FriendGlobal.h"

typedef struct FriendData {
	unsigned char data[12];
} FriendData;

typedef struct FriendCtl {
	unsigned char pad0[0x1d];
	unsigned char needRefresh;
} FriendCtl;

typedef struct FriendGlobal FriendGlobal;

extern struct FriendGlobal g_021AA860;
extern int DWCi_Acc_GetFlagDataTypeThunk(FriendData *friendData);
extern int DWCi_GetProfileIDFromList(int index);
extern int func_0205915C(FriendData *friendData);
extern void DWCi_DeleteFriendFromList(void *friendData, int deleteIndex, int otherIndex);

int DWCi_RefreshFriendListForth(FriendData *friendList, int index, int profileID)
{
	int i;
	int pid_i;

	if (DWCi_Acc_GetFlagDataTypeThunk(&friendList[index]) == 1)
		return 0;
	for (i = 0; i < index; i++) {
		pid_i = DWCi_GetProfileIDFromList(i);
		if (pid_i != 0 && pid_i == profileID) {
			if (func_0205915C(&friendList[index]) && !func_0205915C(&friendList[i]))
				DWCi_DeleteFriendFromList(friendList, i, index);
			else
				DWCi_DeleteFriendFromList(friendList, index, i);
			((FriendCtl *)g_021AA860.ctl)->needRefresh = 1;
			return 1;
		}
	}
	return 0;
}
