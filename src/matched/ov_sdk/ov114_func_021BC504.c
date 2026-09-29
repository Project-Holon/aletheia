/*
 * function: NHTTPi_SendProxyConnectMethod
 * address:  0x021BC504
 * packet:   pkt_ov114_021BC504
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SendProxyConnectMethod (libnhttp.TWL.HYB.a(nhttp_thread.o))
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
extern char g_021CE45C[];
extern char g_021CE468[];
extern char g_021CE46C[];
extern char g_021CE478[];
extern char g_021CE440[];
extern char g_021CE480[];

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
