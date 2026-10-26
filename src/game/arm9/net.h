#ifndef GAME_ARM9_NET_H
#define GAME_ARM9_NET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of net.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../arm9/net_types.h"
#include "../arm9/net_types.h"

void GFL_NET_SetupHeaps(u32 parentHeapId, u32 zero, u32 oldBaseHeapId, u32 newBaseHeapId);
void GFL_NET_StartSession(GFLNetInitializeStruct *req, GFLNetUserFunc callback, void *work);
int GFL_NET_GetRunState(void);
int GFL_NET_IsSessionNull(void);
void GFL_NET_EndSession(void);
int GFL_NET_Exit(GFLNetUserFunc exitCallback);
void GFL_NET_ClearExitFlag(void);
void *GFL_NET_GetScanResult(u32 index);
void *GFL_NET_GetScanResultMac(u32 index);
u32 GFL_NET_Main(void);
void GFL_NET_RequestDisconnect(void);
void GFL_NET_ConnectMacAddressParent(void *context);
void GFL_NET_ConnectMacAddressChild(void *context);
void GFL_NET_BeaconScanStart(void);
void GFL_NET_StartByNetType(void);
void GFL_NET_StartChangeoverEx(GFLNetUserFunc onFinished, void (*onResult)(void *, int), GFLNetUserFunc onReady);
void GFL_NET_SetGameKindOverride(int gameKind);
void GFL_NET_IRC_WIRELESS_GetMacAddress(void *dst, u32 slot);
void GFL_NET_IRC_WIRELESS_SetSessionParam(NetIrcFilterFn value);
void GFL_NET_IRC_WIRELESS_Exit(void);
void GFL_NET_StartChangeoverChild(GFLNetUserFunc changeoverParam);
void GFL_NET_EndDeviceWrapper(int unused);
void GFL_NET_StartChangeoverParent(GFLNetUserFunc changeoverParam);
void GFL_NET_SetDeviceModeIfRunning(int mode);
void GFL_NET_SetChangeoverModeWrapper(u32 mode, u32 flags, u8 *macAddr);
u32 GFL_NET_IRC_WIRELESS_Step(void);
void GFL_NET_IRC_WIRELESS_SetRetryRequest(int retryRequest);
int GFL_NET_IRC_WIRELESS_GetRetryCount(void);
void GFL_NET_SetLinkTimeout(u32 frames);
u8 GFL_NET_GetHandleNetID(GFLNetHandle *handle);
int GFL_NET_GetNegotiationNum(void);
u32 GFL_NET_IsConnectMember(u32 index);
void GFL_NET_SetAcceptConnection(void *unusedArg, void *eventArg);
u32 GFL_NET_IsIdle(void);
void GFL_NET_SetIconPos(u16 iconX, u16 iconY);
u32 GFL_NET_IsNetTypeBeacon(void);
u32 GFL_NET_IsNetTypeWifi(void);
void GFL_NET_RefreshWmIcon(void);
void GFL_NET_RefreshWmIconAtTopRight(u32 restartParamA, u32 restartParamB);
u32 GFL_NET_IsParentAid(void);
u32 GFL_NET_IsHandleReady(GFLNetHandle *handle);
int GFL_NET_SendToHandle(GFLNetHandle *handle, u32 command, u32 size, const void *data);
u32 GFL_NET_SendData(GFLNetHandle *handle, u32 sendId, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);
u32 GFL_NET_SendDataMask(GFLNetHandle *handle, u32 targetMask, u32 command, u32 size, const void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);
int GFL_NET_ResetSendQueue(void);
int GFL_NET_IsSendQueueEntryOfHandle(GFLNetHandle *handle, u32 command);
void GFL_NET_StartTimingSync(GFLNetHandle *handle, u16 tag);
u32 GFL_NET_CheckTimingSync(GFLNetHandle *handle, u32 timingNo);
void GFL_NET_SetGameKind(int gameKind, int unused);
u32 GFL_NET_GetGameKind(void);
void *GFL_NET_GetWifiUserData(void);
void *GFL_NET_GetFriendList(void);
u32 GFL_NET_GetFriendListNum(void);
void GFL_NET_SetWaitMode(u32 waitMode);
void *GFL_NET_GetUserArg(void);
void GFL_NET_SetUserArg(void *userArg);
u32 GFL_NET_GetMaxConnectNum(void);
u32 GFL_NET_GetChildSendSize(void);
u32 GFL_NET_GetParentSendSize(void);
void GFL_NET_CallDeviceReadyFunc(void);
void GFL_NET_CallErrorStateFunc(u32 errorCode);
void GFL_NET_CallStateChangeFunc(u32 newState);
GFLNetSession *GFL_NET_GetSession(void);
GFLNetSession *GFL_NET_GetInitParam(void);
void GFL_NET_SetAutoExit(u8 autoExit);
void GFL_NET_SetLoginOption(u8 loginOption);
void *GFL_NET_AllocAligned(u32 heapId, u32 size, const char *fileName, u16 line);
void GFL_NET_FreeAligned(void *block);
void GFL_NET_SetIrcParams(u32 paramA, u32 paramB);
void GFL_NET_GetIrcParams(u32 *outParamA, u32 *outParamB);
void GFL_NET_CopyInitParam(void *dst);
void GFL_NET_ClearBeaconCallbacks(void);
u32 GFL_NET_CheckError(void);
void GFL_NET_RefreshWmIconAt(u32 iconX, u32 iconY);
void GFL_NET_RefreshWmIconAtOrigin(void);
void GFL_NET_SetErrorCheckEnabled(u32 enable);
/* END mkheaders: generated region */

#endif
