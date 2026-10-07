/*
 * file:     unit_021BBEC0_p04.c
 * unit:     yes
 * function: func_021BC504, func_021BC740
 * address:  0x021BC504
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
 *   NHTTPi_GetSystemInfoP            0x021bef08 arm
 *   NHTTPi_GetReqInfoP               0x021bef48 arm
 *   NHTTPi_GetThreadInfoP            0x021bef50 arm
 *   NHTTPi_GetBgnEndInfoP            0x021bef3c arm
 *   NHTTPi_intToStr                  0x021ba4e4 arm
 *   NHTTPi_SendData                  0x021bc384 arm
 *   NHTTPi_SendProxyAuthorization    0x021bc40c arm
 *   NHTTPi_SocSend                   0x021ba020 arm
 *   NHTTPi_memclr                    0x021ba13c arm
 *   g_021CE45C                       0x021ce45c data
 *   g_021CE468                       0x021ce468 data
 *   g_021CE46C                       0x021ce46c data
 *   g_021CE478                       0x021ce478 data
 *   g_021CE440                       0x021ce440 data
 *   g_021CE480                       0x021ce480 data
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
typedef struct
{
    char pad[0x324];
    int sendBufwp;                                      /* +0x324 */
} ThreadData;

typedef struct
{
    char pad0[0x100];
    char commBuf[1];                                    /* +0x100 */
} ThreadInfo;

typedef struct
{
    char pad[0xc];
    int socket;                                         /* +0xc */
} BgnEnd;

typedef struct
{
    char pad[0xc];
    void *req_p;                                        /* +0xc */
} ReqList;

typedef struct
{
    ReqList *reqCurrent;                                /* +0x0 */
} ReqInfo;

typedef struct
{
    char pad14[0x14];
    int hostLen;                                        /* +0x14 */
    char pad18[0x20 - 0x18];
    int port;                                           /* +0x20 */
    char *URL_p;                                        /* +0x24 */
} Req;

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

typedef unsigned char  u8;

extern void *NHTTPi_GetSystemInfoP(void);
extern ReqInfo *NHTTPi_GetReqInfoP(void *sysInfo_p);
extern ThreadInfo *NHTTPi_GetThreadInfoP(void *sysInfo_p);
extern BgnEnd *NHTTPi_GetBgnEndInfoP(void *sysInfo_p);
extern int NHTTPi_intToStr(char *p_p, unsigned long n);
extern int NHTTPi_SendData(ThreadData *threadData_p, char *src_p, int srclen);
extern int NHTTPi_SendProxyAuthorization(ThreadData *threadData_p);
extern int NHTTPi_SocSend(Req *req_p, int socket, char *buf_p, int len,
                          int flags);
extern void NHTTPi_memclr(void *p_p, int size);
extern u8 *func_021BEF08(void);
extern void *func_021BEF48(int p);
extern void *func_021BEF50(int p);
extern NHTTPBgnEndInfo *func_021BEF3C(void *sysInfo_p);
extern void *func_021BEF58(int p);
extern int func_021B9F94(void *mutexInfo_p, NHTTPReq *req_p, int socket, char *buf_p, int len, int flags);
extern int func_021BA448(signed char *s, int len);
extern int func_021BA150(const char *p1_p, const char *p2_p, int size);
int NHTTPi_SendProxyConnectMethod(ThreadData *threadData_p);
extern char g_021CE45C[];
extern char g_021CE468[];
extern char g_021CE46C[];
extern char g_021CE478[];
extern char g_021CE440[];
extern char g_021CE480[];
extern char g_021CE4A8[];


int NHTTPi_SendProxyConnectMethod(ThreadData *threadData_p)
{
    int stat;
    int portlen;
    char portstr[5];
    void *sysInfo_p;
    ThreadInfo *threadInfo_p;
    Req *req_p;
    BgnEnd *bgnEndInfo_p;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    req_p = (Req *)NHTTPi_GetReqInfoP(sysInfo_p)->reqCurrent->req_p;
    threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);

    portlen = NHTTPi_intToStr(portstr, req_p->port);

    stat = NHTTPi_SendData(threadData_p, g_021CE45C, 8);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, req_p->URL_p + 8, req_p->hostLen - 8);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, g_021CE468, 1);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, portstr, portlen);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, g_021CE46C, 0xb);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, g_021CE478, 6);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, req_p->URL_p + 8, req_p->hostLen - 8);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, g_021CE468, 1);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, portstr, portlen);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, g_021CE440, 2);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendData(threadData_p, g_021CE480, 0x25);
    if (stat != 0)
        return stat;

    stat = NHTTPi_SendProxyAuthorization(threadData_p);
    if (stat != 0)
        return stat;

    NHTTPi_SendData(threadData_p, g_021CE440, 2);

    if (threadData_p->sendBufwp > 0)
    {
        stat = NHTTPi_SocSend(req_p, bgnEndInfo_p->socket, threadInfo_p->commBuf,
                              threadData_p->sendBufwp, 0);
        if (stat < 0)
            return 1;
        if (stat == 0)
            return 2;
    }

    threadData_p->sendBufwp = 0;
    NHTTPi_memclr(threadInfo_p->commBuf, 0x4000);
    return 0;
}


static int func_021BC740(void)
{
    void *sysInfo_p = func_021BEF08();
    NHTTPReqInfo *reqInfo_p = func_021BEF48((int)sysInfo_p);
    NHTTPThreadInfo *threadInfo_p = func_021BEF50((int)sysInfo_p);
    NHTTPBgnEndInfo *bgnEndInfo_p = func_021BEF3C(sysInfo_p);
    void *mutexInfo_p = func_021BEF58((int)sysInfo_p);
    char *commBuf_p;
    NHTTPReq *req_p;
    NHTTPRes *res_p;
    char tmpbuf[512];
    int i;
    int recvbyte;
    int endFlag;
    int connectFlag;
    int totalRecvbyte;

    req_p = reqInfo_p->reqCurrent->req_p;
    res_p = req_p->res_p;
    connectFlag = 0;
    totalRecvbyte = 0;
    while (1) {
        recvbyte = func_021B9F94(mutexInfo_p, req_p, bgnEndInfo_p->socket, &tmpbuf[totalRecvbyte],
                                 512 - totalRecvbyte, 0);
        totalRecvbyte += recvbyte;
        res_p->httpStatus = func_021BA448((signed char *)(&tmpbuf[9]), 3);
        if (func_021BA150(tmpbuf, g_021CE4A8, 5) == 0 && tmpbuf[8] == ' ' && res_p->httpStatus == 200)
            connectFlag = 1;
        for (endFlag = i = 0; i < totalRecvbyte; i++) {
            if (i > 1 && tmpbuf[i - 1] == 0x0d && tmpbuf[i] == 0x0d) {
                endFlag = 1;
            } else if (i > 1 && tmpbuf[i - 1] == 0x0a && tmpbuf[i] == 0x0a) {
                endFlag = 1;
            } else if (i > 3 && tmpbuf[i - 3] == 0x0d && tmpbuf[i - 2] == 0x0a && tmpbuf[i - 1] == 0x0d &&
                       tmpbuf[i] == 0x0a) {
                endFlag = 1;
            }
        }
        if (endFlag)
            return connectFlag ? 1 : 0;
        if (recvbyte < 0)
            return 0;
        if (totalRecvbyte >= 512) {
            commBuf_p = threadInfo_p->commBuf;
            recvbyte = func_021B9F94(mutexInfo_p, req_p, bgnEndInfo_p->socket, commBuf_p, 1, 0);
            if (recvbyte < 0)
                return 0;
            if (recvbyte != 0)
                return 0;
        }
    }
}
