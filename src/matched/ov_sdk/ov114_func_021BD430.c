/*
 * function: func_021BD430
 * address:  0x021BD430
 * packet:   pkt_ov114_021BD430
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_ThreadHostAddrProc (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF48 0x021BEF48 arm ov114
 *   func_021BA118 0x021BA118 arm ov114
 *   func_021BA130 0x021BA130 arm ov114
 *   func_021BA098 0x021BA098 arm ov114
 *   func_021BA13C 0x021BA13C arm ov114
 *   func_021BA124 0x021BA124 arm ov114
 *   func_021BA100 0x021BA100 arm ov114
 */

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
    int doCancel;
    int isStarted;
    int isSSL;
    int isProxy;
    int isRawData;
    int hostLen;
    int hostDescLen;
    int method;
    int port;
    char *URL_p;
    char *hostname_p;
    char pad[0xe4 - 0x2c];
    char proxyAddr[256];
    int proxyPort;
} Req;

typedef struct {
    char pad[0xc];
    Req *req_p;
} ReqList;

typedef struct {
    ReqList *reqCurrent;
} ReqInfo;

extern void *func_021BEF08(void);
extern ReqInfo *func_021BEF48(void *sysInfo);
extern int func_021BA118(char *s);
extern int func_021BA130(char *a, char *b);
extern u32 func_021BA098(Req *req, char *hostname);
extern void func_021BA13C(void *p, u32 size);
extern int func_021BA124(char *s, int max);
extern void func_021BA100(void *dst, void *src, int n);

static int func_021BD430(ThreadData *threadData_p)
{
    void *sysInfo_p;
    ReqInfo *reqInfo_p;
    Req *req_p;
    char *hostname_p;

    sysInfo_p = func_021BEF08();
    reqInfo_p = func_021BEF48(sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    hostname_p = req_p->hostname_p;
    if (req_p->isProxy) {
        hostname_p = req_p->proxyAddr;
    }
    if (func_021BA118(hostname_p) == 0 || func_021BA130(hostname_p, threadData_p->preHostname) != 0) {
        threadData_p->hostaddr = func_021BA098(req_p, hostname_p);
        if (threadData_p->hostaddr == 0) {
            if (req_p->isProxy) {
                threadData_p->result = 12;
                return 0;
            } else {
                threadData_p->result = 4;
                return 0;
            }
        }
    } else {
        threadData_p->hostaddr = threadData_p->preHostaddr;
    }
    func_021BA13C(threadData_p->preHostname, 256);
    func_021BA100(threadData_p->preHostname, hostname_p, func_021BA124(hostname_p, 255));
    threadData_p->port = req_p->port;
    if (req_p->isProxy) {
        threadData_p->port = req_p->proxyPort;
    }
    if (threadData_p->hostaddr != threadData_p->preHostaddr
        || threadData_p->port != threadData_p->prePort
        || req_p->isSSL == 1) {
        threadData_p->isKeepAlive = 0;
    }
    threadData_p->preHostaddr = threadData_p->hostaddr;
    threadData_p->prePort = threadData_p->port;
    return 1;
}
