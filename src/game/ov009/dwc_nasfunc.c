/*
 * file:     dwc_nasfunc.c
 * unit:     yes
 * function: DWC_GetDateTime, DWC_SVLGetTokenAsync, DWC_SVLProcess, DWC_NASLoginAsync, DWC_NASLoginProcess
 * address:  0x02167ED8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   RTC_GetDateTime  0x020889C0  arm
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   RTC_ConvertSecondToDateTime  0x020891E0  arm
 *   gDwcNasTimeDiff     0x021AA834  data
 *   gDwcNasTimeBase     0x021AA838  data
 *   gDwcNasTimeOffset     0x021AA840  data
 *   DWC_Auth_GetId  0x02058FB4  arm
 *   DWC_Svl_Init  0x0217C070  arm  ov009
 *   strlen  0x0209477C  arm
 *   DWC_Svl_GetTokenAsync  0x0217C144  arm  ov009
 *   DWC_Svl_Cleanup  0x0217C104  arm  ov009
 *   DWC_Alloc      0x0205A16C  arm
 *   DWC_Free       0x0205A1B0  arm
 *   gDwcNasTokenInitial     0x021A1F6C  data
 *   DWC_Svl_Process  0x0217C384  arm  ov009
 *   OS_Terminate   0x02088234  arm
 *   DWCi_SetError  0x02059F54  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   DWC_Auth_Create  0x02177EE8  arm  ov009
 *   gDwcNasCnt     0x021AA830  data
 *   gDwcNasInitialId     0x021A1F74  data
 *   DWC_Auth_GetError  0x021781DC  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   DWC_Auth_GetResult  0x02178224  arm  ov009
 *   DWC_Auth_Destroy  0x02178144  arm  ov009
 *   DWC_Free  0x0205A1B0  arm
 *   DWCi_SetError  0x02059F54  arm
 */
typedef struct NasTimeDiff {
    int valid;
    long long base;
    long long diff;
} NasTimeDiff;

#include "dwc_auth.h"
#include "../arm9/util_wifiidtool.h"
#include "../sdk_rtc.h"

typedef struct AuthId {
    int ids[4];
    int useA;
} AuthId;

#include "../types.h"

#include "../sdk_dwc.h"

typedef struct {
    int returncode;
    char retcode[4];
    char datetime[15];
    char locator[51];
    char token[301];
    char challenge[9];
    char cookie[65];
} AuthResult;

typedef struct NalCnt {
    unsigned char http[0x1C50];
    unsigned char auth[0x1C84 - 0x1C50];
    unsigned char id[0x1C90 - 0x1C84];
    void *(*alloc)(int, unsigned long);
    void (*free)(int, void *, unsigned long);
    AuthResult result;
} NalCnt;

#include "../arm9/external.h"
#include "../arm9/convert.h"
extern int DWC_Svl_Init(void *(*alloc)(int, unsigned long), void (*free)(int, void *, unsigned long));
#include "../arm9/msl_string_str.h"
#include "dwc_svl.h"
#include "../arm9/dwc_memfunc.h"
#include "../arm9/os_terminate_processor.h"
#include "../arm9/dwc_error.h"
#include "../arm9/mi_memory.h"
extern int DWC_Auth_GetError(void);
extern void DWC_Auth_GetResult(int *result);
extern void DWC_Auth_Destroy(void);
extern NasTimeDiff gDwcNasTimeDiff;
extern long long gDwcNasTimeBase;
extern long long gDwcNasTimeOffset;
extern char gDwcNasTokenInitial[];
extern char gDwcNasInitialId[];
extern NalCnt *gDwcNasCnt;
int DWC_GetDateTime(void *date, void *time);
int DWC_SVLGetTokenAsync(char *svl, void *result);
int DWC_SVLProcess(void);
int DWC_NASLoginAsync(void);
int DWC_NASLoginProcess(void);

/*
 * sdk:      DWC_GetDateTime (libdwcnas.TWL.HYB.a dwc_nasfunc.o)
 */
int DWC_GetDateTime(void *date, void *time)
{
    long long localsec;

    if ((*(int *)&gDwcNasTimeDiff) == 0)
        return 0;
    if (RTC_GetDateTime(date, time) != 0)
        return 0;
    localsec = RTC_ConvertDateTimeToSecond(date, time);
    if (localsec == -1LL)
        return 0;
    if (localsec < gDwcNasTimeBase)
        localsec += 3155760000LL;
    localsec -= gDwcNasTimeOffset;
    if (localsec < 0 || localsec > 3155759999LL)
        return 0;
    RTC_ConvertSecondToDateTime(date, time, localsec);
    return 1;
}

/*
 * sdk:      DWC_SVLGetTokenAsync (libdwcnas.TWL.HYB.a dwc_nasfunc.o)
 */
int DWC_SVLGetTokenAsync(char *svl, void *result)
{
    AuthId id;
    int flag;

    DWC_Auth_GetId((struct DWCAuthWiFiId *)&id);
    if (id.useA == 0)
        return 0;
    if (DWC_Svl_Init(DWC_Alloc, DWC_Free) == 0)
        return 0;
    if (strlen(svl) == 0)
        flag = DWC_Svl_GetTokenAsync(gDwcNasTokenInitial, result);
    else
        flag = DWC_Svl_GetTokenAsync(svl, result);
    if (flag != 0)
        return 1;
    DWC_Svl_Cleanup();
    return 0;
}

/*
 * Calls DWC_Svl_Cleanup when DWC_Svl_Process returns 3 to 5.
 */
int DWC_SVLProcess(void)
{
    int v = DWC_Svl_Process();
    if ((u32)(v - 3) <= 2) DWC_Svl_Cleanup();
    return v;
}

/*
 * sdk:      DWC_NASLoginAsync (libdwcnas.TWL.HYB.a dwc_nasfunc.o)
 */
int DWC_NASLoginAsync(void)
{
    if (gDwcNasCnt != 0)
        OS_Terminate();
    gDwcNasCnt = DWC_Alloc(4, 0x1E5C);
    if (gDwcNasCnt == 0) {
        DWCi_SetError(9, -20100);
        return 0;
    }
    MI_CpuFill8(gDwcNasCnt, 0, 0x1E5C);
    MI_CpuCopy8(gDwcNasInitialId, gDwcNasCnt->id, 9);
    gDwcNasCnt->alloc = DWC_Alloc;
    gDwcNasCnt->free = DWC_Free;
    DWC_Auth_Create((struct DWCAuthParam *)gDwcNasCnt->auth, (DWCHttp *)gDwcNasCnt);
    return 1;
}

/*
 * sdk:      DWC_NASLoginProcess (libdwcnas.TWL.HYB.a dwc_nasfunc.o)
 */
int DWC_NASLoginProcess(void)
{
    AuthResult result;

    if (gDwcNasCnt == 0)
        return 0;
    switch (DWC_Auth_GetError()) {
    case 0:
        return 2;
    case 0x15:
        MI_CpuFill8(&result, 0, sizeof(result));
        DWC_Auth_GetResult((int *)(&result));
        DWC_Auth_Destroy();
        if (result.returncode == 20002) {
            DWC_Auth_Create((struct DWCAuthParam *)gDwcNasCnt->auth, (DWCHttp *)gDwcNasCnt->http);
            return 2;
        }
        DWC_Free(4, gDwcNasCnt, 7772);
        gDwcNasCnt = 0;
        return 3;
    case 0x14:
        DWC_Auth_Destroy();
        DWC_Free(4, gDwcNasCnt, 7772);
        gDwcNasCnt = 0;
        return 5;
    default:
        DWC_Auth_GetResult((int *)(&result));
        DWC_Auth_Destroy();
        DWC_Free(4, gDwcNasCnt, 7772);
        gDwcNasCnt = 0;
        DWCi_SetError(2, result.returncode);
        return 4;
    }
}
