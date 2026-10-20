#ifndef GAME_ARM9_DWC_AC_WDS_H
#define GAME_ARM9_DWC_AC_WDS_H

#include "../types.h"

/* Access point record of the hotspot service. */

typedef struct WDSApInfo
{
    u8 ssid[32];
    u8 apnum[10];
    u16 hotspotid;
    u8 hotspotname[24];
    u8 wepkey[32];
    u8 channel;
    u8 encryptflag;
    u8 infoflag;
    u8 reserve[5];
    u16 mtu;
    u16 crc;
} WDSApInfo;

typedef struct WDSBriefApInfo
{
    int isvalid;
    u16 rssi;
    WDSApInfo apinfo;
} WDSBriefApInfo;

#include "../arm9/rc4.h"
#include "../sdk_math.h"
#include "../sdk_wm.h"
unsigned char WDSGetRssi8(unsigned char rssi);
void WDSScanCallback(void *arg);
unsigned long WDS_GetWorkAreaSize(void);
int WDS_Initialize(void *wdsWork, void (*callback)(void *), unsigned short dmaNo);
int WDS_End(void (*callback)(void *));
int WDS_StartScan(void (*callback)(void *));
int WDS_EndScan(void (*callback)(void *));
int WDS_GetApInfoByIndex(int index, WDSBriefApInfo *briefapinfo);
int WDS_GetApInfoAll(WDSBriefApInfo *briefapinfo);
int WDS_DecryptWMBssDesc(CRYPTORC4Context *rc4context, unsigned short *crcContext, MATHCRC16Table *crcTable, const WMBssDesc *bssDesc, WDSApInfo *apinfo);
int IsValidApnum(unsigned char *apnum);
int WDS_IsAvailableForAutoConnect(WDSApInfo *apinfo);

#endif
