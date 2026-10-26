/*
 * file:     dwc_svl.c
 * unit:     yes
 * function: DWC_Svl_Init, DWC_Svl_Cleanup, DWC_Svl_GetTokenAsync, DWC_Svl_Process, DWCi_Svl_ParseHttp
 * address:  0x0217C070
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Svl_Cleanup, DWC_Svl_GetTokenAsync, DWC_Svl_Process,
 *           DWCi_Svl_ParseHttp (libdwcauth.TWL.HYB.a dwc_svl.o)
 *
 * symbols:
 *   DWCi_SetError  0x02059F54  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_Terminate  0x02088234  arm
 *   strcmp  0x020948E0  arm
 *   DWC_Http_Create  0x0217956C  arm  ov009
 *   DWC_Auth_GetCalInfoFromNVRAM  0x02178F4C  arm  ov009
 *   DWC_Auth_SetCalInfoToHttp  0x02179218  arm  ov009
 *   DWC_Http_Destroy  0x02179CF4  arm  ov009
 *   DWC_Http_Add_PostBase64Item  0x02179F3C  arm  ov009
 *   DWC_Http_FinishHeader  0x0217967C  arm  ov009
 *   OS_GetThreadPriority  0x02085A30  arm
 *   DWC_Http_StartThread  0x02179718  arm  ov009
 *   DWC_Http_ParseResult  0x0217A484  arm  ov009
 *   DWC_Http_GetResult  0x0217A728  arm  ov009
 *   DWC_Auth_SetNasTimeDiff  0x02168250  arm  ov009
 *   atoi  0x020964E0  arm
 *   DWC_Http_GetBase64DecodedResult  0x0217A77C  arm  ov009
 *   gDwcSvlWorkarea     0x021ACEF4  data ov009
 *   gDwcHttpParamArg     0x021A2358  data ov009
 *   gDwcSvlNasUrl     0x021A2840  data ov009
 *   gDwcSvlPostLabelAction     0x021A2860  data ov009
 *   gDwcSvlPostValueSvcloc     0x021A2868  data ov009
 *   gDwcSvlPostLabelSvc     0x021A2870  data ov009
 *   gDwcSvlLabelDate     0x021A2874  data ov009
 *   gDwcSvlLabelHttpResult     0x021A287C  data ov009
 *   errno     0x02153FAC  data
 *   gDwcSvlLabelReturnCd     0x021A2888  data ov009
 *   gDwcSvlLabelSvcHost     0x021A2894  data ov009
 *   gDwcSvlLabelServiceToken     0x021A289C  data ov009
 *   gDwcSvlLabelStatusData     0x021A28AC  data ov009
 *   OSi_ThreadInfo     0x02150FEC  data
 *
 * Service-locator (SVL) token request on top of the DWC HTTP client.  The
 * control block gDwcSvlWorkarea is one DWCSvlIntWorkarea (0x1C5C bytes): the
 * caller's alloc and free callbacks, the embedded DWCHttp, and the result
 * pointer.  strcmp (strcmp) is declared pure: the object keeps the
 * intwork load live across the call, which only a side-effect-free callee
 * allows.
 */

#include "../types.h"

#include "../sdk_os.h"

#include "dwc_http_types.h"
#include "../sdk_dwc.h"

#include "cps_ssl_types.h"

typedef struct DWCSvlIntWorkarea {
    DWCAuthAlloc alloc;
    DWCAuthFree free;
    DWCHttp http;
    DWCSvlResult *result;
} DWCSvlIntWorkarea;

#include "../arm9/dwc_error.h"
#include "../arm9/mi_memory.h"
#include "../arm9/os_thread.h"
#include "../arm9/os_terminate_processor.h"
extern int strcmp(const char *s1, const char *s2) __attribute__((pure));
#include "dwc_http.h"
#include "dwc_cal.h"
#include "dwc_nastime.h"
#include "../arm9/msl_strtod.h"
int DWCi_Svl_ParseHttp(void);

extern DWCSvlIntWorkarea *gDwcSvlWorkarea;
extern DWCAuthHttpParam gDwcHttpParamArg;
extern char gDwcSvlNasUrl[];
extern char gDwcSvlPostLabelAction[];
extern char gDwcSvlPostValueSvcloc[];
extern char gDwcSvlPostLabelSvc[];
extern char gDwcSvlLabelDate[];
extern char gDwcSvlLabelHttpResult[];
extern int errno;
extern char gDwcSvlLabelReturnCd[];
extern char gDwcSvlLabelSvcHost[];
extern char gDwcSvlLabelServiceToken[];
extern char gDwcSvlLabelStatusData[];

int DWC_Svl_Init(DWCAuthAlloc alloc, DWCAuthFree free)
{
    void *p;

    if (gDwcSvlWorkarea != 0) {
        DWCi_SetError(9, -24100);
        return 0;
    }

    p = alloc(0, sizeof(DWCSvlIntWorkarea));
    gDwcSvlWorkarea = p;
    if (p == 0) {
        DWCi_SetError(9, -24100);
        return 0;
    }

    MI_CpuFill8(p, 0, sizeof(DWCSvlIntWorkarea));

    gDwcSvlWorkarea->alloc = alloc;
    gDwcSvlWorkarea->free = free;
    return 1;
}

/*
 * sdk:      DWC_Svl_Cleanup (dwc_svl.o)
 */
void DWC_Svl_Cleanup(void)
{
    if (gDwcSvlWorkarea == 0) {
        return;
    }
    DWC_Http_Destroy((&gDwcSvlWorkarea->http));
    gDwcSvlWorkarea->free(0, gDwcSvlWorkarea, 0);
    gDwcSvlWorkarea = 0;
}

/*
 * sdk:      DWC_Svl_GetTokenAsync (libdwcauth.TWL.HYB.a dwc_svl.o)
 *
 * strcmp (strcmp) is declared pure: the object keeps the intwork
 * load live across the call, which only a side-effect-free callee allows.
 */
int DWC_Svl_GetTokenAsync(char *svc, DWCSvlResult *result)
{
    DWCHttpParam httpparam;
    DWCCalInfo calinfo;

    gDwcSvlWorkarea->result = result;
    MI_CpuFill8(result, 0, sizeof(DWCSvlResult));

    if (gDwcSvlWorkarea->http.thread.id != 0 && !OS_IsThreadTerminated(&gDwcSvlWorkarea->http.thread))
        OS_Terminate();

    httpparam.url = gDwcHttpParamArg.url;
    httpparam.action = 0;
    httpparam.len_recvbuf = 0x1000;
    httpparam.alloc = gDwcSvlWorkarea->alloc;
    httpparam.free = gDwcSvlWorkarea->free;
    if (strcmp(gDwcHttpParamArg.url, gDwcSvlNasUrl) != 0)
        httpparam.ignoreca = 1;
    else
        httpparam.ignoreca = 0;
    httpparam.timeout = 20000;

    if (DWC_Http_Create(&gDwcSvlWorkarea->http, &httpparam) != 0) {
        DWCi_SetError(9, -24100);
        return 0;
    }

    if (!DWC_Auth_GetCalInfoFromNVRAM(&calinfo) || !DWC_Auth_SetCalInfoToHttp(&gDwcSvlWorkarea->http, &calinfo, 0)) {
        DWC_Http_Destroy((&gDwcSvlWorkarea->http));
        DWCi_SetError(9, -24100);
        return 0;
    }

    if (DWC_Http_Add_PostBase64Item(&gDwcSvlWorkarea->http, gDwcSvlPostLabelAction, gDwcSvlPostValueSvcloc, 6) != 0
        || DWC_Http_Add_PostBase64Item(&gDwcSvlWorkarea->http, gDwcSvlPostLabelSvc, svc, 4) != 0) {
        DWC_Http_Destroy((&gDwcSvlWorkarea->http));
        DWCi_SetError(9, -24100);
        return 0;
    }

    if (DWC_Http_FinishHeader((&gDwcSvlWorkarea->http)) != 0) {
        DWC_Http_Destroy((&gDwcSvlWorkarea->http));
        DWCi_SetError(9, -24100);
        return 0;
    }

    DWC_Http_StartThread((&gDwcSvlWorkarea->http), OS_GetThreadPriority(OSi_ThreadInfo.current) - 1);
    if (gDwcSvlWorkarea->http.thread.id == 0) {
        DWC_Http_Destroy((&gDwcSvlWorkarea->http));
        DWCi_SetError(9, -24100);
        return 0;
    }
    return 1;
}

/*
 * sdk:      DWC_Svl_Process (dwc_svl.o)
 */
int DWC_Svl_Process(void)
{
    if (gDwcSvlWorkarea == 0) {
        return 0;
    }
    if (gDwcSvlWorkarea->http.thread.id == 0) {
        return 1;
    }
    if (OS_IsThreadTerminated(&gDwcSvlWorkarea->http.thread) == 1) {
        switch (gDwcSvlWorkarea->http.error) {
        case 8:
            if (DWCi_Svl_ParseHttp() == 0) {
                DWC_Http_Destroy((&gDwcSvlWorkarea->http));
                return 4;
            }
            DWC_Http_Destroy((&gDwcSvlWorkarea->http));
            return 3;
        case 7:
            DWC_Http_Destroy((&gDwcSvlWorkarea->http));
            return 5;
        default:
            DWC_Http_Destroy((&gDwcSvlWorkarea->http));
            DWCi_SetError(0x10, -24101);
            return 4;
        }
    }
    return 2;
}

/*
 * sdk:      DWCi_Svl_ParseHttp (libdwcauth.TWL.HYB.a dwc_svl.o)
 */
int DWCi_Svl_ParseHttp(void)
{
    char *strp;
    int httpretcode;
    char retcode[4];
    DWCHttp *DWChttp = &gDwcSvlWorkarea->http;

    if (!DWC_Http_ParseResult(DWChttp, 0)) {
        DWCi_SetError(15, -25101);
        return 0;
    }

    strp = DWC_Http_GetResult(DWChttp, gDwcSvlLabelDate);
    if (strp != 0)
        DWC_Auth_SetNasTimeDiff(strp);

    strp = DWC_Http_GetResult(DWChttp, gDwcSvlLabelHttpResult);
    if (strp == 0) {
        DWCi_SetError(15, -25101);
        return 0;
    }
    httpretcode = atoi(strp);
    if (errno == 34) {
        DWCi_SetError(15, -25101);
        return 0;
    }
    if (httpretcode != 200) {
        DWCi_SetError(15, -25000 - httpretcode);
        return 0;
    }

    if (DWC_Http_GetBase64DecodedResult(DWChttp, gDwcSvlLabelReturnCd, retcode, 4) <= 0) {
        DWCi_SetError(15, -25101);
        return 0;
    }
    httpretcode = atoi(retcode);
    if (errno == 34) {
        DWCi_SetError(15, -25101);
        return 0;
    }
    if (httpretcode >= 100) {
        DWCi_SetError(15, -24000 - httpretcode);
        return 0;
    }

    if (DWC_Http_GetBase64DecodedResult(DWChttp, gDwcSvlLabelSvcHost, gDwcSvlWorkarea->result->svlhost, 64) < 0
        || DWC_Http_GetBase64DecodedResult(DWChttp, gDwcSvlLabelServiceToken, gDwcSvlWorkarea->result->svltoken, 300) < 0
        || DWC_Http_GetBase64DecodedResult(DWChttp, gDwcSvlLabelStatusData, retcode, 1) < 0) {
        DWCi_SetError(15, -25101);
        return 0;
    }

    gDwcSvlWorkarea->result->status = (retcode[0] == 'Y') ? 1 : 0;
    return 1;
}
