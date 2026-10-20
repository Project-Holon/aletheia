#ifndef GAME_ARM9_NET_IRC_WIRELESS_H
#define GAME_ARM9_NET_IRC_WIRELESS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of net_irc_wireless.c, prototypes copied from their definitions. */

struct NetMacList;

#include "../arm9/net_types.h"
#include "../arm9/net_types.h"
#include "../types.h"

GFLNetInitializeStruct *GFL_NET_IRC_WIRELESS_Create(const GFLNetInitializeStruct *src, u32 callbackArg);
void GFL_NET_IRC_WIRELESS_Destroy(void);
void GFL_NET_IRC_WIRELESS_DestroyIfIdle(void);
int GFL_NET_IRC_WIRELESS_IsActive(void);
void GFL_NET_IRC_WIRELESS_SetSessionParamValue(unsigned int value);
void *GFL_NET_IRC_WIRELESS_SetCallbacks(void (*onFinished)(u32), void (*onResult)(u32, int), void (*onReady)(u32));
void GFL_NET_IRC_WIRELESS_AddMacAddress(const u8 *mac);
void GFL_NET_IRC_WIRELESS_CopyMacAddress(void *dst, u32 slot);
void GFL_NET_IRC_WIRELESS_OnSyncReady(void);
void GFL_NET_IRC_WIRELESS_OnConnectEnd(u32 userArg);
void GFL_NET_IRC_WIRELESS_SetState(NetIrcWirelessLink *link, int state);
void GFL_NET_IRC_WIRELESS_Main(void);
void *GFL_NET_IRC_WIRELESS_GetBeaconData(void *beaconArg);
void *GFL_NET_IRC_WIRELESS_GetBeaconCompare(void *beaconArg);
void GFL_NET_IRC_WIRELESS_AddMacList(u32 unusedA, u32 unusedB, struct NetMacList *macList);
u32 GFL_NET_IRC_WIRELESS_RetryStep(void);
void GFL_NET_IRC_WIRELESS_RequestRetry(int netId);
int GFL_NET_IRC_WIRELESS_GetRetryCountValue(void);
void GFL_NET_IRC_WIRELESS_SetGameKindOverride(int gameKind);
/* END mkheaders: generated region */

#endif
