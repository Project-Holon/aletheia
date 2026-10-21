#ifndef GAME_ARM9_WM_DS_H
#define GAME_ARM9_WM_DS_H

#include "../sdk_wm.h"

typedef struct WMDataSharingInfo WMDataSharingInfo;
typedef struct WMDataSet WMDataSet;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wm_ds.c, prototypes copied from their definitions. */

struct WMDataSharingInfo;
struct WMDataSet;
typedef struct WMDataSharingInfo WMDataSharingInfo;
typedef struct WMDataSet WMDataSet;

#include "../types.h"

WMErrCode WM_StartDataSharing(WMDataSharingInfo *dsInfo, u16 port, u16 aidBitmap, u16 dataLength, BOOL doubleMode);
WMErrCode WM_EndDataSharing(WMDataSharingInfo *dsInfo);
WMErrCode WM_StepDataSharing(WMDataSharingInfo *dsInfo, const u16 *sendData, WMDataSet *receiveData);
void WmDataSharingSetDataCallback(void *callback);
void WmDataSharingReceiveCallback_Parent(void *callback);
void WmDataSharingReceiveCallback_Child(void *callback);
void WmDataSharingReceiveData(WMDataSharingInfo *dsInfo, u16 aid, u16 *data);
void WmDataSharingSendDataSet(WMDataSharingInfo *dsInfo, BOOL delayed);
u16 *WM_GetSharedDataAddress(WMDataSharingInfo *dsInfo, WMDataSet *receiveData, u16 aid);
u16 *WmGetSharedDataAddress(WMDataSharingInfo *dsInfo, u32 aidBitmap, u16 *receiveBuf, u32 aid);
/* END mkheaders: generated region */

#endif
