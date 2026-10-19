/*
 * file:     dwc_netcheck.c
 * unit:     yes
 * function: DWC_Netcheck_Create, DWC_Netcheck_Destroy, DWC_Netcheck_Abort, DWC_Netcheck_GetError, DWC_Netcheck_GetReturnCode, DWCi_Netcheck_StartThread, DWCi_Netcheck_Thread, DWCi_Netcheck_SetError
 * address:  0x0217A880
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Netcheck_Thread (sdk/TwlDWC/lib/ARM9-TS/Rom/libdwcauth.TWL.HYB.a dwc_netcheck.o)
 *
 * 2026-10-01: full rewrite from the vendor listing and DWARF, EXACT.  What
 * closed it: one while(1) loop with the DWARF locals in reverse DWARF order
 * (the -2..-5 and 40000>>1 stack slots are the compiler's hoisted loop
 * constants, not locals); every error exit written out in full and left to
 * the compiler's cross-jumping; switch on DWChttp->error per request (case 2
 * falls into default; in the blacklist request the case 8 arm comes after
 * default); switch on the conntest HTTP code (200, 302, default); the two
 * Add_PostBase64Item calls joined by ||; strlen taken from the house
 * string.h so the compiler knows it writes no memory (the argument pointer
 * and the strncpy destination stay in registers across it).
 *
 * symbols:
 *   DWC_Http_Create                  0x0217956c arm
 *   DWC_Http_Destroy                 0x02179cf4 arm
 *   DWC_Http_FinishHeader            0x0217967c arm
 *   OS_GetThreadPriority             0x02085a30 arm
 *   DWC_Http_StartThread             0x02179718 arm
 *   OS_IsThreadTerminated            0x0208574c arm
 *   OS_JoinThread                    0x02085710 arm
 *   DWC_Http_ParseResult             0x0217a484 arm
 *   DWC_Http_GetResult               0x0217a728 arm
 *   atoi                             0x020964e0 arm
 *   strcmp                           0x020948e0 arm
 *   DWC_Auth_GetCalInfoFromNVRAM     0x02178f4c arm
 *   DWC_Auth_SetCalInfoToHttp        0x02179218 arm
 *   DWC_Http_Add_PostBase64Item      0x02179f3c arm
 *   strlen                           0x0209477c arm
 *   DWCi_Netcheck_SetError           0x0217b7e8 arm
 *   strncpy                          0x02094860 arm
 *   DWCi_BM_GetWiFiInfo              0x02058518 arm
 *   DWC_Auth_Create                  0x02177ee8 arm
 *   DWC_Auth_Join                    0x02178194 arm
 *   DWC_Auth_GetError                0x021781dc arm
 *   DWC_Auth_GetResult               0x02178224 arm
 *   DWC_Auth_Destroy                 0x02178144 arm
 *   DWC_Http_GetBase64DecodedResult  0x0217a77c arm
 *   DWC_Http_Add_Body                0x0217a044 arm
 *   OS_Sleep                         0x02085a38 arm
 *   DWChttp                          0x021ace5c data
 *   _ZZ23DWC_SimpleNetcheckAsynciE6bFirst_0 0x021a26d4 data
 *   DWCnetcheckhttpparam             0x021ace8c data
 *   OSi_ThreadInfo                   0x02150fec data
 *   gDwcNetcheckLabelHttpResult                       0x021a2700 data
 *   errno                            0x02153fac data
 *   DWCauthhttpparam                 0x021a2358 data
 *   gDwcNetcheckNasUrl                       0x021a270c data
 *   gDwcNetcheckPostLabelAction                       0x021a272c data
 *   gDwcNetcheckPostValueMessage                       0x021a2734 data
 *   gDwcNetcheckPostLabelHotspot                       0x021a273c data
 *   DWCnetcheckauthparam             0x021acea8 data
 *   gDwcNetcheckPostValueParse                       0x021a274c data
 *   gDwcNetcheckPostLabelHtml                       0x021a2754 data
 *   gDwcNetcheckLabelReturnCd                       0x021a275c data
 *   gDwcNetcheckLabelUrl                       0x021a2768 data
 *   gDwcNetcheckLabelData                       0x021a276c data
 *   gDwcNetcheckLabelWait                       0x021a2774 data
 *   MI_CpuFill8                      0x02082BCC arm
 *   OS_InitMutex                     0x02086004 arm
 *   OS_LockMutex                     0x02086028 arm
 *   OS_UnlockMutex                   0x02086078 arm
 *   OS_CreateThread                  0x020853C0 arm
 *   OS_WakeupThreadDirect            0x02085868 arm
 *   DWC_Http_Abort                    0x021797D4 arm ov009
 *   DWC_Auth_Abort                   0x021780A8 arm ov009
 *   DWCi_Netcheck_StartThread                    0x0217AAF4 arm ov009
 *
 */

#include "../../matched/arm9_sdk/libc/string.h"

#include "../types.h"

#include "../sdk_dwc.h"

#include "../sdk_os.h"

typedef struct DWCHttp {
    u8 stack[0x1000];
    u8 initflag;
    DWCHttpParam param;
    int error;                  /* +0x1020 */
    u8 pad1024[0x112c - 0x1024];
    unsigned long hostip;       /* +0x112c */
    u8 pad1130[0x1a44 - 0x1130];
    DWCHttpBuffer rep;          /* +0x1a44 */
    u8 pad1a54[0x1a74 - 0x1a54];
    DWCHttpLabelValue labelvalue[32];
    OSThread thread;            /* +0x1b74 */
    u8 mutex[0x18];
    int abort;
} DWCHttp;

typedef struct {
    u8 stack[0x1000];
    int error;                  /* +0x1000 */
    int returncode;             /* +0x1004 */
    u8 pad1008[0x1108 - 0x1008];
    DWCNetcheckParam param;     /* +0x1108 */
    char *url;                  /* +0x1114 */
    char *blurl;                /* +0x1118 */
    OSThread thread;            /* +0x111c */
    u8 mutex[0x18];             /* +0x11dc */
} DWCNetcheck;

typedef struct {
    DWCHttp *http;              /* +0x00 DWChttp */
    DWCNetcheck *nc;            /* +0x04 DWCnetcheck */
    int reserved08;
    unsigned long conntestip;   /* +0x0c */
    int allow302;               /* +0x10 */
    int ishotspot;              /* +0x14 */
    u8 pad18[0x30 - 0x18];
    DWCHttpParam httpparam;     /* +0x30 DWCnetcheckhttpparam */
} NetcheckBss;

typedef struct {
    int bFirst;
    char *url;
} NetcheckData;

extern NetcheckBss DWChttp;
extern NetcheckData _ZZ23DWC_SimpleNetcheckAsynciE6bFirst_0;
extern DWCHttpParam DWCnetcheckhttpparam;
extern DWCAuthParam DWCnetcheckauthparam;
extern DWCHttpParam DWCauthhttpparam;
extern OSThreadInfo OSi_ThreadInfo;
extern int errno;
extern char gDwcNetcheckLabelHttpResult[];
extern char gDwcNetcheckNasUrl[];
extern char gDwcNetcheckPostLabelAction[];
extern char gDwcNetcheckPostValueMessage[];
extern char gDwcNetcheckPostLabelHotspot[];
extern char gDwcNetcheckPostValueParse[];
extern char gDwcNetcheckPostLabelHtml[];
extern char gDwcNetcheckLabelReturnCd[];
extern char gDwcNetcheckLabelUrl[];
extern char gDwcNetcheckLabelData[];
extern char gDwcNetcheckLabelWait[];

extern int DWC_Http_Create(DWCHttp *http, DWCHttpParam *param);
extern void DWC_Http_Destroy(char *http);
extern int DWC_Http_FinishHeader(char *http);
extern unsigned long OS_GetThreadPriority(void *thread);
extern void DWC_Http_StartThread(char *http, unsigned int prio);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_JoinThread(void *thread);
extern int DWC_Http_ParseResult(DWCHttp *http, int noparsebody);
extern char *DWC_Http_GetResult(char *http, char *label);
extern int atoi(unsigned int s);
extern int strcmp(const char *a, const char *b);
extern int DWC_Auth_GetCalInfoFromNVRAM(void *cal);
extern int DWC_Auth_SetCalInfoToHttp(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
extern int DWC_Http_Add_PostBase64Item(DWCHttp *http, char *label, char *data, unsigned long data_len);
extern void DWCi_Netcheck_SetError(int error);
extern unsigned char *strncpy(unsigned char *dest, unsigned char *src, unsigned int n);
extern void DWCi_BM_GetWiFiInfo(DWCWiFiInfo *buf);
extern int DWC_Auth_Create(DWCAuthParam *param, struct DWCHttp *http);
extern void DWC_Auth_Join(void);
extern int DWC_Auth_GetError(void);
extern void DWC_Auth_GetResult(int *result);
extern void DWC_Auth_Destroy(void);
extern int DWC_Http_GetBase64DecodedResult(char *http, char *label, char *buffer, unsigned int buffer_len);
extern int DWC_Http_Add_Body(char *http, char *data);
extern void OS_Sleep(unsigned long msec);

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void OS_InitMutex(struct OSMutex *mutex);
extern void OS_LockMutex(struct OSMutex *mutex);
extern void OS_UnlockMutex(struct OSMutex *mutex);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack, unsigned long size, unsigned long prio);
extern void OS_WakeupThreadDirect(void *thread);
extern void DWC_Http_Abort(char *http);
extern void DWC_Auth_Abort(void);
void DWCi_Netcheck_StartThread(void);
static void DWCi_Netcheck_Thread(void *arg);

/*
 * sdk:      DWC_Netcheck_Create (dwc_netcheck.o)
 */
int DWC_Netcheck_Create(DWCNetcheckParam *param)
{
    void *(*alloc)(unsigned long, long) = param->alloc;

    if (DWChttp.nc != 0) {
        return 4;
    }
    DWChttp.nc = alloc(0, sizeof(DWCNetcheck));
    if (DWChttp.nc == 0) {
        return 4;
    }
    MI_CpuFill8(DWChttp.nc, 0, sizeof(DWCNetcheck));
    DWChttp.nc->returncode = -99999;
    DWChttp.nc->param = *param;
    if (DWChttp.http != 0) {
        return 4;
    }
    DWChttp.http = alloc(0, sizeof(DWCHttp));
    if (DWChttp.http == 0) {
        return 4;
    }
    DWChttp.ishotspot = 0;
    OS_InitMutex((struct OSMutex *)DWChttp.nc->mutex);
    DWCi_Netcheck_StartThread();
    return 0;
}

/*
 * sdk:      DWC_Netcheck_Destroy (dwc_netcheck.o)
 */
void DWC_Netcheck_Destroy(void)
{
    void (*free)(unsigned long, void *, long) = DWChttp.nc->param.free;

    if (DWChttp.http != 0) {
        DWC_Http_Destroy((char *)DWChttp.http);
        free(0, DWChttp.http, 0);
        DWChttp.http = 0;
    }
    DWC_Auth_Destroy();
    if (DWChttp.nc == 0) {
        return;
    }
    if (DWChttp.nc->url != 0) {
        free(0, DWChttp.nc->url, 0);
        DWChttp.nc->url = 0;
    }
    if (DWChttp.nc->blurl != 0) {
        free(0, DWChttp.nc->blurl, 0);
        DWChttp.nc->blurl = 0;
    }
    free(0, DWChttp.nc, 0);
    DWChttp.nc = 0;
}

/*
 * sdk:      DWC_Netcheck_Abort (dwc_netcheck.o)
 */
void DWC_Netcheck_Abort(void)
{
    if (DWChttp.nc == 0) {
        return;
    }
    if (DWChttp.http != 0) {
        DWC_Http_Abort((char *)DWChttp.http);
    }
    DWC_Auth_Abort();
    if (DWChttp.nc->thread.id != 0 &&
        !OS_IsThreadTerminated(&DWChttp.nc->thread)) {
        OS_JoinThread(&DWChttp.nc->thread);
    }
    DWChttp.nc->returncode = -7;
}

/*
 * sdk:      DWC_Netcheck_GetError (dwc_netcheck.o)
 */
int DWC_Netcheck_GetError(void)
{
    int error;

    OS_LockMutex((struct OSMutex *)DWChttp.nc->mutex);
    error = DWChttp.nc->error;
    OS_UnlockMutex((struct OSMutex *)DWChttp.nc->mutex);
    return error;
}

int DWC_Netcheck_GetReturnCode(void)
{
    return DWChttp.nc->returncode;
}

/*
 * sdk:      DWCi_Netcheck_StartThread (dwc_netcheck.o)
 */
void DWCi_Netcheck_StartThread(void)
{
    if (DWChttp.nc->thread.id != 0 &&
        !OS_IsThreadTerminated(&DWChttp.nc->thread)) {
        return;
    }
    OS_CreateThread(&DWChttp.nc->thread, DWCi_Netcheck_Thread, DWChttp.nc,
                    DWChttp.nc->stack + sizeof(DWChttp.nc->stack), 0x1000, 16);
    OS_WakeupThreadDirect(&DWChttp.nc->thread);
}

static inline void *OS_GetCurrentThread(void)
{
    return OSi_ThreadInfo.current;
}

#define DWChttp_     (DWChttp.http)
#define DWCnetcheck_ (DWChttp.nc)

static void DWCi_Netcheck_Thread(void *arg)
{
    char *httpretcode;
    int httpretcodei;
    DWCWiFiInfo DWC_netcheck_wifiinfo;
    DWCAuthResult authresult;
    void *(*alloc)(unsigned long, long) = DWCnetcheck_->param.alloc;
    void (*free)(unsigned long, void *, long) = DWCnetcheck_->param.free;
    char *body302;
    char *bodywayport;
    char retcode[4];
    char *url = 0;
    int url_len;
    char *data = 0;
    int data_len;
    char *wait = 0;
    int wait_len;
    int wait_sec;
    DWCCalInfo calinfo;

    while (1) {
        DWChttp.httpparam.url = _ZZ23DWC_SimpleNetcheckAsynciE6bFirst_0.url;
        DWChttp.httpparam.action = 1;
        DWChttp.httpparam.len_recvbuf = 0x1000;
        DWChttp.httpparam.alloc = alloc;
        DWChttp.httpparam.free = free;
        DWChttp.httpparam.timeout = 20000;
        DWCnetcheck_->returncode = -2;
        if (DWC_Http_Create(DWChttp_, &DWCnetcheckhttpparam) != 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(1);
            goto exit;
        }
        if (DWC_Http_FinishHeader((char *)DWChttp_) != 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(1);
            goto exit;
        }
        DWC_Http_StartThread((char *)DWChttp_, OS_GetThreadPriority(OS_GetCurrentThread()) - 1);
        if (DWChttp_->thread.id != 0 && !OS_IsThreadTerminated(&DWChttp_->thread))
            OS_JoinThread(&DWChttp_->thread);
        switch (DWChttp_->error) {
        case 8:
            break;
        case 2:
            DWCnetcheck_->returncode = -1;
        default:
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(3);
            goto exit;
        }
        if (DWC_Http_ParseResult(DWChttp_, 0) != 1) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(2);
            goto exit;
        }
        httpretcode = DWC_Http_GetResult((char *)DWChttp_, gDwcNetcheckLabelHttpResult);
        httpretcodei = atoi((unsigned int)httpretcode);
        if (errno == 34) {
            DWCi_Netcheck_SetError(2);
            goto exit;
        }
        switch (httpretcodei) {
        case 200:
            DWChttp.conntestip = DWChttp_->hostip;
            break;
        case 302:
            DWChttp.ishotspot = 1;
            if (DWCnetcheck_->blurl != 0) {
                DWCnetcheck_->returncode = -6;
                DWC_Http_Destroy((char *)DWChttp_);
                DWChttp.httpparam.url = DWCauthhttpparam.url;
                DWChttp.httpparam.action = 0;
                DWChttp.httpparam.len_recvbuf = 0x200;
                DWChttp.httpparam.alloc = alloc;
                DWChttp.httpparam.free = free;
                DWChttp.httpparam.timeout = 20000;
                if (strcmp(DWChttp.httpparam.url, gDwcNetcheckNasUrl) != 0)
                    DWChttp.httpparam.ignoreca = 1;
                if (DWC_Http_Create(DWChttp_, &DWCnetcheckhttpparam) != 0) {
                    DWC_Http_Destroy((char *)DWChttp_);
                    DWCi_Netcheck_SetError(1);
                    goto exit;
                }
                if (!DWC_Auth_GetCalInfoFromNVRAM(&calinfo) || !DWC_Auth_SetCalInfoToHttp(DWChttp_, &calinfo, 1)) {
                    DWC_Http_Destroy((char *)DWChttp_);
                    DWCi_Netcheck_SetError(8);
                    goto exit;
                }
                if (DWC_Http_Add_PostBase64Item(DWChttp_, gDwcNetcheckPostLabelAction, gDwcNetcheckPostValueMessage, 7) != 0
                 || DWC_Http_Add_PostBase64Item(DWChttp_, gDwcNetcheckPostLabelHotspot, DWCnetcheck_->blurl, strlen(DWCnetcheck_->blurl)) != 0) {
                    DWC_Http_Destroy((char *)DWChttp_);
                    DWCi_Netcheck_SetError(8);
                    goto exit;
                }
                free(0, DWCnetcheck_->blurl, 0);
                DWCnetcheck_->blurl = 0;
                if (DWC_Http_FinishHeader((char *)DWChttp_) != 0) {
                    DWC_Http_Destroy((char *)DWChttp_);
                    DWCi_Netcheck_SetError(1);
                    goto exit;
                }
                DWC_Http_StartThread((char *)DWChttp_, OS_GetThreadPriority(OS_GetCurrentThread()) - 1);
                if (DWChttp_->thread.id != 0 && !OS_IsThreadTerminated(&DWChttp_->thread))
                    OS_JoinThread(&DWChttp_->thread);
                switch (DWChttp_->error) {
                case 2:
                    DWCnetcheck_->returncode = -1;
                default:
                    DWC_Http_Destroy((char *)DWChttp_);
                    DWCi_Netcheck_SetError(3);
                    goto exit;
                case 8:
                    DWC_Http_Destroy((char *)DWChttp_);
                    DWCi_Netcheck_SetError(7);
                    goto exit;
                }
            }
            body302 = DWChttp_->rep.buffer;
            if (body302 == 0) {
                DWC_Http_Destroy((char *)DWChttp_);
                DWCi_Netcheck_SetError(2);
                goto exit;
            }
            DWCnetcheck_->url = alloc(0, strlen(body302) + 1);
            if (DWCnetcheck_->url == 0) {
                DWC_Http_Destroy((char *)DWChttp_);
                DWCi_Netcheck_SetError(4);
                goto exit;
            }
            strncpy((unsigned char *)DWCnetcheck_->url, (unsigned char *)body302, strlen(body302) + 1);
            break;
        default:
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(10);
            goto exit;
        }
        DWC_Http_Destroy((char *)DWChttp_);

        DWCi_BM_GetWiFiInfo(&DWC_netcheck_wifiinfo);
        if (DWC_netcheck_wifiinfo.attestedUserId == 0) {
            DWCnetcheck_->returncode = -3;
            DWCnetcheckauthparam.ingamesn[0] = 0;
            DWCnetcheckauthparam.gsbrcd[0] = 0;
            DWCnetcheckauthparam.alloc = DWCnetcheck_->param.alloc;
            DWCnetcheckauthparam.free = DWCnetcheck_->param.free;
            if (DWC_Auth_Create(&DWCnetcheckauthparam, DWChttp_) != 0) {
                DWCi_Netcheck_SetError(5);
                goto exit;
            }
            DWC_Auth_Join();
            if (DWC_Auth_GetError() != 21) {
                if (DWC_Auth_GetError() == 9) {
                    DWCnetcheck_->returncode = -1;
                } else {
                    DWC_Auth_GetResult((int *)(&authresult));
                    if (DWChttp.allow302 == 1 && (authresult.returncode == -23302 || DWC_Auth_GetError() == 11)) {
                        DWCnetcheck_->returncode = 0;
                        DWC_Auth_Destroy();
                        DWCi_Netcheck_SetError(11);
                        goto exit;
                    }
                    DWCnetcheck_->returncode = authresult.returncode;
                }
                DWC_Auth_Destroy();
                DWCi_Netcheck_SetError(6);
                goto exit;
            }
            DWC_Auth_Destroy();
        }
        if (httpretcodei == 200) {
            DWCnetcheck_->returncode = 0;
            DWCi_Netcheck_SetError(11);
            goto exit;
        }

        DWCnetcheck_->returncode = -4;
        DWChttp.httpparam.url = DWCauthhttpparam.url;
        DWChttp.httpparam.action = 0;
        DWChttp.httpparam.len_recvbuf = 0x1000;
        DWChttp.httpparam.alloc = alloc;
        DWChttp.httpparam.free = free;
        DWChttp.httpparam.timeout = 40000;
        if (strcmp(DWChttp.httpparam.url, gDwcNetcheckNasUrl) != 0)
            DWChttp.httpparam.ignoreca = 1;
        if (DWC_Http_Create(DWChttp_, &DWCnetcheckhttpparam) != 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(1);
            goto exit;
        }
        if (!DWC_Auth_GetCalInfoFromNVRAM(&calinfo) || !DWC_Auth_SetCalInfoToHttp(DWChttp_, &calinfo, 1)) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(8);
            goto exit;
        }
        if (DWC_Http_Add_PostBase64Item(DWChttp_, gDwcNetcheckPostLabelAction, gDwcNetcheckPostValueParse, 5) != 0
         || DWC_Http_Add_PostBase64Item(DWChttp_, gDwcNetcheckPostLabelHtml, DWCnetcheck_->url, strlen(DWCnetcheck_->url)) != 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(8);
            goto exit;
        }
        free(0, DWCnetcheck_->url, 0);
        DWCnetcheck_->url = 0;
        if (DWC_Http_FinishHeader((char *)DWChttp_) != 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(1);
            goto exit;
        }
        DWC_Http_StartThread((char *)DWChttp_, OS_GetThreadPriority(OS_GetCurrentThread()) - 1);
        if (DWChttp_->thread.id != 0 && !OS_IsThreadTerminated(&DWChttp_->thread))
            OS_JoinThread(&DWChttp_->thread);
        switch (DWChttp_->error) {
        case 8:
            break;
        case 3:
            DWC_Http_Destroy((char *)DWChttp_);
            if (DWChttp.allow302 == 1) {
                DWCnetcheck_->returncode = 0;
                DWCi_Netcheck_SetError(11);
                goto exit;
            }
            DWCi_Netcheck_SetError(3);
            goto exit;
        case 2:
            DWCnetcheck_->returncode = -1;
        default:
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(3);
            goto exit;
        }
        if (DWC_Http_ParseResult(DWChttp_, 0) != 1) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(2);
            goto exit;
        }
        httpretcode = DWC_Http_GetResult((char *)DWChttp_, gDwcNetcheckLabelHttpResult);
        httpretcodei = atoi((unsigned int)httpretcode);
        if (errno == 34) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(2);
            goto exit;
        }
        if (httpretcodei != 200) {
            DWC_Http_Destroy((char *)DWChttp_);
            if (DWChttp.allow302 == 1 && httpretcodei == 302) {
                DWCnetcheck_->returncode = 0;
                DWCi_Netcheck_SetError(11);
                goto exit;
            }
            DWCi_Netcheck_SetError(2);
            goto exit;
        }
        if (DWC_Http_GetBase64DecodedResult((char *)DWChttp_, gDwcNetcheckLabelReturnCd, retcode, 4) <= 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(9);
            goto exit;
        }
        httpretcodei = atoi((unsigned int)retcode);
        if (errno == 34) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(9);
            goto exit;
        }
        if (DWChttp.allow302 == 1 && httpretcodei == 114) {
            DWCnetcheck_->returncode = 0;
            DWCi_Netcheck_SetError(11);
            goto exit;
        }
        if (httpretcodei >= 100) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(6);
            goto exit;
        }
        url_len = DWC_Http_GetBase64DecodedResult((char *)DWChttp_, gDwcNetcheckLabelUrl, 0, 0);
        if (url_len <= 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(9);
            goto exit;
        }
        data_len = DWC_Http_GetBase64DecodedResult((char *)DWChttp_, gDwcNetcheckLabelData, 0, 0);
        if (data_len <= 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(9);
            goto exit;
        }
        wait_len = DWC_Http_GetBase64DecodedResult((char *)DWChttp_, gDwcNetcheckLabelWait, 0, 0);
        url = alloc(0, url_len + 1);
        if (url == 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(4);
            goto exit;
        }
        data = alloc(0, data_len + 1);
        if (data == 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(4);
            goto exit;
        }
        if (wait_len > 0) {
            wait = alloc(0, wait_len + 1);
            if (wait == 0) {
                DWC_Http_Destroy((char *)DWChttp_);
                DWCi_Netcheck_SetError(4);
                goto exit;
            }
        }
        url_len = DWC_Http_GetBase64DecodedResult((char *)DWChttp_, gDwcNetcheckLabelUrl, url, url_len + 1);
        if (url_len < 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(9);
            goto exit;
        }
        url[url_len] = 0;
        data_len = DWC_Http_GetBase64DecodedResult((char *)DWChttp_, gDwcNetcheckLabelData, data, data_len + 1);
        if (data_len < 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(9);
            goto exit;
        }
        data[data_len] = 0;
        wait_sec = 0;
        if (wait_len > 0) {
            wait_len = DWC_Http_GetBase64DecodedResult((char *)DWChttp_, gDwcNetcheckLabelWait, wait, wait_len + 1);
            if (wait_len < 0) {
                DWC_Http_Destroy((char *)DWChttp_);
                DWCi_Netcheck_SetError(9);
                goto exit;
            }
            wait[wait_len] = 0;
            wait_sec = atoi((unsigned int)wait);
            if (errno == 34) {
                DWC_Http_Destroy((char *)DWChttp_);
                DWCi_Netcheck_SetError(9);
                goto exit;
            }
            wait_sec *= 1000;
            if (wait_sec > 180000)
                wait_sec = 180000;
        }
        DWC_Http_Destroy((char *)DWChttp_);

        DWCnetcheck_->returncode = -5;
        DWChttp.httpparam.url = url;
        DWChttp.httpparam.action = 0;
        DWChttp.httpparam.len_recvbuf = 0x1000;
        DWChttp.httpparam.alloc = alloc;
        DWChttp.httpparam.free = free;
        DWChttp.httpparam.timeout = 120000;
        if (DWC_Http_Create(DWChttp_, &DWCnetcheckhttpparam) != 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(1);
            goto exit;
        }
        if (DWC_Http_Add_Body((char *)DWChttp_, data) != 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(8);
            goto exit;
        }
        if (DWC_Http_FinishHeader((char *)DWChttp_) != 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(1);
            goto exit;
        }
        DWC_Http_StartThread((char *)DWChttp_, OS_GetThreadPriority(OS_GetCurrentThread()) - 1);
        if (DWChttp_->thread.id != 0 && !OS_IsThreadTerminated(&DWChttp_->thread))
            OS_JoinThread(&DWChttp_->thread);
        switch (DWChttp_->error) {
        case 8:
            break;
        case 2:
            DWCnetcheck_->returncode = -1;
        default:
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(3);
            goto exit;
        }
        if (DWC_Http_ParseResult(DWChttp_, 1) != 1) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(2);
            goto exit;
        }
        bodywayport = DWChttp_->rep.buffer;
        if (bodywayport == 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(2);
            goto exit;
        }
        DWCnetcheck_->blurl = alloc(0, strlen(bodywayport) + 1);
        if (DWCnetcheck_->blurl == 0) {
            DWC_Http_Destroy((char *)DWChttp_);
            DWCi_Netcheck_SetError(4);
            goto exit;
        }
        strncpy((unsigned char *)DWCnetcheck_->blurl, (unsigned char *)bodywayport, strlen(bodywayport) + 1);
        DWC_Http_Destroy((char *)DWChttp_);
        OS_Sleep(wait_sec);
    }
exit:
    if (url != 0)
        free(0, url, 0);
    if (data != 0)
        free(0, data, 0);
    if (wait != 0)
        free(0, wait, 0);
}

/*
 * sdk:      DWCi_Netcheck_SetError (dwc_netcheck.o)
 */
void DWCi_Netcheck_SetError(int error)
{
    OS_LockMutex((struct OSMutex *)DWChttp.nc->mutex);
    DWChttp.nc->error = error;
    OS_UnlockMutex((struct OSMutex *)DWChttp.nc->mutex);
}
