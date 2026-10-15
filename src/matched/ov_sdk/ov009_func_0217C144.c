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
 *   gDwcSvlWorkarea     0x021ACEF4  data ov009
 *   gDwcHttpParamArg     0x021A2358  data ov009
 *   gDwcSvlNasUrl     0x021A2840  data ov009
 *   gDwcSvlPostLabelAction     0x021A2860  data ov009
 *   gDwcSvlPostValueSvcloc     0x021A2868  data ov009
 *   gDwcSvlPostLabelSvc     0x021A2870  data ov009
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

extern DWCSvlIntWorkarea *gDwcSvlWorkarea;
extern DWCAuthHttpParam gDwcHttpParamArg;
extern char gDwcSvlNasUrl[];
extern char gDwcSvlPostLabelAction[];
extern char gDwcSvlPostValueSvcloc[];
extern char gDwcSvlPostLabelSvc[];
extern OSThreadInfo gMslRefToken;

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
        func_02059F54(9, -24100);
        return 0;
    }

    if (!DWC_Auth_GetCalInfoFromNVRAM(&calinfo) || !DWC_Auth_SetCalInfoToHttp(&gDwcSvlWorkarea->http, &calinfo, 0)) {
        DWC_Http_Destroy((char *)(&gDwcSvlWorkarea->http));
        func_02059F54(9, -24100);
        return 0;
    }

    if (DWC_Http_Add_PostBase64Item(&gDwcSvlWorkarea->http, gDwcSvlPostLabelAction, gDwcSvlPostValueSvcloc, 6) != 0
        || DWC_Http_Add_PostBase64Item(&gDwcSvlWorkarea->http, gDwcSvlPostLabelSvc, svc, 4) != 0) {
        DWC_Http_Destroy((char *)(&gDwcSvlWorkarea->http));
        func_02059F54(9, -24100);
        return 0;
    }

    if (DWC_Http_FinishHeader((char *)(&gDwcSvlWorkarea->http)) != 0) {
        DWC_Http_Destroy((char *)(&gDwcSvlWorkarea->http));
        func_02059F54(9, -24100);
        return 0;
    }

    DWC_Http_StartThread((char *)(&gDwcSvlWorkarea->http), OS_GetThreadPriority(gMslRefToken.current) - 1);
    if (gDwcSvlWorkarea->http.thread.id == 0) {
        DWC_Http_Destroy((char *)(&gDwcSvlWorkarea->http));
        func_02059F54(9, -24100);
        return 0;
    }
    return 1;
}
