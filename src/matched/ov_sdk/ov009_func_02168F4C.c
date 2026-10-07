/*
 * function: func_02168F4C
 * address:  0x02168F4C
 * packet:   pkt_ov009_02168F4C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GPRecvBuddyStatusCallback (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * symbols:
 *   func_02169038  0x02169038  arm  ov009
 *   func_021861A8  0x021861A8  arm  ov009
 *   func_02186220  0x02186220  arm  ov009
 *   func_02185FD4  0x02185FD4  arm  ov009
 *   g_021AA860  0x021AA860  data
 */

#include "../include/G_FriendGlobal.h"

typedef struct FriendCtl {
	unsigned char pad0[0x34];
	void (*statusCallback)(int, unsigned char, char *, void *);
	void *statusParam;
} FriendCtl;

typedef struct FriendGlobal FriendGlobal;

extern struct FriendGlobal g_021AA860;

typedef struct BuddyStatus {
	int profile;
	int status;
	char statusString[256];
	char locationString[256];
	unsigned char pad[0xc];
} BuddyStatus;

typedef struct RecvArg {
	int profile;
	unsigned char pad[4];
	int index;
} RecvArg;

extern int func_02169038(int profileID);
extern int func_021861A8(void **connection, int profile);
extern int func_02186220(void **connection, int profile);
struct GPBuddyStatus;
extern int func_02185FD4(void **connection, int index, struct GPBuddyStatus *status);

void func_02168F4C(void **connection, RecvArg *arg)
{
	BuddyStatus status;
	int friendIdx;

	friendIdx = func_02169038(arg->profile);
	if (friendIdx == -1) {
		if (func_021861A8(connection, arg->profile))
			func_02186220(connection, arg->profile);
		return;
	}
	if (((FriendCtl *)g_021AA860.ctl)->statusCallback == 0)
		return;
	func_02185FD4(connection, arg->index, (struct GPBuddyStatus *)(&status));
	((FriendCtl *)g_021AA860.ctl)->statusCallback(friendIdx, status.status, status.locationString, ((FriendCtl *)g_021AA860.ctl)->statusParam);
}
