/*
 * function: NHTTPi_ThreadSendProc
 * address:  0x021BD7E8
 * packet:   pkt_ov114_021BD7E8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: codegen, 46 bytes wrong.  Size and control flow are exact.  Two
 *          independent residues, both allocator-level:
 *          (1) the global r6<->r7 callee-saved swap of the two pointer
 *              chains {sysInfo_p, threadInfo_p} and {mutexInfo_p,
 *              connection_p, stat}.  Every differing instruction is the same
 *              opcode with r6/r7 exchanged.  Declaration order does not move
 *              it: adding the DWARF's `char *commBuf_p` local (used for the
 *              two SocSend/memclr sites) is byte-neutral, as are sysInfo_p
 *              first, sysInfo_p last, and a reversed declaration list.
 *          (2) the constant 0.  The vendor build materialises `mov r5,#0`
 *              once at +000C and reuses r5 for sendBufwp=0 (+0078),
 *              sendStatus=0 (+0080) and the tail sendBufwp=0 (+0350); ours
 *              pools only the +0350 use and rematerialises r0=0 at +0078.
 *              Same class as ov114 0x021CB3B4, where the pool WAS recovered
 *              by raising the literal count: the vendor pools a constant when
 *              the same store appears in sibling branches (there the shared
 *              `a->neg = 0` had to be written out twice, once per branch,
 *              giving three zero literals in the region).  Here the pool
 *              spans three statements in three regions, so that lever has no
 *              branch to duplicate into; no spelling tried moves it.
 *          Next pass: recover the vendor ordering by finding which source
 *          statement creates the long-lived zero.
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
 *   g_021CE4DC                       0x021ce4dc data
 *   g_021CE4E4                       0x021ce4e4 data
 *   g_021CE4EC                       0x021ce4ec data
 *   g_021CE4F4                       0x021ce4f4 data
 *   g_021CE46C                       0x021ce46c data
 *   g_021CE478                       0x021ce478 data
 *   g_021CE440                       0x021ce440 data
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

extern char g_021CE4DC[];
extern char g_021CE4E4[];
extern char g_021CE4EC[];
extern char g_021CE4F4[];
extern char g_021CE46C[];
extern char g_021CE478[];
extern char g_021CE440[];

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
    int stat;
    ReqInfo *reqInfo_p;
    Req *req_p;
    void *mutexInfo_p;
    BgnEnd *bgnEndInfo_p;
    int *connection_p;
    ThreadInfo *threadInfo_p;
    int urlLength;
    int sendStatus;
    int isMultipartForm;
    NHTTPi_DATALIST *datalist_p;
    int postResult;
    int a_encodingType;
    void *sysInfo_p;

    sysInfo_p = NHTTPi_GetSystemInfoP();
    reqInfo_p = NHTTPi_GetReqInfoP(sysInfo_p);
    req_p = reqInfo_p->reqCurrent->req_p;
    mutexInfo_p = NHTTPi_GetMutexInfoP(sysInfo_p);
    bgnEndInfo_p = NHTTPi_GetBgnEndInfoP(sysInfo_p);
    connection_p = NHTTPi_Request2Connection(mutexInfo_p, req_p);
    threadInfo_p = NHTTPi_GetThreadInfoP(sysInfo_p);
    urlLength = NHTTPi_strlen(req_p->f24);
    threadData_p->field330 = 0xa;
    if (connection_p != 0) {
        *connection_p = 2;
    }
    threadData_p->sendBufwp = 0;
    sendStatus = 0;
    switch (req_p->f1c) {
    case 0:
        sendStatus = NHTTPi_SendData(threadData_p, g_021CE4DC, 4);
        break;
    case 1:
        sendStatus = NHTTPi_SendData(threadData_p, g_021CE4E4, 5);
        break;
    case 2:
        sendStatus = NHTTPi_SendData(threadData_p, g_021CE4EC, 5);
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
            sendStatus = NHTTPi_SendData(threadData_p, g_021CE4F4, 1);
            if (sendStatus != 0) {
                return sendStatus;
            }
        }
    }
    sendStatus = NHTTPi_SendData(threadData_p, g_021CE46C, 0xb);
    if (sendStatus != 0) {
        return sendStatus;
    }
    stat = 8;
    if (req_p->f08 == 0) {
        stat = 7;
    }
    sendStatus = NHTTPi_SendData(threadData_p, g_021CE478, 6);
    if (sendStatus != 0) {
        return sendStatus;
    }
    sendStatus = NHTTPi_SendData(threadData_p, req_p->f24 + stat, req_p->f14 - stat);
    if (sendStatus != 0) {
        return sendStatus;
    }
    sendStatus = NHTTPi_SendData(threadData_p, g_021CE440, 2);
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
            if (req_p->fd4 == 0) {
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
                if (req_p->fd4 != 2) {
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
        sendStatus = NHTTPi_SendData(threadData_p, g_021CE440, 2);
        if (sendStatus != 0) {
            return sendStatus;
        }
    }
    stat = threadData_p->sendBufwp;
    a_encodingType = 0;
    if (stat > 0) {
        stat = NHTTPi_SocSend(req_p, bgnEndInfo_p->socket, threadInfo_p->commBuf, threadData_p->sendBufwp, 0);
        threadData_p->sendBufwp = 0;
        NHTTPi_memclr(threadInfo_p->commBuf, 0x4000);
        if (stat < 0) {
            a_encodingType = 1;
        }
        if (stat == 0) {
            a_encodingType = 2;
        }
    }
    threadData_p->sendBufwp = 0;
    NHTTPi_memclr(threadInfo_p->commBuf, 0x4000);
    return a_encodingType;
}
