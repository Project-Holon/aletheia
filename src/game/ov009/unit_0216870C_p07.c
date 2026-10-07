/*
 * file:     unit_0216870C_p07.c
 * unit:     yes
 * function: func_021692C4, func_02169568
 * address:  0x021692C4
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
 *   g_021AA860  0x021AA860  data
 */
#include "../../matched/include/G_FriendGlobal.h"

#define FL (s_bNeedCloseStatsConnection.fl)
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
void DWCi_UpdateFriendReq(DWCstAccFriendData *friendList, int friendListLen);
void func_02169568(void);
extern FriendState s_bNeedCloseStatsConnection;
extern struct FriendGlobal g_021AA860;


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
