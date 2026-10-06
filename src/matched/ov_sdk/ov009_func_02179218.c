/*
 * function: func_02179218
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
 *   func_02084F80  0x02084F80  arm
 *   func_0209477C  0x0209477C  arm
 *   func_02179F3C  0x02179F3C  arm  ov009
 *   func_02096578  0x02096578  arm
 *   func_02179E60  0x02179E60  arm  ov009
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

extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);
extern int func_02179F3C(struct DWCHttp *http, char *label, char *data, unsigned long data_len);
typedef unsigned short u16;
extern int func_02096578(const u16 *s);
extern int func_02179E60(char *http, char *label, char *data);

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

int func_02179218(DWCHttp *http, DWCCalInfo *calinfo, int allowessid)
{
    char buf[33];

    func_02084F80(buf, sizeof(buf), g_021A24E0, 5, 3);
    if (func_02179F3C(http, (char *)g_021A24EC, buf, func_0209477C((const u8 *)buf)) != 0)
        return 0;
    if (func_02179F3C(http, (char *)g_021A24F4, calinfo->userid, func_0209477C((const u8 *)calinfo->userid)) != 0)
        return 0;
    if (func_02179F3C(http, (char *)g_021A24FC, calinfo->passwd, func_0209477C((const u8 *)calinfo->passwd)) != 0)
        return 0;
    if (func_02179F3C(http, (char *)g_021A2504, calinfo->bssid, func_0209477C((const u8 *)calinfo->bssid)) != 0)
        return 0;
    if (func_02179F3C(http, (char *)g_021A250C, calinfo->apinfo, func_0209477C((const u8 *)calinfo->apinfo)) != 0)
        return 0;
    if (func_02179F3C(http, (char *)g_021A2514, calinfo->gamecd, func_0209477C((const u8 *)calinfo->gamecd)) != 0)
        return 0;
    if (func_02179F3C(http, (char *)g_021A251C, calinfo->makercd, func_0209477C((const u8 *)calinfo->makercd)) != 0)
        return 0;
    if (func_02179F3C(http, (char *)g_021A2524, calinfo->unitcd, func_0209477C((const u8 *)calinfo->unitcd)) != 0)
        return 0;
    if (func_02179F3C(http, (char *)g_021A252C, calinfo->macadr, func_0209477C((const u8 *)calinfo->macadr)) != 0)
        return 0;
    if (func_02179F3C(http, (char *)g_021A2534, calinfo->lang, func_0209477C((const u8 *)calinfo->lang)) != 0)
        return 0;
    if (func_02179F3C(http, (char *)g_021A253C, calinfo->birth, func_0209477C((const u8 *)calinfo->birth)) != 0)
        return 0;
    if (func_02179F3C(http, (char *)g_021A2544, calinfo->devtime, func_0209477C((const u8 *)calinfo->devtime)) != 0)
        return 0;
    if (func_02179F3C(http, (char *)g_021A254C, (char *)calinfo->devname, func_02096578(calinfo->devname) * 2) != 0)
        return 0;
    if (allowessid == 1) {
        if (func_02179F3C(http, (char *)g_021A2554, calinfo->ssid, func_0209477C((const u8 *)calinfo->ssid)) != 0)
            return 0;
    }

    func_02084F80(buf, sizeof(buf), g_021A255C, 5, 3);
    if (func_02179E60((char *)http, (char *)g_021A2574, buf) != 0)
        return 0;
    if (func_02179E60((char *)http, (char *)g_021A2580, calinfo->gamecd) != 0)
        return 0;
    return 1;
}
