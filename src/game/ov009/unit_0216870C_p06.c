/*
 * file:     unit_0216870C_p06.c
 * unit:     yes
 * function: func_021696B0, func_021697D8, func_0216980C, func_021698C0
 * address:  0x021696B0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02168FF0  0x02168FF0  arm  ov009
 *   func_020591CC  0x020591CC  arm
 *   func_02059A10  0x02059A10  arm
 *   func_0205915C  0x0205915C  arm
 *   func_02059214  0x02059214  arm
 *   func_0205912C  0x0205912C  arm
 *   func_02059270  0x02059270  arm
 *   func_0216959C  0x0216959C  arm  ov009
 *   g_021AA860     0x021AA860  data
 *   g_021A200C   0x021A200C  data
 *   func_02185D04  0x02185D04  arm
 *   func_0216AA70  0x0216AA70  arm  ov009
 *   func_0216A39C  0x0216A39C  arm  ov009
 *   func_020598EC  0x020598EC  arm
 *   func_02186108  0x02186108  arm  ov009
 *   func_02185FD4  0x02185FD4  arm  ov009
 *   s_bNeedCloseStatsConnection  0x021AA860  data
 *   func_02168E50  0x02168E50  arm
 */
#include "../../matched/include/G_FriendGlobal.h"
#include "../../matched/include/G_FriendGlobal.h"

struct DWCstAccUserData;
struct GPBuddyStatus;
typedef unsigned char u8;

struct Work {
    char pad0[0x18];
    u8 *friendList;
    char pad1c;
    u8 flag;
};

typedef struct FriendCtl {
	unsigned char pad0[4];
	void **connection;
	unsigned char pad1[0x28];
	void (*statusCallback)(int, unsigned char, char *, void *);
	void *statusParam;
	unsigned char pad2[0x30];
	unsigned char needRefresh;
} FriendCtl;

typedef struct BuddyStatus {
	int profile;
	int status;
	char statusString[256];
	char locationString[256];
	unsigned char pad[0xc];
} BuddyStatus;

extern int func_02168FF0(int index);
extern int func_020591CC(void *friendData);
extern void func_02059A10(void *friendData, int pid);
extern int func_0205915C(void *friendData);
extern void func_02059214(void *friendData);
extern int func_0205912C(void *friendData);
extern void func_02059270(void *friendData, int flag);
extern void func_0216959C(void *friendList, int deleteIndex, int otherIndex);
extern int func_02185D04(void **connection, int profile, char *reason);
extern int func_0216AA70(void);
extern int func_0216A39C(void);
extern int func_020598EC(struct DWCstAccUserData *userdata, void *frienddata);
extern int func_02186108(void **connection, int profile, int *index);
extern int func_02185FD4(void **connection, int index, struct GPBuddyStatus *status);
extern void func_02168E50(int error, int errorCode);
int func_021696B0(u8 *friendList, int friendListLen, int profileID);
/* * sdk: DWCi_GPSendBuddyRequest (dwc_friend.o) */ int func_021697D8(int profileID);
/* * closed (2026-10-01, ov SDK wave 2): the dwc_friend.o statics (s_bNeedCloseStatsConnection +0, * stpFriendCnt +0xc) are TU `static ... = 0;` as in DWCi_FriendProcess, not one extern * struct; the anchor web now schedules the prologue like the image. * * sdk: DWCi_GetFriendBuddyStatus (libdwcmatch.TWL.HYB.a(dwc_friend.o)) */ int func_0216980C(void *friendData, BuddyStatus *status);
int func_021698C0(int result);
extern struct FriendGlobal g_021AA860;
extern char g_021A200C[];



/*
 * sdk:      DWCi_RefreshFriendListAll (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
int func_021696B0(u8 *friendList, int friendListLen, int profileID)
{
    int index = -1;
    int pid_i;
    int i;
    int j;

    for (i = 0; i < friendListLen; i++) {
        pid_i = func_02168FF0(i);
        if (pid_i == 0)
            continue;
        if (pid_i == profileID)
            index = i;
        for (j = i + 1; j < friendListLen; j++) {
            if (pid_i != func_02168FF0(j))
                continue;
            if (func_020591CC(friendList + i * 12) == 2 && func_020591CC(friendList + j * 12) == 3)
                func_02059A10(friendList + i * 12, pid_i);
            if (func_0205915C(friendList + j * 12)) {
                func_02059214(friendList + i * 12);
                if (func_0205912C(g_021AA860.ctl->friendList + i * 12))
                    func_02059270(g_021AA860.ctl->friendList + i * 12, 1);
            }
            func_0216959C(friendList, j, i);
            g_021AA860.ctl->flag = 1;
        }
    }
    return index;
}




/*
 * sdk:      DWCi_GPSendBuddyRequest (dwc_friend.o)
 */
int func_021697D8(int profileID)
{
    int gpResult;

    gpResult = func_02185D04(*(void ***)(*(char **)(((char *)&g_021AA860) + 0xc) + 4), profileID, g_021A200C);
    func_021698C0(gpResult);
    return gpResult;
}




static int s_bInCloseStatsConnection = 0;



static int s_bInPersistThink = 0;



static int s_bNeedCloseStatsConnection = 0;



static FriendCtl *stpFriendCnt = 0;




/*
 * closed (2026-10-01, ov SDK wave 2): the dwc_friend.o statics (s_bNeedCloseStatsConnection +0,
 *   stpFriendCnt +0xc) are TU `static ... = 0;` as in DWCi_FriendProcess, not one extern
 *   struct; the anchor web now schedules the prologue like the image.
 *
 * sdk:      DWCi_GetFriendBuddyStatus (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
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


/*
 * sdk:      DWCi_HandleGPError (dwc_friend.o)
 */
int func_021698C0(int result)
{
    int dwcError;
    int errorCode;

    if (result == 0) return 0;
    switch (result) {
    case 1: dwcError = 9; errorCode = -1; break;
    case 2: dwcError = 9; errorCode = -2; break;
    case 3: dwcError = 6; errorCode = -10; break;
    case 4: dwcError = 6; errorCode = -20; break;
    }
    func_02168E50(dwcError, errorCode + (int)0xfffeeaa8);
    return result;
}
