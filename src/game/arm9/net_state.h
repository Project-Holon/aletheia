#ifndef GAME_ARM9_NET_STATE_H
#define GAME_ARM9_NET_STATE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of net_state.c, prototypes copied from their definitions. */

struct NetStateWork;

#include "../types.h"
#include "../arm9/net_types.h"

void GFL_NET_STATE_ChangeState(struct NetStateWork *work, void *state, u32 timer);
void GFL_NET_STATE_ChangeStateDebug(struct NetStateWork *work, void *state, u32 timer, int line);
void GFL_NET_STATE_InitWork(u32 heapId);
void GFL_NET_STATE_FreeWork(struct NetStateWork *work);
void GFL_NET_STATE_DeviceInitialized(struct NetStateWork *work);
void GFL_NET_STATE_DeviceInitialize(u32 heapId, GFLNetUserFunc initCallback);
void GFL_NET_STATE_ConnectMacDone(void);
void GFL_NET_STATE_ExtendConnectTimer(void);
void GFL_NET_STATE_ConnectMac(struct NetStateWork *work);
void GFL_NET_STATE_StartConnectMac(void);
void GFL_NET_STATE_ConnectMacAddress(void *mac, int anyParent);
void GFL_NET_STATE_BeaconScanIdle(void);
void GFL_NET_STATE_StartBeaconScan(void);
void GFL_NET_STATE_BeaconScan(void);
u32 GFL_NET_STATE_Main(void);
void GFL_NET_STATE_ParentConnected(void);
void GFL_NET_STATE_ParentWait(void);
int GFL_NET_STATE_ParentConnectCallback(void);
void GFL_NET_STATE_StartParent(void);
void GFL_NET_STATE_ChangeParentWait(int heapId);
void GFL_NET_STATE_InitParent(u32 unused);
u32 GFL_NET_STATE_RollChildWaitTime(struct NetStateWork *work);
u32 GFL_NET_STATE_RollParentWaitTime(struct NetStateWork *work);
void GFL_NET_STATE_ChangeoverConnect(struct NetStateWork *work);
void GFL_NET_STATE_ChangeoverWaitDevice(void);
void GFL_NET_STATE_ChangeoverStopParent(void);
void GFL_NET_STATE_ChangeoverStopParentRetry(void);
void GFL_NET_STATE_ChangeoverParentConnectWait(struct NetStateWork *work);
void GFL_NET_STATE_ChangeoverParentMain(struct NetStateWork *work);
void GFL_NET_STATE_ChangeoverParentRestart(struct NetStateWork *work);
int GFL_NET_STATE_ChangeoverParentCallback(void);
void GFL_NET_STATE_ChangeoverStartParent(struct NetStateWork *work);
void GFL_NET_STATE_ChangeoverChildNegotiation(void);
void GFL_NET_STATE_ChildNegotiationWait(struct NetStateWork *work);
void GFL_NET_STATE_ParentNegotiationWait(struct NetStateWork *work);
void GFL_NET_STATE_ChangeoverChildConnected(struct NetStateWork *work);
void GFL_NET_STATE_ChangeoverStopChild(void);
void GFL_NET_STATE_ChangeoverChildMain(struct NetStateWork *work);
void GFL_NET_STATE_ChangeoverChildScan(struct NetStateWork *work);
void GFL_NET_STATE_StartChangeover(u16 unusedArg, GFLNetUserFunc initCallback, u8 hasMac);
void GFL_NET_STATE_ChangeoverRestart(struct NetStateWork *work);
void GFL_NET_STATE_ChangeChangeoverMode(u8 mode, u8 hasMac, const void *mac);
void GFL_NET_STATE_ChangeoverStopChildDevice(struct NetStateWork *work);
void GFL_NET_STATE_SetChangeoverMode(u32 mode, u32 hasMac, u8 *mac);
void GFL_NET_STATE_WaitDisconnect(void);
void GFL_NET_STATE_RecvExitCommand(u32 netID, u32 size, void *data, void *work, struct GFLNetHandle *handle);
u32 GFL_NET_STATE_ExitIfChild(void);
void GFL_NET_STATE_ExitWait(struct NetStateWork *work);
void GFL_NET_STATE_ExitStopDevice(void);
void GFL_NET_STATE_Exit(NetStateExitFunc exitCallback);
void GFL_NET_STATE_ClearExitFlag(void);
void GFL_NET_STATE_Idle(void);
void GFL_NET_STATE_EndDevice(void);
GFLNetSession *GFL_NET_STATE_SetMPMode(int netID, int size, u8 *data, int work);
void GFL_NET_STATE_WifiError(void);
void GFL_NET_STATE_WifiLoggedOut(void);
void GFL_NET_STATE_WifiFatal(void);
void GFL_NET_STATE_WifiErrorWait(void);
void GFL_NET_STATE_WifiStopError(void);
void GFL_NET_STATE_SetWifiErrorCode(struct NetStateWork *work, u32 errorCode);
void GFL_NET_STATE_WifiLoginMain(struct NetStateWork *work);
void GFL_NET_STATE_WifiLoginStart(struct NetStateWork *work);
int GFL_NET_STATE_WifiEnterLogin(int loginTarget);
u32 GFL_NET_STATE_WifiEnterRandomMatch(void);
u32 GFL_NET_STATE_WifiEnterFriendMatch(void);
void GFL_NET_STATE_WifiEnterLoginDefault(void);
int GFL_NET_STATE_GetWifiState(void);
void GFL_NET_STATE_WifiConnected(void);
void GFL_NET_STATE_WifiMatchDisconnect(struct NetStateWork *work);
void GFL_NET_STATE_WifiDisconnect(u32 hasMatch);
void GFL_NET_STATE_WifiDisconnectFinal(void);
int GFL_NET_STATE_IsWifiDisconnectFinal(void);
int GFL_NET_STATE_IsWifiLoginState(void);
int GFL_NET_STATE_IsWifiLoginOrConnected(void);
void GFL_NET_STATE_WifiLogoutWait(struct NetStateWork *work);
void GFL_NET_STATE_WifiLogoutStop(void);
void GFL_NET_STATE_WifiLogout(NetStateExitFunc exitCallback);
void GFL_NET_STATE_WifiMatchWait(struct NetStateWork *work);
void GFL_NET_STATE_WifiMatchStart(void);
void GFL_NET_STATE_WifiStartMatch(void);
void GFL_NET_STATE_SetAutoExit(u8 autoExit);
void GFL_NET_STATE_SetLoginOption(u8 option);
void GFL_NET_STATE_NoProc(void);
u32 GFL_NET_STATE_SetErrorMode(u8 mode);
void GFL_NET_STATE_ClearErrorMode(void);
u32 GFL_NET_STATE_GetErrorMode(void);
void GFL_NET_STATE_SetError(int errorCode, u32 errorArg1, u32 errorArg2, u32 errorArg3);
void GFL_NET_STATE_SetWifiError(void);
NetErrorInfo *GFL_NET_STATE_GetError(void);
void GFL_NET_STATE_FatalError(void);
int GFL_NET_STATE_IsFatalError(void);
/* END mkheaders: generated region */

#endif
