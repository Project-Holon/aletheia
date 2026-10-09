/*
 * file:     unit_0216870C_p05.c
 * unit:     yes
 * function: func_02169210, func_02169294, func_021692C4, func_02169568, func_0216959C, func_021695F0
 * address:  0x02169210
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   func_02185948  0x02185948  arm  ov009
 *   _ll_udiv  0x0209C00C  arm
 *   g_021AA860  0x021AA860  data
 *   gpGetNumBuddies                  0x02185fa4 arm
 *   DWCi_HandleGPError               0x021698c0 arm
 *   gpGetBuddyStatus                 0x02185fd4 arm
 *   DWCi_GetProfileIDFromList        0x02168ff0 arm
 *   DWCi_IsBuddyFriendData           0x0205915c arm
 *   DWC_SetGsProfileId               0x02059a10 arm
 *   DWCi_SetBuddyFriendData          0x02059214 arm
 *   DWC_IsBuddyFriendData            0x0205912c arm
 *   DWCi_SetExpIsBuddyFriendFlag     0x02059270 arm
 *   gpDeleteBuddy                    0x02186220 arm
 *   DWCi_IsBuddyMsgAlreadySent       0x020591b0 arm
 *   DWCi_RefreshFriendListForth      0x021695f0 arm
 *   gpGetBuddyIndex                  0x02186108 arm
 *   DWCi_GPSendBuddyRequest          0x021697d8 arm
 *   DWCi_SetSentBuddyReqFlag         0x020592a0 arm
 *   DWCi_GetUserData                 0x0216a39c arm
 *   DWC_GetGsProfileId               0x020598ec arm
 *   DWC_LoginIdToUserName            0x02059a44 arm
 *   gpProfileSearchA                 0x02185b10 arm
 *   DWCi_GPProfileSearchCallback     0x02169934 arm
 *   s_bNeedCloseStatsConnection      0x021aa860 data
 *   func_02082BCC  0x02082BCC  arm
 *   func_020591CC  0x020591CC  arm
 *   func_02168FF0  0x02168FF0  arm  ov009
 *   func_0205915C  0x0205915C  arm
 */
#include "../../matched/include/G_FriendGlobal.h"
#include "../../matched/include/G_FriendGlobal.h"

typedef unsigned long long u64;

struct Work {
	char pad0[4];
	void *conn;
	int count;
	u64 last;
};

typedef unsigned char u8;

typedef union DWCstAccFriendData {
    char data[0xc];
} DWCstAccFriendData;

typedef struct GPBuddyStatus {
    int profile;
    int status;
    char statusString[256];
    char locationString[256];
    unsigned int ip;
    int port;
    int quietModeFlags;
} GPBuddyStatus;

typedef struct FriendList {
    int field0;
    void **connection;
    int field8;
    int pad1;
    int pad2;
    int count;
    DWCstAccFriendData *list;
    u8 field1c;
    u8 field1d;
    u8 reason;
    u8 field1f;
    u8 pad4[0x5c - 0x20];
    int *field5c;
} FriendList;

typedef struct FriendState {
    int field0;
    int field4;
    int pad2;
    FriendList *fl;
} FriendState;

typedef struct FriendData {
	unsigned char data[12];
} FriendData;

typedef struct FriendCtl {
	unsigned char pad0[0x1d];
	unsigned char needRefresh;
} FriendCtl;

typedef struct FriendGlobal FriendGlobal;

extern u64 func_020870D0(void);
extern u64 _ll_udiv(u64 a, u64 b);
extern int func_02185948(void *conn);
extern int gpGetNumBuddies(void **connection, int *numBuddies);
extern int DWCi_HandleGPError(int result);
extern int gpGetBuddyStatus(void **connection, int index, GPBuddyStatus *status);
extern int DWCi_GetProfileIDFromList(int index);
extern int DWCi_IsBuddyFriendData(DWCstAccFriendData *frienddata);
extern void DWC_SetGsProfileId(DWCstAccFriendData *frienddata, int gs_profile_id);
extern void DWCi_SetBuddyFriendData(DWCstAccFriendData *frienddata);
extern int DWC_IsBuddyFriendData(DWCstAccFriendData *frienddata);
extern void DWCi_SetExpIsBuddyFriendFlag(DWCstAccFriendData *frienddata, int setflag);
extern int gpDeleteBuddy(void **connection, int profile);
extern int DWCi_IsBuddyMsgAlreadySent(DWCstAccFriendData *frienddata);
extern int DWCi_RefreshFriendListForth(DWCstAccFriendData *friendList, int index, int profileID);
extern int gpGetBuddyIndex(void **connection, int profile, int *index);
extern int DWCi_GPSendBuddyRequest(int profileID);
extern void DWCi_SetSentBuddyReqFlag(DWCstAccFriendData *frienddata, int setflag);
extern void *DWCi_GetUserData(void);
extern int DWC_GetGsProfileId(void *userdata, DWCstAccFriendData *frienddata);
extern void DWC_LoginIdToUserName(void *userdata, DWCstAccFriendData *frienddata, char *username);
extern int gpProfileSearchA(void **connection, char *nick, char *uniquenick, char *email,
                            char *firstname, char *lastname, int icquin, int blocking,
                            void (*callback)(void **, void *, void *), void *param);
extern void DWCi_GPProfileSearchCallback(void **connection, void *arg, void *param);
extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern int func_020591CC(FriendData *friendData);
extern int func_02168FF0(int index);
extern int func_0205915C(FriendData *friendData);
/* * sdk: DWCi_GPProcess (libdwcmatch.TWL.HYB.a(dwc_friend.o)) */ int func_02169210(void);
/* * Clears the word and the two bytes at +0x1e and +0x1f of the object at * +0xc of the current root. */ void func_02169294(void);
void DWCi_UpdateFriendReq(DWCstAccFriendData *friendList, int friendListLen);
void func_02169568(void);
void func_0216959C(void *friendData, int deleteIndex, int otherIndex);
int func_021695F0(FriendData *friendList, int index, int profileID);
extern struct FriendGlobal g_021AA860;
extern FriendState s_bNeedCloseStatsConnection;




/*
 * sdk:      DWCi_GPProcess (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
int func_02169210(void)
{
	int result;
	struct Work *w;
	u64 tick;
	result = 0;
	tick = func_020870D0();
	w = g_021AA860.ctl;
	if ((tick - w->last) * 64 / 33514 >= 300) {
		w->count++;
		result = func_02185948(g_021AA860.ctl->conn);
		g_021AA860.ctl->last = func_020870D0();
	}
	return result;
}





/*
 * Clears the word and the two bytes at +0x1e and +0x1f of the object at
 * +0xc of the current root.
 */
void func_02169294(void)
{
    char *p = *(char **)(((char *)&g_021AA860) + 0xc);
    char *q;

    if (p == 0) return;
    *(int *)p = 0;
    q = *(char **)(((char *)&g_021AA860) + 0xc);
    *(unsigned char *)(q + 0x1e) = 0;
    q = *(char **)(((char *)&g_021AA860) + 0xc);
    *(unsigned char *)(q + 0x1f) = 0;
}




#define FL (s_bNeedCloseStatsConnection.fl)





void DWCi_UpdateFriendReq(DWCstAccFriendData *friendList, int friendListLen)
{
    GPBuddyStatus status;
    char userName[21];
    int numBuddy;
    int i;
    int j;
    int profileID;

    if (FL->reason == 0) {
        DWCi_HandleGPError(gpGetNumBuddies(FL->connection, &numBuddy));
        i = 0;
        for (; i < numBuddy; ) {
            DWCi_HandleGPError(gpGetBuddyStatus(FL->connection, i, &status));
            for (j = 0; j < friendListLen; j++) {
                if (DWCi_GetProfileIDFromList(j) == status.profile) {
                    if (DWCi_IsBuddyFriendData(&friendList[j]) != 0)
                        goto after;
                    DWC_SetGsProfileId(&friendList[j], status.profile);
                    DWCi_SetBuddyFriendData(&friendList[j]);
                    if (DWC_IsBuddyFriendData(&FL->list[j]) != 0)
                        DWCi_SetExpIsBuddyFriendFlag(&FL->list[j], 1);
                    FL->field1d = 1;
                    goto after;
                }
            }
        after:
            if (j == friendListLen) {
                DWCi_HandleGPError(gpDeleteBuddy(FL->connection, status.profile));
                numBuddy--;
                i--;
            }
            i++;
        }
        FL->reason = 1;
    }

    while (FL->field1c < friendListLen) {
        if (DWCi_IsBuddyMsgAlreadySent(&friendList[FL->field1c]) != 0)
            goto next;
        profileID = DWCi_GetProfileIDFromList(FL->field1c);
        if (profileID == 0)
            goto blockB;
        if (DWCi_RefreshFriendListForth(friendList, FL->field1c, profileID) != 0)
            goto next;
        DWCi_HandleGPError(gpGetBuddyIndex(FL->connection, profileID, &i));
        if (i != -1)
            goto next;
        DWCi_GPSendBuddyRequest(profileID);
        DWCi_SetSentBuddyReqFlag(&friendList[FL->field1c], 1);
        goto next;
    blockB:
        if (DWC_GetGsProfileId(DWCi_GetUserData(), &friendList[FL->field1c]) != -1)
            goto next;
        DWC_LoginIdToUserName(DWCi_GetUserData(), &friendList[FL->field1c], userName);
        gpProfileSearchA(FL->connection, 0, 0, 0, 0, userName, 0, 0,
                         DWCi_GPProfileSearchCallback, (void *)FL->field1c);
        FL->reason = 2;
        return;
    next:
        FL->field1c++;
    }
}





void func_02169568(void)
{
    (*(void (*)(int, unsigned char, int))(*(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x2c)))(
        0,
        *(unsigned char *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x1d),
        *(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x30));
    *(int *)(*(char **)(((char *)&g_021AA860) + 0xc)) = 2;
}



void func_0216959C(void *friendData, int deleteIndex, int otherIndex)
{
    if (*(char **)(((char *)&g_021AA860) + 0xc) == 0) return;
    func_02082BCC((char *)friendData + deleteIndex * 0xc, 0, 0xc);
    if (*(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x3c) == 0) return;
    (*(void (*)(int, int, int))(*(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x3c)))(
        deleteIndex, otherIndex, *(int *)(*(char **)(((char *)&g_021AA860) + 0xc) + 0x40));
}


/*
 * sdk:      DWCi_RefreshFriendListForth (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 */
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
