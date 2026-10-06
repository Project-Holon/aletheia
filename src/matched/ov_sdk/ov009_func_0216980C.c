/*
 * function: func_0216980C
 * address:  0x0216980C
 * packet:   pkt_ov009_0216980C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * closed (2026-10-01, ov SDK wave 2): the dwc_friend.o statics (s_bNeedCloseStatsConnection +0,
 *   stpFriendCnt +0xc) are TU `static ... = 0;` as in DWCi_FriendProcess, not one extern
 *   struct; the anchor web now schedules the prologue like the image.
 *
 * sdk:      DWCi_GetFriendBuddyStatus (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * symbols:
 *   func_0216AA70  0x0216AA70  arm  ov009
 *   func_0216A39C  0x0216A39C  arm  ov009
 *   func_020598EC  0x020598EC  arm
 *   func_02186108  0x02186108  arm  ov009
 *   func_02185FD4  0x02185FD4  arm  ov009
 *   s_bNeedCloseStatsConnection  0x021AA860  data
 */

typedef struct FriendCtl {
	unsigned char pad0[4];
	void **connection;
	unsigned char pad1[0x28];
	void (*statusCallback)(int, unsigned char, char *, void *);
	void *statusParam;
	unsigned char pad2[0x30];
	unsigned char needRefresh;
} FriendCtl;

static int s_bInCloseStatsConnection = 0;
static int s_bInPersistThink = 0;
static int s_bNeedCloseStatsConnection = 0;
static FriendCtl *stpFriendCnt = 0;

typedef struct BuddyStatus {
	int profile;
	int status;
	char statusString[256];
	char locationString[256];
	unsigned char pad[0xc];
} BuddyStatus;

extern int func_0216AA70(void);
extern int func_0216A39C(void);
struct DWCstAccUserData;
extern int func_020598EC(struct DWCstAccUserData *userdata, void *frienddata);
extern int func_02186108(void **connection, int profile, int *index);
struct GPBuddyStatus;
extern int func_02185FD4(void **connection, int index, struct GPBuddyStatus *status);

int func_0216980C(void *friendData, BuddyStatus *status)
{
	unsigned char ret = 0;
	int buddyIdx = 0;
	int profileid;
	if (stpFriendCnt == 0 || !func_0216AA70())
		return 0;
	profileid = func_020598EC((struct DWCstAccUserData *)func_0216A39C(), friendData);
	if (profileid > 0) {
		if (func_02186108(stpFriendCnt->connection, profileid, &buddyIdx) != 0)
			goto end;
	}
	if (!(profileid > 0 && buddyIdx != -1)) {
		ret = 0;
	} else {
		int res = func_02185FD4(stpFriendCnt->connection, buddyIdx, (struct GPBuddyStatus *)status);
		ret = 0;
		if (res == 0)
			ret = 1;
	}
end:
	return ret;
}
