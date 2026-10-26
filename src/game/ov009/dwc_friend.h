#ifndef GAME_OV009_DWC_FRIEND_H
#define GAME_OV009_DWC_FRIEND_H

typedef struct FriendCnt FriendCnt;
typedef struct RecvArg RecvArg;

#include "../arm9/dwc_account.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_friend.c, prototypes copied from their definitions. */

struct FriendCnt;
struct RecvArg;
typedef struct FriendCnt FriendCnt;
typedef struct RecvArg RecvArg;

#include "../types.h"
#include "../ov009/gpi_types.h"

u8 DWC_GetFriendStatus(sptr a, sptr b);
u8 DWC_GetFriendStatusSC(void *friendData, u8 *maxEntry, u8 *numEntry, char *statusString);
unsigned char DWC_GetFriendStatusData(void *p, char *a, int *b);
unsigned char DWC_GetFriendStatusDataSC(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size);
int DWC_SetOwnStatusData(char *statusData, unsigned long size);
int DWC_SetBuddyFriendCallback(void (*callback)(int, void *), void *param);
void DWCi_FriendInit(FriendCnt *friendCnt, void **pGpObj, unsigned short *playerName, DWCstAccFriendData *friendList, int friendListLen);
void DWCi_FriendProcess(void);
int DWCi_IsServerUpdating(void);
void DWCi_UpdateServersAsync(char *authToken, char *partnerChallenge, void (*finishCallback)(int, u8, int), int finishParam, void (*statusCallback)(int, u8, char *, void *), void *statusParam, void (*deleteCallback)(int, int, int), int deleteParam);
void DWCi_StopFriendProcess(int error, int errorCode);
void DWCi_GPRecvBuddyRequestCallback(void **connection, void *arg, void *param);
int DWCi_GPRecvBuddyAuthCallback(void **connection, void *arg, void *param);
void DWCi_GPRecvBuddyStatusCallback(void **connection, void *arg, void *param);
int DWCi_GetProfileIDFromList(int index);
int DWCi_GetFriendListIndex(int pid);
void DWCi_InitGPProcessCount(void);
int DWCi_SetGPStatus(int status, const char *statusString, const char *locString);
void DWCi_CallBuddyFriendCallback(int index);
void DWCi_ShutdownFriend(void);
int DWCi_GPProcess(void);
void DWCi_CloseFriendProcess(void);
void DWCi_EndUpdateServers(void);
void DWCi_DeleteFriendFromList(void *friendData, int deleteIndex, int otherIndex);
int DWCi_GPSendBuddyRequest(int profileID);
int DWCi_GetFriendBuddyStatus(void *friendData, GPBuddyStatus *status);
void DWCi_GPProfileSearchCallback(void **connection, void *argv, void *param);
void DWCi_GPGetInfoCallback_RecvAuthMessage(void **connection, void *argv, void *param);
int DWCi_GetPersCallbackLevel(void);
void DWCi_BeginCloseStatsConnection(void);
void DWCi_EndCloseStatsConnection(void);
void DWCi_GetReverseBuddiesCallback(void **connection, void *argv, void *param);
/* END mkheaders: generated region */

#endif
