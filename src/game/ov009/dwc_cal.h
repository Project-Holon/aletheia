#ifndef GAME_OV009_DWC_CAL_H
#define GAME_OV009_DWC_CAL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_cal.c, prototypes copied from their definitions. */

#include "../sdk_dwc.h"
#include "../sdk_dwc.h"
#include "../ov009/dwc_http_types.h"

int DWC_Auth_GetCalInfoFromNVRAM(void *cal);
int DWC_Auth_GetCalInfoFromWiFiInfo(DWCCalInfo *cal, DWCWiFiInfo *wifiinfo);
int DWC_Auth_SetCalInfoToHttp(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
/* END mkheaders: generated region */

#endif
