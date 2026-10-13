/*
 * function: NHTTPi_ThreadHostAddrProc
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
 *   NHTTPi_GetSystemInfoP 0x021BEF08 arm ov114
 *   NHTTPi_GetReqInfoP 0x021BEF48 arm ov114
 *   NHTTPi_strlen 0x021BA118 arm ov114
 *   NHTTPi_strcmp 0x021BA130 arm ov114
 *   NHTTPi_resolveHostname 0x021BA098 arm ov114
 *   NHTTPi_memclr 0x021BA13C arm ov114
 *   NHTTPi_strnlen 0x021BA124 arm ov114
 *   NHTTPi_memcpy 0x021BA100 arm ov114
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

typedef unsigned char  u8;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetReqInfoP(int p);
extern int NHTTPi_strlen(char *s);
extern int NHTTPi_strcmp(char *a, char *b);
extern unsigned long NHTTPi_resolveHostname(int unused, char *hostname_p);
extern void NHTTPi_memclr(int a, int b);
extern int NHTTPi_strnlen(char *s, int max);
extern void NHTTPi_memcpy(void *dst, void *src, int n);

static int NHTTPi_ThreadHostAddrProc(ThreadData *threadData_p)
{
    void *sysInfo_p;
    ReqInfo *reqInfo_p;
    Req *req_p;
    char *hostname_p;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    reqInfo_p = NHTTPi_GetReqInfoP((int)sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    hostname_p = req_p->hostname_p;
    if (req_p->isProxy) {
        hostname_p = req_p->proxyAddr;
    }
    if (NHTTPi_strlen(hostname_p) == 0 || NHTTPi_strcmp(hostname_p, threadData_p->preHostname) != 0) {
        threadData_p->hostaddr = NHTTPi_resolveHostname((int)req_p, hostname_p);
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
    NHTTPi_memclr((int)threadData_p->preHostname, 256);
    NHTTPi_memcpy(threadData_p->preHostname, hostname_p, NHTTPi_strnlen(hostname_p, 255));
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
