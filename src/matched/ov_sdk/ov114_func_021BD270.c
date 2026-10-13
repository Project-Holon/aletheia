/*
 * function: NHTTPi_ThreadReqEnd
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
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *   NHTTPi_GetBgnEndInfoP  0x021BEF3C  arm  ov114
 *   NHTTPi_GetReqInfoP  0x021BEF48  arm  ov114
 *   NHTTPi_GetMutexInfoP  0x021BEF58  arm  ov114
 *   NHTTPi_Request2Connection  0x021BEBE0  arm  ov114
 *   NHTTPi_SocClose  0x021B9CFC  arm  ov114
 *   NHTTPi_SetError  0x021BA874  arm  ov114
 *   NHTTPi_lockReqList  0x021BEFCC  arm  ov114
 *   NHTTPi_free  0x021BA850  arm  ov114
 *   NHTTPi_unlockReqList  0x021BEFD8  arm  ov114
 *   NHTTPi_destroyRequestObject  0x021BB934  arm  ov114
 *   NHTTPi_CompleteCallback  0x021BEE1C  arm  ov114
 *   NHTTPi_NotifyCompletion  0x021BEA98  arm  ov114
 *   NHTTPi_DeleteConnection  0x021BF1B0  arm  ov114
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

extern unsigned char *NHTTPi_GetSystemInfoP(void);
extern NHTTPBgnEndInfo *NHTTPi_GetBgnEndInfoP();
typedef unsigned char  u8;
extern void *NHTTPi_GetReqInfoP(int p);
extern void *NHTTPi_GetMutexInfoP(int p);
extern NHTTPConnection *NHTTPi_Request2Connection(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p);
extern int NHTTPi_SocClose(NHTTPMutexInfo *mutexInfo_p, NHTTPReq *req_p, int socket);
extern void NHTTPi_SetError(u8 *p, int v);
extern void NHTTPi_lockReqList();
extern void NHTTPi_free(int a);
extern void NHTTPi_unlockReqList();
extern int NHTTPi_destroyRequestObject(int a, u8 *b);
extern void NHTTPi_CompleteCallback(NHTTPMutexInfo *mutexInfo_p, NHTTPConnection *connection_p);
extern void NHTTPi_NotifyCompletion(u8 *p);
extern int NHTTPi_DeleteConnection(NHTTPConnection *connection_p);

static void NHTTPi_ThreadReqEnd(NHTTPThreadData *threadData_p)
{
    NHTTPSysInfo *sysInfo_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
    NHTTPReqInfo *reqInfo_p;
    NHTTPMutexInfo *mutexInfo_p;
    NHTTPReq *req_p;
    NHTTPRes *res_p;
    NHTTPConnection *connection_p;

    sysInfo_p = (NHTTPSysInfo *)NHTTPi_GetSystemInfoP();
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    reqInfo_p = NHTTPi_GetReqInfoP((int)sysInfo_p);
    mutexInfo_p = NHTTPi_GetMutexInfoP((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    res_p = req_p->res_p;
    connection_p = NHTTPi_Request2Connection(mutexInfo_p, req_p);

    if (req_p->doCancel) {
        threadData_p->result = 8;
        threadData_p->isKeepAlive = 0;
    }
    if (threadData_p->isKeepAlive == 0 && bgnEndInfo_p->socket >= 0) {
        if (NHTTPi_SocClose(mutexInfo_p, req_p, bgnEndInfo_p->socket) < 0)
            threadData_p->result = 10;
        bgnEndInfo_p->socket = -1;
    }
    if (threadData_p->result == 0) {
        res_p->isSuccess = 1;
    } else {
        res_p->isSuccess = 0;
        NHTTPi_SetError((u8 *)bgnEndInfo_p, threadData_p->result);
        if (res_p->recvBuf_p == threadData_p->tmpBodyBuf) {
            res_p->recvBuf_p = 0;
            res_p->recvBufLen = 0;
        }
    }
    if (connection_p != 0)
        connection_p->nhttpError = threadData_p->result;

    NHTTPi_lockReqList(mutexInfo_p);
    NHTTPi_free((int)reqInfo_p->reqCurrent);
    reqInfo_p->reqCurrent = 0;
    NHTTPi_unlockReqList(mutexInfo_p);
    NHTTPi_destroyRequestObject((int)mutexInfo_p, (u8 *)req_p);
    if (connection_p != 0 && res_p->isSuccess != 0)
        connection_p->status = 5;
    NHTTPi_CompleteCallback(mutexInfo_p, connection_p);
    if (connection_p != 0)
        NHTTPi_NotifyCompletion((u8 *)connection_p);
    NHTTPi_DeleteConnection(connection_p);
}
