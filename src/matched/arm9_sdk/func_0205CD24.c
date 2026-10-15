/*
 * function: DWC_GetApInfo
 * address:  0x0205CD24
 * packet:   pkt_0205CD24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GetApInfo (dwc_connectinet.o)
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   DWC_GetInetStatus 0x0205CA20 arm
 *   DWC_AC_GetApType 0x0205BDD0 arm
 *   OS_DisableInterrupts 0x02087988 arm
 *   WCM_GetApMacAddress 0x02166384 arm
 *   DC_InvalidateRange 0x020862B8 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   WCM_GetApEssid 0x021663C8 arm
 *   DWC_AC_GetApSpotInfo 0x0205BE00 arm
 *   DWCi_DivideFullApinfo 0x0205CCE4 arm
 *   DWC_AC_GetSecuritySetting 0x0205BE58 arm
 */

typedef struct {
    int aptype;
    int area;
    int security;
    char spotinfo[10];
    char essid[33];
    unsigned char bssid[6];
} DWCApInfo;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int DWC_GetInetStatus(void);
extern unsigned char DWC_AC_GetApType(void);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned char *WCM_GetApMacAddress(void);
extern void DC_InvalidateRange(void *startAddr, unsigned long nBytes);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern int OS_IsRunOnTwl(void);
extern unsigned char *WCM_GetApEssid(unsigned short *length);
extern int DWC_AC_GetApSpotInfo(unsigned char *apSpotInfo);
extern void DWCi_DivideFullApinfo(char *fullapinfo, DWCApInfo *apinfo);
extern int DWC_AC_GetSecuritySetting(void);

int DWC_GetApInfo(DWCApInfo *apinfo)
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
        DWCi_DivideFullApinfo((char *)apSpotInfo, apinfo);
    } else {
        apinfo->area = 0xff;
    }
    apinfo->security = DWC_AC_GetSecuritySetting();
    return 1;
}
