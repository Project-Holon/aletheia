#ifndef GAME_ARM9_DWC_CONNECTINET_H
#define GAME_ARM9_DWC_CONNECTINET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_connectinet.c, prototypes copied from their definitions. */

#include "../arm9/dwc_connectinet_types.h"
#include "../sdk_wm.h"

void DWC_InitInetEx(DWCstInetControl *inetCntl, unsigned short dmaNo, unsigned short unused, unsigned short ssl_priority);
void DWC_SetRwinSize(long size);
void DWC_ConnectInetAsync(void);
void DWC_DebugConnectInetExAsync(void *ssid, void *wep, int wepMode, unsigned short mtu, char *apSpotInfo, int overrideType);
int DWC_CheckInet(void);
void DWC_ProcessInet(void);
int DWC_GetInetStatus(void);
void DWC_CleanupInet(void);
int DWCi_CheckDisconnected(void);
int DWC_GetLinkLevel(void);
void DWCi_DivideFullApinfo(char *fullapinfo, DWCApInfo *apinfo);
int DWC_GetApInfo(DWCApInfo *apinfo);
int DWC_CheckWiFiStation(void *ssid, unsigned short len, DWCApInfo *apinfo);
unsigned long DWC_GetCheckNintendoZoneWorkSize(void);
int DWC_CheckNintendoZone(void *work, WMBssDesc *bssdesc, DWCApInfo *apinfo);
unsigned long DWC_GetParseWMBssDescWorkSize(void);
int DWC_ParseWMBssDesc(void *work, WMBssDesc *bssdesc, DWCApInfo *apinfo);
int DWC_UpdateConnection(void);
/* END mkheaders: generated region */

#endif
