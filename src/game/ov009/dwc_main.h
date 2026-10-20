#ifndef GAME_OV009_DWC_MAIN_H
#define GAME_OV009_DWC_MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_main.c, prototypes copied from their definitions. */

struct GTI2Connection;

#include "../arm9/dwc_account.h"
#include "../types.h"
#include "../ov009/dwc_match_ctl_types.h"
#include "../ov009/gpi_types.h"

void DWC_InitFriendsMatch(DWCstAccUserData *userdata, int productID, char *secretKey, int sendBufSize, int recvBufSize, void *friendList, int friendListLen);
void DWC_ShutdownFriendsMatch(void);
void DWC_ProcessFriendsMatch(void);
int DWC_LoginAsync(u16 *ingamesn, int reserved, void (*callback)(int, int, void *), void *param);
int DWC_UpdateServersAsync(int unused, void *updateCallback, void *updateParam, void *statusCallback, void *statusParam, void *deleteCallback, void *deleteParam);
int DWC_ConnectToAnybodyAsync(int topology, unsigned char maxEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
int DWC_SetupGameServer(int topology, unsigned char maxEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
int DWC_ConnectToGameServerAsync(int topology, int serverIndex, void (*matchedCallback)(int, int, int, int, int, void *), void *matchedParam, void (*newClientCallback)(int, void *), void *newClientParam, int (*attemptCallback)(unsigned char *, void *), unsigned char *connectionUserData, void *attemptParam);
int DWC_SetConnectionClosedCallback(MatchedCallback callback, void *param);
int DWC_CloseAllConnectionsHard(void);
int DWC_CloseConnectionHardFromServer(unsigned char aid);
int DWC_GetNumConnectionHost(void);
unsigned char DWC_GetMyAID(void);
int DWC_GetAIDList(unsigned char **out);
int DWC_GetAIDBitmap(void);
int DWC_IsValidAID(unsigned char aid);
int DWC_GetState(void);
unsigned char DWC_GetServerAID(void);
int DWC_IsServerMyself(void);
int DWCi_GT2Startup(void);
void *DWCi_GetGT2Connection(unsigned char aid);
int DWCi_GetConnectionAID(void *connection);
int DWCi_GT2GetConnectionListIdx(void);
void DWCi_ClearGT2ConnectionList(void);
void **DWCi_GetGT2ConnectionByIdx(int i);
void **DWCi_GetGT2ConnectionByProfileID(int pid, int flag);
void *DWCi_GetConnectionInfoByIdx(int i);
int DWCi_IsValidAID(unsigned char aid);
void DWCi_SetState(int v);
int DWCi_DeleteAID(unsigned char aid);
int DWCi_GetAIDBitmapFromList(unsigned char *p, int n);
int DWCi_CloseConnectionHard(unsigned char aid);
void DWCi_LoginCallback(int error, int profileID, void *param);
void DWCi_UpdateServersCallback(int error, int isChanged);
void DWCi_MatchedCallback(int error, int cancel, int self, int isServer, int index, void *param);
void DWCi_GPErrorCallback(void **pconnection, void *arg, void *param);
void DWCi_GPRecvBuddyMessageCallback(void **pconnection, GPRecvBuddyMessageArg *arg);
void DWCi_GT2ReceivedCallback(void *connection, unsigned char *message, int size, int reliable);
void DWCi_GT2ClosedProcess(struct GTI2Connection *connection, int reason, int isPseudClose, unsigned char closeAid);
void DWCi_GT2ClosedCallback(void *connection, int reason);
void DWCi_GT2PingCallback(void *connection, int latency);
void DWCi_GT2SocketErrorCallback(void *socket);
void DWCi_CustomCommonInit(unsigned char v);
unsigned char DWCi_GetServerOrSubServerAID(void);
int DWCi_IsGetAIDValid(void);
/* END mkheaders: generated region */

#endif
