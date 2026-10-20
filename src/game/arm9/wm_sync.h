#ifndef GAME_ARM9_WM_SYNC_H
#define GAME_ARM9_WM_SYNC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wm_sync.c, prototypes copied from their definitions. */

struct WMStatus;
struct WMMpRecvData;
struct WMMpRecvHeader;
typedef struct WMMpRecvData WMMpRecvData;
typedef struct WMMpRecvHeader WMMpRecvHeader;

#include "../sdk_wm.h"
#include "../types.h"

WMErrCode WM_SetIndCallback(WMCallbackFunc callback);
WMErrCode WM_SetPortCallback(u16 port, WMCallbackFunc callback, void *arg);
WMErrCode WM_ReadStatus(struct WMStatus *statusBuf);
int WM_GetMPSendBufferSize(void);
int WM_GetMPReceiveBufferSize(void);
WMMpRecvData *WM_ReadMPData(const WMMpRecvHeader *header, u16 aid);
u16 WM_GetAllowedChannel(void);
WMLinkLevel WM_GetLinkLevel(void);
u16 WM_GetDispersionBeaconPeriod(void);
u16 WM_GetDispersionScanPeriod(void);
WMOtherElements WM_GetOtherElements(WMBssDesc *bssDesc);
u16 WM_GetNextTgid(void);
/* END mkheaders: generated region */

typedef struct WMMpRecvData WMMpRecvData;
typedef struct WMMpRecvHeader WMMpRecvHeader;

#endif
