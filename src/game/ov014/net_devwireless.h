#ifndef GAME_OV014_NET_DEVWIRELESS_H
#define GAME_OV014_NET_DEVWIRELESS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of net_devwireless.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov014/wih.h"

void *GFL_NET_DEVWIRELESS_GetDeviceTable(void);
int GFL_NET_DEVWIRELESS_Setup(int heapId, u32 setupParam, int wmParam, void *userData);
int GFL_NET_DEVWIRELESS_Begin(void (*doneCallback)(void));
int GFL_NET_DEVWIRELESS_Update(u32 tick);
int GFL_NET_DEVWIRELESS_RequestDisconnect(void);
int GFL_NET_DEVWIRELESS_OnShutdownDone(int result);
int GFL_NET_DEVWIRELESS_Cleanup(void (*endCallback)(int));
int GFL_NET_DEVWIRELESS_ClearScanList(void);
int GFL_NET_DEVWIRELESS_UnusedSlot7(void);
int GFL_NET_DEVWIRELESS_UnusedSlot8(void);
int GFL_NET_DEVWIRELESS_UnusedSlot9(void);
void *GFL_NET_DEVWIRELESS_GetScanResult(int entryIndex);
void *GFL_NET_DEVWIRELESS_GetScanResultMac(int entryIndex);
int GFL_NET_DEVWIRELESS_UnusedSlot12(void);
int GFL_NET_DEVWIRELESS_UnusedSlot13(void);
int GFL_NET_DEVWIRELESS_HasBeaconBeenSent(void *unused);
int GFL_NET_DEVWIRELESS_SetConnectCallback(WihSlotCallback connectCallback);
int GFL_NET_DEVWIRELESS_StartParent(int autoChannel);
int GFL_NET_DEVWIRELESS_StartChildScan(int resetWork);
int GFL_NET_DEVWIRELESS_StartChild(u32 unused, u8 *bssid, u32 entryIndex, u32 unused2, void (*onConnected)(void));
int GFL_NET_DEVWIRELESS_UnusedSlot19(void);
int GFL_NET_DEVWIRELESS_RequestShutdown(void);
int GFL_NET_DEVWIRELESS_IsDataSharing(void);
int GFL_NET_DEVWIRELESS_StepDataSharing(const u16 *sendData);
u16 *GFL_NET_DEVWIRELESS_GetSharedData(u32 aid);
int GFL_NET_DEVWIRELESS_SendData(u16 *data,u32 size,int unused,WihResultCallback callbackArg);
int GFL_NET_DEVWIRELESS_SetEventCallback(int (*callback)(int, int, int));
int GFL_NET_DEVWIRELESS_IsActive(void);
int GFL_NET_DEVWIRELESS_IsConnected(void);
int NET_WHPIPE_IsWorkNotAllocated(void);
int NET_WHPIPE_IsWhIdle(void);
unsigned int NET_WHPIPE_QueryConnectBitmap(void);
int NET_WHPIPE_QueryOwnAid(void);
int GFL_NET_DEVWIRELESS_GetSignalLevel(void);
int GFL_NET_DEVWIRELESS_GetLastErrorCode(void);
void GFL_NET_DEVWIRELESS_SetWatchDisconnect(unsigned char watch);
void GFL_NET_DEVWIRELESS_SetAcceptChild(int accept);
int GFL_NET_DEVWIRELESS_StartAutoSearch(void);
void GFL_NET_DEVWIRELESS_StartJoinLock(int frames);
/* END mkheaders: generated region */

#endif
