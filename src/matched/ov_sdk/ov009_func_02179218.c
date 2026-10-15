/*
 * function: DWC_Auth_SetCalInfoToHttp
 * address:  0x02179218
 * packet:   pkt_ov009_02179218
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Auth_SetCalInfoToHttp (libdwcauth.TWL.HYB.a dwc_cal.o)
 *
 * symbols:
 *   OS_SNPrintf  0x02084F80  arm
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

typedef struct DWCHttp DWCHttp;

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

extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);
typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern int DWC_Http_Add_PostBase64Item(struct DWCHttp *http, char *label, char *data, unsigned long data_len);
typedef unsigned short u16;
extern int wcslen(const u16 *s);
extern int DWC_Http_Add_HeaderItem(char *http, char *label, char *data);

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

int DWC_Auth_SetCalInfoToHttp(DWCHttp *http, DWCCalInfo *calinfo, int allowessid)
{
    char buf[33];

    OS_SNPrintf(buf, sizeof(buf), gDwcCalFmtVersion, 5, 3);
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyVersion, buf, strlen((const u8 *)buf)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyUserId, calinfo->userid, strlen((const u8 *)calinfo->userid)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyPasswd, calinfo->passwd, strlen((const u8 *)calinfo->passwd)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyBssid, calinfo->bssid, strlen((const u8 *)calinfo->bssid)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyApInfo, calinfo->apinfo, strlen((const u8 *)calinfo->apinfo)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyGameCd, calinfo->gamecd, strlen((const u8 *)calinfo->gamecd)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyMakerCd, calinfo->makercd, strlen((const u8 *)calinfo->makercd)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyUnitCd, calinfo->unitcd, strlen((const u8 *)calinfo->unitcd)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyMacAdr, calinfo->macadr, strlen((const u8 *)calinfo->macadr)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyLang, calinfo->lang, strlen((const u8 *)calinfo->lang)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyBirth, calinfo->birth, strlen((const u8 *)calinfo->birth)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyDevTime, calinfo->devtime, strlen((const u8 *)calinfo->devtime)) != 0)
        return 0;
    if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeyDevName, (char *)calinfo->devname, wcslen(calinfo->devname) * 2) != 0)
        return 0;
    if (allowessid == 1) {
        if (DWC_Http_Add_PostBase64Item(http, (char *)gDwcCalKeySsid, calinfo->ssid, strlen((const u8 *)calinfo->ssid)) != 0)
            return 0;
    }

    OS_SNPrintf(buf, sizeof(buf), gDwcCalFmtHeaderVersion, 5, 3);
    if (DWC_Http_Add_HeaderItem((char *)http, (char *)gDwcCalHeaderVersion, buf) != 0)
        return 0;
    if (DWC_Http_Add_HeaderItem((char *)http, (char *)gDwcCalHeaderGameCd, calinfo->gamecd) != 0)
        return 0;
    return 1;
}
