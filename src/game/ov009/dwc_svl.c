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
 *   func_02059F54  0x02059F54  arm
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
 *   func_0217A728  0x0217A728  arm  ov009
 *   func_02168250  0x02168250  arm  ov009
 *   atoi  0x020964E0  arm
 *   func_0217A77C  0x0217A77C  arm  ov009
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
 *   gMslRefToken     0x02150FEC  data
 *
 * Service-locator (SVL) token request on top of the DWC HTTP client.  The
 * control block gDwcSvlWorkarea is one DWCSvlIntWorkarea (0x1C5C bytes): the
 * caller's alloc and free callbacks, the embedded DWCHttp, and the result
 * pointer.  strcmp (strcmp) is declared pure: the object keeps the
 * intwork load live across the call, which only a side-effect-free callee
 * allows.
 */

typedef unsigned int u32;

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

typedef struct DWCHttpBuffer {
    char *buffer;
    char *write_index;
    char *buffer_tail;
    unsigned long length;
} DWCHttpBuffer;

typedef struct DWCHttpParam {
    char *url;
    int action;
    unsigned long len_recvbuf;
    void *(*alloc)(unsigned long name, long size);
    void (*free)(unsigned long name, void *ptr, long size);
    int ignoreca;
    int timeout;
} DWCHttpParam;

typedef struct CPSSslConnection {
    char pad0[0x800];
    char *server_name;
    char pad804[0xc];
    int (*auth_callback)(int result);
    char pad814[0x1c];
} CPSSslConnection;

typedef struct CPSSoc {
    char pad0[0xc];
    CPSSslConnection *con;
    char pad10[0x90];
} CPSSoc;

typedef struct DWCHttpLabelValue {
    char *label;
    char *value;
} DWCHttpLabelValue;

typedef struct DWCHttp {
    unsigned char stack[0x1000];
    unsigned char initflag;
    DWCHttpParam param;
    int error;
    char url[256];
    char *hostname;
    char *filepath;
    unsigned long hostip;
    int ssl_enabled;
    unsigned short port;
    CPSSoc soc;
    CPSSslConnection con;
    unsigned char *lowrecvbuf;
    unsigned char *lowsendbuf;
    unsigned long lowentropydata[8];
    int num_postitem;
    DWCHttpBuffer req;
    DWCHttpBuffer rep;
    char content_len_mutex[0x18];
    int content_len;
    int receivedbody_len;
    DWCHttpLabelValue labelvalue[32];
    OSThread thread;
    char mutex[0x18];
    int abort;
} DWCHttp;

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

typedef void *(*DWCSvlAlloc)(unsigned long name, long size);
typedef void (*DWCSvlFree)(unsigned long name, void *ptr, long size);

typedef struct DWCSvlIntWorkarea {
    DWCSvlAlloc alloc;
    DWCSvlFree free;
    DWCHttp http;
    DWCSvlResult *result;
} DWCSvlIntWorkarea;

typedef struct DWCAuthHttpParam {
    char *url;
} DWCAuthHttpParam;

extern void func_02059F54(int error, int errorCode);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int OS_IsThreadTerminated(OSThread *thread);
extern void OS_Terminate(void);
extern int strcmp(const char *s1, const char *s2) __attribute__((pure));
extern int DWC_Http_Create(DWCHttp *http, DWCHttpParam *param);
extern int DWC_Auth_GetCalInfoFromNVRAM(void *cal);
extern int DWC_Auth_SetCalInfoToHttp(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
extern void DWC_Http_Destroy(DWCHttp *http);
extern int DWC_Http_Add_PostBase64Item(DWCHttp *http, char *label, char *data, unsigned long data_len);
extern int DWC_Http_FinishHeader(DWCHttp *http);
extern unsigned long OS_GetThreadPriority(OSThread *thread);
extern void DWC_Http_StartThread(DWCHttp *http, unsigned long prio);
extern int DWC_Http_ParseResult(DWCHttp *http, int noparsebody);
extern char *func_0217A728(DWCHttp *http, char *label);
extern int func_02168250(char *datestr);
extern int atoi(u32 a0);
extern int func_0217A77C(DWCHttp *http, char *label, char *buffer, unsigned long buffer_len);
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
extern OSThreadInfo gMslRefToken;

int DWC_Svl_Init(DWCSvlAlloc alloc, DWCSvlFree free)
{
    void *p;

    if (gDwcSvlWorkarea != 0) {
        func_02059F54(9, -24100);
        return 0;
    }

    p = alloc(0, sizeof(DWCSvlIntWorkarea));
    gDwcSvlWorkarea = p;
    if (p == 0) {
        func_02059F54(9, -24100);
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
    DWC_Http_Destroy(&gDwcSvlWorkarea->http);
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
        func_02059F54(9, -24100);
        return 0;
    }

    if (!DWC_Auth_GetCalInfoFromNVRAM(&calinfo) || !DWC_Auth_SetCalInfoToHttp(&gDwcSvlWorkarea->http, &calinfo, 0)) {
        DWC_Http_Destroy(&gDwcSvlWorkarea->http);
        func_02059F54(9, -24100);
        return 0;
    }

    if (DWC_Http_Add_PostBase64Item(&gDwcSvlWorkarea->http, gDwcSvlPostLabelAction, gDwcSvlPostValueSvcloc, 6) != 0
        || DWC_Http_Add_PostBase64Item(&gDwcSvlWorkarea->http, gDwcSvlPostLabelSvc, svc, 4) != 0) {
        DWC_Http_Destroy(&gDwcSvlWorkarea->http);
        func_02059F54(9, -24100);
        return 0;
    }

    if (DWC_Http_FinishHeader(&gDwcSvlWorkarea->http) != 0) {
        DWC_Http_Destroy(&gDwcSvlWorkarea->http);
        func_02059F54(9, -24100);
        return 0;
    }

    DWC_Http_StartThread(&gDwcSvlWorkarea->http, OS_GetThreadPriority(gMslRefToken.current) - 1);
    if (gDwcSvlWorkarea->http.thread.id == 0) {
        DWC_Http_Destroy(&gDwcSvlWorkarea->http);
        func_02059F54(9, -24100);
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
                DWC_Http_Destroy(&gDwcSvlWorkarea->http);
                return 4;
            }
            DWC_Http_Destroy(&gDwcSvlWorkarea->http);
            return 3;
        case 7:
            DWC_Http_Destroy(&gDwcSvlWorkarea->http);
            return 5;
        default:
            DWC_Http_Destroy(&gDwcSvlWorkarea->http);
            func_02059F54(0x10, -24101);
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
        func_02059F54(15, -25101);
        return 0;
    }

    strp = func_0217A728(DWChttp, gDwcSvlLabelDate);
    if (strp != 0)
        func_02168250(strp);

    strp = func_0217A728(DWChttp, gDwcSvlLabelHttpResult);
    if (strp == 0) {
        func_02059F54(15, -25101);
        return 0;
    }
    httpretcode = atoi((u32)strp);
    if (errno == 34) {
        func_02059F54(15, -25101);
        return 0;
    }
    if (httpretcode != 200) {
        func_02059F54(15, -25000 - httpretcode);
        return 0;
    }

    if (func_0217A77C(DWChttp, gDwcSvlLabelReturnCd, retcode, 4) <= 0) {
        func_02059F54(15, -25101);
        return 0;
    }
    httpretcode = atoi((u32)retcode);
    if (errno == 34) {
        func_02059F54(15, -25101);
        return 0;
    }
    if (httpretcode >= 100) {
        func_02059F54(15, -24000 - httpretcode);
        return 0;
    }

    if (func_0217A77C(DWChttp, gDwcSvlLabelSvcHost, gDwcSvlWorkarea->result->svlhost, 64) < 0
        || func_0217A77C(DWChttp, gDwcSvlLabelServiceToken, gDwcSvlWorkarea->result->svltoken, 300) < 0
        || func_0217A77C(DWChttp, gDwcSvlLabelStatusData, retcode, 1) < 0) {
        func_02059F54(15, -25101);
        return 0;
    }

    gDwcSvlWorkarea->result->status = (retcode[0] == 'Y') ? 1 : 0;
    return 1;
}
