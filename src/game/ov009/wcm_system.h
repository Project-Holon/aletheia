#ifndef GAME_OV009_WCM_SYSTEM_H
#define GAME_OV009_WCM_SYSTEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wcm_system.c, prototypes copied from their definitions. */

#include "../ov009/wcm_types.h"
#include "../sdk_wm.h"

long WCM_Init(void *buf, long len);
long WCM_InitEx(void *buf, long len, unsigned char deviceId);
long WCM_Finish(void);
int WCM_GetWorkSize(long *workSize, unsigned char deviceId);
long WCM_StartupAsync(void *config, void (*notify)(void *));
long WCM_CleanupAsync(void);
void WCM_SearchAsync(void *bssid, void *essid, unsigned long option);
long WCM_BeginSearchAsync(void *bssid, void *essid, unsigned long option);
long WCM_EndSearchAsync(void);
long WCM_ConnectAsync(void *bssDesc, void *wepDesc, unsigned long option);
long WCM_DisconnectAsync(void);
long WCM_TerminateAsync(void);
long WCM_GetPhase(void);
unsigned long WCM_UpdateOption(unsigned long option);
unsigned short WCM_GetAllowedChannel(void);
WCMWork *WCMi_GetSystemWork(void);
void WcmConfigure(WCMConfig *config, void (*notify)(void *));
void WcmInitOption(void);
unsigned short WCMi_GetNextScanChannel(unsigned short channel);
void WCMi_Notify(short result, void *para0, void *para1, long para2);
void WCMi_NotifyEx(short notify, short result, void *para0, void *para1, long para2);
void WCMi_SetPhase(unsigned char phase);
void WCMi_ResetKeepAliveAlarm(void);
void WcmKeepAliveAlarm(void);
unsigned char WCMi_GetDefaultDeviceId(void);
/* END mkheaders: generated region */

#endif
