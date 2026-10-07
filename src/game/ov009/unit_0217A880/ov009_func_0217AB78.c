/*
 * function: DWCi_Netcheck_Thread
 * address:  0x0217AB78
 * packet:   pkt_ov009_0217AB78
 * region:   ov009
 * compiler: 1.1p1
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
 *   g_021A2700                       0x021a2700 data
 *   errno                            0x02153fac data
 *   DWCauthhttpparam                 0x021a2358 data
 *   g_021A270C                       0x021a270c data
 *   g_021A272C                       0x021a272c data
 *   g_021A2734                       0x021a2734 data
 *   g_021A273C                       0x021a273c data
 *   DWCnetcheckauthparam             0x021acea8 data
 *   g_021A274C                       0x021a274c data
 *   g_021A2754                       0x021a2754 data
 *   g_021A275C                       0x021a275c data
 *   g_021A2768                       0x021a2768 data
 *   g_021A276C                       0x021a276c data
 *   g_021A2774                       0x021a2774 data
 *
 * Verified with:
 *   python tools/match.py one --src ... --func DWCi_Netcheck_Thread --addr 0x0217AB78
 *     --region ov009 --arm --cc 1.1p1 --lang c99 --diff
 */

#include "../../../matched/arm9_sdk/libc/string.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    char *url;
    int action;
    unsigned long len_recvbuf;
    void *(*alloc)(unsigned long, long);
    void (*free)(unsigned long, void *, long);
    int ignoreca;
    int timeout;
} DWCHttpParam;

typedef struct {
    u8 pad0[0x1020];
    int error;                  /* +0x1020 */
    u8 pad1024[0x112c - 0x1024];
    unsigned long hostip;       /* +0x112c */
    u8 pad1130[0x1a44 - 0x1130];
    char *rep;                  /* +0x1a44 rep.buffer */
    u8 pad1a48[0x1b74 - 0x1a48];
    u8 thread[0x6c];            /* +0x1b74 */
    int thread_id;              /* +0x1be0 */
} DWCHttp;

typedef struct {
    u8 stack[0x1004];
    int returncode;             /* +0x1004 */
    u8 pad1008[0x1108 - 0x1008];
    void *(*alloc)(unsigned long, long);        /* +0x1108 */
    void (*free)(unsigned long, void *, long);  /* +0x110c */
    int pad1110;
    char *url;                  /* +0x1114 */
    char *blurl;                /* +0x1118 */
} DWCNetcheck;

typedef struct {
    u16 ingamesn[26];
    char gsbrcd[12];
    void *(*alloc)(unsigned long, long);
    void (*free)(unsigned long, void *, long);
} DWCAuthParam;

typedef struct {
    int returncode;
    char rest[0x1c0];
} DWCAuthResult;

typedef struct {
    u64 attestedUserId;
    u64 notAttestedId;
    u16 pass;
    u16 randomHistory;
} DWCWiFiInfo;

typedef struct {
    u8 data[0x94];
} DWCCalInfo;

typedef struct {
    DWCHttp *http;              /* +0x00 DWChttp */
    DWCNetcheck *nc;            /* +0x04 DWCnetcheck */
    int f08;
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

typedef struct {
    int pad0;
    void *current;
} OSThreadInfo;

extern NetcheckBss DWChttp;
extern NetcheckData _ZZ23DWC_SimpleNetcheckAsynciE6bFirst_0;
extern DWCHttpParam DWCnetcheckhttpparam;
extern DWCAuthParam DWCnetcheckauthparam;
extern DWCHttpParam DWCauthhttpparam;
extern OSThreadInfo OSi_ThreadInfo;
extern int errno;
extern char g_021A2700[];
extern char g_021A270C[];
extern char g_021A272C[];
extern char g_021A2734[];
extern char g_021A273C[];
extern char g_021A274C[];
extern char g_021A2754[];
extern char g_021A275C[];
extern char g_021A2768[];
extern char g_021A276C[];
extern char g_021A2774[];

extern int DWC_Http_Create(DWCHttp *http, DWCHttpParam *param);
extern void DWC_Http_Destroy(DWCHttp *http);
extern int DWC_Http_FinishHeader(DWCHttp *http);
extern unsigned long OS_GetThreadPriority(void *thread);
extern void DWC_Http_StartThread(DWCHttp *http, unsigned long prio);
extern int OS_IsThreadTerminated(void *thread);
extern void OS_JoinThread(void *thread);
extern int DWC_Http_ParseResult(DWCHttp *http, int noparsebody);
extern char *DWC_Http_GetResult(DWCHttp *http, char *label);
extern int atoi(const char *p);
extern int strcmp(const char *a, const char *b);
extern int DWC_Auth_GetCalInfoFromNVRAM(DWCCalInfo *cal);
extern int DWC_Auth_SetCalInfoToHttp(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
extern int DWC_Http_Add_PostBase64Item(DWCHttp *http, char *label, char *data, unsigned long data_len);
extern void DWCi_Netcheck_SetError(int error);
extern char *strncpy(char *dst, const char *src, unsigned long n);
extern void DWCi_BM_GetWiFiInfo(DWCWiFiInfo *buf);
extern int DWC_Auth_Create(DWCAuthParam *param, void *http);
extern void DWC_Auth_Join(void);
extern int DWC_Auth_GetError(void);
extern void DWC_Auth_GetResult(DWCAuthResult *result);
extern void DWC_Auth_Destroy(void);
extern int DWC_Http_GetBase64DecodedResult(DWCHttp *http, char *label, char *buffer, unsigned long buffer_len);
extern int DWC_Http_Add_Body(DWCHttp *http, char *data);
extern void OS_Sleep(unsigned long msec);

static inline void *OS_GetCurrentThread(void)
{
    return OSi_ThreadInfo.current;
}

#define DWChttp_     (DWChttp.http)
#define DWCnetcheck_ (DWChttp.nc)

static void DWCi_Netcheck_Thread(void)
{
    char *httpretcode;
    int httpretcodei;
    DWCWiFiInfo DWC_netcheck_wifiinfo;
    DWCAuthResult authresult;
    void *(*alloc)(unsigned long, long) = DWCnetcheck_->alloc;
    void (*free)(unsigned long, void *, long) = DWCnetcheck_->free;
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
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(1);
            goto exit;
        }
        if (DWC_Http_FinishHeader(DWChttp_) != 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(1);
            goto exit;
        }
        DWC_Http_StartThread(DWChttp_, OS_GetThreadPriority(OS_GetCurrentThread()) - 1);
        if (DWChttp_->thread_id != 0 && !OS_IsThreadTerminated(DWChttp_->thread))
            OS_JoinThread(DWChttp_->thread);
        switch (DWChttp_->error) {
        case 8:
            break;
        case 2:
            DWCnetcheck_->returncode = -1;
        default:
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(3);
            goto exit;
        }
        if (DWC_Http_ParseResult(DWChttp_, 0) != 1) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(2);
            goto exit;
        }
        httpretcode = DWC_Http_GetResult(DWChttp_, g_021A2700);
        httpretcodei = atoi(httpretcode);
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
                DWC_Http_Destroy(DWChttp_);
                DWChttp.httpparam.url = DWCauthhttpparam.url;
                DWChttp.httpparam.action = 0;
                DWChttp.httpparam.len_recvbuf = 0x200;
                DWChttp.httpparam.alloc = alloc;
                DWChttp.httpparam.free = free;
                DWChttp.httpparam.timeout = 20000;
                if (strcmp(DWChttp.httpparam.url, g_021A270C) != 0)
                    DWChttp.httpparam.ignoreca = 1;
                if (DWC_Http_Create(DWChttp_, &DWCnetcheckhttpparam) != 0) {
                    DWC_Http_Destroy(DWChttp_);
                    DWCi_Netcheck_SetError(1);
                    goto exit;
                }
                if (!DWC_Auth_GetCalInfoFromNVRAM(&calinfo) || !DWC_Auth_SetCalInfoToHttp(DWChttp_, &calinfo, 1)) {
                    DWC_Http_Destroy(DWChttp_);
                    DWCi_Netcheck_SetError(8);
                    goto exit;
                }
                if (DWC_Http_Add_PostBase64Item(DWChttp_, g_021A272C, g_021A2734, 7) != 0
                 || DWC_Http_Add_PostBase64Item(DWChttp_, g_021A273C, DWCnetcheck_->blurl, strlen(DWCnetcheck_->blurl)) != 0) {
                    DWC_Http_Destroy(DWChttp_);
                    DWCi_Netcheck_SetError(8);
                    goto exit;
                }
                free(0, DWCnetcheck_->blurl, 0);
                DWCnetcheck_->blurl = 0;
                if (DWC_Http_FinishHeader(DWChttp_) != 0) {
                    DWC_Http_Destroy(DWChttp_);
                    DWCi_Netcheck_SetError(1);
                    goto exit;
                }
                DWC_Http_StartThread(DWChttp_, OS_GetThreadPriority(OS_GetCurrentThread()) - 1);
                if (DWChttp_->thread_id != 0 && !OS_IsThreadTerminated(DWChttp_->thread))
                    OS_JoinThread(DWChttp_->thread);
                switch (DWChttp_->error) {
                case 2:
                    DWCnetcheck_->returncode = -1;
                default:
                    DWC_Http_Destroy(DWChttp_);
                    DWCi_Netcheck_SetError(3);
                    goto exit;
                case 8:
                    DWC_Http_Destroy(DWChttp_);
                    DWCi_Netcheck_SetError(7);
                    goto exit;
                }
            }
            body302 = DWChttp_->rep;
            if (body302 == 0) {
                DWC_Http_Destroy(DWChttp_);
                DWCi_Netcheck_SetError(2);
                goto exit;
            }
            DWCnetcheck_->url = alloc(0, strlen(body302) + 1);
            if (DWCnetcheck_->url == 0) {
                DWC_Http_Destroy(DWChttp_);
                DWCi_Netcheck_SetError(4);
                goto exit;
            }
            strncpy(DWCnetcheck_->url, body302, strlen(body302) + 1);
            break;
        default:
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(10);
            goto exit;
        }
        DWC_Http_Destroy(DWChttp_);

        DWCi_BM_GetWiFiInfo(&DWC_netcheck_wifiinfo);
        if (DWC_netcheck_wifiinfo.attestedUserId == 0) {
            DWCnetcheck_->returncode = -3;
            DWCnetcheckauthparam.ingamesn[0] = 0;
            DWCnetcheckauthparam.gsbrcd[0] = 0;
            DWCnetcheckauthparam.alloc = DWCnetcheck_->alloc;
            DWCnetcheckauthparam.free = DWCnetcheck_->free;
            if (DWC_Auth_Create(&DWCnetcheckauthparam, DWChttp_) != 0) {
                DWCi_Netcheck_SetError(5);
                goto exit;
            }
            DWC_Auth_Join();
            if (DWC_Auth_GetError() != 21) {
                if (DWC_Auth_GetError() == 9) {
                    DWCnetcheck_->returncode = -1;
                } else {
                    DWC_Auth_GetResult(&authresult);
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
        if (strcmp(DWChttp.httpparam.url, g_021A270C) != 0)
            DWChttp.httpparam.ignoreca = 1;
        if (DWC_Http_Create(DWChttp_, &DWCnetcheckhttpparam) != 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(1);
            goto exit;
        }
        if (!DWC_Auth_GetCalInfoFromNVRAM(&calinfo) || !DWC_Auth_SetCalInfoToHttp(DWChttp_, &calinfo, 1)) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(8);
            goto exit;
        }
        if (DWC_Http_Add_PostBase64Item(DWChttp_, g_021A272C, g_021A274C, 5) != 0
         || DWC_Http_Add_PostBase64Item(DWChttp_, g_021A2754, DWCnetcheck_->url, strlen(DWCnetcheck_->url)) != 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(8);
            goto exit;
        }
        free(0, DWCnetcheck_->url, 0);
        DWCnetcheck_->url = 0;
        if (DWC_Http_FinishHeader(DWChttp_) != 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(1);
            goto exit;
        }
        DWC_Http_StartThread(DWChttp_, OS_GetThreadPriority(OS_GetCurrentThread()) - 1);
        if (DWChttp_->thread_id != 0 && !OS_IsThreadTerminated(DWChttp_->thread))
            OS_JoinThread(DWChttp_->thread);
        switch (DWChttp_->error) {
        case 8:
            break;
        case 3:
            DWC_Http_Destroy(DWChttp_);
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
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(3);
            goto exit;
        }
        if (DWC_Http_ParseResult(DWChttp_, 0) != 1) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(2);
            goto exit;
        }
        httpretcode = DWC_Http_GetResult(DWChttp_, g_021A2700);
        httpretcodei = atoi(httpretcode);
        if (errno == 34) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(2);
            goto exit;
        }
        if (httpretcodei != 200) {
            DWC_Http_Destroy(DWChttp_);
            if (DWChttp.allow302 == 1 && httpretcodei == 302) {
                DWCnetcheck_->returncode = 0;
                DWCi_Netcheck_SetError(11);
                goto exit;
            }
            DWCi_Netcheck_SetError(2);
            goto exit;
        }
        if (DWC_Http_GetBase64DecodedResult(DWChttp_, g_021A275C, retcode, 4) <= 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(9);
            goto exit;
        }
        httpretcodei = atoi(retcode);
        if (errno == 34) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(9);
            goto exit;
        }
        if (DWChttp.allow302 == 1 && httpretcodei == 114) {
            DWCnetcheck_->returncode = 0;
            DWCi_Netcheck_SetError(11);
            goto exit;
        }
        if (httpretcodei >= 100) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(6);
            goto exit;
        }
        url_len = DWC_Http_GetBase64DecodedResult(DWChttp_, g_021A2768, 0, 0);
        if (url_len <= 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(9);
            goto exit;
        }
        data_len = DWC_Http_GetBase64DecodedResult(DWChttp_, g_021A276C, 0, 0);
        if (data_len <= 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(9);
            goto exit;
        }
        wait_len = DWC_Http_GetBase64DecodedResult(DWChttp_, g_021A2774, 0, 0);
        url = alloc(0, url_len + 1);
        if (url == 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(4);
            goto exit;
        }
        data = alloc(0, data_len + 1);
        if (data == 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(4);
            goto exit;
        }
        if (wait_len > 0) {
            wait = alloc(0, wait_len + 1);
            if (wait == 0) {
                DWC_Http_Destroy(DWChttp_);
                DWCi_Netcheck_SetError(4);
                goto exit;
            }
        }
        url_len = DWC_Http_GetBase64DecodedResult(DWChttp_, g_021A2768, url, url_len + 1);
        if (url_len < 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(9);
            goto exit;
        }
        url[url_len] = 0;
        data_len = DWC_Http_GetBase64DecodedResult(DWChttp_, g_021A276C, data, data_len + 1);
        if (data_len < 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(9);
            goto exit;
        }
        data[data_len] = 0;
        wait_sec = 0;
        if (wait_len > 0) {
            wait_len = DWC_Http_GetBase64DecodedResult(DWChttp_, g_021A2774, wait, wait_len + 1);
            if (wait_len < 0) {
                DWC_Http_Destroy(DWChttp_);
                DWCi_Netcheck_SetError(9);
                goto exit;
            }
            wait[wait_len] = 0;
            wait_sec = atoi(wait);
            if (errno == 34) {
                DWC_Http_Destroy(DWChttp_);
                DWCi_Netcheck_SetError(9);
                goto exit;
            }
            wait_sec *= 1000;
            if (wait_sec > 180000)
                wait_sec = 180000;
        }
        DWC_Http_Destroy(DWChttp_);

        DWCnetcheck_->returncode = -5;
        DWChttp.httpparam.url = url;
        DWChttp.httpparam.action = 0;
        DWChttp.httpparam.len_recvbuf = 0x1000;
        DWChttp.httpparam.alloc = alloc;
        DWChttp.httpparam.free = free;
        DWChttp.httpparam.timeout = 120000;
        if (DWC_Http_Create(DWChttp_, &DWCnetcheckhttpparam) != 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(1);
            goto exit;
        }
        if (DWC_Http_Add_Body(DWChttp_, data) != 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(8);
            goto exit;
        }
        if (DWC_Http_FinishHeader(DWChttp_) != 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(1);
            goto exit;
        }
        DWC_Http_StartThread(DWChttp_, OS_GetThreadPriority(OS_GetCurrentThread()) - 1);
        if (DWChttp_->thread_id != 0 && !OS_IsThreadTerminated(DWChttp_->thread))
            OS_JoinThread(DWChttp_->thread);
        switch (DWChttp_->error) {
        case 8:
            break;
        case 2:
            DWCnetcheck_->returncode = -1;
        default:
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(3);
            goto exit;
        }
        if (DWC_Http_ParseResult(DWChttp_, 1) != 1) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(2);
            goto exit;
        }
        bodywayport = DWChttp_->rep;
        if (bodywayport == 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(2);
            goto exit;
        }
        DWCnetcheck_->blurl = alloc(0, strlen(bodywayport) + 1);
        if (DWCnetcheck_->blurl == 0) {
            DWC_Http_Destroy(DWChttp_);
            DWCi_Netcheck_SetError(4);
            goto exit;
        }
        strncpy(DWCnetcheck_->blurl, bodywayport, strlen(bodywayport) + 1);
        DWC_Http_Destroy(DWChttp_);
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
