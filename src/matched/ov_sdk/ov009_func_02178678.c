/*
 * function: DWCi_Auth_ParseHttp
 * address:  0x02178678
 * packet:   pkt_ov009_02178678
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Auth_ParseHttp (libdwcauth.TWL.HYB.a dwc_auth.o)
 *
 * symbols:
 *   DWC_Http_ParseResult  0x0217A484  arm  ov009
 *   DWCi_Auth_FillResult  0x02178814  arm  ov009
 *   DWCi_AUTH_UpDateWiFiID  0x02058DD0  arm
 *   DWCi_AUTH_RemakeWiFiID  0x02058E20  arm
 *   DWCi_AUTH_MakeWiFiID  0x02058D88  arm
 *   gDwcAuthGlobal  0x021AB184  data  ov009
 *   gDwcWiFiInfo  0x021AB190  data  ov009
 */

#include "../include/G_DWCWFCUtil.h"

typedef struct DWCAuthParam
{
    unsigned short ingamesn[26];
    char gsbrcd[12];
    void *(*alloc)(unsigned long name, long size);
    void (*free)(unsigned long name, void *ptr, long size);
} DWCAuthParam;

typedef struct DWCAuth
{
    char pad0[0x1004];
    int result;
    int error;
    char pad100c[0x11cc - 0x100c];
    DWCAuthParam param;
    char pad1214[0x1314 - 0x1214];
    void *http;
    char pad1318[0x13f4 - 0x1318];
} DWCAuth;

typedef struct DWCWFCUtil DWCWFCUtil;

struct DWCHttp;
extern int DWC_Http_ParseResult(struct DWCHttp *http, int noparsebody);
extern int DWCi_Auth_FillResult(void);
struct tagDWCWiFiInfo;
extern int DWCi_AUTH_UpDateWiFiID(struct tagDWCWiFiInfo *wifiinfo, void *work);
extern int DWCi_AUTH_RemakeWiFiID(struct tagDWCWiFiInfo *wifiinfo);
extern int DWCi_AUTH_MakeWiFiID(void *work);

extern struct DWCWFCUtil gDwcAuthGlobal;
extern char gDwcWiFiInfo[];

int DWCi_Auth_ParseHttp(void)
{
    void *(*alloc)(unsigned long, long) = ((DWCAuth *)gDwcAuthGlobal.auth)->param.alloc;
    void (*free)(unsigned long, void *, long) = ((DWCAuth *)gDwcAuthGlobal.auth)->param.free;
    unsigned char *bmwork;

    if (DWC_Http_ParseResult(((DWCAuth *)gDwcAuthGlobal.auth)->http, 0) != 1)
    {
        ((DWCAuth *)gDwcAuthGlobal.auth)->error = 20100;
        return 14;
    }
    if (DWCi_Auth_FillResult() != 0)
        return 14;

    if (((DWCAuth *)gDwcAuthGlobal.auth)->error < 20100)
    {
        if (((DWCAuth *)gDwcAuthGlobal.auth)->error == 20002)
        {
            bmwork = (unsigned char *)alloc(0, 0x101f);
            if (bmwork == 0)
            {
                ((DWCAuth *)gDwcAuthGlobal.auth)->error = 20100;
                return 2;
            }
            if (DWCi_AUTH_UpDateWiFiID((struct tagDWCWiFiInfo *)gDwcWiFiInfo, (void *)(((unsigned long)bmwork + 31) & ~31)) != 1)
            {
                free(0, bmwork, 0);
                ((DWCAuth *)gDwcAuthGlobal.auth)->error = 20100;
                return 15;
            }
            free(0, bmwork, 0);
        }
        return 21;
    }
    switch (((DWCAuth *)gDwcAuthGlobal.auth)->error)
    {
    case 20104:
        DWCi_AUTH_RemakeWiFiID((struct tagDWCWiFiInfo *)gDwcWiFiInfo);
        ((DWCAuth *)gDwcAuthGlobal.auth)->error = 20104;
        return 16;
    case 20108:
        bmwork = (unsigned char *)alloc(0, 0x1000);
        if (bmwork == 0)
        {
            ((DWCAuth *)gDwcAuthGlobal.auth)->error = 20108;
            return 17;
        }
        DWCi_AUTH_MakeWiFiID((void *)(((unsigned long)bmwork + 31) & ~31));
        free(0, bmwork, 0);
        ((DWCAuth *)gDwcAuthGlobal.auth)->error = 20108;
        return 17;
    default:
        return 18;
    }
}
