/*
 * function: DWCi_GPGetInfoCallback_RecvBuddyRequest
 * address:  0x02169BB0
 * packet:   pkt_ov009_02169BB0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GPGetInfoCallback_RecvBuddyRequest (libdwcmatch.TWL.HYB.a dwc_friend.o)
 *
 * Accessing the singleton through a `#define STATE` macro (not a local that
 * caches it) is what frees r4 for the state pointer and forces the deny block
 * to sink after the main path.
 *
 * symbols:
 *   DWC_GetFriendDataType            0x020591CC arm
 *   DWCi_GetUserData                 0x0216A39C arm ov009
 *   DWC_LoginIdToUserName            0x02059A44 arm
 *   strcmp                           0x020948E0 arm
 *   DWC_IsBuddyFriendData            0x0205912C arm
 *   gpAuthBuddyRequest               0x02185E94 arm ov009
 *   DWC_SetGsProfileId               0x02059A10 arm
 *   OS_SNPrintf                      0x02084F80 arm
 *   DWC_GetGsProfileId               0x020598EC arm
 *   memcmp                           0x020923F0 arm
 *   DWCi_GPSendBuddyRequest          0x021697D8 arm ov009
 *   DWCi_RefreshFriendListAll        0x021696B0 arm ov009
 *   DWCi_SetReverseBuddyFlag         0x02059240 arm
 *   DWCi_SetExpIsBuddyFriendFlag     0x02059270 arm
 *   DWCi_CallBuddyFriendCallback     0x02169174 arm ov009
 *   gpDenyBuddyRequest               0x02185EE4 arm ov009
 *   s_bNeedCloseStatsConnection      0x021AA860 data
 *   gDwcFriendKeyFormat                       0x021A2010 data
 */

typedef struct DWCstAccFriendData {
    char data[0xc];
} DWCstAccFriendData;

typedef struct DWCstAccUserData {
    char pad[0x24];
    unsigned int gamecode;
} DWCstAccUserData;

typedef struct GPGetInfoResponseArg {
    int field0;
    int field4;
    char pad8[0x8e - 8];
    char userName[9];
    char gamecode[4];
} GPGetInfoResponseArg;

typedef struct FriendList {
    char pad0[0x14];
    int count;
    DWCstAccFriendData *list;
    char pad1[0x1d - 0x1c];
    unsigned char field1d;
} FriendList;

typedef struct FriendState {
    char pad0[0xc];
    FriendList *fl;
} FriendState;

extern int DWC_GetFriendDataType(DWCstAccFriendData *frienddata);
extern DWCstAccUserData *DWCi_GetUserData(void);
extern void DWC_LoginIdToUserName(DWCstAccUserData *userdata, DWCstAccFriendData *frienddata, char *username);
extern int strcmp(char *s1, char *s2);
extern int DWC_IsBuddyFriendData(DWCstAccFriendData *frienddata);
extern int gpAuthBuddyRequest(void **connection, int profile);
extern void DWC_SetGsProfileId(DWCstAccFriendData *frienddata, int gs_profile_id);
extern int OS_SNPrintf(char *dst, unsigned long len, char *fmt, ...);
extern int DWC_GetGsProfileId(DWCstAccUserData *userdata, DWCstAccFriendData *frienddata);
extern int memcmp(void *p1, void *p2, unsigned long size);
extern int DWCi_GPSendBuddyRequest(int profileID);
extern int DWCi_RefreshFriendListAll(DWCstAccFriendData *friendList, int friendListLen, int profileID);
extern void DWCi_SetReverseBuddyFlag(DWCstAccFriendData *frienddata, int setflag);
extern void DWCi_SetExpIsBuddyFriendFlag(DWCstAccFriendData *frienddata, int setflag);
extern void DWCi_CallBuddyFriendCallback(int index);
extern int gpDenyBuddyRequest(void **connection, int profile);
extern char s_bNeedCloseStatsConnection[];
extern char gDwcFriendKeyFormat[];

#define STATE ((FriendState *)s_bNeedCloseStatsConnection)

static void DWCi_GPGetInfoCallback_RecvBuddyRequest(void **connection, GPGetInfoResponseArg *arg)
{
    int i;
    int confirm = 0;
    int alreadyBuddy = 0;
    int index;
    unsigned int gamecode;
    char userName[21];
    char gamecode_str[5];

    if (arg->field0 != 0)
        return;

    for (i = 0; i < STATE->fl->count; i++) {
        if (DWC_GetFriendDataType(&STATE->fl->list[i]) == 1) {
            DWC_LoginIdToUserName(DWCi_GetUserData(), &STATE->fl->list[i], userName);
            if (strcmp(userName, arg->userName) != 0)
                continue;
            if (DWC_IsBuddyFriendData(&STATE->fl->list[i]))
                alreadyBuddy = 1;
            gpAuthBuddyRequest(connection, arg->field4);
            DWC_SetGsProfileId(&STATE->fl->list[i], arg->field4);
            confirm = 1;
        } else if (DWC_GetFriendDataType(&STATE->fl->list[i]) == 3 || DWC_GetFriendDataType(&STATE->fl->list[i]) == 2) {
            gamecode = DWCi_GetUserData()->gamecode;
            OS_SNPrintf(gamecode_str, 5, gDwcFriendKeyFormat, (gamecode >> 24) & 0xff, (gamecode >> 16) & 0xff, (gamecode >> 8) & 0xff, gamecode & 0xff);
            if (DWC_GetGsProfileId(DWCi_GetUserData(), &STATE->fl->list[i]) != arg->field4)
                continue;
            if (memcmp(gamecode_str, arg->gamecode, 4) != 0)
                continue;
            if (DWC_IsBuddyFriendData(&STATE->fl->list[i]))
                alreadyBuddy = 1;
            gpAuthBuddyRequest(connection, arg->field4);
            confirm = 1;
        }
    }

    if (confirm != 0) {
        DWCi_GPSendBuddyRequest(arg->field4);
        index = DWCi_RefreshFriendListAll(STATE->fl->list, STATE->fl->count, arg->field4);
        DWCi_SetReverseBuddyFlag(&STATE->fl->list[index], 1);
        if (!DWC_IsBuddyFriendData(&STATE->fl->list[index]))
            return;
        DWCi_SetExpIsBuddyFriendFlag(&STATE->fl->list[index], 1);
        if (alreadyBuddy)
            return;
        DWCi_CallBuddyFriendCallback(index);
        STATE->fl->field1d = 1;
    } else {
        gpDenyBuddyRequest(connection, arg->field4);
    }
}
