/*
 * file:     dwc_auth.c
 * unit:     yes
 * function: DWC_Auth_SetCustomNas, DWC_Auth_GetCustomNas, DWC_Auth_Create, DWCi_Auth_StartThread, DWC_Auth_Abort, DWC_Auth_Destroy, DWC_Auth_Join, DWC_Auth_GetError, DWC_Auth_GetResult, DWCi_Auth_Start, DWCi_Auth_Thread, DWCi_Auth_ParseHttp, DWCi_Auth_FillResult, DWCi_Auth_Prepare_FirstPost, DWCi_Auth_SetError
 * address:  0x02177EC8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Sets the word at the state object.
 *
 * symbols:
 *   g_021A2358  0x021A2358  data
 *   MI_CpuFill8  0x02082BCC  arm
 *   gDwcAuthGlobal  0x021AB184  data  ov009
 *   OS_InitMutex  0x02086004  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_CreateThread  0x020853C0  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   gDwcAuth     0x021AB188  data
 *   OS_LockMutex  0x02086028  arm
 *   OS_UnlockMutex  0x02086078  arm
 *   DWC_Http_Abort  0x021797D4  arm  ov009
 *   OS_JoinThread  0x02085710  arm
 *   DWC_Http_Destroy  0x02179CF4  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   strcmp  0x020948E0  arm
 *   DWC_Http_Create  0x0217956C  arm  ov009
 *   DWCi_BM_GetWiFiInfo  0x02058518  arm
 *   DWC_Http_FinishHeader  0x0217967C  arm  ov009
 *   OS_GetThreadPriority  0x02085A30  arm
 *   DWC_Http_StartThread  0x02179718  arm  ov009
 *   gDwcHttpParamArg  0x021A2358  data  ov009
 *   gDwcAuthNasUrl  0x021A2374  data  ov009
 *   gDwcWiFiInfo  0x021AB190  data  ov009
 *   gMslRefToken  0x02150FEC  data
 *   OS_GetTick  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 *   OS_Sleep  0x02085A38  arm
 *   DWC_Http_ParseResult  0x0217A484  arm  ov009
 *   DWCi_AUTH_UpDateWiFiID  0x02058DD0  arm
 *   DWCi_AUTH_RemakeWiFiID  0x02058E20  arm
 *   DWCi_AUTH_MakeWiFiID  0x02058D88  arm
 *   DWC_Http_GetResult  0x0217A728  arm  ov009
 *   DWC_Auth_SetNasTimeDiff  0x02168250  arm  ov009
 *   atoi  0x020964E0  arm
 *   DWC_Http_GetBase64DecodedResult  0x0217A77C  arm  ov009
 *   strtol  0x02095F40  arm
 *   strlen  0x0209477C  arm
 *   DWC_Http_GetRawResult  0x0217A7C8  arm  ov009
 *   errno     0x02153FAC  data
 *   gDwcAuthLabelDate     0x021A2394  data ov009
 *   gDwcAuthLabelHttpResult     0x021A239C  data ov009
 *   gDwcAuthLabelReturnCd     0x021A23A8  data ov009
 *   gDwcAuthLabelToken     0x021A23B4  data ov009
 *   gDwcAuthLabelLocator     0x021A23BC  data ov009
 *   gDwcAuthLabelChallenge     0x021A23C4  data ov009
 *   gDwcAuthLabelDateTime     0x021A23D0  data ov009
 *   gDwcAuthLabelSetCookie     0x021A23DC  data ov009
 *   DWC_Http_Add_PostBase64Item  0x02179F3C  arm  ov009
 *   DWC_Auth_GetCalInfoFromWiFiInfo  0x02178F78  arm  ov009
 *   DWC_Auth_SetCalInfoToHttp  0x02179218  arm  ov009
 *   wcslen  0x02096578  arm
 *   gDwcAuthPostValueAcctCreate  0x021A23E8  data  ov009
 *   gDwcAuthPostLabelAction  0x021A23F4  data  ov009
 *   gDwcAuthPostValueLogin  0x021A23FC  data  ov009
 *   gDwcAuthPostLabelGsbrcd  0x021A2404  data  ov009
 *   gDwcAuthAllowEssId  0x021ACE70  data  ov009
 *   gDwcAuthPostValueIsWfc  0x021A240C  data  ov009
 *   gDwcAuthPostLabelIsWfc  0x021A2410  data  ov009
 *   gDwcAuthPostLabelIngamesn  0x021A2418  data  ov009
 */
#include "dwc_http_types.h"
#include "dwc_auth_types.h"


#include "../types.h"

#include "../sdk_os.h"

typedef struct DWCHttp {
    char pad0[0x1020];
    int state;
    char pad1024[0xb50];
    char thread[0x6c];
    int thread_started;
} DWCHttp;

typedef struct DWCAuth {
    char stack[0x1000];
    int reserved1000;
    int error;
    DWCAuthResult result;
    DWCAuthParam param;
    char pad1214[0x100];
    DWCHttp *http;
    char thread[0x6c];
    int started;
    char pad1388[0x50];
    OSMutex mutex;
    int abort_flag;
} DWCAuth;

typedef struct DWCAuthGlobal {
    int useWfc;
    DWCAuth *auth;
    int state;
    unsigned long long userid;
} DWCAuthGlobal;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void OS_InitMutex(OSMutex *mutex);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long stack_size, unsigned long prio);
extern void OS_WakeupThreadDirect(void *thread);
extern void OS_LockMutex(OSMutex *mutex);
extern void OS_UnlockMutex(OSMutex *mutex);
extern void DWC_Http_Abort(char *http);
extern void OS_JoinThread(void *thread);
extern void DWC_Http_Destroy(char *http);
extern void MI_CpuCopy8(void *src, void *dst, unsigned long size);
extern int strcmp(const char *, const char *);
extern int DWC_Http_Create(DWCHttp *http, DWCHttpParam *param);
extern void DWCi_BM_GetWiFiInfo(DWCWiFiInfo *buf);
extern int DWC_Http_FinishHeader(char *http);
extern unsigned long OS_GetThreadPriority(void *thread);
extern void DWC_Http_StartThread(char *http, unsigned int prio);
extern unsigned long long OS_GetTick(void);
extern void OS_Sleep(unsigned long msec);
extern int DWC_Http_ParseResult(DWCHttp *http, int noparsebody);
extern int DWCi_AUTH_UpDateWiFiID(DWCWiFiInfo *wifiinfo, void *work);
extern int DWCi_AUTH_RemakeWiFiID(DWCWiFiInfo *wifiinfo);
extern int DWCi_AUTH_MakeWiFiID(void *work);
extern char *DWC_Http_GetResult(char *http, char *label);
extern int DWC_Auth_SetNasTimeDiff(char *datestr);
extern int atoi(u32 s);
extern int DWC_Http_GetBase64DecodedResult(char *http, char *label, char *buffer, unsigned int buffer_len);
extern s32 strtol(u32 s, u32 *endptr, u32 base);
extern int strlen(const u8 *s);
extern int DWC_Http_GetRawResult(char *http, char *label, char *buffer, int buffer_len);
extern int DWC_Http_Add_PostBase64Item(DWCHttp *http, char *label, char *data, unsigned long data_len);
extern int DWC_Auth_GetCalInfoFromWiFiInfo(DWCCalInfo *cal, DWCWiFiInfo *wifiinfo);
extern int DWC_Auth_SetCalInfoToHttp(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
extern int wcslen(const u16 *s);
void DWC_Auth_SetCustomNas(char *v);
char *DWC_Auth_GetCustomNas(void);
int DWC_Auth_Create(DWCAuthParam *param, DWCHttp *http);
void DWCi_Auth_StartThread(void);
void DWC_Auth_Abort(void);
void DWC_Auth_Destroy(void);
void DWC_Auth_Join(void);
int DWC_Auth_GetError(void);
void DWC_Auth_GetResult(int *result);
int DWCi_Auth_Start(int getwifiinfofromflash);
void DWCi_Auth_Thread(void *arg);
int DWCi_Auth_ParseHttp(void);
int DWCi_Auth_FillResult(void);
int DWCi_Auth_Prepare_FirstPost(DWCHttp *http, char *gsbrcd, unsigned short *ingamesn);
void DWCi_Auth_SetError(int error);
extern DWCHttpParam g_021A2358;
extern DWCHttpParam gDwcHttpParamArg;
extern char gDwcAuthNasUrl[];
extern DWCAuthGlobal gDwcAuthGlobal;
extern DWCAuth *gDwcAuth;
extern DWCWiFiInfo gDwcWiFiInfo;
extern OSThreadInfo gMslRefToken;
extern int errno;
extern char gDwcAuthLabelDate[];
extern char gDwcAuthLabelHttpResult[];
extern char gDwcAuthLabelReturnCd[];
extern char gDwcAuthLabelToken[];
extern char gDwcAuthLabelLocator[];
extern char gDwcAuthLabelChallenge[];
extern char gDwcAuthLabelDateTime[];
extern char gDwcAuthLabelSetCookie[];
extern char gDwcAuthPostValueAcctCreate[];
extern char gDwcAuthPostLabelAction[];
extern char gDwcAuthPostValueLogin[];
extern char gDwcAuthPostLabelGsbrcd[];
extern int gDwcAuthAllowEssId;
extern char gDwcAuthPostValueIsWfc[];
extern char gDwcAuthPostLabelIsWfc[];
extern char gDwcAuthPostLabelIngamesn[];

void DWC_Auth_SetCustomNas(char *v)
{
    g_021A2358.url = (char *)v;
}

char *DWC_Auth_GetCustomNas(void)
{
	return g_021A2358.url;
}

/*
 * sdk:      DWC_Auth_Create (libdwcauth.TWL.HYB.a dwc_auth.o)
 */
int DWC_Auth_Create(DWCAuthParam *param, DWCHttp *http)
{
    void *(*alloc)(unsigned long, long) = param->alloc;

    if (gDwcAuthGlobal.auth != 0)
        return 2;
    gDwcAuthGlobal.auth = (DWCAuth *)alloc(0, sizeof(DWCAuth));
    if (gDwcAuthGlobal.auth == 0)
        return 2;
    MI_CpuFill8(gDwcAuthGlobal.auth, 0, sizeof(DWCAuth));
    gDwcAuthGlobal.auth->http = http;
    gDwcAuthGlobal.state = 0;
    MI_CpuFill8(&gDwcAuthGlobal.auth->result, 0, sizeof(DWCAuthResult));
    gDwcAuthGlobal.auth->result.returncode = 20100;
    gDwcAuthGlobal.auth->param = *param;
    gDwcAuthGlobal.auth->param.ingamesn[25] = 0;
    gDwcAuthGlobal.auth->param.gsbrcd[11] = 0;
    gDwcAuthGlobal.auth->error = DWCi_Auth_Start(1);
    if (gDwcAuthGlobal.auth->error != 0)
        return gDwcAuthGlobal.auth->error;
    gDwcAuthGlobal.useWfc = 0;
    DWCi_Auth_StartThread();
    return 0;
}

/*
 * sdk:      DWCi_Auth_StartThread (libdwcauth.TWL.HYB.a(dwc_auth.o))
 */
void DWCi_Auth_StartThread(void)
{
	OS_InitMutex(&gDwcAuthGlobal.auth->mutex);
	gDwcAuthGlobal.auth->abort_flag = 0;
	if (gDwcAuthGlobal.auth->started != 0) {
		if (OS_IsThreadTerminated(gDwcAuthGlobal.auth->thread) == 0)
			return;
	}
	OS_CreateThread(gDwcAuthGlobal.auth->thread, DWCi_Auth_Thread, &gDwcAuth, gDwcAuthGlobal.auth->stack + 0x1000, 0x1000, 0x10);
	OS_WakeupThreadDirect(gDwcAuthGlobal.auth->thread);
}

/*
 * sdk:      DWC_Auth_Abort (libdwcauth.TWL.HYB.a(dwc_auth.o))
 */
void DWC_Auth_Abort(void)
{
	if (gDwcAuthGlobal.auth == 0)
		return;
	OS_LockMutex(&gDwcAuthGlobal.auth->mutex);
	gDwcAuthGlobal.auth->abort_flag = 1;
	OS_UnlockMutex(&gDwcAuthGlobal.auth->mutex);
	if (gDwcAuthGlobal.auth->http != 0)
		DWC_Http_Abort((char *)gDwcAuthGlobal.auth->http);
	if (gDwcAuthGlobal.auth->started == 0)
		return;
	if (OS_IsThreadTerminated(gDwcAuthGlobal.auth->thread) != 0)
		return;
	OS_JoinThread(gDwcAuthGlobal.auth->thread);
}

/*
 * sdk:      DWC_Auth_Destroy (libdwcauth.TWL.HYB.a(dwc_auth.o))
 */
void DWC_Auth_Destroy(void)
{
	void (*free)(unsigned long, void *, long);

	if (gDwcAuthGlobal.auth == 0)
		return;
	free = gDwcAuthGlobal.auth->param.free;
	if (gDwcAuthGlobal.auth->http != 0)
		DWC_Http_Destroy((char *)gDwcAuthGlobal.auth->http);
	free(0, gDwcAuthGlobal.auth, 0);
	gDwcAuthGlobal.auth = 0;
}

/*
 * sdk:      DWC_Auth_Join (libdwcauth.TWL.HYB.a(dwc_auth.o))
 */
void DWC_Auth_Join(void)
{
	if (gDwcAuthGlobal.auth->started == 0)
		return;
	if (OS_IsThreadTerminated(gDwcAuthGlobal.auth->thread) != 0)
		return;
	OS_JoinThread(gDwcAuthGlobal.auth->thread);
}

/*
 * sdk:      DWC_Auth_GetError (libdwcauth.TWL.HYB.a(dwc_auth.o))
 */
int DWC_Auth_GetError(void)
{
	int error;

	if (gDwcAuthGlobal.auth == 0)
		return 0x16;
	OS_LockMutex(&gDwcAuthGlobal.auth->mutex);
	error = gDwcAuthGlobal.auth->error;
	OS_UnlockMutex(&gDwcAuthGlobal.auth->mutex);
	return error;
}

/*
 * sdk:      DWC_Auth_GetResult (libdwcauth.TWL.HYB.a(dwc_auth.o))
 */
void DWC_Auth_GetResult(int *result)
{
	if (gDwcAuthGlobal.auth == 0)
		MI_CpuFill8(result, 0, 0x1c4);
	MI_CpuCopy8(&gDwcAuthGlobal.auth->result, result, 0x1c4);
	if (result[0] < 20000 || result[0] >= 30000)
		result[0] = 20998;
	if (result[0] >= 20100)
		result[0] = -result[0];
}

/*
 * sdk:      DWCi_Auth_Start (libdwcauth.TWL.HYB.a dwc_auth.o)
 *
 * The pool carried 0x021A2358 twice: once for the url/f14/fc/f10 accesses and
 * once for the DWC_Http_Create argument, so the source named the struct through
 * two externs (docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-*).
 * With one name 1.1p1 CSEs both uses into a callee-saved register and the
 * function comes out one instruction (8 bytes) short.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/DWCi_Auth_Start.c \
 *       --func DWCi_Auth_Start --addr 0x021782B4 --region ov009 --arm --cc 1.1p1 --lang c99 --diff
 */
int DWCi_Auth_Start(int getwifiinfofromflash)
{
    if (strcmp(g_021A2358.url, gDwcAuthNasUrl) != 0)
        g_021A2358.ignoreca = 1;

    g_021A2358.alloc = gDwcAuthGlobal.auth->param.alloc;
    g_021A2358.free = gDwcAuthGlobal.auth->param.free;
    if (DWC_Http_Create(gDwcAuthGlobal.auth->http, &gDwcHttpParamArg) != 0)
        return 4;

    if (getwifiinfofromflash == 1)
        DWCi_BM_GetWiFiInfo(&gDwcWiFiInfo);

    gDwcAuthGlobal.auth->error = DWCi_Auth_Prepare_FirstPost(gDwcAuthGlobal.auth->http, gDwcAuthGlobal.auth->param.gsbrcd, gDwcAuthGlobal.auth->param.ingamesn);
    if (gDwcAuthGlobal.auth->error != 0)
        return 4;

    if (DWC_Http_FinishHeader((char *)gDwcAuthGlobal.auth->http) != 0)
        return 4;

    DWC_Http_StartThread((char *)gDwcAuthGlobal.auth->http, OS_GetThreadPriority(gMslRefToken.current) - 1);
    return 0;
}

/*
 * sdk:      DWCi_Auth_Thread (libdwcauth.TWL.HYB.a dwc_auth.o)
 */
void DWCi_Auth_Thread(void *arg)
{
    int retrycount = 0;
    unsigned long long startwait;
    int result_httpparse;
    int getwifiinfofromflash;

    for (;;) {
        if (gDwcAuthGlobal.auth->http->thread_started != 0
            && !OS_IsThreadTerminated(gDwcAuthGlobal.auth->http->thread))
            OS_JoinThread(gDwcAuthGlobal.auth->http->thread);

        if (gDwcAuthGlobal.auth->http->state != 8) {
            gDwcAuthGlobal.auth->result.returncode = 20100;
            if (gDwcAuthGlobal.auth->http->state == 7) {
                DWCi_Auth_SetError(20);
                return;
            }
            if (retrycount > 2) {
                if (gDwcAuthGlobal.auth->http->state == 2)
                    DWCi_Auth_SetError(9);
                else if (gDwcAuthGlobal.auth->http->state == 3)
                    DWCi_Auth_SetError(11);
                else
                    DWCi_Auth_SetError(13);
                return;
            }
            retrycount++;
            getwifiinfofromflash = 1;
        } else {
            result_httpparse = DWCi_Auth_ParseHttp();
            switch (result_httpparse) {
            case 21:
                DWCi_Auth_SetError(21);
                return;
            case 16:
                if (retrycount > 2) {
                    DWCi_Auth_SetError(16);
                    return;
                }
                retrycount++;
                getwifiinfofromflash = 0;
                break;
            case 17:
                DWCi_Auth_SetError(result_httpparse);
                return;
            default:
                if (retrycount >= 2) {
                    DWCi_Auth_SetError(result_httpparse);
                    return;
                }
                retrycount++;
                getwifiinfofromflash = 1;
                break;
            }
        }

        startwait = OS_GetTick();
        while (((OS_GetTick() - startwait) << 6) / 33514 < 5000) {
            OS_LockMutex(&gDwcAuthGlobal.auth->mutex);
            if (gDwcAuthGlobal.auth->abort_flag == 1) {
                gDwcAuthGlobal.auth->result.returncode = 20100;
                OS_UnlockMutex(&gDwcAuthGlobal.auth->mutex);
                DWCi_Auth_SetError(20);
                return;
            }
            OS_UnlockMutex(&gDwcAuthGlobal.auth->mutex);
            OS_Sleep(5000);
        }

        DWC_Http_Destroy((char *)gDwcAuthGlobal.auth->http);
        OS_LockMutex(&gDwcAuthGlobal.auth->mutex);
        gDwcAuthGlobal.auth->error = DWCi_Auth_Start(getwifiinfofromflash);
        if (gDwcAuthGlobal.auth->error != 0) {
            gDwcAuthGlobal.auth->result.returncode = 20100;
            OS_UnlockMutex(&gDwcAuthGlobal.auth->mutex);
            return;
        }
        OS_UnlockMutex(&gDwcAuthGlobal.auth->mutex);
    }
}

/*
 * sdk:      DWCi_Auth_ParseHttp (libdwcauth.TWL.HYB.a dwc_auth.o)
 */
int DWCi_Auth_ParseHttp(void)
{
    void *(*alloc)(unsigned long, long) = gDwcAuthGlobal.auth->param.alloc;
    void (*free)(unsigned long, void *, long) = gDwcAuthGlobal.auth->param.free;
    unsigned char *bmwork;

    if (DWC_Http_ParseResult(gDwcAuthGlobal.auth->http, 0) != 1)
    {
        gDwcAuthGlobal.auth->result.returncode = 20100;
        return 14;
    }
    if (DWCi_Auth_FillResult() != 0)
        return 14;

    if (gDwcAuthGlobal.auth->result.returncode < 20100)
    {
        if (gDwcAuthGlobal.auth->result.returncode == 20002)
        {
            bmwork = (unsigned char *)alloc(0, 0x101f);
            if (bmwork == 0)
            {
                gDwcAuthGlobal.auth->result.returncode = 20100;
                return 2;
            }
            if (DWCi_AUTH_UpDateWiFiID(&gDwcWiFiInfo, (void *)(((unsigned long)bmwork + 31) & ~31)) != 1)
            {
                free(0, bmwork, 0);
                gDwcAuthGlobal.auth->result.returncode = 20100;
                return 15;
            }
            free(0, bmwork, 0);
        }
        return 21;
    }
    switch (gDwcAuthGlobal.auth->result.returncode)
    {
    case 20104:
        DWCi_AUTH_RemakeWiFiID(&gDwcWiFiInfo);
        gDwcAuthGlobal.auth->result.returncode = 20104;
        return 16;
    case 20108:
        bmwork = (unsigned char *)alloc(0, 0x1000);
        if (bmwork == 0)
        {
            gDwcAuthGlobal.auth->result.returncode = 20108;
            return 17;
        }
        DWCi_AUTH_MakeWiFiID((void *)(((unsigned long)bmwork + 31) & ~31));
        free(0, bmwork, 0);
        gDwcAuthGlobal.auth->result.returncode = 20108;
        return 17;
    default:
        return 18;
    }
}

/*
 * sdk:      DWCi_Auth_FillResult (libdwcauth.TWL.HYB.a dwc_auth.o)
 */
int DWCi_Auth_FillResult(void)
{
    char *endptr;
    int returncode;

    endptr = 0;
    endptr = DWC_Http_GetResult((char *)gDwcAuthGlobal.auth->http, gDwcAuthLabelDate);
    if (endptr != 0)
        DWC_Auth_SetNasTimeDiff(endptr);

    endptr = 0;
    errno = 0;
    returncode = atoi((u32)DWC_Http_GetResult((char *)gDwcAuthGlobal.auth->http, gDwcAuthLabelHttpResult));
    if (errno == 0x22) {
        gDwcAuthGlobal.auth->result.returncode = 20101;
        return 12;
    }
    if (returncode != 200) {
        gDwcAuthGlobal.auth->result.returncode = returncode + 23000;
        return 18;
    }
    if (DWC_Http_GetBase64DecodedResult((char *)gDwcAuthGlobal.auth->http, gDwcAuthLabelReturnCd, gDwcAuthGlobal.auth->result.retcode, 4) <= 0) {
        gDwcAuthGlobal.auth->result.returncode = 20101;
        return 14;
    }
    returncode = strtol((u32)gDwcAuthGlobal.auth->result.retcode, (u32 *)(&endptr), 10);
    if (endptr != gDwcAuthGlobal.auth->result.retcode + strlen((const u8 *)gDwcAuthGlobal.auth->result.retcode)) {
        gDwcAuthGlobal.auth->result.returncode = 20101;
        return 12;
    }
    gDwcAuthGlobal.auth->result.returncode = returncode + 20000;
    if (returncode < 100) {
        gDwcAuthGlobal.auth->result.token[0] = 0;
        gDwcAuthGlobal.auth->result.locator[0] = 0;
        gDwcAuthGlobal.auth->result.challenge[0] = 0;
        gDwcAuthGlobal.auth->result.datetime[0] = 0;
        gDwcAuthGlobal.auth->result.cookie[0] = 0;
        DWC_Http_GetBase64DecodedResult((char *)gDwcAuthGlobal.auth->http, gDwcAuthLabelToken, gDwcAuthGlobal.auth->result.token, 0x12d);
        DWC_Http_GetBase64DecodedResult((char *)gDwcAuthGlobal.auth->http, gDwcAuthLabelLocator, gDwcAuthGlobal.auth->result.locator, 0x33);
        DWC_Http_GetBase64DecodedResult((char *)gDwcAuthGlobal.auth->http, gDwcAuthLabelChallenge, gDwcAuthGlobal.auth->result.challenge, 9);
        DWC_Http_GetBase64DecodedResult((char *)gDwcAuthGlobal.auth->http, gDwcAuthLabelDateTime, gDwcAuthGlobal.auth->result.datetime, 0xf);
        DWC_Http_GetRawResult((char *)gDwcAuthGlobal.auth->http, gDwcAuthLabelSetCookie, gDwcAuthGlobal.auth->result.cookie, 0x41);
        gDwcAuthGlobal.auth->result.cookie[0x2b] = 0;
        if (returncode != 40)
            gDwcAuthGlobal.state = 1;
        else
            gDwcAuthGlobal.state = 2;
    }
    return 0;
}

/*
 * sdk:      DWCi_Auth_Prepare_FirstPost (libdwcauth.TWL.HYB.a dwc_auth.o)
 */
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

    if (!DWC_Auth_GetCalInfoFromWiFiInfo(&calinfo, &gDwcWiFiInfo))
        return 5;
    if (!DWC_Auth_SetCalInfoToHttp(http, &calinfo, gDwcAuthAllowEssId))
        return 8;

    if (gDwcAuthGlobal.useWfc == 1)
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

/*
 * sdk:      DWCi_Auth_SetError (libdwcauth.TWL.HYB.a(dwc_auth.o))
 */
void DWCi_Auth_SetError(int error)
{
	OS_LockMutex(&gDwcAuthGlobal.auth->mutex);
	gDwcAuthGlobal.auth->error = error;
	OS_UnlockMutex(&gDwcAuthGlobal.auth->mutex);
}
