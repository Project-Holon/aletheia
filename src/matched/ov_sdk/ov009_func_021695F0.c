/*
 * function: func_021695F0
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
 *   func_020591CC  0x020591CC  arm
 *   func_02168FF0  0x02168FF0  arm  ov009
 *   func_0205915C  0x0205915C  arm
 *   func_0216959C  0x0216959C  arm  ov009
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
extern int func_020591CC(FriendData *friendData);
extern int func_02168FF0(int index);
extern int func_0205915C(FriendData *friendData);
extern void func_0216959C(void *friendData, int deleteIndex, int otherIndex);

int func_021695F0(FriendData *friendList, int index, int profileID)
{
	int i;
	int pid_i;

	if (func_020591CC(&friendList[index]) == 1)
		return 0;
	for (i = 0; i < index; i++) {
		pid_i = func_02168FF0(i);
		if (pid_i != 0 && pid_i == profileID) {
			if (func_0205915C(&friendList[index]) && !func_0205915C(&friendList[i]))
				func_0216959C(friendList, i, index);
			else
				func_0216959C(friendList, index, i);
			((FriendCtl *)g_021AA860.ctl)->needRefresh = 1;
			return 1;
		}
	}
	return 0;
}
