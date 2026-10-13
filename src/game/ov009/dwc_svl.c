/*
 * file:     dwc_svl.c
 * unit:     yes
 * function: func_0217C070, func_0217C104, func_0217C144, func_0217C384, func_0217C448
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
 *   func_02088234  0x02088234  arm
 *   func_020948E0  0x020948E0  arm
 *   func_0217956C  0x0217956C  arm  ov009
 *   func_02178F4C  0x02178F4C  arm  ov009
 *   func_02179218  0x02179218  arm  ov009
 *   func_02179CF4  0x02179CF4  arm  ov009
 *   func_02179F3C  0x02179F3C  arm  ov009
 *   func_0217967C  0x0217967C  arm  ov009
 *   OS_GetThreadPriority  0x02085A30  arm
 *   func_02179718  0x02179718  arm  ov009
 *   func_0217A484  0x0217A484  arm  ov009
 *   func_0217A728  0x0217A728  arm  ov009
 *   func_02168250  0x02168250  arm  ov009
 *   func_020964E0  0x020964E0  arm
 *   func_0217A77C  0x0217A77C  arm  ov009
 *   g_021ACEF4     0x021ACEF4  data ov009
 *   g_021A2358     0x021A2358  data ov009
 *   g_021A2840     0x021A2840  data ov009
 *   g_021A2860     0x021A2860  data ov009
 *   g_021A2868     0x021A2868  data ov009
 *   g_021A2870     0x021A2870  data ov009
 *   g_021A2874     0x021A2874  data ov009
 *   g_021A287C     0x021A287C  data ov009
 *   g_02153FAC     0x02153FAC  data
 *   g_021A2888     0x021A2888  data ov009
 *   g_021A2894     0x021A2894  data ov009
 *   g_021A289C     0x021A289C  data ov009
 *   g_021A28AC     0x021A28AC  data ov009
 *   g_02150FEC     0x02150FEC  data
 *
 * Service-locator (SVL) token request on top of the DWC HTTP client.  The
 * control block g_021ACEF4 is one DWCSvlIntWorkarea (0x1C5C bytes): the
 * caller's alloc and free callbacks, the embedded DWCHttp, and the result
 * pointer.  strcmp (func_020948E0) is declared pure: the object keeps the
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
extern void func_02088234(void);
extern int func_020948E0(const char *s1, const char *s2) __attribute__((pure));
extern int func_0217956C(DWCHttp *http, DWCHttpParam *param);
extern int func_02178F4C(void *cal);
extern int func_02179218(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
extern void func_02179CF4(DWCHttp *http);
extern int func_02179F3C(DWCHttp *http, char *label, char *data, unsigned long data_len);
extern int func_0217967C(DWCHttp *http);
extern unsigned long OS_GetThreadPriority(OSThread *thread);
extern void func_02179718(DWCHttp *http, unsigned long prio);
extern int func_0217A484(DWCHttp *http, int noparsebody);
extern char *func_0217A728(DWCHttp *http, char *label);
extern int func_02168250(char *datestr);
extern int func_020964E0(u32 a0);
extern int func_0217A77C(DWCHttp *http, char *label, char *buffer, unsigned long buffer_len);
int func_0217C448(void);

extern DWCSvlIntWorkarea *g_021ACEF4;
extern DWCAuthHttpParam g_021A2358;
extern char g_021A2840[];
extern char g_021A2860[];
extern char g_021A2868[];
extern char g_021A2870[];
extern char g_021A2874[];
extern char g_021A287C[];
extern int g_02153FAC;
extern char g_021A2888[];
extern char g_021A2894[];
extern char g_021A289C[];
extern char g_021A28AC[];
extern OSThreadInfo g_02150FEC;

int func_0217C070(DWCSvlAlloc alloc, DWCSvlFree free)
{
    void *p;

    if (g_021ACEF4 != 0) {
        func_02059F54(9, -24100);
        return 0;
    }

    p = alloc(0, sizeof(DWCSvlIntWorkarea));
    g_021ACEF4 = p;
    if (p == 0) {
        func_02059F54(9, -24100);
        return 0;
    }

    MI_CpuFill8(p, 0, sizeof(DWCSvlIntWorkarea));

    g_021ACEF4->alloc = alloc;
    g_021ACEF4->free = free;
    return 1;
}

/*
 * sdk:      DWC_Svl_Cleanup (dwc_svl.o)
 */
void func_0217C104(void)
{
    if (g_021ACEF4 == 0) {
        return;
    }
    func_02179CF4(&g_021ACEF4->http);
    g_021ACEF4->free(0, g_021ACEF4, 0);
    g_021ACEF4 = 0;
}

/*
 * sdk:      DWC_Svl_GetTokenAsync (libdwcauth.TWL.HYB.a dwc_svl.o)
 *
 * strcmp (func_020948E0) is declared pure: the object keeps the intwork
 * load live across the call, which only a side-effect-free callee allows.
 */
int func_0217C144(char *svc, DWCSvlResult *result)
{
    DWCHttpParam httpparam;
    DWCCalInfo calinfo;

    g_021ACEF4->result = result;
    MI_CpuFill8(result, 0, sizeof(DWCSvlResult));

    if (g_021ACEF4->http.thread.id != 0 && !OS_IsThreadTerminated(&g_021ACEF4->http.thread))
        func_02088234();

    httpparam.url = g_021A2358.url;
    httpparam.action = 0;
    httpparam.len_recvbuf = 0x1000;
    httpparam.alloc = g_021ACEF4->alloc;
    httpparam.free = g_021ACEF4->free;
    if (func_020948E0(g_021A2358.url, g_021A2840) != 0)
        httpparam.ignoreca = 1;
    else
        httpparam.ignoreca = 0;
    httpparam.timeout = 20000;

    if (func_0217956C(&g_021ACEF4->http, &httpparam) != 0) {
        func_02059F54(9, -24100);
        return 0;
    }

    if (!func_02178F4C(&calinfo) || !func_02179218(&g_021ACEF4->http, &calinfo, 0)) {
        func_02179CF4(&g_021ACEF4->http);
        func_02059F54(9, -24100);
        return 0;
    }

    if (func_02179F3C(&g_021ACEF4->http, g_021A2860, g_021A2868, 6) != 0
        || func_02179F3C(&g_021ACEF4->http, g_021A2870, svc, 4) != 0) {
        func_02179CF4(&g_021ACEF4->http);
        func_02059F54(9, -24100);
        return 0;
    }

    if (func_0217967C(&g_021ACEF4->http) != 0) {
        func_02179CF4(&g_021ACEF4->http);
        func_02059F54(9, -24100);
        return 0;
    }

    func_02179718(&g_021ACEF4->http, OS_GetThreadPriority(g_02150FEC.current) - 1);
    if (g_021ACEF4->http.thread.id == 0) {
        func_02179CF4(&g_021ACEF4->http);
        func_02059F54(9, -24100);
        return 0;
    }
    return 1;
}

/*
 * sdk:      DWC_Svl_Process (dwc_svl.o)
 */
int func_0217C384(void)
{
    if (g_021ACEF4 == 0) {
        return 0;
    }
    if (g_021ACEF4->http.thread.id == 0) {
        return 1;
    }
    if (OS_IsThreadTerminated(&g_021ACEF4->http.thread) == 1) {
        switch (g_021ACEF4->http.error) {
        case 8:
            if (func_0217C448() == 0) {
                func_02179CF4(&g_021ACEF4->http);
                return 4;
            }
            func_02179CF4(&g_021ACEF4->http);
            return 3;
        case 7:
            func_02179CF4(&g_021ACEF4->http);
            return 5;
        default:
            func_02179CF4(&g_021ACEF4->http);
            func_02059F54(0x10, -24101);
            return 4;
        }
    }
    return 2;
}

/*
 * sdk:      DWCi_Svl_ParseHttp (libdwcauth.TWL.HYB.a dwc_svl.o)
 */
int func_0217C448(void)
{
    char *strp;
    int httpretcode;
    char retcode[4];
    DWCHttp *DWChttp = &g_021ACEF4->http;

    if (!func_0217A484(DWChttp, 0)) {
        func_02059F54(15, -25101);
        return 0;
    }

    strp = func_0217A728(DWChttp, g_021A2874);
    if (strp != 0)
        func_02168250(strp);

    strp = func_0217A728(DWChttp, g_021A287C);
    if (strp == 0) {
        func_02059F54(15, -25101);
        return 0;
    }
    httpretcode = func_020964E0((u32)strp);
    if (g_02153FAC == 34) {
        func_02059F54(15, -25101);
        return 0;
    }
    if (httpretcode != 200) {
        func_02059F54(15, -25000 - httpretcode);
        return 0;
    }

    if (func_0217A77C(DWChttp, g_021A2888, retcode, 4) <= 0) {
        func_02059F54(15, -25101);
        return 0;
    }
    httpretcode = func_020964E0((u32)retcode);
    if (g_02153FAC == 34) {
        func_02059F54(15, -25101);
        return 0;
    }
    if (httpretcode >= 100) {
        func_02059F54(15, -24000 - httpretcode);
        return 0;
    }

    if (func_0217A77C(DWChttp, g_021A2894, g_021ACEF4->result->svlhost, 64) < 0
        || func_0217A77C(DWChttp, g_021A289C, g_021ACEF4->result->svltoken, 300) < 0
        || func_0217A77C(DWChttp, g_021A28AC, retcode, 1) < 0) {
        func_02059F54(15, -25101);
        return 0;
    }

    g_021ACEF4->result->status = (retcode[0] == 'Y') ? 1 : 0;
    return 1;
}
