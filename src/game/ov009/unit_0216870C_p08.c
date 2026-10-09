/*
 * file:     unit_0216870C_p08.c
 * unit:     yes
 * function: DWCi_GPGetInfoCallback_RecvBuddyRequest, func_02169E18, func_02169FE4
 * address:  0x02169BB0
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
 *   g_021A2010                       0x021A2010 data
 *   func_020591CC  0x020591CC  arm
 *   func_0216A39C  0x0216A39C  arm  ov009
 *   func_02059A44  0x02059A44  arm
 *   func_020948E0  0x020948E0  arm
 *   func_020598EC  0x020598EC  arm
 *   func_0205915C  0x0205915C  arm
 *   func_02059A10  0x02059A10  arm
 *   func_02059214  0x02059214  arm
 *   func_021696B0  0x021696B0  arm  ov009
 *   func_02059240  0x02059240  arm
 *   func_0205912C  0x0205912C  arm
 *   func_02059270  0x02059270  arm
 *   func_02169174  0x02169174  arm  ov009
 *   g_021AA860  0x021AA860  data
 */
#include "../../matched/include/G_FriendGlobal.h"

struct DWCstAccUserData;
typedef struct DWCstAccFriendData {
    char data[0xc];
} DWCstAccFriendData;

typedef struct DWCstAccUserData {
    char pad[0x24];
    unsigned int gamecode;
} DWCstAccUserData;

typedef struct GPGetInfoResponseArg_02169BB0 {
    int field0;
    int field4;
    char pad8[0x8e - 8];
    char userName[9];
    char gamecode[4];
} GPGetInfoResponseArg_02169BB0;

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

typedef struct {
    unsigned char data[12];
} DWCFriendData;

typedef struct {
    char pad0[0x14];
    int friendListLen;
    DWCFriendData *friendList;
    unsigned char pad1c;
    unsigned char buddyUpdated;
} DWCFriendControl;

typedef struct {
    int result;
    int profile;
    char nick[31];
    char uniquenick[21];
    char email[51];
    char firstname[31];
    char lastname[31];
} GPGetInfoResponseArg_0216870C;

typedef unsigned char  u8;

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
extern int func_020591CC(DWCFriendData *frienddata);
extern int func_0216A39C(void);
extern void func_02059A44(void *userdata, DWCFriendData *frienddata, char *username);
extern int func_020948E0(const char *a, const char *b);
extern int func_020598EC(struct DWCstAccUserData *userdata, void *frienddata);
extern int func_0205915C(DWCFriendData *frienddata);
extern void func_02059A10(void *frienddata, int gs_profile_id);
extern void func_02059214(DWCFriendData *frienddata);
extern int func_021696B0(u8 *friendList, int friendListLen, int profileID);
extern void func_02059240(void *frienddata, int setflag);
extern int func_0205912C(DWCFriendData *frienddata);
extern void func_02059270(void *frienddata, int setflag);
extern void func_02169174(int index);
/* * sdk: DWCi_GPGetInfoCallback_RecvAuthMessage (libdwcmatch.TWL.HYB.a(dwc_friend.o)) * * The object reads arg from r1 (GP callback: connection, arg, param); the DWARF * prototype lists only arg. */ void func_02169E18(void *connection, GPGetInfoResponseArg_0216870C *arg);
/* * The word at +0x20 of the block held at +0xc of the module state block. */ int func_02169FE4(void);
extern char s_bNeedCloseStatsConnection[];
extern char g_021A2010[];
extern struct FriendGlobal g_021AA860;


#define STATE ((FriendState *)s_bNeedCloseStatsConnection)


static void DWCi_GPGetInfoCallback_RecvBuddyRequest(void **connection, GPGetInfoResponseArg_02169BB0 *arg)
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
            OS_SNPrintf(gamecode_str, 5, g_021A2010, (gamecode >> 24) & 0xff, (gamecode >> 16) & 0xff, (gamecode >> 8) & 0xff, gamecode & 0xff);
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



/*
 * sdk:      DWCi_GPGetInfoCallback_RecvAuthMessage (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * The object reads arg from r1 (GP callback: connection, arg, param); the DWARF
 * prototype lists only arg.
 */
void func_02169E18(void *connection, GPGetInfoResponseArg_0216870C *arg)
{
    char userName[21];
    int index;
    int i;
    int listChanged = 0;
    int alreadyBuddy = 0;

    if (arg->result != 0)
        return;
    for (i = 0; i < ((DWCFriendControl *)g_021AA860.ctl)->friendListLen; i++) {
        if (func_020591CC(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]) == 1) {
            func_02059A44((void *)func_0216A39C(), &((DWCFriendControl *)g_021AA860.ctl)->friendList[i], userName);
            if (func_020948E0(userName, arg->lastname) == 0) {
                func_02059A10(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i], arg->profile);
                func_02059214(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]);
                listChanged = 1;
            }
        } else if (func_020591CC(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]) == 3
                   || func_020591CC(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]) == 2) {
            if (func_020598EC((struct DWCstAccUserData *)func_0216A39C(), &((DWCFriendControl *)g_021AA860.ctl)->friendList[i]) == arg->profile) {
                if (func_0205915C(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]) == 1)
                    alreadyBuddy = 1;
                else {
                    func_02059A10(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i], arg->profile);
                    func_02059214(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]);
                    listChanged = 1;
                }
            }
        }
    }
    if (!listChanged)
        return;
    index = func_021696B0((u8 *)((DWCFriendControl *)g_021AA860.ctl)->friendList, ((DWCFriendControl *)g_021AA860.ctl)->friendListLen, arg->profile);
    if (!alreadyBuddy) {
        func_02059240(&((DWCFriendControl *)g_021AA860.ctl)->friendList[index], 1);
        if (func_0205912C(&((DWCFriendControl *)g_021AA860.ctl)->friendList[index]))
            func_02059270(&((DWCFriendControl *)g_021AA860.ctl)->friendList[index], 1);
        func_02169174(index);
    }
    ((DWCFriendControl *)g_021AA860.ctl)->buddyUpdated = 1;
}



/*
 * The word at +0x20 of the block held at +0xc of the module state block.
 */
int func_02169FE4(void)
{
    int blk = *(int *)(((char *)&g_021AA860) + 0xc);

    return *(int *)(blk + 0x20);
}
