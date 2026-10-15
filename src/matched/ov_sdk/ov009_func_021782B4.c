/*
 * function: DWCi_Auth_Start
 * address:  0x021782B4
 * packet:   pkt_ov009_021782B4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Auth_Start (libdwcauth.TWL.HYB.a dwc_auth.o)
 *
 * symbols:
 *   strcmp  0x020948E0  arm
 *   DWC_Http_Create  0x0217956C  arm  ov009
 *   DWCi_BM_GetWiFiInfo  0x02058518  arm
 *   DWCi_Auth_Prepare_FirstPost  0x02178A94  arm  ov009
 *   DWC_Http_FinishHeader  0x0217967C  arm  ov009
 *   OS_GetThreadPriority  0x02085A30  arm
 *   DWC_Http_StartThread  0x02179718  arm  ov009
 *   g_021A2358  0x021A2358  data  ov009
 *   gDwcHttpParamArg  0x021A2358  data  ov009
 *   gDwcAuthNasUrl  0x021A2374  data  ov009
 *   gDwcAuthGlobal  0x021AB184  data  ov009
 *   gDwcWiFiInfo  0x021AB190  data  ov009
 *   gMslRefToken  0x02150FEC  data
 *
 * The pool carried 0x021A2358 twice: once for the url/f14/fc/f10 accesses and
 * once for the DWC_Http_Create argument, so the source named the struct through
 * two externs (docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-*).
 * With one name 1.1p1 CSEs both uses into a callee-saved register and the
 * function comes out one instruction (8 bytes) short.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_021782B4.c \
 *       --func DWCi_Auth_Start --addr 0x021782B4 --region ov009 --arm --cc 1.1p1 --lang c99 --diff
 */

#include "../include/G_DWCWFCUtil.h"
#include "../include/G_DWCHttpParam.h"

typedef struct DWCHttp DWCHttp;

typedef struct DWCHttpParam DWCHttpParam;

typedef struct DWCAuth
{
    char pad0[0x1004];
    int result;
    char pad1008[0x1cc - 0x8];
    unsigned short ingamesn[26];
    char pad1200[0];
} DWCAuth;

typedef struct DWCWFCUtil DWCWFCUtil;

typedef struct
{
    int f0;
    void *current;
} OSThreadInfo;

extern int strcmp(const char *, const char *);
extern int DWC_Http_Create(struct DWCHttp *http, struct DWCHttpParam *param);
struct tagDWCWiFiInfo;
extern void DWCi_BM_GetWiFiInfo(struct tagDWCWiFiInfo *buf);
extern int DWCi_Auth_Prepare_FirstPost(DWCHttp *http, char *gsbrcd, unsigned short *ingamesn);
extern int DWC_Http_FinishHeader(char *http);
extern unsigned long OS_GetThreadPriority(void *thread);
extern void DWC_Http_StartThread(char *http, unsigned long prio);

extern struct DWCHttpParam g_021A2358;
extern struct DWCHttpParam gDwcHttpParamArg;
extern char gDwcAuthNasUrl[];
extern struct DWCWFCUtil gDwcAuthGlobal;
extern char gDwcWiFiInfo[];
extern OSThreadInfo gMslRefToken;

#define AUTH_RESULT (*(int *)(((char *)gDwcAuthGlobal.auth) + 0x1004))
#define AUTH_HTTP (*(DWCHttp **)(((char *)gDwcAuthGlobal.auth) + 0x1314))

int DWCi_Auth_Start(int getwifiinfofromflash)
{
    if (strcmp(g_021A2358.url, gDwcAuthNasUrl) != 0)
        g_021A2358.f14 = 1;

    g_021A2358.fc = *(int *)(((char *)gDwcAuthGlobal.auth) + 0x120c);
    g_021A2358.f10 = *(int *)(((char *)gDwcAuthGlobal.auth) + 0x1210);
    if (DWC_Http_Create(AUTH_HTTP, &gDwcHttpParamArg) != 0)
        return 4;

    if (getwifiinfofromflash == 1)
        DWCi_BM_GetWiFiInfo((struct tagDWCWiFiInfo *)gDwcWiFiInfo);

    AUTH_RESULT = DWCi_Auth_Prepare_FirstPost(AUTH_HTTP, ((char *)gDwcAuthGlobal.auth) + 0x1200, (unsigned short *)(((char *)gDwcAuthGlobal.auth) + 0x11cc));
    if (AUTH_RESULT != 0)
        return 4;

    if (DWC_Http_FinishHeader((char *)AUTH_HTTP) != 0)
        return 4;

    DWC_Http_StartThread((char *)AUTH_HTTP, OS_GetThreadPriority(gMslRefToken.current) - 1);
    return 0;
}
