#ifndef GAME_ARM9_UTIL_WIFIIDTOOL_H
#define GAME_ARM9_UTIL_WIFIIDTOOL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of util_wifiidtool.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../sdk_dwc.h"

u64 DWCi_Util_WiFiId_scrambleUid(u16 rand, u32 mac, u8 vend, u8 mainunit);
int DWCi_AUTH_GetNewWiFiInfo(DWCWiFiInfo *wifiinfo);
int DWCi_AUTH_MakeWiFiID(void *work);
int DWCi_AUTH_UpDateWiFiID(DWCWiFiInfo *wifiinfo, void *work);
int DWCi_AUTH_RemakeWiFiID(DWCWiFiInfo *wifiinfo);
void DWC_Auth_GetId(DWCAuthWiFiId *id);
int DWC_Auth_CheckWiFiIDNeedCreate(void);
/* END mkheaders: generated region */

#endif
