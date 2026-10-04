/*
 * function: func_021BD270
 * address:  0x021BD270
 * packet:   pkt_ov114_021BD270
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_ThreadReqEnd (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BEF3C  0x021BEF3C  arm  ov114
 *   func_021BEF48  0x021BEF48  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *   func_021BEBE0  0x021BEBE0  arm  ov114
 *   func_021B9CFC  0x021B9CFC  arm  ov114
 *   func_021BA874  0x021BA874  arm  ov114
 *   func_021BEFCC  0x021BEFCC  arm  ov114
 *   func_021BA850  0x021BA850  arm  ov114
 *   func_021BEFD8  0x021BEFD8  arm  ov114
 *   func_021BB934  0x021BB934  arm  ov114
 *   func_021BEE1C  0x021BEE1C  arm  ov114
 *   func_021BEA98  0x021BEA98  arm  ov114
 *   func_021BF1B0  0x021BF1B0  arm  ov114
 */

typedef struct _NHTTPMutexInfo NHTTPMutexInfo;
typedef struct _NHTTPSysInfo NHTTPSysInfo;

typedef struct _NHTTPThreadData {
    char pad0[0x104];
    char tmpBodyBuf[512];
    char pad1[0x330 - 0x304];
    int result;
    int restartConnect;
    int isKeepAlive;
} NHTTPThreadData;

typedef struct _NHTTPBgnEndInfo {
    char pad0[0xc];
    int socket;
} NHTTPBgnEndInfo;

typedef struct _NHTTPReq {
    int doCancel;
    char pad0[0x2c - 4];
    struct _NHTTPRes *res_p;
} NHTTPReq;

typedef struct _NHTTPRes {
    char pad0[0x10];
    int isSuccess;
    char pad1[0x1c - 0x14];
    unsigned long recvBufLen;
    char pad2[0x28 - 0x20];
    char *recvBuf_p;
} NHTTPRes;

typedef struct _NHTTPi_REQLIST {
    char pad0[0xc];
    NHTTPReq *req_p;
} NHTTPi_REQLIST;

typedef struct _NHTTPReqInfo {
    NHTTPi_REQLIST *reqCurrent;
} NHTTPReqInfo;

typedef struct _NHTTPConnection {
    int status;
    int nhttpError;
} NHTTPConnection;

extern NHTTPSysInfo *func_021BEF08(void);
extern NHTTPBgnEndInfo *func_021BEF3C();
typedef unsigned char  u8;
extern void *func_021BEF48(int p);
extern NHTTPMutexInfo *func_021BEF58();
extern NHTTPConnection *func_021BEBE0(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p);
extern int func_021B9CFC(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket);
extern void func_021BA874(u8 *p, int v);
extern void func_021BEFCC();
extern void func_021BA850(int a);
extern void func_021BEFD8();
extern int func_021BB934(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p);
extern void func_021BEE1C(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p);
extern void func_021BEA98(NHTTPConnection *connection_p);
extern int func_021BF1B0(NHTTPConnection *connection_p);

static void func_021BD270(NHTTPThreadData *threadData_p)
{
    NHTTPSysInfo *sysInfo_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
    NHTTPReqInfo *reqInfo_p;
    NHTTPMutexInfo *mutexInfo_p;
    NHTTPReq *req_p;
    NHTTPRes *res_p;
    NHTTPConnection *connection_p;

    sysInfo_p = func_021BEF08();
    bgnEndInfo_p = func_021BEF3C(sysInfo_p);
    reqInfo_p = func_021BEF48((int)sysInfo_p);
    mutexInfo_p = func_021BEF58(sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    res_p = req_p->res_p;
    connection_p = func_021BEBE0(mutexInfo_p, req_p);

    if (req_p->doCancel) {
        threadData_p->result = 8;
        threadData_p->isKeepAlive = 0;
    }
    if (threadData_p->isKeepAlive == 0 && bgnEndInfo_p->socket >= 0) {
        if (func_021B9CFC(mutexInfo_p, req_p, bgnEndInfo_p->socket) < 0)
            threadData_p->result = 10;
        bgnEndInfo_p->socket = -1;
    }
    if (threadData_p->result == 0) {
        res_p->isSuccess = 1;
    } else {
        res_p->isSuccess = 0;
        func_021BA874((u8 *)bgnEndInfo_p, threadData_p->result);
        if (res_p->recvBuf_p == threadData_p->tmpBodyBuf) {
            res_p->recvBuf_p = 0;
            res_p->recvBufLen = 0;
        }
    }
    if (connection_p != 0)
        connection_p->nhttpError = threadData_p->result;

    func_021BEFCC(mutexInfo_p);
    func_021BA850((int)reqInfo_p->reqCurrent);
    reqInfo_p->reqCurrent = 0;
    func_021BEFD8(mutexInfo_p);
    func_021BB934(mutexInfo_p, req_p);
    if (connection_p != 0 && res_p->isSuccess != 0)
        connection_p->status = 5;
    func_021BEE1C(mutexInfo_p, connection_p);
    if (connection_p != 0)
        func_021BEA98(connection_p);
    func_021BF1B0(connection_p);
}
