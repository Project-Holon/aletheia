/*
 * function: DWCi_Auth_Prepare_FirstPost
 * address:  0x02178A94
 * packet:   pkt_ov009_02178A94
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Auth_Prepare_FirstPost (libdwcauth.TWL.HYB.a dwc_auth.o)
 *
 * symbols:
 *   strlen  0x0209477C  arm
 *   DWC_Http_Add_PostBase64Item  0x02179F3C  arm  ov009
 *   func_02178F78  0x02178F78  arm  ov009
 *   func_02179218  0x02179218  arm  ov009
 *   wcslen  0x02096578  arm
 *   gDwcAuthGlobal  0x021AB184  data  ov009
 *   g_021A23E8  0x021A23E8  data  ov009
 *   g_021A23F4  0x021A23F4  data  ov009
 *   g_021A23FC  0x021A23FC  data  ov009
 *   g_021A2404  0x021A2404  data  ov009
 *   gDwcWiFiInfo  0x021AB190  data  ov009
 *   g_021ACE70  0x021ACE70  data  ov009
 *   g_021A240C  0x021A240C  data  ov009
 *   g_021A2410  0x021A2410  data  ov009
 *   g_021A2418  0x021A2418  data  ov009
 */

#include "../include/G_DWCWFCUtil.h"

typedef struct DWCHttp DWCHttp;

typedef struct DWCCalInfo
{
    char data[0x94];
} DWCCalInfo;

typedef struct DWCWFCUtil DWCWFCUtil;

typedef unsigned char  u8;
struct DWCWiFiInfo;
extern int strlen(const u8 *s);
typedef unsigned short u16;
extern int DWC_Http_Add_PostBase64Item(struct DWCHttp *http, char *label, char *data, unsigned long data_len);
extern int func_02178F78(struct DWCCalInfo *cal, struct DWCWiFiInfo *wifiinfo);
extern int func_02179218(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
extern int wcslen(const u16 *s);

extern struct DWCWFCUtil gDwcAuthGlobal;
extern char g_021A23E8[];
extern char g_021A23F4[];
extern char g_021A23FC[];
extern char g_021A2404[];
extern char gDwcWiFiInfo[];
extern int g_021ACE70;
extern char g_021A240C[];
extern char g_021A2410[];
extern char g_021A2418[];

int DWCi_Auth_Prepare_FirstPost(DWCHttp *http, char *gsbrcd, unsigned short *ingamesn)
{
    DWCCalInfo calinfo;

    if (gDwcAuthGlobal.userid == 0)
    {
        if (DWC_Http_Add_PostBase64Item(http, g_021A23F4, g_021A23E8, strlen((const u8 *)g_021A23E8)) != 0)
            return 8;
    }
    else
    {
        if (DWC_Http_Add_PostBase64Item(http, g_021A23F4, g_021A23FC, strlen((const u8 *)g_021A23FC)) != 0)
            return 8;
        if (DWC_Http_Add_PostBase64Item(http, g_021A2404, gsbrcd, strlen((const u8 *)gsbrcd)) != 0)
            return 8;
    }

    if (!func_02178F78(&calinfo, (struct DWCWiFiInfo *)gDwcWiFiInfo))
        return 5;
    if (!func_02179218(http, &calinfo, g_021ACE70))
        return 8;

    if (gDwcAuthGlobal.f0 == 1)
    {
        if (DWC_Http_Add_PostBase64Item(http, g_021A2410, g_021A240C, strlen((const u8 *)g_021A240C)) != 0)
            return 8;
    }

    if (wcslen(ingamesn) != 0)
    {
        if (DWC_Http_Add_PostBase64Item(http, g_021A2418, (char *)ingamesn, wcslen(ingamesn) * 2) != 0)
            return 8;
    }
    return 0;
}
