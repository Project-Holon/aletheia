#ifndef GAME_ARM9_WM_STANDARD_H
#define GAME_ARM9_WM_STANDARD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wm_standard.c, prototypes copied from their definitions. */

#include "../sdk_wm.h"
#include "../types.h"

WMErrCode WM_Enable(WMCallbackFunc callback);
WMErrCode WMi_EnableEx(WMCallbackFunc callback, u32 miscFlags);
WMErrCode WM_Disable(WMCallbackFunc callback);
WMErrCode WM_PowerOn(WMCallbackFunc callback);
WMErrCode WM_PowerOff(WMCallbackFunc callback);
WMErrCode WM_Initialize(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo);
WMErrCode WM_InitializeForListening(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo, BOOL blink);
WMErrCode WMi_InitializeEx(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo, u32 miscFlags);
WMErrCode WM_Reset(WMCallbackFunc callback);
WMErrCode WM_End(WMCallbackFunc callback);
WMErrCode WM_SetParentParameter(WMCallbackFunc callback, WMParentParam *pparaBuf);
BOOL WmCheckParentParameter(WMParentParam *param);
WMErrCode WMi_StartParentEx(WMCallbackFunc callback, BOOL powerSave);
WMErrCode WM_StartParent(WMCallbackFunc callback);
WMErrCode WM_EndParent(WMCallbackFunc callback);
WMErrCode WM_StartScanEx(WMCallbackFunc callback, const WMScanExParam *param);
WMErrCode WM_EndScan(WMCallbackFunc callback);
WMErrCode WM_StartConnectEx(WMCallbackFunc callback, WMBssDesc *pInfo, u8 *ssid, BOOL powerSave, u16 authMode);
WMErrCode WM_Disconnect(WMCallbackFunc callback, u16 aid);
/* END mkheaders: generated region */

#endif
