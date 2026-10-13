/*
 * function: NHTTP_CreateConnection
 * address:  0x021BF04C
 * packet:   pkt_ov114_021BF04C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTP_CreateConnection (libnhttp.TWL.HYB.a(d_nhttp_private.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP 0x021BEF08 arm ov114
 *   NHTTPi_GetBgnEndInfoP 0x021BEF3C arm ov114
 *   NHTTPi_GetMutexInfoP 0x021BEF58 arm ov114
 *   NHTTPi_alloc 0x021BA820 arm ov114
 *   NHTTPi_SetError 0x021BA874 arm ov114
 *   NHTTPi_memclr 0x021BA13C arm ov114
 *   NHTTPi_CreateRequest 0x021BB3CC arm ov114
 *   NHTTPi_free 0x021BA850 arm ov114
 *   NHTTPi_CommitConnectionList 0x021BEB88 arm ov114
 *   NHTTPi_SetVirtualContentLength 0x021BEF60 arm ov114
 */

typedef unsigned long u32;

typedef struct {
    char pad[0x2c];
    void *res_p;
} Req;

typedef struct {
    u32 status;
    u32 nhttpError;
    int sslError;
    int running;
    Req *req_p;
    void *res_p;
    int reqId;
    int (*connectionCallback)(void *, int, void *);
    void *next_p;
    u32 postData0;
    u32 postData1;
    u32 virtualContentLength;
    void *reqCallback;
    unsigned short padding[6];
    unsigned short tmpBuf[16384];
    u32 tmpBufOffset;
    u32 tmpBufRest;
    int ref;
} Connection;

typedef unsigned char  u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetBgnEndInfoP(void);
extern void *NHTTPi_GetMutexInfoP(int p);
extern int NHTTPi_alloc(int a, int b);
extern void NHTTPi_SetError(u8 *p, int v);
extern void NHTTPi_memclr(int a, int b);
extern Req *NHTTPi_CreateRequest(void *bgnEnd, char *url_p, int method, char *buf_p, u32 len,
                          void *param_p, void *bufFull, void *freeBuf);
extern void NHTTPi_free(int a);
extern int NHTTPi_CommitConnectionList(int a, int b);
extern void NHTTPi_SetVirtualContentLength(u8 *p, u32 v);

void *NHTTP_CreateConnection(char *url_p, int method, char *buf_p, u32 len,
                    int (*callback)(void *, int, void *), void *userParam_p)
{
    Connection *connection_p;
    void *sysInfo_p;
    void *bgnEndInfo_p;
    void *mutexInfo_p;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP();
    mutexInfo_p = NHTTPi_GetMutexInfoP((int)sysInfo_p);
    connection_p = (Connection *)NHTTPi_alloc(0x804c, 0x20);
    if (connection_p == 0) {
        NHTTPi_SetError(bgnEndInfo_p, 1);
        return 0;
    }
    NHTTPi_memclr((int)connection_p, 0x804c);
    connection_p->req_p = NHTTPi_CreateRequest(bgnEndInfo_p, url_p, method, buf_p, len, userParam_p, 0, 0);
    if (connection_p->req_p == 0) {
        NHTTPi_free((int)connection_p);
        return 0;
    }
    connection_p->res_p = connection_p->req_p->res_p;
    connection_p->status = 0;
    connection_p->connectionCallback = callback;
    connection_p->postData0 = 0;
    connection_p->postData1 = 0;
    connection_p->reqId = -1;
    NHTTPi_CommitConnectionList((int)mutexInfo_p, (int)connection_p);
    connection_p->nhttpError = 0xf;
    connection_p->sslError = 0;
    connection_p->running = 1;
    NHTTPi_SetVirtualContentLength((u8 *)connection_p, 0);
    connection_p->reqCallback = 0;
    connection_p->tmpBufOffset = 0;
    connection_p->tmpBufRest = 0;
    NHTTPi_memclr((int)connection_p->tmpBuf, 0x8000);
    connection_p->ref = 1;
    return connection_p;
}
