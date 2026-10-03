/*
 * function: func_02178A94
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
 *   func_0209477C  0x0209477C  arm
 *   func_02179F3C  0x02179F3C  arm  ov009
 *   func_02178F78  0x02178F78  arm  ov009
 *   func_02179218  0x02179218  arm  ov009
 *   func_02096578  0x02096578  arm
 *   g_021AB184  0x021AB184  data  ov009
 *   g_021A23E8  0x021A23E8  data  ov009
 *   g_021A23F4  0x021A23F4  data  ov009
 *   g_021A23FC  0x021A23FC  data  ov009
 *   g_021A2404  0x021A2404  data  ov009
 *   g_021AB190  0x021AB190  data  ov009
 *   g_021ACE70  0x021ACE70  data  ov009
 *   g_021A240C  0x021A240C  data  ov009
 *   g_021A2410  0x021A2410  data  ov009
 *   g_021A2418  0x021A2418  data  ov009
 */

typedef struct DWCHttp DWCHttp;

typedef struct DWCCalInfo
{
    char data[0x94];
} DWCCalInfo;

typedef struct DWCWFCUtil
{
    int f0;
    void *auth;
    int state;
    unsigned long long userid;
} DWCWFCUtil;

extern unsigned long func_0209477C(const char *s);
typedef unsigned short u16;
extern int func_02179F3C(struct DWCHttp *http, char *label, char *data, unsigned long data_len);
extern int func_02178F78(DWCCalInfo *cal, void *wifiinfo);
extern int func_02179218(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
extern int func_02096578(const u16 *s);

extern DWCWFCUtil g_021AB184;
extern char g_021A23E8[];
extern char g_021A23F4[];
extern char g_021A23FC[];
extern char g_021A2404[];
extern char g_021AB190[];
extern int g_021ACE70;
extern char g_021A240C[];
extern char g_021A2410[];
extern char g_021A2418[];

int func_02178A94(DWCHttp *http, char *gsbrcd, unsigned short *ingamesn)
{
    DWCCalInfo calinfo;

    if (g_021AB184.userid == 0)
    {
        if (func_02179F3C(http, g_021A23F4, g_021A23E8, func_0209477C(g_021A23E8)) != 0)
            return 8;
    }
    else
    {
        if (func_02179F3C(http, g_021A23F4, g_021A23FC, func_0209477C(g_021A23FC)) != 0)
            return 8;
        if (func_02179F3C(http, g_021A2404, gsbrcd, func_0209477C(gsbrcd)) != 0)
            return 8;
    }

    if (!func_02178F78(&calinfo, g_021AB190))
        return 5;
    if (!func_02179218(http, &calinfo, g_021ACE70))
        return 8;

    if (g_021AB184.f0 == 1)
    {
        if (func_02179F3C(http, g_021A2410, g_021A240C, func_0209477C(g_021A240C)) != 0)
            return 8;
    }

    if (func_02096578(ingamesn) != 0)
    {
        if (func_02179F3C(http, g_021A2418, (char *)ingamesn, func_02096578(ingamesn) * 2) != 0)
            return 8;
    }
    return 0;
}
