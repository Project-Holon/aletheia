/*
 * function: NHTTPi_ThreadParseHeaderProc
 * address:  0x021BDD34
 * packet:   pkt_ov114_021BDD34
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_ThreadParseHeaderProc (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP            0x021bef08 arm
 *   NHTTPi_GetReqInfoP               0x021bef48 arm
 *   NHTTPi_GetThreadInfoP            0x021bef50 arm
 *   NHTTPi_loadFromHdrRecvBuf        0x021bb210 arm
 *   NHTTPi_strnicmp                  0x021ba150 arm
 *   NHTTPi_strToInt                  0x021ba448 arm
 *   NHTTPi_findNextLineHdrRecvBuf    0x021bafa0 arm
 *   NHTTPi_getHeaderValue            0x021bbbc8 arm
 *   NHTTPi_compareTokenN_HdrRecvBuf  0x021bb12c arm
 *   sNHTTPHttpPrefix                       0x021ce4a8 data
 *   sNHTTPContentLength                       0x021ce4f8 data
 *   sNHTTPConnection                       0x021ce508 data
 *   sNHTTPKeepAlive                       0x021ce514 data
 *   sNHTTPTransferEncoding                       0x021ce520 data
 *   sNHTTPChunked                       0x021ce534 data
 */

typedef struct
{
    int headerLen;                                      /* +0x0 */
    int bodyLen;                                        /* +0x4 */
    int totalBodyLen;                                   /* +0x8 */
    int contentLength;                                  /* +0xc */
    int isSuccess;                                      /* +0x10 */
    int isHeaderParse;                                  /* +0x14 */
    int httpStatus;                                     /* +0x18 */
} NHTTPRes;

typedef struct
{
    char pad0[0x8];
    int isSSL;                                          /* +0x8 */
    char padc[0x2c - 0xc];
    NHTTPRes *res_p;                                    /* +0x2c */
} Req;

typedef struct
{
    char pad0[0xc];
    Req *req_p;                                         /* +0xc */
} ReqList;

typedef struct
{
    ReqList *reqCurrent;                                /* +0x0 */
} ReqInfo;

typedef struct
{
    char pad0[0x304];
    char tmpHeaderBuf[0xe];                             /* +0x304 */
    char pad1[0x32c - 0x312];
    int contentLength;                                  /* +0x32c */
    int result;                                         /* +0x330 */
    int restartConnect;                                 /* +0x334 */
    int isKeepAlive;                                    /* +0x338 */
    int isChunked;                                      /* +0x33c */
} ThreadData;

typedef struct
{
    char pad0[0x100];
    char commBuf[1];                                    /* +0x100 */
} ThreadInfo;

extern void *NHTTPi_GetSystemInfoP(void);
extern ReqInfo *NHTTPi_GetReqInfoP(void *sysInfo_p);
extern ThreadInfo *NHTTPi_GetThreadInfoP(void *sysInfo_p);
extern int NHTTPi_loadFromHdrRecvBuf(NHTTPRes *res_p, char *dst_p, int pos,
                                     int len);
extern int NHTTPi_strnicmp(char *p1_p, char *p2_p, int size);
extern int NHTTPi_strToInt(char *p_p, int len);
extern int NHTTPi_findNextLineHdrRecvBuf(NHTTPRes *res_p, int pos, int limit,
                                         int *colon_pos_p,
                                         int *return_code_size_p);
extern int NHTTPi_getHeaderValue(NHTTPRes *res_p, char *label_p, int *pos_p);
extern int NHTTPi_compareTokenN_HdrRecvBuf(NHTTPRes *res_p, int pos, int limit,
                                           char *str_p, char extdeli);
extern char sNHTTPHttpPrefix[];
extern char sNHTTPContentLength[];
extern char sNHTTPConnection[];
extern char sNHTTPKeepAlive[];
extern char sNHTTPTransferEncoding[];
extern char sNHTTPChunked[];

int NHTTPi_ThreadParseHeaderProc(ThreadData *threadData_p)
{
    int connectionHeaderStrLen;
    int labelend;
    int n;
    char *commBuf_p;
    ThreadInfo *threadInfo_p;
    Req *req_p;
    NHTTPRes *res_p;
    ReqInfo *reqInfo_p;
    void *sysInfo_p;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    reqInfo_p = NHTTPi_GetReqInfoP(sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    res_p = req_p->res_p;
    threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);
    commBuf_p = threadInfo_p->commBuf;

    if (NHTTPi_loadFromHdrRecvBuf(res_p, threadData_p->tmpHeaderBuf, 0, 0xe) == 0)
    {
        threadData_p->result = 7;
        return 0;
    }
    if (NHTTPi_strnicmp(threadData_p->tmpHeaderBuf, sNHTTPHttpPrefix, 5) != 0)
    {
        threadData_p->result = 7;
        return 0;
    }
    if (threadData_p->tmpHeaderBuf[8] != 0x20)
    {
        threadData_p->result = 7;
        return 0;
    }

    res_p->httpStatus = NHTTPi_strToInt(threadData_p->tmpHeaderBuf + 9, 3);
    if (res_p->httpStatus < 0)
    {
        threadData_p->result = 7;
        return 0;
    }

    if (NHTTPi_findNextLineHdrRecvBuf(res_p, 0xc, res_p->headerLen, &labelend, 0) < 0)
    {
        threadData_p->result = 7;
        return 0;
    }

    threadData_p->contentLength = NHTTPi_getHeaderValue(res_p, sNHTTPContentLength, &n);
    if (threadData_p->contentLength == 0)
    {
        threadData_p->result = 0;
        return 0;
    }
    if (threadData_p->contentLength > 0x4000)
    {
        threadData_p->result = 7;
        return 0;
    }
    if (threadData_p->contentLength > 0)
    {
        if (NHTTPi_loadFromHdrRecvBuf(res_p, commBuf_p, n,
                                      threadData_p->contentLength) == 0)
        {
            threadData_p->result = 7;
            return 0;
        }
        threadData_p->contentLength =
            NHTTPi_strToInt(commBuf_p, threadData_p->contentLength);
        if (threadData_p->contentLength < 0)
        {
            threadData_p->result = 7;
            return 0;
        }
        res_p->contentLength = threadData_p->contentLength;
    }
    else
    {
        res_p->contentLength = -1;
    }

    if (req_p->isSSL != 0)
    {
        threadData_p->isKeepAlive = 0;
    }
    else
    {
        connectionHeaderStrLen = NHTTPi_getHeaderValue(res_p, sNHTTPConnection, &n);
        if (connectionHeaderStrLen == 0)
        {
            threadData_p->result = 7;
            threadData_p->isKeepAlive = 0;
            return 0;
        }
        if (connectionHeaderStrLen > 0x4000)
        {
            threadData_p->isKeepAlive = 0;
        }
        else
        {
            if (connectionHeaderStrLen > 0)
            {
                if (NHTTPi_compareTokenN_HdrRecvBuf(res_p, n,
                                                   n + connectionHeaderStrLen,
                                                   sNHTTPKeepAlive, 0) == 0)
                    threadData_p->isKeepAlive = 1;
                else
                    threadData_p->isKeepAlive = 0;
            }
            else
            {
                threadData_p->isKeepAlive = 0;
            }
        }
    }

    threadData_p->isChunked = NHTTPi_getHeaderValue(res_p, sNHTTPTransferEncoding, &n);
    if (threadData_p->isChunked == 0)
    {
        threadData_p->result = 7;
        return 0;
    }
    if (threadData_p->isChunked > 0x4000)
    {
        threadData_p->isChunked = 0;
    }
    else
    {
        threadData_p->isChunked =
            (threadData_p->isChunked > 0)
                ? (NHTTPi_compareTokenN_HdrRecvBuf(res_p, n,
                                                   n + threadData_p->isChunked,
                                                   sNHTTPChunked, 0x3b) == 0)
                : 0;
    }

    threadData_p->result = 0;
    res_p->isHeaderParse = 1;
    return 1;
}
