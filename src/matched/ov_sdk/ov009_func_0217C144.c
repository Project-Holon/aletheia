/*
 * function: func_0217C144
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_0208574C  0x0208574C  arm
 *   func_02088234  0x02088234  arm
 *   func_020948E0  0x020948E0  arm
 *   func_0217956C  0x0217956C  arm  ov009
 *   func_02059F54  0x02059F54  arm
 *   func_02178F4C  0x02178F4C  arm  ov009
 *   func_02179218  0x02179218  arm  ov009
 *   func_02179CF4  0x02179CF4  arm  ov009
 *   func_02179F3C  0x02179F3C  arm  ov009
 *   func_0217967C  0x0217967C  arm  ov009
 *   func_02085A30  0x02085A30  arm
 *   func_02179718  0x02179718  arm  ov009
 *   g_021ACEF4     0x021ACEF4  data ov009
 *   g_021A2358     0x021A2358  data ov009
 *   g_021A2840     0x021A2840  data ov009
 *   g_021A2860     0x021A2860  data ov009
 *   g_021A2868     0x021A2868  data ov009
 *   g_021A2870     0x021A2870  data ov009
 *   g_02150FEC     0x02150FEC  data
 *
 * strcmp (func_020948E0) is declared pure: the object keeps the intwork
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

extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern int func_0208574C(OSThread *thread);
extern void func_02088234(void);
extern int func_020948E0(const char *s1, const char *s2) __attribute__((pure));
extern int func_0217956C(DWCHttp *http, DWCHttpParam *param);
extern void func_02059F54(int error, int errorCode);
extern int func_02178F4C(void *cal);
extern int func_02179218(DWCHttp *http, DWCCalInfo *calinfo, int allowessid);
extern void func_02179CF4(char *http);
extern int func_02179F3C(DWCHttp *http, char *label, char *data, unsigned long data_len);
extern int func_0217967C(char *http);
extern unsigned long func_02085A30(OSThread *thread);
extern void func_02179718(char *http, unsigned long prio);

extern DWCSvlIntWorkarea *g_021ACEF4;
extern DWCAuthHttpParam g_021A2358;
extern char g_021A2840[];
extern char g_021A2860[];
extern char g_021A2868[];
extern char g_021A2870[];
extern OSThreadInfo g_02150FEC;

int func_0217C144(char *svc, DWCSvlResult *result)
{
    DWCHttpParam httpparam;
    DWCCalInfo calinfo;

    g_021ACEF4->result = result;
    func_02082BCC(result, 0, sizeof(DWCSvlResult));

    if (g_021ACEF4->http.thread.id != 0 && !func_0208574C(&g_021ACEF4->http.thread))
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
        func_02179CF4((char *)(&g_021ACEF4->http));
        func_02059F54(9, -24100);
        return 0;
    }

    if (func_02179F3C(&g_021ACEF4->http, g_021A2860, g_021A2868, 6) != 0
        || func_02179F3C(&g_021ACEF4->http, g_021A2870, svc, 4) != 0) {
        func_02179CF4((char *)(&g_021ACEF4->http));
        func_02059F54(9, -24100);
        return 0;
    }

    if (func_0217967C((char *)(&g_021ACEF4->http)) != 0) {
        func_02179CF4((char *)(&g_021ACEF4->http));
        func_02059F54(9, -24100);
        return 0;
    }

    func_02179718((char *)(&g_021ACEF4->http), func_02085A30(g_02150FEC.current) - 1);
    if (g_021ACEF4->http.thread.id == 0) {
        func_02179CF4((char *)(&g_021ACEF4->http));
        func_02059F54(9, -24100);
        return 0;
    }
    return 1;
}
