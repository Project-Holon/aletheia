/*
 * function: func_02178F78
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
 *   func_02084F80  0x02084F80  arm
 *   func_02088234  0x02088234  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_02084F40  0x02084F40  arm
 *   func_02087C88  0x02087C88  arm
 *   func_020889C0  0x020889C0  arm
 *   func_02087988  0x02087988  arm
 *   func_02166384  0x02166384  arm  ov009
 *   func_020862B8  0x020862B8  arm
 *   func_0208799C  0x0208799C  arm
 *   func_0205BDD0  0x0205BDD0  arm
 *   func_021663C8  0x021663C8  arm  ov009
 *   func_0205BE00  0x0205BE00  arm
 *   g_021A2490     0x021A2490  data ov009
 *   g_021A2498     0x021A2498  data ov009
 *   g_021A24A0     0x021A24A0  data ov009
 *   g_021A24A8     0x021A24A8  data ov009
 *   g_021A24B4     0x021A24B4  data ov009
 *   g_021A24D0     0x021A24D0  data ov009
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
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
extern void func_02088234(void);
extern void func_02082D44(const void *srcp, void *dstp, unsigned long size);
extern void func_02087C6C(unsigned char *macAddress);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern void func_02087C88(OSOwnerInfo *info);
extern int func_020889C0(RTCDate *date, RTCTime *time);
extern unsigned long func_02087988(void);
extern unsigned char *func_02166384(void);
extern void func_020862B8(void *startAddr, unsigned long nBytes);
extern unsigned long func_0208799C(unsigned long state);
extern unsigned char func_0205BDD0(void);
extern unsigned char *func_021663C8(unsigned short *length);
extern int func_0205BE00(unsigned char *apSpotInfo);

extern const char g_021A2490[];
extern const char g_021A2498[];
extern const char g_021A24A0[];
extern const char g_021A24A8[];
extern const char g_021A24B4[];
extern const char g_021A24D0[];

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
        func_02084F80(cal->userid, sizeof(cal->userid), g_021A2490, wifiinfo->attestedUserId);
    else
        func_02084F80(cal->userid, sizeof(cal->userid), g_021A2490, wifiinfo->notAttestedId);
    func_02084F80(cal->passwd, sizeof(cal->passwd), g_021A2498, wifiinfo->pass);

    if (*(unsigned char *)0x02FFFE0C == 0)
        func_02088234();
    func_02082D44((void *)0x02FFFE0C, cal->gamecd, 4);
    if (*(unsigned char *)0x02FFFE10 == 0)
        func_02088234();
    func_02082D44((void *)0x02FFFE10, cal->makercd, 2);

    cal->unitcd[0] = '0';

    func_02087C6C(macaddr);
    for (i = 0; i < 6; i++)
        func_02084F40(&cal->macadr[i * 2], g_021A24A0, macaddr[i]);

    func_02087C88(&ownerinfo);
    if (ownerinfo.language >= 8)
        ownerinfo.language = 1;
    func_02084F80(cal->lang, sizeof(cal->lang), g_021A24A0, ownerinfo.language);
    func_02082D44(ownerinfo.nickName, cal->devname, 20);
    func_02084F80(cal->birth, sizeof(cal->birth), g_021A24A8,
                  ownerinfo.birthday.month, ownerinfo.birthday.day);

    if (func_020889C0(&rtcdate, &rtctime) != 0)
        return 0;
    func_02084F80(cal->devtime, sizeof(cal->devtime), g_021A24B4,
                  rtcdate.year, rtcdate.month, rtcdate.day,
                  rtctime.hour, rtctime.minute, rtctime.second);

    preirq = func_02087988();

    wcmbssid = func_02166384();
    func_020862B8(wcmbssid, 6);
    if (wcmbssid == 0) {
        func_0208799C(preirq);
        return 0;
    }
    for (i = 0; i < 6; i++)
        func_02084F40(&cal->bssid[i * 2], g_021A24A0, wcmbssid[i]);

    aptype = func_0205BDD0();
    if (aptype == 0xff || aptype > 99)
        aptype = 99;
    func_02084F80(cal->apinfo, sizeof(cal->apinfo), g_021A24D0, aptype);

    wcmessid = func_021663C8(&wcmessidlen);
    func_020862B8(wcmessid, 32);
    if (wcmessid == 0) {
        func_0208799C(preirq);
        return 0;
    }
    func_02082D44(wcmessid, cal->ssid, 32);
    func_0205BE00((unsigned char *)&cal->apinfo[3]);

    func_0208799C(preirq);
    return 1;
}
