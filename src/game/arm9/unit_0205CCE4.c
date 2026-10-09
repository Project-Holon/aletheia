/*
 * file:     unit_0205CCE4.c
 * unit:     yes
 * function: func_0205CCE4, func_0205CD24, func_0205CE84, DWC_GetCheckNintendoZoneWorkSize, func_0205CF30
 * address:  0x0205CCE4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   DWC_GetInetStatus 0x0205CA20 arm
 *   DWC_AC_GetApType 0x0205BDD0 arm
 *   OS_DisableInterrupts 0x02087988 arm
 *   WCM_GetApMacAddress 0x02166384 arm
 *   DC_InvalidateRange 0x020862B8 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   WCM_GetApEssid 0x021663C8 arm
 *   DWC_AC_GetApSpotInfo 0x0205BE00 arm
 *   DWC_AC_GetSecuritySetting 0x0205BE58 arm
 *   DWC_AC_CheckWiFiStation 0x0205BFD4 arm
 *   DWCi_AC_GetPostalCode 0x0205EA70 arm
 *   MATHi_CRC16InitTableRev 0x020819FC arm
 *   WDS_DecryptWMBssDesc 0x0205A7CC arm
 *   WDS_IsAvailableForAutoConnect 0x0205A8FC arm
 */
typedef struct {
    int aptype;
    int area;
    int security;
    char spotinfo[10];
    char essid[33];
    unsigned char bssid[6];
} DWCApInfo;

typedef struct {
    unsigned short magicNumber;
    unsigned char ver;
    unsigned char platform;
    unsigned long ggid;
    unsigned short tgid;
    unsigned char userGameInfoLength;
} WMGameInfo;

typedef struct {
    unsigned short length;
    unsigned short rssi;
    unsigned char bssid[6];
    unsigned short ssidLength;
    unsigned char ssid[32];
    unsigned short capaInfo;
    unsigned short rateSet[2];
    unsigned short beaconPeriod;
    unsigned short dtimPeriod;
    unsigned short channel;
    unsigned short cfpPeriod;
    unsigned short cfpMaxDuration;
    unsigned short gameInfoLength;
    unsigned short otherElementCount;
    WMGameInfo gameInfo;
} WMBssDesc;

typedef struct { unsigned char data[0x104]; } CRYPTORC4Context;

typedef struct { unsigned short table[256]; } MATHCRC16Table;

typedef struct {
    unsigned char head[0x20];
    char fullapinfo[0x50];
} WDSApInfo;

typedef struct {
    CRYPTORC4Context rc4context;
    unsigned short crcContext;
    MATHCRC16Table crcTable;
    WDSApInfo apinfo;
} DWCCheckNintendoZoneWork;

extern void MI_CpuCopy8(const void *src, void *dst, unsigned long size);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int DWC_GetInetStatus(void);
extern unsigned char DWC_AC_GetApType(void);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned char *WCM_GetApMacAddress(void);
extern void DC_InvalidateRange(void *startAddr, unsigned long nBytes);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int OS_IsRunOnTwl(void);
extern unsigned char *WCM_GetApEssid(unsigned short *length);
extern int DWC_AC_GetApSpotInfo(unsigned char *apSpotInfo);
extern int DWC_AC_GetSecuritySetting(void);
extern int DWC_AC_CheckWiFiStation(void *ssid, unsigned short len);
extern int DWCi_AC_GetPostalCode(char *ssid, unsigned char *pos);
extern void MATHi_CRC16InitTableRev(MATHCRC16Table *table, unsigned short poly);
extern int WDS_DecryptWMBssDesc(CRYPTORC4Context *rc4context, unsigned short *crcContext, MATHCRC16Table *crcTable, WMBssDesc *bssdesc, WDSApInfo *apinfo);
extern int WDS_IsAvailableForAutoConnect(WDSApInfo *apinfo);
void func_0205CCE4(char *fullapinfo, DWCApInfo *apinfo);
int func_0205CD24(DWCApInfo *apinfo);
int func_0205CE84(void *ssid, unsigned short len, DWCApInfo *apinfo);
unsigned long DWC_GetCheckNintendoZoneWorkSize(void);
int func_0205CF30(void *work, WMBssDesc *bssdesc, DWCApInfo *apinfo);





/*
 * sdk:      DWCi_DivideFullApinfo (dwc_connectinet.o)
 */
void func_0205CCE4(char *fullapinfo, DWCApInfo *apinfo)
{
    int isdigit = 0;

    if (fullapinfo[0] >= '0' && fullapinfo[0] <= '9') {
        isdigit = 1;
    }
    apinfo->area = isdigit ? fullapinfo[0] - '0' : 0xff;
    MI_CpuCopy8(fullapinfo + 1, apinfo->spotinfo, 9);
}





/*
 * sdk:      DWC_GetApInfo (dwc_connectinet.o)
 */
int func_0205CD24(DWCApInfo *apinfo)
{
    unsigned short essidlen;
    unsigned char apSpotInfo[10];
    unsigned char *wcmapbssid;
    unsigned char *wcmapessid;
    unsigned long preirq;

    MI_CpuFill8(apinfo, 0, sizeof(DWCApInfo));
    apinfo->area = 0xff;
    if (DWC_GetInetStatus() != 4) {
        return 0;
    }
    apinfo->aptype = DWC_AC_GetApType();
    if (apinfo->aptype == 0xff || apinfo->aptype > 99) {
        apinfo->aptype = 99;
        return 0;
    }
    preirq = OS_DisableInterrupts();
    wcmapbssid = WCM_GetApMacAddress();
    DC_InvalidateRange(wcmapbssid, 6);
    if (wcmapbssid == 0) {
        OS_RestoreInterrupts(preirq);
        return 0;
    }
    MI_CpuCopy8(wcmapbssid, apinfo->bssid, 6);
    if (apinfo->aptype == 0 || apinfo->aptype == 1 || apinfo->aptype == 2
        || (OS_IsRunOnTwl() && (unsigned int)(apinfo->aptype - 10) <= 2)) {
        wcmapessid = WCM_GetApEssid(&essidlen);
        DC_InvalidateRange(wcmapessid, 0x20);
        if (wcmapessid == 0) {
            OS_RestoreInterrupts(preirq);
            return 0;
        }
        MI_CpuCopy8(wcmapessid, apinfo->essid, essidlen);
    }
    OS_RestoreInterrupts(preirq);
    if (DWC_AC_GetApSpotInfo(apSpotInfo)) {
        func_0205CCE4((char *)apSpotInfo, apinfo);
    } else {
        apinfo->area = 0xff;
    }
    apinfo->security = DWC_AC_GetSecuritySetting();
    return 1;
}




/*
 * sdk:      DWC_CheckWiFiStation (dwc_connectinet.o)
 */
int func_0205CE84(void *ssid, unsigned short len, DWCApInfo *apinfo)
{
    unsigned char apSpotInfo[10];

    MI_CpuFill8(apSpotInfo, 0, 10);
    if (ssid == 0) {
        return 0;
    }
    if (DWC_AC_CheckWiFiStation(ssid, len)) {
        if (apinfo == 0) {
            return 1;
        }
        if (DWCi_AC_GetPostalCode(ssid, apSpotInfo)) {
            apinfo->aptype = 4;
            func_0205CCE4((char *)apSpotInfo, apinfo);
            return 1;
        }
    }
    return 0;
}


unsigned long DWC_GetCheckNintendoZoneWorkSize(void)
{
    return 0x376;
}


/*
 * sdk:      DWC_CheckNintendoZone (dwc_connectinet.o)
 */
int func_0205CF30(void *work, WMBssDesc *bssdesc, DWCApInfo *apinfo)
{
    DWCCheckNintendoZoneWork *pwork;

    if (work == 0 || bssdesc == 0) {
        return 0;
    }
    MI_CpuFill8(work, 0, 0x376);
    if (bssdesc->gameInfo.userGameInfoLength + 0x10 == 0x80
        && bssdesc->gameInfo.magicNumber == 1
        && bssdesc->gameInfo.ggid == 0x857) {
        pwork = (DWCCheckNintendoZoneWork *)work;
        pwork->crcContext = 0;
        MATHi_CRC16InitTableRev(&pwork->crcTable, 0xa001);
        if (WDS_DecryptWMBssDesc(&pwork->rc4context, &pwork->crcContext, &pwork->crcTable, bssdesc, &pwork->apinfo)
            && WDS_IsAvailableForAutoConnect(&pwork->apinfo)) {
            if (apinfo != 0) {
                apinfo->aptype = 8;
                func_0205CCE4(pwork->apinfo.fullapinfo, apinfo);
            }
            return 1;
        }
    }
    return 0;
}
