/*
 * file:     unit_021BF04C.c
 * unit:     yes
 * function: func_021BF04C, func_021BF184, func_021BF1B0, func_021BF288, func_021BF308, func_021BF374, func_021BF3BC, func_021BF3E4, NHTTP_GetUserParam, func_021BF488, func_021BF4B0
 * address:  0x021BF04C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF3C 0x021BEF3C arm ov114
 *   func_021BEF58 0x021BEF58 arm ov114
 *   func_021BA820 0x021BA820 arm ov114
 *   func_021BA874 0x021BA874 arm ov114
 *   func_021BA13C 0x021BA13C arm ov114
 *   func_021BB3CC 0x021BB3CC arm ov114
 *   func_021BA850 0x021BA850 arm ov114
 *   func_021BEB88 0x021BEB88 arm ov114
 *   func_021BEF60 0x021BEF60 arm ov114
 *   func_021BEC00  0x021BEC00  arm  ov114
 *   func_021BF1B0  0x021BF1B0  arm  ov114
 *   NHTTPi_GetSystemInfoP      0x021bef08 arm
 *   NHTTPi_GetMutexInfoP       0x021bef58 arm
 *   NHTTPi_GetThreadInfoP      0x021bef50 arm
 *   NHTTPi_CancelRequestAsync  0x021bba14 arm
 *   NHTTPi_decRef              0x021bf018 arm
 *   NHTTPi_DestroyRequest      0x021bb8b4 arm
 *   NHTTP_WaitForConnection    0x021bf288 arm
 *   NHTTPi_DestroyResponse     0x021bbb28 arm
 *   NHTTPi_OmitConnectionList  0x021beba8 arm
 *   NHTTPi_free                0x021ba850 arm
 *   func_021BEF50 0x021BEF50  arm
 *   func_021B9C1C 0x021B9C1C  arm
 *   func_021BEA64 0x021BEA64  arm
 *   NHTTPi_GetConnection       0x021bec00 arm
 *   NHTTPi_SendRequestAsync    0x021bb97c arm
 *   NHTTPi_addRef              0x021befe4 arm
 *   NHTTPi_Connection2Response  0x021bebc8 arm
 */
#include "nhttp_types.h"
struct Conn;
typedef unsigned long u32_021BF04C;


typedef struct {
    u32_021BF04C status;
    u32_021BF04C nhttpError;
    int sslError;
    int running;
    NHTTPReq *req_p;
    void *res_p;
    int reqId;
    int (*connectionCallback)(void *, int, void *);
    void *next_p;
    u32_021BF04C postData0;
    u32_021BF04C postData1;
    u32_021BF04C virtualContentLength;
    void *reqCallback;
    unsigned short padding[6];
    unsigned short tmpBuf[16384];
    u32_021BF04C tmpBufOffset;
    u32_021BF04C tmpBufRest;
    int ref;
} Connection;

typedef unsigned int u32_021BF184;

typedef unsigned int u32_021BF1B0;


typedef unsigned int u32_021BF308;


extern u8 *func_021BEF08(void);
extern void *func_021BEF3C(void);
extern void *func_021BEF58(int p);
extern int func_021BA820(int a, int b);
extern void func_021BA874(u8 *p, int v);
extern void func_021BA13C(int a, int b);
extern NHTTPReq *func_021BB3CC(void *bgnEnd, char *url_p, int method, char *buf_p, u32_021BF04C len,
                          void *param_p, void *bufFull, void *freeBuf);
extern void func_021BA850(int a);
extern int func_021BEB88(int a, int b);
extern void func_021BEF60(u8 *p, u32_021BF04C v);
extern struct Conn *func_021BEC00(int a, int b);
extern int func_021BF1B0(u8 *);
extern NHTTPSysInfo *NHTTPi_GetSystemInfoP(void);
extern NHTTPMutexInfo *NHTTPi_GetMutexInfoP(void);
extern NHTTPThreadInfo *NHTTPi_GetThreadInfoP(NHTTPSysInfo *);
extern int NHTTPi_CancelRequestAsync(NHTTPSysInfo *, int);
extern int NHTTPi_decRef(NHTTPMutexInfo *, NHTTPConnection *);
extern void NHTTPi_DestroyRequest(NHTTPSysInfo *, NHTTPReq *);
extern int NHTTP_WaitForConnection(void *);
extern void NHTTPi_DestroyResponse(NHTTPMutexInfo *, void *);
extern int NHTTPi_OmitConnectionList(NHTTPMutexInfo *, NHTTPConnection *);
extern void NHTTPi_free(void *);
extern int func_021BEF50(void);
extern void func_021B9C1C(int, int);
extern void func_021BEA64(u8 *p);
extern NHTTPConnection *NHTTPi_GetConnection(NHTTPMutexInfo *, void *);
extern int NHTTPi_SendRequestAsync(NHTTPSysInfo *, NHTTPReq *);
extern int NHTTPi_addRef(NHTTPMutexInfo *, NHTTPConnection *);
extern NHTTPRes *NHTTPi_Connection2Response(NHTTPMutexInfo *, void *);
void *func_021BF04C(char *url_p, int method, char *buf_p, u32_021BF04C len, int (*callback)(void *, int, void *), void *userParam_p);
int func_021BF184(int a);
int NHTTPi_DeleteConnection(NHTTPConnection *connection_p);
int func_021BF288(int x);
int NHTTP_StartConnection(void *handle);
int NHTTP_CancelConnection(void *handle);
int func_021BF3BC(int a);
int NHTTP_GetBodyBuffer(void *handle, char **value_pp, unsigned long *size_p);
void *NHTTP_GetUserParam(void *handle);
int func_021BF488(int a);
int NHTTP_GetConnectionProgress(void *handle, unsigned long *received_p, unsigned long *contentlen_p);


void *func_021BF04C(char *url_p, int method, char *buf_p, u32_021BF04C len,
                    int (*callback)(void *, int, void *), void *userParam_p)
{
    Connection *connection_p;
    void *sysInfo_p;
    void *bgnEndInfo_p;
    void *mutexInfo_p;

    sysInfo_p = func_021BEF08();
    bgnEndInfo_p = func_021BEF3C();
    mutexInfo_p = func_021BEF58((int)sysInfo_p);
    connection_p = (Connection *)func_021BA820(0x804c, 0x20);
    if (connection_p == 0) {
        func_021BA874(bgnEndInfo_p, 1);
        return 0;
    }
    func_021BA13C((int)connection_p, 0x804c);
    connection_p->req_p = func_021BB3CC(bgnEndInfo_p, url_p, method, buf_p, len, userParam_p, 0, 0);
    if (connection_p->req_p == 0) {
        func_021BA850((int)connection_p);
        return 0;
    }
    connection_p->res_p = connection_p->req_p->res_p;
    connection_p->status = 0;
    connection_p->connectionCallback = callback;
    connection_p->postData0 = 0;
    connection_p->postData1 = 0;
    connection_p->reqId = -1;
    func_021BEB88((int)mutexInfo_p, (int)connection_p);
    connection_p->nhttpError = 0xf;
    connection_p->sslError = 0;
    connection_p->running = 1;
    func_021BEF60((u8 *)connection_p, 0);
    connection_p->reqCallback = 0;
    connection_p->tmpBufOffset = 0;
    connection_p->tmpBufRest = 0;
    func_021BA13C((int)connection_p->tmpBuf, 0x8000);
    connection_p->ref = 1;
    return connection_p;
}


/*
 * Keyed dispatch on record `a`; -1 when the key is unknown.
 */
int func_021BF184(int a)
{
    u8 *p = (u8 *)func_021BEC00((int)func_021BEF58((int)func_021BEF08()), a);
    if (p == 0)
        return -1;
    return func_021BF1B0(p);
}


int NHTTPi_DeleteConnection(NHTTPConnection *connection_p)
{
    NHTTPSysInfo *sysInfo_p = NHTTPi_GetSystemInfoP();
    NHTTPMutexInfo *mutexInfo_p = NHTTPi_GetMutexInfoP();

    NHTTPi_GetThreadInfoP(sysInfo_p);
    if (connection_p == 0)
        return -1;
    if (connection_p->ref > 0 && connection_p->reqId >= 0) {
        NHTTPi_CancelRequestAsync(sysInfo_p, connection_p->reqId);
        connection_p->reqId = -1;
    }
    if (NHTTPi_decRef(mutexInfo_p, connection_p) > 0)
        return 0;
    if (connection_p->req_p != 0 && connection_p->req_p->isStarted == 0)
        NHTTPi_DestroyRequest(sysInfo_p, connection_p->req_p);
    if (connection_p->res_p != 0) {
        if (connection_p->req_p != 0)
            NHTTP_WaitForConnection(connection_p);
        NHTTPi_DestroyResponse(mutexInfo_p, connection_p->res_p);
    }
    NHTTPi_OmitConnectionList(mutexInfo_p, connection_p);
    NHTTPi_free(connection_p);
    return 0;
}


int func_021BF288(int x)
{
    int a = (int)func_021BEF08();
    int b = func_021BEF50();
    int c;
    int d;

    c = (int)func_021BEC00((int)func_021BEF58(a), x);
    if (c == 0)
        return -1;
    d = func_021BF3BC(x);
    func_021B9C1C(b, 1);
    if (d != -1 && d != 0) {
        if (func_021BF488(x) == 0xf)
            func_021BEA64((u8 *)c);
    }
    return 0;
}


int NHTTP_StartConnection(void *handle)
{
    NHTTPSysInfo *sysInfo_p = NHTTPi_GetSystemInfoP();
    NHTTPMutexInfo *mutexInfo_p = NHTTPi_GetMutexInfoP();
    NHTTPConnection *connection_p = NHTTPi_GetConnection(mutexInfo_p, handle);

    if (connection_p == 0)
        return -1;
    if (connection_p->req_p == 0)
        return -1;
    connection_p->reqId = NHTTPi_SendRequestAsync(sysInfo_p, connection_p->req_p);
    if (connection_p->reqId >= 0) {
        connection_p->status = 1;
        NHTTPi_addRef(mutexInfo_p, connection_p);
    }
    return 0;
}


int NHTTP_CancelConnection(void *handle)
{
    NHTTPSysInfo *sysInfo_p = NHTTPi_GetSystemInfoP();
    NHTTPMutexInfo *mutexInfo_p = NHTTPi_GetMutexInfoP();
    NHTTPConnection *connection_p = NHTTPi_GetConnection(mutexInfo_p, handle);

    if (connection_p == 0)
        return -1;
    if (connection_p->reqId < 0)
        return -1;
    NHTTPi_CancelRequestAsync(sysInfo_p, connection_p->reqId);
    return 0;
}


int func_021BF3BC(int a)
{
    u8 *p = (u8 *)func_021BEC00((int)func_021BEF58((int)func_021BEF08()), a);
    if (p == 0)
        return -1;
    return *(u32 *)p;
}


int NHTTP_GetBodyBuffer(void *handle, char **value_pp, unsigned long *size_p)
{
    NHTTPMutexInfo *mutexInfo_p;
    void *connection_p;
    NHTTPRes *res_p;

    NHTTPi_GetSystemInfoP();
    mutexInfo_p = NHTTPi_GetMutexInfoP();
    connection_p = NHTTPi_GetConnection(mutexInfo_p, handle);
    if (connection_p == 0)
        goto fail;
    res_p = NHTTPi_Connection2Response(mutexInfo_p, connection_p);
    if (res_p == 0)
        return -1;
    *value_pp = res_p->recvBuf_p;
    *size_p = res_p->recvBufLen;
    return res_p->bodyLen;
fail:
    return -1;
}


void *NHTTP_GetUserParam(void *handle)
{
    NHTTPMutexInfo *mutexInfo_p;
    void *connection_p;
    NHTTPRes *res_p;

    NHTTPi_GetSystemInfoP();
    mutexInfo_p = NHTTPi_GetMutexInfoP();
    connection_p = NHTTPi_GetConnection(mutexInfo_p, handle);
    if (connection_p == 0)
        goto fail;
    res_p = NHTTPi_Connection2Response(mutexInfo_p, connection_p);
    return res_p ? res_p->param_p : 0;
fail:
    return 0;
}


/*
 * Keyed +0x04 read of record `a`; -1 when the key is unknown.
 */
int func_021BF488(int a)
{
    u8 *p = (u8 *)func_021BEC00((int)func_021BEF58((int)func_021BEF08()), a);
    if (p != 0)
        return *(u32 *)(p + 4);
    return -1;
}


int NHTTP_GetConnectionProgress(void *handle, unsigned long *received_p, unsigned long *contentlen_p)
{
    NHTTPMutexInfo *mutexInfo_p;
    void *connection_p;
    NHTTPRes *res_p;

    NHTTPi_GetSystemInfoP();
    mutexInfo_p = NHTTPi_GetMutexInfoP();
    connection_p = NHTTPi_GetConnection(mutexInfo_p, handle);
    if (connection_p == 0)
        goto fail;
    res_p = NHTTPi_Connection2Response(mutexInfo_p, connection_p);
    if (res_p == 0)
        goto fail2;
    *received_p = res_p->totalBodyLen;
    *contentlen_p = (res_p->contentLength == 0xffffffff) ? 0 : res_p->contentLength;
    return 0;
fail2:
    return -1;
fail:
    return -1;
}
