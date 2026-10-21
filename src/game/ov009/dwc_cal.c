/*
 * file:     dwc_cal.c
 * unit:     yes
 * function: DWC_Auth_GetCalInfoFromNVRAM, DWC_Auth_GetCalInfoFromWiFiInfo, DWC_Auth_SetCalInfoToHttp
 * address:  0x02178F4C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_BM_GetWiFiInfo  0x02058518  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_SNPrintf  0x02084F80  arm
 *   OS_Terminate  0x02088234  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   OS_SPrintf  0x02084F40  arm
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   RTC_GetDateTime  0x020889C0  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   WCM_GetApMacAddress  0x02166384  arm  ov009
 *   DC_InvalidateRange  0x020862B8  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   DWC_AC_GetApType  0x0205BDD0  arm
 *   WCM_GetApEssid  0x021663C8  arm  ov009
 *   DWC_AC_GetApSpotInfo  0x0205BE00  arm
 *   gDwcCalFmtUserId     0x021A2490  data ov009
 *   gDwcCalFmtPasswd     0x021A2498  data ov009
 *   gDwcCalFmtHexByte     0x021A24A0  data ov009
 *   gDwcCalFmtBirth     0x021A24A8  data ov009
 *   gDwcCalFmtDevTime     0x021A24B4  data ov009
 *   gDwcCalFmtApInfo     0x021A24D0  data ov009
 *   strlen  0x0209477C  arm
 *   DWC_Http_Add_PostBase64Item  0x02179F3C  arm  ov009
 *   wcslen  0x02096578  arm
 *   DWC_Http_Add_HeaderItem  0x02179E60  arm  ov009
 *   gDwcCalFmtVersion     0x021A24E0  data ov009
 *   gDwcCalKeyVersion     0x021A24EC  data ov009
 *   gDwcCalKeyUserId     0x021A24F4  data ov009
 *   gDwcCalKeyPasswd     0x021A24FC  data ov009
 *   gDwcCalKeyBssid     0x021A2504  data ov009
 *   gDwcCalKeyApInfo     0x021A250C  data ov009
 *   gDwcCalKeyGameCd     0x021A2514  data ov009
 *   gDwcCalKeyMakerCd     0x021A251C  data ov009
 *   gDwcCalKeyUnitCd     0x021A2524  data ov009
 *   gDwcCalKeyMacAdr     0x021A252C  data ov009
 *   gDwcCalKeyLang     0x021A2534  data ov009
 *   gDwcCalKeyBirth     0x021A253C  data ov009
 *   gDwcCalKeyDevTime     0x021A2544  data ov009
 *   gDwcCalKeyDevName     0x021A254C  data ov009
 *   gDwcCalKeySsid     0x021A2554  data ov009
 *   gDwcCalFmtHeaderVersion     0x021A255C  data ov009
 *   gDwcCalHeaderVersion     0x021A2574  data ov009
 *   gDwcCalHeaderGameCd     0x021A2580  data ov009
 */
typedef struct {
    char bytes[0x14];
} WiFiInfo;

#include "../arm9/dwc_backup.h"
#include "../sdk_rtc.h"

#include "../sdk_os.h"


#include "../types.h"

#include "../sdk_dwc.h"

#include "../arm9/mi_memory.h"
#include "../arm9/os_printf.h"
#include "../arm9/os_terminate_processor.h"
#include "../arm9/os_ownerinfo.h"
#include "../arm9/external.h"
#include "../arm9/os_system.h"
#include "wcm_cpsif.h"
#include "../arm9/os_cache.h"
#include "../arm9/dwc_ac.h"
#include "../arm9/msl_string_str.h"
#include "dwc_http.h"
#include "../arm9/msl_wchar.h"
int DWC_Auth_GetCalInfoFromNVRAM(void *cal);
int DWC_Auth_GetCalInfoFromWiFiInfo(DWCCalInfo *cal, DWCWiFiInfo *wifiinfo);
int DWC_Auth_SetCalInfoToHttp(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
extern const char gDwcCalFmtUserId[];
extern const char gDwcCalFmtPasswd[];
extern const char gDwcCalFmtHexByte[];
extern const char gDwcCalFmtBirth[];
extern const char gDwcCalFmtDevTime[];
extern const char gDwcCalFmtApInfo[];
extern const char gDwcCalFmtVersion[];
extern const char gDwcCalKeyVersion[];
extern const char gDwcCalKeyUserId[];
extern const char gDwcCalKeyPasswd[];
extern const char gDwcCalKeyBssid[];
extern const char gDwcCalKeyApInfo[];
extern const char gDwcCalKeyGameCd[];
extern const char gDwcCalKeyMakerCd[];
extern const char gDwcCalKeyUnitCd[];
extern const char gDwcCalKeyMacAdr[];
extern const char gDwcCalKeyLang[];
extern const char gDwcCalKeyBirth[];
extern const char gDwcCalKeyDevTime[];
extern const char gDwcCalKeyDevName[];
extern const char gDwcCalKeySsid[];
extern const char gDwcCalFmtHeaderVersion[];
extern const char gDwcCalHeaderVersion[];
extern const char gDwcCalHeaderGameCd[];

/*
 * sdk:      DWC_Auth_GetCalInfoFromNVRAM (dwc_cal.o)
 */
int DWC_Auth_GetCalInfoFromNVRAM(void *cal)
{
    WiFiInfo wifiinfo;
    DWCi_BM_GetWiFiInfo((struct tagDWCWiFiInfo *)&wifiinfo);
    return DWC_Auth_GetCalInfoFromWiFiInfo(cal, (DWCWiFiInfo *)(&wifiinfo));
}

/*
 * sdk:      DWC_Auth_GetCalInfoFromWiFiInfo (libdwcauth.TWL.HYB.a dwc_cal.o)
 */
int DWC_Auth_GetCalInfoFromWiFiInfo(DWCCalInfo *cal, DWCWiFiInfo *wifiinfo)
{
    long i;
    unsigned char macaddr[6];
    OSOwnerInfo ownerinfo;
    RTCDate rtcdate;
    RTCTime rtctime;
    unsigned long preirq;
    unsigned char *wcmbssid;
    unsigned char *wcmessid;
    unsigned short wcmessidlen;
    unsigned char aptype;

    MI_CpuFill8(cal, 0, sizeof(DWCCalInfo));

    if (wifiinfo->attestedUserId != 0)
        OS_SNPrintf(cal->userid, sizeof(cal->userid), gDwcCalFmtUserId, wifiinfo->attestedUserId);
    else
        OS_SNPrintf(cal->userid, sizeof(cal->userid), gDwcCalFmtUserId, wifiinfo->notAttestedId);
    OS_SNPrintf(cal->passwd, sizeof(cal->passwd), gDwcCalFmtPasswd, wifiinfo->pass);

    if (*(unsigned char *)0x02FFFE0C == 0)
        OS_Terminate();
    MI_CpuCopy8((void *)0x02FFFE0C, cal->gamecd, 4);
    if (*(unsigned char *)0x02FFFE10 == 0)
        OS_Terminate();
    MI_CpuCopy8((void *)0x02FFFE10, cal->makercd, 2);

    cal->unitcd[0] = '0';

    OS_GetMacAddress(macaddr);
    for (i = 0; i < 6; i++)
        OS_SPrintf(&cal->macadr[i * 2], gDwcCalFmtHexByte, macaddr[i]);

    OS_GetOwnerInfo(&ownerinfo);
    if (ownerinfo.language >= 8)
        ownerinfo.language = 1;
    OS_SNPrintf(cal->lang, sizeof(cal->lang), gDwcCalFmtHexByte, ownerinfo.language);
    MI_CpuCopy8(ownerinfo.nickName, cal->devname, 20);
    OS_SNPrintf(cal->birth, sizeof(cal->birth), gDwcCalFmtBirth,
                  ownerinfo.birthday.month, ownerinfo.birthday.day);

    if (RTC_GetDateTime(&rtcdate, &rtctime) != 0)
        return 0;
    OS_SNPrintf(cal->devtime, sizeof(cal->devtime), gDwcCalFmtDevTime,
                  rtcdate.year, rtcdate.month, rtcdate.day,
                  rtctime.hour, rtctime.minute, rtctime.second);

    preirq = OS_DisableInterrupts();

    wcmbssid = WCM_GetApMacAddress();
    DC_InvalidateRange(wcmbssid, 6);
    if (wcmbssid == 0) {
        OS_RestoreInterrupts(preirq);
        return 0;
    }
    for (i = 0; i < 6; i++)
        OS_SPrintf(&cal->bssid[i * 2], gDwcCalFmtHexByte, wcmbssid[i]);

    aptype = DWC_AC_GetApType();
    if (aptype == 0xff || aptype > 99)
        aptype = 99;
    OS_SNPrintf(cal->apinfo, sizeof(cal->apinfo), gDwcCalFmtApInfo, aptype);

    wcmessid = WCM_GetApEssid(&wcmessidlen);
    DC_InvalidateRange(wcmessid, 32);
    if (wcmessid == 0) {
        OS_RestoreInterrupts(preirq);
        return 0;
    }
    MI_CpuCopy8(wcmessid, cal->ssid, 32);
    DWC_AC_GetApSpotInfo((unsigned char *)&cal->apinfo[3]);

    OS_RestoreInterrupts(preirq);
    return 1;
}

/*
 * sdk:      DWC_Auth_SetCalInfoToHttp (libdwcauth.TWL.HYB.a dwc_cal.o)
 */
int DWC_Auth_SetCalInfoToHttp(DWCHttp *http, DWCCalInfo *calinfo, int allowessid)
{
    char buf[33];

    OS_SNPrintf(buf, sizeof(buf), gDwcCalFmtVersion, 5, 3);
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyVersion, buf, strlen(buf)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyUserId, calinfo->userid, strlen(calinfo->userid)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyPasswd, calinfo->passwd, strlen(calinfo->passwd)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyBssid, calinfo->bssid, strlen(calinfo->bssid)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyApInfo, calinfo->apinfo, strlen(calinfo->apinfo)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyGameCd, calinfo->gamecd, strlen(calinfo->gamecd)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyMakerCd, calinfo->makercd, strlen(calinfo->makercd)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyUnitCd, calinfo->unitcd, strlen(calinfo->unitcd)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyMacAdr, calinfo->macadr, strlen(calinfo->macadr)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyLang, calinfo->lang, strlen(calinfo->lang)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyBirth, calinfo->birth, strlen(calinfo->birth)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyDevTime, calinfo->devtime, strlen(calinfo->devtime)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyDevName, (char *)calinfo->devname, wcslen(calinfo->devname) * 2) != 0)
        return 0;
    if (allowessid == 1) {
        if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeySsid, calinfo->ssid, strlen(calinfo->ssid)) != 0)
            return 0;
    }

    OS_SNPrintf(buf, sizeof(buf), gDwcCalFmtHeaderVersion, 5, 3);
    if (DWC_Http_Add_HeaderItem((char *)http, (char *)gDwcCalHeaderVersion, buf) != 0)
        return 0;
    if (DWC_Http_Add_HeaderItem((char *)http, (char *)gDwcCalHeaderGameCd, calinfo->gamecd) != 0)
        return 0;
    return 1;
}
