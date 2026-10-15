/*
 * function: DWCi_GetFriendBuddyStatus
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
 *   DWCi_CheckLogin  0x0216AA70  arm  ov009
 *   DWCi_GetUserData  0x0216A39C  arm  ov009
 *   DWC_GetGsProfileId  0x020598EC  arm
 *   gpGetBuddyIndex  0x02186108  arm  ov009
 *   gpGetBuddyStatus  0x02185FD4  arm  ov009
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

extern int DWCi_CheckLogin(void);
extern int DWCi_GetUserData(void);
struct DWCstAccUserData;
extern int DWC_GetGsProfileId(struct DWCstAccUserData *userdata, void *frienddata);
extern int gpGetBuddyIndex(void **connection, int profile, int *index);
struct GPBuddyStatus;
extern int gpGetBuddyStatus(void **connection, int index, struct GPBuddyStatus *status);

int DWCi_GetFriendBuddyStatus(void *friendData, BuddyStatus *status)
{
	unsigned char ret = 0;
	int buddyIdx = 0;
	int profileid;
	if (stpFriendCnt == 0 || !DWCi_CheckLogin())
		return 0;
	profileid = DWC_GetGsProfileId((struct DWCstAccUserData *)DWCi_GetUserData(), friendData);
	if (profileid > 0) {
		if (gpGetBuddyIndex(stpFriendCnt->connection, profileid, &buddyIdx) != 0)
			goto end;
	}
	if (!(profileid > 0 && buddyIdx != -1)) {
		ret = 0;
	} else {
		int res = gpGetBuddyStatus(stpFriendCnt->connection, buddyIdx, (struct GPBuddyStatus *)status);
		ret = 0;
		if (res == 0)
			ret = 1;
	}
end:
	return ret;
}
