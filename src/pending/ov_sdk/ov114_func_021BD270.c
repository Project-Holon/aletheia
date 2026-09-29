typedef unsigned long u32;

typedef struct {
    int id;
    char preHostname[256];
    char tmpBodyBuf[512];
    char tmpHeaderBuf[14];
    unsigned short padding;
    u32 hostaddr;
    u32 preHostaddr;
    int port;
    int prePort;
    int sendBufwp;
    int recvBufwp;
    int contentLength;
    int result;
    int restartConnect;
    int isKeepAlive;
} ThreadData;

typedef struct {
    int headerLen;
    int bodyLen;
    int totalBodyLen;
    int contentLength;
    int isSuccess;
    int isHeaderParse;
    int httpStatus;
    u32 recvBufLen;
    char *allHeader_p;
    char *foundHeader_p;
    char *recvBuf_p;
} Res;

typedef struct {
    int doCancel;
    char pad[0x2c - 4];
    Res *res_p;
} Req;

typedef struct {
    char pad[0xc];
    Req *req_p;
} ReqList;

typedef struct {
    ReqList *reqCurrent;
} ReqInfo;

typedef struct {
    char pad[0xc];
    int socket;
} BgnEnd;

typedef struct {
    int status;
    int nhttpError;
} Connection;

extern void *func_021BEF08(void);
extern BgnEnd *func_021BEF3C(void);
extern ReqInfo *func_021BEF48(void *sysInfo);
extern void *func_021BEF58(void *sysInfo);
extern Connection *func_021BEBE0(void *mutex, Req *req);
extern int func_021B9CFC(void *mutex, Req *req);
extern void func_021BA874(BgnEnd *bgn, int err);
extern void func_021BEFCC(void *mutex);
extern void func_021BA850(void *p);
extern void func_021BEFD8(void *mutex);
extern void func_021BB934(void *mutex, Req *req);
extern void func_021BEE1C(void *mutex, Connection *c);
extern void func_021BEA98(Connection *c);
extern void func_021BF1B0(Connection *c);

static void func_021BD270(ThreadData *threadData_p)
{
    void *sysInfo_p;
    BgnEnd *bgnEndInfo_p;
    ReqInfo *reqInfo_p;
    void *mutexInfo_p;
    Req *req_p;
    Res *res_p;
    Connection *connection_p;

    sysInfo_p = func_021BEF08();
    bgnEndInfo_p = func_021BEF3C();
    reqInfo_p = func_021BEF48(sysInfo_p);
    mutexInfo_p = func_021BEF58(sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    res_p = req_p->res_p;
    connection_p = func_021BEBE0(mutexInfo_p, req_p);
    if (req_p->doCancel) {
        threadData_p->result = 8;
        threadData_p->isKeepAlive = 0;
    }
    if (threadData_p->isKeepAlive == 0 && bgnEndInfo_p->socket >= 0) {
        if (func_021B9CFC(mutexInfo_p, req_p) < 0) {
            threadData_p->result = 10;
        }
        bgnEndInfo_p->socket = -1;
    }
    if (threadData_p->result == 0) {
        res_p->isSuccess = 1;
    } else {
        res_p->isSuccess = 0;
        func_021BA874(bgnEndInfo_p, threadData_p->result);
        if (res_p->recvBuf_p == threadData_p->tmpBodyBuf) {
            res_p->recvBuf_p = 0;
            res_p->recvBufLen = 0;
        }
    }
    if (connection_p) {
        connection_p->nhttpError = threadData_p->result;
    }
    func_021BEFCC(mutexInfo_p);
    func_021BA850(reqInfo_p->reqCurrent);
    reqInfo_p->reqCurrent = 0;
    func_021BEFD8(mutexInfo_p);
    func_021BB934(mutexInfo_p, req_p);
    if (connection_p && res_p->isSuccess) {
        connection_p->status = 5;
    }
    func_021BEE1C(mutexInfo_p, connection_p);
    if (connection_p) {
        func_021BEA98(connection_p);
    }
    func_021BF1B0(connection_p);
}
