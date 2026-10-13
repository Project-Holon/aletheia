/*
 * function: NHTTPi_ThreadSendProc
 * address:  0x021BD7E8
 * packet:   pkt_ov114_021BD7E8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * closed (wave 3 lane25, 2026-10-01): three source-shape fixes, no allocator
 *        wall.  (1) `sendStatus = 0;` sits before `field330 = 0xa` (its live
 *        range pushes 0xa/2 into r1 and shares the entry zero in r5).
 *        (2) DWARF `commBuf_p = threadInfo_p->commBuf;` right after
 *        GetThreadInfoP, used at all three sites (fixes the r6/r7 chain swap;
 *        CW forward-substitutes the add).  (3) DWARF `a_encodingType` is
 *        req_p->encodingType (+0xd4, first location r0), not the return code;
 *        the tail return code is `postResult`.  Declarations in DWARF order
 *        (raw list reversed: sysInfo_p first, stat last).
 *
 * sdk:      NHTTPi_ThreadSendProc (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP            0x021bef08 arm
 *   NHTTPi_GetReqInfoP               0x021bef48 arm
 *   NHTTPi_GetMutexInfoP             0x021bef58 arm
 *   NHTTPi_GetBgnEndInfoP            0x021bef3c arm
 *   NHTTPi_Request2Connection        0x021bebe0 arm
 *   NHTTPi_GetThreadInfoP            0x021bef50 arm
 *   NHTTPi_strlen                    0x021ba118 arm
 *   NHTTPi_SendData                  0x021bc384 arm
 *   NHTTPi_SendProxyAuthorization    0x021bc40c arm
 *   NHTTPi_SendBasicAuthorization    0x021bc488 arm
 *   NHTTPi_SendHeaderList            0x021bc924 arm
 *   NHTTPi_SendProcPostDataRaw       0x021bc9f0 arm
 *   NHTTPi_SendProcPostDataBinary    0x021bcb74 arm
 *   NHTTPi_SendProcPostDataAscii     0x021bcf24 arm
 *   NHTTPi_SocSend                   0x021ba020 arm
 *   NHTTPi_memclr                    0x021ba13c arm
 *   sNHTTPMethodGet                       0x021ce4dc data
 *   sNHTTPMethodPost                       0x021ce4e4 data
 *   sNHTTPMethodHead                       0x021ce4ec data
 *   sNHTTPSlash                       0x021ce4f4 data
 *   sNHTTPHttpVersionLine                       0x021ce46c data
 *   sNHTTPHostHeader                       0x021ce478 data
 *   sNHTTPCrLf                       0x021ce440 data
 */

typedef unsigned long u32;

typedef struct _NHTTPi_DATALIST {
    struct _NHTTPi_DATALIST *head;
    struct _NHTTPi_DATALIST *next;
    void *pad08;
    void *pad0c;
    u32 pad10;
    u32 field14;
} NHTTPi_DATALIST;

typedef struct {
    char pad00[8];
    void *f08;
    void *f0c;
    void *f10;
    u32 f14;
    int f18;
    int f1c;
    char pad20[4];
    char *f24;
    char pad28[0xc];
    NHTTPi_DATALIST *f34;
    char pad38[0x9c];
    u32 fd4;
} Req;

typedef struct {
    char pad[0xc];
    Req *req_p;
} ReqList;

typedef struct {
    ReqList *reqCurrent;
} ReqInfo;

typedef struct {
    char pad[0x324];
    int sendBufwp;
    char pad328[8];
    int field330;
} ThreadData;

typedef struct {
    char pad[0x100];
    char commBuf[1];
} ThreadInfo;

typedef struct {
    char pad[0xc];
    int socket;
} BgnEnd;

extern char sNHTTPMethodGet[];
extern char sNHTTPMethodPost[];
extern char sNHTTPMethodHead[];
extern char sNHTTPSlash[];
extern char sNHTTPHttpVersionLine[];
extern char sNHTTPHostHeader[];
extern char sNHTTPCrLf[];

extern void *NHTTPi_GetSystemInfoP(void);
extern void *NHTTPi_GetMutexInfoP(void *sysInfo_p);
extern ReqInfo *NHTTPi_GetReqInfoP(void *sysInfo_p);
extern BgnEnd *NHTTPi_GetBgnEndInfoP(void *sysInfo_p);
extern int *NHTTPi_Request2Connection(void *mutexInfo_p, Req *req_p);
extern ThreadInfo *NHTTPi_GetThreadInfoP(void *sysInfo_p);
extern int NHTTPi_strlen(char *p);
extern int NHTTPi_SendData(ThreadData *threadData_p, char *src_p, int srclen);
extern int NHTTPi_SendProxyAuthorization(ThreadData *threadData_p);
extern int NHTTPi_SendBasicAuthorization(ThreadData *threadData_p);
extern int NHTTPi_SendHeaderList(ThreadData *threadData_p);
extern int NHTTPi_SendProcPostDataRaw(ThreadData *threadData_p);
extern int NHTTPi_SendProcPostDataBinary(ThreadData *threadData_p);
extern int NHTTPi_SendProcPostDataAscii(ThreadData *threadData_p);
extern int NHTTPi_SocSend(Req *req_p, int socket, char *buf_p, int len, int flags);
extern void NHTTPi_memclr(void *p_p, int size);

static int NHTTPi_ThreadSendProc(ThreadData *threadData_p)
{
    void *sysInfo_p;
    ReqInfo *reqInfo_p;
    Req *req_p;
    void *mutexInfo_p;
    BgnEnd *bgnEndInfo_p;
    int *connection_p;
    ThreadInfo *threadInfo_p;
    char *commBuf_p;
    int urlLength;
    int sendStatus;
    int isMultipartForm;
    NHTTPi_DATALIST *datalist_p;
    int postResult;
    int a_encodingType;
    int stat;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    reqInfo_p = NHTTPi_GetReqInfoP(sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    connection_p = NHTTPi_Request2Connection(mutexInfo_p, req_p);
    threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);
    commBuf_p = threadInfo_p->commBuf;
    urlLength = NHTTPi_strlen(req_p->f24);
    sendStatus = 0;
    threadData_p->field330 = 0xa;
    if (connection_p != 0) {
        *connection_p = 2;
    }
    threadData_p->sendBufwp = 0;
    switch (req_p->f1c) {
    case 0:
        sendStatus = NHTTPi_SendData(threadData_p, sNHTTPMethodGet, 4);
        break;
    case 1:
        sendStatus = NHTTPi_SendData(threadData_p, sNHTTPMethodPost, 5);
        break;
    case 2:
        sendStatus = NHTTPi_SendData(threadData_p, sNHTTPMethodHead, 5);
        break;
    }
    if (sendStatus != 0) {
        return sendStatus;
    }
    if (req_p->f0c != 0 && req_p->f08 == 0) {
        sendStatus = NHTTPi_SendData(threadData_p, req_p->f24, urlLength);
        if (sendStatus != 0) {
            return sendStatus;
        }
    } else {
        if (urlLength > req_p->f18) {
            sendStatus = NHTTPi_SendData(threadData_p, req_p->f24 + req_p->f18, urlLength - req_p->f18);
            if (sendStatus != 0) {
                return sendStatus;
            }
        } else {
            sendStatus = NHTTPi_SendData(threadData_p, sNHTTPSlash, 1);
            if (sendStatus != 0) {
                return sendStatus;
            }
        }
    }
    sendStatus = NHTTPi_SendData(threadData_p, sNHTTPHttpVersionLine, 0xb);
    if (sendStatus != 0) {
        return sendStatus;
    }
    stat = 8;
    if (req_p->f08 == 0) {
        stat = 7;
    }
    sendStatus = NHTTPi_SendData(threadData_p, sNHTTPHostHeader, 6);
    if (sendStatus != 0) {
        return sendStatus;
    }
    sendStatus = NHTTPi_SendData(threadData_p, req_p->f24 + stat, req_p->f14 - stat);
    if (sendStatus != 0) {
        return sendStatus;
    }
    sendStatus = NHTTPi_SendData(threadData_p, sNHTTPCrLf, 2);
    if (sendStatus != 0) {
        return sendStatus;
    }
    if (req_p->f0c != 0 && req_p->f08 == 0) {
        sendStatus = NHTTPi_SendProxyAuthorization(threadData_p);
        if (sendStatus != 0) {
            return sendStatus;
        }
    }
    sendStatus = NHTTPi_SendBasicAuthorization(threadData_p);
    if (sendStatus != 0) {
        return sendStatus;
    }
    sendStatus = NHTTPi_SendHeaderList(threadData_p);
    if (sendStatus != 0) {
        return sendStatus;
    }
    if (req_p->f1c == 1) {
        if (req_p->f10 != 0) {
            postResult = NHTTPi_SendProcPostDataRaw(threadData_p);
        } else {
            a_encodingType = req_p->fd4;
            if (a_encodingType == 0) {
                isMultipartForm = 0;
                datalist_p = req_p->f34;
                if (datalist_p != 0) {
                    while (1) {
                        if (datalist_p->field14 != 0) {
                            isMultipartForm = 1;
                            break;
                        }
                        if (datalist_p == req_p->f34->head) {
                            break;
                        }
                        datalist_p = datalist_p->next;
                        if (datalist_p != 0) {
                            continue;
                        }
                        break;
                    }
                }
            } else {
                isMultipartForm = 1;
                if (a_encodingType != 2) {
                    isMultipartForm = 0;
                }
            }
            if (isMultipartForm) {
                postResult = NHTTPi_SendProcPostDataBinary(threadData_p);
            } else {
                postResult = NHTTPi_SendProcPostDataAscii(threadData_p);
            }
        }
        if (postResult != 0) {
            if (postResult == 3) {
                threadData_p->field330 = 3;
            }
            return postResult;
        }
    } else {
        sendStatus = NHTTPi_SendData(threadData_p, sNHTTPCrLf, 2);
        if (sendStatus != 0) {
            return sendStatus;
        }
    }
    stat = threadData_p->sendBufwp;
    postResult = 0;
    if (stat > 0) {
        stat = NHTTPi_SocSend(req_p, bgnEndInfo_p->socket, commBuf_p, threadData_p->sendBufwp, 0);
        threadData_p->sendBufwp = 0;
        NHTTPi_memclr(commBuf_p, 0x4000);
        if (stat < 0) {
            postResult = 1;
        }
        if (stat == 0) {
            postResult = 2;
        }
    }
    threadData_p->sendBufwp = 0;
    NHTTPi_memclr(commBuf_p, 0x4000);
    return postResult;
}
