#ifndef GAME_OV009_DWC_FRIEND_H
#define GAME_OV009_DWC_FRIEND_H

/* Public functions of dwc_friend.c, prototypes copied from their definitions. */

struct FriendCnt;
struct RecvArg;
typedef struct FriendCnt FriendCnt;
typedef struct RecvArg RecvArg;

u8 DWC_GetFriendStatus(int a, int b);
u8 DWC_GetFriendStatusSC(void *friendData, u8 *maxEntry, u8 *numEntry, char *statusString);
unsigned char DWC_GetFriendStatusData(void *p, int a, int b);
unsigned char DWC_GetFriendStatusDataSC(void *friendData, unsigned char *maxEntry, unsigned char *numEntry, char *statusData, int *size);
int DWC_SetOwnStatusData(char *statusData, unsigned long size);
int DWC_SetBuddyFriendCallback(void (*callback)(int, void *), void *param);
void DWCi_FriendInit(FriendCnt *friendCnt, int pGpObj, int userData, int friendList, int friendListLen);
void DWCi_FriendProcess(void);
int DWCi_IsServerUpdating(void);
void DWCi_UpdateServersAsync(int authToken, int partnerChallenge, void (*finishCallback)(int, u8, int), int finishParam, void (*statusCallback)(int, u8, char *, void *), void *statusParam, void (*deleteCallback)(int, int, int), int deleteParam);
void DWCi_StopFriendProcess(int error, int errorCode);
void DWCi_GPRecvBuddyRequestCallback(void **connection, int *arg);
int DWCi_GPRecvBuddyAuthCallback(void **connection, int *arg);
void DWCi_GPRecvBuddyStatusCallback(void **connection, RecvArg *arg);
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
void DWCi_GPProfileSearchCallback(void **connection, void *argv, void *param);
void DWCi_GPGetInfoCallback_RecvAuthMessage(void **connection, void *argv, void *param);
int DWCi_GetPersCallbackLevel(void);
void DWCi_BeginCloseStatsConnection(void);
void DWCi_EndCloseStatsConnection(void);
void DWCi_GetReverseBuddiesCallback(void **connection, void *argv, void *param);

#endif
