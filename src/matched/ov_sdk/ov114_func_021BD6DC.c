/*
 * function: func_021BD6DC
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
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF3C 0x021BEF3C arm ov114
 *   func_021BEF48 0x021BEF48 arm ov114
 *   func_021BEF58 0x021BEF58 arm ov114
 *   func_021BC504 0x021BC504 arm ov114
 *   func_021BC740 0x021BC740 arm ov114
 *   func_021B9E3C 0x021B9E3C arm ov114
 *   func_021BA884 0x021BA884 arm ov114
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
extern u8 *func_021BEF08(void);
extern BgnEnd *func_021BEF3C(void);
extern ReqInfo *func_021BEF48(void *sysInfo);
extern void *func_021BEF58(int p);
extern int func_021BC504(ThreadData *td);
extern int func_021BC740(ThreadData *td);
extern int func_021B9E3C(BgnEnd *bgn, void *mutex, Req *req, int socket);
extern int func_021BA884(BgnEnd *bgn);

static int func_021BD6DC(ThreadData *threadData_p)
{
    void *sysInfo_p;
    BgnEnd *bgnEndInfo_p;
    ReqInfo *reqInfo_p;
    void *mutexInfo_p;
    Req *req_p;
    int sendStatus;
    int SSLConnectResult;

    sysInfo_p = func_021BEF08();
    bgnEndInfo_p = func_021BEF3C();
    reqInfo_p = func_021BEF48(sysInfo_p);
    mutexInfo_p = func_021BEF58((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    threadData_p->result = 10;
    threadData_p->sendBufwp = 0;
    if (req_p->isSSL && req_p->isProxy) {
        sendStatus = func_021BC504(threadData_p);
        if (sendStatus != 0) {
            return sendStatus;
        }
        if (func_021BC740(threadData_p) == 0) {
            return 1;
        }
        SSLConnectResult = func_021B9E3C(bgnEndInfo_p, mutexInfo_p, req_p, bgnEndInfo_p->socket);
        if (SSLConnectResult != 0) {
            if (SSLConnectResult == -1004) {
                if (func_021BA884(bgnEndInfo_p) != 0) {
                    threadData_p->result = 16;
                }
                return 1;
            } else if (SSLConnectResult == -1005) {
                if (func_021BA884(bgnEndInfo_p) != 0) {
                    threadData_p->result = 17;
                }
                return 1;
            } else {
                if (func_021BA884(bgnEndInfo_p) != 0) {
                    threadData_p->result = 14;
                }
                return 1;
            }
        }
    }
    return 0;
}
