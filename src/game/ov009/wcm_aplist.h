#ifndef GAME_OV009_WCM_APLIST_H
#define GAME_OV009_WCM_APLIST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wcm_aplist.c, prototypes copied from their definitions. */

#include "../sdk_wm.h"
#include "../ov009/wcm_types.h"

void WCM_ClearApList(void);
long WCM_CountApList(void);
long WCM_LockApList(long lock);
void *WCM_PointApList(long index);
WMBssDesc *WCM_PointApListEx(long index);
void WCMi_EntryApList(WMBssDesc *bssDesc, unsigned short linkLevel);
WCMApList *WcmAllocApList(void);
void WcmAppendApList(WCMApList *aplist);
void WCMi_BssDescCopy(WMBssDesc *srcBssDesc, WMBssDesc *destBssDesc);
WMGameInfo *WCMi_GetGameInfo(WMBssDesc *bssDesc);
/* END mkheaders: generated region */

#endif
