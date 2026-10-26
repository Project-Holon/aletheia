#ifndef GAME_OV014_NET_WHPIPE_H
#define GAME_OV014_NET_WHPIPE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of net_whpipe.c, prototypes copied from their definitions. */

#include "../arm9/net_whpipe_types.h"
#include "../arm9/net_whpipe_types.h"
#include "../types.h"
#include "../ov014/wih.h"

void NET_WHPIPE_SetTask(WhPipeWork *work, WhPipeTask task);
int NET_WHPIPE_Create(int heapId, int wmParam, void *userData, int forListening);
void NET_WHPIPE_SetEventCallback(int (*callback)(int a, int b, int c));
int NET_WHPIPE_IsBeaconAcceptable(WhPipeEntry *entry);
int NET_WHPIPE_StoreScannedEntry(void *arg);
int NET_WHPIPE_CheckBeaconFlags(WhPipeEntry *entry, u32 flags);
void NET_WHPIPE_ClearEntries(void);
void NET_WHPIPE_ResetState(WhPipeWork *work);
int NET_WHPIPE_ForwardEvent(u32 a, u32 b, u32 c);
int NET_WHPIPE_StartScan(int clearEntries);
void NET_WHPIPE_TaskBeginFinalize(WhPipeWork *work);
void NET_WHPIPE_TaskWaitFinalize(WhPipeWork *work);
int NET_WHPIPE_RequestFinalize(void);
void NET_WHPIPE_Destroy(void);
int NET_WHPIPE_NotifyEntryAcceptable(void *arg);
void NET_WHPIPE_TickEntryAges(void);
void NET_WHPIPE_PublishBeacon(void);
void NET_WHPIPE_RefreshBeacon(void);
void NET_WHPIPE_UpdateState(u32 tick);
void NET_WHPIPE_Update(u32 tick);
int NET_WHPIPE_IsConnected(void);
int NET_WHPIPE_IsAidConnected(u16 aid);
int NET_WHPIPE_GetConnectedNum(void);
int NET_WHPIPE_IsWorkAllocated(void);
int NET_WHPIPE_IsIdle(void);
unsigned int NET_WHPIPE_GetChildBitmap(void);
int NET_WHPIPE_IsDisconnectDetected(void);
void NET_WHPIPE_SetWatchDisconnect(u8 watch);
u8 *NET_WHPIPE_GetEntryBeaconData(int index);
u8 *NET_WHPIPE_GetEntryBssid(int index);
u8 NET_WHPIPE_GetEntryBeaconKind(int index);
void NET_WHPIPE_ReleaseEntrySlot(u32 index);
void NET_WHPIPE_ReleaseAllEntrySlots(void);
void NET_WHPIPE_ReleaseEntry(unsigned int index);
u8 *NET_WHPIPE_GetEntryBeacon(WhPipeEntry *entry, u8 *outKind);
int NET_WHPIPE_HasBeaconBeenSent(void *unused);
int NET_WHPIPE_IsStateScanning(void);
int NET_WHPIPE_SendData(u16 *data, unsigned int size, WihResultCallback callbackArg);
unsigned int NET_WHPIPE_GetConnectBitmap(void);
int NET_WHPIPE_GetOwnAid(void);
void NET_WHPIPE_TaskConnectParent(WhPipeWork *work);
void NET_WHPIPE_TaskStartParent(WhPipeWork *work);
int NET_WHPIPE_StartParent(int autoChannel);
void NET_WHPIPE_SetBeaconGameInfo(u8 *buf, u32 len);
void NET_WHPIPE_TaskConnectChild(WhPipeWork *work);
int NET_WHPIPE_StartChild(u32 unused, u8 *bssid, u32 entryIndex, void (*onConnected)(void));
void NET_WHPIPE_TaskFinishEnd(WhPipeWork *work);
int NET_WHPIPE_RequestEnd(WihEndCallback endCallback);
int NET_WHPIPE_AcceptChild(void *startParentCb, void *userArg);
int NET_WHPIPE_RejectChild(void *startParentCb, void *userArg);
void NET_WHPIPE_SetAcceptChild(int acceptChild);
void NET_WHPIPE_TaskParentSearchWait(WhPipeWork *work);
void NET_WHPIPE_TaskParentSearchStart(WhPipeWork *work);
void NET_WHPIPE_TaskChildScanWait(WhPipeWork *work);
void NET_WHPIPE_TaskChildScanStart(WhPipeWork *work);
int NET_WHPIPE_StartAutoSearch(void);
void NET_WHPIPE_OnChildDisconnected(void);
u8 NET_WHPIPE_GetEntryKind(u8 i);
void NET_WHPIPE_SelectEntry(u32 i);
void NET_WHPIPE_StartJoinLock(int a);
void NET_WHPIPE_SetBeaconStatus(u8 value);
void NET_WHPIPE_SetNotifyCallback(WhPipeNotifyFunc callback, void *value);
/* END mkheaders: generated region */

#endif
