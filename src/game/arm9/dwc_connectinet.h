#ifndef GAME_ARM9_DWC_CONNECTINET_H
#define GAME_ARM9_DWC_CONNECTINET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_connectinet.c, prototypes copied from their definitions. */

void DWC_SetRwinSize(long size);
void DWC_ConnectInetAsync(void);
void DWC_DebugConnectInetExAsync(void *ssid, void *wep, int wepMode, unsigned short mtu, char *apSpotInfo, int overrideType);
int DWC_CheckInet(void);
void DWC_ProcessInet(void);
int DWC_GetInetStatus(void);
void DWC_CleanupInet(void);
int DWCi_CheckDisconnected(void);
int DWC_GetLinkLevel(void);
unsigned long DWC_GetCheckNintendoZoneWorkSize(void);
void DWC_GetParseWMBssDescWorkSize(void);
int DWC_UpdateConnection(void);
/* END mkheaders: generated region */

#endif
