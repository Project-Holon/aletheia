/*
 * function: NHTTPi_ThreadRecvBodyProc
 * address:  0x021BDFF8
 * packet:   pkt_ov114_021BDFF8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    chunkSize doubles as the constant zero on the content-length and plain-read
 *           paths (it is only reassigned on the chunked path).  The +0x104 buffer pointer is an
 *           inline expression at each use (hoisted by the compiler), not commBuf_p.  The
 *           BufFull test is `!NHTTPi_BufFull(...)`, the RecvBufN position argument is written
 *           as an if/else over two calls (a ?: yields conditional moves), the trailer
 *           SkipLineBuf result is ignored, the plain read loop tests `n == 0` first, and
 *           the chunked branch precedes the plain loop in source order.
 *
 * sdk:      NHTTPi_ThreadRecvBodyProc (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP            0x021bef08 arm
 *   NHTTPi_GetReqInfoP               0x021bef48 arm
 *   NHTTPi_GetBgnEndInfoP            0x021bef3c arm
 *   NHTTPi_GetMutexInfoP             0x021bef58 arm
 *   NHTTPi_Request2Connection        0x021bebe0 arm
 *   NHTTPi_GetThreadInfoP            0x021bef50 arm
 *   NHTTPi_SetVirtualContentLength   0x021bef60 arm
 *   NHTTPi_BufFull                   0x021bc2fc arm
 *   NHTTPi_RecvBufN                  0x021bb344 arm
 *   NHTTPi_isRecvBufFull             0x021bb2fc arm
 *   NHTTPi_SocRecv                   0x021b9f94 arm
 *   NHTTPi_SkipLineBuf               0x021bc00c arm
 *   NHTTPi_strToHex                  0x021ba35c arm
 *   NHTTPi_RecvBuf                   0x021bb310 arm
 *   NHTTPi_Response2Connection       0x021bebf0 arm
 *   NHTTPi_ReceivedCallback          0x021bed90 arm
 */

typedef unsigned long u32;

typedef struct {
    char pad[0x328];
    int f328;
    int f32c;
    int f330;
    char pad334[8];
    int f33c;
} ThreadData;

typedef struct {
    int f0;
    int f4;
    int f8;
    char padc[0xc];
    int f18;
    int f1c;
    char pad20[8];
    void *f28;
} Res;

typedef struct {
    char pad0[0x1c];
    int f1c;
    char pad20[0xc];
    Res *f2c;
} Req;

typedef struct {
    char pad[0xc];
    Req *req_p;
} ReqList;

typedef struct {
    ReqList *reqCurrent;
} ReqInfo;

typedef struct {
    char pad[0x100];
    char commBuf[1];
} ThreadInfo;

typedef struct {
    char pad[0xc];
    int socket;
} BgnEnd;

extern void *NHTTPi_GetSystemInfoP(void);
extern ReqInfo *NHTTPi_GetReqInfoP(void *sysInfo_p);
extern BgnEnd *NHTTPi_GetBgnEndInfoP(void *sysInfo_p);
extern void *NHTTPi_GetMutexInfoP(void *sysInfo_p);
extern void *NHTTPi_Request2Connection(void *mutexInfo_p, Req *req_p);
extern ThreadInfo *NHTTPi_GetThreadInfoP(void *sysInfo_p);
extern void NHTTPi_SetVirtualContentLength(void *connection_p, u32 contentLength);
extern int NHTTPi_BufFull(void *mutexInfo_p, Res *res_p);
extern int NHTTPi_RecvBufN(void *mutexInfo_p, Req *req_p, int socket, int pos, int len, int flags);
extern int NHTTPi_isRecvBufFull(Res *res_p, int pos);
extern int NHTTPi_SocRecv(void *mutexInfo_p, Req *req_p, int socket, char *buf_p, int len, int flags);
extern int NHTTPi_SkipLineBuf(void *mutexInfo_p, Req *req_p, int socket);
extern int NHTTPi_strToHex(char *p_p, int len);
extern int NHTTPi_RecvBuf(void *mutexInfo_p, Req *req_p, int socket, int pos, int len);
extern void *NHTTPi_Response2Connection(void *mutexInfo_p, Res *res_p);
extern void NHTTPi_ReceivedCallback(void *mutexInfo_p, void *connection_p);

#define BUF2(td) ((char *)(td) + 0x104)

static int NHTTPi_ThreadRecvBodyProc(ThreadData *threadData_p)
{
    void *sysInfo_p;
    ReqInfo *reqInfo_p;
    Req *req_p;
    Res *res_p;
    BgnEnd *bgnEndInfo_p;
    void *mutexInfo_p;
    void *connection_p;
    ThreadInfo *threadInfo_p;
    char *commBuf_p;
    char tmpBuf[2];
    int chunkSize = 0;
    int n;
    int recvbyte;
    int idx;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    reqInfo_p = NHTTPi_GetReqInfoP(sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    res_p = req_p->f2c;
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    connection_p = NHTTPi_Request2Connection(mutexInfo_p, req_p);
    threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);
    commBuf_p = threadInfo_p->commBuf;
    if (req_p->f1c == 2 || res_p->f18 == 0xcc || res_p->f18 == 0x130 ||
        (res_p->f18 >= 100 && res_p->f18 < 200)) {
        return 1;
    }
    NHTTPi_SetVirtualContentLength(connection_p, 0);
    if (connection_p != 0) {
        *(int *)connection_p = 4;
    }
    if (threadData_p->f32c < 0) {
        goto chunked;
    }
    NHTTPi_SetVirtualContentLength(connection_p, threadData_p->f32c);
    if (threadData_p->f32c > 0) {
        do {
            if (threadData_p->f330 != 6) {
                if (!NHTTPi_BufFull(mutexInfo_p, res_p)) {
                    threadData_p->f330 = 6;
                    res_p->f28 = BUF2(threadData_p);
                    res_p->f1c = 0x200;
                }
            }
            if (threadData_p->f330 == 6)
                n = NHTTPi_RecvBufN(mutexInfo_p, req_p, bgnEndInfo_p->socket, chunkSize,
                                    threadData_p->f32c, chunkSize);
            else
                n = NHTTPi_RecvBufN(mutexInfo_p, req_p, bgnEndInfo_p->socket, res_p->f4,
                                    threadData_p->f32c, chunkSize);
            if (n < 0) {
                return 0;
            }
            if (n == 0) {
                break;
            }
            if (threadData_p->f330 != 6) {
                res_p->f4 += n;
                res_p->f8 += n;
            }
            threadData_p->f32c -= n;
        } while (threadData_p->f32c > 0);
    }
    if (threadData_p->f330 != 6) {
        if (threadData_p->f32c != 0) {
            threadData_p->f330 = NHTTPi_isRecvBufFull(res_p, res_p->f4) ? 6 : 0xa;
        } else {
            threadData_p->f330 = chunkSize;
        }
    }
    goto tail;
chunked:
    threadData_p->f330 = 0xa;
    if (threadData_p->f33c == 0) {
        goto plain;
    }
    chunkSize = 0xa - 0xb;
reset:
    tmpBuf[0] = 0;
    tmpBuf[1] = 0;
    threadData_p->f328 = 0;
    while (threadData_p->f328 < 0x4000) {
        if (NHTTPi_SocRecv(mutexInfo_p, req_p, bgnEndInfo_p->socket, commBuf_p + threadData_p->f328, 1, 0) < 0) {
            return 0;
        }
        idx = threadData_p->f328;
        recvbyte = commBuf_p[idx];
        tmpBuf[idx & 1] = (char)recvbyte;
        if (recvbyte == ';' || (recvbyte == 0xa && tmpBuf[(idx - 1) & 1] == 0xd)) {
            if (recvbyte == 0xa) {
                idx--;
            } else {
                if (NHTTPi_SkipLineBuf(mutexInfo_p, req_p, bgnEndInfo_p->socket) <= 0) {
                    return 0;
                }
            }
            if (idx == 0) {
                return 0;
            }
            chunkSize = NHTTPi_strToHex(commBuf_p, idx);
            if (chunkSize < 0) {
                return 0;
            }
            break;
        }
        threadData_p->f328++;
    }
    if (threadData_p->f328 == 0x4000) {
        threadData_p->f330 = 7;
        return 0;
    }
    if (chunkSize > 0) {
        NHTTPi_SetVirtualContentLength(connection_p, chunkSize);
        if (chunkSize > 0) {
            do {
                if (threadData_p->f330 != 6) {
                    if (!NHTTPi_BufFull(mutexInfo_p, res_p)) {
                        threadData_p->f330 = 6;
                        res_p->f28 = BUF2(threadData_p);
                        res_p->f1c = 0x200;
                    }
                }
                if (threadData_p->f330 == 6)
                    n = NHTTPi_RecvBufN(mutexInfo_p, req_p, bgnEndInfo_p->socket, 0, chunkSize, 0);
                else
                    n = NHTTPi_RecvBufN(mutexInfo_p, req_p, bgnEndInfo_p->socket, res_p->f4, chunkSize, 0);
                if (n <= 0) {
                    return 0;
                }
                res_p->f4 += n;
                res_p->f8 += n;
                chunkSize -= n;
                if (chunkSize == 0) {
                    if (NHTTPi_SocRecv(mutexInfo_p, req_p, bgnEndInfo_p->socket, commBuf_p, 2, 0) <= 0) {
                        return 0;
                    }
                }
            } while (chunkSize > 0);
        }
        goto reset;
    }
    NHTTPi_SkipLineBuf(mutexInfo_p, req_p, bgnEndInfo_p->socket);
    threadData_p->f330 = 0;
    goto tail;
plain:
    for (;;) {
        if (!NHTTPi_BufFull(mutexInfo_p, res_p)) {
            threadData_p->f330 = 6;
            res_p->f28 = BUF2(threadData_p);
            res_p->f1c = 0x200;
        }
        if (threadData_p->f330 == 6) {
            n = NHTTPi_RecvBuf(mutexInfo_p, req_p, bgnEndInfo_p->socket, chunkSize, chunkSize);
        } else {
            n = NHTTPi_RecvBuf(mutexInfo_p, req_p, bgnEndInfo_p->socket, res_p->f4, 0);
        }
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            if (threadData_p->f330 != 6) {
                threadData_p->f330 = 0;
            }
            break;
        }
        res_p->f4 += n;
        res_p->f8 += n;
    }
tail:
    {
        void *conn2 = NHTTPi_Response2Connection(mutexInfo_p, res_p);

        if (threadData_p->f330 == 0 && conn2 != 0) {
            NHTTPi_ReceivedCallback(mutexInfo_p, conn2);
        }
    }
    return 1;
}
