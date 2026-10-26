#ifndef GAME_OV009_NET_DEVWIFI_H
#define GAME_OV009_NET_DEVWIFI_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of net_devwifi.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov009/dwc_rap_types.h"

void GFL_NET_DEVWIFI_InitDwc(int heapId);
int GFL_NET_DEVWIFI_Setup(int heapId, int param);
int GFL_NET_DEVWIFI_Begin(void (*doneCallback)(int));
int GFL_NET_DEVWIFI_Update(int cancelRequest);
int GFL_NET_DEVWIFI_UpdateDisconnect(void *requestClose);
int GFL_NET_DEVWIFI_Cleanup(void (*doneCallback)(int));
int GFL_NET_DEVWIFI_StartMatchWithKey(void *matchValue, int maxPlayers, int useFilter, int unused);
int GFL_NET_DEVWIFI_StartFriendMatch(int friendIndex, int maxPlayers, int limitToTwo);
int GFL_NET_DEVWIFI_PollDisconnect(int requestClose);
int GFL_NET_DEVWIFI_SendMessage(void *data, int size, int unused, void (*doneCallback)(int));
int GFL_NET_DEVWIFI_SetRecvCallback(DwcRapRecvFunc callback);
int GFL_NET_DEVWIFI_IsActive(void);
int GFL_NET_DEVWIFI_IsConnected(void);
int GFL_NET_DEVWIFI_IsOffline(void);
int GFL_NET_DEVWIFI_IsIdle(void);
int GFL_NET_DEVWIFI_GetAidBitmap(void);
int GFL_NET_DEVWIFI_GetMyAid(void);
int GFL_NET_DEVWIFI_GetSignalLevel(void);
int GFL_NET_DEVWIFI_GetLastErrorCode(void);
void GFL_NET_DEVWIFI_SetErrorOnDisconnect(u32 enabled);
int GFL_NET_DEVWIFI_IsFriendWaiting(int friendIndex);
s16 GFL_NET_DEVWIFI_IsVchatEnabled(void);
int GFL_NET_DEVWIFI_GetNewClientAid(void);
void GFL_NET_DEVWIFI_SetAllowConnect(u32 allowed);
int GFL_NET_DEVWIFI_IsInSession(void);
void *GFL_NET_DEVWIFI_GetDeviceTable(void);
/* END mkheaders: generated region */

#endif
