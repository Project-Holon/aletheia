#ifndef GAME_ARM9_WM_ETC_H
#define GAME_ARM9_WM_ETC_H

/* Public functions of wm_etc.c, prototypes copied from their definitions. */

#include "../sdk_wm.h"
#include "../types.h"

WMErrCode WM_SetWEPKey(WMCallbackFunc callback, u16 wepmode, const u16 *wepkey);
WMErrCode WM_SetWEPKeyEx(WMCallbackFunc callback, u16 wepmode, u16 wepkeyid, const u8 *wepkey);
WMErrCode WM_SetGameInfo(WMCallbackFunc callback, const u16 *userGameInfo, u16 userGameInfoSize, u32 ggid, u16 tgid, u8 attr);
WMErrCode WM_SetBeaconIndication(WMCallbackFunc callback, u16 flag);
WMErrCode WM_SetLifeTime(WMCallbackFunc callback, u16 tableNumber, u16 camLifeTime, u16 frameLifeTime, u16 mpLifeTime);
WMErrCode WM_MeasureChannel(WMCallbackFunc callback, u16 ccaMode, u16 edThreshold, u16 channel, u16 measureTime);
void WMi_CheckInitializedAfterMeasure(void);

#endif
