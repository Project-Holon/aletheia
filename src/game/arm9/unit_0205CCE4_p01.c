/*
 * file:     unit_0205CCE4_p01.c
 * unit:     yes
 * function: func_0205CCE4, func_0205CD24, func_0205CE84
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
 */
typedef struct {
    int aptype;
    int area;
    int security;
    char spotinfo[10];
    char essid[33];
    unsigned char bssid[6];
} DWCApInfo;

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
void func_0205CCE4(char *fullapinfo, DWCApInfo *apinfo);
int func_0205CD24(DWCApInfo *apinfo);
int func_0205CE84(void *ssid, unsigned short len, DWCApInfo *apinfo);



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
