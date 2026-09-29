/*
 * function: func_021BC740
 * address:  0x021BC740
 * packet:   pkt_ov114_021BC740
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      NHTTPi_RecvProxyConnectHeader (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BEF48  0x021BEF48  arm  ov114
 *   func_021BEF50  0x021BEF50  arm  ov114
 *   func_021BEF3C  0x021BEF3C  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *   func_021B9F94  0x021B9F94  arm  ov114
 *   func_021BA448  0x021BA448  arm  ov114
 *   func_021BA150  0x021BA150  arm  ov114
 *   g_021CE4A8  0x021CE4A8  data
 */

typedef struct {
    char pad[0x18];
    int httpStatus;
    char pad1c[0x2c - 0x1c];
} NHTTPRes;

typedef struct {
    char pad[0x2c];
    NHTTPRes *res_p;
} NHTTPReq;

typedef struct {
    char pad[0xc];
    NHTTPReq *req_p;
} NHTTPReqList;

typedef struct {
    NHTTPReqList *reqCurrent;
} NHTTPReqInfo;

typedef struct {
    char pad[0xc];
    int socket;
} NHTTPBgnEndInfo;

typedef struct {
    char pad0[0x100];
    char commBuf[1];
} NHTTPThreadInfo;

extern void *func_021BEF08(void);
extern NHTTPReqInfo *func_021BEF48();
extern NHTTPThreadInfo *func_021BEF50(void *sysInfo_p);
extern NHTTPBgnEndInfo *func_021BEF3C(void *sysInfo_p);
extern void *func_021BEF58(void *sysInfo_p);
extern int func_021B9F94(void *mutexInfo_p, NHTTPReq *req_p, int socket, char *buf_p, int len, int flags);
extern int func_021BA448(char *p_p, int len);
extern int func_021BA150(char *p1_p, char *p2_p, int size);
extern char g_021CE4A8[];

static int func_021BC740(void)
{
    int totalRecvbyte;
    int connectFlag;
    int endFlag;
    int recvbyte;
    int i;
    char tmpbuf[512];
    NHTTPRes *res_p;
    NHTTPReq *req_p;
    void *mutexInfo_p;
    NHTTPBgnEndInfo *bgnEndInfo_p;
    NHTTPThreadInfo *threadInfo_p;
    NHTTPReqInfo *reqInfo_p;
    void *sysInfo_p;

    sysInfo_p = func_021BEF08();
    reqInfo_p = func_021BEF48();
    threadInfo_p = func_021BEF50(sysInfo_p);
    bgnEndInfo_p = func_021BEF3C(sysInfo_p);
    mutexInfo_p = func_021BEF58(sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    res_p = req_p->res_p;
    connectFlag = 0;
    totalRecvbyte = 0;
    while (1) {
        recvbyte = func_021B9F94(mutexInfo_p, req_p, bgnEndInfo_p->socket, tmpbuf + totalRecvbyte,
                                 512 - totalRecvbyte, 0);
        totalRecvbyte += recvbyte;
        res_p->httpStatus = func_021BA448(&tmpbuf[9], 3);
        if (func_021BA150(tmpbuf, g_021CE4A8, 5) == 0 && tmpbuf[8] == ' ' && res_p->httpStatus == 200)
            connectFlag = 1;
        endFlag = 0;
        for (i = 0; i < totalRecvbyte; i++) {
            if (i > 1 && tmpbuf[i - 1] == '\r' && tmpbuf[i] == '\r') {
                endFlag = 1;
                break;
            }
            if (i > 1 && tmpbuf[i - 1] == '\n' && tmpbuf[i] == '\n') {
                endFlag = 1;
                break;
            }
            if (i > 3 && tmpbuf[i - 3] == '\r' && tmpbuf[i - 2] == '\n' && tmpbuf[i - 1] == '\r' &&
                tmpbuf[i] == '\n')
                endFlag = 1;
        }
        if (endFlag)
            return connectFlag != 0;
        if (recvbyte < 0)
            return 0;
        if (totalRecvbyte >= 512) {
            recvbyte = func_021B9F94(mutexInfo_p, req_p, bgnEndInfo_p->socket, threadInfo_p->commBuf, 1, 0);
            if (recvbyte < 0)
                return 0;
            if (recvbyte != 0)
                return 0;
        }
    }
}
