/*
 * function: DWC_Auth_GetCalInfoFromWiFiInfo
 * address:  0x02178F78
 * packet:   pkt_ov009_02178F78
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Auth_GetCalInfoFromWiFiInfo (libdwcauth.TWL.HYB.a dwc_cal.o)
 *
 * symbols:
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
 *   func_020862B8  0x020862B8  arm
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
 */

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

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);
extern void OS_Terminate(void);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern void OS_GetMacAddress(unsigned char *macAddress);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern void OS_GetOwnerInfo(OSOwnerInfo *info);
extern int RTC_GetDateTime(RTCDate *date, RTCTime *time);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned char *WCM_GetApMacAddress(void);
extern void func_020862B8(void *startAddr, unsigned long nBytes);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern unsigned char DWC_AC_GetApType(void);
extern unsigned char *WCM_GetApEssid(unsigned short *length);
extern int DWC_AC_GetApSpotInfo(unsigned char *apSpotInfo);

extern const char gDwcCalFmtUserId[];
extern const char gDwcCalFmtPasswd[];
extern const char gDwcCalFmtHexByte[];
extern const char gDwcCalFmtBirth[];
extern const char gDwcCalFmtDevTime[];
extern const char gDwcCalFmtApInfo[];

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
    func_020862B8(wcmbssid, 6);
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
