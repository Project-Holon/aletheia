/*
 * function: DWC_Svl_GetTokenAsync
 * address:  0x0217C144
 * packet:   pkt_ov009_0217C144
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Svl_GetTokenAsync (libdwcauth.TWL.HYB.a dwc_svl.o)
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_Terminate  0x02088234  arm
 *   strcmp  0x020948E0  arm
 *   DWC_Http_Create  0x0217956C  arm  ov009
 *   func_02059F54  0x02059F54  arm
 *   DWC_Auth_GetCalInfoFromNVRAM  0x02178F4C  arm  ov009
 *   DWC_Auth_SetCalInfoToHttp  0x02179218  arm  ov009
 *   DWC_Http_Destroy  0x02179CF4  arm  ov009
 *   DWC_Http_Add_PostBase64Item  0x02179F3C  arm  ov009
 *   DWC_Http_FinishHeader  0x0217967C  arm  ov009
 *   OS_GetThreadPriority  0x02085A30  arm
 *   DWC_Http_StartThread  0x02179718  arm  ov009
 *   g_021ACEF4     0x021ACEF4  data ov009
 *   g_021A2358     0x021A2358  data ov009
 *   g_021A2840     0x021A2840  data ov009
 *   g_021A2860     0x021A2860  data ov009
 *   g_021A2868     0x021A2868  data ov009
 *   g_021A2870     0x021A2870  data ov009
 *   gMslRefToken     0x02150FEC  data
 *
 * strcmp (strcmp) is declared pure: the object keeps the intwork
 * load live across the call, which only a side-effect-free callee allows.
 */

typedef struct OSThread {
    char pad0[0x6c];
    int id;
    char pad70[0x50];
} OSThread;

typedef struct OSThreadInfo {
    unsigned short isNeedRescheduling;
    unsigned short irqDepth;
    OSThread *current;
} OSThreadInfo;

typedef struct DWCHttp {
    char pad0[0x1b74];
    OSThread thread;
    char mutex[0x18];
    int abort;
} DWCHttp;

typedef struct DWCHttpParam {
    char *url;
    int action;
    unsigned long len_recvbuf;
    void *(*alloc)(unsigned long name, long size);
    void (*free)(unsigned long name, void *ptr, long size);
    int ignoreca;
    int timeout;
} DWCHttpParam;

typedef struct DWCCalInfo {
    char userid[14];
    char passwd[7];
    char gamecd[5];
    char makercd[3];
    char unitcd[2];
    char macadr[13];
    char lang[3];
    char birth[5];
    char devtime[13];
    char bssid[13];
    char ssid[33];
    char apinfo[14];
    unsigned short devname[11];
} DWCCalInfo;

typedef struct DWCSvlResult {
    int status;
    char svlhost[65];
    char svltoken[301];
} DWCSvlResult;

typedef struct DWCSvlIntWorkarea {
    void *(*alloc)(unsigned long name, long size);
    void (*free)(unsigned long name, void *ptr, long size);
    DWCHttp http;
    DWCSvlResult *result;
} DWCSvlIntWorkarea;

typedef struct DWCAuthHttpParam {
    char *url;
} DWCAuthHttpParam;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int OS_IsThreadTerminated(OSThread *thread);
extern void OS_Terminate(void);
extern int strcmp(const char *s1, const char *s2) __attribute__((pure));
extern int DWC_Http_Create(DWCHttp *http, DWCHttpParam *param);
extern void func_02059F54(int error, int errorCode);
extern int DWC_Auth_GetCalInfoFromNVRAM(void *cal);
extern int DWC_Auth_SetCalInfoToHttp(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
extern void DWC_Http_Destroy(char *http);
extern int DWC_Http_Add_PostBase64Item(DWCHttp *http, char *label, char *data, unsigned long data_len);
extern int DWC_Http_FinishHeader(char *http);
extern unsigned long OS_GetThreadPriority(OSThread *thread);
extern void DWC_Http_StartThread(char *http, unsigned long prio);

extern DWCSvlIntWorkarea *g_021ACEF4;
extern DWCAuthHttpParam g_021A2358;
extern char g_021A2840[];
extern char g_021A2860[];
extern char g_021A2868[];
extern char g_021A2870[];
extern OSThreadInfo gMslRefToken;

int DWC_Svl_GetTokenAsync(char *svc, DWCSvlResult *result)
{
    DWCHttpParam httpparam;
    DWCCalInfo calinfo;

    g_021ACEF4->result = result;
    MI_CpuFill8(result, 0, sizeof(DWCSvlResult));

    if (g_021ACEF4->http.thread.id != 0 && !OS_IsThreadTerminated(&g_021ACEF4->http.thread))
        OS_Terminate();

    httpparam.url = g_021A2358.url;
    httpparam.action = 0;
    httpparam.len_recvbuf = 0x1000;
    httpparam.alloc = g_021ACEF4->alloc;
    httpparam.free = g_021ACEF4->free;
    if (strcmp(g_021A2358.url, g_021A2840) != 0)
        httpparam.ignoreca = 1;
    else
        httpparam.ignoreca = 0;
    httpparam.timeout = 20000;

    if (DWC_Http_Create(&g_021ACEF4->http, &httpparam) != 0) {
        func_02059F54(9, -24100);
        return 0;
    }

    if (!DWC_Auth_GetCalInfoFromNVRAM(&calinfo) || !DWC_Auth_SetCalInfoToHttp(&g_021ACEF4->http, &calinfo, 0)) {
        DWC_Http_Destroy((char *)(&g_021ACEF4->http));
        func_02059F54(9, -24100);
        return 0;
    }

    if (DWC_Http_Add_PostBase64Item(&g_021ACEF4->http, g_021A2860, g_021A2868, 6) != 0
        || DWC_Http_Add_PostBase64Item(&g_021ACEF4->http, g_021A2870, svc, 4) != 0) {
        DWC_Http_Destroy((char *)(&g_021ACEF4->http));
        func_02059F54(9, -24100);
        return 0;
    }

    if (DWC_Http_FinishHeader((char *)(&g_021ACEF4->http)) != 0) {
        DWC_Http_Destroy((char *)(&g_021ACEF4->http));
        func_02059F54(9, -24100);
        return 0;
    }

    DWC_Http_StartThread((char *)(&g_021ACEF4->http), OS_GetThreadPriority(gMslRefToken.current) - 1);
    if (g_021ACEF4->http.thread.id == 0) {
        DWC_Http_Destroy((char *)(&g_021ACEF4->http));
        func_02059F54(9, -24100);
        return 0;
    }
    return 1;
}
