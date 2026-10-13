/*
 * function: NHTTPi_ThreadProxyProc
 * address:  0x021BD6DC
 * packet:   pkt_ov114_021BD6DC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_ThreadProxyProc (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP 0x021BEF08 arm ov114
 *   NHTTPi_GetBgnEndInfoP 0x021BEF3C arm ov114
 *   NHTTPi_GetReqInfoP 0x021BEF48 arm ov114
 *   NHTTPi_GetMutexInfoP 0x021BEF58 arm ov114
 *   NHTTPi_SendProxyConnectMethod 0x021BC504 arm ov114
 *   NHTTPi_RecvProxyConnectHeader 0x021BC740 arm ov114
 *   NHTTPi_SocSSLConnect 0x021B9E3C arm ov114
 *   NHTTPi_GetSSLError 0x021BA884 arm ov114
 */

typedef struct {
    char pad[0x324];
    int sendBufwp;
    int recvBufwp;
    int contentLength;
    int result;
} ThreadData;

typedef struct {
    int doCancel;
    int isStarted;
    int isSSL;
    int isProxy;
} Req;

typedef struct {
    char pad[0xc];
    int socket;
} BgnEnd;

typedef struct {
    char pad[0xc];
    Req *req_p;
} ReqList;

typedef struct {
    ReqList *reqCurrent;
} ReqInfo;

typedef unsigned char  u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern BgnEnd *NHTTPi_GetBgnEndInfoP(void);
typedef unsigned int   u32;
extern void *NHTTPi_GetReqInfoP(int p);
extern void *NHTTPi_GetMutexInfoP(int p);
extern int NHTTPi_SendProxyConnectMethod(ThreadData *td);
extern int NHTTPi_RecvProxyConnectHeader(ThreadData *td);
extern int NHTTPi_SocSSLConnect(BgnEnd *bgn, void *mutex, Req *req, int socket);
extern u32 NHTTPi_GetSSLError(u8 *p);

static int NHTTPi_ThreadProxyProc(ThreadData *threadData_p)
{
    void *sysInfo_p;
    BgnEnd *bgnEndInfo_p;
    ReqInfo *reqInfo_p;
    void *mutexInfo_p;
    Req *req_p;
    int sendStatus;
    int SSLConnectResult;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP();
    reqInfo_p = NHTTPi_GetReqInfoP((int)sysInfo_p);
    mutexInfo_p = NHTTPi_GetMutexInfoP((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    threadData_p->result = 10;
    threadData_p->sendBufwp = 0;
    if (req_p->isSSL && req_p->isProxy) {
        sendStatus = NHTTPi_SendProxyConnectMethod(threadData_p);
        if (sendStatus != 0) {
            return sendStatus;
        }
        if (NHTTPi_RecvProxyConnectHeader(threadData_p) == 0) {
            return 1;
        }
        SSLConnectResult = NHTTPi_SocSSLConnect(bgnEndInfo_p, mutexInfo_p, req_p, bgnEndInfo_p->socket);
        if (SSLConnectResult != 0) {
            if (SSLConnectResult == -1004) {
                if (NHTTPi_GetSSLError((u8 *)bgnEndInfo_p) != 0) {
                    threadData_p->result = 16;
                }
                return 1;
            } else if (SSLConnectResult == -1005) {
                if (NHTTPi_GetSSLError((u8 *)bgnEndInfo_p) != 0) {
                    threadData_p->result = 17;
                }
                return 1;
            } else {
                if (NHTTPi_GetSSLError((u8 *)bgnEndInfo_p) != 0) {
                    threadData_p->result = 14;
                }
                return 1;
            }
        }
    }
    return 0;
}
