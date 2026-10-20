#ifndef GAME_ARM9_DWC_ACCOUNT_H
#define GAME_ARM9_DWC_ACCOUNT_H

/* Public functions of dwc_account.c, prototypes copied from their definitions. */

struct DWCstAccFriendKeyData;
struct DWCstAccGsProfileIdData;

typedef struct DWCstAccLoginId
{
    unsigned long id_data;
    unsigned long userid_lo32;
    unsigned long playerid;
} DWCstAccLoginId;

typedef struct DWCstAccUserData
{
    unsigned long size;
    DWCstAccLoginId pseudo;
    DWCstAccLoginId authentic;
    int gs_profile_id;
    unsigned long flag;
    unsigned long gamecode;
    unsigned long reserved[5];
    unsigned long crc32;
} DWCstAccUserData;

#include "../types.h"

int DWCi_Acc_SetMaskBits(unsigned long *ptr, unsigned long data, unsigned long shift, unsigned long mask);
unsigned long long DWCi_Acc_GetUserId(struct DWCstAccLoginId *loginId);
unsigned long DWCi_Acc_GetPlayerId(struct DWCstAccLoginId *loginId);
unsigned long long DWCi_Acc_GetFriendKey(struct DWCstAccFriendKeyData *data);
int DWCi_Acc_GetGsProfileId(struct DWCstAccGsProfileIdData *data);
void DWCi_Acc_SetUserId(struct DWCstAccLoginId *loginId, unsigned long long userId);
void DWCi_Acc_SetPlayerId(struct DWCstAccLoginId *loginId, int playerId);
void DWCi_Acc_SetFriendKey(struct DWCstAccFriendKeyData *data, unsigned long long friendKey);
void DWCi_Acc_SetGsProfileId(struct DWCstAccGsProfileIdData *data, int gsProfileId);
unsigned long DWCi_Acc_GetFlag_DataType(void *userdata);
BOOL DWC_IsBuddyFriendData(void *frienddata);
int DWCi_IsBuddyFriendData(void *frienddata);
int DWCi_IsReverseBuddyFriendData(void *frienddata);
int DWCi_IsBuddyMsgAlreadySent(void *frienddata);
unsigned long DWCi_Acc_GetFlagDataTypeThunk(void *userdata);
void DWCi_Acc_SetFlags(void *userdata, unsigned long flags);
void DWCi_Acc_SetFlag_DataType(void *userdata, int type);
void DWCi_SetReverseBuddyFlag(void *frienddata, int setflag);
void DWCi_SetExpIsBuddyFriendFlag(void *frienddata, int setflag);
void DWCi_SetSentBuddyReqFlag(void *frienddata, int setflag);
unsigned long long DWC_Acc_CreateFriendKey(int gs_profile_id, unsigned long gamecode, int method);
int DWC_CheckFriendKey(struct DWCstAccUserData *userdata, unsigned long long friendKey);
int DWC_Acc_CheckFriendKey(unsigned long long friendkey, unsigned long gamecode, int method);
int DWC_Acc_FriendKeyToGsProfileId(unsigned long long friendkey, unsigned long gamecode);
void DWCi_Acc_U64ToString32(unsigned long long num, int bitnum, char *result);
void DWCi_Acc_LoginIdToUserName(struct DWCstAccLoginId *loginid, unsigned long gamecode, char *username);
void DWCi_Acc_CreateUserData(struct DWCstAccUserData *userdata, unsigned long gamecode);
void DWCi_Acc_CreateTempLoginId(struct DWCstAccLoginId *loginid);
int DWCi_Acc_CheckConsoleUserId(struct DWCstAccLoginId *loginid);
int DWCi_Acc_IsValidLoginId(void *loginid);
int DWCi_Acc_IsAuthentic(void *userdata);
int DWC_IsValidFriendData(void *frienddata);
int DWCi_Acc_IsValidFriendDataThunk(void *frienddata);
void DWC_CreateUserData(void *userdata);
int DWC_CheckUserData(struct DWCstAccUserData *userdata);
int DWC_CheckValidConsole(struct DWCstAccUserData *userdata);
int DWC_CheckHasProfile(struct DWCstAccUserData *userdata);
void DWCi_Acc_SetLoginIdToUserData(struct DWCstAccUserData *userdata, struct DWCstAccLoginId *loginid, int gs_profile_id);
int DWC_CheckDirtyFlag(void *userdata);
int DWCi_Acc_IsDirty(void *userdata);
void DWC_ClearDirtyFlag(struct DWCstAccUserData *userdata);
void DWCi_Acc_ClearDirty(struct DWCstAccUserData *userdata);
unsigned long long DWC_GetFriendKey(void *frienddata);
int DWC_GetGsProfileId(struct DWCstAccUserData *userdata, void *frienddata);
unsigned long long DWC_CreateFriendKey(struct DWCstAccUserData *userdata);
void DWC_CreateFriendKeyToken(void *token, unsigned long long friend_key);
void DWC_CreateExchangeToken(struct DWCstAccUserData *userdata, void *token);
void DWC_SetGsProfileId(void *frienddata, int gs_profile_id);
void DWC_LoginIdToUserName(struct DWCstAccUserData *userdata, void *frienddata, char *username);
int DWC_IsEqualFriendData(void *frienddata1, void *frienddata2);

#endif
