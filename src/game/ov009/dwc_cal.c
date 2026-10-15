/*
 * file:     dwc_cal.c
 * unit:     yes
 * function: func_02178F4C, func_02178F78, func_02179218
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
 *   func_02166384  0x02166384  arm  ov009
 *   func_020862B8  0x020862B8  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   DWC_AC_GetApType  0x0205BDD0  arm
 *   func_021663C8  0x021663C8  arm  ov009
 *   DWC_AC_GetApSpotInfo  0x0205BE00  arm
 *   g_021A2490     0x021A2490  data ov009
 *   g_021A2498     0x021A2498  data ov009
 *   g_021A24A0     0x021A24A0  data ov009
 *   g_021A24A8     0x021A24A8  data ov009
 *   g_021A24B4     0x021A24B4  data ov009
 *   g_021A24D0     0x021A24D0  data ov009
 *   strlen  0x0209477C  arm
 *   DWC_Http_Add_PostBase64Item  0x02179F3C  arm  ov009
 *   wcslen  0x02096578  arm
 *   DWC_Http_Add_HeaderItem  0x02179E60  arm  ov009
 *   g_021A24E0     0x021A24E0  data ov009
 *   g_021A24EC     0x021A24EC  data ov009
 *   g_021A24F4     0x021A24F4  data ov009
 *   g_021A24FC     0x021A24FC  data ov009
 *   g_021A2504     0x021A2504  data ov009
 *   g_021A250C     0x021A250C  data ov009
 *   g_021A2514     0x021A2514  data ov009
 *   g_021A251C     0x021A251C  data ov009
 *   g_021A2524     0x021A2524  data ov009
 *   g_021A252C     0x021A252C  data ov009
 *   g_021A2534     0x021A2534  data ov009
 *   g_021A253C     0x021A253C  data ov009
 *   g_021A2544     0x021A2544  data ov009
 *   g_021A254C     0x021A254C  data ov009
 *   g_021A2554     0x021A2554  data ov009
 *   g_021A255C     0x021A255C  data ov009
 *   g_021A2574     0x021A2574  data ov009
 *   g_021A2580     0x021A2580  data ov009
 */
struct DWCCalInfo;
struct DWCWiFiInfo;
typedef struct {
    char bytes[0x14];
} WiFiInfo;

typedef struct DWCCalInfo {
    char userid[14];
    char passwd[7];
    char gamecd[5];
    char makercd[3];
    char unitcd[2];
    char macadr[13];
    char lang[3];
    char birth[5];
    char devtime[13];
    char bssid[13];
    char ssid[33];
    char apinfo[14];
    unsigned short devname[11];
} DWCCalInfo;

typedef struct DWCWiFiInfo {
    unsigned long long attestedUserId;
    unsigned long long notAttestedId;
    unsigned short pass;
    unsigned short randomHistory;
} DWCWiFiInfo;

typedef struct RTCTime {
    unsigned long hour;
    unsigned long minute;
    unsigned long second;
} RTCTime;

typedef struct RTCDate {
    unsigned long year;
    unsigned long month;
    unsigned long day;
    int week;
} RTCDate;

typedef struct OSBirthday {
    unsigned char month;
    unsigned char day;
} OSBirthday;

typedef struct OSOwnerInfo {
    unsigned char language;
    unsigned char favoriteColor;
    OSBirthday birthday;
    unsigned short nickName[11];
    unsigned short nickNameLength;
    unsigned short comment[27];
    unsigned short commentLength;
} OSOwnerInfo;

typedef struct DWCHttp DWCHttp;

typedef unsigned char  u8;

typedef unsigned short u16;

extern void DWCi_BM_GetWiFiInfo(WiFiInfo *buf);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);
extern void OS_Terminate(void);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern void OS_GetMacAddress(unsigned char *macAddress);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern void OS_GetOwnerInfo(OSOwnerInfo *info);
extern int RTC_GetDateTime(RTCDate *date, RTCTime *time);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned char *func_02166384(void);
extern void func_020862B8(void *startAddr, unsigned long nBytes);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern unsigned char DWC_AC_GetApType(void);
extern unsigned char *func_021663C8(unsigned short *length);
extern int DWC_AC_GetApSpotInfo(unsigned char *apSpotInfo);
extern int strlen(const u8 *s);
extern int DWC_Http_Add_PostBase64Item(struct DWCHttp *http, char *label, char *data, unsigned long data_len);
extern int wcslen(const u16 *s);
extern int DWC_Http_Add_HeaderItem(char *http, char *label, char *data);
int func_02178F4C(void *cal);
int func_02178F78(DWCCalInfo *cal, DWCWiFiInfo *wifiinfo);
int func_02179218(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
extern const char g_021A2490[];
extern const char g_021A2498[];
extern const char g_021A24A0[];
extern const char g_021A24A8[];
extern const char g_021A24B4[];
extern const char g_021A24D0[];
extern const char g_021A24E0[];
extern const char g_021A24EC[];
extern const char g_021A24F4[];
extern const char g_021A24FC[];
extern const char g_021A2504[];
extern const char g_021A250C[];
extern const char g_021A2514[];
extern const char g_021A251C[];
extern const char g_021A2524[];
extern const char g_021A252C[];
extern const char g_021A2534[];
extern const char g_021A253C[];
extern const char g_021A2544[];
extern const char g_021A254C[];
extern const char g_021A2554[];
extern const char g_021A255C[];
extern const char g_021A2574[];
extern const char g_021A2580[];


/*
 * sdk:      DWC_Auth_GetCalInfoFromNVRAM (dwc_cal.o)
 */
int func_02178F4C(void *cal)
{
    WiFiInfo wifiinfo;
    DWCi_BM_GetWiFiInfo(&wifiinfo);
    return func_02178F78(cal, (struct DWCWiFiInfo *)(&wifiinfo));
}


/*
 * sdk:      DWC_Auth_GetCalInfoFromWiFiInfo (libdwcauth.TWL.HYB.a dwc_cal.o)
 */
int func_02178F78(DWCCalInfo *cal, DWCWiFiInfo *wifiinfo)
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
        OS_SNPrintf(cal->userid, sizeof(cal->userid), g_021A2490, wifiinfo->attestedUserId);
    else
        OS_SNPrintf(cal->userid, sizeof(cal->userid), g_021A2490, wifiinfo->notAttestedId);
    OS_SNPrintf(cal->passwd, sizeof(cal->passwd), g_021A2498, wifiinfo->pass);

    if (*(unsigned char *)0x02FFFE0C == 0)
        OS_Terminate();
    MI_CpuCopy8((void *)0x02FFFE0C, cal->gamecd, 4);
    if (*(unsigned char *)0x02FFFE10 == 0)
        OS_Terminate();
    MI_CpuCopy8((void *)0x02FFFE10, cal->makercd, 2);

    cal->unitcd[0] = '0';

    OS_GetMacAddress(macaddr);
    for (i = 0; i < 6; i++)
        OS_SPrintf(&cal->macadr[i * 2], g_021A24A0, macaddr[i]);

    OS_GetOwnerInfo(&ownerinfo);
    if (ownerinfo.language >= 8)
        ownerinfo.language = 1;
    OS_SNPrintf(cal->lang, sizeof(cal->lang), g_021A24A0, ownerinfo.language);
    MI_CpuCopy8(ownerinfo.nickName, cal->devname, 20);
    OS_SNPrintf(cal->birth, sizeof(cal->birth), g_021A24A8,
                  ownerinfo.birthday.month, ownerinfo.birthday.day);

    if (RTC_GetDateTime(&rtcdate, &rtctime) != 0)
        return 0;
    OS_SNPrintf(cal->devtime, sizeof(cal->devtime), g_021A24B4,
                  rtcdate.year, rtcdate.month, rtcdate.day,
                  rtctime.hour, rtctime.minute, rtctime.second);

    preirq = OS_DisableInterrupts();

    wcmbssid = func_02166384();
    func_020862B8(wcmbssid, 6);
    if (wcmbssid == 0) {
        OS_RestoreInterrupts(preirq);
        return 0;
    }
    for (i = 0; i < 6; i++)
        OS_SPrintf(&cal->bssid[i * 2], g_021A24A0, wcmbssid[i]);

    aptype = DWC_AC_GetApType();
    if (aptype == 0xff || aptype > 99)
        aptype = 99;
    OS_SNPrintf(cal->apinfo, sizeof(cal->apinfo), g_021A24D0, aptype);

    wcmessid = func_021663C8(&wcmessidlen);
    func_020862B8(wcmessid, 32);
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
int func_02179218(DWCHttp *http, DWCCalInfo *calinfo, int allowessid)
{
    char buf[33];

    OS_SNPrintf(buf, sizeof(buf), g_021A24E0, 5, 3);
    if (DWC_Http_Add_PostBase64Item(http, (char *)g_021A24EC, buf, strlen((const u8 *)buf)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)g_021A24F4, calinfo->userid, strlen((const u8 *)calinfo->userid)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)g_021A24FC, calinfo->passwd, strlen((const u8 *)calinfo->passwd)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)g_021A2504, calinfo->bssid, strlen((const u8 *)calinfo->bssid)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)g_021A250C, calinfo->apinfo, strlen((const u8 *)calinfo->apinfo)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)g_021A2514, calinfo->gamecd, strlen((const u8 *)calinfo->gamecd)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)g_021A251C, calinfo->makercd, strlen((const u8 *)calinfo->makercd)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)g_021A2524, calinfo->unitcd, strlen((const u8 *)calinfo->unitcd)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)g_021A252C, calinfo->macadr, strlen((const u8 *)calinfo->macadr)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)g_021A2534, calinfo->lang, strlen((const u8 *)calinfo->lang)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)g_021A253C, calinfo->birth, strlen((const u8 *)calinfo->birth)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)g_021A2544, calinfo->devtime, strlen((const u8 *)calinfo->devtime)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)g_021A254C, (char *)calinfo->devname, wcslen(calinfo->devname) * 2) != 0)
        return 0;
    if (allowessid == 1) {
        if (DWC_Http_Add_PostBase64Item(http, (char *)g_021A2554, calinfo->ssid, strlen((const u8 *)calinfo->ssid)) != 0)
            return 0;
    }

    OS_SNPrintf(buf, sizeof(buf), g_021A255C, 5, 3);
    if (DWC_Http_Add_HeaderItem((char *)http, (char *)g_021A2574, buf) != 0)
        return 0;
    if (DWC_Http_Add_HeaderItem((char *)http, (char *)g_021A2580, calinfo->gamecd) != 0)
        return 0;
    return 1;
}
