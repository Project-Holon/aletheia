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
 *   DWC_Auth_GetCalInfoFromWiFiInfo  0x02178F78  arm  ov009
 *   DWC_Auth_SetCalInfoToHttp  0x02179218  arm  ov009
 *   wcslen  0x02096578  arm
 *   gDwcAuthGlobal  0x021AB184  data  ov009
 *   gDwcAuthPostValueAcctCreate  0x021A23E8  data  ov009
 *   gDwcAuthPostLabelAction  0x021A23F4  data  ov009
 *   gDwcAuthPostValueLogin  0x021A23FC  data  ov009
 *   gDwcAuthPostLabelGsbrcd  0x021A2404  data  ov009
 *   gDwcWiFiInfo  0x021AB190  data  ov009
 *   gDwcAuthAllowEssId  0x021ACE70  data  ov009
 *   gDwcAuthPostValueIsWfc  0x021A240C  data  ov009
 *   gDwcAuthPostLabelIsWfc  0x021A2410  data  ov009
 *   gDwcAuthPostLabelIngamesn  0x021A2418  data  ov009
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
extern int DWC_Auth_GetCalInfoFromWiFiInfo(struct DWCCalInfo *cal, struct DWCWiFiInfo *wifiinfo);
extern int DWC_Auth_SetCalInfoToHttp(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
extern int wcslen(const u16 *s);

extern struct DWCWFCUtil gDwcAuthGlobal;
extern char gDwcAuthPostValueAcctCreate[];
extern char gDwcAuthPostLabelAction[];
extern char gDwcAuthPostValueLogin[];
extern char gDwcAuthPostLabelGsbrcd[];
extern char gDwcWiFiInfo[];
extern int gDwcAuthAllowEssId;
extern char gDwcAuthPostValueIsWfc[];
extern char gDwcAuthPostLabelIsWfc[];
extern char gDwcAuthPostLabelIngamesn[];

int DWCi_Auth_Prepare_FirstPost(DWCHttp *http, char *gsbrcd, unsigned short *ingamesn)
{
    DWCCalInfo calinfo;

    if (gDwcAuthGlobal.userid == 0)
    {
        if (DWC_Http_Add_PostBase64Item(http, gDwcAuthPostLabelAction, gDwcAuthPostValueAcctCreate, strlen((const u8 *)gDwcAuthPostValueAcctCreate)) != 0)
            return 8;
    }
    else
    {
        if (DWC_Http_Add_PostBase64Item(http, gDwcAuthPostLabelAction, gDwcAuthPostValueLogin, strlen((const u8 *)gDwcAuthPostValueLogin)) != 0)
            return 8;
        if (DWC_Http_Add_PostBase64Item(http, gDwcAuthPostLabelGsbrcd, gsbrcd, strlen((const u8 *)gsbrcd)) != 0)
            return 8;
    }

    if (!DWC_Auth_GetCalInfoFromWiFiInfo(&calinfo, (struct DWCWiFiInfo *)gDwcWiFiInfo))
        return 5;
    if (!DWC_Auth_SetCalInfoToHttp(http, &calinfo, gDwcAuthAllowEssId))
        return 8;

    if (gDwcAuthGlobal.f0 == 1)
    {
        if (DWC_Http_Add_PostBase64Item(http, gDwcAuthPostLabelIsWfc, gDwcAuthPostValueIsWfc, strlen((const u8 *)gDwcAuthPostValueIsWfc)) != 0)
            return 8;
    }

    if (wcslen(ingamesn) != 0)
    {
        if (DWC_Http_Add_PostBase64Item(http, gDwcAuthPostLabelIngamesn, (char *)ingamesn, wcslen(ingamesn) * 2) != 0)
            return 8;
    }
    return 0;
}
