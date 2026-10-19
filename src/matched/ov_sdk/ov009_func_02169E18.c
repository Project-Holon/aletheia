/*
 * function: DWCi_GPGetInfoCallback_RecvAuthMessage
 * address:  0x02169E18
 * packet:   pkt_ov009_02169E18
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GPGetInfoCallback_RecvAuthMessage (libdwcmatch.TWL.HYB.a(dwc_friend.o))
 *
 * The object reads arg from r1 (GP callback: connection, arg, param); the DWARF
 * prototype lists only arg.
 *
 * symbols:
 *   DWCi_Acc_GetFlagDataTypeThunk  0x020591CC  arm
 *   DWCi_GetUserData  0x0216A39C  arm  ov009
 *   func_02059A44  0x02059A44  arm
 *   strcmp  0x020948E0  arm
 *   DWC_GetGsProfileId  0x020598EC  arm
 *   func_0205915C  0x0205915C  arm
 *   DWC_SetGsProfileId  0x02059A10  arm
 *   DWCi_SetBuddyFriendData  0x02059214  arm
 *   DWCi_RefreshFriendListAll  0x021696B0  arm  ov009
 *   DWCi_SetReverseBuddyFlag  0x02059240  arm
 *   DWC_IsBuddyFriendData  0x0205912C  arm
 *   DWCi_SetExpIsBuddyFriendFlag  0x02059270  arm
 *   DWCi_CallBuddyFriendCallback  0x02169174  arm  ov009
 *   g_021AA860  0x021AA860  data
 */

#include "../include/G_FriendGlobal.h"

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
} GPGetInfoResponseArg;

extern int DWCi_Acc_GetFlagDataTypeThunk(DWCFriendData *frienddata);
extern int DWCi_GetUserData(void);
extern void func_02059A44(void *userdata, DWCFriendData *frienddata, char *username);
extern int strcmp(const char *a, const char *b);
struct DWCstAccUserData;
extern int DWC_GetGsProfileId(struct DWCstAccUserData *userdata, void *frienddata);
extern int func_0205915C(DWCFriendData *frienddata);
extern void DWC_SetGsProfileId(void *frienddata, int gs_profile_id);
extern void DWCi_SetBuddyFriendData(DWCFriendData *frienddata);
typedef unsigned char  u8;
extern int DWCi_RefreshFriendListAll(u8 *friendList, int friendListLen, int profileID);
extern void DWCi_SetReverseBuddyFlag(void *frienddata, int setflag);
extern int DWC_IsBuddyFriendData(DWCFriendData *frienddata);
extern void DWCi_SetExpIsBuddyFriendFlag(void *frienddata, int setflag);
extern void DWCi_CallBuddyFriendCallback(int index);
extern struct FriendGlobal g_021AA860;

void DWCi_GPGetInfoCallback_RecvAuthMessage(void *connection, GPGetInfoResponseArg *arg)
{
    char userName[21];
    int index;
    int i;
    int listChanged = 0;
    int alreadyBuddy = 0;

    if (arg->result != 0)
        return;
    for (i = 0; i < ((DWCFriendControl *)g_021AA860.ctl)->friendListLen; i++) {
        if (DWCi_Acc_GetFlagDataTypeThunk(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]) == 1) {
            func_02059A44((void *)DWCi_GetUserData(), &((DWCFriendControl *)g_021AA860.ctl)->friendList[i], userName);
            if (strcmp(userName, arg->lastname) == 0) {
                DWC_SetGsProfileId(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i], arg->profile);
                DWCi_SetBuddyFriendData(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]);
                listChanged = 1;
            }
        } else if (DWCi_Acc_GetFlagDataTypeThunk(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]) == 3
                   || DWCi_Acc_GetFlagDataTypeThunk(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]) == 2) {
            if (DWC_GetGsProfileId((struct DWCstAccUserData *)DWCi_GetUserData(), &((DWCFriendControl *)g_021AA860.ctl)->friendList[i]) == arg->profile) {
                if (func_0205915C(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]) == 1)
                    alreadyBuddy = 1;
                else {
                    DWC_SetGsProfileId(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i], arg->profile);
                    DWCi_SetBuddyFriendData(&((DWCFriendControl *)g_021AA860.ctl)->friendList[i]);
                    listChanged = 1;
                }
            }
        }
    }
    if (!listChanged)
        return;
    index = DWCi_RefreshFriendListAll((u8 *)((DWCFriendControl *)g_021AA860.ctl)->friendList, ((DWCFriendControl *)g_021AA860.ctl)->friendListLen, arg->profile);
    if (!alreadyBuddy) {
        DWCi_SetReverseBuddyFlag(&((DWCFriendControl *)g_021AA860.ctl)->friendList[index], 1);
        if (DWC_IsBuddyFriendData(&((DWCFriendControl *)g_021AA860.ctl)->friendList[index]))
            DWCi_SetExpIsBuddyFriendFlag(&((DWCFriendControl *)g_021AA860.ctl)->friendList[index], 1);
        DWCi_CallBuddyFriendCallback(index);
    }
    ((DWCFriendControl *)g_021AA860.ctl)->buddyUpdated = 1;
}
